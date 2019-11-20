//
//  LLDebugTool.h
//
//  Copyright (c) 2018 LLDebugTool Software Foundation (https://github.com/HDB-Li/LLDebugTool)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import <Foundation/Foundation.h>

#import "LLConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Control whether DebugTool is started.
 */
@interface LLDebugTool : NSObject

/**
 Singleton to control debugTool.
 
 @return Singleton
 */
+ (instancetype _Nonnull)sharedTool;

/**
 Start working.
 */
- (void)startWorking;

/**
 Start working with config block.

 @param configBlock Config block.
 */
- (void)startWorkingWithConfigBlock:(void (^__nullable)(LLConfig *config))configBlock;

/**
 Stop working.
 */
- (void)stopWorking;

/**
 Whether working or not.
 */
@property (nonatomic, assign, readonly) BOOL isWorking;

/**
 Execute action.
 
 @param action Action.
 */
- (void)executeAction:(LLDebugToolAction)action;

/**
 Execute action.

 @param action Action.
 @param data Data.
 */
- (void)executeAction:(LLDebugToolAction)action data:(NSDictionary <NSString *, id>*_Nullable)data;

/**
 Print and save a log model with infos.
 
 @param file File name.
 @param function Function name.
 @param lineNo Line number.
 @param level Log level.
 @param onEvent Event,can filter by this.
 @param message Message.
 */
- (void)logInFile:(NSString *_Nullable)file function:(NSString *_Nullable)function lineNo:(NSInteger)lineNo level:(LLConfigLogLevel)level onEvent:(NSString *_Nullable)onEvent message:(NSString *_Nullable)message;

#pragma mark - Version Control

/**
LLDebugTool's version.
*/
+ (NSString *)version;

/**
 Version number.
 */
+ (NSString *)versionNumber;

/**
Whether is Beta.
*/
+ (BOOL)isBetaVersion;

#pragma mark - DEPRECATED

/**
 LLDebugTool's version.
 */
@property (nonatomic, copy, readonly) NSString * version LLDebugToolDeprecated("Use class method.");

/**
 Whether is Beta.
 */
@property (nonatomic, assign, readonly) BOOL isBetaVersion LLDebugToolDeprecated("Use class method.");

@end

NS_ASSUME_NONNULL_END
