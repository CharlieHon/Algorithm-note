#include <iostream>
using namespace std;

const int maxn = 100010;
int a[maxn] = {0};

int main()
{
	int n, schID, score;
	cin >> n;
	
	for(int i=0; i<n; ++i){
		cin >> schID >> score;
		a[schID] += score;
	}
	
	int k=1, MAX = -1;
	for(int i=1; i<=n; ++i){
		if(a[i] > MAX){
			k = i;
			MAX = a[i];
		}
	}
	
	cout << k << " " << a[k] << endl;
	return 0;
}
