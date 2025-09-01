#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 2751번 문제 수 정렬하기2 

void Merge(int start, int end); // 분할
void MergeSort(int start, int end, int middle); // 병합
static vector<int>A;   // 정렬 배열
static vector<int>tmp; // 임시 배열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	A = vector<int>(N + 1, 0); // 편의 상 [0]인덱스를 제외하고 [1]부터 시작한다.
	tmp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	Merge(1, N);

	for (int i = 1; i <= N; i++)
	{
		cout << A[i] << '\n';
	}
}

void Merge(int start, int end)
{
	// 더 이상 쪼개질 수 없다면 return
	if (end - start < 1)
	{
		return;
	}

	int middle = (end + start) / 2; // == start + (end - start) / 2

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

	int k = start; // A배열에 넣기위한 위치
	int index1 = start;
	int index2 = middle + 1;

	// 값을 비교하여 정렬 배열 A에 넣어주기 -> 오름차순 정렬이라 더 작은 값을 A배열에 넣는다.
	while (index1 <= middle && index2 <= end)
	{
		if (tmp[index1] > tmp[index2])
		{
			A[k++] = tmp[index2++];
		}
		else
		{
			A[k++] = tmp[index1++];
		}
	}

	// 남은 한쪽 원소 정리하기

	while (index1 <= middle)
	{
		A[k++] = tmp[index1++];
	}
	while (index2 <= end)
	{
		A[k++] = tmp[index2++];
	}
}