//
//  LowCPUModeViewController.m
//  pag-ios
//
//  Created by Guopeng Qi on 2023/3/24.
//  Copyright © 2023 PAG. All rights reserved.
//

#import "LowCPUModeViewController.h"
#import <libpag/PAGDecoder.h>
#import <libpag/PAGFile.h>


#define WIDTH  100

@interface PAGTableViewCell : UITableViewCell
@property (nonatomic,strong) UIImageView* uiImageVIew;
@property (nonatomic,strong) NSString* filePath;
@end

@implementation PAGTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.uiImageVIew = [[UIImageView alloc] initWithFrame:CGRectMake(20, 0, WIDTH, WIDTH)];
        [self.contentView addSubview:self.uiImageVIew];
    }
    return self;
}

- (void)setFilePath:(NSString *)filePath {
    if ([filePath length] > 0) {
        PAGFile* pagFile = [PAGFile Load:filePath];
        if (pagFile == nil) {
            return;
        }
        float scaleFactor = fmax(self.frame.size.width * [UIScreen mainScreen].scale / [pagFile width], self.frame.size.height * [UIScreen mainScreen].scale / [pagFile height]);
        PAGDecoder* pagDecoder = [PAGDecoder Make:pagFile maxFrameRate:30.0f scale:scaleFactor];
        if (pagDecoder == nil) {
            return;
        }
        NSInteger numFrame = [pagDecoder numFrames];
        NSMutableArray<UIImage*>* imagesArray = [NSMutableArray new];
        for (int i = 0; i < numFrame; i++) {
            UIImage* image = [pagDecoder frameAtIndex:i];
            if (image) {
                [imagesArray addObject:image];
            }
        }
        pagDecoder = nil;
        [self.uiImageVIew setAnimationImages:imagesArray];
        [self.uiImageVIew setAnimationDuration:[pagFile duration] * 1.0/ 1000000];
        pagFile = nil;
        [self.uiImageVIew startAnimating];
    }
}

@end

@interface LowCPUModeViewController ()<UITableViewDelegate,UITableViewDataSource>
@property(nonatomic, strong) UITableView *tableView;
@end

@implementation LowCPUModeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.tableView];
    self.tableView.frame = self.view.frame;
    [self.tableView reloadData];
    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 6;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    PAGTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(PAGTableViewCell.class) forIndexPath:indexPath];
    cell.filePath = [self resourcePathWithIndex:[indexPath row]];
    cell.backgroundColor = [UIColor whiteColor];
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return WIDTH;
}

- (UITableView *)tableView{
    if (!_tableView) {
        _tableView = [[UITableView alloc]initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerClass:PAGTableViewCell.class forCellReuseIdentifier:NSStringFromClass(PAGTableViewCell.class)];
    }
    return _tableView;
}
- (NSString*)resourcePathWithIndex:(NSInteger)index {
    return [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%ld", index] ofType:@"pag"];
}

@end
