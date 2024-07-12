%{
#include <string>
#include <iostream>
#include "ir/node.hpp"
#include "parser/parser.hpp"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) yylval.token = t; return t

extern int yylineno;
extern char* yytext;
int yycolumn = 1;


%}

%x COMMENT
%x MULTI_COMMENT

%option noyywrap
%option yylineno

%%

\/\/            { BEGIN COMMENT; }
<COMMENT>[^\n]* { ; }
<COMMENT>\n     { BEGIN 0; }

\/\*            { BEGIN MULTI_COMMENT; }
<MULTI_COMMENT>[^*]* { ; }
<MULTI_COMMENT>\*+[^*/]* { ; }
<MULTI_COMMENT>\*+\/ { BEGIN 0; }

"opt"           { TOKEN(KW_OPT); }
"for"           { TOKEN(KW_FOR); }
"ret"           { TOKEN(KW_RETURN); }
"fun"           { TOKEN(KW_FUNCTION); }
"var"           { TOKEN(KW_VAR); }

"Int"           { SAVE_TOKEN; return KW_INT;   }
"Flt"           { SAVE_TOKEN; return KW_FLOAT; }
"Boo"           { SAVE_TOKEN; return KW_BOOL;  }
"Str"           { SAVE_TOKEN; return KW_STRING; }
"Non"           { SAVE_TOKEN; return KW_NONE;  }

"true"                   { SAVE_TOKEN;         return BOOL; }
"false"                  { SAVE_TOKEN;         return BOOL; }
"maybe"                  { SAVE_TOKEN;         return BOOL; }
[0-9]+                   { SAVE_TOKEN;         return NUMBER; }
[0-9]+"."[0-9]*          { SAVE_TOKEN;         return FRAC_NUMBER; }
[A-Za-z_][A-Za-z0-9_]*   { SAVE_TOKEN;         return IDENTIFIER; }
\'[^"]*\'                { SAVE_TOKEN;         return STRING; }

"=="            { TOKEN(COM_EQ); }
"<="            { TOKEN(COM_LE); }
">="            { TOKEN(COM_GE); }
"<>"            { TOKEN(COM_NE); }

"<"             { TOKEN(COM_LT);  }
">"             { TOKEN(COM_GT);  }

"="             { TOKEN(OP_ASSIGN); }
"+"             { TOKEN(OP_PLUS);   }
"-"             { TOKEN(OP_MINUS);  }
"*"             { TOKEN(OP_MULT);   }
"/"             { TOKEN(OP_DIV);    }

"("             { TOKEN(LPAREN); }
")"             { TOKEN(RPAREN); }
"{"             { TOKEN(LBRACE); }
"}"             { TOKEN(RBRACE); }

","             { TOKEN(COMMA);    }
":"             { TOKEN(COLON); }
"!"             { TOKEN(SEMICOLON); }


[ \t\r]+        { ; }
\n              { yycolumn = 1; }

.               { std::cout << "unknown token: " << yytext << "\n"; yyterminate(); }

%%