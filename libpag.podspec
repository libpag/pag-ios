Pod::Spec.new do |s|

  s.name     = 'libpag'
  s.version  = '4.4.41'
  s.ios.deployment_target   = '9.0'
  s.summary  = 'libpag SDK'
  s.homepage = 'https://github.com/libpag/libpag-ios'
  s.source   = {
 "http": "https://github.com/libpag/pag-ios/releases/download/4.4.41/libpag_4.4.41_ios_arm64_x86_64.zip"
  }
  s.license          = { :type => 'Apache License Version 2.0', :file => 'LICENSE' }
  s.author = {'libpag' => 'libpag@tencent.com'}
  s.ios.frameworks = ['UIKit', 'VideoToolbox', 'CoreMedia']
  s.vendored_frameworks = 'libpag.xcframework'
end
