//
//  PAGImageViewTableViewController.m
//  pag-ios
//
//  Created by Guopeng Qi on 2023/3/23.
//  Copyright © 2023 PAG. All rights reserved.

#import "PAGImageViewTableViewController.h"

#import <libpag/PAGImageView.h>

#define WIDTH  100

@interface PAGCell : UITableViewCell
@property (nonatomic,strong) PAGImageView* pagImageView;
@property (nonatomic,strong) NSString* filePath;
@end

@implementation PAGCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.pagImageView = [[PAGImageView alloc] initWithFrame:CGRectMake(20, 0, WIDTH, WIDTH)];
        [self.contentView addSubview:self.pagImageView];
    }
    return self;
}

- (void)setFilePath:(NSString *)filePath {
    if ([filePath length] > 0) {
        [self.pagImageView setPath:filePath];
        [self.pagImageView setCurrentFrame:0];
        [self.pagImageView setRepeatCount:-1];
        [self.pagImageView play];
    }
}

@end

@interface PAGImageViewTableViewController ()<UITableViewDelegate,UITableViewDataSource>
@property(nonatomic, strong) UITableView *tableView;
@end

@implementation PAGImageViewTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.tableView];
    self.tableView.frame = self.view.frame;
    [self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 20;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    PAGCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(PAGCell.class) forIndexPath:indexPath];
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
        [_tableView registerClass:PAGCell.class forCellReuseIdentifier:NSStringFromClass(PAGCell.class)];
    }
    return _tableView;
}
- (NSString*)resourcePathWithIndex:(NSInteger)index {
    return [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%ld", index] ofType:@"pag"];
}

@end
