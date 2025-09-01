#include <iostream>
#include <algorithm>
using namespace std;

/// <summary>
/// 투 포인터 - 연속된 자연수의 합 구하기
/// </summary>

int main()
{
	int N = 0;
	cin >> N;

	int start_index = 1;
	int end_index = 1;
	int sum = 1;
	int count = 1;

	while (end_index != N)
	{
		if (sum == N)
		{
			count++;
			sum += ++end_index;
		}
		else if (sum > N)
		{
			sum -= start_index++;
		}
		else
		{
			sum += ++end_index;
		}
	}
	cout << count;
}