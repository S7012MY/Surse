#include <iostream>
#include <fstream>
using namespace std;

#define MAXN 16
#define MAXM 250

ifstream f("ture.in");
ofstream g("ture.out");

int n, m, k, p;
int a[MAXM][1 << MAXN]; // a[j][i] = nr de posibilitati de a plasa pe primele j linii si sa le am ocupate coloanele din starea i;
int board[MAXN][MAXM];

void readNormal() {
  for (int i = 1; i <= p; i++) {
    int x, y;
    f >> x >> y;
    board[x - 1][y - 1] = 1;
  }
}

void readInvers() {
  for (int i = 1; i <= p; i++) {
    int x, y;
    f >> x >> y;
    board[y - 1][x - 1] = 1;
  }
}

int main()
{
    f >> n >> m >> k >> p;

    if (k > min(m, n)) {
      cout << 0 << '\n';
      return 0;
    }

    if (n <= m) {
      readNormal();
    } else {
      readInvers();
      swap(n, m);
    }

    for (int j = 0; j < m; j++) {
      a[j][0] = 1;
    }
    for (int i = 1; i < (1 << n); i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
          if (board[j][k] == 1) {
            continue;
          }
          if (i & (1 << k) == 0) {
            continue;
          }
          a[j][i] += a[j][i & (1 << k)];
        }
      }
    }

    for (int i = 0; i < (1 << n); i++) {
      cout << i << ": ";
      for (int j = 0; j < m; j++) {
        cout << a[j][i] << ' ';
      }
      cout << endl;
    }
    cout << endl;

    int sol = 0;
    for (int i = 0; i < (1 << n); i++) {
      int nrb = 0;
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          nrb++;
        }
      }

      if (nrb != k) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        sol += a[j][i];
      }
    }

    g << sol << '\n';

    return 0;
}
