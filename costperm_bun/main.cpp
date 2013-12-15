#include <cstdio>
#include <algorithm>
using namespace std;

int v[100005];

int main () {

        freopen ("costperm.in", "r", stdin);
        freopen ("costperm.out", "w", stdout);
        int n, i;
        long long cost=0;
        bool schimb= 1;
        scanf ("%d", &n);
        for (i = 1; i <= n; ++ i)
                scanf ("%d", &v[i]);

        while (schimb) {
                schimb = 0;
                for (i = 1; i < n; ++ i)
                        if (v [i + 1] < v [i]) {
                                schimb = 1;
                                swap (v [i + 1], v [i]);
                                cost += v [i];
                        }
        }
        printf ("%lld\n", cost);
        return 0;
}
