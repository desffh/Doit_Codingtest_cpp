#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 1427번 문제 내림차순으로 자릿수 정렬하기

// 선택정렬은 잘 사용하지 않으니 원리만 알고 넘어가기

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> str;

	vector<int> A(str.size(), 0); // 입력받은 문자열 길이만큼 사이즈 지정 후 0으로 초기화

	for (int i = 0; i < str.size(); i++)
	{
		A[i] = stoi(str.substr(i, 1)); // i부터 1크기의 문자열을 정수로 배열에 담기
	}

	for (int i = 0; i < str.size(); i++)
	{
		int Max = i;

		for (int j = i + 1; j < str.size(); j++)
		{
			if (A[j] > A[Max]) // 내림차순이라 최댓값을 찾는다.
			{
				Max = j;
			}
		}
		if (A[i] < A[Max]) // i자리와 최댓값인 Max자리를 스왑
		{
			swap(A[i], A[Max]);
		}
	}

	for (int c : A)
	{
		cout << c;
	}
}


