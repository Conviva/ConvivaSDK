//
//  CISJSONDecoder.h
//  iOSConvivaSDK
//
//  Created by Nirvaid Rathore on 19/04/16.
//  Copyright © 2016 Conviva. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import "CISLogger.h"

@interface CISJSONDecoder : NSObject {
@private
    int currIdx;    // Index into the string for the current character being read
    int tokenStart; // Index into the string for the start of the current token
    int tokenLen;
    
    // The token types
    enum TokenType {
        TOK_NUMBER,
        TOK_STRING,
        TOK_LBRACE,
        TOK_RBRACE,
        TOK_COMMA,
        TOK_COLON,
        TOK_LBRACKET,
        TOK_RBRACKET,
        TOK_EOF
    } currToken; // The current token
}

@property(nonatomic, copy) NSString *pInput;
@property(nonatomic, strong) id pObject; // The parsed object

// Extract the result of the parser
- (void)assignInputString:(NSString *)input;
- (id)asObject;
- (NSDictionary *)asDictionary;
- (NSArray *)asArray;
- (double)asNumber;
- (NSString *)asString;

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithLogger:(CISLogger *)logger NS_DESIGNATED_INITIALIZER;

@end
