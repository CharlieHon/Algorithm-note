#include <iostream>
#include <string> 
using namespace std;
int main()
{
	string s;
	bool flag = true;
	cin >> s;
	string::size_type size = s.length();
	for(int i=0; i <= size/2; ++i){
		if(s[i] != s[size-1-i]){
			flag = false;
			break;
		}
	}
	
	if(flag)	cout << "YES";
	else	cout << "NO";
	return 0;
}
