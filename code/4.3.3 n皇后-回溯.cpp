#include <iostream>
#include <cmath>
using namespace std;

int count = 0;	//�����Ϸ�����
const int maxn = 10001;	//hash����󳤶�
int n, p[maxn];	//nΪ���̴�С��p[index]��ʾ�±�index�лʺ������к� 
bool hashTable[maxn] = {false};	//hash�� 
void generateN2(int index){
	if(index == n+1){	//�ݹ�߽磬����һ���Ϸ����� 
		++count;	//�ܵ��������һ���ǺϷ��� 
		return ;
	}
	for(int x=1; x<=n; ++x){
		if(hashTable[x] == false){
			bool flag = true;
			for(int pre=1; pre<index; ++pre){
				if(abs(pre-index) == abs(p[pre] - x)){
					flag = false;
					break;	
				}
			}
			if(flag){
				p[index] = x;
				hashTable[x] = true;
				generateN2(index+1);
				hashTable[x] = false;
			}
		}
	}
}

int main()
{
	n = 8;
	generateN2(1);
	cout << count << endl; 
	return 0;
}
