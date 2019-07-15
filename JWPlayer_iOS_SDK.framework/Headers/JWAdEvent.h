//
//  JWAdEvent.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 5/16/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWEvent.h"
#import "JWAdConfig.h"
#import "JWAdBreak.h"

NS_ASSUME_NONNULL_BEGIN
@interface JWAdEvent : NSObject

/*!
 The ad tag that for which the event was fired.
 */
@property (nonatomic, copy) NSString *tag;

@end

@protocol JWAdDetailEvent <NSObject>

/*!
 The type of ad that is being played.
 */
@property (nonatomic, copy) NSString *creativeType;

/*!
 The client that is currently being used, vast, googima or freewheel.
 */
@property (nonatomic) JWAdClient client;

@end


@protocol JWAdRequestEvent <JWAdDetailEvent>

/*!
 Whether an ad is in a pre, mid, or post position.
 */
@property (nonatomic, copy) NSString *adPosition;

/*!
 An ad's position. Will return a number (in seconds) of a midroll's position
 */
@property (nonatomic, copy) NSString *offset;

@end


@protocol JWAdCompanionsEvent <NSObject>

/*!
 An array with available companion information.
 */
@property (nonatomic) NSArray <JWAdCompanion *> *companions;

@end


@protocol JWAdScheduleEvent <NSObject>

/*!
 An array containing the adBreaks of the VMAP schedule.
 */
@property (nonatomic) NSArray <JWAdBreak *> *adBreaks;

/*!
 The client that is currently being used, vast, googima or freewheel.
 */
@property (nonatomic) JWAdClient client;

@end


@protocol JWAdImpressionEvent <JWAdDetailEvent>

/*!
 An ad's position (pre, mid, post).
 */
@property (nonatomic, copy) NSString *adPosition;

/*!
 AdSystem referenced inside of the VAST XML.
 */
@property (nonatomic, nullable, copy) NSString *adSystem;

/*!
 AdTitle referenced inside of the VAST XML.
 */
@property (nonatomic, nullable, copy) NSString *adTitle;

/*!
 VAST-only: An array of the AdSystems specified in any utilized ad wrappers; index denotes level of wrapper.
 */
@property (nonatomic, nullable) NSArray *wrapper;

/*!
 The URL which will be opened if the ad is clicked.
 */
@property (nonatomic, copy) NSString *clickThroughUrl;

/*!
 The currently playing media item.
 */
@property (nonatomic, copy) NSString *mediaFile;

/*!
 VAST-only: The version of VAST referenced in the VAST XML.
 */
@property (nonatomic) CGFloat vastVersion;

/*!
 Wether the ad is linear or nonlinear.
 */
@property (nonatomic) JWAdType linear;

/*!
 Details of the VMAP schedule's adBreak that is currently playing. Available only for VMAP schedules on Vast.
 */
@property (nonatomic, nullable) NSDictionary *vmapInfo;

@end


@protocol JWAdStateChangeEvent <JWAdDetailEvent, JWStateChangeEvent>

/*!
 The new state of the player.
 */
@property (nonatomic) JWPlayerState newState;

@end

@protocol JWAdTimeEvent <JWAdDetailEvent, JWTimeEvent>

/*!
 Returns the sequence number the ad is a part of.
 */
@property (nonatomic) NSUInteger sequence;

@end
NS_ASSUME_NONNULL_END
