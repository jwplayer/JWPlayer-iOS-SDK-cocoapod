Pod::Spec.new do |s|

  s.name         = "JWPlayer-SDK"
  s.version      = "3.0.1"
  s.summary      = "JW Player SDK for iOS. SDKs page: https://www.jwplayer.com/video-solutions/mobile-sdk/"

  s.homepage     = "https://developer.jwplayer.com/ios-sdk/"
  
  s.license      = { :type => "Commercial", :file => "LICENSE.md" }

  s.authors      = { "JW Player" => "support@jwplayer.com" }

  s.platform     = :ios, "8.0"
  s.documentation_url = "https://developer.jwplayer.com/sdk/ios/reference/"
  
  s.source       = { :git => "https://github.com/jwplayer/JWPlayer-iOS-SDK-cocoapod.git", :tag => s.version.to_s }

  s.ios.vendored_frameworks = "JWPlayer_iOS_SDK.framework"

    # Module Umbrella header goes here - related to [IOS-1437](https://jwplayer.atlassian.net/browse/IOS-1437)
  spec.module_name = 'JWPlayer_iOS_SDK'

  spec.social_media_url = 'https://www.facebook.com/jwplayer/'
  spec.social_media_url = 'https://twitter.com/jwplayer'
  spec.social_media_url = 'https://twitter.com/jwpsupport'

  # From https://www.jwplayer.com/video-solutions/mobile-sdk/
  spec.description = <<-DESC
    The SDK includes native software classes and methods that enable developers
    to build HLS video playback, VAST advertising, player UI customization and
    other features directly into any mobile application to expand your reach to
    the billions of mobile app users worldwide.
  DESC

end


