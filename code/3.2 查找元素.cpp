#include <iostream>
using namespace std;
const int maxn = 200;
int a[maxn] = {0};
int main()
{
	int n, x, k;
	cin >> n;	//输入n个数 
	for(int i=0; i<n; ++i){
		cin >> x;
		a[i] = x;
	}
	
	cin >> k;//输入要查找的数 
	int j; 
	for(j=0; j<n; ++j){
		if(a[j] == k){
			cout << j;
			break;
		}
	}
	
	//没找到则下标j==n 
	if(j == n)
		cout << -1;
	return 0;
}
