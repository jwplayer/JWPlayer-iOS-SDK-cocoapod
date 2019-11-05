//
//  JWDrmDataSource.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 5/24/16.
//  Copyright © 2016 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
    Type of encryption for DRM content.
 */
typedef NS_ENUM(NSInteger, JWEncryption) {
    /// Apple's FairPlay encryption
    JWEncryptionFairPlay = 0
};

NS_ASSUME_NONNULL_BEGIN
/**
 The JWDrmDataSource protocol defines methods that get called when assistance is required to reproduce DRM encrypted content.
 */
@protocol JWDrmDataSource <NSObject>

@required

/**
 Called when the JW Player SDK realizes that a stream is DRM encrypted and requires a content identifier from the application to begin decrypting.
 
 @param loadingRequestURL The url of the resource being loaded.
 
 @param encryption The DRM system used (i.e. Apple FairPlay).
 
 @param completion The completion block used to provide the JW Player SDK with the content identifier. In the case of Apple FairPlay this is an opaque identifier for the content and is needed to obtain the SPC (Server Playback Context) message from the operating system.
 */
- (void)fetchContentIdentifierForRequest:(NSURL *)loadingRequestURL
                           forEncryption:(JWEncryption)encryption
                          withCompletion:(void (^)(NSData *contentIdentifier))completion;

/**
 Called when the JW Player SDK realizes that a stream is DRM encrypted and requires an application identifier from the application to begin decrypting.
 
 @param loadingRequestURL The url of the resource being loaded.
 
 @param encryption The DRM system used (i.e. Apple FairPlay).
 
 @param completion The completion block used to provide the JW Player SDK with the application identifier. In the case of Apple FairPlay this is the Application Certificate you receive after registering an FPS playback app.
 */
- (void)fetchAppIdentifierForRequest:(NSURL *)loadingRequestURL
             forEncryption:(JWEncryption)encryption
            withCompletion:(void (^)(NSData *appIdentifier))completion;

/**
 Called when the JW Player SDK needs the content key to being decrypting.
 
 @param requestBytes The key request data that must be transmitted to the key vendor to obtain the content key. In the case of Apple FairPlay this is the SPC (Server Playback Context) message from the operating system which must be sent to the Key Server in order to obtain the CKC (Content Key Context) message.
 
 @param encryption The DRM system used (i.e. Apple FairPlay).
 
 @param completion The completion block used to provide the JW Player SDK with the Server Response.
 In the case of Apple FairPlay, the response is the content key wrapped inside an encrypted Content Key Context (the CKC message) returned by the key server.
 In the case of Apple FairPlay, a date for renewal of resources that expire can be specified by passing a renewal date in the completion block. When specifying a renewal date the content type (the UTI indicating the type of data contained by the response) should be specified.
 */
- (void)fetchContentKeyWithRequest:(NSData *)requestBytes
                     forEncryption:(JWEncryption)encryption
                    withCompletion:(void (^)(NSData *response, NSDate *_Nullable renewalDate, NSString *_Nullable contentType))completion;

@end
NS_ASSUME_NONNULL_END
