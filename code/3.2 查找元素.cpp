#include <iostream>
using namespace std;
const int maxn = 200;
int a[maxn] = {0};
int main()
{
	int n, x, k;
	cin >> n;	//����n���� 
	for(int i=0; i<n; ++i){
		cin >> x;
		a[i] = x;
	}
	
	cin >> k;//����Ҫ���ҵ��� 
	int j; 
	for(j=0; j<n; ++j){
		if(a[j] == k){
			cout << j;
			break;
		}
	}
	
	//û�ҵ����±�j==n 
	if(j == n)
		cout << -1;
	return 0;
}
