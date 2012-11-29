#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

ifstream fin("spirala3.in");
ofstream fout("spirala3.out");

#define MAXN 52

short n1, sol, n2, xc, yc, m[MAXN][MAXN], dirL[5][MAXN][MAXN];
short pd[MAXN][MAXN][MAXN][MAXN][4];

short nextDir (short curDir) {
	++curDir;
	if (curDir == 4) curDir = 0;
	return curDir;
}

short max (short a, short b) {
	if (a > b)
		return a;
	return b;
}

void evolve(short &x, short &y, short &x2, short &y2, short dir) {
	switch (dir) {
		case 0: {
			--y;
			break;
		}
		case 1: {
			++x2;
			break;
		}
		case 2: {
			++y2;
			break;
		}
		case 3: {
			--x;
			break;
		}
	}
}

void getCurPoshort (short x, short y, short x2, short y2, short dir) {
	switch (dir) {
		case 0: {
			xc = x;
			yc = y;
			break;
		}
		case 1: {
			xc = x2;
			yc = y;
			break;
		}
		case 2: {
			xc = x2;
			yc = y2;
			break;
		}
		case 3: {
			xc = x;
			yc = y2;
			break;
		}
	}
}

short getDist (short x, short y, short x2, short y2, short dir) {
	switch (dir) {
		case 0: {
			return y2 - y + 1;
		}
		case 1: {
			return x2 - x + 1;
		}
		case 2: {
			return y2 - y + 1;
		}
		case 3: {
			return x2 - x + 1;
		}
	}
	return -1;
}

void doInitPD() {
	for (short i = 1; i <= n1; ++i)
		for (short j = 1; j <= n2; ++j)
			for (short k = 0; k < 4; ++k)
				if (m[i][j] == 0)
					pd[i][j][i][j][k] = 1;
}


void initMat(short m[MAXN][MAXN]) {
	for (short i = 0; i <= n1 + 1; ++i)
		for (short j = 0; j <= n2 + 1; ++j)
			m[i][j] = 1;
}

void calcDir() {
	short i, j;
	for (i = 1; i <= n1; ++i)
		for (j = 1; j <= n2; ++j)
			if (m[i][j] != 1)
				dirL[0][i][j] = dirL[0][i][j - 1] + 1;
	for (i = 1; i <= n1; ++i)
		for (j = n2; j > 0; --j)
			if (m[i][j] != 1)
				dirL[2][i][j] = dirL[2][i][j + 1] + 1;
	for (i = n1; i > 0; --i)
		for (j = 1; j <= n2; ++j)
			if (m[i][j] != 1)
				dirL[1][i][j] = dirL[1][i + 1][j] + 1;
	for (i = 1; i <= n1; ++i)
		for (j = 1; j <= n2; ++j)
			if (m[i][j] != 1)
				dirL[3][i][j] = dirL[3][i - 1][j] + 1;
}

void init() {
	calcDir();
	doInitPD();
}

void solve() {
	short i, j, x, y, x2, y2, x1, y1, ndir, d;
	for (i = 0; i < n1; ++i)
	for (j = 0; j < n2; ++j)
		for (x = 1; x + i <= n1; ++x)
		for (y = 1; y + j <= n2; ++y)
			for (d = 0; d < 4; ++d) {
				x1 = x; y1 = y;
				x2 = x + i; y2 = y + j;
				if (pd[x1][y1][x2][y2][d] > 0) {
					evolve(x1, y1, x2, y2, d);
					getCurPoshort(x1, y1, x2, y2, d);
					if (m[xc][yc] == 0) {
						pd[x1][y1][x2][y2][d] = max (pd[x1][y1][x2][y2][d], pd[x][y][x + i][y + j][d] + 1);
						ndir = nextDir(d);
						sol = max(sol, pd[x][y][x + i][y + j][d] + dirL[ndir][xc][yc] );
						if (dirL[ndir][xc][yc] >= getDist (x1, y1, x2, y2, ndir)) {
							pd[x1][y1][x2][y2][ndir] = max (pd[x1][y1][x2][y2][ndir], pd[x][y][x + i][y + j][d] + getDist (x1, y1, x2, y2, ndir) );
						}
					}
				}
			}
}

void reset() {
	memset(pd, 0, sizeof(pd));
	memset(dirL, 0, sizeof(dirL));
}

void reverse() {
	short i, j, newM[MAXN][MAXN];
	for (i = 0; i <= n1 + 1; ++i)
		for (j = 0; j <= n2 + 1; ++j)
			newM[i][j] = m[i][n2 - j + 1];
	memcpy(m, newM, sizeof(newM));
}

void read() {
	fin >> n1 >> n2;
	initMat(m);
	for (short i = 1; i <= n1; ++i)
		for (short j = 1; j <= n2; ++j)
			fin >> m[i][j];
}

int main() {
	read();
	init();
	solve();
	reverse();
	reset();
	init();
	solve();
	fout << sol << "\n";
	return 0;
}
