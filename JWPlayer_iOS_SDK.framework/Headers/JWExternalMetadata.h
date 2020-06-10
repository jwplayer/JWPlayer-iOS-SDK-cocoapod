//
//  JWExternalMetadata.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/1/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Metadata that can be passed externally, to supplement the encoded metadata of the underlying media asset.
 @discussion surfaced via the JWPlayerDelegate's onMeta call when playback position reaches the position specified in the startTime property, or by seeking to position in between startTime and endTime.
 @see JWPlayerDelegate
 */
@interface JWExternalMetadata : NSObject

/**
 Playback position in seconds indicating the start of the  range in which the Metadata will be surfaced.
 */
@property (nonatomic) CGFloat startTime;

/**
 Playback position in seconds indicating the end of the range in which the Metadata will be surfaced.
 */
@property (nonatomic) CGFloat endTime;

/**
 Unique identifier.
 */
@property (nonatomic) NSInteger identifier;

- (instancetype)initWithIdentifier:(NSInteger)identifier startTime:(CGFloat)startTime endTime:(CGFloat)endTime;

@end

NS_ASSUME_NONNULL_END
