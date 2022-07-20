#include <iostream>
using namespace std;
int main()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;
	int k[40], num=0;	//k[]存放d进制的每一位 
	do{//进制转换 
		k[num++] = sum % d;
		sum /= d;
	} while(sum != 0);
	
	for(int i=num-1; i>=0; --i){	//从高位到低位进行输出 
		printf("%d", k[i]);
	}
	return 0;
}
