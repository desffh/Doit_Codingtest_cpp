#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1377�� ���� ���� ���� ���α׷�1

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// �������� swap�� �Ͼ�� �ʾҴٴ� ��, �̹� ��� �����Ͱ� ���ĵǾ��ٴ� ��
	// ��, �� ���� �н�(i)�� �ݺ��ؾ� ������ �Ϸ�Ǵ��� ���� ������ �����ϴ� ���̴�.


	int N = 0;

	cin >> N;

	vector<pair<int, int>> A(N); // first : ������ second : ���� �� �ε���

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first; // ������
		A[i].second = i;   // ���� �� �ε��� 
	}

	sort(A.begin(), A.end()); // first �켱���� ����

	int Max = 0;

	for (int i = 0; i < N; i++)
	{
		if (Max < A[i].second - i)
		{
			Max = A[i].second - i; // ���� �� �ε��� - ���� �� �ε���
		}
	}

	cout << Max + 1 << '\n';
}


