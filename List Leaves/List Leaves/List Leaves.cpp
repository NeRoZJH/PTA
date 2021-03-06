// List Leaves.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>

#define Max 10
#define Null -1

struct Tree
{
	int section;
	int Left;
	int Right;

}T[Max],Ts[Max];


int BuildTree(int n);
void sequence(int n, int Root);
void ListLeaves(int n, int Root);
bool IsLeaf(int Root);

int main()
{
	int n;
	int Root;


	std::cin >> n;
	Root = BuildTree(n);

	sequence(n,Root);

	ListLeaves(n,Root);

	system("pause");
    return 0;
}

int BuildTree(int n)
{
	int check[Max] = { 0,0,0,0,0,0,0,0,0,0 };
	int Root;
	for (int i = 0; i < n; i++)
	{
		char tmp_l, tmp_r;
		std::cin >> tmp_l >> tmp_r;
		T[i].section = i;
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

void sequence(int n, int Root)
{
	int R = Root;
	std::queue <int> seq;
	seq.push(R);
	for (int i = 0; i < n; i++)
	{
		int a = seq.front();
		if (T[a].Left > -1)  
			seq.push(T[a].Left);
		if(T[a].Right > -1)
			seq.push(T[a].Right);
		Ts[i] = T[a];
		seq.pop();
		if (seq.empty())
			break;
	}
}

void ListLeaves(int n,int Root)
{
	int num = 0;
	int R = Root;
	std::vector<int> answer;
	for (int i = 0; i < n; i++)
	{
		if (IsLeaf(i))
		{
			answer.push_back(Ts[i].section);
			num++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i == num-1)
		{
			std::cout << answer.at(i);
		}else
			std::cout << answer.at(i)<<' ';
	}
}

bool IsLeaf(int Root)
{
	if (Ts[Root].Left == Null && Ts[Root].Right == Null)
		return true;
	else
		return false;
}
