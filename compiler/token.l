%{
#include <string>
#include <iostream>
#include "ir/node.hpp"
#include "utils/logger.hpp"
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

"opt"           { ddlbx::utility::Logger::info("TOKEN: KW_OPT");      TOKEN(KW_OPT); }
"for"           { ddlbx::utility::Logger::info("TOKEN: KW_FOR");      TOKEN(KW_FOR); }
"ret"           { ddlbx::utility::Logger::info("TOKEN: KW_RETURN");   TOKEN(KW_RETURN); }
"fun"           { ddlbx::utility::Logger::info("TOKEN: KW_FUNCTION"); TOKEN(KW_FUNCTION); }
"var"           { ddlbx::utility::Logger::info("TOKEN: KW_VAR");      TOKEN(KW_VAR); }
"obj"           { ddlbx::utility::Logger::info("TOKEN: KW_OBJECT");   TOKEN(KW_OBJECT); }

"Int"           { SAVE_TOKEN; ddlbx::utility::Logger::info("TOKEN: KW_INT");      return KW_INT;   }
"Flt"           { SAVE_TOKEN; ddlbx::utility::Logger::info("TOKEN: KW_FLOAT");    return KW_FLOAT; }
"Boo"           { SAVE_TOKEN; ddlbx::utility::Logger::info("TOKEN: KW_BOOL");     return KW_BOOL;  }
"Str"           { SAVE_TOKEN; ddlbx::utility::Logger::info("TOKEN: KW_STRING");   return KW_STRING; }
"Non"           { SAVE_TOKEN; ddlbx::utility::Logger::info("TOKEN: KW_NONE");     return KW_NONE;  }

"and"           { ddlbx::utility::Logger::info("TOKEN: AND");  TOKEN(OP_AND); }
"or"            { ddlbx::utility::Logger::info("TOKEN: OR");   TOKEN(OP_OR);  }
"not"           { ddlbx::utility::Logger::info("TOKEN: NOT");  TOKEN(OP_NOT); }

"from"          { ddlbx::utility::Logger::info("TOKEN: FROM");  TOKEN(KW_FROM); }
"to"            { ddlbx::utility::Logger::info("TOKEN: TO");    TOKEN(KW_TO); }
"step"          { ddlbx::utility::Logger::info("TOKEN: STEP");  TOKEN(KW_STEP); }

"true"                   { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
"false"                  { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
"maybe"                  { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: BOOL " + YYTEXT_STR);         return BOOL; }
[0-9]+                   { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: INT " + YYTEXT_STR);          return NUMBER; }
[0-9]+"."[0-9]*          { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: FLOAT " + YYTEXT_STR);        return FRAC_NUMBER; }
[A-Za-z_][A-Za-z0-9_]*   { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: IDENTIFIER " + YYTEXT_STR);   return IDENTIFIER; }
\'[^"]*\'                { SAVE_TOKEN;     ddlbx::utility::Logger::info("TOKEN: STRING " + YYTEXT_STR);       return STRING; }


"=="            { ddlbx::utility::Logger::info("TOKEN: EQ");   TOKEN(COM_EQ); }
"<="            { ddlbx::utility::Logger::info("TOKEN: LE");   TOKEN(COM_LE); }
">="            { ddlbx::utility::Logger::info("TOKEN: GE");   TOKEN(COM_GE); }
"<>"            { ddlbx::utility::Logger::info("TOKEN: NE");   TOKEN(COM_NE); }

"<"             { ddlbx::utility::Logger::info("TOKEN: '<'");  TOKEN(COM_LT);  }
">"             { ddlbx::utility::Logger::info("TOKEN: '>'");  TOKEN(COM_GT);  }

"="             { ddlbx::utility::Logger::info("TOKEN: '='");  TOKEN(OP_ASSIGN); }
"+"             { ddlbx::utility::Logger::info("TOKEN: '+'");  TOKEN(OP_PLUS);   }
"-"             { ddlbx::utility::Logger::info("TOKEN: '-'");  TOKEN(OP_MINUS);  }
"*"             { ddlbx::utility::Logger::info("TOKEN: '*'");  TOKEN(OP_MULT);   }
"/"             { ddlbx::utility::Logger::info("TOKEN: '/'");  TOKEN(OP_DIV);    }

"("             { ddlbx::utility::Logger::info("TOKEN: '('");  TOKEN(LPAREN); }
")"             { ddlbx::utility::Logger::info("TOKEN: ')'");  TOKEN(RPAREN); }
"{"             { ddlbx::utility::Logger::info("TOKEN: '{'");  TOKEN(LBRACE); }
"}"             { ddlbx::utility::Logger::info("TOKEN: '}'");  TOKEN(RBRACE); }

","             { ddlbx::utility::Logger::info("TOKEN: ','");  TOKEN(COMMA);    }
":"             { ddlbx::utility::Logger::info("TOKEN: ':'");  TOKEN(COLON); }
"!"             { ddlbx::utility::Logger::info("TOKEN: '!'");  TOKEN(SEMICOLON); }
"."             { ddlbx::utility::Logger::info("TOKEN: '.'");  TOKEN(DOT); }

[ \t\r]+        { ; }
\n              { yycolumn = 1; }

.               { ddlbx::utility::Logger::info("unknown token: " + YYTEXT_STR + "\n"); yyterminate(); }

%%