#include <cstdio>
#include <vector>

using namespace std;

template <typename T> inline void ignore_value(T) {}

const int MAX = 18;

int n;
char rel[MAX][MAX + 1];
vector <int> result, cur;

void read_data()
{
	ignore_value(scanf("%d", &n));
	for (int i = 0; i < n; ++i)
		ignore_value(scanf("%s", rel[i]));
}

inline bool ok(int v)
{
	for (vector <int>::const_iterator i = cur.begin(); i != cur.end(); ++i)
		if (rel[*i][v] == '1')
			return false;
	return true;
}

void dfs(int v)
{
	cur.push_back(v);

	if (cur.size() > result.size())
		result = cur;

	for (int i = v + 1; i < n; ++i)
		if (ok(i))
			dfs(i);
	cur.pop_back();
	for (int i = v + 1; i < n; ++i)
		if (ok(i))
			dfs(i);
}

void output()
{
	printf("%d\n%d", (int)result.size(), result[0] + 1);
	for (int i = 1; i < (int)result.size(); ++i)
		printf(" %d", result[i] + 1);
	printf("\n");
}

int main()
{
	read_data();
	dfs(0);
	output();
	return 0;
}
