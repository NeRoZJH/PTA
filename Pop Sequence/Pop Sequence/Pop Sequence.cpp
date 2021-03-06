// Pop Sequence.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>

using namespace std;

int check(int m, int n);

int main()
{
	int m, n, k;


	cin >> m >> n >> k;

	for (int K = 1; K <= k; K++)
	{
	     cout << (check(m, n)?"YES":"NO") << endl;
	}

	system("pause");
    return 0;
}

int check(int m, int n)
{
	stack<int> st;
	st.push(0);
	int num = 1;
	int cap = m + 1;
	int flag = 1;
	int top;

	for (int i = 1; i <= n; i++)
	{
		cin >> top;
		while (num <= top && top > st.top() && st.size() < cap)
		{
			st.push(num);
			num++;
		}
		if (top != st.top())
		{
			flag = 0;
		}
		st.pop();
	}

	return flag;
}
