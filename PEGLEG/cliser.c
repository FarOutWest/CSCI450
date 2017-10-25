/* A recursive-descent parser generated by peg 0.1.18 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 7
#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy_end_solid(yycontext *yy); /* 7 */
YY_RULE(int) yy_end_normal(yycontext *yy); /* 6 */
YY_RULE(int) yy_end_loop(yycontext *yy); /* 5 */
YY_RULE(int) yy_vertex(yycontext *yy); /* 4 */
YY_RULE(int) yy_outer_loop(yycontext *yy); /* 3 */
YY_RULE(int) yy_facet_normal(yycontext *yy); /* 2 */
YY_RULE(int) yy_solid_description(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_end_normal(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_end_normal\n"));
  {
#line 0
  printf("%s\n");;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_end_loop(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_end_loop\n"));
  {
#line 0
  printf("%s\n");;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_vertex(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_vertex\n"));
  {
#line 0
  printf("%s\n");;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_outer_loop(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_outer_loop\n"));
  {
#line 0
  printf("%s\n");;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_facet_normal(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_facet_normal\n"));
  {
#line 0
  printf("%s\n");;
  }
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy_end_solid(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "end_solid"));  if (!yymatchString(yy, "endsolid")) goto l1;
  yyprintf((stderr, "  ok   %s @ %s\n", "end_solid", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "end_solid", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_end_normal(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "end_normal"));  if (!yymatchString(yy, "endfacet")) goto l2;  yyDo(yy, yy_1_end_normal, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "end_normal", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "end_normal", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_end_loop(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "end_loop"));  if (!yymatchString(yy, "endloop")) goto l3;  yyDo(yy, yy_1_end_loop, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "end_loop", yy->__buf+yy->__pos));
  return 1;
  l3:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "end_loop", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_vertex(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "vertex"));  if (!yymatchString(yy, "vertex")) goto l4;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\200\100\377\003\000\000\000\000\040\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l4;
  l5:;	
  {  int yypos6= yy->__pos, yythunkpos6= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\200\100\377\003\000\000\000\000\040\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l6;  goto l5;
  l6:;	  yy->__pos= yypos6; yy->__thunkpos= yythunkpos6;
  }  yyDo(yy, yy_1_vertex, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "vertex", yy->__buf+yy->__pos));
  return 1;
  l4:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "vertex", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_outer_loop(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "outer_loop"));  if (!yymatchString(yy, "outer loop")) goto l7;  yyDo(yy, yy_1_outer_loop, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "outer_loop", yy->__buf+yy->__pos));
  return 1;
  l7:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "outer_loop", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_facet_normal(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "facet_normal"));  if (!yymatchString(yy, "facet normal")) goto l8;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\200\100\377\003\000\000\000\000\040\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l8;
  l9:;	
  {  int yypos10= yy->__pos, yythunkpos10= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\200\100\377\003\000\000\000\000\040\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l10;  goto l9;
  l10:;	  yy->__pos= yypos10; yy->__thunkpos= yythunkpos10;
  }  yyDo(yy, yy_1_facet_normal, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "facet_normal", yy->__buf+yy->__pos));
  return 1;
  l8:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "facet_normal", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_solid_description(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "solid_description"));  if (!yymatchString(yy, "solid ")) goto l11;
  yyprintf((stderr, "  ok   %s @ %s\n", "solid_description", yy->__buf+yy->__pos));
  return 1;
  l11:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "solid_description", yy->__buf+yy->__pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_solid_description);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif
