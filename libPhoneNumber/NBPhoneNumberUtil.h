//
//  NBPhoneNumberUtil.h
//  libPhoneNumber
//
//  Created by tabby on 2015. 2. 8..
//  Copyright (c) 2015년 ohtalk.me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBPhoneNumberDefines.h"

@class NBPhoneMetaData, NBPhoneNumber, NBMetadataHelper;

@interface NBPhoneNumberUtil : NSObject

+ (NBPhoneNumberUtil * _Null_unspecified)sharedInstance;
- (instancetype _Nonnull)initWithMetadataHelper:(NBMetadataHelper * _Nonnull)helper;

- (instancetype _Null_unspecified)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) NSDictionary * _Null_unspecified DIGIT_MAPPINGS;

// regular expressions
- (NSArray * _Null_unspecified)matchesByRegex:(NSString * _Null_unspecified)sourceString regex:(NSString * _Null_unspecified)pattern;
- (NSArray * _Null_unspecified)matchedStringByRegex:(NSString * _Null_unspecified)sourceString regex:(NSString * _Null_unspecified)pattern;
- (NSString * _Null_unspecified)replaceStringByRegex:(NSString * _Null_unspecified)sourceString
                             regex:(NSString * _Null_unspecified)pattern
                      withTemplate:(NSString * _Null_unspecified)templateString;
- (int)stringPositionByRegex:(NSString * _Null_unspecified)sourceString regex:(NSString * _Null_unspecified)pattern;

// libPhoneNumber Util functions
- (NSString * _Null_unspecified)convertAlphaCharactersInNumber:(NSString * _Null_unspecified)number;

- (NSString * _Null_unspecified)normalize:(NSString * _Null_unspecified)phoneNumber;
- (NSString * _Null_unspecified)normalizeDigitsOnly:(NSString * _Null_unspecified)number;
- (NSString * _Null_unspecified)normalizeDiallableCharsOnly:(NSString * _Null_unspecified)number;

- (BOOL)isNumberGeographical:(NBPhoneNumber * _Null_unspecified)phoneNumber;

- (NSString * _Null_unspecified)extractPossibleNumber:(NSString * _Null_unspecified)phoneNumber;
- (NSNumber * _Null_unspecified)extractCountryCode:(NSString * _Null_unspecified)fullNumber nationalNumber:(NSString * _Null_unspecified * _Null_unspecified)nationalNumber;
- (NSString * _Null_unspecified)countryCodeByCarrier;

- (NSString * _Null_unspecified)getNddPrefixForRegion:(NSString * _Null_unspecified)regionCode stripNonDigits:(BOOL)stripNonDigits;
- (NSString * _Null_unspecified)getNationalSignificantNumber:(NBPhoneNumber * _Null_unspecified)phoneNumber;

- (NSArray * _Null_unspecified)getSupportedRegions;

- (NBEPhoneNumberType)getNumberType:(NBPhoneNumber * _Null_unspecified)phoneNumber;

- (NSNumber * _Null_unspecified)getCountryCodeForRegion:(NSString * _Null_unspecified)regionCode;

- (NSString * _Null_unspecified)getRegionCodeForCountryCode:(NSNumber * _Null_unspecified)countryCallingCode;
- (NSArray * _Null_unspecified)getRegionCodesForCountryCode:(NSNumber * _Null_unspecified)countryCallingCode;
- (NSString * _Null_unspecified)getRegionCodeForNumber:(NBPhoneNumber * _Null_unspecified)phoneNumber;

- (NBPhoneNumber * _Null_unspecified)getExampleNumber:(NSString * _Null_unspecified)regionCode error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NBPhoneNumber * _Null_unspecified)getExampleNumberForType:(NSString * _Null_unspecified)regionCode
                                      type:(NBEPhoneNumberType)type
                                     error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NBPhoneNumber * _Null_unspecified)getExampleNumberForNonGeoEntity:(NSNumber * _Null_unspecified)countryCallingCode
                                             error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (BOOL)canBeInternationallyDialled:(NBPhoneNumber * _Null_unspecified)number error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (BOOL)truncateTooLongNumber:(NBPhoneNumber * _Null_unspecified)number;

- (BOOL)isValidNumber:(NBPhoneNumber * _Null_unspecified)number;
- (BOOL)isViablePhoneNumber:(NSString * _Null_unspecified)phoneNumber;
- (BOOL)isAlphaNumber:(NSString * _Null_unspecified)number;
- (BOOL)isValidNumberForRegion:(NBPhoneNumber * _Null_unspecified)number regionCode:(NSString * _Null_unspecified)regionCode;
- (BOOL)isNANPACountry:(NSString * _Null_unspecified)regionCode;
- (BOOL)isLeadingZeroPossible:(NSNumber * _Null_unspecified)countryCallingCode;

- (NBEValidationResult)isPossibleNumberWithReason:(NBPhoneNumber * _Null_unspecified)number error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (BOOL)isPossibleNumber:(NBPhoneNumber * _Null_unspecified)number;
- (BOOL)isPossibleNumber:(NBPhoneNumber * _Null_unspecified)number error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (BOOL)isPossibleNumberString:(NSString * _Null_unspecified)number
             regionDialingFrom:(NSString * _Null_unspecified)regionDialingFrom
                         error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (NBEMatchType)isNumberMatch:(id _Null_unspecified)firstNumberIn second:(id _Null_unspecified)secondNumberIn error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (int)getLengthOfGeographicalAreaCode:(NBPhoneNumber * _Null_unspecified)phoneNumber error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (int)getLengthOfNationalDestinationCode:(NBPhoneNumber * _Null_unspecified)phoneNumber error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (BOOL)maybeStripNationalPrefixAndCarrierCode:(NSString * _Null_unspecified * _Null_unspecified)numberStr
                                      metadata:(NBPhoneMetaData * _Null_unspecified)metadata
                                   carrierCode:(NSString * _Null_unspecified * _Null_unspecified)carrierCode;
- (NBECountryCodeSource)maybeStripInternationalPrefixAndNormalize:(NSString * _Null_unspecified * _Null_unspecified)numberStr
                                                possibleIddPrefix:(NSString * _Null_unspecified)possibleIddPrefix;

- (NSNumber * _Null_unspecified)maybeExtractCountryCode:(NSString * _Null_unspecified)number
                             metadata:(NBPhoneMetaData * _Null_unspecified)defaultRegionMetadata
                       nationalNumber:(NSString * _Null_unspecified * _Null_unspecified)nationalNumber
                         keepRawInput:(BOOL)keepRawInput
                          phoneNumber:(NBPhoneNumber * _Null_unspecified * _Null_unspecified)phoneNumber
                                error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (NBPhoneNumber * _Null_unspecified)parse:(NSString * _Null_unspecified)numberToParse
           defaultRegion:(NSString * _Null_unspecified)defaultRegion
                   error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NBPhoneNumber * _Null_unspecified)parseAndKeepRawInput:(NSString * _Null_unspecified)numberToParse
                          defaultRegion:(NSString * _Null_unspecified)defaultRegion
                                  error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NBPhoneNumber * _Null_unspecified)parseWithPhoneCarrierRegion:(NSString * _Null_unspecified)numberToParse error:(NSError * _Null_unspecified * _Null_unspecified)error;

- (NSString * _Null_unspecified)format:(NBPhoneNumber * _Null_unspecified)phoneNumber
        numberFormat:(NBEPhoneNumberFormat)numberFormat
               error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatByPattern:(NBPhoneNumber * _Null_unspecified)number
                 numberFormat:(NBEPhoneNumberFormat)numberFormat
           userDefinedFormats:(NSArray * _Null_unspecified)userDefinedFormats
                        error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatNumberForMobileDialing:(NBPhoneNumber * _Null_unspecified)number
                         regionCallingFrom:(NSString * _Null_unspecified)regionCallingFrom
                            withFormatting:(BOOL)withFormatting
                                     error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatOutOfCountryCallingNumber:(NBPhoneNumber * _Null_unspecified)number
                            regionCallingFrom:(NSString * _Null_unspecified)regionCallingFrom
                                        error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatOutOfCountryKeepingAlphaChars:(NBPhoneNumber * _Null_unspecified)number
                                regionCallingFrom:(NSString * _Null_unspecified)regionCallingFrom
                                            error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatNationalNumberWithCarrierCode:(NBPhoneNumber * _Null_unspecified)number
                                      carrierCode:(NSString * _Null_unspecified)carrierCode
                                            error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatInOriginalFormat:(NBPhoneNumber * _Null_unspecified)number
                   regionCallingFrom:(NSString * _Null_unspecified)regionCallingFrom
                               error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (NSString * _Null_unspecified)formatNationalNumberWithPreferredCarrierCode:(NBPhoneNumber * _Null_unspecified)number
                                       fallbackCarrierCode:(NSString * _Null_unspecified)fallbackCarrierCode
                                                     error:(NSError * _Null_unspecified * _Null_unspecified)error;
- (BOOL)formattingRuleHasFirstGroupOnly:(NSString * _Null_unspecified)nationalPrefixFormattingRule;

/**
 * Returns the mobile token for the provided country calling code if it has one, otherwise
 * returns an empty string. A mobile token is a number inserted before the area code when dialing
 * a mobile number from that country from abroad.
 *
 * @param countryCallingCode  the country calling code for which we want the mobile token.
 * @return  the mobile token, as a string, for the given country calling code.
 */
- (NSString * _Null_unspecified)getCountryMobileTokenFromCountryCode:(NSInteger)countryCallingCode;

@end
