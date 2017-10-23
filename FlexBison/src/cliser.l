%option noyywrap

%{
#include <iostream>
#include <assert.h>
#include <string.h>
#include <map>
#include "cliser.hpp"
#include "cliser.tab.hpp"

#define DEBUG_LEXER 1
%}

%%
[0-9]+ {
  yylval = node(atoi(yytext));
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as NUMBER: " << yylval << std::endl;
#endif
  return NUMBER;
}

(facet\tnormal|endfacet) {
  if (strcmp(yytext, "facet normal") == 0) {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as FACET NORMAL" << std::endl;
#endif
    return FACETNORMAL;
  }
  if (strcmp(yytext, "endfacet") == 0) {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as ENDFACET" << std::endl;
#endif
    return ENDFACET;
  }
  assert(0);
}

(outer\tloop|endloop) {
  if (strcmp(yytext, "outer loop") == 0) {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as OUTER LOOP" << std::endl;
#endif
    return OUTERLOOP;
  }
  if (strcmp(yytext, "endloop") == 0) {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as ENDLOOP" << std::endl;
#endif
    return ENDLOOP;
  }
  assert(0);
}

(vertex) {
  if (strcmp(yytext, "vertex") == 0) {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as VERTEX" << std::endl;
#endif
    return VERTEX;
  }
}

[ \t]+ {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as WHITE SPACE" << std::endl;
#endif
  return WS;
}

\r?\n {
#if DEBUG_LEXER == 1
  std::cout << "lexed " << yytext << " as EOL" << std::endl;
#endif
  return EOL;
}

. {
  std::cout << "syntax error '" << yytext << "'" << std::endl;
  assert(0);
}

%%
