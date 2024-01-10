#pragma once

/**
 * Enum defining tokens for the lexer. Will not necessarily match the lexeme
 * output.
 * 
 * Some notes:
 *   - kIdLeadingWhitespace will be converted to "indent" and "dedent" lexemes
 *   - No tabs only spaces! Tabs are illegal
 */
enum LexTokenId
{
                          // Example:
    kIdIdentifier = 1000, // x
    kIdTrue,              // True
    kIdFalse,             // False
    kIdNone,              // None
    kIdNumber,            // 34.22
    kIdString,            // "Hello!!"
    kIdLParen,            // (
    kIdRParen,            // )
    kIdDot,               // .
    kIdUnOp,              // not
    kIdBinOp,             // +
    kIdColon,             // :
    kIdWhile,             // while
    kIdIf,                // if
    kIdElif,              // elif
    kIdElse,              // else
    kIdParamSep,          // ,
    kIdDef,               // def
    kIdReturn,            // return
    kIdAssign,            // =
    kIdPass,              // pass
    kIdBreak,             // break
    kIdContinue,          // continue
    kIdSemicolon,         // ;
    // kIdEndmarker,      // <EOF>
    kIdNewline,           // \n
    kIdLeadingWhitespace, // ^ 
    kIdIgnoredWhitespace, //  
    kIdComment            // # something something
};