#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <utility>

using namespace std;

struct treeNode{
	bool fail;
	vector<treeNode> sub;
	treeNode() :fail(false) {}
};

int calc(int k)
{
	treeNode root;
	for (int m = k; ; ++m)
	{
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
			pos = (pos + sub) % i;
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

	for (cin >> k, m = 2*k-1; k != 0; cin >> k, m = 2*k-1)
	{
		cout << calc(k) << endl;
	}

	return 0;
}
