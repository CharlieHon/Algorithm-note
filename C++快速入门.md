#cpp #Algorithm 2022/7/19
## 2.8.1 结构体的定义
定义一个结构体的基本格式如下：
```cpp
struct Name{
	//一些基本的数据结构或者自定义的数据类型
};

struct studentInfo{
	int id;
	char gender; //'F' or 'M'
	char name[20];
	char mahor[20];
	
}Alice, Bob, stu[1000];

//结构体里面能定义除了自身之外的任何数据类型。
struct node{
	node n;//不能定义node型变量
	node *next;//可以定义node*型指针变量
};
```
## 2.8.2 访问结构体内的元素
- 有两种方法：
	- `"."`操作和`"->"`操作
```cpp
struct studentInof{
	int id;
	char name[20];
	studengtInof* next; //用来指向下一个学生的地址
}stu, *p;

//访问stu中变量的写法如下
stu.id
stu.name
stu.next
//访问指针变量p中元素的写法
(*p).id
p->name//完全等价
p->next
```
## 2.8.3 结构体的初始化
- 可以先定义一个studentInfostu的结构以变量，然后对其中的元素逐一赋值，以达到初始化的目的
```cpp
stu.id = 1;
stu.gender = 'M';
printf("%d %c", &stu.id, &stu.gender);
```
- **构造函数**：用来初始化结构体的一种函数，直接定义在结构体中。
- 构造函数**不需要写返回类型，且函数名与结构体名相同**。
- 对一个普通定义的结构体，其内部会生成一个默认的构造函数(但不可见)。
- 可以看到这个构造函数与结构体类型名相同；它没有返回类型，所以studentInfo前面没有写东西；眉头参数，所以小括号内是空的；也没有函数体，因此花括号内也是空的。由于这个构造函数的存在，才可以直接定义studengtInfo类型的变量而不进行初始化。
```cpp
struct studengtInof{
	int id;
	char gender;
	//默认生成的构造函数
	studengtInfo(){}
}

struct studengtInfo{
	int id;
	char gender;
	studengtInfo(int _id, char _gender){
		//赋值
		id = _id;
		gender = _gender;
	}
};

//构造函数可以简化成一行
struct studengtInfo{
	int id;
	char gender;
	studengtInfo(int _id, char _gender) : id(_id), gender(_gender) {}
};
studengtInfo stu = stundengtInfo(10086, 'M');
```
- 注意：如果自己重新定义了构造函数，则不能不经过初始化就定义结构体变量
- 只要参数个数和类型不完全相同，就可以定义任意多个构造函数，以适应不同的初始化场合
```cpp
struct studengtInfo{
	int id;
	char gender;
	//用以不初始化就定义结构体变量
	studengtInfo(){}
	//只初始化gender
	studengtInfo(char _gender){
		gender = _gender;
	}
	//同时初始化id和gender
	studengtInfo(int _id, char _gender){
		id = _id;
		gender = _gender;
	}
};
```
- 下面是一个应用实例，其中结构体Point用于存放平面点的坐标x, y
```cpp
#include <iostream>
using namespace std;
struct Point{
	int x, y;
	Point() {}	//用以不经初始化定义
	Point(int _x, int _y) : x(_x), y(_y) {}	//用以提供x和y的初始化 
}pt[10];

int main()
{
	int num=0;
	for(int i=0; i<=3; ++i){
		for(int j=1; j<=3; ++j){
			pt[num++] = Point(i, j);	//直接使用构造函数 
		}
	}
	
	for(int i=0; i<num; ++i)
		printf("%d,%d\n", pt[i].x, pt[i].y);
	
	//0,1 0,2, 0,3 1.1, ..., 3,3
	return 0;
}
```
2022/7/20
### cin与cout
- cin与cout是C++中的输入与输出函数，需要添加头文件`#include<iostream>`和`using namespace std;`才能使用。不需指定输入格式，也不需要使用取地址运算符`&`，可以直接输入/输出。
## 2.9.2 浮点数的比较
由于计算机中采用有限位的二进制编码，因此浮点数在计算机中的存储并不总是精确的。需要引入一个极小数eps来对这种误差进行修正
1. 等于运算符(`==`)
如果一个数落在了[b-eps, b+eps]的区间中时，就应当判断为`a==b`成立。经验表明，eps取10^-8是一个合适的数字
```cpp
const double eps = 1e-8;
#define Equ(a, b) ((abs((a)-(b)))<(eps))
```
2. 圆周率Π
因为由于`cos(Π) = -1`可知`Π = arcos(-1)`。
```cpp
const double Pi=acos(-1.0);
```
## 2.9.3 复杂度
一般来说，复杂度可以分为时间复杂度和空间复杂度，有时还会提到编码复杂度。
1. 时间复杂度
时间复杂度是算法需要执行基本运算的次数所处的等级，其中基本运算就是类似加减乘除这种计算机可以直接实现的运算。时间复杂度是评判算法的时间效率的有效标准。
- 高等级的幂次会覆盖低等级的幂次，因此`O(3n^2+n+2)=O(3n^2)=O(n^2)=O(cn^2)`，其中c是一个常数，称为算法时间复杂度的常数，当有些算法实现较为复杂时，其常数会比较大
- 二分查找的时间复杂度就是`O(logn)`，表示对数的时间复杂度(一般省略底数)
- 常数复杂度`O(1)`表示算法消耗的时间不随规模的增长而增长。
- 显然有`O(1)<O(logn)<O(n)<O(n^2)`成立
2. 空间复杂度
空间复杂度采用与时间复杂度相同的写法，表示算法需要消耗的最大数据空间。
- 对于某个算法，如果其消耗的最大数据空间是一个二位数组，那么算法的空间复杂度就是`O(n^2)`
- 一般来说只要不开好几个`10^7`以上的数组即可。
- `O(1)`的空间复杂度是指算法消耗的空间不随数据规模的增大而增大
- 考虑空间一般够用，因此常采用以空间换时间的策略。
3. 编码复杂度
是一个定性的概念，没有量化的标准。对于一个问题来说，如果使用了冗长的算法思想，那么代码量将会非常巨大，其编码复杂度就会非常大。
## 2.10 黑盒测试
- 单点测试：系统会判断每组数据的输出结果是否正确。如果正确，那么对该组数据来说就通过了测试，并获得了这组数据的分值。
- 多点测试：程序一次运行所有数据，并要求所有数据输出结果都必须完全正确，才能算作通过。

题目的3种输入格式：
1. while...EOF型
如果题目没有给定输入的结束条件，那么就默认读取到文件末尾。
`scanf`函数的返回值为其成功读入的参数的个数。一般只有在读取文件到达文件末尾导致无法读取现象，才会产生读入失败。此时，scanf函数会返回-1而不是0，在C语言种使用EOF(即End Of File)来代表-1.
- 利用scanf的返回值是否为EOF来判断输入是否结束
- 在命令行中手动触发EOF，按`Ctrl+Z`会显示一个`^Z`，再按`Enter`键就可以结束while了。
```cpp
while(scanf("%d", &n) != EOF){
	...
}
```
2. while...break型
题目要求当输入的数据满足某个条件时停止输入。如输入都为0时结束
```cpp
#include <iostream>
int main()
{
	int a, b;
	//1.在while...EOF的内部进行判断，当满足推出条件时终端(break)当前while循环
	while(scanf("%d%d", &a, &b)){
		if(a==0 && b==0)
			break;
		printf("%d\n", a+b);
	}
	
	//2.把推出条件的判断放在while语句中，令其与scanf用逗号隔开
	while(scanf("%d%d", &a, &b), a||b)
		printf("%d\n", a+b);
	return 0;
}
```
3. while(T--)型
题目给出测试数据的组数，然后才给出相应数量组数的输入数据。用一个变量T来存储，并在程序开始时读入。`while(T--)`就是循环执行T次的含义
```cpp
#include <iostream>
int main()
{
	int T, a, b;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
}
```