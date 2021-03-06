// Reversing Linked List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

#define MAXSIZE 100001

struct Node
{
	int Address;
	int Data;
	int NextAddr;
}PNode[MAXSIZE];


void ListInput(int Add, int n);//输入链表并进行排序
void listReverse(int k,int n);//链表反转
void printList(int n);

int main()
{
	int n, HeadAddress, k;//n为链表总长度，k为翻转个数，HeadAddress为链表头指针地址。

	cin >> HeadAddress >> n >> k;

	ListInput(HeadAddress, n);

	listReverse(k,n);

	printList(n);

	system("pause");
    return 0;
}

void ListInput(int Add,int n)
{
	for (int i = 1; i <=n; i++)
	{
		cin >> PNode[i].Address >> PNode[i].Data >> PNode[i].NextAddr;
		if (PNode[i].Address == Add)
		{
			PNode[0] = PNode[i];
			PNode[i] = PNode[1];
			PNode[1] = PNode[0];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = i + 1; k <= n; k++)
		{
			if (PNode[k].Address == PNode[i].NextAddr)
			{
				PNode[0] = PNode[k];
				PNode[k] = PNode[i+1];
				PNode[i+1] = PNode[0];
			}
		}
	}
}

void listReverse(int k,int n)
{
	int m = n / k;

	
	for (int i = 0; i < m; i++)
	{
		for (int a = 1; a <= k/2; a++)
		{
			PNode[0] = PNode[k * i + a];
			PNode[k * i + a] = PNode[k * i + k - a + 1];
			PNode[k * i + k - a + 1] = PNode[0];
		}
	}

	for (int i = 1; i < n; i++)
	{
		PNode[i].NextAddr = PNode[i + 1].Address;
	}
	PNode[n].NextAddr = -1;
}

void printList(int n)
{
	for (int i = 1; i < n; i++)
	{
		cout <<setw(5)<<setfill('0')<< PNode[i].Address << ' '<<PNode[i].Data
			<< ' ' << setw(5) << setfill('0')<<PNode[i].NextAddr<<'\n';
	}
	cout << setw(5) << setfill('0') << PNode[n].Address << ' ' << PNode[n].Data
		<< ' ' << PNode[n].NextAddr << '\n';
}

