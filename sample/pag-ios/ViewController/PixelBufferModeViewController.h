//
//  PixelBufferModeViewController.h
//  pag-ios
//
//  Created by partyhuang(黄庆然) on 2019/10/31.
//  Copyright © 2019 kevingpqi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <libpag/PAGRenderer.h>

NS_ASSUME_NONNULL_BEGIN

@interface PixelBufferModeViewController : UIViewController

@property (strong, nonatomic) PAGSurface * surface;

@property (strong, nonatomic) PAGFile * pagFile;

@property (strong, nonatomic) PAGRenderer * render;

@end

NS_ASSUME_NONNULL_END
