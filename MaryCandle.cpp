#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &T)
{
	map<int, int> candles;


	for (size_t i = 0; i < T.size(); i++)
	{
		int candle = T[i];
		if (candles.find(candle) != candles.end())
		{
			candles[candle]++;
		}
		else
		{
			candles.insert({ candle, 1 });
		}
	}

	for (size_t j = 0; j < T.size() / 2; j++)
	{
		int key = 0;

		for (auto it : candles)
		{
			if (key == 0 || it.second > candles[key])
			{
				key = it.first;
			}
		}

		candles[key]--;

		if (candles[key] <= 0)
		{
			candles.erase(key);
		}
	}

	return candles.size();
}



void main()
{
	vector<int> T = { 80,80,10000000,80,80,80,80,80,123456789 };
	//{ 3,4,7,7,6,6 };

	cout << solution(T) << endl;

	system("pause");

}