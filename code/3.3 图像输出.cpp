#include <iostream>
using namespace std;

int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int row = (n % 2) ? (n/2 + 1) : (n / 2);
	//第1行 
	for(int i=0; i<n; ++i)
		printf("%c", c);
	printf("\n");
	//第2~row-2行 
	for(int i=0; i<row-2; ++i){
		printf("%c", c);
		for(int j=0; j<n-2; ++j){
			printf(" ");
			if(j==n-2)
				printf("\n");
		}
		printf("%c\n", c);
	}
	//第row行 
	for(int i=0; i<n; ++i)
		printf("%c", c);
	return 0;
}
