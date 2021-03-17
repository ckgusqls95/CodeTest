#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	answer = n - lost.size();

	
	vector<int>::iterator it;

	for(vector<int>::iterator p = lost.begin(); p != lost.end();)
	{
		it = find(reserve.begin(), reserve.end(), p);
		if (it == reserve.end())
		{
			++p;
		}
		else
		{
			answer++;
			reserve.erase(it);
			lost.erase(p);
		}
	}
	

	for(int i = 0; i < lost.size(); i++)
	{
		for(int j = 0; j < reserve.size(); j++)
		{
			if(reserve[j] == lost[i] + 1 || reserve[j] == lost[i] - 1)
			{
				reserve.erase(reserve.begin() + j);
				answer++;
				break;
			}
		}		
	}	
	return answer;
}

void main()
{
	vector<int> lost = { 1,2,3 };
	vector<int> reserve = { 2,3,4 };
	printf("%d",solution(5,lost,reserve));
}

/*
 *#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	answer = n - lost.size();

	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == lost[i])
			{
				reserve.erase(reserve.begin() + j);
				lost[i] = 0;
				answer++;
				break;
			}
		}
	}

	for(int i = 0; i < lost.size(); i++)
	{
		for(int j = 0; j < reserve.size(); j++)
		{
			if(reserve[j] == lost[i] + 1 || reserve[j] == lost[i] - 1)
			{
				reserve.erase(reserve.begin() + j);
				answer++;
				break;
			}
		}		
	}	
	return answer;
}
 *
 * 
 */