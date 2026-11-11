//
//  NBAsYouTypeFormatter.h
//  libPhoneNumber
//
//  Created by ishtar on 13. 2. 25..
//

#import <Foundation/Foundation.h>

@class NBAsYouTypeFormatter;
@class NBMetadataHelper;

@interface NBAsYouTypeFormatter : NSObject

- (instancetype _Nonnull)initWithRegionCode:(NSString * _Nullable)regionCode;
- (instancetype _Nonnull)initWithRegionCode:(NSString * _Nullable)regionCode metadataHelper:(NBMetadataHelper * _Nonnull)helper;

- (NSString * _Null_unspecified)inputString:(NSString * _Null_unspecified)string;
- (NSString * _Null_unspecified)inputStringAndRememberPosition:(NSString * _Null_unspecified)string;

- (NSString * _Null_unspecified)inputDigit:(NSString * _Null_unspecified)nextChar;
- (NSString * _Null_unspecified)inputDigitAndRememberPosition:(NSString * _Null_unspecified)nextChar;

- (NSString * _Null_unspecified)removeLastDigit;
- (NSString * _Null_unspecified)removeLastDigitAndRememberPosition;

- (NSInteger)getRememberedPosition;

- (void)clear;

@property(nonatomic, assign, readonly) BOOL isSuccessfulFormatting;

@end
