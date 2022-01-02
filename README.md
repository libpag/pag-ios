# libpag-ios

<div align="left">
<img src=https://pag.io/img/new_official_website/logo_l.png width=20% />
</div>

<style> a{ TEXT-DECORATION:none }</style>

![license](https://img.shields.io/badge/license-Apache2.0-brightgreen.svg)

[<font color=blue>官方主页</font>](https://pag.io/)

## 项目介绍

PAG(Portable Animated Graphics)是一套完整的动画工作流。提供从
AE（Adobe After Effects）导出插件，到桌面预览工具，再到各端
的跨平台渲染 SDK。

PAG 的目标是降低或消除动画研发成本，打通设计师创作到素材交
付上线的流程，不断输出运行时可编辑的高质量动画内容。

## iOS端接入

### 基本要求<br/>

- **支持iOS8及以上**
- **需要使用Xcode8.0及以上版本进行编译**

### Framework接入<br>
1. 将libpag的framework文件放置在iOS工程项目目录下
2. 在项目工程中，配置所使用Target的General->Embedded Binaries，添加libpag.framework
3. 由于libpag暂时不支持Bitcode，需要配置Build Settings->Build Options->Enable Bitcode 为No

### cocoapods接入<br>
修改App目录下的Podfile文件，添加相应的libpag的引用.

```
	pod 'libpag' 
```
版本更新记录查看：[<font color=blue>SDK下载页面</font>](https://github.com/libpag/libpag/releases)<br/>

