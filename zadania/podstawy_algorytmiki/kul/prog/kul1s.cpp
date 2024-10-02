#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

const char EMPTY = '.';
const int SIZE = 8;
const int MAX = SIZE + 1;
const int MV_CNT = 2;
const int HEIGHT_LIMIT = 8;
const int MVS[MV_CNT][2] = {{0, 1}, {1, 0}};

struct mv {
	char premove[MAX][MAX];
	pair <int, int> t[2];
};

mv stack[MAX];
int height = 0;
int best_found = MAX*MAX;
bool to_clear[MAX][MAX];
char tab[MAX][MAX];
vector <pair <pair <int, int>, pair <int, int> > > result;

static inline void read_data()
{
	int i, j, cnt = 0;
	char conv[256];
	bool used[256], converted[256];

	memset(used, 0, sizeof(used));
	memset(converted, 0, sizeof(converted));

	for (i = 0; i < SIZE; ++i) {
		scanf("%s", tab[i]);
		for (j = 0; j < SIZE; ++j)
			if (tab[i][j] != EMPTY) {
				if (!converted[(int)tab[i][j]]) {
					converted[(int)tab[i][j]] = true;
					conv[(int)tab[i][j]] = (char)(cnt + '0');
					++cnt;
				}
				tab[i][j] = conv[(int)tab[i][j]];
			}
	}
}

static inline bool check()
{
	int i, j;

	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			if (tab[i][j] != EMPTY)
				return false;
	return true;
}

static inline bool check_triplet()
{
	int i, j;

	for (i = 0; i < SIZE - 2; ++i)
		for (j = 0; j < SIZE; ++j)
			if (tab[i][j] != EMPTY && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j])
				return true;

	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE - 2; ++j)
			if (tab[i][j] != EMPTY && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2])
				return true;

	return false;
}

static inline void mark_triplets()
{
	int i, j;

	for (i = 0; i < SIZE - 2; ++i)
		for (j = 0; j < SIZE; ++j)
			if (tab[i][j] != EMPTY && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j])
				to_clear[i][j] = to_clear[i+1][j] = to_clear[i+2][j] = true;

	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE - 2; ++j)
			if (tab[i][j] != EMPTY && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2])
				to_clear[i][j] = to_clear[i][j+1] = to_clear[i][j+2] = true;
}

static inline bool valid(const pair <int, int> &t1, const pair <int, int> &t2)
{
	if (t2.first >= SIZE || t2.second >= SIZE)
		return false;

	char temp1 = tab[t1.first][t1.second], temp2 = tab[t2.first][t2.second];
	if (temp1 == temp2)
		return false;

	tab[t1.first][t1.second] = temp2;
	tab[t2.first][t2.second] = temp1;

	bool result = check_triplet();

	tab[t1.first][t1.second] = temp1;
	tab[t2.first][t2.second] = temp2;
	return result;
}

static inline void save_state(const pair <int, int> &t1, const pair <int, int> &t2)
{
	stack[height].t[0] = t1;
	stack[height].t[1] = t2;
	memcpy(stack[height].premove, tab, sizeof(tab));

	++height;
}

static inline void restore_state()
{
	--height;
	memcpy(tab, stack[height].premove, sizeof(tab));
}

static inline void gravity()
{
	int i, j, k;

	for (i = SIZE - 1; i > 0; --i)
		for (j = SIZE - 1; j >= 0; --j) {
			if (tab[i][j] == EMPTY && tab[i-1][j] != EMPTY) {
				k = i;
				while (k < SIZE && tab[k][j] == EMPTY) {
					tab[k][j] = tab[k-1][j];
					tab[k-1][j] = EMPTY;
					++k;
				}
			}
		}
}

static inline void simulate(const pair <int, int> &t1, const pair <int, int> &t2)
{
	char temp1 = tab[t1.first][t1.second], temp2 = tab[t2.first][t2.second];

	tab[t1.first][t1.second] = temp2;
	tab[t2.first][t2.second] = temp1;

	while (check_triplet()) {
		memset(to_clear, 0, sizeof(to_clear));
		mark_triplets();
		int i, j;
		for (i = 0; i < SIZE; ++i)
			for (j = 0; j < SIZE; ++j)
				if (to_clear[i][j])
					tab[i][j] = EMPTY;
		gravity();
	}
}

static inline bool finished()
{
	int i, j;

	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			if (tab[i][j] != EMPTY)
				return false;

	if (best_found > height) {
		best_found = height;
		result.clear();
		for (j = 0; j < height; ++j)
			result.push_back(make_pair(stack[j].t[0], stack[j].t[1]));
	}
	return true;
}

static inline bool sure_fail()
{
	char cnt[SIZE];
	int i, j;

	for (i = 0; i < SIZE; ++i)
		cnt[i] = 0;
	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j)
			++cnt[tab[i][j] - '0'];
	for (i = 0; i < SIZE; ++i)
		if (cnt[i] != 0 && cnt[i] < 3)
			return true;

	return false;
}

static void dfs()
{
	int i, j;
	pair <int, int> t1, t2;

	if (finished())
		return;

	if (height + 1 >= best_found)
		return;

	if (height == HEIGHT_LIMIT)
		return;

	if (sure_fail())
		return;

	for (i = 0; i < SIZE; ++i)
		for (j = 0; j < SIZE; ++j) {
			t1 = make_pair(i, j);
			for (int mv = 0; mv < MV_CNT; ++mv) {
				t2.first = t1.first + MVS[mv][0];
				t2.second = t1.second + MVS[mv][1];
				if (valid(t1, t2)) {
					save_state(t1, t2);
					simulate(t1, t2);
					dfs();
					restore_state();
				}
			}
		}
}

void output()
{
	printf("%d\n", (int)result.size());
	for (int i = 0; i < (int)result.size(); ++i)
		printf("%d %d %d %d\n",
			result[i].first.first + 1, result[i].first.second + 1,
			result[i].second.first + 1, result[i].second.second + 1);
}

int main()
{
	read_data();
	dfs();
	output();
	return 0;
}
