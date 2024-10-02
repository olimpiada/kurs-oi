#include <iostream>
using namespace std;

int main()
{
  int k;
  cin >> k;
  int x = 0;
  int potega = 1;
  for (int i = 0; i <= k; i++)
  {
    int p_i;
    cin >> p_i;
    x += p_i * potega;
    potega *= 2;
  }
  cout << x + 1 << endl;
  return 0;
}
