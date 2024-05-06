Pod::Spec.new do |s|

  s.name     = 'libpag'
  s.version  = '4.3.54'
  s.ios.deployment_target   = '9.0'
  s.summary  = 'libpag SDK'
  s.homepage = 'https://github.com/libpag/libpag-ios'
  s.source   = {:git => 'https://github.com/libpag/libpag-ios.git', :tag => s.version.to_s }
  s.license          = { :type => 'Apache License Version 2.0', :file => 'LICENSE' }
  s.author = {'libpag' => 'libpag@tencent.com'}
  s.ios.frameworks = ['UIKit', 'VideoToolbox', 'CoreMedia']
  s.vendored_frameworks = 'framework/libpag.xcframework'
  s.pod_target_xcconfig = { 
   'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' 
  }
  s.user_target_xcconfig = { 
   'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.xcconfig = {
    'VALID_ARCHS' =>  'arm64 armv7 x86_64',
  }
end
