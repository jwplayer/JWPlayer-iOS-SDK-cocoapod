//
//  JWCaptionConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 5/4/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
    JWEdgeStyle defines the border style of the caption.
 */
typedef NS_ENUM(NSInteger, JWEdgeStyle) {
    /// no border
    JWEdgeStyleNone,
    /// drop shadow for the border
    JWEdgeStyleDropshadow,
    /// border style is rendered as raised
    JWEdgeStyleRaised,
    /// border style is rendered as depressed
    JWEdgeStyleDepressed,
    /// border style is rendered as uniform
    JWEdgeStyleUniform
};

NS_ASSUME_NONNULL_BEGIN

/**
 Configuration object used to customize the captions. Must be set to the `JWConfig` object used to create the `JWPlayerController`.
 
 Styles specified using this structure will only be applied if the user's accessibility settings allow it, and only for SRT and WebVTT captions. EIA-608 captions always default to the user's accessibility settings.
 */
@interface JWCaptionStyling : NSObject

/* ========================================*/
/** @name Accessing Captions Styling Attributes
 */

/**
 Overrides the default font color of the captions, including its opacity.
 
 @note Styles specified using this property will only be applied if the user's accessibility settings allow it, and only for SRT and WebVTT captions. EIA-608 captions always default to the user's accessibility settings.
*/
@property (nonatomic, nullable, retain) UIColor *color;

/**
 Changes the background color and the opacity of the overall window the captions reside in.
 
 @note Styles specified using this property will only be applied if the user's accessibility settings allow it, and only for SRT and WebVTT captions. EIA-608 captions always default to the user's accessibility settings.
 */
@property (nonatomic, nullable, retain) UIColor *windowColor;

/**
 Changes the highlight color and highlight opacity of the text.
 
 @note Styles specified using this property will only be applied if the user's accessibility settings allow it, and only for SRT and WebVTT captions. EIA-608 captions always default to the user's accessibility settings.
 */
@property (nonatomic, nullable, retain) UIColor *backgroundColor;

/**
 Overrides the default font style and font size.
 
 @note Styles specified using this property will only be applied if the user's accessibility settings allow it, and only for SRT and WebVTT captions. EIA-608 captions always default to the user's accessibility settings.
 */
@property (nonatomic, nullable, retain) UIFont *font;

/**
 The edge style is an option to put emphasis around text. The available options are: none, dropshadow, raised, depressed, and uniform.
 
 @note Styles specified using this property will only be applied if the user's accessibility settings allow it, and only for SRT and WebVTT captions. EIA-608 captions always default to the user's accessibility settings.
 */
@property (nonatomic) JWEdgeStyle edgeStyle;

@end
NS_ASSUME_NONNULL_END
