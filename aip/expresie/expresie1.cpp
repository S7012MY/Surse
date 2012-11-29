/*
   Sursa: Eugen Nodea
   Rez. forma poloneza - 
  */
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

char expr[20001],polo[20001],stiva[20001];
int putere[300];
bool apare[300];
int i, vf, j, semn, poz;
char lit;
string st[20001];


ifstream f("expresie.in");
ofstream g("expresie.out");

int main()
{
    f>>expr;

    for (i=0; i<(int)strlen(expr); i++)
        if (expr[i]>='a' && expr[i]<='z')
            apare[(int)expr[i]]=1;

    j = 0;
    vf = 0;
    for (i=0; i<(int)strlen(expr); i++)
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
        if (expr[i] == '/' || expr[i] == '*')
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

    //g<<polo << '\n';

    vf = 0;
    for (i=0; i<(int)strlen(polo); i++)
        if (polo[i] == '*')
        {
            string x="",y="";
            poz=st[vf].find('/');
            if (poz!=-1)
            {
                x=st[vf].substr(0,st[vf].find('/'));
                y=st[vf].substr(st[vf].find('/')+1,st[vf].size());
            }
            else
                x=st[vf].substr(0,st[vf].size());

            vf--;
            poz=st[vf].find('/');
            if (poz!=-1)
            {
                x+=st[vf].substr(0,st[vf].find('/'));
                y+=st[vf].substr(st[vf].find('/')+1,st[vf].size());
            }
            else
                x+=st[vf].substr(0,st[vf].size());
            st[vf]= x;
            if (y!="")
                st[vf]+= '/' + y;
        }
        else if (polo[i] == '/')
        {
            string x="",y="";
            poz=st[vf].find('/');
            if (poz!=-1)
            {
                y=st[vf].substr(0,st[vf].find('/'));
                x=st[vf].substr(st[vf].find('/')+1,st[vf].size());
            }
            else
                y=st[vf].substr(0,st[vf].size());

            vf--;
            poz=st[vf].find('/');
            if (poz!=-1)
            {
                x+=st[vf].substr(0,st[vf].find('/'));
                y+=st[vf].substr(st[vf].find('/')+1,st[vf].size());
            }
            else
                x+=st[vf].substr(0,st[vf].size());
            st[vf]= x + '/' + y;
        }
        else
            st[++vf]=polo[i];

    semn=1;
    for (j=0; j<st[1].size(); j++)
        if (st[1][j]=='/') semn=-1;
        else if (semn==1) putere[(int)st[1][j]]++;
        else putere[(int)st[1][j]]--;

    for (lit = 'a'; lit <= 'z'; lit++)
        if (apare[(int)lit])
            g << lit << ' ' << putere[int(lit)] << '\n';

    return 0;
}
