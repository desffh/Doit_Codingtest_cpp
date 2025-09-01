#include <iostream>
#include <algorithm>
using namespace std;

/// <summary>
/// 슬라이딩 윈도우 - DNA 비밀번호
/// </summary>

int checkarr[4]; // 체크 배열 (A C G T)
int myarr[4];    // 상태 배열 (A C G T)
int checkcount = 0; // 부분 문자열의 최소갯수를 만족하는 지 확인하는 변수

// 문자열 추가하기
void Add(char& a)
{
	switch (a)
	{
	case 'A': // 들어온 문자열 카운팅 & 최소 요구 개수와 같다면 checkcount++
		myarr[0]++;
		if (myarr[0] == checkarr[0])
		{
			checkcount++;
		}
		break;
	case 'C':
		myarr[1]++;
		if (myarr[1] == checkarr[1])
		{
			checkcount++;
		}
		break;
	case 'G':
		myarr[2]++;
		if (myarr[2] == checkarr[2])
		{
			checkcount++;
		}
		break;
	case 'T':
		myarr[3]++;
		if (myarr[3] == checkarr[3])
		{
			checkcount++;
		}
		break;
	}
}

// 문자열 제거하기
void Remove(char& a)
{
	switch (a)
	{
	case 'A':
		if (myarr[0] == checkarr[0])
		{
			checkcount--;
		}
		myarr[0]--;
		break;
	case 'C':
		if (myarr[1] == checkarr[1])
		{
			checkcount--;
		}
		myarr[1]--;
		break;
	case 'G':
		if (myarr[2] == checkarr[2])
		{
			checkcount--;
		}
		myarr[2]--;
		break;
	case 'T':
		if (myarr[3] == checkarr[3])
		{
			checkcount--;
		}
		myarr[3]--;
		break;
	}
}


int main()
{
	// 제한 시간 2초 = 2 x 10^8
	// 문자열과 부분 문자열 길이 최대 10^6
	// [최종 시간 복잡도 -> O(N) 이하로 가능

	// [슬라이딩 윈도우]
	// - 부분 문자열이 이동할 때 마다 앞에 원소는 제거하고 뒤의 원소는 추가해야함.
	// - 유효한 비밀번호를 검사할 때 기존 검사 결과에 새로 들어온 문자열
	// 제거되는 문자열만 반영하여 확인하는 것이 핵심이다.

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S = 0;
	int P = 0;
	string A; // 입력받은 문자열
	int Result = 0;

	cin >> S >> P >> A;

	// 체크 배열 입력받기
	for (int i = 0; i < 4; i++)
	{
		cin >> checkarr[i];

		if (checkarr[i] == 0)
		{
			checkcount++;
		}
	}

	// 초기 P배열 저장
	for (int i = 0; i < P; i++)
	{
		// 문자열의 P배열 크기만큼 myarr에 추가
		Add(A[i]);
	}

	// 최소 갯수를 만족한다면 -> 4는 A C G T 각각을 의미
	if (checkcount == 4)
	{
		Result++;
	}

	// 슬라이딩 윈도우
	for (int i = P; i < S; i++)
	{
		int add = i;
		int remove = i - P;

		Add(A[add]);
		Remove(A[remove]);

		if (checkcount == 4)
		{
			Result++;
		}
	}

	cout << Result << '\n';
}


