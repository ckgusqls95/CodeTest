#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0;

	int position = 0;
	string CurrentName;

	for(int i = 0; i < name.size(); i++)
	{
		CurrentName += 'A';
	}
	int i = 0;
	while(i < name.size())
	{
		CurrentName[position] = name[position];
		answer += name[position] > 'N' ? ('Z' - name[position] + 1): name[position] - 'A';
		
		int Nextposition = 0;
		int count1 = 0;
		int count2 = 0;
		
		for(int front = position;;)
		{
			front++;
			count1++;
			if(CurrentName[front] == 'A' && name[front] != 'A')
			{
				Nextposition = front;
				break;
			}
			
			if(front >= name.size() - 1)
			{
				Nextposition = INT_MAX;
				break;
			}
		}

		for(int back = position;;)
		{
			back--;
			count2++;
			if(back < 0)
			{
				back = name.size() -1;
			}
			
			if(CurrentName[back] == 'A' && name[back] != 'A')
			{
				if(count2 < count1)
				{
					Nextposition = back;
				}
				break;
			}
			if(back == position)
			{
				break;
			}
		}

		if(Nextposition == INT_MAX)
		{			
			break;
		}

		position = Nextposition;
		answer += count1 < count2 ? count1 : count2;
		i++;
	}
	
	
	return answer;
}


void main(void)
{
	string name = "JAN";
	printf("%d",solution(name));
}