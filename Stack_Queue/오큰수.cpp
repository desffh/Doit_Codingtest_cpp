#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 17298�� ���� ��ū�� ���ϱ�

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; // ���� ����

	cin >> N;

	vector <int> A(N, 0);  // ũ�Ⱑ N�� ���� �迭
	vector <int> ans(N, 0);// ũ�Ⱑ N�� ���� �迭

	stack<int> idxStack;   // �ε����� ���� 
	idxStack.push(0);

	// ���� �迭 �Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i < N; i++)
	{
		// ������ ���� �ʾҰ�, ������ ���� top���� ũ�ٸ� �ݺ�
		// -> ���� �ε����� ������ ��ū���� ���� �� �ֱ� �����̴�.
		while (!idxStack.empty() && A[idxStack.top()] < A[i])
		{
			// top �ε����� ��ū�� A[i] ����
			ans[idxStack.top()] = A[i];

			idxStack.pop();
		}
		idxStack.push(i);
	}

	// ���� �ݺ����� �� ���Ҵµ��� ���ÿ� ���Ұ� ���Ҵٸ�
	while (!idxStack.empty())
	{
		ans[idxStack.top()] = -1;
		idxStack.pop();
	}

	// ���� �迭 ���
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}