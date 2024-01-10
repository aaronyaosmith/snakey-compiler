#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include <boost/spirit/include/lex_lexertl.hpp>

#include "lex_token_id.h"

template <typename Lexer> struct LexTokens : boost::spirit::lex::lexer<Lexer>
{
    LexTokens()
    {
        this->self.add
            // clang-format off

            // comments
            ("#.*$", LexTokenId::kIdComment)

            // NEWLINE, INDENT, DEDENT
            ("\\n", LexTokenId::kIdNewline)
            ("^\\s+$", LexTokenId::kIdIgnoredWhitespace)
            ("^ +", LexTokenId::kIdLeadingWhitespace)
            (" +", LexTokenId::kIdIgnoredWhitespace)

            // literals
            ("(\\\"[^\\n\\\"]*\\\")|('[^\\n']+')", LexTokenId::kIdString)
            ("[0-9]+(\\.[0-9]+)?", LexTokenId::kIdNumber)

            // keywords
            ("True", LexTokenId::kIdTrue)
            ("False", LexTokenId::kIdFalse)
            ("None", LexTokenId::kIdNone)
            ("while", LexTokenId::kIdWhile)
            ("if", LexTokenId::kIdIf)
            ("elif", LexTokenId::kIdElif)
            ("else", LexTokenId::kIdElse)
            ("def", LexTokenId::kIdDef)
            ("return", LexTokenId::kIdReturn)
            ("pass", LexTokenId::kIdPass)
            ("break", LexTokenId::kIdBreak)
            ("continue", LexTokenId::kIdContinue)

            // operators
            ("\\.", LexTokenId::kIdDot)
            ("=", LexTokenId::kIdAssign)
            (
                "([\\+\\-\\*\\/<>@%])|(==)|(<=)|(>=)|(!=)|(\\/\\/)",
                LexTokenId::kIdBinOp
            )
            ("not", LexTokenId::kIdUnOp)

            // delimiters
            ("\\(", LexTokenId::kIdLParen)
            ("\\)", LexTokenId::kIdRParen)
            (":", LexTokenId::kIdColon)
            (",", LexTokenId::kIdParamSep)
            (";", LexTokenId::kIdSemicolon)

            // identifiers
            ("[a-zA-Z_]+[a-zA-Z0-9_]*", LexTokenId::kIdIdentifier);

        // clang-format on
    }
};

struct Printer
{
    template <typename Token>
    bool operator()(Token const &t, std::ostream &os) const
    {
        std::string match{t.value().begin(), t.value().end()};
        auto name_string_it = token_to_name_string.find((LexTokenId)t.id());
        if (name_string_it == token_to_name_string.end())
        {
            throw std::logic_error("No name string for id " +
                                   std::to_string(t.id()));
        }
        if (match.find("\n") != std::string::npos) {
            os << name_string_it->second << "(<newline>)\n";
        }
        else
        {  
            os << name_string_it->second << "(" << match << ") ";
        }
        return true;
    }

  private:
    static const std::unordered_map<LexTokenId, std::string>
        token_to_name_string;
};

const std::unordered_map<LexTokenId, std::string>
    Printer::token_to_name_string{
        {LexTokenId::kIdComment, "Comment"},
        {LexTokenId::kIdIgnoredWhitespace, "IgnoredWhitespace"},
        {LexTokenId::kIdLeadingWhitespace, "LeadingWhitespace"},
        {LexTokenId::kIdNewline, "Newline"},
        {LexTokenId::kIdIgnoredWhitespace, "IgnoredWhitespace"},
        {LexTokenId::kIdString, "String"},
        {LexTokenId::kIdNumber, "Number"},
        {LexTokenId::kIdTrue, "True"},
        {LexTokenId::kIdFalse, "False"},
        {LexTokenId::kIdNone, "None"},
        {LexTokenId::kIdWhile, "While"},
        {LexTokenId::kIdIf, "If"},
        {LexTokenId::kIdElif, "Elif"},
        {LexTokenId::kIdElse, "Else"},
        {LexTokenId::kIdDef, "Def"},
        {LexTokenId::kIdReturn, "Return"},
        {LexTokenId::kIdPass, "Pass"},
        {LexTokenId::kIdBreak, "Break"},
        {LexTokenId::kIdContinue, "Continue"},
        {LexTokenId::kIdDot, "Dot"},
        {LexTokenId::kIdAssign, "Assign"},
        {LexTokenId::kIdUnOp, "UnOp"},
        {LexTokenId::kIdBinOp, "BinOp"},
        {LexTokenId::kIdLParen, "LParen"},
        {LexTokenId::kIdRParen, "RParen"},
        {LexTokenId::kIdColon, "Colon"},
        {LexTokenId::kIdParamSep, "ParamSep"},
        {LexTokenId::kIdSemicolon, "Semicolon"},
        {LexTokenId::kIdIdentifier, "Identifier"}};
