#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[90];
	gets(str);
	int len = strlen(str), r=0, c=0;	//rΪ�У�cΪ��
	char ans[90][90];	//ans[0]~ans[r]��ŵ���
	for(int i=0; i<len; ++i){
		if(str[i] != ' '){	//������ǿո�������ans[r][h]������++c
			ans[r][c++] = str[i];			
		}
		else{
			ans[r][c] = '\0';	//����ǿո�˵��һ�����ʽ�������r����1����h�ָ���0
			++r;
			c = 0;
		}
	}
	
	for(int i=r; i>=0; --i){	//����������� 
		printf("%s", ans[i]);
		if(i>0)	printf(" ");
	}
	
	return 0;
}
