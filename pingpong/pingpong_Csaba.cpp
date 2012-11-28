//Code by Patcas Csaba
//Time complexity: O(1) :)
//Space complexity: O(1)
//Method: Dynamic programmming
//Implementation time: 3 hours

#include <vector>
#include <string> 
#include <set> 
#include <map> 
#include <queue> 
#include <bitset> 
#include <stack>
#include <list>

#include <numeric> 
#include <algorithm> 

#include <cstdio>
#include <fstream>
#include <iostream> 
#include <sstream> 
#include <iomanip>

#include <cctype>
#include <cmath> 
#include <ctime>
#include <cassert>

using namespace std;

#define LL long long
#define PII pair <int, int>
#define VB vector <bool>
#define VI vector <int>
#define VD vector <double>
#define VS vector <string>
#define VPII vector <pair <int, int> >
#define VVI vector < VI >
#define VVB vector < VB >

#define FORN(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FORI(it, X) for(__typeof((X).begin()) it = (X).begin(); it !=(X).end(); ++it) 
#define REPEAT do{ 
#define UNTIL(x) }while(!(x)); 

#define SZ size()
#define BG begin() 
#define EN end() 
#define CL clear()
#define X first
#define Y second
#define RS resize
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()

#define IN_FILE "pingpong.in"
#define OUT_FILE "pingpong.out"

ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);

double p1, p2, p3, p4, p5, q1, q2, q3, q4, q5, p, p11, p12, p21, p22, prob1, prob2;
vector <VD> dp(1001, VD(1001));

double SolveSet(int firstServe)
{
	FORN(i, 1001)
		FORN(j, 1001) dp[i][j] = 0;
	dp[0][0] = 1;
	FOR(i, 0, 10)
		FOR(j, 0, 10)
		{
			if (i == 10 && j == 10) continue;
			int nowServe = ((i + j) % 4 < 2) ? firstServe : 3 - firstServe;
			if (nowServe == 1)
			{
				dp[i + 1][j] += dp[i][j] * p11;
				dp[i][j + 1] += dp[i][j] * p12;
			}
			else
			{
				dp[i + 1][j] += dp[i][j] * p21;
				dp[i][j + 1] += dp[i][j] * p22;
			}
		}
	FOR(i, 10, 998)
		if (firstServe == 1)
		{
			dp[i + 1][i] += p11 * dp[i][i];
			dp[i][i + 1] += p12 * dp[i][i];

			dp[i + 2][i] += p21 * dp[i + 1][i];
			dp[i][i + 2] += p22 * dp[i][i + 1];

			dp[i + 1][i + 1] += p21 * dp[i][i + 1];
			dp[i + 1][i + 1] += p22 * dp[i + 1][i];
		}
		else
		{
			dp[i + 1][i] += p21 * dp[i][i];
			dp[i][i + 1] += p22 * dp[i][i];

			dp[i + 2][i] += p11 * dp[i + 1][i];
			dp[i][i + 2] += p12 * dp[i][i + 1];

			dp[i + 1][i + 1] += p11 * dp[i][i + 1];
			dp[i + 1][i + 1] += p12 * dp[i + 1][i];
		}
	double ans = 0;
	FOR(i, 0, 9) ans += dp[11][i];
	FOR(i, 12, 1000) ans += dp[i][i - 2];
	return ans;
}

double SolveMatch(int firstServe)
{
	FORN(i, 4)
		FORN(j, 4) dp[i][j] = 0;

	dp[0][0] = 1;
	FOR(i, 0, 2)
		FOR(j, 0, 2)
		{
			int nowServe = ((i + j) % 2) ? 3 - firstServe : firstServe;
			if (nowServe == 1)
			{
				dp[i + 1][j] += prob1 * dp[i][j];
				dp[i][j + 1] += (1 - prob1) * dp[i][j];
			}
			else
			{
				dp[i + 1][j] += prob2 * dp[i][j];
				dp[i][j + 1] += (1 - prob2) * dp[i][j];
			}
		}

	double ans = 0;
	FOR(i, 0, 2) ans += dp[3][i];
	return ans;
}

int main()
{
	//Read data
	fin >> p1 >> p2 >> p3 >> p4 >> p5 >> q1 >> q2 >> q3 >> q4 >> q5 >> p;
	fin.close();

	//Solve
	p11 = p1 + (1 - p1) * (1 - q2) * p3 + (1 - p1) * (1 - q2) * (1 - p3) * (1 - q4) * p5 + (1 - p1) * (1 - q2) * (1 - p3) * (1 - q4) * (1 - p5) * p;
	p12 = (1 - p1) * q2 + (1 - p1) * (1 - q2) * (1 - p3) * q4 + (1 - p1) * (1 - q2) * (1 - p3) * (1 - q4) * (1 - p5) * (1 - p);
	p21 = (1 - q1) * p2 + (1 - q1) * (1 - p2) * (1 - q3) * p4 + (1 - q1) * (1 - p2) * (1 - q3) * (1 - p4) * (1 - q5) * p;
	p22 = q1 + (1 - q1) * (1 - p2) * q3 + (1 - q1) * (1 - p2) * (1 - q3) * (1 - p4) * q5 + (1 - q1) * (1 - p2) * (1 - q3) * (1 - p4) * (1 - q5) * (1 - p);
	
	prob1 = SolveSet(1);
	prob2 = SolveSet(2);
	//These two seem to be always equal, I have no f* idea why...

	//Write data
	double sol1 = SolveMatch(1);
	double sol2 = SolveMatch(2);
	//Same stuff...
	double solution = (sol1 + sol2) * 0.5;

	fout << fixed << setprecision(3) << solution;
	fout.close();

	return 0;
}
