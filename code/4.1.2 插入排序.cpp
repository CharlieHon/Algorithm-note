#include <iostream>
using namespace std;

void InsertSort(int *a, const int n);

int main()
{
	int a[] = {4, 5, 6, 2, 3, 7, 8, 9, 0};
	int len = sizeof(a) / sizeof(int);
	InsertSort(a, len);
	for(size_t i=0; i != len; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

void InsertSort(int *a, const int n){
	int i, j;
	for(i=1; i<n; ++i){
		int tmp = a[i];
		j=i;
		while(j > 0 && a[j-1] > tmp){
			a[j] = a[j-1];
			--j;
		}
		a[j] = tmp;	//≤Â»ÎŒª÷√Œ™j 
	}
} 
