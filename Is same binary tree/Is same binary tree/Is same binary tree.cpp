// Is same binary tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

struct Tree
{
	int data;
	Tree *Left;
	Tree *Right;
};

Tree *Insert(Tree *T,int x);
bool IsSame(Tree *T,Tree *Tc);

int main()
{
	int n, l;

	std::cin >> n;
	while (n)
	{
		int x;

		std::cin >> l;
		Tree *Root = nullptr;

		for (int i = 0; i < n; i++)
		{
		    std::cin >> x;
			Root = Insert(Root, x);
		}

		for (int i = 0; i < l; i++)
		{
			Tree *Root_c = nullptr;
			for (int a = 0; a < n; a++)
			{
				std::cin >> x;
				Root_c = Insert(Root_c, x);

			}
			if (IsSame(Root, Root_c))
			{
				std::cout << "Yes"<<std::endl;

			}
			else
				std::cout << "No"<<std::endl;

			delete(Root_c);
		}
		delete(Root);
		std::cin >> n;
	}
	system("pause");
    return 0;
}

Tree * Insert(Tree * T, int x)
{
	if (T == nullptr)
	{
		T = new Tree;
		T->data = x;
		T->Left = T->Right = nullptr;
	}
	else
	{
		if (x < T->data)
			T->Left = Insert(T->Left, x);
		else if (x > T->data)
			T->Right = Insert(T->Right, x);
	}
	return T;
}

bool IsSame(Tree * T, Tree * Tc)
{
	if (T &&Tc&&T->data == Tc->data)
	{
		if (IsSame(T->Left, Tc->Left) && IsSame(T->Right, Tc->Right))
			return true;
		else return false;
	}
	else if (!T && !Tc)
		return true;
	else
		return false;
}
