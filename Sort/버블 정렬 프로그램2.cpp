#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 1517번 문제 버블 정렬 프로그램2

void Merge(int start, int end);
void MergeSort(int start, int end, int middle);

static vector<int>A;   // 정렬 배열
static vector<int>tmp; // 임시 배열
static long result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	Merge(1, N);

	cout << result << '\n';
}

void Merge(int start, int end)
{
	// 크기가 1보다 작다면 return
	if (end - start < 1)
	{
		return;
	}

	int middle = (start + end) / 2;

	Merge(start, middle);
	Merge(middle + 1, end);

	MergeSort(start, end, middle);
}

void MergeSort(int start, int end, int middle)
{
	for (int i = start; i <= end; i++)
	{
		tmp[i] = A[i];
	}

	int k = start; // 배열A에 순회
	int index1 = start;
	int index2 = middle + 1;

	while (index1 <= middle && index2 <= end)
	{
		if (tmp[index1] > tmp[index2])
		{
			A[k] = tmp[index2];
			result += index2 - k; // 뒤의 값이 앞으로 올때의 거리만 저장
			k++;
			index2++;
		}
		else
		{
			A[k++] = tmp[index1++];
		}
	}

	while (index1 <= middle)
	{
		A[k++] = tmp[index1++];
	}
	while (index2 <= end)
	{
		A[k++] = tmp[index2++];
	}
}

