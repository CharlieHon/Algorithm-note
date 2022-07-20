#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> svec;
	string s;
	while(cin >> s){
		svec.push_back(s);
	}
	
	vector<string>::size_type size=svec.size();	//单词的个数 
	for(int i=size-1; i >=0; --i){
		cout << svec[i];
		if(i != 0)
			cout << " ";
	}
	return 0;
}
