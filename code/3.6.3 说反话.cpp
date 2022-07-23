#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[90];
	gets(str);
	int len = strlen(str), r=0, c=0;	//r为行，c为列
	char ans[90][90];	//ans[0]~ans[r]存放单词
	for(int i=0; i<len; ++i){
		if(str[i] != ' '){	//如果不是空格，则存放至ans[r][h]，并令++c
			ans[r][c++] = str[i];			
		}
		else{
			ans[r][c] = '\0';	//如果是空格，说明一个单词结束，行r增加1，列h恢复至0
			++r;
			c = 0;
		}
	}
	
	for(int i=r; i>=0; --i){	//倒着输出单词 
		printf("%s", ans[i]);
		if(i>0)	printf(" ");
	}
	
	return 0;
}
