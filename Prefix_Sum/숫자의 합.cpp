#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 구간 합 - 숫자의 합 구하기
/// </summary>

int main()
{
	int N = 0;
	int sum = 0;
	string st;

	cin >> N; // 숫자의 개수
	cin >> st; // 문자열 숫자들


	for (int i = 0; i < st.length(); i++)
	{
		sum += st[i] - '0';
	}

	cout << sum;
}