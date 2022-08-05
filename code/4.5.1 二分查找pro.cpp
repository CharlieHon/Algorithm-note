#include <iostream>
using namespace std;
//��������Ϊ����ұ�[left, right]������ĳ�ʼֵΪ[0, n-1] 
int BinarySearch(int *a, int left, int right, int target){
	int mid;	//midΪleft��right���е� 
	while(left <= right){	//���left>right��û�취�γɱ������� 
		mid = (left + right) / 2;	//ȡ�е� 
		if(a[mid] == target)	return mid;	//�ҵ�x�������±� 
		else if(a[mid] < target){	//�м����С�� x 
			left = mid + 1;			//����������[mid+1, right]���� 
		}
		else if(a[mid] > target){	//�м��������x 
			right = mid - 1;		//����������[left, mid-1]���� 
		}
	}
	return -1; //����ʧ�ܣ�����-1 
}

int main()
{
	int a[] = {1,5,6,15,26,34,38,50,61,82,88,96,102};
	int size = sizeof(a) / sizeof(int);
	int target;
	cout << "������Ҫ���ҵ�����";
	cin >> target;
	cout << BinarySearch(a, 0, size-1, target);
	return 0;
}
