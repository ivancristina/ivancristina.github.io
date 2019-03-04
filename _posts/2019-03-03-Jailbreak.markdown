---
layout:     post
title:      "How to Jailbreak"
subtitle:   "With unc0ver for iOS 11.0 - 12.1.2"
date:       2019-03-03
author:     "Ivan"
header-img: "img/post-bg-unc0ver.jpg"
header-mask:  0.3
catalog:      true
tags:
    - Jailbreak
    - unc0ver
    - Guide
---

# Introduction

Here it is a complete guide on how to Jailbreak from iOS **11** up to iOS **12.1.2**. All the versions in between are jailbreakable, except on some configurations.
This guide is specific to just those iOS versions, all the version behind are jailbreakable, but the following versions still needs to be exploited.
As for now, the Apple **A12** devices (iPhone XS, XS Max, XR and iPad Pro 2018) are not exploitable due to some Apple hardening tehniques like *PAC*, or *Pointer Autenthication*. If you want to learn more, I'll make a specific post in the future. But if you're here for the mere guide, you'll probably stick with that.

### Requirements

In order to jailbreak you need very few but important requirements:
* An Apple **iPhone** (5S or later), **iPad** (Air/Mini 2 or successive) or **iPod** (6th gen or later)
* An iOS version later than **11**, but earlier then **12.1.2** - that's mandatory
* Internet access
* Time, patience and a bit of computer knowledge

## Preparations

* First of all remeber that (even though it is already stable) this is a **beta version**, use it with caution or wait for the final version if you're really unexpirienced
* Make sure that in Settings → General → iPhone Storage there are **OTA updates** (shown as *iOS 12.x*): in case there is one, delete it before starting with the jailbreaking process
![alt text](/img/in-post/JB/iStorage.png "Check for the OTA in here")
* In orded to definitively block the OTA update install the *tvOS profile* [clicking here](https://raw.githubusercontent.com/Jwhite077/NOOTA/master/tvOS_12_Beta_Profile.mobileconfig). It will ask you for your passcode and to reboot. Once you reboot, the updates are gone until you remove the profile. If you go to the update section you will indeed see an error
![alt text](/img/in-post/JB/tvOS.png "Install the tvOS profile")
* If you already used **rootlessJB** on iOS 12, uninstall it by pressing the “Uninstall” button within the tool

## Download

There are two ways to install unc0ver. Installing that from your PC or just installing them via a 3rd party store. The easiest method is the second one, but I'll show both.

#### Without PC

There are several 3rd party stores, but the most known are **Ignition** and **TweakBox*. I really prefer Ignition over TweakBox, so I'll use it for this example. Visit the [Ignition](https://app.ignition.fun/), choose between **Web View** or **App Download**. As for now, stick with Web View, you could download the app later. Go into the Jailbreak session and download the latest version of **unc0ver** jailbreak. It could be called unc0ver *-new beta* or just unc0ver. Download the latest one - as for the time I'm writing it's *-new beta*.

Install it with the *Get* button, and click install at the popup that will open. Don't open directly unc0ver, go to Settings → General → Profiles, click on the one under tvOS (it could have a different name from the screenshot) and then click *Trust*.
![alt text](/img/in-post/JB/Profiles.png "Trust the profile")

Now the app is verified and you can open it.
![alt text](/img/in-post/JB/unc0ver Icon.png "You can now open unc0ver")

#### With PC

If you already downloaded unc0ver via Ignition, skip this step and go to the [next one](/2019/03/03/Jailbreak/#jailbreaking).

I'll start saying that manually installing the IPA will imply that the app will have a 7 days verification, after that you have to resign it with your PC, except in case you own an Apple Developer account (which costs $99/year) or an AppBlade one. In that case the app will be signed to 365 days, but if you're reading this guide I really doubt you are a developer.

By this way you will instead download the unsigned app and install it manually via a tool called **Cydia Impactor**, developed by saurik itself, the developer of Cydia. Download it from [its website](http://www.cydiaimpactor.com/), choosing your OS build.

Also, download unc0ver from here. Pick the latest [pre-release](https://github.com/pwn20wndstuff/Undecimus/releases). It will show up in the assets section as an `.ipa` file (something like `Undecimus-vX.X.X-bXX.ipa`).

Once you're done connect your iPhone to your PC/Mac via USB cable, open Impactor and grab the `.ipa` file into Impactor. It will ask you to put your Apple ID email and password. Don't worry, those datas are sent **just** to Apple in order to sign the app with your Apple ID.

Once you're done, go back to Settings → General → Profiles and Trust your own account. The app could now be run.

## Jailbreaking

You will see a giant button called **Jailbreak**. Once you're ready, click it. Once you click it, you end up restarting or respringing: I'll talk about it later.
![alt text](/img/in-post/JB/unc0ver.png "Press the Jailbreak button")

Click it now. The device will run the exploit and if that's successful it will reach the first stage, the **snapshot renaming"**. Now, press *OK* and the device will restart.
![alt text](/img/in-post/JB/Snapshot Rename.png "First step done")

It could happen that reached the step **2/38** the device could *panic* because the exploit fails and the device will automatically reboot. Don't mind, that's normal, you just have to retry.
![alt text](/img/in-post/JB/unc0ver Exploit.png "The device could panic at step 2/38")

Once again, open unc0ver and click the Jailbreak button once again. If everything goes well, you will reach the **bootstrap extraction** stage. Press OK and reboot again.
![alt text](/img/in-post/JB/Bootstrap Extracted.png "First step done")

That should be the last time: press Jailbreak again. At a certain point the device will **respring**: the screen will go black and will dim, at the center of the screen there should be a rotating circle (as when the device shutdown). Wait for it to finish and you should finally see **Cydia**!
![alt text](/img/in-post/JB/Cydia Icon.png "Cydia appeared")

Now the jailbreak is activated, but remember that this is a ***semi-unthetered*** jailbreak. That means that whenever you turn off your device you will re-enter in jailed mode. But that's not a big deal: open unc0ver, press the *Jailbreak* button and after a respring you will reactivate your jailbreak.

Remember to update even the unc0ver app itself from Ignition or download and resign the new IPA via Impactor in order to always have the most stable experience! Once updated, open the app and press the *Re-Jailbreak* button.
![alt text](/img/in-post/JB/unc0ver ReJailbreak.png "Press the Re-Jailbreak button")

## Setup Cydia

Now it's time to set up Cydia. First of all open it up and you will see this welcome screen.
![alt text](/img/in-post/JB/Cydia.png "Welcome")

Go into the *Sources* tab on the bottom, and you will see this screen.
![alt text](/img/in-post/JB/Cydia Sources.png "Sources tab")

Those are the **repositories**, where all the **tweaks** are stored and distributed from. Most of the tweaks are free, but some are paid. ***DO NOT PIRATE THEM***, for various reasons. First of all, because developers spend their time offering us these wonderful customizations which we would never have and supporting them paying some of their tweaks is the less we could do. Secondly, because pirated tweaks could lead to **bootloops**, forcing you to restoring your iDevice, losing both the jailbreak and ***all*** **your data**. Always download them from the official repo (usually they are *BigBoss*, *Chariz* or *Dynastic*). If you are not sure about the repo of the tweak you're searching for, Google "`name of your tweak here` repo". You'll surely find it.
![alt text](/img/in-post/JB/Cydia Sources.png "Sources tab")

Whenever you *Refresh* the sources a red banner will appear. By doing that you'll reload the *index* of every repo and if there are updates, they will show up. It's usually better to update your tweaks in order to improve their stability. If any *Essential update* will show up, please do a *Complete update*. Those packages are updated from the maintainer of your jailbreak and makes your jailbreak more stable.
![alt text](/img/in-post/JB/Cydia Necessary Update.png "Perform a complete update")

But how to add a repo? That's super easy. Most of the repos now have specific button, prompting to add the repo, but it could also happen that you should manually add it. In that case press the *Edit* button on top-right, then *Add* and pasting the URL of the repo and finally *Add source*. In this case I'll add the `http://tigisoftware.com/cydia`, the repo of **Filza**. We'll talk about it later.
![alt text](/img/in-post/JB/Cydia Add Sources.png "Add the source")

If you want to delete a repo, simply press *Edit* and then delete it with the red button next to it.
![alt text](/img/in-post/JB/Cydia Source Remove.png "Remove source by this way")

### Installing tweaks

Here comes the fun part: installing tweaks. Tweaks are packages which customize your system, just by adding customizations or even adding apps. In this example we'll install a famous jailbroken app called **Filza**. It's a package manager with ***root*** priviledges. If you are unexpirienced don't use it, but it's always good having it.

In Cydia, refresh the sources, then go to the *Search* tab and write your package name. There will be more than one result, in this case pick the **64bit** version (since you are running unc0ver, you must be 64bit).
![alt text](/img/in-post/JB/Cydia Search Filza.png "Search for the packages here")

A popup window will show up. If you want to install something else *Continue Queuing*, otherwise just *Confirm*.
![alt text](/img/in-post/JB/Cydia Installation Confirm.png "Press confirm to install")

You'll se a **verbose** output of what's happening.
![alt text](/img/in-post/JB/Cydia Filza Installation.png "Verbose output")

Once you'll read *Restart SpringBoard* just press it. After a respring you'll see your new tweaks or your new apps!
![alt text](/img/in-post/JB/Cydia Restart Springboard.png "Press Restart SpringBoard")

And now you should see Filza installed!
![alt text](/img/in-post/JB/Filza Icon.png "Here it is")

If you want to remove a tweak you installed, go to the *Installed* tab, open the tweak you want to remove, click *Edit* and then *Remove*. Even in this case you can queue more actions.
![alt text](/img/in-post/JB/Cydia Installed.png "This is the Installed tab")

As I said tweaks can also customize various aspects of iOS, in this case you can see the settings before and after installing the tweak **System Info**.
![alt text](/img/in-post/JB/iOS Info.png "Before")
![alt text](/img/in-post/JB/iOS Info Tweak.png "After")

As I said, periodically check for updates by refreshing the sources. If there are some updates, they will show up in the *Changes* section.
![alt text](/img/in-post/JB/Cydia Changes.png "Updates will show up here")

### The End

You are now ready to ~~mess~~ play with your device.

You can find my socials in the footer of this web page, in case you want to follow me or need urgent help.

> Happy Jailbreaking!
