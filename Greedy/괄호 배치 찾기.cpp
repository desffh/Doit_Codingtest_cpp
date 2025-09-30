#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// 문자열을 char a기준으로 자르고 자른 문자열을 저장한 벡터배열을 반환
vector<string> Split(string str, char a)
{
	vector<string> A;

	stringstream stream(str); // 스트림으로 변환
	string words;
	while (getline(stream, words, a))
	{
		A.push_back(words);
	}

	return A;
}

// 괄호 내부 합계
int mySum(string s)
{
	int sum = 0;

	vector<string> B = Split(s, '+');

	for (int i = 0; i < B.size(); i++)
	{
		sum += stoi(B[i]);
	}
	return sum;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		1541번 - 최솟값을 만드는 괄호 배치 찾기

		값을 최소로 만들기 위해서는 큰 값을 빼면 된다.
		-> 즉, + 연산을 모두 한 뒤 - 연산을 하면 커다란 값들을 빼게 되어 최소가 된다.
	*/

	int answer = 0;
	string str = "";

	cin >> str;

	vector<string> strA = Split(str, '-');

	for (int i = 0; i < strA.size(); i++)
	{
		int result = mySum(strA[i]);

		// 합이 제일 앞의 값일 경우
		if (i == 0)
		{
			answer += result;
		}
		else
		{
			answer -= result;
		}
	}

	cout << answer << '\n';
}
