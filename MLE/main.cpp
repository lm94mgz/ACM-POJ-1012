#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct treeNode{
	bool fail;
	vector<treeNode> sub;
	treeNode() :fail(false) {}
};

int calc(int k)
{
	treeNode root;
	for (int m = k;; ++m)
	{
		if (m % (k + 1) > 1)
			continue;

		treeNode *node = &root;

		int i = 2 * k, pos = -1;
		for (; i > k; --i)
		{
			int sub = m % i;
			if (node->sub.size() < i)
				node->sub.resize(i);
			node = (treeNode*)&node->sub[sub];
			if (node->fail)
				break;
			pos = (pos + sub + i) % i;
			if (pos-- < k)
			{
				node->fail = true;
				break;
			}
		}

		if (i == k)
			return m;
	}
}

int main()
{
	int k, m;
	map<int, int> cache;

	for (cin >> k; k != 0; cin >> k)
	{
		if (cache.find(k) == cache.end())
			cache.insert(make_pair(k, calc(k)));
		cout << cache[k] << endl;
	}

	return 0;
}
