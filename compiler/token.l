%{
#include <string>
#include <iostream>
#include "ir/node.hpp"
#include "utils/log.hpp"
#include "parser/parser.hpp"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) yylval.token = t; return t
#define YYTEXT_STR std::string(yytext)

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

"opt"           { ddlbx::utility::Log::log("TOKEN: KW_OPT");      TOKEN(KW_OPT); }
"for"           { ddlbx::utility::Log::log("TOKEN: KW_FOR");      TOKEN(KW_FOR); }
"ret"           { ddlbx::utility::Log::log("TOKEN: KW_RETURN");   TOKEN(KW_RETURN); }
"fun"           { ddlbx::utility::Log::log("TOKEN: KW_FUNCTION"); TOKEN(KW_FUNCTION); }
"var"           { ddlbx::utility::Log::log("TOKEN: KW_VAR");      TOKEN(KW_VAR); }

"Int"           { SAVE_TOKEN; ddlbx::utility::Log::log("TOKEN: KW_INT");      return KW_INT;   }
"Flt"           { SAVE_TOKEN; ddlbx::utility::Log::log("TOKEN: KW_FLOAT");    return KW_FLOAT; }
"Boo"           { SAVE_TOKEN; ddlbx::utility::Log::log("TOKEN: KW_BOOL");     return KW_BOOL;  }
"Str"           { SAVE_TOKEN; ddlbx::utility::Log::log("TOKEN: KW_STRING");   return KW_STRING; }
"Non"           { SAVE_TOKEN; ddlbx::utility::Log::log("TOKEN: KW_NONE");     return KW_NONE;  }

"and"           { ddlbx::utility::Log::log("TOKEN: AND");  TOKEN(OP_AND); }
"or"            { ddlbx::utility::Log::log("TOKEN: OR");   TOKEN(OP_OR);  }
"not"           { ddlbx::utility::Log::log("TOKEN: NOT");  TOKEN(OP_NOT); }

"true"                   { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
"false"                  { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
"maybe"                  { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
[0-9]+                   { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: INT " + YYTEXT_STR);          return NUMBER; }
[0-9]+"."[0-9]*          { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: FLOAT " + YYTEXT_STR);        return FRAC_NUMBER; }
[A-Za-z_][A-Za-z0-9_]*   { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: IDENTIFIER " + YYTEXT_STR);   return IDENTIFIER; }
\'[^"]*\'                { SAVE_TOKEN;     ddlbx::utility::Log::log("TOKEN: STRING " + YYTEXT_STR);       return STRING; }


"=="            { ddlbx::utility::Log::log("TOKEN: EQ");   TOKEN(COM_EQ); }
"<="            { ddlbx::utility::Log::log("TOKEN: LE");   TOKEN(COM_LE); }
">="            { ddlbx::utility::Log::log("TOKEN: GE");   TOKEN(COM_GE); }
"<>"            { ddlbx::utility::Log::log("TOKEN: NE");   TOKEN(COM_NE); }

"<"             { ddlbx::utility::Log::log("TOKEN: '<'");  TOKEN(COM_LT);  }
">"             { ddlbx::utility::Log::log("TOKEN: '>'");  TOKEN(COM_GT);  }

"="             { ddlbx::utility::Log::log("TOKEN: '='");  TOKEN(OP_ASSIGN); }
"+"             { ddlbx::utility::Log::log("TOKEN: '+'");  TOKEN(OP_PLUS);   }
"-"             { ddlbx::utility::Log::log("TOKEN: '-'");  TOKEN(OP_MINUS);  }
"*"             { ddlbx::utility::Log::log("TOKEN: '*'");  TOKEN(OP_MULT);   }
"/"             { ddlbx::utility::Log::log("TOKEN: '/'");  TOKEN(OP_DIV);    }

"("             { ddlbx::utility::Log::log("TOKEN: '('");  TOKEN(LPAREN); }
")"             { ddlbx::utility::Log::log("TOKEN: ')'");  TOKEN(RPAREN); }
"{"             { ddlbx::utility::Log::log("TOKEN: '{'");  TOKEN(LBRACE); }
"}"             { ddlbx::utility::Log::log("TOKEN: '}'");  TOKEN(RBRACE); }

","             { ddlbx::utility::Log::log("TOKEN: ','");  TOKEN(COMMA);    }
":"             { ddlbx::utility::Log::log("TOKEN: ':'");  TOKEN(COLON); }
"!"             { ddlbx::utility::Log::log("TOKEN: '!'");  TOKEN(SEMICOLON); }


[ \t\r]+        { ; }
\n              { yycolumn = 1; }

.               { ddlbx::utility::Log::log("unknown token: " + YYTEXT_STR + "\n"); yyterminate(); }

%%