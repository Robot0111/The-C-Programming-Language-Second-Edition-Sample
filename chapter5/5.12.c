#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME,PARENS,BRACKETS};

void dcl(void); 
void dirdcl(void);
int gettoken(void);
int tokentype;              /* 最后一个记号的类型 */
char token[MAXTOKEN];       /* 最后一个记号字符串 */
char name[MAXTOKEN];        /* 标识符名 */
char datatype[MAXTOKEN];    /* 数据类型为char、int 等 */
char out[1000];             /* 输出串 */
/* dcl 函数,对一个声明符进行语法分析 */

void dcl(void)
{
    int ns;
    for(ns = 0; gettoken() == '*';)
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out,"pointer to");
    
}

/* dirdcl函数:分析一个直接声明 */
void dirdcl(void)
{
    int type;

    if(tokentype != ')'){
        dcl();
        if (tokentype != ')')
            printf("error:missing )\n");
    } else if(tokentype == NAME)
        strcpy(name,token);
    else
        printf("error:expected name or (dcl)\n");
    while((type=gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out,"function returning");
        else {
            strcat(out,"array");
            strcat(out,token);
            strcat(out,"of");
        }
}

int main()
{
    while (gettoken() != EOF){
        strcpy(datatype,token);
        out[0] = '\0';
        dcl(); /* 分析该行的其余部分 */
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s:%s %s\n",name,out,datatype);
    }
    return 0;
}
/* 返回下一个标记 */
int gettoken(void)
{
    int c,getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
    ;
    if (c == '('){
        if((c = getch()) == ')'){
            strcpy(token,"()");
            return tokentype = PARENS;
        }else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '['){
        for( *p++ = c;(*p++ = getch()) != ']';)
        ;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}