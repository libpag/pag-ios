Pod::Spec.new do |s|

  s.name     = 'libpag'
  s.version  = '1.0.0'
  s.ios.deployment_target   = '8.0'
  s.summary  = 'libpag SDK'
  s.homepage = 'https://github.com/libpag/libpag-ios'
  s.source   = {:git => 'https://github.com/libpag/libpag-ios.git', :tag => s.version.to_s }
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author = {'libpag' => 'libpag@tencent.com'}
  s.ios.frameworks = ['UIKit', 'VideoToolbox', 'CoreMedia']
  s.vendored_frameworks = 'framework/*.framework'
  
end
