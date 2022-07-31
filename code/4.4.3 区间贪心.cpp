#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101;
struct interval{
	int x;	//���������Ҷ˵� 
	int y;
} I[maxn];

bool cmp2(const interval &a, const interval &b){
	//���x��ͬ������˵�Ӵ�С���򣻷��򣬰����Ҷ˵��С�������� 
	return (a.x != b.x) ? (a.x > b.x) : (a.y < b.y);
}

int main()
{
	int n;
	while(scanf("%d", &n), n != 0){
		for(int i=0; i<n; ++i){
			scanf("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I+n, cmp2);
		// ans��¼���ཻ���������lastX��¼��һ����ѡ���������˵�
		int ans = 1, lastX = I[0].x;
		for(int i=1; i<n; ++i){
			if(I[i].y <= lastX){
				lastX = I[i].x;
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
