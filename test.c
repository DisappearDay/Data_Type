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
