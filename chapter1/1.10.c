#include <stdio.h>

#define MAXLINE 1000



int getline(void);
void copy(void);

int main()
{
	int len;
	extern int max;
	extern char longest[];
	
	max = 0;
	while ((len = getline()) > 0)
		if(len > max) {
			max = len;
			copy();
		}
	if (max > 0){
		//for(int j =0; j < MAXLINE -1; j++)
		printf("%s",longest);
	}
	return 0;
}

int getline(void)
{
	int c,i;
extern char line[MAXLINE];
	
	for ( i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n'){
		line[i] = c;
		++i;
	}
	line[i]='\0';
	return i;
}
void copy(void)
{
	int i;
	extern char line[],longest[];
	
	i = 0;
	while (( longest[i] = line[i]) != '\0')
		++i;
}
int max;
char line[MAXLINE];
char longest[MAXLINE];