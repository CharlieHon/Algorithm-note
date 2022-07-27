#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(const int &a, const int &b)
{
	return a > b;	//�������Ϊ�� a > b ʱ��a����bǰ�� 
}

struct score{
	int x, y;
}ssd[4];

bool cmp(score &a, score &b){
	//���x��ȣ�����y��С�������򣬷�����x�Ӵ�С���� 
	if(a.x != b.x)	return a.x > b.x;
	else			return a.y < b.y;
}

bool cmp2(const string &s1, const string &s2){
	return s1.size() < s2.size();
}

int main()
{
	int a[] = {45, 21, 5, 8, 10, 6, 4, 3, 9, 47};
	int size = sizeof(a) / sizeof(int);
	for(int i=0; i != size; ++i)
		cout << a[i] << " ";
	cout << endl;
	
	sort(a, a+size);
	for(int *p=a; p != a+size; ++p)
		cout << *p << " ";
	cout << endl;
	
	sort(a, a+size, compare);
	for(int *p=a; p != a+size; ++p)
		cout << *p << " ";
	cout << endl;
	
	// �ṹ������ 
	ssd[0].x = 2;	//{2, 2}
	ssd[0].y = 2;
	ssd[1].x = 1;	//{1, 3}
	ssd[1].y = 3;
	ssd[2].x = 3;	//{3, 1}
	ssd[2].y = 1;
	ssd[3].x = 2;	//{2, 3}
	ssd[3].y = 3;
	
	sort(ssd, ssd+4, cmp);
	for(int i=0; i<4; ++i){
		cout << ssd[i].x << " " << ssd[i].y << endl;
	}
	//returns {3, 1} {2, 2}, {2, 3} {1, 3}
	
	//vector��������
	vector<int> ivec;
	ivec.push_back(3);
	ivec.push_back(1);
	ivec.push_back(2);
	sort(ivec.begin(), ivec.end(), compare);
	for(int i=0; i<3; ++i)
		cout << ivec[i] << " ";
	cout << endl;	// 3 2 1
	
	//string����
	string str[3] = {"bbb", "cc", "aaa"};
	sort(str, str+3);	//��string�����鰴�ֵ����С�������
	for(int i=0; i<3; ++i)
		cout << str[i] << " ";
	cout << endl;		// aaa bbb cc
	
	//���ַ������ȴ�С��������
	sort(str, str+3, cmp2);
	for(int i=0; i<3; ++i)
		cout << str[i] << " ";
	cout << endl;		// cc aaa bbb
	return 0;
}
