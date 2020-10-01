//
//  PixelBufferDemoViewController.m
//  pag-ios
//
//  Created by partyhuang(黄庆然) on 2020/1/8.
//  Copyright © 2020 kevingpqi. All rights reserved.
//

#import <objc/runtime.h>

#import <libpag/PAGPlayer.h>
#import <libpag/PAGRenderer.h>
#import <libpag/PAGSurface.h>
#import <libpag/PAGFile.h>
#import <libpag/PAGTextLayer.h>
#import "PixelBufferDemoViewController.h"


@interface PixelBufferDemoViewController ()

@property (nonatomic, strong) PAGFile* file;

@property (nonatomic, strong) PAGSurface* surface;

@property (nonatomic, strong) PAGPlayer* player;

@end


//工具方法，非libpag使用必须函数
@interface PixelBufferDemoViewController (Tool)
+ (UIImage*)imageFromCVPixelBufferRef:(CVPixelBufferRef)pixelBuffer;
@end

@implementation PixelBufferDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //初始化PAG组件
    [self initPAG];
    //替换数据demo方法
    [self replaceImageAndText];
    //进度控制和渲染，result为渲染结果
    CVPixelBufferRef result = [self presentOnce];
    UIImage* image = [self.class imageFromCVPixelBufferRef:result];
    UIImageView* imageView = [[UIImageView alloc] initWithImage:image];
    [self.view addSubview:imageView];
}

- (void)initPAG {
    //文件加载
    NSString* path = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"pag"];
    self.file = [PAGFile Load:path];
    //player是libpag3.0中的控制器，用于播放进度控制，与surface为一一对应的关系。
    //render之中的功能转移到了PAGPlayer和PAGFile中。如果需要绘制多个File的内容，可以使用PAGComposition组装PAGFile。具体请看{@link CombinePAGViewController}
    self.player = [[PAGPlayer alloc] init];
    //surface是libpag中的工作台，用于提供渲染环境
    self.surface = [PAGSurface MakeFromGPU:self.view.bounds.size];
    //绑定数据
    [self.player setSurface:self.surface];
    [self.player setComposition:self.file];
}

- (CVPixelBufferRef)presentOnce {
    [self.player setProgress:0.5];
    [self.player flush];
    return [self.surface getCVPixelBuffer];
}


- (void)replaceImageAndText {
    ///两种方式替换数据
    ///1.使用file通过editableIndex进行替换，如果editableIndex是同一个，那么对应的editableIndex的Layer的显示内容都会改变
    NSString* imagePath = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"png"];
    PAGImage* image = [PAGImage FromPath:imagePath];
    [self.file replaceImage:0 data:image];
    
    PAGText* text = [self.file getTextData:0];
    text.text = @"测试数据";
    [self.file replaceText:0 data:text];
    
    ///2.使用Layer上的接口直接进行替换，只会修改对应Layer的数据，不会影响同一个editableIndex的其他Layer
    PAGImageLayer* imageLayer = (PAGImageLayer*)[self.file getLayersByEditableIndex:1 layerType:PAGLayerTypeImage].firstObject;
    [imageLayer replaceImage:image];
    
    PAGTextLayer* textLayer = (PAGTextLayer*)[self.file getLayersByEditableIndex:1 layerType:PAGLayerTypeText].firstObject;
    [textLayer setText:@"test"];
}


@end



/// Deprecated是libpag2.0之中提供的接口，在3.0中render已经过时。3.0中，替换数据不再存在于render中，而是下发到每个Layer之中。
/// 3.0替换数据可以更简单，直接通过Layer进行替换。如果希望仍然使用原先的替换方式，可以在PAGFile中调用与2.0PAGRender一致的接口进行处理。
/// 3.0的设计理念是先组装PAGComposition，再渲染。渲染过程中，如果希望修改，则对每个Layer具体调整。
/// render中进度控制，播放控制的代码被归在PAGPlayer中；
/// 图片替换、文本替换的代码被归在PAGLayer以及PAGFile中。
@interface PixelBufferDemoViewController (Deprecated)

@property (nonatomic, strong) PAGRenderer* render;

- (void)initPAGDeprecated __attribute__((deprecated));

- (CVPixelBufferRef)presentOnceDeprecated __attribute__((deprecated));

- (void)replaceImageAndTextDeprecated __attribute__((deprecated));

@end


@implementation PixelBufferDemoViewController (Deprecated)

- (void)setRender:(PAGRenderer *)render {
    objc_setAssociatedObject(self, @"render", render, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (PAGRenderer *)render {
    return objc_getAssociatedObject(self, @"render");
}

- (void)initPAGDeprecated {
    PAGRenderer* render = [[PAGRenderer alloc] init];
    [render setSurface:self.surface];
    [render setFile:self.file];
}

- (CVPixelBufferRef)presentOnceDeprecated {
    //
    [self.render setProgress:0];
    [self.render flush];
    return [self.surface getCVPixelBuffer];
}

- (void)replaceImageAndTextDeprecated {
    NSString* imagePath = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"png"];
    PAGImage* image = [PAGImage FromPath:imagePath];
    [self.render replaceImage:0 data:image];
    
    PAGText* text = [self.file getTextData:0];
    text.text = @"测试数据";
    [self.render setTextData:0 data:text];
}

@end



@implementation PixelBufferDemoViewController (Tool)

+ (UIImage *)imageFromCVPixelBufferRef:(CVPixelBufferRef)pixelBuffer {
    CVPixelBufferLockBaseAddress(pixelBuffer, 0);
    CIImage *ciImage = [CIImage imageWithCVPixelBuffer:pixelBuffer];
    CVPixelBufferUnlockBaseAddress(pixelBuffer, 0);
    CIContext *temporaryContext = [CIContext contextWithOptions:nil];
    CGImageRef videoImage = [temporaryContext
                             createCGImage:ciImage
                             fromRect:CGRectMake(0, 0,
                                                 CVPixelBufferGetWidth(pixelBuffer),
                                                 CVPixelBufferGetHeight(pixelBuffer))];
    
    UIImage *uiImage = [UIImage imageWithCGImage:videoImage];
    CGImageRelease(videoImage);
    return uiImage;
}

@end
