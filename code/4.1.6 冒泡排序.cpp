#include <iostream>
using namespace std;
void BubbleSort(int *a, const int n){
	for(int i=n-1; i>0; --i){	//每次找到当前最大值值，需要进行n-1次排序 
		for(int j=0; j<i; ++j){	//未排序部分 
			if(a[j] > a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

void print(int *p, const int n){
	for(int i=0; i<n; ++i)
		cout << p[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = {1,5,6,8,9,1,2,34,20};
	int n = sizeof(a) / sizeof(int);
	print(a, n);
	BubbleSort(a, n);
	print(a, n);
	return 0;
}
