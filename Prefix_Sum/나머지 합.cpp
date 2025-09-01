#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// ���� �� - ������ �� ���ϱ�
/// </summary>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N = 0; // ������ ����
	int M = 0; // ������ �������� �ϴ� ��

	cin >> N >> M;

	// ������ N, 0���� �ʱ�ȭ 
	vector<long> S(N, 0);  // �� �迭
	vector<long> C(M, 0);  // ������ �迭

	long answer = 0;

	cin >> S[0]; // 0��° �Է¹ޱ�

	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		cin >> temp;       //���ڹ迭 �Է¹ޱ�

		S[i] = S[i - 1] + temp; // �� �迭 ����
	}

	for (int i = 0; i < N; i++)
	{
		int remainer = S[i] % M;

		if (remainer == 0) answer++; // �� �迭�� �������� 0�̸� �� ��ü�� ���信 �߰�

		C[remainer]++; // ������ �迭�� ī����
	}

	for (int i = 0; i < M; i++)
	{
		// �������� ���� �ε��� ��2���� �̴� ����� �� -> ��찡 2�̻��̾����
		if (C[i] > 1) answer += C[i] * (C[i] - 1) / 2;
	}

	cout << answer << endl;
}