#include <cstdio>

template <typename T> inline void ignore_value(T) {}

const int MAX = 500010;

int n, k;
char text[MAX];

inline int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void read_data()
{
	ignore_value(scanf("%d %d %s", &n, &k, text + 1));
	for (int i = 1; i <= n; ++i)
		text[i] -= '0';
}

inline int find_zeros()
{
	int temp = 0, result = 0;
	int i = 1;

	while (i <= n) {
		if (text[i] == 0) {
			++temp;
		} else {
			result = max(result, temp);
			temp = 0;
		}

		++i;
	}

	result = max(result, temp);
	return result;
}

void calc()
{
	while (k != 0) {
		--k;

		int q;
		ignore_value(scanf("%d", &q));
		text[q] = 1 - text[q];
		printf("%d\n", find_zeros());
	}
}

int main()
{
	read_data();
	calc();
	return 0;
}
