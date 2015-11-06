//
//  JWPlayerViewController.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 8/14/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JWConfig.h"
#import "JWPlayerDelegate.h"

#define JWPlayerAllNotification @"JWPlayerAllNotification"
#define JWMetaDataAvailableNotification @"JWMetaDataAvailableNotification"
#define JWPlayerStateChangedNotification @"JWPlayerStateChangedNotification"
#define JWPlaybackPositionChangedNotification @"JWPlaybackPositionChangedNotification"
#define JWFullScreenStateChangedNotification @"JWFullScreenStateChangedNotification"
#define JWAdActivityNotification @"JWAdActivityNotification"
#define JWAdPlaybackProgressNotification @"JWAdPlaybackProgressNotification"
#define JWAdClickNotification @"JWAdClickNotification"
#define JWErrorNotification @"JWErrorNotification"
#define JWCaptionsNotification @"JWCaptionsNotification"
#define JWVideoQualityNotification @"JWVideoQualityNotification"
#define JWPlaylistNotification @"JWPlaylistNotification"

/*!
 @class JWPlayerController
 A class that encapsulates JW Player and provides control over the playback as well as holds the state of the player and notifies about status updates.
 */
@interface JWPlayerController : NSObject


@property (nonatomic, retain, readonly) NSString *googleIMAVersion;
/*!
 Player view.
 @discussion to be added to the applicatiion view hierarchy.
 */
@property (nonatomic, retain, readonly) UIView *view;

/*!
 Returns current state of the player.
 @discussion Can be "idle", "playing", "paused" and "buffering".
 */
@property (nonatomic, retain, readonly) NSString *playerState;

/*!
 Metadata associated with the current video. Usually includes dimensions and duration of the video.
 @discussion becomes available shortly after the video starts playing. There is a notification JWMetaDataAvailableNotification posted right after metadata is available.
 */
@property (nonatomic, retain) NSDictionary *metadata;

/*!
 Dimensions of the current video. Becomes available shortly after the video starts to play as a part of metadata.
 */
@property (nonatomic) CGSize naturalSize;

/*!
 Duration of the current video. Becomes available shortly after the video starts to play as a part of metadata.
 */
@property (nonatomic) double duration;

/*!
 JWConfig object that was used to setup the player.
 @discussion Check JWConfig documentation for more info.
 */
@property (nonatomic, retain, readonly) JWConfig *config;

/*!
 Playback position of the current video.
 @discussion gets updated as the video plays. JWPlaybackProgressNotification is posted every time position changes. KVO compliant.
 */
@property (nonatomic, retain) NSNumber *playbackPosition;

/*!
 Returns the current PlaylistItem's filled buffer, as a percentage (0 to 100) of the total video's length.
 @discussion This only applies to progressive downloads of media (MP4/FLV/WebM and AAC/MP3/Vorbis); streaming media (HLS/RTMP/YouTube/DASH) do not expose this behavior.
 */
@property (nonatomic, readonly) NSInteger buffer;

/*!
 Enable the built-in controls by setting them true, disable the controls by setting them false.
 */
@property (nonatomic) BOOL controls;

/*!
 Returns the region of the display not used by the controls. You can use this information to ensure your visual assets don't overlap with the controls.
 */
@property (nonatomic, readonly) CGRect safeRegion;

/*!
 A Boolean value that determines whether the video is in full screen.
 */
@property (nonatomic, readonly) BOOL isInFullscreen;

/*!
 A Boolean value that determines whether the video should go to full screen mode when the device rotates to landscape.
 @discussion Make sure your app supports landscape to make this property work.
 */
@property (nonatomic) BOOL forceFullScreenOnLandscape;

/*!
 A Boolean value that determines whether the video should rotate to landscape when the fullscreen button is pressed.
 @discussion Make sure your app supports landscape to make this property work.
 */
@property (nonatomic) BOOL forceLandscapeOnFullScreen;

/*!
 If set to YES will open Safari after the user clicks the ad.
 */
@property (nonatomic) BOOL openSafariOnAdClick;

/*!
 The index of the caption object in captions list currently used by the player.
 @discussion index 0 stands for no caption.
 @see captionsList
 */
@property (nonatomic) NSInteger currentCaptions;

/*!
 The object that acts as the delegate of the jwPlayerController.
@discussion The delegate must adopt the JWPlayerDelegate protocol. The delegate is not retained.
 @see JWPlayerDelegate
 */
@property (nonatomic, weak) id<JWPlayerDelegate> delegate;

/*!
 The index of the object in quality levels list currently used by the player.
 */
@property (nonatomic) NSInteger currentQualityLevel;

/*!
 List of quality levels available for the current media.
 */
@property (nonatomic, retain, readonly) NSArray *levels;

/*!
 The index of the currently active item in the playlist.
 */
@property (nonatomic) NSInteger playlistIndex;

/*!
 List of all the captions supplied in the config
 @discussion Use currentCaptions to activate one of the captions programmatically.
 Object at index 0 is "off".
 @see currentCaptions
 */
@property (nonatomic, retain, readonly) NSArray *captionsList;

/*!
 Version of underlying web player
 */
@property (nonatomic, retain, readonly) NSString *playerVersion;

/*!
 Player edition based on the provided JW License key
 @discussion iOS SDK supports only "ads" and "enterprise"
 */
@property (nonatomic, retain, readonly) NSString *playerEdition;

/*!
 Inits the player with config object in JWConfig format.
 @param config  JWConfig object that is used to setup the player.
 */
- (instancetype)initWithConfig:(JWConfig *)config;

/*!
 Inits the player with config object in JWConfig format and sets the object that acts as the delegate of the jwPlayerController.
  @param config JWConfig object that is used to setup the player.
 @param delegate The object that acts as the delegate of the jwPlayerController.
 @see JWPlayerDelegate
 */
- (instancetype)initWithConfig:(JWConfig *)config delegate:(id<JWPlayerDelegate>)delegate;

/*!
 Starts to play video from current position.
 */
- (void)play;

/*!
 Pauses video.
 */
- (void)pause;

/*!
 Stops the player (returning it to the idle state) and unloads the currently playing media file.
 */
- (void)stop;

/*!
 @param position Time in the video to seek to
 @see duration
 */
- (void)seek:(NSUInteger)position;

/*!
 Switches the player to full screen mode.
 */
- (void)enterFullScreen;

/*!
 Switches the player to inline mode.
 */
- (void)exitFullScreen;

/*!
 Loads a new file into the player.
 @param file Video URL to play using JW Player.
 */
- (void)load:(NSString *)file;

/*!
 Loads a new JWConfig object into the player.
 @param config COnfiguration object.
 */
- (void)loadConfig:(JWConfig *)config;

/*!
 Loads a new playlist into the player.
 @param playlist An array containing playlist items.
 */
- (void)loadPlaylist:(NSArray *)playlist;

/*!
 Immediately starts to play an ad using the vastPlugin.
 @param tag Xml file with info about the ad.
 @discussion Usually used to inject an ad in streams where you can't schedule an ad. If you wish to play the ad with the Google IMA Client, please use playAd:onClient: instead and specify 'googima' as your ad client.
 */
- (void)playAd:(NSString *)tag;

/*!
 Immediately starts to play an ad.
 @param tag Xml file with info about the ad.
 @param adClient Set to googima if you wish to use google IMA; set to vastPlugin if not. Setting to nil defaults to vastPlugin. Note: Due to the fact that Google IMA's iOS SDK is still in Beta mode, we suggest using the vastPlugin.
 @discussion Usually used to inject an ad in streams where you can't schedule an ad.
 @see AdClient
 */
- (void)playAd:(NSString *)tag onClient:(JWAdClient)adClient;

/*!
 Version of the iOS SDK
 */
+ (NSString *)SDKVersion;

/*!
 Version of the iOS SDK, truncated. 
 (i.e.: if SDKVersion returns 1.001, SDKVersionToMinor returns 1.).
 */
+ (NSString *)SDKVersionToMinor;

@end
