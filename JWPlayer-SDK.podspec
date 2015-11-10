Pod::Spec.new do |s|

  s.name         = "JWPlayer-SDK"
  s.version      = "2.0.31"
  s.summary      = "JW Player SDK for iOS."

  s.homepage     = "http://www.jwplayer.com/products/mobile-sdk/"
  s.license      = { :type => "Commercial", :file => "ToS.md" }

  s.authors      = { "JW Player" => "support@jwplayer.com" }
  
  s.platform     = :ios, "7.0"
  s.documentation_url = "http://developer.jwplayer.com/sdk/ios/docs/developer-guide/"
  s.source       = { :git => "https://github.com/jwplayer/JWPlayer-iOS-SDK-cocoapod.git", :tag => s.version.to_s }

  s.source_files = "Headers/*.h"
  s.public_header_files = "Headers/*.h"
  s.ios.vendored_library = "libJWPlayer-iOS-SDK.a"
  
  s.requires_arc = true

end
