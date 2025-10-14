#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1016번 제곱이 아닌 수 찾기
	*/

	long Min; // 입력받는 값의 최대 범위가 10^12
	long Max;

	int count = 0;

	cin >> Min >> Max;

	vector<bool> Check(Max - Min + 1);

	for (long i = 2; i * i <= Max; i++)
	{
		long pow = i * i; // 제곱 수

		// 시작 인덱스 설정 -> 범위 내의 첫 제곱수의 배수부터 시작하기 위함
		long start_index = Min / pow;

		// 나머지가 0이 아니라면 + 1
		if (Min % pow != 0)
		{
			start_index++;
		}

		for (long j = start_index; pow * j <= Max; j++)
		{
			// 배열의 범위가 [Min, Max]로 되어있기 때문에 위치도 보정해야한다.
			// j * pow의 실제 값을 인덱스로 배열에 넣기 위함.
			Check[(int)((j * pow) - Min)] = true;
		}
	}

	for (int i = 0; i < Max - Min + 1; i++)
	{
		if (Check[i] != true)
		{
			count++;
		}
	}
	cout << count << "\n";
}
