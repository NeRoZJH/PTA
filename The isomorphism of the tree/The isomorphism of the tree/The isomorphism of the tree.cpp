// The isomorphism of the tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

#define Max 10
#define Null -1

struct Tree
{
	char Data;
	int Left;
	int Right;

}T1[Max],T2[Max];


int BuildTree(int n,Tree (&T)[Max]);
bool Isomorphism(int R1, int R2);

int main()
{
	int n1, n2;
	int Root1, Root2;

	
	std::cin >> n1;
	Root1 = BuildTree(n1,T1);

	std::cin >> n2;
	Root2 = BuildTree(n2,T2);

	std::cout << (Isomorphism(Root1, Root2) ? "Yes" : "No");
	system("pause");

    return 0;
}

int BuildTree(int n,Tree (&T)[Max])
{
	int check[Max] = {0,0,0,0,0,0,0,0,0,0};
	int Root;
	for (int i = 0; i < n; i++)
	{
		char tmp_l, tmp_r;
		std::cin >> T[i].Data >> tmp_l >> tmp_r;
		if (tmp_l == '-')
			T[i].Left = Null;
		else
		{
			T[i].Left = tmp_l - '0';
			check[T[i].Left] = 1;
		}
		if (tmp_r == '-')
			T[i].Right = Null;
		else
		{
			T[i].Right = tmp_r - '0';
			check[T[i].Right] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			Root = i;
			break;
		}
	}
	
	return Root;
}

bool Isomorphism(int R1, int R2)
{
	if (R1 == Null && R2 == Null)  //两树节点的Data皆为空
		return true;
	if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null)) // 一个节点为空 一个不为空
		return false;
	if (T1[R1].Data != T2[R2].Data)  //两个节点的Data不相同
		return false;
	else
		return (Isomorphism(T1[R1].Left, T2[R2].Right) && Isomorphism(T1[R1].Right, T2[R2].Left)) ||
		(Isomorphism(T1[R1].Left, T2[R2].Left) && Isomorphism(T1[R1].Right, T2[R2].Right));
	return false;
}
