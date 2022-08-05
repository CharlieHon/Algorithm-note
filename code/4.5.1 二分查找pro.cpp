#include <iostream>
using namespace std;
//二分区间为左闭右闭[left, right]，传入的初始值为[0, n-1] 
int BinarySearch(int *a, int left, int right, int target){
	int mid;	//mid为left和right的中点 
	while(left <= right){	//如果left>right就没办法形成闭区间了 
		mid = (left + right) / 2;	//取中点 
		if(a[mid] == target)	return mid;	//找到x，返回下标 
		else if(a[mid] < target){	//中间的数小于 x 
			left = mid + 1;			//往右子区间[mid+1, right]查找 
		}
		else if(a[mid] > target){	//中间的数大于x 
			right = mid - 1;		//往左子区间[left, mid-1]查找 
		}
	}
	return -1; //查找失败，返回-1 
}

int main()
{
	int a[] = {1,5,6,15,26,34,38,50,61,82,88,96,102};
	int size = sizeof(a) / sizeof(int);
	int target;
	cout << "请输入要查找的数：";
	cin >> target;
	cout << BinarySearch(a, 0, size-1, target);
	return 0;
}
