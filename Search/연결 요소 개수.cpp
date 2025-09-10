#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int v);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		11724�� ���� ����� ���� ���ϱ�

		1. �� ��忡 ������ ��带 ���� �� 2���� �迭 ����
		   -> ��� ���̸� ���� [0]�� ������� �ʴ´�.

		2. ����� 1��°���� N���� DFS�� �����Ѵ�.
		   -> DFS���ο� �湮 ���ο� ���� �����ϰų� Ż���Ѵ�.

		   -> ��� �Լ��� ���ð� ���� ������� ó���Ǵ� ��

		3. DFS�� ���� Ƚ�� == ���� ��� ����
	*/

	int N = 0; // ��� ����
	int M = 0; // ���� ����

	cin >> N >> M;

	A.resize(N + 1); // [0]���� �Է¹ޱ� -> ��� ���̸� ����
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int node1;
		int node2;

		cin >> node1 >> node2;

		A[node1].push_back(node2);
		A[node2].push_back(node1);
	}

	int count = 0;

	for (int i = 1; i < N + 1; i++) // [0]���� DFS ����
	{
		if (!visited[i]) // �湮���� �ʾ����� DFS����
		{
			count++;
			DFS(i);
		}
	}

	cout << count << '\n';
}

void DFS(int v)
{
	if (visited[v]) return; // �̹� �湮üũ�� �Ǿ����� ����x

	visited[v] = true;

	for (int element : A[v])
	{
		if (visited[element] == false) // ��������Ʈ ��Ұ� �湮���� �ʾҴٸ�
		{
			DFS(element); // Ž��
		}
	}
}