#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;


// 둘의 길이가 같아야함
// 숫자면 숫자만큼 상대방은 이동 나는 한칸이렇게
// 같은 자리에 같은 문자가 있으며
// 같은 자리에 숫자와 영문자이면
void conversion(string origin, string &strTemp);
bool solution(string &S, string &T)
{
	string s, t;
	
	conversion(S, s);
	conversion(T, t);
	cout << t << endl;
	cout << s << endl;

	if(s.size() != t.size())
	{
		return false;
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		// s == '0' ? t == '0' true
		// s == t true
		if (s[i] != t[i])
		{
			if (s[i] != '0' && t[i] != '0')
			{
				return false;
			}
		}

	}

	return true;
}

void conversion(string origin, string &strTemp)
{
	int temp = 0;
	for (int i = 0; i < origin.size(); i++)
	{
		if (origin[i] >= 'A')
		{
			strTemp += origin[i];
		}
		else
		{
			int j = i;
			while (j < origin.size() && origin[j] < 'A')
			{
				if (temp == 0)
				{
					temp = origin[j] - '0';
				}
				else
				{
					temp = temp * 10 + (origin[j] - '0');
				}
				j++;
				
			}

			for (int k = 0; k < temp; k++)
			{
				strTemp += '0';
			}
			temp = 0;
			i = j - 1;
		}
	}
}


void main(void)
{
			// false  // true  // false  // true
	string S = "ba1"; // "a10" // "3x2x" // "A2Le"
	string T = "1Ad"; // "10a" // "8"    // "2pL1"
	std::cout << solution(S,T) << endl;
	system("pause");
}