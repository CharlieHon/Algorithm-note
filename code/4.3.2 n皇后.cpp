#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 10000;
int n, p[maxn];
bool hashTable[maxn] = {false}; 
int count = 0;
void generateN(int index){
	if(index == n+1){
		bool flag = true;
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				if(abs(j - i) == abs(p[i] - p[j]))
					flag = false;
			}
		}
		if(flag)	++count;
		return ;
	}
	for(int x=1; x<=n; ++x){
		if(hashTable[x] == false){
			p[index] = x;
			hashTable[x] = true;
			generateN(index+1);
			hashTable[x] = false;
			
		}
	}
	
}

int main()
{
	n = 8;
	generateN(1);
	cout << count << endl;	 
	return 0;
}
