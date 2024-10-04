#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int dl = 7;
  int kn = 7;
  int N = 77777;
  int K = 777;

  ifstream f("file2.txt");
  long long a[N];
  for(int i=0;i<N;i++) f >> a[i];

  long long pref_ost[kn][dl];
  for (int x=0; x<kn; x++) 
  {
    for (int y=0; y<dl; y++) 
    {
      pref_ost[x][y] = 0;
    }
  }

  for (int x=K; x<N-K*(kn-2); x++) 
  { 
    int ost = a[x-K] % dl;
    pref_ost[0][ost] = max(a[x-K],pref_ost[0][ost]);
    for (int y=0; y<kn-1; y++)
    {
      for (int z=0; z<dl; z++)
      {
        long long sm = pref_ost[y][z]+a[x+y*K];
        long long ost2 = sm % dl;
        pref_ost[y+1][ost2] = max(sm,pref_ost[y+1][ost2]);
      }
    }
  }

  cout << pref_ost[kn-1][0];


  return 0;
}
