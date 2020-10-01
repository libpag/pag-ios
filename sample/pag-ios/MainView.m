//
//  MainView.m
//  PAGTestPod
//
//  Created by kevingpqi on 2019/1/15.
//  Copyright © 2019年 kevingpqi. All rights reserved.
//

#import "MainView.h"
#import <libpag/PAGView.h>

@implementation MainView {
    PAGView* pagView;
    NSString* pagPath;
}

- (void)loadPAGAndPlay {
    if (pagView != nil) {
        [pagView stop];
        [pagView removeFromSuperview];
        pagView = nil;
    }
    
    pagPath = [[NSBundle mainBundle] pathForResource:@"replacement" ofType:@"pag"];
    pagView = [[PAGView alloc] init];
    pagView.frame = self.frame;
    [self addSubview:pagView];
    PAGFile* pagFile = [PAGFile Load:pagPath];
    if ([pagFile numTexts] > 0) {
        PAGText* textData = [pagFile getTextData:0];
        textData.text = @"hah哈哈哈哈哈👌";
        [pagView setTextData:0 data:textData];
    }
    
    if([pagFile numImages] > 0){
        NSString* filePath = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"png"];
        PAGImage* pagImage = [PAGImage FromPath:filePath];
        if(pagImage){
            [pagView replaceImage:0 data:pagImage];
        }
    }
    
    [pagView setFile:pagFile];
    [pagView setRepeatCount:-1];
    [pagView play];
}


- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([pagView isPlaying]) {
        [pagView stop];
    } else {
        [pagView play];
    }
    
}


@end
