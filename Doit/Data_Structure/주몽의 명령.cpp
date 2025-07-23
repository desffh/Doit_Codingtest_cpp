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

	while (start_index <= end_index)
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