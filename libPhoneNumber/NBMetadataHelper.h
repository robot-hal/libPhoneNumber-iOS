//
//  NBMetadataHelper.h
//  libPhoneNumber
//
//  Created by tabby on 2015. 2. 8..
//  Copyright (c) 2015년 ohtalk.me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBPhoneNumberDefines.h"

@class NBPhoneMetaData;

@interface NBMetadataHelper : NSObject

+ (BOOL)hasValue:(NSString * _Null_unspecified)string;

- (instancetype _Null_unspecified)initWithZippedData:(NSData * _Null_unspecified)data expandedLength:(NSUInteger)expandedLength;

- (instancetype _Nonnull)init;

- (NSArray * _Null_unspecified)regionCodeFromCountryCode:(NSNumber * _Null_unspecified)countryCodeNumber;
- (NSString * _Null_unspecified)countryCodeFromRegionCode:(NSString * _Null_unspecified)regionCode;

- (NBPhoneMetaData * _Null_unspecified)getMetadataForNonGeographicalRegion:(NSNumber * _Null_unspecified)countryCallingCode;
- (NBPhoneMetaData * _Null_unspecified)getMetadataForRegion:(NSString * _Null_unspecified)regionCode;

- (NSDictionary * _Null_unspecified)countryCodeToCountryNumberDictionary;
- (NSArray * _Null_unspecified)getAllMetadata;

@end
