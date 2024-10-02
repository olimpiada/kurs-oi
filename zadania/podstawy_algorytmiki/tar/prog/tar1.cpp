#include <cstdio>

template <typename T> inline void ignore_value(T) {}

bool calc(long long p, long long q)
{
	static const int LIMIT = 1000 * 1000; //LIMIT^3 == 10^18

	long long x, lo = 1, hi = LIMIT;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		x = mid * mid * mid + p * mid;
		if (x == q) {
			printf("%lld\n", mid);
			return true;
		} else if (x < q) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	return false;
}

int main()
{
	int z;
	ignore_value(scanf("%d", &z));

	while (z != 0) {
		--z;

		long long p, q;
		ignore_value(scanf("%lld %lld", &p, &q));
		if (!calc(p, q))
			printf("NIE\n");
	}

	return 0;
}
