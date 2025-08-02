#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// �� ������ - �ָ��� �۷�
/// </summary>

int main()
{
	int N; // ����� ����
	int M; // ������ �ϼ��Ǵ� ��ȣ�� ��
	cin >> N >> M;

	vector <int> A(N, 0); // ������ ���� �迭 (ũ�� N, 0���� ��� �ʱ�ȭ)
	int count = 0;


	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end()); // �������� ����

	int start_index = 0;
	int end_index = N - 1;

	while (start_index < end_index)
	{
		// ���� 2���� ��� == ���� ��ȣ
		if (A[start_index] + A[end_index] == M)
		{
			count++;
			start_index++;
			end_index--;
		}
		// ���� ��ȣ�� �� ũ�ٸ� -> ���� ��ȣ �̵�
		else if (A[start_index] + A[end_index] < M)
		{
			start_index++;
		}
		// ���� ��ȣ�� �� �۴ٸ� -> ū ��ȣ �̵�
		else
		{
			end_index--;
		}
	}

	cout << count << endl;
}



// 2��° Ǯ�� (push_back() & start < end �϶� �ݺ�

int main2()
{
	// 0. �� ���� ���� �̿��ؼ� ���ϱ� ������ �� ���̵� ���� ���
	// 1. start�� ó�� �ε���, end�� ������ �ε���
	// 2. �Է¹��� ���ڸ� ���� -> �ð����⵵ �� NlogN���� ��밡��
	// 3. �� ������ ����

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0; // ����� �ϴ� �� M

	cin >> N >> M;

	int count = 0;
	vector<int>result;


	int start = 0;
	int end = N - 1;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;

		result.push_back(temp);
	}

	sort(result.begin(), result.end());

	while (start < end)
	{
		if (result[start] + result[end] == M)
		{
			count++;
			start++;
			end--;
		}
		else if (result[start] + result[end] < M)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	cout << count << '\n';
}