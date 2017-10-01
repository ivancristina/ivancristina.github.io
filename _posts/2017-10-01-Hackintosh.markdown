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


![java-javascript](/img/in-post/post-js-version/Hackintosh.png)

It wasn't very easy to accomplish, but dang! An Hackintosh (almost) completely working!

The process is not reccomended for noobs (although I am one myself), unless you really want to spend a lot of time to even try to make it boot, but I ensure you that the overall result will be worth the hours of headache you'll get later!

## My build

So let's start with my build. I assembled it something like 7 months ago, and it costed me around €500. Now it could cost like 100 uro less, but I'm pretty happy for the result I got with those money anyway.

My entire setup has been built by:

- an <a href="http://amzn.eu/h3i8nZy" target="_blank">MSI H270 Gaming M3</a>, a 200 serie mobo, with a bunch of RGB LEDs and an overall fancy aestetich. Worth the €126 I spent, now at €116*.
- an <a href="http://amzn.eu/5WilklT" target="_blank">Intel Core i5-7500</a>, a 3.4Ghz with 6Mb of cache Kaby Lake. Bought at €211, now at €184*
- a <a href="http://amzn.eu/1DicCyw" target="_blank">Western Digital Blue</a> 1 Tb @ 7200RPM HDD. Really solid. Very nice product for the 51 euro I spent for it* (price it has kept).
- a single slot of <a href="http://amzn.eu/j4PcU9x" target="_blank">Ballistix Sport LT</a> RAM. 8 Gb DDR4 at 2400Mhz clock. A nice deal for €54, considering now it costs more than €10 more.
- a <a href="http://amzn.eu/7L74v01" target="_blank">Corsair VS450</a> PSU, 80+ certification and huge quality that you can afford at €41* (as I did, for instance). Bought because didn't plan about a GPU, now regretting a bit if I have to tell you.
- and at the end, the <a href="http://amzn.eu/6XEPdiw" target="_blank">Carbide Spec-03</a>. Fancy ATX case, with a nice glass (plastic, in reality) panel, with 2 quiet Corsair fans inside (one LED and one not). Kept its price of €65.

So you could ask... why not a more powerful PSU? Why not an external GPU instead of that sh**ty HD 630? And moreover, why not a damn SSD?
Well. I was a stupid. A very poor stupid. Dind't think and didn't have money. Moreover expecially in these months, along with the price of high end GPUs for bitcoin mining (thanks dears, hope you to loose all the bitcoin you mined), both italian physical and virtual shops (like Amazon) well thought to increase prices. For everything! Even CPUs, low end GPUs and SSD. Those in particular actually costs almost the double of the "real" price.

About the Motherboard, totally worth it. H serie because I didn't need the Z feautures, and also because as a (poor) student, I don't have enough money to afford a Z Mobo and a K CPU. Anyway nice to see, very well built and managed by MSI softwares in Windows. With Hackintosh... you know, newer not always means better, expecially if you basically adapting a closed source OS with non proprietary hardware. But some patches, and I was good to go.
The CPU... DAMN, if I hated it! I mean, it's actually powerful an power-friendly, but the price was actually a bit high IMHO. And as I told before... It was a mess let it work in Sierra, until finally the 2017 Mac serie came out, along with their new Kaby Lake models. That made everything ALOT EASIER. In fact, before the 10.12.6 update (with the new Kaby Lake kernel support), in order to let Kaby Lake run you had to <a href="https://www.tonymacx86.com/threads/new-testing-intel-7th-generation-kaby-lake-cpus-200-series-motherboards-in-macos.219877/" target="_blank">spoof your CPU and GPU ID</a>, and some of the times it wouldn't even boot after that (like in my case .-.). Make the GPU work with full acceleration was a mess, but at the end instead of the fu**ing 7mb of virtualized nvram, I managed to get the GPU working along all its 1536 MB of memory. And then, thanks to the 10.12.6 update, I finally also managed to power the CPU at its full power.

![java-javascript](/img/in-post/post-js-version/Info.png)

The following patches (needed in 10.12.5 or before in order to let the CPU and Integrated Graphics work) are indeed no more needed on Sierra 10.12.6 or in any version of the new Apple macOS version, <a href="https://www.tonymacx86.com/threads/macos-high-sierra-is-now-available-on-the-mac-app-store.231773/" target="_blank">High Sierra!</a> (what a huge fantasy, though...)

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

You could find my complete config.plist here.
