#ifndef kc_scanner_h
#define kc_scanner_h

typedef enum {
    // Single-character tokens
    TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,
    TOKEN_LEFT_BRACKET, TOKEN_RIGHT_BRACKET,
    TOKEN_COMMA, TOKEN_DOT, TOKEN_MINUS, TOKEN_PLUS,
    TOKEN_PLUS_EQUAL, TOKEN_MINUS_EQUAL,
    TOKEN_SEMICOLON, TOKEN_SLASH, TOKEN_STAR,
    TOKEN_STAR_EQUAL, TOKEN_SLASH_EQUAL,

    // one to two character tokens like !=
    TOKEN_BANG, TOKEN_BANG_EQUAL, // This is for ! or != equivalently
    TOKEN_EQUAL, TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER, TOKEN_GREATER_EQUAL,
    TOKEN_LESS, TOKEN_LESS_EQUAL,

    // Literals
    TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_NUMBER,

    // Likely going to add more to these key-words
    TOKEN_AND, TOKEN_CLASS, TOKEN_ELSE, TOKEN_FALSE,
    TOKEN_FOR, TOKEN_FUNCTION, TOKEN_IF, TOKEN_NULL, TOKEN_OR,
    TOKEN_PRINT, TOKEN_BREAK, TOKEN_NEXT, TOKEN_RETURN, TOKEN_SUPER, TOKEN_THIS,
    TOKEN_TRUE, TOKEN_VAR, TOKEN_WHILE,

    TOKEN_ERROR, TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    const char* start;
    int length;
    int line;
} Token;

void initScanner(const char* source);
Token scanToken();


#endif