#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define x first
#define y second

typedef pair<double, double> point;

ifstream f("lgput.in");
#define f cin

int n; double r;
point a[105];

int main() {
  f >> n;
  f >> r;
  for (int i = 1; i <= n; i++) {
    f >> a[i].x >> a[i].y;
  }

  double sol;
  a[n + 1] = a[1];
  for (int i = 1; i <= n; i++) {
    sol += sqrt((a[i].x - a[i + 1].x) * (a[i].x - a[i + 1].x) + (a[i].y - a[i + 1].y) * (a[i].y - a[i + 1].y));
  }

  cout << fixed << setprecision(2) << sol + 2 * 3.14159265359 * r;

  return 0;
}
