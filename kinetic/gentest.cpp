#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int n=500,m=200000;

int main() {
  srand(time(NULL));
  ofstream g("kinetic.in");
  g<<n<<' '<<m<<'\n';
  for(int i=1; i<=n; ++i) {
    g<<rand()%10000<<' '<<rand()%10000<<'\n';
  }
  for(int i=1; i<=m; ++i) {
     g<<rand()%1000000000<<' '<<rand()%1000000000<<' '<<rand()%1000000<<'\n';
  }
  return 0;
}
