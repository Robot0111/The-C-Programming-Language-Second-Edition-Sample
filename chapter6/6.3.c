#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key{
    char *word;
    int count;
}keytab[] = {
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "const",0,
    "continue",0,
    "default",0,
    "unsigned",0,
    "void",0,
    "volatile",0,
    "while",0
};
/* 结构数组 keytab[] 每个元素占用的字节数 是 (sizeof keytab[0]) 或者是 (sizeof (struct key)) 个字节数 这里是 16个字节 
所以 数组总数等于 下面的表达式*/
#define NKEYS (sizeof keytab / sizeof keytab[0])
int getword(char *,int);
int binsearch(char *,struct key *,int);

/* 统计输入中c语言关键字的出现次数 */

int main()
{
    int n;
    char word[MAXWORD];
    while (getword(word,MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((n = binsearch(word,keytab,NKEYS)) >= 0)
                keytab[n].count++;
    for(n = 0; n < NKEYS;n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n",keytab[n].count,keytab[n].word);
    return 0;
}

/* binsearch函数:在tab[0] 到tab[n-1]中查找单词 */
int binsearch(char *word,struct key tab[],int n)
{
    int cond;
    int low,high,mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word,tab[mid].word)) < 0)
            high = mid - 1;          //在前半部分查找
        else if (cond > 0)
            low = mid + 1;           //后半部分查找
        else
            return mid;             //找到单词
    }
    return -1;
}

int getword(char *word,int lim)
{
    int c,getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()));

    if(c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}