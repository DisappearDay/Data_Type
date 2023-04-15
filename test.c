#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//声明一个结构体类型
struct Stu   //结构体标签
{
	//声明结构体变量(成员变量)
	char name[20];
	char tele[15];
	char sex[10];
	int age;
}s3,s4,s5; //都是全局变量--可以一次创建多个

struct	Stu s;//全局变量

struct
{
	char name[20];
	int age;
}sa;//只能在这创建

struct
{
	char name[20];
	int age;
}* psa;

typedef struct Node //如果用typedef重定义匿名函数，则不能实现自引用
{
	int data;
	struct Node* next;
}Node;


struct T
{
	double weight;
	short age;
};

struct S
{
	char c;
	struct T st;
	int a;
	double d;
	char arr[20];
};

struct R1
{
	char c1;
	int a;
	char c2;
};
struct R2
{
	char c1;

	char c2;
	int a;
};

int main() {
	//创建结构体变量---局部变量
	struct	Stu s1;
	struct	Stu s2;
	psa = &sa;
	//初始化
	//struct S n = { 'a',10,1.2,"hello" };
	struct S n = { 'a',{10.2,20},10,1.2,"hello" };
	//printf("%c %lf %d %d %lf %s", n.c, n.st.weight, n.st.age, n.a, n.d, n.arr);

	//结构体内存对齐
	struct R1 r1 = { 0 };

	printf("%d\n", sizeof(r1));
	struct R2 r2 = { 0 };
	printf("%d\n",sizeof(r2));
	return 0;
}
struct Stu1 {
	char name;
	int age;
	char tele;
};
struct Stu2 {
	char name;
	char tele;
	int age;
};
struct Stu3 {
	double name;
	char tele;
	int age;
};
struct Stu4 {
	char a;
	struct Stu3 s3;
	double b;
};
//int main() {
//	struct Stu1 s1 = { 0 };
//	struct Stu2 s2 = { 0 };
//	struct Stu3 s3 = { 0 };
//	struct Stu4 s4 = { 0 };
//
//	printf("%d\n", sizeof(s1));//12
//	printf("%d\n", sizeof(s2));//8
//	printf("%d\n", sizeof(s3));//16
//	printf("%d\n", sizeof(s4));//32
//
//	return 0;
//}
// 
// 
// 
//#pragma pack(4)//设置默认对齐数为4
//struct S
//{
//	char c1;
//	double d;
//};
//#pragma pack()//取消设置默认对齐数
//
//int main() {
//	struct S s;
//	printf("%d\n", sizeof(s));
//	return 0;
//}

struct S {
	char name;
	int age;
	double d;
};
#include<stddef.h>
int main() {

	//offsetof();
	printf("%d\n", offsetof(struct S, name));
	printf("%d\n", offsetof(struct S, age));
	printf("%d\n", offsetof(struct S, d));

	return 0;
}
struct R
{
	int a;
	char c;
	double b;
};

void init(struct R* str) {
	str->a = 100;
	str->b = 1.2;
	str->c = 'a';
}

void print1(struct R tmp) {
	printf("%d\n%c\n%lf\n",tmp.a,tmp.c,tmp.b);
}
void print2(const struct R* p) {
	printf("%d\n%lf\n%c\n", p->a, p->b, p->c);
}

int main() {
	struct R r={0};
	init(&r);
	print1(r);
	print2(&r);
	/*r.a=100;
	r.b=1.2;
	r.c='a';*/
	printf("%d\n", r.a);
	return 0;
}

struct Q {
	int a : 2;//数字是bit位，指的是a占用两个bit位  一个字节8个bit位
	int b : 5;
	int c : 10;
	int d : 30;
};

struct W {
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};


int main() {

	//struct Q s;
	//printf("%d\n",sizeof(s));

	struct W w={0};
	w.a = 10;
	w.b = 20;
	w.c = 3;
	w.d = 4;
	printf("%d,%d,%d,%d", w.a, w.b, w.c, w.d);

	return 0;
}
enum Sex {  //是一种类型
	//枚举的可能取值---常量
	male=2,//male=2是给它赋一个初始值   默认的初始值是0
    female,//当male=2时，female就是3
	secret//4
};


int main() {

	enum Sex s = male;//只能取枚举内定义的值
	printf("%d %d %d",male,female,secret);
	return 0;
}
