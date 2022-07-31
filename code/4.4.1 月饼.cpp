#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake{
	double store;	//库存量
	double sell;	//总售价
	double price;	//单价 
} cake[1001];

bool cmp(const mooncake &a, const mooncake &b){
	return a.price > b.price;	//按单价从小到达排序 
}

int main()
{
	int n;	//月饼品种
	double D;	//需求量
	scanf("%d%lf", &n, &D);
	for(int i=0; i<n; ++i)
		scanf("%lf", &cake[i].store);
	for(int i=0; i<n; ++i){
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;	//计算单价 
	}
	
	sort(cake, cake+n, cmp);	//按单价从高到低排序 
	
	double ans = 0;	//收益
	for(int i=0; i<n; ++i){	
		if(cake[i].store <= D){	//如果需求量高于月饼库存量 
			D -= cake[i].store;	 //第i种月饼全部卖出 
			ans += cake[i].sell;
		}else{					//如果月饼库存量高于需求量 
			ans += cake[i].price * D;	//只卖出剩余需求量的月饼
			break; 
		}
	} 
	printf("%.2f\n", ans);
	return 0;
}
