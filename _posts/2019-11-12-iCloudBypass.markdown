---
layout:     post
title:      "iCloud Lock Bypass"
subtitle:   "Bypass iCloud Activation Lock with checkm8"
date:       2019-11-12
author:     "Ivan"
header-img: "img/post-bg-icloud.jpg"
header-mask:  0.3
catalog:      true
tags:
    - iOS
    - bypass
    - iCloud
    - bootrom
---

One of the main iOS Security features discouraging thieves to steal iPhones or iPads is the incredible locking system running behind iOS: iCloud Activation Lock. Basically, if you restore an iPhone with a passcode and an iCloud account active (pretty much every time, since iCloud services run behind pretty much the entire OS), you need to unlock the device with the credentials of the previous iCloud account logged in the device. Without them, you can't just proceed, and that iDevice becomes an iPaperweight(®). But as discussed on a [previous post](/2019/09/29/checkm8/), a bootrom exploit called **checkm8** recently got release and it allows a partial unlock of the device.

> **Disclaimer:** this procedure is not intended to be followed on stolen iDevices. If you found one, return it to Apple and they could try to advice the legitimate owner (unless stupid data protection policy).

### What works, what doesn't

Well, the process will allow to skip the iCloud activation, so all the iCloud services - plus something else - will not work. Those includes, but are not limited to:
- Cellular (it actually works but for just temporary)
- iMessage
- All the iCloud services
- Screenshots

What works then? Well, first of all, the device itself, which is great. And most importantly, the Apple Store. So yeah, far from having your device unlocked, but for sure it's not a useless brick.

#### Requirements

- iCloud locked iDevice;
- an iMac, MacBook or an Hackintosh. If you don't know how to Hackintosh, you could take a look at [my guide](/2017/10/01/Hackintosh/);
- Internet connection;
- 20-30 minutes.

As for now, it's not possible to follow this procedure neither on Windows nor on Linux. Support for those, anyway, is being worked on as I'm writing now.

## Procedure

#### 1. checkra1n

Download [checkra1n](https://checkra.in), execute it and follow the procedures. Checkra1n will send your device in Recovery Mode, then an on-screen guide will show the combination of keys to press. This is needed to enter in **DFU**, a deep Apple Recovery, and it's recognisable because the screen will stay black but the device will be identifiable on iTunes/Finder. Follow the timing to press the keys and you should even be good to go. Wait for the jailbreak to be executed and the device to reboot.

#### 2. Install usbmuxd

Homebrew is an inline package manager for macOS. In case you didn't install it, open a terminal and paste the following:
```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
Once you're done, install usbmuxd - a socket daemon to multiplex connections from and to iOS devices - via
```
brew install usbmuxd
```

#### 3. SSH into the phone

In order to connect to the phone, we will use the SSH server installed with checkra1n. Open up a terminal window and type
```
iproxy 2222 44
```
Open another terminal window and
```
ssh root@localhost -p 2222
```
Password is **alpine**. This opens up an SSH connection as *root* user on *localhost* (our iDevice) on port 2222.

#### 4. Skip the Activation Lock

In order to skip the iCloud Activation Lock, we have to get rid of the `Setup.app`. To do so, we firstly have to mount our root partition in *read&write*
```
mount -o rw,union,update /
```
And then delete Setup.app
```
rm -rf /Applications/Setup.app
```

#### 5. Rejailbreak & SSH again

Proceed following **Step 1** and **Step 2** again

#### 6. Refresh gUICache

In order to let the changes take effect, restore the gUICache executing
```
uicache --all
```
And finally restart BackBoard, a Springboard daemon
```
killall backboardd
```

## Other possible ways

There is another possible theoretical application, but not sure if pratically appliable. We just saw how to bypass iCloud activation lock, but not how to spoof an "**Activate**" state to it. The would consist in copying the `.pem` Activation certificates from a device officially activated. The process, anyway, has some problems.

First of all, both devices needs *rw* on the `/` partition. Basically, they need to be jailbroken. But thankfully, now that checkra1n is out, any A11- device can be theoretically jailbroken. The other problem is that this method has never been tested and we don't really know the side effects of the process.

Plan would copying the **iPhoneActivation.pem**, located in `/System/Library/Lockdown` as well as **device_public_key.pem**, **device_private_key.pem** and **data_ark.plist**, in `/var/root/Library/Lockdown`, from the Activated device to the locked one. After a reboot verification state should be triggered as **passed**. At least on the paper. I'll try to take a look at it once possible.
