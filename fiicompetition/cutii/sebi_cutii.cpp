#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream f("cutii.in");

bool cmp(vector<int>a, vector<int>b)
{	return a[1] < b[1];
}

int M, N;

vector<int>box[60];
int boxx[60];

int sol_ans;
int sol[60];

void update_sol(int K)
{	sol_ans = K;
	for(int i = 1; i <= K; i++)
		sol[i] = boxx[i];
}

bool match(int a, int b)
{	for(int i = 1; i < box[a].size(); i++)
		if(box[a][i] >= box[b][i]) return 0;
	return 1;
}

void back(int k)
{	int i, j;
	
	for(i = boxx[k - 1] + 1; i <= M; i++)
	{	if(match(boxx[k - 1], i))
		{	boxx[k] = i;
			if(k > sol_ans)
				update_sol(k);
			back(k + 1);
		}
	}
}

bool read()
{	int i, j, k;
	
	if(!(f>>M>>N))
		return 0;
	for(i = 1; i <= M; i++)
	{	box[i].clear();
		box[i].push_back(i);
		for(j = 1; j <= N; j++) 
		{	f>>k;
			box[i].push_back(k);
		}
		sort(box[i].begin() + 1, box[i].end());
	}
	
	sort(box + 1, box + M + 1, cmp);
	return 1;
}
	

int main()
{	int i, j, k,nrc;
	ifstream g("cutii.out");
	
	while(read())
	{	
		sol_ans = 0;
		back(1);
		g>>nrc;
		if(nrc!=sol_ans) {
			cout<<nrc<<' '<<sol_ans<<" numar gresit";
			cout.flush();
			while(1);
		}else cout<<"OK!";
		for(int i=1; i<=sol_ans; ++i) g>>nrc;
	}
	
	f.close();
	g.close();
	return 0;
}
