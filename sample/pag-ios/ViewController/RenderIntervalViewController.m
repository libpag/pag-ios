//
//  RenderIntervalViewController.m
//  pag-ios
//
//  Created by Guopeng Qi on 2022/6/11.
//  Copyright © 2022 PAG. All rights reserved.
//

#import "RenderIntervalViewController.h"
#import <libpag/PAGComposition.h>

@interface RenderIntervalViewController ()

@end

@implementation RenderIntervalViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSString* path = [[NSBundle mainBundle] pathForResource:@"test2" ofType:@"pag"];
    PAGFile* pagFile = [PAGFile Load:path];
    if (pagFile == nil) {
        return;
    }
    PAGComposition* pagComposition = [PAGComposition Make:CGSizeMake([pagFile width], [pagFile height])];
    // 播放1~3s
    [pagFile setStartTime:-1000000];
    [pagFile setDuration:3000000];
    [pagComposition addLayer:pagFile];
    [self.pagView setComposition:pagFile];
    
}

@end
