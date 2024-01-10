#include <iostream>
#include <utility>

#include <boost/spirit/include/lex_lexertl.hpp>

#include "lex_tokens.h"

namespace lex = boost::spirit::lex;

typedef lex::lexertl::token<std::string::const_iterator> string_token_type;

int main()
{
    std::string nextline;
    std::string input;
    while (getline(std::cin, nextline))
    {
        input += nextline;
        input += "\n";
    }

    if (std::cin.bad())
    {
        std::cout << "Input error\n";
        return 1;
    }

    LexTokens<lex::lexertl::lexer<string_token_type>> word_count_functor{};

    using std::placeholders::_1;
    auto input_it = input.cbegin();
    auto input_end = input.cend();
    Printer printer{};
    auto func = std::bind(&Printer::operator()<string_token_type>, &printer,
                          _1, std::ref(std::cout));
    bool success =
        lex::tokenize(input_it, input_end, word_count_functor, func);

    if (!success)
    {
        std::string rest(input_it, input_end);
        std::cout << "Lexical analysis failed\n"
                  << "stopped at: \"" << rest << "\"\n";
    }
    return 0;
}