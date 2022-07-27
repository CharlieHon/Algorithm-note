#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student{
	string id;	// 准考证 
	int score;	// 分数 
	int location_number;	// 考场号 
	int local_rank;	// 考场内排名
}stu[1000];

bool cmp(const Student &a, const Student &b){
	// 分数不同按照分数排名，相同则准考证小者靠前 
	if(a.score != b.score)	return a.score > b.score;
	else return a.id < b.id;
}

int main()
{
	int n, k, num=0;	//num为考生总数
	cin >> n;			//n为考场数
	for(int i=1; i<=n; ++i){
		cin >> k;		//k为该考场内人数
		for(int j=0; j<k; ++j){
			cin >> stu[num].id >> stu[num].score;
			stu[num].location_number = i;	//该考生的考场号为i
			++num;		//总考生数加1 
		}
		sort(stu + num -k, stu + num, cmp);	//将该考场的考生排序
		stu[num-k].local_rank = 1;			//该考场第1名的local_rank记为1
		for(int j=num-k+1; j<num; ++j){		//对该考场剩余的学生
			if(stu[j].score == stu[j-1].score){	//对考场剩余的考生 
				//local_rank也相同 
				stu[j].local_rank = stu[j-1].local_rank;	
			}else{
				//如果与前一位考生不同分，local_rank为该考生前的人数 
				stu[j].local_rank = j + 1 - (num - k);
			}
		} 
	}
	cout << num << endl;		//输出总考生数
	sort(stu, stu+num, cmp);	//将所有考生排序
	int r=1;
	for(int i=0; i<num; ++i){
		if(i > 0 && stu[i].score != stu[i-1].score){
			r = i + 1;			//当前考生与上一个考生分数不同时，让r更新为人数+1 
		}
		cout << stu[i].id << " ";
		cout << r << " " << stu[i].location_number << " " << stu[i].local_rank << endl;
	}
	return 0;
}
