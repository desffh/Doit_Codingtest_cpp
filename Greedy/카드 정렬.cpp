#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1715�� ī�� �����ϱ� - �켱���� ť ���
	*/

	int N; // ī�� ���� ����

	int result = 0;

	cin >> N;

	priority_queue<int, vector<int>, greater<int>> A;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		A.push(num);
	}

	while (A.size() > 1)
	{
		int num1 = A.top();
		A.pop();

		int num2 = A.top();
		A.pop();

		int sum = num1 + num2;

		result += sum;

		A.push(sum);
	}

	cout << result << '\n';
}