#include"stdafx.h"
#include <iostream>
#include <string>
#include<math.h>

#define LL 1
#define RR 2
#define LR 3
#define RL 4

typedef struct AVLTreeNode{
    int Data;
	AVLTreeNode *P;
    AVLTreeNode *Left;
    AVLTreeNode *Right;
    int Height;
}AVLTree ,*pAVLTree;

using namespace std;

pAVLTree Insert(pAVLTree T, int x);

pAVLTree AVL_Search(pAVLTree Root, int x);
pAVLTree AVL_Sort(pAVLTree Root,pAVLTree Pac,int Seq);
pAVLTree AVL_Check(pAVLTree T);
int AVL_SortSeq(pAVLTree T,int x);
int Height(pAVLTree Root);
int Deg(pAVLTree Root);
void preorder_Deg(pAVLTree Root);


pAVLTree AVL_LL(pAVLTree T, pAVLTree Root);
pAVLTree AVL_RR(pAVLTree T,pAVLTree Root);
pAVLTree AVL_LR(pAVLTree T,pAVLTree Root);
pAVLTree AVL_RL(pAVLTree T,pAVLTree Root);


int main()
{
	int n,x;
	pAVLTree Root;
	cin >> n;
	Root = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Root = Insert(Root, x);
		preorder_Deg(Root);
		if (AVL_Check(AVL_Search(Root, x)))
		{
			pAVLTree PAc;
			int Seq = 0;

			PAc = AVL_Check(AVL_Search(Root,x));
			Seq = AVL_SortSeq(PAc, x);
			Root = AVL_Sort(Root, PAc,Seq);
			PAc = nullptr;
		}
	}
	cout << Root->Data<<endl;

	system("pause");
	return 0;
}

pAVLTree Insert(pAVLTree T, int x)
{
	if (T == nullptr)
	{
		T = new AVLTree;
		T->Data = x;
		T->P = nullptr;
		T->Height = 0;
		T->Left = T->Right = nullptr;
	}
	else
	{
		if (x < T->Data)
		{
			T->Left = Insert(T->Left, x);
			T->Left->P = T;
		}
		else if (x > T->Data)
		{
			T->Right = Insert(T->Right, x);
			T->Right->P = T;
		}
	}
	return T;
}


pAVLTree AVL_Search(pAVLTree Root, int x)
{
	if (!Root) {
		return nullptr;
	}
	if (Root->Data == x) {
		return Root;
	}
	else {
		if (!AVL_Search(Root->Left, x)) {
			return AVL_Search(Root->Right, x);
		}
		return AVL_Search(Root->Left, x);
	}
}

pAVLTree AVL_Sort(pAVLTree Root, pAVLTree Pac,int Seq)
{
	if (Seq == LL)
		Root = AVL_LL(Pac, Root);
	else if (Seq == LR)
		Root = AVL_LR(Pac, Root);
	else if (Seq == RR)
		Root = AVL_RR(Pac, Root);
	else if (Seq == RL)
		Root = AVL_RL(Pac, Root);
	else	
	return Root;
}

pAVLTree AVL_Check(pAVLTree T)
{
	if (T == nullptr)
	{
		return T;
	}

	while (T && abs(T->Height) <= 1)
	{
		T = T->P;
	}
	return T;
}

int AVL_SortSeq(pAVLTree T, int x)
{
	if (T->Left) 
	{
		if (T->Left->Left)
		{
			if (T->Left->Left->Data == x)
				return RR;

			if (T->Left->Left->Left && T->Left->Left->Left->Data == x)
				return RR;

			if (T->Left->Left->Right && T->Left->Left->Right->Data == x)
				return RR;
		}
		if (T->Left->Right)
		{
			if (T->Left->Right->Data == x)
				return LR;

			if (T->Left->Right->Left && T->Left->Right->Left->Data == x)
				return LR;

			if (T->Left->Right->Right && T->Left->Right->Right->Data == x)
				return LR;
		}
	}
	if (T->Right)
	{
		if (T->Right->Right)
		{
			if (T->Right->Right->Data == x)
				return LL;

			if (T->Right->Right->Left && T->Right->Right->Left->Data == x)
				return LL;

			if (T->Right->Right->Right && T->Right->Right->Right->Data == x)
				return LL;
		}
		if (T->Right->Left)
		{
			if (T->Right->Left->Data == x)
				return RL;

			if (T->Right->Left->Left && T->Right->Left->Left->Data == x)
				return RL;

			if (T->Right->Left->Right && T->Right->Left->Right->Data == x)
				return RL;
		}
	}

	return 0;
}

int Height(pAVLTree Root)
{
	int h, left, right;
	if (!Root) {
		return 0;
	}
	left = Height(Root->Left);
	right = Height(Root->Right);
	h = (left>right ? left : right) + 1;
	return h;
}

int Deg(pAVLTree Root)
{
	int Deg = Height(Root->Left) - Height(Root->Right);
	return Deg;
}

void preorder_Deg(pAVLTree Root)
{
	if (Root)
	{
		Root->Height = Deg(Root);
		preorder_Deg(Root->Left);
		preorder_Deg(Root->Right);
	}
}

pAVLTree AVL_RR(pAVLTree T,pAVLTree Root)
{

	
	pAVLTree tmp;
	tmp = T->Left;

	if (!T->P)
		tmp->P = nullptr;
	else if (T->P->Left && T->P->Left->Data == T->Data)
	{
		T->P->Left = T->Left;
		tmp->P = T->P;
	}
	else if (T->P->Right &&T->P->Right->Data == T->Data)
	{
		T->P->Right = T->Left;
		tmp->P = T->P;
	}

	if(tmp->Right)
	tmp->Right->P = T;
	T->Left = tmp->Right;

	tmp->Right = T;
	T->P = tmp;

	if (Root->Data == T->Data)
		return tmp;
	else return Root;

}

pAVLTree AVL_LL(pAVLTree T,pAVLTree Root)
{
	pAVLTree tmp;
	tmp = T->Right;

	if (!T->P)
		tmp->P = nullptr;
	else if (T->P->Left && T->P->Left->Data == T->Data)
	{
		T->P->Left = T->Right;
		tmp->P = T->P;
	}
	else if (T->P->Right &&T->P->Right->Data == T->Data)
	{
		T->P->Right = T->Right;
		tmp->P = T->P;
	}

	if (tmp->Left)
		tmp->Left->P = T;
	T->Right = tmp->Left;

	tmp->Left = T;
	T->P = tmp;

	if (Root->Data == T->Data)
		return tmp;
	else return Root;
}

pAVLTree AVL_LR(pAVLTree T,pAVLTree Root)
{
	Root = AVL_LL(T->Left, Root);
	Root = AVL_RR(T, Root);
	return Root;
}

pAVLTree AVL_RL(pAVLTree T,pAVLTree Root)
{
	Root = AVL_RR(T->Right, Root);
	Root = AVL_LL(T, Root);
	return Root;
}
