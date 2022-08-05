#include <iostream>
using namespace std;

int target; 
int binarysearch(int *a, const int n){
	int left = 0, right = n-1, mid = (left + right) / 2;
	while(left <= right){
		if(a[mid] < target){
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else if(a[mid] > target){
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int a[] = {3,7,8,11,15,21,33,52,66,88};
	int size = sizeof(a) / sizeof(int);
	cin >> target;
	cout << binarysearch(a, size) << endl;
	return 0;
}
