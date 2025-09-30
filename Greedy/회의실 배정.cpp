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
		1931�� ȸ�ǽ� �����ϱ�

		��ġ�� �ʰ� �� ���� ȸ�ǽǿ��� �� �� �ִ� ȸ���� �ִ� ������
		ȸ�ǽð��� ª�� ������ ��ġ�� �ʰ� ¥�� �ȴ�.
	*/

	int N; // ȸ���� ����
	int result = 0;
	int end = -1;

	cin >> N;

	// ȸ�� ���� : ���� �ð�, �� �ð�
	vector <pair<int, int>> A;

	for (int i = 0; i < N; i++)
	{
		int start;
		int end;
		cin >> start >> end;

		// ���� �ð� ������ ���� ����ð��� first�� ����
		A.push_back(pair<int, int>(end, start));
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++)
	{
		// ���� ȸ�� ���� �ð� >= ���� ȸ�� ���� �ð� => ȸ�ǰ� ��ġ�� �ʴ´ٴ� ��
		if (A[i].second >= end)
		{
			//
			end = A[i].first; // ���� �ð� ����
			result++; //  ȸ�� ī��Ʈ
		}
	}

	cout << result << '\n';
}



// ����� ���� �� �Լ��� ����� ���

/*
// �������� ���� (����ð� second�� ����)
bool Calculate(pair<int, int>& first, pair<int, int>& second)
{
	// ���� �ð��� ���ٸ� ���۽ð� �������� �������� ����
	if (first.second == second.second)
	{
		return first.first < second.first;
	}
	// ���� �ð� �������� ����
	return first.second < second.second;
}
*/

/*int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
		// 1931�� ȸ�ǽ� �����ϱ�

		// ��ġ�� �ʰ� �� ���� ȸ�ǽǿ��� �� �� �ִ� ȸ���� �ִ� ������
		// ȸ�ǽð��� ª�� ������ ��ġ�� �ʰ� ¥�� �ȴ�.
	
	int N; // ȸ���� ����
	int result = 0;
	int end = -1;

	cin >> N;

	// ȸ�� ���� : ���� �ð�, �� �ð�
	vector <pair<int, int>> A(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first;
		cin >> A[i].second;
	}

	// ����� ���� ���Լ� ���
	sort(A.begin(), A.end(), Calculate);

	for (int i = 0; i < N; i++)
	{
		if (A[i].first >= end)
		{
			end = A[i].second;
			result++;
		}
	}
	cout << result << '\n';
}*/

