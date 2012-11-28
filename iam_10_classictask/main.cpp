#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>
#define LL unsigned long long
using namespace std;

const int MaxC = 50000;
const int Base = 10;

class Huge {
	public: int n[MaxC];

	Huge () {
		memset (n, 0, sizeof (n));
	}

	Huge(int A) {
	    *this = A;
	}

    inline void operator = (Huge A) {
		memcpy (n, A.n, sizeof (A.n));
	}

	inline void operator = (LL A) {
		memset (n, 0, sizeof (n));
		for (; A > 0; A /= Base)
            n[++n[0]] = A%Base;
	}

	inline LL operator% (LL B) const {
        LL T = 0;
        for (int i = n[0]; i > 0; --i)
            T = (T*10+n[i])%B;
        return T;
    }

	inline Huge operator* (Huge A) const {
		Huge C;	int i, j; LL T;
		for (i = 1; i <= n[0]; ++i) {
			for (T = 0, j = 1; j <= A.n[0] || T; ++j, T /= Base)
				C.n[i+j-1] = (T += (C.n[i+j-1]+1LL*n[i]*A.n[j]))%Base;
			if (i+j-2 > C.n[0])
                C.n[0] = i+j-2;
		}
		return C;
	}
};

Huge A, S;
LL B, Mod;

inline Huge Pow(Huge X, LL P) {
    Huge R = 1;
    while (P > 0) {
        if (P%2)
            R = (X*R)%Mod, --P;
        else
            X = (X*X)%Mod, P /= 2;
    }
    return R;
}

int main() {
    ifstream fin("classictask.in");
    ofstream fout("classictask.out");
    LL a;
    fin >> a >> B >> Mod;
    //cout<<a<<' '<<B<<' '<<Mod;
    A = a;
    S = Pow(A, B);
    if (S.n[0] == 0)
        S.n[0] = 1;
    for (int i = S.n[0]; i > 0; --i)
        fout << S.n[i];
    return 0;
}

