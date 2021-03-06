// Complete Binary Search Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>

#define MAX 2000

using namespace std;


 typedef struct Tree
{
	int Data;
	int Left;
	int Right;

}*Tnode;

void BuildTree(int n, Tree T[]);
void Sort(int a[],int n);

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void preorder(int Root,Tnode T,int a[])
{
	
	if (Root != -1)
	{
		preorder(T[Root].Left, T, a);
		T[Root].Data = a;
		preorder(T[Root].Right, T, a);
	}
}

int main()
{
	int n;
	int a[MAX];

    cin >> n;

	Tnode ComTree = (Tnode)malloc(sizeof(struct Tree)*n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	Sort(a,n);

	BuildTree(n,ComTree);

	preorder(0, ComTree, a);


	system("pause");
    return 0;
}

void BuildTree(int n, Tree T[])
{
	for (int i = 0; i < n; i++)
	{
		if (2 * i + 2 < n)
		{
			T[i].Left = 2 * i + 1;
			T[i].Right = 2 * i + 2;
		}
		else if (2 * i + 1 < n)
		{
			T[i].Left = 2 * i + 1;
			T[i].Right = -1;
		}
		else if (2 * i + 1 >= n)
		{
			T[i].Left = -1;
			T[i].Right = -1;
		}
	}
	
}


void Sort(int a[],int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			if (a[j] > a[j + 1])
				Swap(a, j, j + 1);
		}
	}
}
