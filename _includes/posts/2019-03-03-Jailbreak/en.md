# Introduction

Here it is a complete guide on how to Jailbreak from iOS **11** up to iOS **12.4**. All the versions in between are jailbreakable, except for **12.3.x** and some configurations. That because Ned Williamson's exploit *sock_puppet* - previously patched by Apple on 12.3 and 12.3.1 - has been strangely unpatched without any explanation on 12.4.
This guide is specific to just those iOS versions. All the version behind are jailbreakable, but the following versions still needs to be exploited.
As for now, the Apple **A12** devices (iPhone XS, XS Max, XR and iPad Pro 2018) are just **partially** exploitable due to some Apple hardening tehniques like _PAC_, or _Pointer Autenthication_. If you want to learn more, I'll make a specific post in the future. But if you're here for the mere guide, you'll probably stick with that.

### Requirements

In order to jailbreak you need very few but important requirements:

-   An Apple **iPhone** (5S or later), **iPad** (Air/Mini 2 or successive) or **iPod** (6th gen or later)
-   An iOS version higher than **11**, but lower then **12.4** - **it's mandatory_** it's not **12.3.x** neither
-   Internet access
-   Time, patience and a bit of computer knowledge

## Preparations

-   First of all remeber that (even though it is already stable) this is a **beta version**, use it with caution or wait for the final version if you're really unexpirienced
-   Make sure that in Settings → General → iPhone Storage there are **OTA updates** (shown as _iOS 12.x_): in case there is one, delete it before starting with the jailbreaking process
    ![alt text](/img/Jailbreak/iStorage.png "Check for the OTA in here")
-   In orded to definitively block the OTA update install the _tvOS profile_ [clicking here](https://raw.githubusercontent.com/Jwhite077/NOOTA/master/tvOS_12_Beta_Profile.mobileconfig). It will ask you for your passcode and to reboot. Once you reboot, the updates are gone until you remove the profile. If you go to the update section you will indeed see an error
    ![alt text](/img/Jailbreak/tvOS.png "Install the tvOS profile")
-   If you already used **rootlessJB** on iOS 12, uninstall it by pressing the “Uninstall” button within the tool

## Download

There are two ways to install unc0ver. Installing that from your PC or just installing them via a 3rd party store. The easiest method is the second one, but I'll show both.

#### Without PC

There are several 3rd party stores, but the most known are **Ignition** and **TweakBox**. I really prefer Ignition over TweakBox, so I'll use it for this example. Visit the [Ignition](https://app.ignition.fun/), choose between **Web View** or **App Download**. As for now, stick with Web View, you could download the app later. Go into the Jailbreak session and download the latest version of **unc0ver** jailbreak. It could be called unc0ver _-new beta_ or just unc0ver. Download the latest one - as for the time I'm writing it's _-new beta_.

Install it with the _Get_ button, and click install at the popup that will open. Don't open directly unc0ver, go to Settings → General → Profiles, click on the one under tvOS (it could have a different name from the screenshot) and then click _Trust_.
![alt text](/img/Jailbreak/Profiles.png "Trust the profile")

Now the app is verified and you can open it.
![alt text](</img/Jailbreak/unc0ver Icon.png> "You can now open unc0ver")

#### With PC

If you already downloaded unc0ver via Ignition, skip this step and go to the [next one](/2019/03/03/Jailbreak/#jailbreaking).

I'll start saying that manually installing the IPA will imply that the app will have a 7 days verification, after that you have to resign it with your PC, except in case you own an Apple Developer account (which costs $99/year) or an AppBlade one. In that case the app will be signed to 365 days, but if you're reading this guide I really doubt you are a developer.

By this way you will instead download the unsigned app and install it manually via a tool called **Cydia Impactor**, developed by saurik itself, the developer of Cydia. Download it from [its website](http://www.cydiaimpactor.com/), choosing your OS build.

Also, download unc0ver from here. Pick the latest [pre-release](https://github.com/pwn20wndstuff/Undecimus/releases). It will show up in the assets section as an `.ipa` file (something like `Undecimus-vX.X.X-bXX.ipa`).

Once you're done connect your iPhone to your PC/Mac via USB cable, open Impactor and grab the `.ipa` file into Impactor. It will ask you to put your Apple ID email and password. Don't worry, those datas are sent **just** to Apple in order to sign the app with your Apple ID.

Once you're done, go back to Settings → General → Profiles and Trust your own account. The app could now be run.

## Jailbreaking

Whenever you open unc0ver go to the _Settings_ tab and make sure that you have the default configurations. As for the time I'm writing, these are the default ones.
![alt text](</img/Jailbreak/unc0ver Settings.png> "Leave everything as it is")

Ok, now go back to the home screen of unc0ver. You will see a giant button called **Jailbreak**. Once you're ready, click it. Once you click it, you end up restarting or respringing: I'll talk about it later.
![alt text](/img/Jailbreak/unc0ver.png "Press the Jailbreak button")

Click it now. The device will run the exploit and if that's successful it will reach the first stage, the "**snapshot renaming**". Now, press _OK_ and the device will restart.
![alt text](</img/Jailbreak/Snapshot Rename.png> "First step done")

It could happen that reached the step **2/38** the device could _panic_ because the exploit fails and the device will automatically reboot. Don't mind, that's normal, you just have to retry.
![alt text](</img/Jailbreak/unc0ver Exploit.png> "The device could panic at step 2/38")

Once again, open unc0ver and click the Jailbreak button once again. If everything goes well, you will reach the "**bootstrap extraction**" stage. Press OK and reboot again.
![alt text](</img/Jailbreak/Bootstrap Extracted.png> "First step done")

That should be the last time: press Jailbreak again. At a certain point the device will **respring**: the screen will go black and will dim, at the center of the screen there should be a rotating circle (as when the device shutdown). Wait for it to finish and you should finally see **Cydia**!
![alt text](</img/Jailbreak/Cydia Icon.png> "Cydia appeared")

Now the jailbreak is activated, but remember that this is a **_semi-unthetered_** jailbreak. That means that whenever you turn off your device you will re-enter in jailed mode. But that's not a big deal: open unc0ver, press the _Jailbreak_ button and after a respring you will reactivate your jailbreak.

Remember to update even the unc0ver app itself from Ignition or download and resign the new IPA via Impactor in order to always have the most stable experience! Once updated, open the app and press the _Re-Jailbreak_ button.
![alt text](</img/Jailbreak/unc0ver ReJailbreak.png> "Press the Re-Jailbreak button")

## Setup Cydia

Now it's time to set up Cydia. First of all open it up and you will see this welcome screen.
![alt text](/img/Jailbreak/Cydia.png "Welcome")

Go into the _Sources_ tab on the bottom, and you will see this screen.
![alt text](</img/Jailbreak/Cydia Sources.png> "Sources tab")

Those are the **repositories**, where all the **tweaks** are stored and distributed from. Most of the tweaks are free, but some are paid. **_DO NOT PIRATE THEM_**, for various reasons. First of all, because developers spend their time offering us these wonderful customizations which we would never have and supporting them paying some of their tweaks is the less we could do. Secondly, because pirated tweaks could lead to **bootloops**, forcing you to restoring your iDevice, losing both the jailbreak and **_all_** **your data**. Always download them from the official repo (usually they are _BigBoss_, _Chariz_ or _Dynastic_). If you are not sure about the repo of the tweak you're searching for, Google "`name of your tweak here` repo". You'll surely find it.

Whenever you _Refresh_ the sources a red banner will appear. By doing that you'll reload the _index_ of every repo and if there are updates, they will show up. It's usually better to update your tweaks in order to improve their stability. If any _Essential update_ will show up, please perform a _Complete update_. Those packages are updated from the maintainer of your jailbreak and makes your jailbreak more stable.
![alt text](</img/Jailbreak/Cydia Necessary Update.png> "Perform a complete update")

But how to add a repo? That's super easy. Most of the repos now have specific button in their website, prompting to add the repo, but it could also happen that you should manually add it. In that case press the _Edit_ button on top-right, then _Add_ and pasting the URL of the repo and finally _Add source_. In this case I'll add `http://tigisoftware.com/cydia`, the repo of **Filza**. We'll talk about it later.
![alt text](</img/Jailbreak/Cydia Sources Add.png> "Add the source")

If you want to delete a repo, simply press _Edit_ and then remove it with the red button next to it.
![alt text](</img/Jailbreak/Cydia Sources Remove.png> "Remove source in this way")

### Installing tweaks

Here comes the fun part: installing tweaks. Tweaks are packages which customize your system, by adding functionalities or even adding apps. In this example we'll install a famous jailbroken app called **Filza**. It's a file manager with **_root_** priviledges. If you are unexpirienced don't use it, but it's always good having it.

In Cydia, refresh the sources, then go to the _Search_ tab and write your package name. There will be more than one result, in this case pick the **64bit** version (since you are running unc0ver, you must be on 64bit hardware).
![alt text](</img/Jailbreak/Cydia Search Filza.png> "Search for the packages here")

A popup window will show up. If you want to install something else _Continue Queuing_, otherwise just _Confirm_.
![alt text](</img/Jailbreak/Cydia Installation Confirm.png> "Press confirm to install")

You'll se a **verbose** output of what's happening.
![alt text](</img/Jailbreak/Cydia Filza Installation.png> "Verbose output")

Once you'll read _Restart SpringBoard_ just press it. After a respring you'll see your new tweaks or your new apps in action!
![alt text](</img/Jailbreak/Cydia Restart SpingBoard.png> "Press Restart SpringBoard")

And now, indeed, you should see Filza installed.
![alt text](</img/Jailbreak/Filza Icon.png> "Here it is")

If you want to remove a tweak you installed, go to the _Installed_ tab, open the tweak you want to remove, click _Edit_ and then _Remove_. Even in this case you can queue more actions.
![alt text](</img/Jailbreak/Cydia Installed.png> "This is the Installed tab")

As I said tweaks can also customize various aspects of iOS, in this case you can see the settings before and after installing the tweak **System Info**.
![alt text](</img/Jailbreak/iOS Info.png> "Before")
![alt text](</img/Jailbreak/iOS Info Tweak.png> "After")

Lastly, periodically check for updates by refreshing the sources. If there are some updates, they will show up in the _Changes_ section.
![alt text](</img/Jailbreak/Cydia Changes.png> "Updates will show up here")

### The End

You are now ready to ~~mess~~ play with your device.

You can find my socials in the footer of this web page, in case you want to follow me or need urgent help.

> Happy Jailbreaking!
> Ivan
