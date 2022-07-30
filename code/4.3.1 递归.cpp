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
	for(int x=1; x<=n; ++x){	//ö��1~n����ͼ��x����p[index] 
		if(hashTable[x] == false){	//���x����p[0]~p[index-1]�� 
			p[index] = x;		//��p�ĵ�indexλΪx������x���뵱ǰ���� 
			hashTable[x] = true;//��x����p�� 
			generateP(index + 1);//���������еĵ�index+1��λ��һֱ�ݹ��p[index]=x������ȫ������ 
			hashTable[x] = false;//�Ѵ�����p[index]Ϊx�������⣬��ԭ״̬ 
		}
	}
}

int main()
{
	n = 3;	// �����1~3��ȫ����
	generateP(1); //��p[1]��ʼ�� 
	return 0;
}
