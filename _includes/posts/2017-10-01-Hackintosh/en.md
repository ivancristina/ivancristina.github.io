It wasn't very easy to accomplish, but dang! An Hackintosh (almost) completely working!

The process is not reccomended for noobs (although I am one myself), unless you really want to spend a lot of time to even try to make it boot, but I ensure you that the overall result will be worth the hours of headache you'll get later!

# 1. My build

So let's start with my build. I assembled it something like 7 months ago, and it costed me around €500. Now it could cost like 100 euro less, but I'm pretty happy for the result I got with those money anyway.

My entire setup has been built with:

-   an **[MSI H270 Gaming M3](http://amzn.eu/h3i8nZy)**, a 200 serie mobo, with a bunch of red LEDs and an overall fancy aestetich. Worth the €126 I spent, now at €116\*.
-   an **[Intel Core i5-7500](http://amzn.eu/5WilklT)**, a 3.4Ghz with 6Mb of cache Kaby Lake. Bought at €211, now at €184\*
-   a **[Western Digital Blue](http://amzn.eu/1DicCyw)** 1 Tb @ 7200RPM HDD. Really solid. Very nice product for the 51 euro I spent for it\* (price it has kept).
-   a single slot of **[Ballistix Sport LT](http://amzn.eu/j4PcU9x)** RAM. 8 Gb DDR4 at 2400Mhz clock. A nice deal for €54, considering now it costs more than €10 more.
-   a **[Corsair VS450](http://amzn.eu/7L74v01)** PSU, 80+ certification and huge quality that you can afford at €41\* (as I did, for instance). Bought because didn't plan about a GPU, **now regretting** a bit if I have to tell you.
-   and at the end, the **[Carbide Spec-03](http://amzn.eu/6XEPdiw)**. Fancy ATX case, with a nice glass (plastic, in reality) panel, with 2 quiet Corsair fans inside (one LED and one not). Kept its price of €65.

> _Prices are referred to those on Amazon.it in March 2017_

So you could ask... why not a more powerful PSU? Why not a dedicated GPU instead of that sh$!ty HD 630? And moreover, why not a damn SSD?
Well. I was a stupid. A **very poor stupid**. Dind't think and didn't have money. Moreover expecially in these months, along with the price of high end GPUs for bitcoin mining _(thanks dears, hope you to loose all the bitcoin you mined)_, both italian physical and virtual shops (like Amazon) well thought to increase prices. For everything! Even CPUs, low end GPUs and SSD. Those in particular actually costs **almost the double** of the "real" price.

About the Motherboard, **totally worth it**. H serie because I didn't need the Z feautures, and also because as a (poor) student, I don't have enough money to afford a Z Mobo and a K CPU. Anyway nice to see, very well built and managed by MSI softwares in Windows. With Hackintosh... you know, newer not always means better, expecially if you basically adapting a closed source OS with non proprietary hardware. But some patches, and I was good to go.

The CPU... DAMN, if **I hated it!** I mean, it's actually powerful an power-friendly, but the price was actually a bit high _IMHO_. And as I told before... It was a mess let it work in Sierra, until finally the 2017 Mac serie came out, along with their new Kaby Lake models. That made everything **ALOT EASIER**. In fact, before the 10.12.6 update (with the new Kaby Lake kernel support), in order to let Kaby Lake run you had to [spoof your CPU and GPU ID](https://www.tonymacx86.com/threads/new-testing-intel-7th-generation-kaby-lake-cpus-200-series-motherboards-in-macos.219877/), and some of the times it wouldn't even boot after that (like in my case .-.). Make the GPU work with full acceleration was a mess, but at the end instead of the fu$!ing 7mb of virtualized nvram, I managed to get the GPU working along all its 1536 MB of memory. And then, thanks to the 10.12.6 update, I finally also managed to power the CPU at its full power.

![java-javascript](/img/Hackintosh/Info.png)

The following patches (needed in 10.12.5 or before in order to let the CPU and Integrated Graphics work) are indeed no more needed on Sierra 10.12.6 or in any version of the new Apple macOS version, [High Sierra!](https://www.tonymacx86.com/threads/macos-high-sierra-is-now-available-on-the-mac-app-store.231773/) _(what a huge fantasy, though...)_

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

You could find my [complete config.plist here](https://github.com/ivancristina/ivancristina.github.io/raw/master/resources/config.plist).

## 2. BIOS Configuration

It may vary by your motherboard.

-   **Step 1:** Load Optimised Default
-   **Step 2:** In BIOS Tab
    		Windows 8/10 Features = Other OS
    		Storage Boot Option Control = UEFI
-   **Step 3:** Peripherals Tab
    		Initial Display Output = IGFX
    		XHCI Handoff = Enabled (In USB Configuration)
-   **Step 4:** Chipset Tab
    		VT-D = Disabled
    		Internal Graphics = Enabled
    		DVMT Pre-Allocated = 64M
-   **Step 5:** Save and Exit

### 3. What To Download

You need to download some files to get things work. These files are necessary for the entire session of the Mac OS installation.

##### 3.1. Bootloader

Latest version of [Clover Bootloader](https://sourceforge.net/projects/cloverefiboot/). This Bootloader let you boot both MacOS, Windows and Linux distros, all in one and with a customizable interface.

##### 3.2. Utilities

They're apps or scripts that will help you with the initialization, installation and configuration of Hackintosh. Download the latest version according to your macOS version

-   [Clover Configurator](http://mackie100projects.altervista.org/download-clover-configurator/). If you encounter the **7mb bug** use the Classic version instead of the Vibrant. This apps let you configure your bootloader settings with a fancy UI, instead than in command line (available also)
-   [UniBeast, MultiBeast and KextBeast](https://www.tonymacx86.com/resources/categories/tonymacx86-downloads.3).
    Those apps respectively let you create a bootable USB, configure your Hackintosh machine and install some primary drivers in **post-installation**
-   [Toleda](https://github.com/toleda/)'s [audio_cloverHDMI-130.command](https://github.com/toleda/audio_CloverHDMI/blob/master/audio_cloverHDMI-130.command.zip?raw=true). This script basically allows you to enable in a few clicks the **HD630 onboard audio**.

##### 3.3. Kexts

Kexts are basically drivers, which let you use your devices in a _plug&play-like_ way.

-   [AppleALC.kext](https://github.com/vit9696/AppleALC/releases) by [vit9696](https://github.com/vit9696) - Github repo [here](https://github.com/vit9696/AppleALC)
-   [Lilu.kext](https://github.com/vit9696/Lilu/releases) by [vit9696](https://github.com/vit9696) - Github repo [here](https://github.com/vit9696/Lilu)
-   [Shiki.kext](https://github.com/vit9696/Shiki/releases) by [vit9696](https://github.com/vit9696) - Github repo [here](https://github.com/vit9696/Shiki)
-   [XHCI-200-series-injector.kext](https://github.com/RehabMan/OS-X-USB-Inject-All/tree/master/XHCI-200-series-injector.kext) by [RehabMan](https://github.com/RehabMan) - Github repo [here](https://github.com/RehabMan/OS-X-USB-Inject-All)
-   [USBInjectAll.kext](https://bitbucket.org/RehabMan/os-x-usb-inject-all/downloads/) by [RehabMan](https://github.com/RehabMan) - Bitbucket repo [here](https://bitbucket.org/RehabMan/os-x-usb-inject-all/src)

Other kexts you'll need later: _(in post installation, with MultiBeast)_

-   AtherosE2200Ethernet.kext
-   FakeSMC.kext
-   IntelMausiEthernet.kext
-   RealtekRTL8111.kext

## 4. Installation

##### 4.1. Prerequisites

-   A **200 Series Motherboard** with Intel 7th Gen _(KabyLake)_ Processor
-   A **_working_** Mac, Hackintosh or Virtual Machine (VM is not reccomended though) - without one of those you can’t move forward.
-   USB stick, **16GB** or larger (some reported they got it working even with an 8GB stick, not my case though)

##### 4.2. Get macOS

1.  Go to your Mac, Hackintosh or VM and open the Mac App Store
2.  Log in with your Apple ID
3.  Download macOS Sierra (10.12.6) or High Sierra _- this guide is based on 10.12.6, but is appliable even to High Sierra with some modifications_
4.  After the download finishes the setup screen will appear you should **Quit** the app from the Dock. You can see the application in **/Applications/Install MacOS Sierra.app**

##### 4.3. Preparing USB

**_If the below guide didn't work for you then try [this one instead](https://www.tonymacx86.com/threads/updated-for-multibeast-9-2-1-and-sierra-10-12-6-sierra-on-200-series-with-kabylake-processor.218494/page-12#post-1586314)_**

1.  Open Disk Utilities –> Select USB and Erase using **Mac OS extended (journaled)** –> **GUID Partition Map** –> **Erase**
2.  Then open Unibeast –> Choose USB –> Then Select **UEFI** –> After that select Sierra
3.  Open USB’s EFI partition –> EFI/Clover –> Open config.plist Using Clover Configurator
4.  Make the necessaries edits (not needed in our case)

In case you have a build equal or very similar to mine, rename the existing **conf.plist** as **orig-config.plist** and paste mine there.

**_Move ALL the downloaded Files into USB, create a folder and paste it there._**

##### 4.4. USB ports tweaking

> _Not needed with my config.plist_

_After Creating Bootable USB, you should do some tweaks on the USB if your motherboard has USB 3.0+ Port. If you have just USB 2.0, then the below steps is not needed, although I reccomend you to follow these steps anyway_

Add these configurations in config.plist using Clover Configurator. **_(Patches already applied in my config.plist)_**

**Increase port limit**

Kernel and Kext Patches –> KextToPatch –> +

```html
Name: AppleUSBXHCIPCI
Find: 83bd74ff ffff10
Replace: 83bd74ff ffff1b
Comment: Increase port limit
```

![java-javascript](/img/Hackintosh/PortLimit.png)

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

![java-javascript](/img/Hackintosh/EHx1.png)
![java-javascript](/img/Hackintosh/EHx2.png)

Move **USBInjectAll.kext** & **XHCI-200-series-injector.kext** to USB’s EFI partition **/EFI/Clover/kexts/Other**.

##### 4.5. Install MacOS Sierra

1.  Turn on the computer
2.  Press the hotkey **Canc** to choose boot device _(it may differ on your motherboard)_
3.  Select USB
4.  At Clover boot screen, select **Boot MacOS from USB**
5.  When you arrive at the Installer, choose a language.
6.  In the top menu bar select Utilities and open **Disk Utility**
7.  Highlight your target drive for the Sierra installation in the left column.
8.  Click _Erase_ button
9.  **Name:** type _Sierra_ (You can rename it later)
10. **Format:** choose _Mac OS extended (journaled)_
11. **For Scheme:** Choose _GUID Partition Map_
12. Click **Erase**
13. Close _Disk Utility_
14. Highlight your target drive for the Sierra installation then click _Continue_.
15. After the first restart press the hotkey _Canc_ to choose boot device
16. Select USB
17. At Clover boot screen, scegli **Boot MacOS from the HDD** you installed.

**_If you don’t know how to install MacOS then follow the steps in the [Installation Guide](https://www.tonymacx86.com/threads/unibeast-install-macos-sierra-on-any-supported-intel-based-pc.200564/)_**

## 5. Post-Installation

After the successful installation, you must install necessary kext and patches to get things work. These are the same thing that we were doing after the installation of Windows OS. In Windows, drivers are in a package and it automatically installed within few clicks, while with macOS we should **manually** do these steps. As I said before, after the release of macOS 10.12.6 everything became easier because 10.12.6 brings the native support for Kabylake Processors. Also, tonymacx86 released a new version of the MultiBeast, which supports 200 Series Motherboard with 7th generation Kabylake processor. _Imagine how many steps you had to do before..._

#### 5.1. Post Installation Using MultiBeast

-   **1st Step** = Copy all the downloaded files to the desktop.
-   **2nd Step** = Open Multibeast –> Quick Start –> **UEFI Boot Mode**
    ![java-javascript](/img/Hackintosh/UEFI.png)

-   **3rd Step** = Drivers –> Audio –> Check both **ALC1220** and **100/200 Series Audio**. _(I also select the 5.1 Output as I have it built onboard)_
    ![java-javascript](/img/Hackintosh/Audio.png)

_If you have different codec then select the codec that you want. Codec version can be found on the specification of your Motherboard_

_There are two methods to get Audio Work. This is the First Method. If it doesn't work for you then try the method Two in “Post Installation Using Clover Configurator/Audio” Section._

-   **4th Step** = Drivers –> Network –> Check **IntelMausiEthernet v2.3** _(I also install RealtekRTL8111 v2.2.1)_
    ![java-javascript](/img/Hackintosh/Network.png)

-   **5th Step** = Drivers –> USB –> Check **Increase Max Port Limit 200 Series**
    ![java-javascript](/img/Hackintosh/PortLimit.png)

-   **6th Step** = Bootloader –> Check **Clover + Emulated NVRAM**
    ![java-javascript](/img/Hackintosh/CloverBootloader.png)

**_Note: After installing Multibeast don’t forget update clover to the latest version. You can do it via the Clover Configurator app or via the link above._**

-   **7th Step** = Customize –> Graphics Configuration –> Select on **Intel HD 6xx**
    ![java-javascript](/img/Hackintosh/Graphics.png)

-   **8th Step** = Final Build Configuration Build –> **_Install_**
    ![java-javascript](/img/Hackintosh/MultiBeast.png)

#### 5.2. Post Installation Using Clover Configurator

> _Not needed with my config.plist_

##### 5.2.1. Basic Configuration

-   Open Clover Configurator, then mount EFI Partition if not mounted (Multibeast will automatically mount the EFI partition)
-   Fix Random Restart problem when system shutdown by Selecting **FixShutdown_0004** under ACPI –> Fixes
    ![java-javascript](/img/Hackintosh/Shutdown.png)

-   **XMPDetection=Yes** (If your RAM clock speed is higher than 2133MHz, like in my case)
    ![java-javascript](/img/Hackintosh/XMP.png)

**_Don’t Close Clover Configurator. Add all entries from the below steps or else you should open the Clover Configurator for every step._**

#### 5.2.2. HD Graphics 630 w/ QuickSync & iTunes DRM Contents

Open Clover Configurator if not open.

**Add patches in DSDT**

ACPI –> DSDT –> Patches –> +

```html
Comment: change GFX0 to IGPU
Find: 47465830
Replace: 49475055
```

![java-javascript](/img/Hackintosh/IGPU.png)

-   Add the bootflag **shikigva=1** in Boot –> Custom Flags
    ![java-javascript](/img/Hackintosh/shikigva.png)

-   Copy **Shiki.kext** and **AppleALC.kext** and paste them in to **EFI drive/EFI/Clover/kexts/Other**.
    ![java-javascript](/img/Hackintosh/kextsOther.png)

##### 5.2.3. Second Audio Method

Open Clover Configurator if not open.

-   Make sure that **Lilu.kext** and **AppleALC.kext** (if you use the above step then AppleALC will already be in the **kexts/Other** folder) are installed. If not install them.
-   Add patches in Clover Configurator

**Add patches in DSDT if not present.**

ACPI –> DSDT –> Patches –> +

```html
Comment: change HDAS to HDEF
Find: 48444153
Replace: 48444546
```

![java-javascript](/img/Hackintosh/HDxx.png)

**Change Audio ID to 1 or 2 if not.**

In the latest version of **AppleALC.kext**, audio ID 1 or 2 or 11 is fully supported for ALC1220 and ALC1220A codecs.

Devices –> Audio –> Change it to **1** or **2** or **11**
![java-javascript](/img/Hackintosh/AudioInjection.png)

Run **audio_cloverHDMI-130.command** to get HDMI Audio working if you want. If this method of HDMI Audio didn’t work for you then follow the [toleda guide on how to enable HDMI Audio](https://www.tonymacx86.com/threads/quick-fix-200-series-kaby-lake-audio-onboard-and-or-hd-6x0-hdmi.221618/).
![java-javascript](/img/Hackintosh/toledaHDMI.png)

#### 5.3. SMBIOS

We need to change the SMBIOS to iMac 18.1 or 18.2 or 18.3 because these are the SMBIOS for the Kabylake processors. This is necessary because without SMBIOS the system will not boot and other features like power management, iMessage, Graphics acceleration won’t work.

For the perfect configuration of SMBIOS head over to [this link](http://www.everymac.com/systems/by_year/macs-released-in-2017.html) and choose SMBIOS that matches your processor.

In my case, I changed the SMBIOS to 18.2 (cause it's the SMBIOS of the i5-7500 powered iMac).
![java-javascript](/img/Hackintosh/SMBIOS.png)

##### 5.4. USB Power Management

Those who looking for the proper USB Power management go to the [USB power property injection for Sierra (and later) Guide](https://www.tonymacx86.com/threads/guide-usb-power-property-injection-for-sierra-and-later.222266/) by RehabMan.

Also, don’t forget to add patches in Kernel and Kext Patches –> Kext To Patch

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

![java-javascript](/img/Hackintosh/AppleUSBXHCIPCI.png)

As you may have seen I didn't apply the first patch, because I didn't need it.

#### 5.5. iMessage

[An iDiot's Guide To iMessage](https://www.tonymacx86.com/threads/an-idiots-guide-to-imessage.196827/) is the best iMessage Guide we can found on the internet, just follow this guide straightforward.

## 6. Geekbench Scores

The results are very nice, considering we're talking about an OS running on non-natively supported hardware.
![java-javascript](/img/Hackintosh/Device.png)
![java-javascript](/img/Hackintosh/Score.png)
![java-javascript](/img/Hackintosh/SCComparison.png)
![java-javascript](/img/Hackintosh/MCComparison.png)
![java-javascript](/img/Hackintosh/OpenCL.png)
![java-javascript](/img/Hackintosh/OpenCLComparison.png)

### 7. Frequently Asked Questions

-   **Question:** After the installation macOS won’t boot from the HDD drive. It only boots from the USB!
    		**Answer:** In this case first of all you need to boot using USB. After you reached the desktop copy the entire EFI folder from USB to your Hackintosh. Then replace the one in the HDD’s EFI folder with that one you just copied.
-   **Question:** How to enable NVIDIA Graphics card?
    		**Answer:** Now NVIDIA releases the new web drivers for Pascal Graphics card. To get NVIDIA card work you need to download NVIDIA FixUP or simply select the NVIDIA Web option from the New Multibeast.
-   **Question:** Will this guide work with all the motherboards?
    		**Answer**: Yes, it will work but you have to select the suitable drivers from the post installation and make sure that the BIOS settings are matched with your motherboard.

### 8. Updating to the latest Version

Apple releases the updates in every one or two months. After using this steps, you can easily update it through your Mac App Store. Sometimes some error could occur. That's why I raccomend you to keep a backup of your EFI folder and the most important file in another partition. Anyway if that happens let me know in the comment box or contact me to my mail, which you can find in the About page.

Graphics issue. After the update, if you can’t boot into desktop then disable **Inject Intel** from the Clover **Boot/Options/Graphics Injector/Untick inject-intel**. After you reach in desktop, Install **Lilu.kext** and **IntelGraphicsFixup.kext** into **Library/Extension**. If this didn’t help then follow the Graphics section from this guide. If your kexts are already installed, then you will not have any issues with the upgrade.

Make sure that the Audio is working because these two is the main part will have an issue after updating. If you had any trouble with the audio, then follow the steps from this Guide.

![java-javascript](/img/Hackintosh/HighSierra.png)

### 9. Thanks to

-   [jktaurus8](https://www.tonymacx86.com/members/jktaurus8.1548388/) for his [awesome guide](https://www.tonymacx86.com/threads/updated-for-multibeast-9-2-1-and-sierra-10-12-6-sierra-on-200-series-with-kabylake-processor.218494/).
-   [RehabMan](https://www.tonymacx86.com/members/rehabman.429483/)
-   [GhostHitWall](https://www.tonymacx86.com/members/ghosthitwall.1415514/)
-   [tonymacx86](https://www.tonymacx86.com/members/tonymacx86.3/)
-   [onmybikedrunk](https://www.tonymacx86.com/members/onmybikedrunk.1085297/)
-   [toleda](https://www.tonymacx86.com/members/toleda.2393/)
-   [P1LGRIM](https://www.tonymacx86.com/members/p1lgrim.374452/)
-   You, if you readed the entired guide. But if you did not... well... fy.
