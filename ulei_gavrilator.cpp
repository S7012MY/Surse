#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<tr1/unordered_map>
#include<algorithm>

using namespace std;
using namespace tr1;
int n,m;

#ifdef DEBUG
#define INSTRUMENT_EULER
#define PRINT_E
#endif

struct str
{
	int x,y,t;
	int gx,gy;

	str()
		{
			x=y=t=0;
		}

	str (int xx,int yy,int tt)
		{
			x=xx;
			y=yy;
			t=tt;
		}

	int pair_for (int a)
		{
			if(a==x)
				return gx;
			return gy;
		}

	void set_pair (int pair,int n)
		{
			if(n==x)
				gx=pair;
			else
				gy=pair;
		}
}e[100005];

vector<int> v[15005];

struct gr
{
	int x,y;

	gr()
		{
			x=y=0;
		}

	gr (int xx,int yy)
		{
			x=xx;
			y=yy;
		}

	int other (int z)
		{
			return x+y-z;
		}
}ww[200005];

bool u[200005];

vector<int> w[15005];
vector<int>::iterator its[15005];
int ne;

void add_edge (int a,int b,int t)
{
	v[a].push_back (ne);
	v[b].push_back (ne);
	e[ne++]=str (a,b,t);
}

inline int f (int n,int m)
{
	return e[m].x+e[m].y-n;
}

inline bool works (int e1,int e2,int e3,int e4)
{
	if(e[e1].t==e[e3].t||e[e2].t==e[e4].t)
		return false;
	return true;
}

/*
void print_w()
{
	for(int i=1;i<=n;i++){
		fprintf (stderr,"w[%d] contains: ",i);
		for(map<int,int>::iterator it=w[i].begin();it!=w[i].end();it++)
			fprintf (stderr,"%d={%d,%d} ",it->first,it->second.x,it->second.y);
		fprintf (stderr,"\n");
	}
}
*/

void print_v (int i)
{
	for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
		printf ("%d ",*it);
	puts ("");
}

void skipdeld (int i)
{
	while(its[i]!=w[i].end() && u[*its[i]])
		its[i]++;
}

//pair == first pair [ == exit pair ]
//last == entry edge
void euler(int pair, int last, int i)
{
#ifdef INSTRUMENT_EULER
	fprintf (stderr,"Entered euler(pair=%d,last=%d,i=%d)\n",pair,last,i);
#endif
#ifdef PRINT_W
//	print_w();
#endif

	//entry edge and exit edge
	int e1=last;//entry edge
	int e2;

	int current_pair=e[e1].pair_for (i);//entry pair == exit pair
	//set<int>::iterator it=w[i].find (current_pair);
	e2=ww[current_pair].other (e1);//exit edge

/*	if(it==w[i].end()){
		fprintf (stderr,"WHOOPS! Could not find %d in map!\n",current_pair);
		exit (42);
	}
*/

	u[current_pair]=1;

	if(pair!=current_pair)
		euler (pair,e2,f (i,e2));
	//else we have reached the destination pair

	//check for other pairs
	//for(map<int,gr>::iterator it=w[i].begin();it!=w[i].end();it++){
	skipdeld (i);
	while(its[i]!=w[i].end()){
		const vector<int>::iterator it=its[i];

		//new edges
		int e3=ww[*it].x;
		int e4=ww[*it].y;

		int next_edge;
		if(works (e1,e2,e3,e4))//check for collisions
			next_edge=e3;
		else//if we have a collision we reverse e3 and e4
			next_edge=e4;

		int dest_node=f (i,next_edge);
		int new_pair=e[next_edge].pair_for (i);
		its[i]++;
		skipdeld (i);
		euler (new_pair,next_edge,dest_node);
	}

	printf ("%d ",i);
//	fflush (stdout);
#ifdef INSTRUMENT_EULER
	fprintf (stderr,"Exited euler(pair=%d,last=%d,i=%d)\n",pair,last,i);	
#endif
}

struct sss
{
	int t,m,c;//type, node, count

	sss()
		{
			t=m=c=0;
		}

	sss (int tt,int mm,int cc)
		{
			t=tt;
			m=mm;
			c=cc;
		}

	bool operator<(const sss s)const
		{
			if(c<s.c)
				return true;
			else if(c>s.c)
				return false;
			return t<s.t;
		}
};

int gn=0;
unordered_map<int,int> fv;

void setg (int x)
{

//	for(int i=0;i<15005;i++)
//		fv[i].clear();
	fv.clear();

	for(vector<int>::iterator it=v[x].begin();it!=v[x].end();it++){
		int key=e[*it].t;
		if(fv.count (key))
			fv[key]++;
		else
			fv.insert (make_pair (key,1));
	}

	vector<sss> vec;
	for(vector<int>::iterator it=v[x].begin();it!=v[x].end();it++)
		vec.push_back (sss (e[*it].t,*it,fv[e[*it].t]));
	sort (vec.begin(),vec.end());

	int m=vec.size()/2;
	for(int i=0;i<m;i++){
		sss s1=vec[i];
		sss s2=vec[i+m];
		int e1=s1.m;
		int e2=s2.m;

		if(e[e1].t==e[e2].t)
			abort();

		e[e1].set_pair (gn,x);
		e[e2].set_pair (gn,x);
		ww[gn]=gr (e1,e2);
		w[x].push_back (gn);

		gn++;
	}
}

int main()
{
	freopen ("ulei.in","r",stdin);
#ifndef DEBUG
	freopen ("ulei.out","w",stdout);
#endif
	int ttt;
	scanf ("%d",&ttt);
	while(ttt--){
		ne=0;
		memset (u,0,sizeof(u));
		//memset (ww,0,sizeof(ww));
		//memset (e,0,sizeof(e));
//		for(int i=0;i<100005;i++)
//			e[i]=str();
		for(int i=0;i<15005;i++){
			v[i].clear();
			w[i].clear();
		}
		scanf ("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int x,y,t;
			scanf ("%d%d%d",&x,&y,&t);
			add_edge (x,y,t);
		}

		gn=0;
		for(int i=1;i<=n;i++){
			setg(i);
			its[i]=w[i].begin();
		}

#ifdef PRINT_E
		for(int i=0;i<ne;i++)
			fprintf (stderr,"e[%d]={%d,%d} ",i,e[i].x,e[i].y);
		fprintf (stderr,"\n");
#endif

#ifdef PRINT_W
		print_w();
#endif

		while(its[1]!=w[1].end()){
			skipdeld (1);
			int edge=ww[*its[1]].x;
			int node=f (1,edge);
			int pair=e[edge].pair_for (1);
			its[1]++;
			skipdeld (1);
			euler (pair,edge,node);
		}

		puts ("1");
	}
}

