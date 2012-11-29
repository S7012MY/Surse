// expresie - varainta 1 			© stelian ciurea
// 100  de puncte cu forma poloneza 
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#define nmax 100001
using namespace std;

char expr[nmax],polo[nmax],stiva[nmax];
int putere[200], apare[200];
short int puteri[nmax];
int i, k, vf, j, ctlit, ctsemn, len, test;
char lit;
char buf[10];

int main()
{
	ctlit = ctsemn = len = vf = i = j = k = 0;
	char numein[20] =  "expresie.in";
	char numeout[20] = "expresie.out";

	ifstream f(numein);
	ofstream g(numeout);

	f>>expr;
	for (i=0;i<(int)strlen(expr);i++)
		if (expr[i]>='a'&&expr[i]<='z')
			apare[(int)expr[i]]=1;

	j = 0;
	vf = 0;
	for (i=0;i<(int)strlen(expr);i++)
	{
		if (expr[i]>='a' && expr[i]<='z')
		{
			polo[j] = expr[i];
			j++;
		}
		if (expr[i] == '(' )
		{
			stiva[vf] = expr[i];
			vf++;
		}
		if (expr[i] == ')' )
		{
			while (stiva[vf-1] != '(') //scoate din stiva pana da de o (
			{
				polo[j] = stiva[vf-1];
				vf--;
				j++;
			}
			vf--; //scoate si ( din stiva
		}
		if (expr[i] == '/')
		{
			while (vf>0 && stiva[vf-1]!='(')
			{
				polo[j] = stiva[vf-1];
				vf--;
				j++;
			}
			stiva[vf] = expr[i];
			vf++;
		}
		if (expr[i] == '*')
		{
			while (vf>0 && stiva[vf-1]!='(')
			{
				polo[j] = stiva[vf-1];
				vf--;
				j++;
			}
			stiva[vf] = expr[i];
			vf++;
		}
	}

	while (vf>0)		//scoate din stiva in poloneza pana goleste stiva
	{
		polo[j] = stiva[vf-1];
		vf--;
		j++;
	}

	//strcpy(polo,expr);
	//g<<polo;
	//cout << polo << endl;

	for (lit = 'a'; lit <= 'z'; lit++)
		putere[(int)lit] = 1;

	len = strlen(polo);
	//cout << len << endl;
	for (i=0; i<len; i++)
	{
		//cout << i << ' ';
		if (polo[i] == '/')
		{
			//determin grupul B:
			ctlit=ctsemn=0;
			for (j=i-1;j>=0;j--)
			{
				if (polo[j]=='/')
					ctsemn++;
				else
					ctlit++;
				if (ctlit == 1 + ctsemn)
					break;
			}
			for (k=j;k<i;k++)
				if (polo[k] != '/')
					putere[(int)polo[k]] = - putere[(int)polo[k]];
		}
	}

	//cout << endl;
	//g << endl;

	for (lit = 'a'; lit <= 'z'; lit++)
		if (apare[(int)lit] == 1)
			if (putere[(int)lit] == 1)
			{
				//cout << lit;
				//g << lit;
			}
	cout << endl;
	//g << endl;
	for (lit = 'a'; lit <= 'z'; lit++)
		if (apare[(int)lit] == 1)
			if (putere[(int)lit] == -1)
			{
				//cout << lit;
				//g << lit;
			}
	cout << endl << endl;

	for (i=0;i<len;i++)
		puteri[i]=1;

	for (i=0; i<len; i++)
		if (polo[i] == '/')
		{
			//determin grupul B:
			ctlit=ctsemn=0;
			for (j=i-1;j>=0;j--)
			{
				if (polo[j]=='/' || polo[j]=='*')
					ctsemn++;
				else
					ctlit++;
				if (ctlit == 1 + ctsemn)
					break;
			}
			for (k=j;k<i;k++)
				if (polo[k] >= 'a' && polo[k] <= 'z')
					puteri[k] = - puteri[k];

		}

	for (lit='a';lit<='z';lit++)
		putere[(int)lit] = 0;

	for (i=0;i<len;i++)
		if (polo[i]>='a' && polo[i]<='z')
			putere[(int)polo[i]] += puteri[i];

	for (lit = 'a'; lit <= 'z'; lit++)
		if (apare[(int)lit] == 1)
			{
				//cout << lit << ' ' << putere[(int)lit] << endl;
				g << lit << ' ' << putere[(int)lit] << endl;
				//g << lit;
			}
	cout << endl;
	f.close();
	g.close();


	return 0;
}
