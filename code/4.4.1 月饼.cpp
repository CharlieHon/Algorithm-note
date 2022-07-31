#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake{
	double store;	//�����
	double sell;	//���ۼ�
	double price;	//���� 
} cake[1001];

bool cmp(const mooncake &a, const mooncake &b){
	return a.price > b.price;	//�����۴�С�������� 
}

int main()
{
	int n;	//�±�Ʒ��
	double D;	//������
	scanf("%d%lf", &n, &D);
	for(int i=0; i<n; ++i)
		scanf("%lf", &cake[i].store);
	for(int i=0; i<n; ++i){
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;	//���㵥�� 
	}
	
	sort(cake, cake+n, cmp);	//�����۴Ӹߵ������� 
	
	double ans = 0;	//����
	for(int i=0; i<n; ++i){	
		if(cake[i].store <= D){	//��������������±������ 
			D -= cake[i].store;	 //��i���±�ȫ������ 
			ans += cake[i].sell;
		}else{					//����±���������������� 
			ans += cake[i].price * D;	//ֻ����ʣ�����������±�
			break; 
		}
	} 
	printf("%.2f\n", ans);
	return 0;
}
