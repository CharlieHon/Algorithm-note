#include <iostream>
using namespace std;
int main()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;
	int k[40], num=0;	//k[]���d���Ƶ�ÿһλ 
	do{//����ת�� 
		k[num++] = sum % d;
		sum /= d;
	} while(sum != 0);
	
	for(int i=num-1; i>=0; --i){	//�Ӹ�λ����λ������� 
		printf("%d", k[i]);
	}
	return 0;
}
