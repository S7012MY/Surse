//#include <vector>
//#include <list>
//#include <map>
//#include <set>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <sstream>
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <cctype>
//#include <string>
//#include <cstring>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//const int maxnode=200000+5;
//const int maxedge=1000000+5;
//
//int nleft,nright,nedge;
//int head[maxnode],point[maxedge],nxt[maxedge];
//int p1[maxnode],p2[maxnode];
//bool visited[maxnode];
//
//void clear()
//{
//	for (int i=0;i<nleft;i++) p1[i]=-1;
//	for (int i=0;i<nright;i++) p2[i]=-1;
//}
//void init(int _nleft,int _nright)
//{
//	nleft=_nleft;
//	nright=_nright;
//	nedge=0;
//	for (int i=0;i<nleft;i++) head[i]=-1;
//	clear();
//}
//void addedge(int u,int v)
//{
//	point[nedge]=v,nxt[nedge]=head[u],head[u]=(nedge++);
//}
//bool find_path(int v)
//{
//	for (int k=head[v];k>=0;k=nxt[k])
//	{
//		int p=point[k];
//		if (!visited[p])
//		{
//			visited[p]=true;
//			if (p2[p]<0 || find_path(p2[p]))
//			{
//				p1[v]=p;
//				p2[p]=v;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//int doMatch()
//{
//	for (int i=0;i<nleft;i++)
//		for (int k=head[i];p1[i]<0 && k>=0;k=nxt[k])
//			if (p2[point[k]]<0)
//			{
//				p1[i]=point[k];
//				p2[point[k]]=i;
//			}
//	for (int i=0;i<nleft;i++) if (p1[i]<0)
//	{
//		for (int k=0;k<nright;k++) visited[k]=false;
//		find_path(i);
//	}
//	int result=0;
//	for (int i=0;i<nleft;i++) if (p1[i]>=0) result++;
//	return result;
//}
//
//const int maxn=1000+5;
//const int maxm=100+5;
//
//int n,m;
//int A[maxn][maxm];
//
//bool isUpper(int x,int y)
//{
//	for (int i=0;i<m;i++)
//		if (A[x][i]<=A[y][i])
//			return false;
//	return true;
//}
//
//int main()
//{
//	freopen("album.in","r",stdin);freopen("album.out","w",stdout);
//	int testcase=1;
//	for (int caseId=1;caseId<=testcase;caseId++)
//	{
//		scanf("%d%d",&n,&m);
//		for (int i=0;i<n;i++) {
//		  for (int j=0;j<m;j++) scanf("%d",&A[i][j]);
//		  sort(A[i],A[i]+m);
//		}
//		init(n,n);
//		for (int i=0;i<n;i++) for (int j=0;j<n;j++)
//			if (isUpper(i,j))
//				addedge(i,j);
//		int c=doMatch();
//		printf("%d\n",n-c);
//	}
//	return 0;
//}
