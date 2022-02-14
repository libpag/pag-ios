Pod::Spec.new do |s|

  s.name     = 'libpag'
  s.version  = '0.2.7.45'
  s.ios.deployment_target   = '8.0'
  s.summary  = 'libpag SDK'
  s.homepage = 'https://github.com/libpag/libpag-ios'
  s.source   = {:git => 'https://github.com/libpag/libpag-ios.git', :tag => s.version.to_s }
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author = {'libpag' => 'libpag@tencent.com'}
  s.ios.frameworks = ['UIKit', 'VideoToolbox', 'CoreMedia']
  s.vendored_frameworks = 'framework/*.xcframework'
  s.pod_target_xcconfig = { 
   'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' 
  }
  s.user_target_xcconfig = { 
   'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  
end
