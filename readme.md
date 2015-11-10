~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
JW Player SDK for iOS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Document version: 11/16/2015
SDK version: 2.0.31

Getting support and submitting feedback
=======================================

To send us your feedback or bug reports, send email to support@jwplayer.com.

Before contacting us, please read our FAQ: http://support.jwplayer.com/customer/portal/articles/2022900-ios-sdk-faq

Using the SDK library
=====================

For integration instructions and API reference, see the: 
http://developer.jwplayer.com/sdk/ios/docs/developer-guide/intro/getting-started/

Using the demo app
==================

The source code of a sample application (JWPlayer_Developer_Demo) demonstrates a very basic set-up and use of the JWPlayer iOS SDK. To use this app, link the SDK Framework (JWPlayer-iOS-SDK.framework) to the sample application’s project and enter your JWPlayer Beta License key in the info.plist under JWPlayerKey.

https://github.com/jwplayer/jwplayer-sdk-ios-demo

What’s new in this release
==========================

- Added support for Google Interactive Media Ads (IMA)

Fixes in this release
=====================

- Fixed an issue where the AdClient default was missing. New default is VAST.
- Fixed an issue where IMA ads were failing in iOS7 if offset was provided in seconds.

Unsupported features
====================

- Casting to Chromecast
- RTMP streaming
- Playback of FLV, Vorbis or WebM formats
- Google Analytics
- Adobe SiteCatalyst
- YouTube integration
- VPAID ads

License notices
===============
Documentation is generated using appledoc (https://github.com/tomaz/appledoc).
