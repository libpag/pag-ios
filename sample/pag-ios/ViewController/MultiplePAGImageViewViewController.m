//
//  MultiplePAGImageViewViewController.m
//  pag-ios
//
//  Created by Guopeng Qi on 2023/3/24.
//  Copyright © 2023 PAG. All rights reserved.
//

#import "MultiplePAGImageViewViewController.h"
#import <libpag/PAGImageView.h>

@interface MultiplePAGImageViewViewController ()

@end

@implementation MultiplePAGImageViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self renderMutiplePAGImageView];
    
    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)renderMutiplePAGImageView {
    float height = 100;
    float itemWidth = self.view.bounds.size.width / 4;
    float itemHeight = itemWidth;
    for (int i = 0; i < 20; i++) {
        PAGImageView* pagImageView = [[PAGImageView alloc] initWithFrame:CGRectMake(itemWidth * (i % 4), (i / 4) * itemHeight + height, itemWidth, itemHeight)];
        [pagImageView setPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%d", i] ofType:@"pag"]];
        [pagImageView setCacheAllFramesInMemory:NO];
        [self.view addSubview:pagImageView];
        [pagImageView setRepeatCount:-1];
        [pagImageView play];
    }
}

@end
