---
layout:       post
title:        "FutureRestore"
subtitle:     "How to downgrade/upgrade to unsigned iOS firmwares"
date:         2019-04-07
author:       "Ivan"
header-img:   "img/post-bg-futurerestore.png"
header-mask:  0.3
catalog:      true
tags:
    - Jailbreak
    - iOS
    - downgrade
    - Guide
---

### A bit of history

Once again, here we are with another Jailbreak-related guide. Some of you may know what futurerestore is, but I'll explain that anyway.
[Futurerestore](https://github.com/tihmstar/futurerestore) is a tool developed by the famous hacker and jailbreaker [tihmstar](https://twitter.com/tihmstar), known also for [h3lix](https://h3lix.tihmstar.net/), [doubleh3lix](https://h3lix.tihmstar.net/), [JailbreakMe 4.0](https://jailbreak.me/) and the [v1ntex exploit](https://github.com/tihmstar/v1ntex).

It is based on [idevicerestore](https://github.com/libimobiledevice/idevicerestore), a tool which consists in a full reimplementation of all granular steps which are performed during a firmware restore in an iDevice and allows to download and restore a device to the latest firmware available.

Futurerestore, anyway, is a hacked up idevicerestore wrapper, which allows specifying SEP and Baseband for restoring, and in this way allowing the user to downgrade or upgrade even to unsigned versions of iOS.

Timhstar, anyway, left the development a year ago or so, and now the Russian developer [kúp](https://twitter.com/s0uthwes?s=17) reworked a fork of futurerestore, updating it constantly and even adding the support for Linux builds.

Another developer, **Tanner Hoffman** aka [qwertyuiop1379](https://github.com/qwertyuiop1379) built a GUI wrapper for futurerestore on Windows, called [iRestore](https://github.com/qwertyuiop1379/iRestore). It has later been [ported to macOS](https://github.com/zzHAMZAzz/iRestore-Mac-Edition) thanks to [/u/jbkid](https://www.reddit.com/user/jbkid). iRestore is as powerful as easy, it allows to automatically download the latest version of (s0uthwest's) futurerestore and provide an easy to use GUI instead of a CLI. That's why our guide will be based on it.

![alt text](</img/FutureRestore/iRestore.png> "iRestore")

## Why do I need it?

Ok, let's explain why all of this mess is needed in first place.

On mostly any Android you can - regardless if the actual process is easy or not - downgrade to older OS versions, or even install custom versions of the OS. There are lots of "variables", so I'll try not to enter into details, but also try to explain it as clear as possible.

Usually, on basically any PC you have the **firmware**, the **bootloader**, the **kernel**, the OS itself and the **recovery** or something similar. Of course there is much more, but for now we'll stick with these.

The firmware installation usually include the installation/update of some other components, like the kernel and the baseband. The firmwares packages are usually `.zip` or `.img` for Android and `.ipsw` for iOS. They way they get installed is completely different, though.

The bootloader is the program which allows during the boot phase to load the **kernel** of the OS from a non-volatile memory (an HDD or an SSD) to a primary memory, usually a volatile one like the RAM. If you're wondering what it is, the kernel is (as the name suggests) the core of the entire OS, with complete control over everything in the system and even responsible of the interfacing between the various hardware components, such as the translation of the _I/O_ requests to data-processing instructions for the _Central Processing Unit_.

Lastly, there is the **recovery**. In some form or another, it is present in every smartphone, but usually it is on Android ones. It could also have a different name, but what it does is basically allowing the user to install, update, backup or restore several crucial SW components of your device, such as firmwares (compressed in images or uncompressed), OTA updates or even kernel, basebands or recoveries themselves, sometimes also providing _debugging_ support as well as basic file manager functions with **r/w** access to the _root filesystem_. The recovery is a very powerful tool, that's why not every OEM allows users to have access to all of its functions, or not even including some of them at all. Basically, stock recoveries usually allow users to install at least OTA updates, but all the aforementioned as very rare to find on stock recoveries. That's why the Android scene offers several powerful open-source alternatives such as the Team Win Recovery Project, aka **TWRP**. Even iOS has a recovery mode alongside another mode called **DFU**: the first one allows you to perform a factory reset updating your iDevice to the latest iOS version available, the second one (which stands for _Device Firmware Update_) skips the **iBoot** bootloader and so permit in some specific cases to downgrade. Anyway, they're both very limited and don't allow the user to perform any action: it just works as an interface between the iPhone and the PC. So why don't install a custom recovery and get away with it? Don't overhype, that's not that simple.

Remember about the bootloader? Well, it is also responsible for loading another important SW component: yeah, the recovery. The problem is indeed at the root, most of the times the bootloader is **closed**, and does not allow the user to load anything else then what it is **meant** to load. Sometimes you can unlock the bootloader (even though most of the times that require unique code coming from the OEM, but requesting it implies losing your warranty). But a lot of brands also chose not to provide any way to unlock it at all. And well, Apple is one of those. So basically there is no way to load unauthorised software, and Apple even puts a step forward to it. Not only you cannot run unauthorised software, you also cannot even run any form of unsigned OS. Apple, anyway, temporary signs its iOS version for a limited period of time, that means that once Apple it stops to sign a specific iOS version (usually one or two weeks following the release of the subsequent iOS version), there is no official (and sometimes even unofficial) way to downgrade to it. Pretty annoying, uh?

## How it works

Now that we explained in general lines why it's not possible to downgrade straightforward, let's explain how updates and downgrades work in first place, in order to understand the following part of the explanation.

In order to successfully restore you need some valid and matching **SHSH** blobs for the **BBTicket** (baseband signing ticket), the **APTicket** (firmware signing ticket) and the **SEP OS**. Let's explain what they are.

The Apple's cryptographic signature hash blobs, also known just as **SHSH** blobs, are 1024-bit RSA signatures verified by the bootloader before execution of an image (like restoring to a specific iOS version) is permitted. **Nonce** is the signing method that randomly generates SHSHs depending on your iDevice identifier (basically, the model) and its **ECID** (_Electronic Chip ID_, a unique number assigned to every Apple device). They are generated from the device bootloaders (baseband, firmware and SEP OS) at the time of a restore request, but are issued just when the iOS version you're currently trying to restore to is still signed. There is also another way to save them though: you can use a script in order to ask for a valid SHSH blob without performing a restore. That would allow you to store a copy of a signed blob which remains signed, and so it can be used later to perform a [replay attack](https://en.wikipedia.org/wiki/Replay_attack) within futurerestore or one of its wrappers. Here's how to [save them](/2019/03/13/futurerestore/#saving-blobs).

The **BBTicket** is a unique baseband signing ticket. The **baseband** is the firmware running on the cellular modem hardware. As the OS itself, the baseband gets updated and could be downgraded or upgraded just to signed baseband versions. iPod touch and Wi-Fi-only iPads do not need BBTickets since by definition they have no baseband.

The **APTicket**, instead, is the generic firmware signing ticket and refers to the _Application Processor_ or just **AP** (basically the technical term given to a processor of an iDevice). Because of it, replay attacks are no longer possible unless the **nonce**(s) (**SEPNonce** + **APNonce** on 64 bit, **APNonce** only on 32 bit) the device generates matches the one on the APTicket.

But what are **SEP**, **SEP OS** and **SEPNonce**? SEP is the _Secure Enclave Processor_, and it's part of A7 processors or successive. What it does is handling keys and other info such as biometrics, and it dialogues with iOS thanks to its own OS: SEP OS. The SEPNonce is a stored uneditable identifier, and considering that all the 64bit devices (iPhone 5S or later) but the iPod touch 6 - which doesn't have TouchID - those devices need this nonce to match too, in addition to the APNonce. Also, in order to downgrade or upgrade to another iOS version, you currently need to be on a SEP OS version compatible with the targeting iOS version, otherwise SEP OS would not work and so you'd lose TouchID or FaceID capabilities.

Now that - hopefully - everything is clear, let's move to the practical part itself.

## Requirements

- An iDevice running a kernel exploitable iOS version, in order to manually set the nonce
- Saved iOS blobs for the iOS version you want to downgrade to ([here](/2019/03/13/futurerestore/#saving-blobs)'s how to do that)
- The IPSW of the iOS version you want to downgrade to ([here](/2019/03/13/futurerestore/#saving-blobs)'s how to do that)
- The latest version of iRestore ([Windows](https://github.com/qwertyuiop1379/iRestore/raw/master/iRestore.exe) or [macOS](https://github.com/zzHAMZAzz/iRestore-Mac-Edition/releases) version)
- A genuine or a certified MFi lightning cable
- Internet access
- Patience

### Saving blobs

As you may have understood at this point, saving blobs is mandatory if you want to downgrade your iDevice. The main problem about it is that you can save your blobs just for the iOS versions currently signed by Apple. Let's say that as for now iOS 12.2 and 12.2.1 are the only signed versions: you cannot save anymore the blobs for the previous versions (such as 12.1.2) and so losing any possibily to downgrade to those versions. So whenever a new iOS version gets out, I warmly suggest you to always save your blobs as soon as possible, before Apple would eventually stop signining them.

As we said before, in order to save blobs you need your identifier and your ECID. To retrieve them, you need to open iTunesk, go to the summary page of your iOS Device, click the serial number until the ECID appears. Note it somewhere or copy it. Click on the ECID again until you'll see the identifier and remember that.

Now, visit [TSS Saver](https://tsssaver.1conan.com/), paste the ECID (iTunes will provide it in HEX) and select the correct identifier. Don't manually set a nonce, TSS Saver automatically uses the `0x1111111111111111` nonce and nonce setters such as the one included in unc0ver used them from now on.

Once you'll save the blobs, you'll get ridirected to a link from where you can find all your stored blobs. You can also retrieve the URL with your ECID.

You can also use [@rJailbreakBot](https://t.me/rJailbreakBot), a very powerful Telegram Bot. You'll use it anyway later, so why not giving it a try?

### Download IPSWs

This is very easy. Open [ipsw.me](https://ipsw.me/) and choose your product, your model, the iOS version you want (the green ones are those still signed and not needing any SHSH blob) and just download. If you're not capable of identifying your model, press [Identify my iOS Device](https://ipsw.me/device-finder) and follow the instructions. The IPSWs size could be around 1 to 4 GB.

### SEP, Baseband and Build Manifest

Open up again [@rJailbreakBot](https://t.me/rJailbreakBot) and type `/sepbb`. Select your model and pick a compatible SEP OS and Baseband combo. The output will look like this:
> **iPhone 7 (GSM)(d101ap) - 16E227**
>
> **SEPOS:** Firmware/all_flash/sep-firmware.d101.RELEASE.im4p
>
> **BBFW:** Firmware/ICE16-3.03.04.Release.bbfw
>
> [IPSW download link](http://updates-http.cdn-apple.com/2019SpringFCS/fullrestores/091-79245/ECCCBE0E-499F-11E9-A2E0-C84576CE070F/iPhone_4.7_P3_12.2_16E227_Restore.ipsw)

Copy the link of _IPSW download link_, visit [extract.me](https://extract.me/) and paste it there. Download the files indicated by [@rJailbreakBot](https://t.me/rJailbreakBot) as SEPOS and BBFW. In this case, for example, I would download `sep-firmware.d101.RELEASE.im4p` and `ICE16-3.03.04.Release.bbfw`. Lastly, download the `BuildManifest.plist`.

### Setup the environment

**First of all, note that futurerestoring you will lose all your data, considering the entire filesystem gets restored!**
+ Disable **Find my iPhone** from Settings → Your name → iCloud → Find my iPhone
+ An OTA update installation in the middle of the process could lead to a bootloop and so force you to restore to the latest iOS version. So in case you already didn't, install the [watchOS profile](https://s007.co/watchos5config) in order to block the OTAs
+ Download your saved blobs from either [@rJailbreakBot](https://t.me/rJailbreakBot) or [TSS Saver](https://tsssaver.1conan.com/). In the last case, pick the one inside the `noapnonce/` folder
+ Open the `.shsh2` with an XML text editor. Press CTRL + F (Windows) or CMD + F (macOS). Search for the “**generator**” string and copy the alphanumeric string inside your nonce setter settings. If you don't know which nonce setter to use, unc0ver has an excellent nonce setter builtin. **NB:** if you saved the `.shsh2` blobs with TSS Saver you could skip this step if you use unc0ver, since it automatically set the nonce to `0x1111111111111111` everytime you jailbreak
+ Jailbreak your phone and check that the nonce now match with that one into the blobs (if you were already jailbroken, jailbreak again)

## Let’s future-restore!

+ Open iRestore
+ Press **Choose IPSW** and select your `.ipsw`
+ Press **Choose SHSH2** and select your `.shsh2`
+ Press **Choose SEP** and select your `.im4p`
+ Press **Choose Baseband** and select your `.bbfw`
+ Press **Choose Build Manifest** and select your `.plist`
+ Once you're ready, press **Go!**

iRestore will start a TSS check to see if the blobs are still valid. In case the verification will pass, the device will enter in recovery mode and if the screen turns green, it means that **iBEC** (a stripped down version of iBoot uploaded when performing a restore from Fake DFU) has been bootstrapped correctly.
![alt text](</img/FutureRestore/Recovery.png> "Recovery")
At this point futurerestore will start the extraction of the IPSW, the Baseband firmware and the SEP OS and will verify them.
![alt text](</img/FutureRestore/Extraction.png> "Extraction")
If they are marked as valid, the downgrade will then start.
![alt text](</img/FutureRestore/Installation.png> "Installation")
In the end you'll see `Done: restoring succeeded`... well, that speaks for itself.
![alt text](</img/FutureRestore/Completed.png> "Completed")
In order not to let iOS force you to upgrade, keep Wi-Fi off during the setup, disable automatic updates and install ASAP the [watchOS profile](https://s007.co/watchos5config) again. Now you're all set and ready to enjoy your iDevice in the iOS version you want!
