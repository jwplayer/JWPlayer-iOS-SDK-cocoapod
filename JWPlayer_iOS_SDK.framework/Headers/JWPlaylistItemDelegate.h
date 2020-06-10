//
//  JWPlaylistItemDelegate.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/27/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

#ifndef JWPlaylistItemDelegate_h
#define JWPlaylistItemDelegate_h

@class JWPlaylistItem;

typedef NS_ENUM(NSInteger, JWPlaylistItemDecision) {
    JWPlaylistItemDecisionContinue = 0,
    JWPlaylistItemDecisionModify,
    JWPlaylistItemDecisionSkip
};

/**
 Defines methods for a delegate which responds to events related to a JWPlaylistItem.
*/
@protocol JWPlaylistItemDelegate <NSObject>

/**
 Fires during playlist item transitions. The transition will be paused until the completion block is called.
 @param playlistItem The upcoming playlist item.
 @param index The index of the upcoming playlist item.
 @param completion Call this block when you are ready to proceed with the playlist item load.
 @note The completion block produce 3 outcomes:
    * set decision to JWPlaylistItemDecisionContinue to proceed with the playlist item's load. You may call the block with a null newPlaylistItem.

    * set decision to JWPlaylistItemDecisionModify to load a different item or a modified version of the playlist item. You must call the completion block with an instance of JWPlaylistItem.

    * set decision to JWPlaylistItemDecisionSkip to reject this playlist item and proceed to the following one. You may call the block with a null newPlaylistItem.

 @note Only fires the first time the playlist item is requested. If the playlist item is replayed, the previous decision will apply. To reset, set the playlistItemDelegate again.
 @see JWPlaylistItem
 @see JWPlayerController
 */
- (void)playlistItem:(JWPlaylistItem *_Nonnull)playlistItem atIndex:(NSInteger)index willLoadAfterCompletion:(void (^_Nonnull)(JWPlaylistItemDecision decision, JWPlaylistItem * _Nullable newPlaylistItem))completion;

@end

#endif /* JWPlaylistItemDelegate_h */
