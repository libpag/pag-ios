//
//  PixelBufferModeViewController.m
//  pag-ios
//
//  Created by partyhuang(黄庆然) on 2019/10/31.
//  Copyright © 2019 kevingpqi. All rights reserved.
//

#import "PixelBufferModeViewController.h"

@interface PixelBufferModeViewController ()
@property (nonatomic) CGFloat progress;
@property (nonatomic) CGFloat progressPreFrame;
@property (strong, nonatomic) CADisplayLink * displayLink;
@end


@implementation PixelBufferModeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initPAG];
    [self initParams];
}


- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    if (self.displayLink) {
        [self.displayLink invalidate];
    }
}

/**
 初始化PAG相关组件
 */
- (void)initPAG {
    //读取PAG素材文件
    NSString* resourcePath = [self resourcePath];
    self.pagFile = [PAGFile Load:resourcePath];
    
    //创建render用于渲染控制
    //tips:替换图片和文字的方法在render中
    self.render = [[PAGRenderer alloc] init];
    
    //创建渲染目标surface，surface可以被多个render共享
    self.surface = [PAGSurface MakeFromGPU:CGSizeMake(self.pagFile.width, self.pagFile.height)];

    //组装file与surface
    [self.render setFile:self.pagFile];
    [self.render setSurface:self.surface];
    
    //进度控制
    [self.render setProgress:0];
    
    //渲染
    [self.render flush];
    
    //获取渲染结果，注使用[PAGSurface FromLayer:<#(CAEAGLLayer *)#>]接口创建的pagSurface是无法通过getCVPixelBuffer接口获取pixelBuffer的
//    CVPixelBufferRef pixelBuffer = [self.surface getCVPixelBuffer];
//    NSLog(@"pixelBuffer %@", pixelBuffer);
    
    
}

- (void)initParams {
    self.progressPreFrame = 1.0 / [self timeToFrame:self.pagFile.duration frameRate:self.pagFile.frameRate];
    self.progress = self.progressPreFrame * 0.1;
}

- (int64_t)timeToFrame:(int64_t)time frameRate:(CGFloat)frameRate {
    return floor(time * frameRate / 1000000ll);
}

- (void)drawNextFrame {
    self.progress += self.progressPreFrame;
    if (self.progress > 1) {
        self.progress -= 1;
    }
    [self.render setProgress:self.progress];
    [self.render flush];
    //获取渲染结果，注使用[PAGSurface FromLayer:<#(CAEAGLLayer *)#>]接口创建的pagSurface是无法通过getCVPixelBuffer接口获取pixelBuffer的
//    CVPixelBufferRef pixelBuffer = [self.surface getCVPixelBuffer];
//    NSLog(@"pixelBuffer %@", pixelBuffer);
}

- (NSString*)resourcePath {
    return [[NSBundle mainBundle] pathForResource:@"replacement" ofType:@"pag"];
}

- (IBAction)start:(id)sender {
    if (self.displayLink == nil) {
        CADisplayLink * displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawNextFrame)];
        self.displayLink = displayLink;
    }
    [self.displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
}

- (IBAction)stop:(id)sender {
    [self.displayLink invalidate];
    self.displayLink = nil;
}

@end
