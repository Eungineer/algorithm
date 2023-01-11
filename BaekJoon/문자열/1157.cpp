/*

Jeongeun in charge
Update: 2023.1.11


1157: 단어 공부

문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

*/

#include<iostream>
#include<string>
using namespace std;

//아스키코드 : 소문자 97~122, 대문자 65~90

int main()
{
	string str;
	cin >> str;

	int num[26] = { 0, };
	int max = -1;
	int idx = -1;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 97)
			num[str[i] - 65]++; //대
		else
			num[str[i] - 97]++; //소

	}

	for (int i = 0; i < 26; i++)
	{

		if (max < num[i])
		{
			max = num[i];
			idx = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (idx == i)
			continue;
		if (max == num[i])
		{
			cout << '?';
			return 0;
		}
	}

	cout << (char)(idx + 65);
	return 0;
}