#include <iostream>
#include <cmath>
using namespace std;

int count = 0;	//计数合法方案
const int maxn = 10001;	//hash表最大长度
int n, p[maxn];	//n为棋盘大小，p[index]表示下标index列皇后所在行号 
bool hashTable[maxn] = {false};	//hash表 
void generateN2(int index){
	if(index == n+1){	//递归边界，生成一个合法方案 
		++count;	//能到达这里的一定是合法的 
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
