#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101;
struct interval{
	int x;	//开区间左右端点 
	int y;
} I[maxn];

bool cmp2(const interval &a, const interval &b){
	//如果x不同，按左端点从大到小排序；否则，按照右端点从小到大排序 
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
		// ans记录不相交区间个数，lastX记录上一个被选中区间的左端点
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
