// Login Anca
# include <fstream>
# include <iostream>
# include <cstdlib>
# define DIM 103
using namespace std;
double P, p[8], q[8], a[2][2][102][102], b[2][2][8][8], pp[4][4], sol;

void read ()
{
	ifstream fin ("pingpong.in");
	for(int i=1;i<=5;++i)
		fin>>p[i];
	for(int i=1;i<=5;++i)
		fin>>q[i];
	fin>>P;
}

void solve ()
{
	double c[2][2];
	c[0][0]=p[1]+(1-p[1])*(1-q[2])*p[3]+(1-p[1])*(1-q[2])*(1-p[3])*(1-q[4])*p[5]+(1-p[1])*(1-q[2])*(1-p[3])*(1-q[4])*(1-p[5])*P;
	c[0][1]=1-c[0][0];
	c[1][0]=(1-q[1])*p[2]+(1-q[1])*(1-p[2])*(1-q[3])*p[4]+(1-q[1])*(1-p[2])*(1-q[3])*(1-p[4])*(1-q[5])*P;
	c[1][1]=1-c[1][0];
	
	a[0][0][0][0]=1;
	a[0][1][0][0]=1;
	a[1][0][0][0]=1;
	a[1][1][0][0]=1;
	
	for(int i=0;i<=11;++i)
		for(int j=0;j<=11;++j)
			for(int w=0;w<2;++w)
				for(int s=0;s<2;++s)
					if (i+j==1)
					{
						if ((w==0 && i==1) || (w==1 && j==1))
							a[s][w][i][j]=c[s][w];
					}	
					else
					{
						if ((i+j)%2==1)
						{
							if (w==0)
							{
								if (i && j!=11)a[s][w][i][j]=	a[1-s][w][i-1][j]*c[s][w]+
																a[1-s][1-w][i-1][j]*c[s][w];
							}
							else
							{
								if (j && i!=11)a[s][w][i][j]=	a[1-s][w][i][j-1]*c[s][w]+	
																a[1-s][1-w][i][j-1]*c[s][w];
							}
						}
						else
						{
							if (w==0)
							{
								if (i && j!=11)a[s][w][i][j]=	a[s][w][i-1][j]*c[s][w]+
																a[s][1-w][i-1][j]*c[s][w];
							}
							else
							{
								if(j && i!=11)a[s][w][i][j]=		a[s][w][i][j-1]*c[s][w]+
																	a[s][1-w][i][j-1]*c[s][w];
							}
						}
						int serv;
						if ((i+j)%4==1 || (i+j)%4==2)
							serv=s;
						else
							serv=1-s;
						if (i==11 && j<10 && w==0)
							pp[serv][w]+=a[s][w][i][j], a[s][w][i][j]=0;
						if (i<10 && j==11 && w==1)
							pp[serv][w]+=a[s][w][i][j], a[s][w][i][j]=0;
					}		

	for(int i=10;i<=100;++i)
		for(int j=10;j<=100;++j)
			for(int s=0;s<2;++s)
				for(int w=0;w<2;++w)
				{
					if (i==10 && j==10)continue;
					if (abs(i-j)>2)continue;
					if (w==0)
					{
						if (abs(j-(i-1))<2)	a[s][w][i][j]=a[1-s][w][i-1][j]*c[s][w]+a[1-s][1-w][i-1][j]*c[s][w];
					}
					else
					{
						if (abs(i-(j-1))<2)a[s][w][i][j]=a[1-s][w][i][j-1]*c[s][w]+a[1-s][1-w][i][j-1]*c[s][w];
					}
					int serv;
					if ((i+j-20)%2==1)
						serv=s;
					else
						serv=1-s;
					if (i-j==2 && w==0)
						pp[serv][w]+=a[s][w][i][j], a[s][w][i][j]=0;
					if (j-i==2 && w==1)
						pp[serv][w]+=a[s][w][i][j], a[s][w][i][j]=0;
				}	
	for(int i=0;i<=3;++i)
		for(int j=0;j<3;++j)
			for(int s=0;s<2;++s)
				for(int w=0;w<2;++w)				
				{
					if (!i&&!j)continue;
					if (i+j==1)
					{
						if (i && !w)b[s][w][i][j]=pp[s][w];
						if (j && w)b[s][w][i][j]=pp[s][w];
					}
					else
					{
						if (w==0)
						{
							if (i)b[s][w][i][j]=b[1-s][w][i-1][j]*pp[s][w]+b[1-s][1-w][i-1][j]*pp[s][w];
						}
						else
						{
							if (j && i<3)b[s][w][i][j]=b[1-s][w][i][j-1]*pp[s][w]+b[1-s][1-w][i][j-1]*pp[s][w];
						}
						if (i==3 && w==0)
						{
							sol+=b[s][w][i][j], b[s][w][i][j]=0;
						}
					}
				}
}

int main ()
{
	read ();
	solve ();
	freopen("pingpong.out", "w", stdout);
	printf("%.3lf", sol/2);
	return 0;
}
