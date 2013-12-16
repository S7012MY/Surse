#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n;
long long nr;
char s[30];

int main()
{
    f >> n;
    for (int i = 1; i <= n; i++) {
        f >> (s);
        f >> nr;

        int baza = strlen(s);
        long long p = baza;

        int l = 0;
        int x = 1;
        while (nr - x > 0) {
            nr -= x;
            x *= baza;
            l++;
        }
        x /= baza;

        for (int i = 1; i <= l; i++) {
            int l1 = 0;
            while (nr - x > 0) {
                 nr -= x;
                 l1++;
            }
            cout << x << ' ' << nr << endl;
            cout << s[l1];
            x /= baza;


        }
        cout << '\n';
    }

    return 0;
}
