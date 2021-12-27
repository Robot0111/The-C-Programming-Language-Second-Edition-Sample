#include <ctype.h>
#include <stdio.h>
#include <string.h>
int atoi(char s[])
{
	int i,n,sign;
	for(i = 0; isspace(s[i]); i++);
	sign = (s[i] =='-') ? -1:1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

/* shellsort 函数:按递增顺序对v[0]...v[n-1] 进行排序*/

void shellsort(int v[],int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2){//控制两个被比较元素之间的距离
		if(gap == 2||gap == 5|| gap == 1){
			for(int k = 0; k < 17; k++)
			printf("%d%s",v[k],",");
		};
		printf("gap value's:%d\n",gap);
		for (i = gap; i < n; i++)//元素间移动位置
			for (j = i-gap; j>=0&& v[j]>v[j+gap];j-=gap){//用于比较各对相距gap个位置的元素,当这两个逆序时把他们互换过来。
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
	}
}

/* reverse 函数：倒置字符串s中各个字符的位置*/
void reverse(char s[]){
	int c,i,j;
	for(i = 0,j = strlen(s)-1; i < j; i++,j--)
	c = s[i],s[i] = s[j], s[j] = c;
}

/* itoa 函数：将数字n转换为字符串并保存到s中*/
void itoa(int n,char s[])
{
	int i,sign;

	if((sign = n) < 0)
	n = -n;
	i = 0;

	do {
		s[i++] = n % 10 +'0';
	}while ((n /=10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
		reverse(s);
	for(int i = 0; i < 10; i++)
		printf("%c",s[i]);
}
//void shellsort(int v[],int n);
int main(){
	int interger = 12345;
	char s[10];
	itoa(interger,s);
}