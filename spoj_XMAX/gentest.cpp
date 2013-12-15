#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int n,x;

int main() {
  ofstream g("date.in");
  srand(time(NULL));
  n=rand()%20+1; g<<n<<'\n';
  for(int i=1; i<=n; ++i) g<<rand()%100+1<<' ';

}
