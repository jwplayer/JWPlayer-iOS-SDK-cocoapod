//
//  JWAdConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 10/3/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWAdRules.h"

/**
    Type of ad provider to be used.
 */
typedef NS_ENUM(NSInteger, JWAdClient) {
    /// VAST ad provider
    JWAdClientVast = 0,
    /// Google IMA provider
    JWAdClientGoogima,
    /// Google IMA DAI provider
    JWAdClientGoogimaDAI,
    /// Freewheel ad provider
    JWAdClientFreewheel
};

NS_ASSUME_NONNULL_BEGIN
@class JWAdBreak, IMASettings, JWGoogimaDaiConfig, JWFreewheelConfig;

/**
 An object providing information about the way ads are handled by the player. Describes adMessage, skipMessage, skipText and skipOffset.
 @note In the current implementation, an adConfig object can be added to config and propagates to all adBreaks.
 */
@interface JWAdConfig : NSObject

/* ========================================*/
/** @name Accessing Ad Config Attributes
 */

/**
The URL of the VAST tag to display, or the custom string of the Freewheel tag to display.
 @note can also specify Vast vmap file to use for ad breaks.
 @note ignore if schedule is set.
*/
@property (nonatomic, nullable, retain) NSString *tag;

/**
 A message to be shown to the user in place of a seekbar while the ad is playing.
 @note 'xx' in the message is replaced with countdown timer until the end of the ad.
 */
@property (nonatomic, nullable, retain) NSString *adMessage;

/**
 A message to be shown on the skip button during countdown to skip availablilty.
 @note 'xx' in the message is replaced with countdown timer until the moment skip becomes available.
 @see skipText
 */
@property (nonatomic, nullable, retain) NSString *skipMessage;

/**
 A message to be shown on the skip button when the skip option becomes available.
 */
@property (nonatomic, nullable, retain) NSString *skipText;

/**
 An integer representing the number of seconds before the ad can be skipped.
 */
@property (nonatomic) NSUInteger skipOffset;

/**
 An array of JWAdBreak objects that proivides info about ad breaks.
 @note tag property is ignored if this property is not nil.
 @see JWAdBreak
 */
@property (nonatomic, nullable, retain) NSArray <JWAdBreak *> *schedule;

/**
 Vast vmap file to use for ad breaks.
 @note schedule is ignored if this property is not nil.
 */
@property (nonatomic, nullable, retain) NSString *adVmap;

/**
 Set to JWAdClientGoogima if you wish to use google IMA; set to JWAdClientVast if not. Setting to nil defaults to vast.
 @note Due to the fact that Google IMA's iOS SDK is still in Beta mode, we suggest using the vast plugin.
 */
@property (nonatomic) JWAdClient client;

/**
 The IMASettings class stores the Google IMA SDK settings.
 @note When setting a custom imaSetting, the default value of enableBackgroundPlayback is NO.
 */
@property (nonatomic, nullable) IMASettings *googimaSettings;

/**
 The JWGoogimaDaiConfig class stores the Google IMA DAI settings.
 */

@property (nonatomic, nullable) JWGoogimaDaiConfig *googimaDaiSettings;

/**
 The JWFreewheelConfig class stores the Freewheel SDK settings.
 @note When setting Freewheel settings, the value of adClient should be set to JWAdClientFreewheel.
 */
@property (nonatomic, nullable) JWFreewheelConfig *freewheel;

/**
 For forcing controls to show for VPAID ads. Default is false.
 @note If the VPAID creative has built-in controls, showing the controls may be redundant.
 */
@property (nonatomic) BOOL vpaidControls;

/**
 Use to control the frequency of ad playback.
 @note Available only for the VAST adClient.
 */
@property (nonatomic, nullable, retain) JWAdRules *rules;

@end
NS_ASSUME_NONNULL_END
