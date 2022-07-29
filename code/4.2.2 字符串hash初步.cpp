#include <iostream>
#include <string>
using namespace std;

int hashFunc(const string &s, const int len){
	int id = 0;
	for(int i=0; i<len; ++i)
		id = id * 26 + (s[i] - 'A');
	return id;
}

int hashTable[26 * 26 * 26 +10];

int main()
{
//	string s("BCD");
//	cout << hashFunc(s, 3);	//731
	int n, m;
	cout << "ÇëÊäÈëN¸ö×Ö·û´®£¬M¸ö²éÑ¯×Ö·û´®£º" << endl;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		int id = hashFunc(s, 3);
		++hashTable[id];
	}
	
	for(int j=0; j<m; ++j){
		string s2;
		cin >> s2;
		int id2 = hashFunc(s2, 3);
		cout << hashTable[id2] << endl;
	}
	return 0;
}
