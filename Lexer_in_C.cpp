// Lexer_in_C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tape_t.h"
#include "string_t.h"
#include "Lexer.h"


void debug_lex(int token)
{
	switch (token)
	{
       
        case '=':
        printf("=\n");
        break;
    case '+':
        printf("+\n");
        break;
    case '-':
        printf("-\n");
        break;
    case '*':
        printf("*\n");
        break;
    case '/':
        printf("/\n");
        break;
    case '%':
        printf("%\n");
        break;
    case '^':
        printf("^\n");
        break;
    case '~':
        printf("~\n");
        break;
    case '&':
        printf("&\n");
        break;
    case '!':
        printf("!\n");
        break;
    case '(':
        printf("(\n");
     break;
    case ')':
        printf(")\n");
        break;
    case '{':
        printf("{\n");
        break;
    case '}':
        printf("}\n");
        break;
    case '[':
        printf("[\n");
        break;
    case ']':
        printf("]\n");
    case '\'':
        printf("\'\n");
        break;
    case '"':
        printf("\"\n");
        break;
    case ';':
        printf(";\n");
        break;
	case ELIPPSIS:
		printf("ELIPPSIS\n");
		break;
	case ADD_ASSIGN:
		printf("ADD_ASSIGN\n");
		break;
	case INC_OP:
		printf("INC_OP\n");
		break;
	case SUB_ASSIGN:
		printf("SUB_ASSIGN\n");
		break;
	case DEC_OP:
		printf("DEC_OP\n");
		break;
	case DIV_ASSIGN:
		printf("DIV_ASSIGN\n");
		break;
	case MUL_ASSIGN:
		printf("MUL_ASSIGN\n");
		break;
	case MOD_ASSIGN:
		printf("MOD_ASSIGN\n");
		break;
	case AND_ASSIGN:
		printf("AND_ASSIGN\n");
		break;
	case XOR_ASSIGN:
		printf("XOR_ASSIGN\n");
		break;
	case OR_ASSIGN:
		printf("OR_ASSIGN\n");
		break;
	case NOT_ASSIGN:
		printf("NOT_ASSIGN\n");
		break;
	case RIGHT_OP:
		printf("RIGHT_OP\n");
		break;
	case LEFT_OP:
		printf("LEFT_OP\n");
		break;
	case EQ_EQ_COND:
		printf("EQ_EQ_COND\n");
		break;
	case ID:
		printf("ID\n");
		break;
	case STROBJ:
		printf("STROBJ\n");
		break;
	case INT_CONST:
		printf("INT_CONST\n");
		break;
	case F_CONST:
		printf("F_CONST\n");
		break;
	case ERR:
		printf("ERR\n");
		break;
	case NOT_FOUND:
		printf("NOT_FOUND\n");
		break;
		/* Keyword token */
	case AUTO:
		printf("AUTO\n");
		break;
	case BREAK:
		printf("BREAK\n");
		break;
	case CASE:
		printf("CASE\n");
		break;
	case CHAR:
		printf("CHAR\n");
		break;
	case CONST:
		printf("CONST\n");
		break;
	case CONTINUE:
		printf("CONTINUE\n");
		break;
	case DEFAULT:
		printf("DEFAULT\n");
		break;
	case DO:
		printf("DO\n");
		break;
	case DOUBLE:
		printf("DOUBLE\n");
		break;
	case ELSE:
		printf("ELSE\n");
		break;
	case ENUM:
		printf("ENUM\n");
		break;
	case EXTERN:
		printf("EXTERN\n");
		break;
	case FLOAT:
		printf("FLOAT\n");
		break;
	case FOR:
		printf("FOR\n");
		break;
	case GOTO:
		printf("GOTO\n");
		break;
	case IF:
		printf("IF\n");
		break;
	case INT:
		printf("INT\n");
		break;
	case LONG:
		printf("LONG\n");
		break;
	case REGISTER:
		printf("REGISTER\n");
		break;
	case RETURN:
		printf("RETURN\n");
		break;
	case SHORT:
		printf("SHORT\n");
		break;
	case SIGNED:
		printf("SIGNED\n");
		break;
	case SIZEOF:
		printf("SIZEOF\n");
		break;
	case STATIC:
		printf("STATIC\n");
		break;
	case STRUCT:
		printf("STRUCT\n");
		break;
	case SWITCH:
		printf("SWITCH\n");
		break;
	case TYPEDEF:
		printf("TYPEDEF\n");
		break;
	case UNION:
		printf("UNION\n");
		break;
	case UNSIGNED:
		printf("UNSIGNED\n");
		break;
	case VOID:
		printf("VOID\n");
		break;
	case VOLATILE:
		printf("VOLATILE\n");
		break;
	case WHILE:
		printf("WHILE\n");
		break;

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	char *tape = {};
	int t = 0;
	tape = (char*)calloc(1, sizeof(char));
	tape_read("C:\\comp\\stmt.c", &tape);
    int file_length;
	string_t str = string_file(tape,&file_length);
	int i = 0;
	string_t meta = string("\0");
        //  printf("entire file length is :%d\n", file_length);
    	
    for (i = 0; t != EOF;)
	{
		printf("Returned token is:%d\n", t = getTokenByPos(str, &i, meta));
		debug_lex(t);	
	}
	return 0;
}

