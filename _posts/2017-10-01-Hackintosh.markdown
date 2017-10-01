---
layout:     post
title:      "Hackintosh"
subtitle:   "Think really different"
date:       2017-10-01
author:     "Ivan"
header-img: "img/post-bg-hackintosh.jpg"
tags:
    - OS
    - macOS
    - Hackintosh
    - Blog
---


![java-javascript](/img/in-post/post-js-version/HackintoshSmall.png)

It wasn't very easy to accomplish, but dang! An Hackintosh (almost) completely working!

The process is not reccomended for noobs (although I am one myself), unless you really want to spend a lot of time to even try to make it boot, but I ensure you that the overall result will be worth the hours of headache you'll get later!

# My build

So let's start with my build. I assembled it something like 7 months ago, and it costed me around €500. Now it could cost like 100 uro less, but I'm pretty happy for the result I got with those money anyway.

My entire setup has been built with:

- an **<a href="http://amzn.eu/h3i8nZy" target="_blank">MSI H270 Gaming M3</a>**, a 200 serie mobo, with a bunch of RGB LEDs and an overall fancy aestetich. Worth the €126 I spent, now at €116*.
- an **<a href="http://amzn.eu/5WilklT" target="_blank">Intel Core i5-7500</a>**, a 3.4Ghz with 6Mb of cache Kaby Lake. Bought at €211, now at €184*
- a **<a href="http://amzn.eu/1DicCyw" target="_blank">Western Digital Blue</a>** 1 Tb @ 7200RPM HDD. Really solid. Very nice product for the 51 euro I spent for it* (price it has kept).
- a single slot of **<a href="http://amzn.eu/j4PcU9x" target="_blank">Ballistix Sport LT</a>** RAM. 8 Gb DDR4 at 2400Mhz clock. A nice deal for €54, considering now it costs more than €10 more.
- a **<a href="http://amzn.eu/7L74v01" target="_blank">Corsair VS450</a>** PSU, 80+ certification and huge quality that you can afford at €41* (as I did, for instance). Bought because didn't plan about a GPU, **now regretting** a bit if I have to tell you.
- and at the end, the <a href="http://amzn.eu/6XEPdiw" target="_blank">Carbide Spec-03</a>. Fancy ATX case, with a nice glass (plastic, in reality) panel, with 2 quiet Corsair fans inside (one LED and one not). Kept its price of €65.

> *Prices are referred to those on Amazon.it in March 2017*

So you could ask... why not a more powerful PSU? Why not an external GPU instead of that sh**ty HD 630? And moreover, why not a damn SSD?
Well. I was a stupid. A **very poor stupid**. Dind't think and didn't have money. Moreover expecially in these months, along with the price of high end GPUs for bitcoin mining *(thanks dears, hope you to loose all the bitcoin you mined)*, both italian physical and virtual shops (like Amazon) well thought to increase prices. For everything! Even CPUs, low end GPUs and SSD. Those in particular actually costs **almost the double** of the "real" price.

About the Motherboard, **totally worth it**. H serie because I didn't need the Z feautures, and also because as a (poor) student, I don't have enough money to afford a Z Mobo and a K CPU. Anyway nice to see, very well built and managed by MSI softwares in Windows. With Hackintosh... you know, newer not always means better, expecially if you basically adapting a closed source OS with non proprietary hardware. But some patches, and I was good to go.
The CPU... DAMN, if **I hated it!** I mean, it's actually powerful an power-friendly, but the price was actually a bit high *IMHO*. And as I told before... It was a mess let it work in Sierra, until finally the 2017 Mac serie came out, along with their new Kaby Lake models. That made everything **ALOT EASIER**. In fact, before the 10.12.6 update (with the new Kaby Lake kernel support), in order to let Kaby Lake run you had to <a href="https://www.tonymacx86.com/threads/new-testing-intel-7th-generation-kaby-lake-cpus-200-series-motherboards-in-macos.219877/" target="_blank">spoof your CPU and GPU ID</a>, and some of the times it wouldn't even boot after that (like in my case .-.). Make the GPU work with full acceleration was a mess, but at the end instead of the fu**ing 7mb of virtualized nvram, I managed to get the GPU working along all its 1536 MB of memory. And then, thanks to the 10.12.6 update, I finally also managed to power the CPU at its full power.

![java-javascript](/img/in-post/post-js-version/Info.png)

The following patches (needed in 10.12.5 or before in order to let the CPU and Integrated Graphics work) are indeed no more needed on Sierra 10.12.6 or in any version of the new Apple macOS version, <a href="https://www.tonymacx86.com/threads/macos-high-sierra-is-now-available-on-the-mac-app-store.231773/" target="_blank">High Sierra!</a> *(what a huge fantasy, though...)*

```html
<key>FakeID</key>
<dict>
	<key>IntelGFX</key>
	<string>0x19168086</string>
```
```html
<key>Devices</key>
<dict>
	<key>AddProperties</key>
	<array>
		<dict>
			<key>Device</key>
			<string>IntelGFX</string>
			<key>Key</key>
			<string>AAPL,GfxYTile</string>
			<key>Value</key>
			<data>
			AQAAAA==
			</data>
		</dict>
	</array>
```

You could find my <a href="https://github.com/ivancristina/ivancristina.github.io/raw/master/resources/config.plist" target="_blank">complete config.plist here</a>.

# How To Hackintosh

### BIOS Config (may vary)

* **Step 1:** Load Optimised Default
* **Step 2:** IN BIOS Tab
	Windows 8/10 Features = Other OS
	Storage Boot Option Control = UEFI
* **Step 3:** Peripherals Tab
	Initial Display Output = IGFX
	XHCI Handoff = Enabled (In USB Configuration)
* **Step 4:** Chipset Tab
	VT-D = Disabled
	Internal Graphics = Enabled
	DVMT Pre-Allocated = 64M
* **Step 5:** Save and Exit

### What To Download

You need to download some files to get things work. These files are necessary for the entire session of the Mac OS installation.

##### Bootloader:

Latest version of <a href="https://sourceforge.net/projects/cloverefiboot/" target="_blank">Clover Bootloader</a>. This Bootloader let you boot both MacOS, Windows and Linux distros, all in one and with a customizable interface.

##### Utilities:

They're apps or scripts that will help you with the initialization, installation and configuration of Hackintosh. Download the latest version according to your macOS version
* <a href="http://mackie100projects.altervista.org/download-clover-configurator/" target="_blank">Clover Configurator</a>. If you encounter the **7mb bug** use the Classic version instead of the Vibrant. This apps let you configure your bootloader settings with a fancy UI, instead than in command line (available also)
* <a href="https://www.tonymacx86.com/resources/categories/tonymacx86-downloads.3" target="_blank">UniBeast, MultiBeast and KextBeast</a>.
Those apps respectively let you create a bootable USB, configure your Hackintosh machine and install some primary drivers in **post-installation**
* <a href="https://github.com/toleda/audio_CloverHDMI/blob/master/audio_cloverHDMI-130.command.zip?raw=true" target="_blank">Toleda's audio_cloverHDMI-130.command</a>. This script basically allows you to enable in a few clicks the **HD630 onboard audio**.

##### Kexts:

Kexts are basically drivers, which let you use your devices in a *plug&play-like* way.

* <a href="https://github.com/vit9696/AppleALC/releases" target="_blank">AppleALC.kext</a> by <a href="https://github.com/vit9696" target="_blank">vit9696</a> (Github repo <a href="https://github.com/vit9696/AppleALC" target="_blank">here</a>)
* <a href="https://github.com/vit9696/Lilu/releases" target="_blank">Lilu.kext</a> by <a href="https://github.com/vit9696" target="_blank">vit9696</a> (Github repo <a href="https://github.com/vit9696/Lilu" target="_blank">here</a>)
* <a href="https://github.com/vit9696/Shiki/releases" target="_blank">Shiki.kext</a> by <a href="https://github.com/vit9696" target="_blank">vit9696</a> (Github repo <a href="https://github.com/vit9696/Shiki" target="_blank">here</a>)
* <a href="https://github.com/RehabMan/OS-X-USB-Inject-All/tree/master/XHCI-200-series-injector.kext" target="_blank">XHCI-200-series-injector.kext</a> by <a href="https://github.com/RehabMan" target="_blank">RehabMan</a> (Github repo <a href="https://github.com/RehabMan/OS-X-USB-Inject-All" target="_blank">here</a>)
* <a href="https://bitbucket.org/RehabMan/os-x-usb-inject-all/downloads/" target="_blank">USBInjectAll.kext</a> by <a href="https://github.com/RehabMan" target="_blank">RehabMan</a> (Bitbucket repo <a href="https://bitbucket.org/RehabMan/os-x-usb-inject-all/src" target="_blank">here</a>)

Other kexts you'll need later: *(in post installation, with MultiBeast)*

* AtherosE2200Ethernet.kext
* FakeSMC.kext
* IntelMausiEthernet.kext
* RealtekRTL8111.kext

## Installation

##### Prerequisites

* A **200 Series Motherboard** with Intel 7th Gen *(KabyLake)* Processor
* A ***working*** Mac, Hackintosh or Virtual Machine (VM is not reccomended though) - without one of those you can’t move forward.
* USB stick, **16GB** or larger (some reported they got it working even with an 8GB stick, not my case though)

##### Get macOS

1. Go to your Mac, Hackintosh or VM and open the Mac App Store
2. Log in with your Apple ID
3. Download macOS Sierra (10.12.6) or High Sierra *- this guide is based on 10.12.6, but is appliable even to High Sierra with some modifications*
4. After the download finishes the setup screen will appear you should **Quit** the app from the Dock. You can see the application in **/Applications/Install MacOS Sierra.app**

##### Preparing USB

***If the below guide didn't work for you then try <a href="https://www.tonymacx86.com/threads/updated-for-multibeast-9-2-1-and-sierra-10-12-6-sierra-on-200-series-with-kabylake-processor.218494/page-12#post-1586314" target="_blank">this one instead</a>***

1. Open Disk Utilities –> Select USB and Erase using **Mac OSX Extended Journaled** –> **GUID Partition Map** –> **Erase**
2. Then open Unibeast –> Choose USB –> Then Select **UEFI** –> After that select Sierra
3. Open USB’s EFI partition –> EFI/Clover –> Open config.plist Using Clover Configurator
4. Make the necessaries edits (not needed in our case)

In case you have a build equal or very similar to mine, rename the existing **conf.plist** as **orig-config.plist** and paste mine there.

***Move ALL the downloaded Files into USB, create a folder and paste it there.***

### USB ports tweaking
> *Not needed with my config.plist*

*After Creating Bootable USB, you should do some tweaks on the USB if your motherboard has no USB 2.0 Port. If you have USB 2.0, then the below steps is not needed, although I reccomend you to follow these steps anyway*

Add these configurations in config.plist using Clover Configurator. ***(Patches already applied in my config.plist)***

**Increase port limit**

Kernel and Kext Patches –> KextToPatch –> +

```html
Name: AppleUSBXHCIPCI
Find: 83bd74ff ffff10
Replace: 83bd74ff ffff1b
Comment: Increase port limit
```
![java-javascript](/img/in-post/post-js-version/PortLimit.png)

**Rename EHC to EH0**

ACPI –> DSDT –> Patches –> +

This two patches would let **USBInjectAll.kext** load:

```html
Comment: change EHC1 to EH01
Find: 45484331
Replace: 45483031
```
```html
Comment: change EHC2 to EH02
Find: 45484332
Replace: 45483032
```
![java-javascript](/img/in-post/post-js-version/EHx1.png)
![java-javascript](/img/in-post/post-js-version/EHx2.png)

Move **USBInjectAll.kext** & **XHCI-200-series-injector.kext** to USB’s EFI partition **/EFI/Clover/kexts/Other**.

##### Install MacOS Sierra

1. Turn on the computer
2. Press the hotkey **Canc** to choose boot device *(it may differ on your motherboard)*
3. Select USB
4. At Clover boot screen, select **Boot Mac OS X from USB**
5. When you arrive at the Installer, choose a language.
6. In the top menu bar select Utilities and open **Disk Utility**
7. Highlight your target drive for the Sierra installation in the left column.
8. Click Erase button
9. **Name:** type Sierra (You can rename it later)
10. **Format:** choose OS X Extended (Journaled)
11. **For Scheme:** Choose GUID Partition Map
12. Click **Erase**
13. Close Disk Utility
14. Highlight your target drive for the Sierra installation then click continue.
15. After the first restart Press the hotkey Canc to choose boot device
16. Select USB
17. At Clover boot screen, Choose MacOS X **from the HDD** you installed.

***If you don’t know how to install then follow the steps in the <a href="https://www.tonymacx86.com/threads/unibeast-install-macos-sierra-on-any-supported-intel-based-pc.200564/" target="_blank">Installation Guide</a>***

## Post-Installation

After the successful installation, you must install necessary kext and patches to get things work. These are the same thing that we were doing after the installation of Windows OS. In Windows, drivers are in a package and it automatically installed within few clicks, while with macOS we should **manually** do these steps. As I said before, after the release of macOS 10.12.6 everything became easier because 10.12.6 brings the native support for Kabylake Processors. Also, tonymacx86 released a new version of the MultiBeast, which supports 200 Series Motherboard with 7th generation Kabylake processor. *Imagine how many steps you had to do before...*

#### Post Installation Using MultiBeast

* **1st Step** = Copy all the downloaded files to the desktop.
* **2nd Step** = Open Multibeast –> Quick Start –> **UEFI Boot Mode**
![java-javascript](/img/in-post/post-js-version/UEFI.png)

* **3rd Step** = Drivers –> Audio –> Check both **ALC1220** and **100/200 Series Audio**. *(I also select the 5.1 Output as I have it built onboard)*
![java-javascript](/img/in-post/post-js-version/Audio.png)

*If you have different codec then select the codec that you want. Codec version can be found on the specification of your Motherboard*

*There are two methods to get Audio Work. This is the First Method If this not works For you then Try method Two in “Post Installation Using Clover Configurator/Audio” Section.*


* **4th Step** = Drivers –> Network –> Check **IntelMausiEthernet v2.3** *(I also install RealtekRTL8111 v2.2.1)*
![java-javascript](/img/in-post/post-js-version/Network.png)

* **5th Step** = Drivers –> USB –> Check **Increase Max Port Limit 200 Series**
![java-javascript](/img/in-post/post-js-version/PortLimit.png)

* **6th Step** = Bootloader –> Check **Clover + Emulated NVRAM**
![java-javascript](/img/in-post/post-js-version/CloverBootloader.png)

***Note: After installing Multibeast don’t forget update clover to the latest version, you can find the link above.***

* **7th Step** = Customize –> Graphics Configuration –> Select on **Intel HD 6xx**
![java-javascript](/img/in-post/post-js-version/Graphics.png)

* **8th Step** = Final Build Configuration Build –> ***Install***
![java-javascript](/img/in-post/post-js-version/MultiBeast.png)

#### Post Installation Using Clover Configurator
> *Not needed with my config.plist*

##### Basic Configuration

* Open Clover Configurator Then mount EFI Partition if not mounted (Multibeast will automatically mount the EFI partition)
* Fix Random Restart problem when system shutdown by Selecting **FixShutdown_0004** under ACPI –> Fixes
![java-javascript](/img/in-post/post-js-version/Shutdown.png)

* **XMPDetection=Yes** (If your RAM clock speed is higher than 2133MHz, like in my case)
![java-javascript](/img/in-post/post-js-version/XMP.png)

***Don’t Close Clover Configurator. Add all entries from the below steps or else you should open the Clover Configurator for every step.***

#### Intel HD Graphics 630 With QuickSync and iTunes DRM Contents

Open Clover Configurator if not open.

**Add patches in DSDT**

ACPI –> DSDT –> Patches –> +

```html
Comment: change GFX0 to IGPU
Find: 47465830
Replace: 49475055
```
![java-javascript](/img/in-post/post-js-version/IGPU.png)

* Add Custom BootFlag **shikigva=1** In Boot –> Custom Flags
![java-javascript](/img/in-post/post-js-version/shikigva.png)

* Copy **Shiki.kext** and **AppleALC.kext** and paste them in to **EFI drive/EFI/Clover/kexts/Other**.
![java-javascript](/img/in-post/post-js-version/kextsOther.png)

##### Audio Method Two

Open Clover Configurator if not open.

* Make sure that **Lilu.kext** and **AppleALC.kext** ( If you use the above step then AppleALC will already be in the **kexts/Other** folder) are installed if not install these Kexts.
* Add patches in Clover Configurator

**Add patches in DSDT if not present.**

ACPI –> DSDT –> Patches –> +

```html
Comment: change HDAS to HDEF
Find: 48444153
Replace: 48444546
```
![java-javascript](/img/in-post/post-js-version/HDxx.png)

**Change Audio ID to 1 or 2 if not.**

In the latest version of **AppleALC.kext**, audio ID 1 or 2 or 11 is fully supported for ALC1220 and ALCS 1220A codecs.

Devices –> Audio –> Change it to **1** or **2** or **11**
![java-javascript](/img/in-post/post-js-version/AudioInjection.png)

Run **audio_cloverHDMI-130.command** to get HDMI Audio working if you want. If this method of HDMI Audio didn’t work for you then follow the <a href="https://www.tonymacx86.com/threads/quick-fix-200-series-kaby-lake-audio-onboard-and-or-hd-6x0-hdmi.221618/" target="_blank">toleda guide on how to enable HDMI Audio</a>.
![java-javascript](/img/in-post/post-js-version/toledaHDMI.png)

#### SMBIOS

We need to change the SMBIOS to iMac 18.1 or 18.2 or 18.3 because these are the SMBIOS for the Kabylake processors. This is necessary because without SMBIOS the system will not boot and other features like power management, iMessage, Graphics acceleration won’t work.

For the perfect configuration of SMBIOS head over to <a href="http://www.everymac.com/systems/by_year/macs-released-in-2017.html" target="_blank">this link</a> and choose SMBIOS that matches your processor.

In my case, I changed the SMBIOS to 18.2 (cause it's the SMBIOS of the i5-75000 powered iMac).
![java-javascript](/img/in-post/post-js-version/SMBIOS.png)

##### USB Power Management

Those who looking for the proper USB Power management go to the <a href="https://www.tonymacx86.com/threads/guide-usb-power-property-injection-for-sierra-and-later.222266/" target="_blank">USB power property injection for Sierra (and later) Guide</a> by RehabMan.

Also, don’t forget to add patches in Kernal and Kext Patches –> Kext To Patch

```html
Name: com.apple.driver.usb.AppleUSBXHCIPCI
Find: 83bd74ff ffff10
Replace: 83bd74ff ffff1b
Comment: change 15 port limit to 26 in XHCI kext (100-series)
```
```html
Name: AppleUSBXHCIPCI
Find: 837d8c10
Replace: 837d8c1b
Comment: Change 15 port limit to 24 in XHCI kext
```
![java-javascript](/img/in-post/post-js-version/AppleUSBXHCIPCI.png)

As you may have seen I didn't apply the first patch, because I didn't need it.

### iMessage
<a href="https://www.tonymacx86.com/threads/an-idiots-guide-to-imessage.196827/" target="_blank">An iDiot's Guide To iMessage</a> it is the best iMessage Guide we can found on the internet, just follow this guide straightforward.

### Geekbench Scores

The results are very nice, considering we're talking about an Os running on non-natively supported hardware.
![java-javascript](/img/in-post/post-js-version/Device.png)
![java-javascript](/img/in-post/post-js-version/Score.png)
![java-javascript](/img/in-post/post-js-version/SCComparison.png)
![java-javascript](/img/in-post/post-js-version/MCComparison.png)
![java-javascript](/img/in-post/post-js-version/OpenCL.png)
![java-javascript](/img/in-post/post-js-version/OpenCLComparison.png)

### Frequently Asked Questions

* **Question:** After the installation macOS won’t boot from the HDD drive. It only boots from the USB!
	**Answer:** In this case first of all you need to boot using USB. After you reached the desktop copy the entire EFI folder from USB to your Hackintosh. Then replace the one in the HDD’s EFI folder with that one you just copied
* **Question:** How to enable NVIDIA Graphics card?
	**Answer:** Now NVIDIA releases the new web drivers for Pascal Graphics card. To get NVIDIA card work you need to download NVIDIA FixUP or simply select the NVIDIA Web option from the New Multibeast.
* **Question:** Will this guide work with all the motherboards?
	**Answer: Yes, it will work but you have to select the suitable drivers from the post installation and make sure that the BIOS settings are matched with your motherboard.

### Updating to the latest Version

Apple releases the updates in every one or two months. After using this steps, you can easily update it through your Mac App Store. Sometimes some error could occur. That's why I raccomend you to keep a backup of your EFI folder and the most important file in another partition. Anyway if that happens let me know in the comment box.

Graphics issue. After the update, if you can’t boot into desktop then disable **Inject Intel** from the Clover **Boot/Options/Graphics Injector/Untick inject-intel**. After you reach in desktop, Install **Lilu.kext** and **IntelGraphicsFixup.kext** into **Library/Extension**. If this didn’t help then follow the Graphics section from this guide. If your kexts are already installed, then you will not have any issues with the upgrade.

Make sure that the Audio is working because these two is the main part will have an issue after updating. If you had any trouble with the audio, then follow the steps from this Guide.

![java-javascript](/img/in-post/post-js-version/HighSierra.png)

### Thanks to

* <a href="https://www.tonymacx86.com/members/jktaurus8.1548388/" target="_blank">jktaurus8</a> and his <a href="https://www.tonymacx86.com/threads/updated-for-multibeast-9-2-1-and-sierra-10-12-6-sierra-on-200-series-with-kabylake-processor.218494/" target="_blank">awesome guide</a>.
* <a href="https://www.tonymacx86.com/members/rehabman.429483/" target="_blank">RehabMan</a>
* <a href="https://www.tonymacx86.com/members/ghosthitwall.1415514/" target="_blank">GhostHitWall</a>
* <a href="https://www.tonymacx86.com/members/tonymacx86.3/" target="_blank">tonymacx86</a>
* <a href="https://www.tonymacx86.com/members/onmybikedrunk.1085297/" target="_blank">onmybikedrunk</a>
* <a href="https://www.tonymacx86.com/members/toleda.2393/" target="_blank">toleda</a>
* <a href="https://www.tonymacx86.com/members/p1lgrim.374452/" target="_blank">P1LGRIM</a>
