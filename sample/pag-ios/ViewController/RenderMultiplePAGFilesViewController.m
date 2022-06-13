//
//  RenderMultiplePAGFilesViewController.m
//  pag-ios
//
//  Created by partyhuang(黄庆然) on 2019/12/30.
//  Copyright © 2019 kevingpqi. All rights reserved.
//

#import "RenderMultiplePAGFilesViewController.h"
#import <libpag/PAGPlayer.h>

@interface RenderMultiplePAGFilesViewController ()

@end

@implementation RenderMultiplePAGFilesViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    PAGComposition* composition = [self makeComposition];
    //3.0需要使用setComposition接口
    [self.pagView setComposition:composition];
}


- (NSString *)resourcePath {
    return nil;
}

- (PAGFile*)getPAGFile:(int)row clume:(int)colume name:(NSString*)name itemWidth:(float)itemWidth itemHeight:(float)itemHeight {
    PAGFile* pagFile = [PAGFile Load:[[NSBundle mainBundle] pathForResource:name ofType:@"pag"]];
    if (pagFile) {
        float scaleX = itemWidth * 1.0f / [pagFile width];
        CGAffineTransform transform = CGAffineTransformMakeScale(scaleX, scaleX);
        CGAffineTransform tranflate = CGAffineTransformMakeTranslation(itemWidth * colume, row * itemHeight + 150);
        transform = CGAffineTransformConcat(transform, tranflate);
        [pagFile setMatrix:transform];
        [pagFile setDuration:10000000];
    }
    return pagFile;
}

/// 3.0组装接口Demo，用于在一个surface中展示不同的file
- (PAGComposition *)makeComposition {
    PAGComposition* compostion = [PAGComposition Make:self.view.bounds.size];
    float itemWidth = self.view.bounds.size.width / 5;
    float itemHeight = 100;
    for (int i = 0; i < 20; i++) {
        PAGFile* pagFile = [self getPAGFile:i / 5 clume:i % 5 name:[NSString stringWithFormat:@"%d", i] itemWidth:itemWidth itemHeight:itemHeight];
        [compostion addLayer:pagFile];
    }
    return compostion;
}


//transform 计算工具函数
+ (CGAffineTransform) transformFromRect:(CGRect)sourceRect toRect:(CGRect)finalRect {
    CGAffineTransform transform = CGAffineTransformIdentity;
    transform = CGAffineTransformTranslate(transform, -(CGRectGetMinX(sourceRect)-CGRectGetMinX(finalRect)), -(CGRectGetMinY(sourceRect)-CGRectGetMinY(finalRect)));
    transform = CGAffineTransformScale(transform, finalRect.size.width/sourceRect.size.width, finalRect.size.height/sourceRect.size.height);
    return transform;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
