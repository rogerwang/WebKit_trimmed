/*
//
// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

This file contains the Lex specification for GLSL ES.
Based on ANSI C grammar, Lex specification:
http://www.lysator.liu.se/c/ANSI-C-grammar-l.html

IF YOU MODIFY THIS FILE YOU ALSO NEED TO RUN generate_parser.sh,
WHICH GENERATES THE GLSL ES LEXER (glslang_lex.cpp).
*/

%top{
//
// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// This file is auto-generated by generate_parser.sh. DO NOT EDIT!

// Ignore errors in auto-generated code.
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wswitch-enum"
#elif defined(_MSC_VER)
#pragma warning(disable: 4065)
#pragma warning(disable: 4189)
#pragma warning(disable: 4505)
#pragma warning(disable: 4701)
#endif
}

%{
#include "compiler/glslang.h"
#include "compiler/ParseHelper.h"
#include "compiler/preprocessor/Token.h"
#include "compiler/util.h"
#include "glslang_tab.h"

/* windows only pragma */
#ifdef _MSC_VER
#pragma warning(disable : 4102)
#endif

#define YY_USER_ACTION yylval->lex.line = yylineno;
#define YY_INPUT(buf, result, max_size) \
    result = string_input(buf, max_size, yyscanner);

static yy_size_t string_input(char* buf, yy_size_t max_size, yyscan_t yyscanner);
static int check_type(yyscan_t yyscanner);
static int reserved_word(yyscan_t yyscanner);
%}

%option noyywrap nounput never-interactive
%option yylineno reentrant bison-bridge
%option stack
%option extra-type="TParseContext*"
%x COMMENT FIELDS

D           [0-9]
L           [a-zA-Z_]
H           [a-fA-F0-9]
E           [Ee][+-]?{D}+
O           [0-7]

%%

%{
    TParseContext* context = yyextra;
%}

    /* Single-line comments */
"//"[^\n]* ;

    /* Multi-line comments */
"/*"           { yy_push_state(COMMENT, yyscanner); }
<COMMENT>. |
<COMMENT>\n ;
<COMMENT>"*/"  { yy_pop_state(yyscanner); }

"invariant"    { return(INVARIANT); }
"highp"        { return(HIGH_PRECISION); }
"mediump"      { return(MEDIUM_PRECISION); }
"lowp"         { return(LOW_PRECISION); }
"precision"    { return(PRECISION); }

"attribute"    { return(ATTRIBUTE); }
"const"        { return(CONST_QUAL); }
"uniform"      { return(UNIFORM); }
"varying"      { return(VARYING); }

"break"        { return(BREAK); }
"continue"     { return(CONTINUE); }
"do"           { return(DO); }
"for"          { return(FOR); }
"while"        { return(WHILE); }

"if"           { return(IF); }
"else"         { return(ELSE); }

"in"           { return(IN_QUAL); }
"out"          { return(OUT_QUAL); }
"inout"        { return(INOUT_QUAL); }

"float"        { context->lexAfterType = true; return(FLOAT_TYPE); }
"int"          { context->lexAfterType = true; return(INT_TYPE); }
"void"         { context->lexAfterType = true; return(VOID_TYPE); }
"bool"         { context->lexAfterType = true; return(BOOL_TYPE); }
"true"         { yylval->lex.b = true;  return(BOOLCONSTANT); }
"false"        { yylval->lex.b = false; return(BOOLCONSTANT); }

"discard"      { return(DISCARD); }
"return"       { return(RETURN); }

"mat2"         { context->lexAfterType = true; return(MATRIX2); }
"mat3"         { context->lexAfterType = true; return(MATRIX3); }
"mat4"         { context->lexAfterType = true; return(MATRIX4); }

"vec2"         { context->lexAfterType = true; return (VEC2); }
"vec3"         { context->lexAfterType = true; return (VEC3); }
"vec4"         { context->lexAfterType = true; return (VEC4); }
"ivec2"        { context->lexAfterType = true; return (IVEC2); }
"ivec3"        { context->lexAfterType = true; return (IVEC3); }
"ivec4"        { context->lexAfterType = true; return (IVEC4); }
"bvec2"        { context->lexAfterType = true; return (BVEC2); }
"bvec3"        { context->lexAfterType = true; return (BVEC3); }
"bvec4"        { context->lexAfterType = true; return (BVEC4); }

"sampler2D"       { context->lexAfterType = true; return SAMPLER2D; }
"samplerCube"     { context->lexAfterType = true; return SAMPLERCUBE; }
"samplerExternalOES" { context->lexAfterType = true; return SAMPLER_EXTERNAL_OES; }
"sampler2DRect" { context->lexAfterType = true; return SAMPLER2DRECT; }

"struct"       { context->lexAfterType = true; return(STRUCT); }

"asm"          { return reserved_word(yyscanner); }

"class"        { return reserved_word(yyscanner); }
"union"        { return reserved_word(yyscanner); }
"enum"         { return reserved_word(yyscanner); }
"typedef"      { return reserved_word(yyscanner); }
"template"     { return reserved_word(yyscanner); }
"this"         { return reserved_word(yyscanner); }
"packed"       { return reserved_word(yyscanner); }

"goto"         { return reserved_word(yyscanner); }
"switch"       { return reserved_word(yyscanner); }
"default"      { return reserved_word(yyscanner); }

"inline"       { return reserved_word(yyscanner); }
"noinline"     { return reserved_word(yyscanner); }
"volatile"     { return reserved_word(yyscanner); }
"public"       { return reserved_word(yyscanner); }
"static"       { return reserved_word(yyscanner); }
"extern"       { return reserved_word(yyscanner); }
"external"     { return reserved_word(yyscanner); }
"interface"    { return reserved_word(yyscanner); }
"flat"         { return reserved_word(yyscanner); }

"long"         { return reserved_word(yyscanner); }
"short"        { return reserved_word(yyscanner); }
"double"       { return reserved_word(yyscanner); }
"half"         { return reserved_word(yyscanner); }
"fixed"        { return reserved_word(yyscanner); }
"unsigned"     { return reserved_word(yyscanner); }
"superp"       { return reserved_word(yyscanner); }

"input"        { return reserved_word(yyscanner); }
"output"       { return reserved_word(yyscanner); }

"hvec2"        { return reserved_word(yyscanner); }
"hvec3"        { return reserved_word(yyscanner); }
"hvec4"        { return reserved_word(yyscanner); }
"dvec2"        { return reserved_word(yyscanner); }
"dvec3"        { return reserved_word(yyscanner); }
"dvec4"        { return reserved_word(yyscanner); }
"fvec2"        { return reserved_word(yyscanner); }
"fvec3"        { return reserved_word(yyscanner); }
"fvec4"        { return reserved_word(yyscanner); }

"sampler1D"    { return reserved_word(yyscanner); }
"sampler3D"    { return reserved_word(yyscanner); }

"sampler1DShadow" { return reserved_word(yyscanner); }
"sampler2DShadow" { return reserved_word(yyscanner); }

"sampler3DRect" { return reserved_word(yyscanner); }
"sampler2DRectShadow" { return reserved_word(yyscanner); }

"sizeof"       { return reserved_word(yyscanner); }
"cast"         { return reserved_word(yyscanner); }

"namespace"    { return reserved_word(yyscanner); }
"using"        { return reserved_word(yyscanner); }

{L}({L}|{D})*       {
   yylval->lex.string = NewPoolTString(yytext); 
   return check_type(yyscanner);
}

0[xX]{H}+         { yylval->lex.i = static_cast<int>(strtol(yytext, 0, 0)); return(INTCONSTANT); }
0{O}+             { yylval->lex.i = static_cast<int>(strtol(yytext, 0, 0)); return(INTCONSTANT); }
0{D}+             { context->error(yylineno, "Invalid Octal number.", yytext); context->recover(); return 0;}
{D}+              { yylval->lex.i = static_cast<int>(strtol(yytext, 0, 0)); return(INTCONSTANT); }

{D}+{E}           { yylval->lex.f = static_cast<float>(atof_dot(yytext)); return(FLOATCONSTANT); }
{D}+"."{D}*({E})? { yylval->lex.f = static_cast<float>(atof_dot(yytext)); return(FLOATCONSTANT); }
"."{D}+({E})?     { yylval->lex.f = static_cast<float>(atof_dot(yytext)); return(FLOATCONSTANT); }

"+="            {  return(ADD_ASSIGN); }
"-="            {  return(SUB_ASSIGN); }
"*="            {  return(MUL_ASSIGN); }
"/="            {  return(DIV_ASSIGN); }
"%="            {  return(MOD_ASSIGN); }
"<<="           {  return(LEFT_ASSIGN); }
">>="           {  return(RIGHT_ASSIGN); }
"&="            {  return(AND_ASSIGN); }
"^="            {  return(XOR_ASSIGN); }
"|="            {  return(OR_ASSIGN); }

"++"            {  return(INC_OP); }
"--"            {  return(DEC_OP); }
"&&"            {  return(AND_OP); }
"||"            {  return(OR_OP); }
"^^"            {  return(XOR_OP); }
"<="            {  return(LE_OP); }
">="            {  return(GE_OP); }
"=="            {  return(EQ_OP); }
"!="            {  return(NE_OP); }
"<<"            {  return(LEFT_OP); }
">>"            {  return(RIGHT_OP); }
";"             { context->lexAfterType = false; return(SEMICOLON); }
("{"|"<%")      { context->lexAfterType = false; return(LEFT_BRACE); }
("}"|"%>")      { return(RIGHT_BRACE); }
","         { if (context->inTypeParen) context->lexAfterType = false; return(COMMA); }
":"         { return(COLON); }
"="         { context->lexAfterType = false; return(EQUAL); }
"("         { context->lexAfterType = false; context->inTypeParen = true; return(LEFT_PAREN); }
")"         { context->inTypeParen = false; return(RIGHT_PAREN); }
("["|"<:")      { return(LEFT_BRACKET); }
("]"|":>")      { return(RIGHT_BRACKET); }
"."         { BEGIN(FIELDS);  return(DOT); }
"!"         { return(BANG); }
"-"         { return(DASH); }
"~"         { return(TILDE); }
"+"         { return(PLUS); }
"*"         { return(STAR); }
"/"         { return(SLASH); }
"%"         { return(PERCENT); }
"<"         { return(LEFT_ANGLE); }
">"         { return(RIGHT_ANGLE); }
"|"         { return(VERTICAL_BAR); }
"^"         { return(CARET); }
"&"         { return(AMPERSAND); }
"?"         { return(QUESTION); }

<FIELDS>{L}({L}|{D})* { 
    BEGIN(INITIAL);
    yylval->lex.string = NewPoolTString(yytext); 
    return FIELD_SELECTION;
}
<FIELDS>[ \t\v\f\r] {}

[ \t\v\n\f\r]   {  }
<*><<EOF>>      { context->AfterEOF = true; yyterminate(); }
<*>.            { context->warning(yylineno, "Unknown char", yytext, ""); return 0; }

%%

yy_size_t string_input(char* buf, yy_size_t max_size, yyscan_t yyscanner) {
    pp::Token token;
    yyget_extra(yyscanner)->preprocessor.lex(&token);
    yy_size_t len = token.type == pp::Token::LAST ? 0 : token.text.size();
    if (len < max_size)
        memcpy(buf, token.text.c_str(), len);
    yyset_lineno(EncodeSourceLoc(token.location.file, token.location.line), yyscanner);

    if (len >= max_size)
        YY_FATAL_ERROR("Input buffer overflow");
    else if (len > 0)
        buf[len++] = ' ';
    return len;
}

int check_type(yyscan_t yyscanner) {
    struct yyguts_t* yyg = (struct yyguts_t*) yyscanner;
    
    int token = IDENTIFIER;
    TSymbol* symbol = yyextra->symbolTable.find(yytext);
    if (yyextra->lexAfterType == false && symbol && symbol->isVariable()) {
        TVariable* variable = static_cast<TVariable*>(symbol);
        if (variable->isUserType()) {
            yyextra->lexAfterType = true;
            token = TYPE_NAME;
        }
    }
    yylval->lex.symbol = symbol;
    return token;
}

int reserved_word(yyscan_t yyscanner) {
    struct yyguts_t* yyg = (struct yyguts_t*) yyscanner;

    yyextra->error(yylineno, "Illegal use of reserved word", yytext, "");
    yyextra->recover();
    return 0;
}

void yyerror(TParseContext* context, const char* reason) {
    struct yyguts_t* yyg = (struct yyguts_t*) context->scanner;

    if (context->AfterEOF) {
        context->error(yylineno, reason, "unexpected EOF");
    } else {
        context->error(yylineno, reason, yytext);
    }
    context->recover();
}

int glslang_initialize(TParseContext* context) {
    yyscan_t scanner = NULL;
    if (yylex_init_extra(context, &scanner))
        return 1;

    context->scanner = scanner;
    return 0;
}

int glslang_finalize(TParseContext* context) {
    yyscan_t scanner = context->scanner;
    if (scanner == NULL) return 0;
    
    context->scanner = NULL;
    yylex_destroy(scanner);

    return 0;
}

int glslang_scan(size_t count, const char* const string[], const int length[],
                 TParseContext* context) {
    yyrestart(NULL, context->scanner);
    yyset_lineno(EncodeSourceLoc(0, 1), context->scanner);
    context->AfterEOF = false;

    // Initialize preprocessor.
    if (!context->preprocessor.init(count, string, length))
        return 1;

    // Define extension macros.
    const TExtensionBehavior& extBehavior = context->extensionBehavior();
    for (TExtensionBehavior::const_iterator iter = extBehavior.begin();
         iter != extBehavior.end(); ++iter) {
        context->preprocessor.predefineMacro(iter->first.c_str(), 1);
    }
    return 0;
}

