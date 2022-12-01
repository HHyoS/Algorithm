#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
#include <climits>
#include <map>
using namespace std;

const int MAX = 20;

int N;
int result = INT_MIN;
string s;
map<char, int> priority;
char parenthesis[MAX];

void setPriority(void)
{
	priority['('] = 2;
	priority['*'] = 1;
	priority['+'] = 0;
	priority['-'] = 0;
}

bool isNotParenthesis(int idx)
{
	return (parenthesis[idx] != '(' && parenthesis[idx] != ')');
}

bool isOperand(char c)
{
	return (c >= '0' && c <= '9');
}

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int calculatePostfix(string tempS)
{
	stack<int> postfixStack;

	for (int a = 0; a < tempS.size(); ++a)
	{
		if (isOperand(tempS[a]))
		{
			postfixStack.push(tempS[a] - '0');

			continue;
		}

		if (postfixStack.size() >= 2)
		{
			int second = postfixStack.top();
			postfixStack.pop();
			int first = postfixStack.top();
			postfixStack.pop();

			int temp = calculate(first, second, tempS[a]);
			postfixStack.push(temp);
		}
	}

	return postfixStack.top();
}

int postfixResult()
{
	string tempS;
	stack<char> st;

	for (int a = 0; a < N; ++a)
	{
		if (isOperand(s[a]))
		{
			tempS += s[a];
		}

		switch (parenthesis[a])
		{
		case '(':
			st.push('(');

			break;
		case ')':
			while (st.empty() == false && st.top() != '(')
			{
				tempS += st.top();

				st.pop();
			}

			st.pop();

			break;
		default:
			if (isOperand(s[a]))
			{
				break;
			}

			while (st.empty() == false && priority[st.top()] >= priority[s[a]])
			{
				if (st.top() == '(')
				{
					break;
				}

				tempS += st.top();
				st.pop();
			}

			st.push(s[a]);

			break;
		}
	}

	while (st.empty() == false)
	{
		tempS += st.top();

		st.pop();
	}

	return calculatePostfix(tempS);
}

void func(int idx)
{
	if (idx >= N)
	{
		result = max(result, postfixResult());

		return;
	}

	for (int a = idx; a < N; a += 2)
	{
		if (a >= N - 2)
		{
			func(a + 1);

			continue;
		}

		if (isNotParenthesis(a) && isNotParenthesis(a + 2))
		{
			parenthesis[a] = '(';
			parenthesis[a + 2] = ')';
			func(a + 2);
			parenthesis[a] = ' ';
			parenthesis[a + 2] = ' ';
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> s;

	setPriority();

	func(0);

	cout << result << "\n";

	return 0;
}
