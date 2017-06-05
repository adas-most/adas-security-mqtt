#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "cpabe-0.11/policy_lang.y"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <glib.h>
#include <pbc.h>

#include "common.h"
#include "policy_lang.h"

typedef struct
{
	uint64_t value;
	int bits; /* zero if this is a flexint */
}
sized_integer_t;

typedef struct
{
	int k;               /* one if leaf, otherwise threshold */
	char* attr;          /* attribute string if leaf, otherwise null */
	GPtrArray* children; /* pointers to bswabe_policy_t's, len == 0 for leaves */
}
cpabe_policy_t;

cpabe_policy_t* final_policy = 0;

int yylex();
int yyerror( const char* s );
sized_integer_t* expint( uint64_t value, uint64_t bits );
sized_integer_t* flexint( uint64_t value );
cpabe_policy_t* leaf_policy( char* attr );
cpabe_policy_t* kof2_policy( int k, cpabe_policy_t* l, cpabe_policy_t* r );
cpabe_policy_t* kof_policy( int k, GPtrArray* list );
cpabe_policy_t* eq_policy( sized_integer_t* n, char* attr );
cpabe_policy_t* lt_policy( sized_integer_t* n, char* attr );
cpabe_policy_t* gt_policy( sized_integer_t* n, char* attr );
cpabe_policy_t* le_policy( sized_integer_t* n, char* attr );
cpabe_policy_t* ge_policy( sized_integer_t* n, char* attr );
#line 44 "cpabe-0.11/policy_lang.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	char* str;
	uint64_t nat;
  sized_integer_t* sint;
	cpabe_policy_t* tree;
	GPtrArray* list;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 76 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TAG 257
#define INTLIT 258
#define OR 259
#define AND 260
#define OF 261
#define LEQ 262
#define GEQ 263
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,
};
static const short yylen[] = {                            2,
    1,    3,    1,    1,    3,    3,    5,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   11,   12,    8,    9,   10,    0,    2,   18,
   16,   17,   13,   14,   15,    0,    6,    0,    0,    7,
    0,    0,
};
static const short yydgoto[] = {                          4,
    5,    6,   39,
};
static const short yysindex[] = {                       -34,
  -53,  -35,  -34,    0,  -50, -231, -254, -254, -254, -254,
 -254,  -10, -227,  -39, -225, -222, -221, -220, -219,  -34,
  -34,    4,    0,    0,    0,    0,    0,  -34,    0,    0,
    0,    0,    0,    0,    0, -217,    0, -231,  -19,    0,
  -34, -231,
};
static const short yyrindex[] = {                         0,
    1,  -47,    0,    0,    0,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    5,    0,  -18,    0,    0,
    0,  -17,
};
static const short yygindex[] = {                         0,
   10,   13,    0,
};
#define YYTABLESIZE 264
static const short yytable[] = {                         13,
    4,   30,    3,   22,    5,    3,   10,    9,   11,   18,
   17,   19,    3,    3,    3,   14,   23,   24,   25,   26,
   27,   40,   19,   20,   41,   19,   20,   20,   21,   28,
   29,   31,   36,   37,   32,   33,   34,   35,   13,    1,
   38,    4,   21,    3,    4,    5,    3,    0,    5,    0,
    0,    0,    0,   42,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,    8,
    0,   15,   16,    0,    3,    3,    0,    0,    0,   20,
   21,    0,    1,    2,    0,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,
    4,    3,    3,    5,
};
static const short yycheck[] = {                         35,
    0,   41,    0,  258,    0,   40,   60,   61,   62,   60,
   61,   62,   60,   61,   62,    3,    7,    8,    9,   10,
   11,   41,   41,   41,   44,   44,   44,  259,  260,   40,
  258,  257,   20,   21,  257,  257,  257,  257,   35,    0,
   28,   41,  260,   41,   44,   41,   44,   -1,   44,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   -1,  262,  263,   -1,  262,  263,   -1,   -1,   -1,  259,
  260,   -1,  257,  258,   -1,  261,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,  259,  260,  259,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'#'",0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'<'","'='",
"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TAG",
"INTLIT","OR","AND","OF","LEQ","GEQ",
};
static const char *yyrule[] = {
"$accept : result",
"result : policy",
"number : INTLIT '#' INTLIT",
"number : INTLIT",
"policy : TAG",
"policy : policy OR policy",
"policy : policy AND policy",
"policy : INTLIT OF '(' arg_list ')'",
"policy : TAG '=' number",
"policy : TAG '<' number",
"policy : TAG '>' number",
"policy : TAG LEQ number",
"policy : TAG GEQ number",
"policy : number '=' TAG",
"policy : number '<' TAG",
"policy : number '>' TAG",
"policy : number LEQ TAG",
"policy : number GEQ TAG",
"policy : '(' policy ')'",
"arg_list : policy",
"arg_list : arg_list ',' policy",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 95 "cpabe-0.11/policy_lang.y"

sized_integer_t*
expint( uint64_t value, uint64_t bits )
{
	sized_integer_t* s;

	if( bits == 0 ){
		if(die("error parsing policy: zero-length integer \"%llub%llu\"\n",value, bits)==-1)
			return NULL;
	}else if( bits > 64 ){
		if(die("error parsing policy: no more than 64 bits allowed \"%llub%llu\"\n",value, bits)==-1)
			return NULL;
	}
	s = malloc(sizeof(sized_integer_t));
	s->value = value;
	s->bits = bits;

	return s;
}

sized_integer_t*
flexint( uint64_t value )
{
	sized_integer_t* s;

	s = malloc(sizeof(sized_integer_t));
	s->value = value;
	s->bits = 0;

	return s;
}

void
policy_free( cpabe_policy_t* p )
{
	int i;

	if( p->attr )
		free(p->attr);

	for( i = 0; i < p->children->len; i++ )
		policy_free(g_ptr_array_index(p->children, i));
	g_ptr_array_free(p->children, 1);

	free(p);
}

cpabe_policy_t*
leaf_policy( char* attr )
{
	cpabe_policy_t* p;

	p = (cpabe_policy_t*) malloc(sizeof(cpabe_policy_t));
	p->k = 1;
	p->attr = attr;
	p->children = g_ptr_array_new();

	return p;
}

cpabe_policy_t*
kof2_policy( int k, cpabe_policy_t* l, cpabe_policy_t* r )
{
	cpabe_policy_t* p;

	p = (cpabe_policy_t*) malloc(sizeof(cpabe_policy_t));
	p->k = k;
	p->attr = 0;
	p->children = g_ptr_array_new();
	g_ptr_array_add(p->children, l);
	g_ptr_array_add(p->children, r);

	return p;
}

cpabe_policy_t*
kof_policy( int k, GPtrArray* list )
{
	cpabe_policy_t* p;

	if( k < 1 ){
		if(die("error parsing policy: trivially satisfied operator \"%dof\"\n", k)==-1) return NULL;
	}else if( k > list->len ){
		if(die("error parsing policy: unsatisfiable operator \"%dof\" (only %d operands)\n",k, list->len)==-1) return NULL;
	}else if( list->len == 1 ){
		if(die("error parsing policy: identity operator \"%dof\" (only one operand)\n", k)==-1) return NULL;
	}
	p = (cpabe_policy_t*) malloc(sizeof(cpabe_policy_t));
	p->k = k;
	p->attr = 0;
	p->children = list;

	return p;
}

char*
bit_marker( char* base, char* tplate, int bit, char val )
{
	char* lx;
	char* rx;
	char* s;

 	lx = g_strnfill(64 - bit - 1, 'x');
	rx = g_strnfill(bit, 'x');
	s = g_strdup_printf(tplate, base, lx, !!val, rx);
	free(lx);
	free(rx);

	return s;
}

cpabe_policy_t*
eq_policy( sized_integer_t* n, char* attr )
{
	if( n->bits == 0 )
		return leaf_policy
			(g_strdup_printf("%s_flexint_%llu", attr, n->value));
	else
		return leaf_policy
			(g_strdup_printf("%s_expint%02d_%llu", attr, n->bits, n->value));

	return 0;
}

cpabe_policy_t*
bit_marker_list( int gt, char* attr, char* tplate, int bits, uint64_t value )
{
	cpabe_policy_t* p;
	int i;

	i = 0;
	while( gt ? (((uint64_t)1)<<i & value) : !(((uint64_t)1)<<i & value) )
		i++;

	p = leaf_policy(bit_marker(attr, tplate, i, gt));
	for( i = i + 1; i < bits; i++ )
		if( gt )
			p = kof2_policy(((uint64_t)1<<i & value) ? 2 : 1, p,
											leaf_policy(bit_marker(attr, tplate, i, gt)));
		else
			p = kof2_policy(((uint64_t)1<<i & value) ? 1 : 2, p,
											leaf_policy(bit_marker(attr, tplate, i, gt)));

	return p;
}

cpabe_policy_t*
flexint_leader( int gt, char* attr, uint64_t value )
{
	cpabe_policy_t* p;
	int k;

	p = (cpabe_policy_t*) malloc(sizeof(cpabe_policy_t));
	p->attr = 0;
	p->children = g_ptr_array_new();

	for( k = 2; k <= 32; k *= 2 )
		if( ( gt && ((uint64_t)1<<k) >  value) ||
				(!gt && ((uint64_t)1<<k) >= value) )
			g_ptr_array_add
				(p->children, leaf_policy
				 (g_strdup_printf(gt ? "%s_ge_2^%02d" : "%s_lt_2^%02d", attr, k)));

	p->k = gt ? 1 : p->children->len;

	if( p->children->len == 0 )
	{
		policy_free(p);
		p = 0;
	}
	else if( p->children->len == 1 )
	{
		cpabe_policy_t* t;
		
		t = g_ptr_array_remove_index(p->children, 0);
		policy_free(p);
		p = t;
	}
	
	return p;
}

cpabe_policy_t*
cmp_policy( sized_integer_t* n, int gt, char* attr )
{
	cpabe_policy_t* p;
	char* tplate;

	/* some error checking */

	if( gt && n->value >= ((uint64_t)1<<(n->bits ? n->bits : 64)) - 1 ){
		if(die("error parsing policy: unsatisfiable integer comparison %s > %llu\n"
				"(%d-bits are insufficient to satisfy)\n", attr, n->value,
				n->bits ? n->bits : 64)==-1) return NULL;
	}else if( !gt && n->value == 0 ){
		if(die("error parsing policy: unsatisfiable integer comparison %s < 0\n"
				"(all numerical attributes are unsigned)\n", attr)==-1) return NULL;
	}else if( !gt && n->value > ((uint64_t)1<<(n->bits ? n->bits : 64)) - 1 ){
		if(die("error parsing policy: trivially satisfied integer comparison %s < %llu\n"
				"(any %d-bit number will satisfy)\n", attr, n->value,
				n->bits ? n->bits : 64)==-1) return NULL;
	}
	/* create it */

	/* horrible */
	tplate = n->bits ?
		g_strdup_printf("%%s_expint%02d_%%s%%d%%s", n->bits) :
		strdup("%s_flexint_%s%d%s");
	p = bit_marker_list(gt, attr, tplate, n->bits ? n->bits :
											(n->value >= ((uint64_t)1<<32) ? 64 :
											 n->value >= ((uint64_t)1<<16) ? 32 :
											 n->value >= ((uint64_t)1<< 8) ? 16 :
											 n->value >= ((uint64_t)1<< 4) ?  8 :
											 n->value >= ((uint64_t)1<< 2) ?  4 : 2), n->value);
	free(tplate);

	if( !n->bits )
	{
		cpabe_policy_t* l;
		
		l = flexint_leader(gt, attr, n->value);
		if( l )
			p = kof2_policy(gt ? 1 : 2, l, p);
	}

	return p;
}

cpabe_policy_t*
lt_policy( sized_integer_t* n, char* attr )
{
	return cmp_policy(n, 0, attr);
}

cpabe_policy_t*
gt_policy( sized_integer_t* n, char* attr )
{
	return cmp_policy(n, 1, attr);
}

cpabe_policy_t*
le_policy( sized_integer_t* n, char* attr )
{
	n->value++;
	return cmp_policy(n, 0, attr);
}

cpabe_policy_t*
ge_policy( sized_integer_t* n, char* attr )
{
	n->value--;
	return cmp_policy(n, 1, attr);
}

char* cur_string = 0;

#define PEEK_CHAR ( *cur_string ? *cur_string     : EOF )
#define NEXT_CHAR ( *cur_string ? *(cur_string++) : EOF )

int
yylex()
{
  int c;
	int r;

  while( isspace(c = NEXT_CHAR) );

	r = 0;
  if( c == EOF )
    r = 0;
	else if( c == '&' )
		r = AND;
	else if( c == '|' )
		r = OR;
	else if( strchr("(),=#", c) || (strchr("<>", c) && PEEK_CHAR != '=') )
		r = c;
	else if( c == '<' && PEEK_CHAR == '=' )
	{
		NEXT_CHAR;
		r = LEQ;
	}
	else if( c == '>' && PEEK_CHAR == '=' )
	{
		NEXT_CHAR;
		r = GEQ;
	}
	else if( isdigit(c) )
	{
		GString* s;

		s = g_string_new("");
		g_string_append_c(s, c);
		while( isdigit(PEEK_CHAR) )
			g_string_append_c(s, NEXT_CHAR);

		sscanf(s->str, "%llu", &(yylval.nat));

		g_string_free(s, 1);
		r = INTLIT;
	}
	else if( isalpha(c) )
	{
		GString* s;

		s = g_string_new("");
		g_string_append_c(s, c);

		while( isalnum(PEEK_CHAR) || PEEK_CHAR == '_' )
			g_string_append_c(s, NEXT_CHAR);

		if( !strcmp(s->str, "and") )
		{
			g_string_free(s, 1);
			r = AND;
		}
		else if( !strcmp(s->str, "or") )
		{
			g_string_free(s, 1);
			r = OR;
		}
		else if( !strcmp(s->str, "of") )
		{
			g_string_free(s, 1);
			r = OF;
		}
		else
		{
			yylval.str = s->str;
			g_string_free(s, 0);
			r = TAG;
		}
	}
	else
		if(die("syntax error at \"%c%s\"\n", c, cur_string)==-1) return NULL;

	return r;
}

int
yyerror( const char* s )
{
  return die("error parsing policy: %s\n", s);
}

#define POLICY_IS_OR(p)  (((cpabe_policy_t*)(p))->k == 1 && ((cpabe_policy_t*)(p))->children->len)
#define POLICY_IS_AND(p) (((cpabe_policy_t*)(p))->k == ((cpabe_policy_t*)(p))->children->len)

void
merge_child( cpabe_policy_t* p, int i )
{
	int j;
	cpabe_policy_t* c;

	c = g_ptr_array_index(p->children, i);
	if( POLICY_IS_AND(p) )
	{
		p->k += c->k;
		p->k--;
	}

	g_ptr_array_remove_index_fast(p->children, i);
	for( j = 0; j < c->children->len; j++ )
		g_ptr_array_add(p->children, g_ptr_array_index(c->children, j));

	g_ptr_array_free(c->children, 0);
	free(c);
}

void
simplify( cpabe_policy_t* p )
{
	int i;

	for( i = 0; i < p->children->len; i++ )
		simplify(g_ptr_array_index(p->children, i));

	if( POLICY_IS_OR(p) )
		for( i = 0; i < p->children->len; i++ )
			if( POLICY_IS_OR(g_ptr_array_index(p->children, i)) )
				merge_child(p, i);

	if( POLICY_IS_AND(p) )
		for( i = 0; i < p->children->len; i++ )
			if( POLICY_IS_AND(g_ptr_array_index(p->children, i)) )
				merge_child(p, i);
}

int
cmp_tidy( const void* a, const void* b )
{
	cpabe_policy_t* pa;
	cpabe_policy_t* pb;

	pa = *((cpabe_policy_t**) a);
	pb = *((cpabe_policy_t**) b);

	if(      pa->children->len >  0 && pb->children->len == 0 )
		return -1;
	else if( pa->children->len == 0 && pb->children->len >  0 )
		return 1;
	else if( pa->children->len == 0 && pb->children->len == 0 )
		return strcmp(pa->attr, pb->attr);
	else
		return 0;	
}

void
tidy( cpabe_policy_t* p )
{
	int i;

	for( i = 0; i < p->children->len; i++ )
		tidy(g_ptr_array_index(p->children, i));

	if( p->children->len > 0 )
		qsort(p->children->pdata, p->children->len,
					sizeof(cpabe_policy_t*), cmp_tidy);
}

char*
format_policy_postfix( cpabe_policy_t* p )
{
	int i;
	char* r;
	char* s;
	char* t;

	if( p->children->len == 0 )
		return strdup(p->attr);

	r = format_policy_postfix(g_ptr_array_index(p->children, 0));
	for( i = 1; i < p->children->len; i++ )
	{
		s = format_policy_postfix(g_ptr_array_index(p->children, i));
		t = g_strjoin(" ", r, s, (char*) 0);
		free(r);
		free(s);
		r = t;
	}
	
	t = g_strdup_printf("%s %dof%d", r, p->k, p->children->len);
 	free(r);

	return t;
}

/*
	Crufty.
*/
int
actual_bits( uint64_t value )
{
	int i;

	for( i = 32; i >= 1; i /= 2 )
		if( value >= ((uint64_t)1<<i) )
			return i * 2;

	return 1;
}

/*
	It is pretty crufty having this here since it is only used in
	keygen. Maybe eventually there will be a separate .c file with the
	policy_lang module.
*/
int
parse_attribute( GSList** l, char* a )
{
	if( !strchr(a, '=') )
		*l = g_slist_append(*l, a);
	else
	{
		int i;
		char* s;
		char* tplate;
		uint64_t value;
		int bits;

		s = malloc(sizeof(char) * strlen(a));

		if( sscanf(a, " %s = %llu # %u ", s, &value, &bits) == 3 )
		{
			/* expint */

			if( bits > 64 ){
				return die("error parsing attribute \"%s\": 64 bits is the maximum allowed\n",
						a, value, bits);
			}
			if( value >= ((uint64_t)1<<bits) ){
				die("error parsing attribute \"%s\": value %llu too big for %d bits\n",
						a, value, bits);
			}
			tplate = g_strdup_printf("%%s_expint%02d_%%s%%d%%s", bits);
			for( i = 0; i < bits; i++ )
				*l = g_slist_append
					(*l, bit_marker(s, tplate, i, !!((uint64_t)1<<i & value)));
			free(tplate);

			*l = g_slist_append
				(*l, g_strdup_printf("%s_expint%02d_%llu", s, bits, value));
		}
		else if( sscanf(a, " %s = %llu ", s, &value) == 2 )
		{
			/* flexint */

			for( i = 2; i <= 32; i *= 2 )
				*l = g_slist_append
					(*l, g_strdup_printf
					 (value < ((uint64_t)1<<i) ? "%s_lt_2^%02d" : "%s_ge_2^%02d", s, i));

			for( i = 0; i < 64; i++ )
				*l = g_slist_append
					(*l, bit_marker(s, "%s_flexint_%s%d%s", i, !!((uint64_t)1<<i & value)));

			*l = g_slist_append
				(*l, g_strdup_printf("%s_flexint_%llu", s, value));
		}
		else
			return die("error parsing attribute \"%s\"\n"
					"(note that numerical attributes are unsigned integers)\n",	a);

 		free(s);
	}
	return 0;	
}

char*
parse_policy_lang(char* s )
{
	char* parsed_policy;

	cur_string = s;
	if(yyparse() == -1) return NULL;
 	simplify(final_policy);
 	tidy(final_policy);
	parsed_policy = format_policy_postfix(final_policy);
	policy_free(final_policy);

	return parsed_policy;
}
#line 829 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 67 "cpabe-0.11/policy_lang.y"
	{ final_policy = yystack.l_mark[0].tree; }
break;
case 2:
#line 69 "cpabe-0.11/policy_lang.y"
	{ yyval.sint = expint(yystack.l_mark[-2].nat, yystack.l_mark[0].nat); }
break;
case 3:
#line 70 "cpabe-0.11/policy_lang.y"
	{ yyval.sint = flexint(yystack.l_mark[0].nat);    }
break;
case 4:
#line 72 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = leaf_policy(yystack.l_mark[0].str);        }
break;
case 5:
#line 73 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = kof2_policy(1, yystack.l_mark[-2].tree, yystack.l_mark[0].tree); }
break;
case 6:
#line 74 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = kof2_policy(2, yystack.l_mark[-2].tree, yystack.l_mark[0].tree); }
break;
case 7:
#line 75 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = kof_policy(yystack.l_mark[-4].nat, yystack.l_mark[-1].list);     }
break;
case 8:
#line 76 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = eq_policy(yystack.l_mark[0].sint, yystack.l_mark[-2].str);      }
break;
case 9:
#line 77 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = lt_policy(yystack.l_mark[0].sint, yystack.l_mark[-2].str);      }
break;
case 10:
#line 78 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = gt_policy(yystack.l_mark[0].sint, yystack.l_mark[-2].str);      }
break;
case 11:
#line 79 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = le_policy(yystack.l_mark[0].sint, yystack.l_mark[-2].str);      }
break;
case 12:
#line 80 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = ge_policy(yystack.l_mark[0].sint, yystack.l_mark[-2].str);      }
break;
case 13:
#line 81 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = eq_policy(yystack.l_mark[-2].sint, yystack.l_mark[0].str);      }
break;
case 14:
#line 82 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = gt_policy(yystack.l_mark[-2].sint, yystack.l_mark[0].str);      }
break;
case 15:
#line 83 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = lt_policy(yystack.l_mark[-2].sint, yystack.l_mark[0].str);      }
break;
case 16:
#line 84 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = ge_policy(yystack.l_mark[-2].sint, yystack.l_mark[0].str);      }
break;
case 17:
#line 85 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = le_policy(yystack.l_mark[-2].sint, yystack.l_mark[0].str);      }
break;
case 18:
#line 86 "cpabe-0.11/policy_lang.y"
	{ yyval.tree = yystack.l_mark[-1].tree;                     }
break;
case 19:
#line 88 "cpabe-0.11/policy_lang.y"
	{ yyval.list = g_ptr_array_new();
                                       g_ptr_array_add(yyval.list, yystack.l_mark[0].tree); }
break;
case 20:
#line 90 "cpabe-0.11/policy_lang.y"
	{ yyval.list = yystack.l_mark[-2].list;
                                       g_ptr_array_add(yyval.list, yystack.l_mark[0].tree); }
break;
#line 1117 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
