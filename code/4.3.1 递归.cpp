#include <iostream>
using namespace std;

int F(int n){	//n! 
	if(n == 0)	return 1;	
	else		return F(n-1) * n;
}

int Fibo(int n){
	if(n == 1 || n == 0)	return 1;
	else					return Fibo(n-1) + Fibo(n-2);
}

const int maxn = 11;
int n, p[maxn];
bool hashTable[maxn] = {false};
void generateP(int index){
	if(index == n+1){
		for(int i=1; i<=n; ++i)
			cout << p[i] << " ";
		cout << endl;
		return ;
	}
	for(int x=1; x<=n; ++x){	//枚举1~n，试图将x填入p[index] 
		if(hashTable[x] == false){	//如果x不在p[0]~p[index-1]中 
			p[index] = x;		//令p的第index位为x，即把x加入当前排列 
			hashTable[x] = true;//记x已在p中 
			generateP(index + 1);//处理排列中的第index+1号位，一直递归把p[index]=x的排列全部包含 
			hashTable[x] = false;//已处理完p[index]为x的子问题，还原状态 
		}
	}
}

int main()
{
	n = 3;	// 欲输出1~3的全排列
	generateP(1); //从p[1]开始填 
	return 0;
}
