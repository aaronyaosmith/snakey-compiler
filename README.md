# Snakey

A toy compiler for Snakey: a language reminscent of Python.

So far this is just a messy lexer, printing lexemes to stdout.

## Example

`./Snakey < input.snak > output.txt`

### `output.txt`

Looks okay! Though some output isn't necessarily what I want:

```
Newline(<newline>)
Def(def) IgnoredWhitespace( ) Identifier(main) LParen(() RParen()) Colon(:) Newline(<newline>)
Newline(<newline>)
LeadingWhitespace(    ) Identifier(num) IgnoredWhitespace( ) Assign(=) IgnoredWhitespace( ) Number(2) Newline(<newline>)
LeadingWhitespace(    ) While(while) IgnoredWhitespace( ) Identifier(num) IgnoredWhitespace( ) BinOp(<) IgnoredWhitespace( ) Number(10) Colon(:) Newline(<newline>)
IgnoredWhitespace(    ) Newline(<newline>)
LeadingWhitespace(        ) If(if) IgnoredWhitespace( ) Identifier(num) IgnoredWhitespace( ) BinOp(%) IgnoredWhitespace( ) Number(2) IgnoredWhitespace( ) BinOp(==) IgnoredWhitespace( ) Number(0) Colon(:) Newline(<newline>)
LeadingWhitespace(            ) Identifier(print) LParen(() String("Found an even number") ParamSep(,) IgnoredWhitespace( ) Identifier(num) RParen()) Newline(<newline>)
Newline(<newline>)
LeadingWhitespace(        ) Continue(continue) Newline(<newline>)
Newline(<newline>)
LeadingWhitespace(    ) Identifier(print) LParen(() String("Found an odd number") ParamSep(,) IgnoredWhitespace( ) Identifier(num) RParen()) Newline(<newline>)

```