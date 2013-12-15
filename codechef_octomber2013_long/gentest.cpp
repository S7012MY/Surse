#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int n;

int main() {
  ofstream g("input.txt");
  srand(time(NULL));
  g<<"2\n";
  n=rand()%50+1;
  g<<n<<'\n';
  for(int i=1; i<=n; ++i) g<<rand()%50+1<<' '; g<<'\n';
  for(int i=1; i<=n; ++i) g<<rand()%50+1<<' '; g<<'\n';
  n=rand()%50+1;
  g<<n<<'\n';
  for(int i=1; i<=n; ++i) g<<rand()%50+1<<' '; g<<'\n';
  for(int i=1; i<=n; ++i) g<<rand()%50+1<<' '; g<<'\n';

}
