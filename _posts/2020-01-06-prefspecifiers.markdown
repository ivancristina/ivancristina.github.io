---
layout:     post
title:      "Preference Specifiers"
subtitle:   "List of preference specifiers for Root.plist"
date:       2020-01-06
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

# Specifiers

`Root.plist` is written in xml syntax, you'll see that this is nothing but a simple array of dictionaries representing various specifiers. A very good list of them is reported [on iPhoneDevWiki](https://iphonedevwiki.net/index.php/Preferences_specifier_plist), but let's see some of the most important ones.

This website **detects the darkmode**, and in particular this page allows you to see the various cells in light/dark mode just my switching your **system** dark mode (supported by iOS, macOS and Windows). Try it out!

<!-- Rounded switch -->
<center><sub><b><font size="4.5">Toggle the switch to watch the values as active:</font></b></sub>
<label class="switch">
  <input onclick="toggleImgClass()" type="checkbox" id="toggle">
  <span class="slider round"></span>
</label>

<div id="iphone" class="device device-iphone-8 device-spacegray">
  <div class="device-frame">
    <img id="screenshot" class="device-content ps_deselected nomargin">
  </div>
  <div class="device-stripe"></div>
  <div class="device-header"></div>
  <div class="device-sensors"></div>
  <div class="device-btns"></div>
  <div class="device-power"></div>
</div>
</center>

Down here I'm going to report them in order of appearence in the screenshot.

## RootListController

```xml
<plist version="1.0">
<dict>
  <key>items</key>
    <array>
      <dict>
        <key>cell</key>
        <string>CELL_TYPE</string>
        <key>PROPERTY</key>
        <string>VALUE</string>
      </dict>
    </array>
  <key>title</key>
  <string>Preference Specifiers</string>
</dict>
</plist>
```

#### PSGroupCell
Cells between `PSGroupCell`s will be grouped. You can add Headers and Footers.
<img class="ps_group" src="/img/Specifiers/Group.png">
```xml
<dict>
  <key>cell</key>
  <string>PSGroupCell</string>
  <key>label</key>
  <string>Header</string>
  <key>footerText</key>
  <string>Footer</string>
  <key>footerAlignment</key>
  <integer>1</integer>
</dict>
```

#### PSSwitchCell
<img id="switch" class="ps_switch" src="/img/Specifiers/Switch.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSSwitchCell</string>
  <key>label</key>
  <string>Switch</string>
</dict>
```

#### PSSpinnerCell
<img class="ps_spinner" src="/img/Specifiers/Spinner.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSSpinnerCell</string>
  <key>label</key>
  <string>Loading</string>
</dict>
```

#### PSSliderCell
<img id="slider" class="ps_slider" src="/img/Specifiers/Slider.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSSliderCell</string>
  <key>showValue</key>
  <true/>
</dict>
```

#### PSButtonCell
<img class="ps_button" src="/img/Specifiers/Button.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSButtonCell</string>
  <key>label</key>
  <string>Button</string>
</dict>
```

#### PSSegmentCell
<img id="segment" class="ps_segment" src="/img/Specifiers/Segment.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSSegmentCell</string>
  <key>label</key>
  <string>Button</string>
  <key>validTitles</key>
  <array>
    <string>One</string>
    <string>Two</string>
    <string>Three</string>
    <string>Four</string>
    <string>Five</string>
    <string>Six</string>
  </array>
  <key>validValues</key>
  <array>
    <string>1</string>
    <string>2</string>
    <string>3</string>
    <string>4</string>
    <string>5</string>
    <string>6</string>
  </array>
</dict>
```

#### PSLinkListCell
<img class="ps_list" src="/img/Specifiers/List.jpeg">
<center>It brings to an external view, showing the <code class="highlighter-rouge">validTitles</code>:</center>
<img class="ps_listview" src="/img/Specifiers/ListView.png">
```xml
<dict>
  <key>cell</key>
  <string>PSLinkListCell</string>
  <key>label</key>
  <string>List</string>
  <key>validTitles</key>
  <array>
    <string>One</string>
    <string>Two</string>
    <string>Three</string>
    <string>Four</string>
    <string>Five</string>
    <string>Six</string>
  </array>
  <key>validValues</key>
  <array>
    <string>1</string>
    <string>2</string>
    <string>3</string>
    <string>4</string>
    <string>5</string>
    <string>6</string>
  </array>
</dict>
```
#### PSGiantCell
It brings to an external controller, in this case `TPBRootListController`.
<img class="ps_giant" src="/img/Specifiers/Giant.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSGiantCell</string>
  <key>label</key>
  <string>Giant Cell (external view)</string>
  <key>detail</key>
  <string>TPBRootListController</string>
</dict>
```

#### PSLinkCell
It brings to an external controller, in this case `TPBRootListController`.
<img class="ps_link" src="/img/Specifiers/Link.jpeg">
```xml
<dict>
  <string>PSLinkCell</string>
  <key>label</key>
  <string>Link (external view)</string>
  <key>detail</key>
  <string>TPBRootListController</string>
</dict>
```

#### PSEditTextCell
<img id="text" class="ps_text" src="/img/Specifiers/Text.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSEditTextCell</string>
  <key>label</key>
  <string>TextEdit</string>
  <key>placeholder</key>
  <string>Default text</string>
</dict>
```

#### PSSecureEditTextCell
<img id="securetext" class="ps_securetext" src="/img/Specifiers/SecureText.jpeg">
```xml
<dict>
  <string>PSSecureEditTextCell</string>
  <key>label</key>
  <string>Password</string>
  <key>placeholder</key>
  <string>Dots will appear</string>
</dict>
```

#### PSStaticTextCell
<img class="ps_static" src="/img/Specifiers/Static.jpeg">
```xml
<dict>
  <key>cell</key>
  <string>PSStaticTextCell</string>
  <key>label</key>
  <string>Static text</string>
</dict>
```

// Devices.css by github.com/picturepan2
<link rel="stylesheet" href="/css/devices.css">
<script>
// Detects darkmode for iPhone
if (window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches) {
    document.getElementById("iphone").className = 'device device-iphone-8 device-spacegray';
}else{
    document.getElementById("iphone").className = 'device device-iphone-8 device-gold';
}
// Toggle javascript
function toggleImgClass(){
  if (toggle.checked){
    document.getElementById("screenshot").className = 'device-content ps_selected nomargin';
    document.getElementById("switch").className = 'ps_switch_active';
    document.getElementById("slider").className = 'ps_slider_active';
    document.getElementById("segment").className = 'ps_segment_active';
    document.getElementById("text").className = 'ps_text_active';
    document.getElementById("securetext").className = 'ps_securetext_active';
  }else{
    document.getElementById("screenshot").className = 'device-content ps_deselected nomargin';
    document.getElementById("switch").className = 'ps_switch';
    document.getElementById("slider").className = 'ps_slider';
    document.getElementById("segment").className = 'ps_segment';
    document.getElementById("text").className = 'ps_text';
    document.getElementById("securetext").className = 'ps_securetext';
  }
}
</script>
<style>
img{width:75%;}
.nomargin{margin: auto!important;}
.ps_selected{content:url("/img/Specifiers/Selected.png");}
.ps_deselected{content:url("/img/Specifiers/Deselected.png");}
.ps_switch{content:url("/img/Specifiers/Switch.jpeg");}
.ps_switch_active{content:url("/img/Specifiers/SwitchActive.jpeg");}
.ps_slider{content:url("/img/Specifiers/Slider.jpeg");}
.ps_slider_active{content:url("/img/Specifiers/SliderActive.jpeg");}
.ps_segment{content:url("/img/Specifiers/Segment.jpeg");}
.ps_segment_active{content:url("/img/Specifiers/SegmentActive.jpeg");}
.ps_text{content:url("/img/Specifiers/Text.jpeg");}
.ps_text_active{content:url("/img/Specifiers/TextActive.jpeg");}
.ps_securetext{content:url("/img/Specifiers/SecureText.jpeg");}
.ps_securetext_active{content:url("/img/Specifiers/SecureTextActive.jpeg");}
@media (prefers-color-scheme: dark) {
  .ps_selected{content:url("/img/Specifiers/Selected Dark.png");}
  .ps_deselected{content:url("/img/Specifiers/Deselected Dark.png");}
  .ps_group{content:url("/img/Specifiers/Group Dark.png");}
  .ps_switch{content:url("/img/Specifiers/Switch Dark.jpeg");}
  .ps_switch_active{content:url("/img/Specifiers/SwitchActive Dark.jpeg");}
  .ps_spinner{content:url("/img/Specifiers/Spinner Dark.jpeg");}
  .ps_slider{content:url("/img/Specifiers/Slider Dark.jpeg");}
  .ps_slider_active{content:url("/img/Specifiers/SliderActive Dark.jpeg");}
  .ps_button{content:url("/img/Specifiers/Button Dark.jpeg");}
  .ps_segment{content:url("/img/Specifiers/Segment Dark.jpeg");}
  .ps_segment_active{content:url("/img/Specifiers/SegmentActive Dark.jpeg");}
  .ps_list{content:url("/img/Specifiers/List Dark.jpeg");}
  .ps_listview{content:url("/img/Specifiers/ListView Dark.png");}
  .ps_giant{content:url("/img/Specifiers/Giant Dark.jpeg");}
  .ps_link{content:url("/img/Specifiers/Link Dark.jpeg");}
  .ps_text{content:url("/img/Specifiers/Text Dark.jpeg");}
  .ps_text_active{content:url("/img/Specifiers/TextActive Dark.jpeg");}
  .ps_securetext{content:url("/img/Specifiers/SecureText Dark.jpeg");}
  .ps_securetext_active{content:url("/img/Specifiers/SecureTextActive Dark.jpeg");}
  .ps_static{content:url("/img/Specifiers/Static Dark.jpeg");}
}
@media (min-width:320px)  {
  img{width:100%;}
  .device{
    zoom: 0.70;
    margin:auto;
    -moz-transform: scale(0.75);
}
}
</style>
