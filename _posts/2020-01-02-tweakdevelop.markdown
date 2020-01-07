---
layout:     post
title:      "Creating tweaks"
subtitle:   "How to begin with Theos Tweak Development"
date:       2020-01-02
author:     "Ivan"
header-img: "img/post-bg-tweak.png"
header-mask:  0.3
catalog:      true
tags:
    - iOS
    - Jailbreak
    - tweaks
    - development
---

# What are tweaks

> Some people may want to [skip this paragraph](#requirements)

It's been over a decade since Jay Freeman introduced Cydia and probably indirectly led the Jailbreak scene to be what it is today. **A mess**, but even a very nice place sometimes.

Saurik, by the way, did not do all the job alone. The reason why the Jailbreak scene is alive - and despite what many people say - it probably is [more than ever](/2019/09/29/checkm8/), is thanks to those heroes who do not wear caps (but do wear socks under sandals, in some cases 😣) are tweak developers. Essentially, a tweak is a customization not present natively in iOS software, but that can be installed via 3rd party stores. Tweaks can be as powerful as simple, and many times those tweaks features were so loved by users that Apple itself natively introduced them in its own software. In a word, tweaks are usually visionary.

Tweaks are mainly written in Objective-C (Apple's own language prior to Swift) and uses some Logos syntax. The environment that allows user to create tweaks is called Theos. It is cross-platform and open-source. Theos did change a lot over the years, and for sure still will, so this post could be obsolete even tomorrow. Theos uses Logos as compiler and creates .deb packages as result of compilation. Those packages can later be installed with those previously mentioned 3rd party stores (like Cydia, Zebra, Sileo and Installer), which in turn rely on APT, a Debian package manager.

#### Requirements

Even though this post could be followed with some variations on Windows and Mac (or even on your iDevice itself), many tweak developers use/require:
- a Mac or an [Hackintosh](/2017/10/01/Hackintosh/);
- a [jailbroken iDevice](/2019/03/03/Jailbreak/) for testing (could use even [Simulator](https://github.com/angelXwind/simject), but not reported here);
- Internet connection;
- Patience. A lot.

### 1. Theos

Follow Theos installing procedures for [macOS](https://github.com/theos/theos/wiki/Installation-macOS), [Linux](https://github.com/theos/theos/wiki/Installation-Linux), [iOS](https://github.com/theos/theos/wiki/Installation-iOS) or [Windows](https://github.com/theos/theos/wiki/Installation-Cygwin).

<sup>[Cygwin](https://cygwin.com/install.html) is required for Windows</sup>

Once Theos is installed and configured, you can update it in a future via the command
```
$THEOS/bin/update-theos
```
At this point you should download the [SDKs](https://github.com/theos/sdks) and put them in you Theos `sdks` folder.
Last step is configuring your Theos configurations for connect to your device. With a text editor you should open your `bash_profile`, or alternatively just run
```
nano ~/.bash_profile
```
And paste the following code (changing the IP and SSH port (by default 22) with your device's ones):
```
export THEOS_DEVICE_IP=192.168.1.3
export THEOS_DEVICE_PORT=22
```
At this point, if you did everything correctly, you should be good to go!

### 2. Create a Tweak

In order to create a tweak, you can use **NIC** (*New Instance Creator*), a templating system used by Theos for building quick templates and not forcing the user to create all the files manually. You can use the command
```
$THEOS/bin/nic.pl
```
This will prompt you several options. The order may vary between Theos versions. What you have to choose is anyway the option for `iphone/tweak`. You will be able to quickly put your tweak informations like the *Project Name*, the *Package Name* (aka its **Bundle ID**), the *Author* (you) and repo *Maintainer*, and then the Bundle filter. Here you should put the Bundle ID of the app you want your tweak to work with only. For example, if you want to tweak just the iOS *Calendar*, you can filter `com.apple.mobilecal` and your tweak will work just with that. If you want to apply some system-wide customizations, you could leave **Springboard** as your default choice.
Right after that Theos will ask if by any chance you want to terminate some app once your tweak gets installed. By leaving Springboard you will let the installer will prompt a **respring** by default, if you put `-`, no apps will be closed.

Theos will at this point generate the required files with your submitted values. The project structure would look like this:
```
{Project Name}
│   {Project Name}.plist
│   control
│   Makefile
│   Tweak.x  
│   ..
```
`{Project Name}.plist` is the file filtering the Bundle ID to terminate.<br/>
`control` contains most of the informations previously submitted to NIC, as well as the version, description and section of the tweak.<br/>
`Makefile` contains the information required by our package builder, GNU Make, such as the external frameworks etc.<br/>
`Tweak.x` is the actual code of the tweak itself. By default Theos will create a quite nice comment with some basic features and syntax examples.

### 3. Writing the Tweak

To understand how to write a tweak, we must talk about iOS Runtime Headers before. Headers, in general, are usually files that developers can import in their code in order to use interfaces, functions, properties or variables inside it, and they usually have the `.h` extension and you usually `#import Header.h` in the first lines of your code.

Some of those headers, anyway, are not meant to be used by developers and kept "private" or you just cannot execute them in normal scenarios. Tweak development is a perfect example of the use of Apple private APIs. As with C++, Objective-C relies on Runtime Headers, basically all those classes, superclasses and ivars loaded in order to allow your code to actually work, even if not strictly used. Thanks to runtime introspection and class-dump, it's possible to "export" those headers in order to use them as reference. Several developers generated iOS Runtime Headers from the various iOS versions, but probably Elias Limneos' [Headers Library](http://developer.limneos.net/) is the website where most of the Tweak developers spent most time at.

In tweak development you do not run code in a completely ordinary way. Instead of creating classes executing code, a basic tweak usually injects into iOS methods, and maybe change some values or add some code to it.

As said before, you will mainly code in Objective-C but there are some Logos function to watch out for. They are:<br/>
`%hook` allows to inject code inside class' methods.<br/>
`%group` allows to create `%hook`s groups. They cannot be nidificated<br/>
`%new` manually creates a new method inside a `%hook`<br/>
`%end` must be used to close each independent block of code listed before<br/>
`%orig` returns the original method with default values. You can even `%orig(arg1)` to send `arg1` to the original method<br/>
`%init` allows to execute a `%hook` or a `%group`

Taking as example my tweak [Accent](https://github.com/ivancristina/accent), we can see some practical examples of the aforementioned syntax. The purpose of accent is changing the tint color system-wide. In order to do it, we first have to understand how Apple's code works, before writing ours. Specifically, iOS mainly relies on default colors, "calling" their values each time in order to render them inside the apps using them. That said, if I change the default colors at the root, I could be able to theme iOS in a quite "solid" way - even though, with some occasional side effects.

Apple stores those default colors in a header called `UIColors.h`, on its own under a framework called **UIKitCore**. Taking a look at the [iOS 13.1.3 version](http://developer.limneos.net/?ios=13.1.3&framework=UIKitCore.framework&header=UIColor.h), you can see that after some properties, you can find several `±(void)`s and `±(id)`s. Those are called **methods**. The method sending the default blue color in iOS is `+(id)systemBlueColor;`. In order to change its value, I have to create a new variable where to store my new value and then return it to the method. I also want to create a switch in my code which allows me to run or not my code injection.

```objectivec
BOOL enabled = YES;       // let's set enabled as default
UIColor* newColor = [UIColor colorWithRed:1.00 green:0.47 blue:0.60 alpha:1.0];   // create our new color

%hook UIColor   // hook into the UIColor
+(id)systemBlueColor {    // inject in the method
    if (enabled) {        // if enabled
        return newColor;  // set our color as systemBlueColor
    } else {              // otherwise
        return %orig;     // run original code
    }
}
%end      // closes the hook
```
Now that we created our tweak code, let's make basic PreferenceBundle in order to actually toggle our ON/OFF switch.

### 4. PreferenceBundle

A Preference Bundle is indeed a panel appearing in your settings app, letting the user change settings for your tweak or even for the dev to show useful/donation links if he feels so. In order to create one, `cd` into your `{Project Name}` and then reopen NIC with `$THEOS/bin/nic.pl`. Choose `iphone/preference_bundle_modern`. At this point insert your PreferenceBundle Name (usually, I add *Preferences* to my Tweak name: for Accent my PB is AccentPreferences), another BundleID (even here, I add *preferences*) and a three character identifier for your PB (for **A**ccent's **P**reference**B**undle I used **APB**). Now your tweak Makefile will include your PB in your build and your project structure should look like this:
```
{Project Name}
│   {Project Name}.plist
│   control
│   Makefile
│   Tweak.x  
│
└───{PreferenceBundle Name}
    │   XXXRootListController.h
    │   XXXRootListController.m
    │   entry.plist
    │   Makefile
    |
    └───Resources
        |   Info.plist
        |   Root.plist
        |   ..
```
`RootListController` will contain the ObjC code for your PreferenceBundle.<br/>
`entry.plist` contains the name of your PB, as well as the name for it's icon (to include later).<br/>
`Makefile` works in a similar way to the main one [here](#2-create-a-tweak).<br/>
`Info.plist` includes the bundleID of your PB.<br/>
`Root.plist` instead, handles the appearance and structure of your PB.

Let's then create a new button. First of all, we have to visually create our switch. Opening `Root.plist`, you will see that Theos generate some template code. If you're familiar with xml, you'll see that this is nothing but a simple array of dictionaries representing various specifiers. A very good list of them is reported [on iPhoneDevWiki](https://iphonedevwiki.net/index.php/Preferences_specifier_plist), but I even made a graphical view of the most important ones [here](/2020/01/06/prefspecifiers/). Let's see an example.

```xml
<plist version="1.0">
<dict>
	<key>items</key>
	<array>
		<dict>
			<key>cell</key>
			<!-- Type of cell -->
			<string>PSGroupCell</string>
			<key>label</key>
			<!-- And its label, you can put whatever you want here -->
			<string>testpreferences First Page</string>
		</dict>
		<dict>
			<key>cell</key>
			<string>PSSwitchCell</string>
			<key>default</key>
			<!-- Tells that by default it will be on (BOOL true) -->
			<true/>
			<key>defaults</key>
			<!-- You PB BundleID -->
			<string>com.ivanc.testpreferences</string>
			<key>key</key>
			<!-- Identifier of the switch -->
			<string>AwesomeSwitch1</string>
			<key>label</key>
			<!-- And again, its label -->
			<string>Awesome Switch 1</string>
		</dict>
	</array>
	<key>title</key>
	<!-- The name that will appear for your PB -->
	<string>testpreferences</string>
</dict>
</plist>
```
Now, in order to connect our switch to our boolean value, we must let our Tweak.x know which switch it should check for. The identifier of our switch is in the `key` key (no, it's not a typo 😅) - in this case it's `AwesomeSwitch1` - so let's change it to `isEnabled`. The value of our switch will be stored in NSUserDefaults, a class which caches the preference values.
We should also add a `PostNotificaton`, a broadcast system through which a class alerts another one that something happened (in this case, when the switch goes ON/OFF). We have to give an address similar to our bundleid, like `com.YOURNAME.preferenceschanged`.
After cleaning up and removing all the unnecessary code, our final code would be:

**Root.plist**
```xml
<plist version="1.0">
<dict>
	<key>items</key>
	<array>
		<dict>
			<key>cell</key>
			<string>PSSwitchCell</string>
			<!-- We will use NSUserDefaults -->
			<key>default</key>
			<true/>
			<key>defaults</key>
			<string>com.ivanc.testpreferences</string>
			<key>key</key>
			<!-- We changed the identifier -->
			<string>isEnabled</string>
			<key>label</key>
			<!-- We changed the label -->
			<string>Enabled</string>
			<key>PostNotification</key>
			<!-- Our PostNotificaton address -->
			<string>com.ivanc.preferenceschanged</string>
		</dict>
	</array>
	<key>title</key>
	<string>testpreferences</string>
</dict>
</plist>
```

**Tweak.x**
```objectivec
BOOL enabled;             // not dummy anymore
UIColor* newColor = [UIColor colorWithRed:1.00 green:0.47 blue:0.60 alpha:1.0];

void setColor(){          // our void where to put our code
  // our preference file is the NSUserDefaults of our PreferenceBundle
  preferences = [[NSUserDefaults standardUserDefaults] persistentDomainForName:@"com.ivanc.testpreferences"];
  enabled = [[preferences valueForKey:@"isEnabled"] boolValue];   // enabled value now comes from isEnabled
}

// What to do when our class receives the PostNotificaton
static void PreferencesChangedCallback(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo) {
    setColor();           // Just need this one in our case. Could add more voids later
}

%hook UIColor
+(id)systemBlueColor {
    if (enabled) {
        return newColor;
    } else {
        return %orig;
    }
}
%end

%ctor {                   // Our constructor
    // Our observer for the PostNotificaton
    CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, (CFNotificationCallback) PreferencesChangedCallback, CFSTR("com.ivanc.preferenceschanged"), NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
    setColor();           // We will run our main void anyway
    %init;                // And we initialize the tweak
}
```

### 5. Customization

You may want at this point customize a bit your tweak. An example is adding icons. You can easily create your logo with Sketch (and even use [my template](https://github.com/ivancristina/accent/tree/master/sketch) for icon and banner), then export it with normal, @2x and @3x [scale factors](https://developer.apple.com/design/human-interface-guidelines/ios/icons-and-images/image-size-and-resolution/). Call them `icon.png`, `icon@2x.png` and `icon@3x.png`, then place them in `Resources` inside the PreferenceBundle folder.
Also, you may want to customize your PreferenceBundle adding buttons and assigning them specific voids. A practical example would be adding a link, for example to your GitHub page or something else. In order to do that, you may first have to create your button in the `Root.plist` like this:
```xml
<plist version="1.0">
<dict>
	<key>items</key>
	<array>
		<dict>
			[...]
		</dict>
		<dict>
			<key>cell</key>
			<string>PSButtonCell</string>
			<key>action</key>
			<!-- We link to the void we're going to create -->
			<string>openGithub</string>
			<key>label</key>
			<string>Github repo</string>
		</dict>
	</array>
	<key>title</key>
	<string>testpreferences</string>
</dict>
</plist>
```
and we write the actual code to execute in `XXXRootListController.m`, between specifiers NSArray and the `@end`
```objectivec
- (NSArray *)specifiers {
	[...]
}

-(void)openGithub {
  [[UIApplication sharedApplication] openURL:[NSURL URLWithString: @"https://github.com"] options:@{} completionHandler:nil];
}
@end
```

### 6. Compile

This could give you some headaches sometimes.

In order to compile an installable `.deb` you first have to `cd` to your Project folder through terminal and then
```
make package
```
To this, you can add more arguments. For example you can `make package install` if you want to directly install to the phone (if you correctly configured the IP address in [Step 1](#1-theos)). By default, your tweak will be compiled in debug mode and Theos will not apply its assets optimizations, so in order to build a "cleaner" package you will have to `make package install FINALPACKAGE=1`. In each case, the result package will be in `packages` folder.

As with any piece of code, Logos could fail to build. At this point you gotta fix your s**t man. Errors are USUALLY descriptive enough to tell you what the error is, and the line and raw of where it encountered the problem. This will probably take the most time, and where you'll learn the most. In case you really don't know how to fix it, do what all the developers since the beginning of time did: ask on [r/jailbreakdevelopers](https://www.reddit.com/r/jailbreakdevelopers/) or the good old [StackOverflow](https://stackoverflow.com/).

Happy bug hunting!
