//
//  JWPlaylistItem.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 12/8/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWAdConfig.h"
#import "JWTrack.h"

@class JWConfig;

/*!
 @class JWPlaylistItem
 An object providing info about playlist items.
 */
@interface JWPlaylistItem : NSObject

/*!
 An array of JWSource objects representing multiple quality levels of a video.
 @see JWSource
 */
@property (nonatomic, retain) NSArray *sources;

/*!
 Video URL to a single video file, to be played using JW Player.
 */
@property (nonatomic, retain) NSString *file;

/*!
 URL to a poster image. The image is displayed before and after playback, and in the listbar. For audio-only media, the poster image stays visible during playback.
 */
@property (nonatomic, retain) NSString *image;

/*!
 Title of the video.
 @discussion Shown in the listbar and in the play button container in the center of the screen before the video starts to play.
 */
@property (nonatomic, retain) NSString *title;

/*!
 An array of JWAdBreak objects that proivide info about ad breaks.
 @see JWAdBreak
 */
@property (nonatomic, retain) NSArray *adSchedule;

/*!
 An array of JWTrack objects providing captions for different languages.
 @see JWTrack
 */
@property (nonatomic, retain) NSArray *tracks;

/*!
 Short description of the item. It is displayed in the listbar.
 */
@property (nonatomic, retain) NSString *desc;

/*!
 Inits a JWPlaylistItem object with provided JWConfig.
 @param config configuration object.
 */
+ (instancetype)playlistItemWithConfig:(JWConfig *)config;

@end
