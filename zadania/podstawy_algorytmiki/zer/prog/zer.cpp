#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define d(x) cout << #x << "=" << x;
#define de(x) cout << #x << "=" << x << endl;

struct wierzcholek {
	int maks;
	int lewe_zera;
	int prawe_zera;
	int poziom;
};

int n, k,c;
int dwojka=1;
wierzcholek drzewo[1100000];
string zera_i_jedynki;

void max_dfs(int ob)
{
	if (ob*2 < dwojka)
	{
		max_dfs(ob * 2);
		max_dfs(ob * 2 + 1);
	}
	drzewo[ob].poziom = drzewo[ob * 2].poziom * 2;
	drzewo[ob].lewe_zera = drzewo[ob * 2].lewe_zera;
	drzewo[ob].prawe_zera = drzewo[ob * 2 + 1].prawe_zera;
	if (drzewo[ob * 2].lewe_zera == drzewo[ob * 2].prawe_zera && drzewo[ob*2].lewe_zera==drzewo[ob*2].poziom)
		drzewo[ob].lewe_zera = drzewo[ob * 2].prawe_zera + drzewo[ob * 2 + 1].lewe_zera;
	if (drzewo[ob * 2 + 1].lewe_zera == drzewo[ob * 2 + 1].prawe_zera && drzewo[ob*2+1].prawe_zera==drzewo[ob*2+1].poziom)
		drzewo[ob].prawe_zera = drzewo[ob * 2 + 1].lewe_zera + drzewo[ob * 2].prawe_zera;
	drzewo[ob].maks = max(drzewo[ob * 2].maks, drzewo[ob * 2 + 1].maks);
	drzewo[ob].maks = max(drzewo[ob].maks, drzewo[ob * 2].prawe_zera + drzewo[ob * 2 + 1].lewe_zera);
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> zera_i_jedynki;
	while (dwojka < n)
		dwojka *= 2;
	for (int i = 0; i <= dwojka * 2; i++)
		drzewo[i].poziom = 1;
	for (int i = 0; i < n; i++)
	{
		if (zera_i_jedynki[i] == '1')
		{
			drzewo[dwojka + i].maks = 0;
			drzewo[dwojka + i].lewe_zera = 0;
			drzewo[dwojka + i].prawe_zera = 0;
		}
		else
		{
			drzewo[dwojka + i].maks = 1;
			drzewo[dwojka + i].lewe_zera = 1;
			drzewo[dwojka + i].prawe_zera = 1;
		}
	}
	max_dfs(1);
	/*for (int i = 1; i < dwojka*2; i++)
	{
		de(i);
		de(drzewo[i].maks);
		de(drzewo[i].lewe_zera);
		de(drzewo[i].prawe_zera);
	}*/
	//cout << drzewo[1].maks << '\n';
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		int cur = (dwojka + c - 1)/2;
		if (zera_i_jedynki[c - 1] == '0')
		{
			zera_i_jedynki[c - 1] = '1';
			drzewo[dwojka + c-1].maks = 0;
			drzewo[dwojka + c-1].lewe_zera = 0;
			drzewo[dwojka + c-1].prawe_zera = 0;
		}
		else
		{
			zera_i_jedynki[c - 1] = '0';
			drzewo[dwojka + c - 1].maks = 1;
			drzewo[dwojka + c - 1].lewe_zera = 1;
			drzewo[dwojka + c - 1].prawe_zera = 1;
		}
		while (cur != 1)
		{
			drzewo[cur].lewe_zera = drzewo[cur * 2].lewe_zera;
			drzewo[cur].prawe_zera = drzewo[cur * 2 + 1].prawe_zera;
			if (drzewo[cur * 2].lewe_zera == drzewo[cur * 2].prawe_zera && drzewo[cur * 2].lewe_zera == drzewo[cur*2].poziom)
				drzewo[cur].lewe_zera = drzewo[cur * 2].prawe_zera + drzewo[cur * 2 + 1].lewe_zera;
			if (drzewo[cur * 2 + 1].lewe_zera == drzewo[cur * 2 + 1].prawe_zera && drzewo[cur * 2 + 1].prawe_zera ==drzewo[cur*2+1].poziom)
				drzewo[cur].prawe_zera = drzewo[cur * 2 + 1].lewe_zera + drzewo[cur * 2].prawe_zera;
			drzewo[cur].maks = max(drzewo[cur * 2].maks, drzewo[cur * 2 + 1].maks);
			drzewo[cur].maks = max(drzewo[cur].maks, drzewo[cur * 2].prawe_zera + drzewo[cur * 2 + 1].lewe_zera);
			cur /= 2;
		}
		drzewo[cur].lewe_zera = drzewo[cur * 2].lewe_zera;
		drzewo[cur].prawe_zera = drzewo[cur * 2 + 1].prawe_zera;
		if (drzewo[cur * 2].lewe_zera == drzewo[cur * 2].prawe_zera && drzewo[cur * 2].lewe_zera != 0)
			drzewo[cur].lewe_zera = drzewo[cur * 2].prawe_zera + drzewo[cur * 2 + 1].lewe_zera;
		if (drzewo[cur * 2 + 1].lewe_zera == drzewo[cur * 2 + 1].prawe_zera && drzewo[cur * 2 + 1].prawe_zera != 0)
			drzewo[cur].prawe_zera = drzewo[cur * 2 + 1].lewe_zera + drzewo[cur * 2].prawe_zera;
		drzewo[cur].maks = max(drzewo[cur * 2].maks, drzewo[cur * 2 + 1].maks);
		drzewo[cur].maks = max(drzewo[cur].maks, drzewo[cur * 2].prawe_zera + drzewo[cur * 2 + 1].lewe_zera);
		cout << drzewo[1].maks << '\n';
	}
	return 0;
}
