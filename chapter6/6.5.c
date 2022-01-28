#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnoden*right;
};


#define MAXWORD 100
struct tnode *addtrue(struct tnode *,char *);
void treeprint(struct tnode *);
int getword(char *,int);

/* 单词出现斌率的统计 */

main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word,MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root,word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup(char *);

/* addtree函数:在p 的位置或p的下方增加一个w节点 */

struct tnode *addtree(struct tnode *p,char *w)
{
    int cond;

    if(p == NULL) { /* 该单词是一个新单词 */
        p = talloc();/* 创建一个新节点 */
        p -> word = strdup(w);
        p -> count = 1;
        p-> left = p->right = NULL;
    } else if ((cond = strcmp(w,p->word)) == 0)
        p->count++;         /* 新单词与节点中的单词匹配 */
    else if (cond < 0)      /* 如果小于该节点中的单词,则进入左子树 */
        p->left = addtree(p->left,w);
    else                    /* 如果大于该节点中的单词,则进入右子树 */
        p->right = addtree(p->right,w);
    return p;
}

/* treeprint函数:按序打印树p */
void treeprint(struct tnode *p)
{
    if (p != NULL){
        treeprint(p -> left);
        printf("%4d %s\n",p->count ,p ->word);
        treeprint(p -> right);
    }
}

/* talloc 函数:创建一个tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
};

char *strdup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p,s);
    return p;
}