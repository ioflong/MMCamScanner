//
//  MMCropView.h
//  MMCamScanner
//
//  Created by mukesh mandora on 09/06/15.
//  Copyright (c) 2015 madapps. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MTGeometry.h"

@class MMCropView;

@protocol MMCropViewDelegate <NSObject>

@optional
- (void)cropView:(MMCropView *)cropView frameEdited:(BOOL)frameEdited;

@end

@interface MMCropView : UIView
{
    CGPoint touchOffset;
    CGPoint a;
    CGPoint b;
    CGPoint c;
    CGPoint d;
    
   
    BOOL frameMoved;
    int currentIndex,previousIndex;
    int k;
    
}

@property (nonatomic, weak) id<MMCropViewDelegate> delegate;

@property (nonatomic, strong) UIView *activePoint;

@property (strong, nonatomic) UIView *pointD;
@property (strong, nonatomic) UIView *pointC;
@property (strong, nonatomic) UIView *pointB;
@property (strong, nonatomic) UIView *pointA;
//middle points
@property (nonatomic, strong) NSMutableArray *points;

@property (strong, nonatomic) UIView *redDot;
@property (assign, nonatomic) BOOL alreadyShowRedDot;

- (void)resortPoints;
- (BOOL)shouldResetFrame:(BOOL)resotPoints;
- (BOOL)frameEdited;
- (void)resetFrame;
- (CGPoint)coordinatesForPoint: (int)point withScaleFactor: (CGFloat)scaleFactor;

- (void)bottomLeftCornerToCGPoint: (CGPoint)point;
- (void)bottomRightCornerToCGPoint: (CGPoint)point;
- (void)topRightCornerToCGPoint: (CGPoint)point;
- (void)topLeftCornerToCGPoint: (CGPoint)point;


-(void)checkangle:(int)index;
-(void)findPointAtLocation:(CGPoint)location;
- (void)moveActivePointToLocation:(CGPoint)locationPoint;

@end
