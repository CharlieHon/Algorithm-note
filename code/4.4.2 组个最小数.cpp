#include <iostream>

using namespace std;

int main()
{
	int count[10];			//��¼����0~9�ĸ��� 
	for(int i=0; i<10; ++i)	
		scanf("%d", &count[i]);
	for(int i=1; i<10; ++i){
		if(count[i] > 0){	//��1~9��ѡ��count��Ϊ0����С������ 
			printf("%d", i);
			--count[i];
			break;			//�ҵ�һ��֮����ж� 
		}
	}
	for(int i=0; i<10; ++i){	//��0~9�����Ӧ���������� 
		while(count[i] > 0){
			printf("%d", i);
			--count[i];
		}
	}
	return 0;
}
