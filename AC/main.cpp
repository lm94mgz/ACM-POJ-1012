#include <iostream>
#include <map>

using namespace std;

int main()
{
	int k;
	map<int, int> cache;

	for (cin >> k; k != 0; cin >> k)
	{
		if (cache.find(k) != cache.end())
		{
			cout << cache[k] << endl;
			continue;
		}

		int n = 2 * k;
		int m = 1;
		int lastKillIndex = 0;

		for (int i = 1; i <= k; ++i)
		{
			lastKillIndex = (lastKillIndex + m - 1) % (n - i + 1);
			if (lastKillIndex < k)
			{
				i = 0;
				m++;
				lastKillIndex = 0;
			}
		}

		cache.insert(make_pair(k, m));
		cout << m << endl;
	}
	return 0;
}
