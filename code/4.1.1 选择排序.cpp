#include <iostream>
using namespace std;
void SelectSort(int *a, const int n);
//—°‘Ò≈≈–Ú 
int main()
{
	int a[] = {16, 5, 6, 4, 2, 3, 1, 7, 9, 8};
	SelectSort(a, 10);
	for(int *p = a; p != a+10; ++p)
		cout << *p << " ";
	cout << endl;
	return 0;
}

void SelectSort(int *a, const int n)
{
	for(int i=0; i < n-1; ++i){
		int min = i;
		for(int j=i+1; j < n; ++j){
			if(a[j] < a[min])
				min = j;
		}
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}	
}
