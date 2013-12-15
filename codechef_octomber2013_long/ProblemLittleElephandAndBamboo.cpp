#include<iostream>
#include <fstream>
#include <cstdio>
#include<cmath>
using namespace std;

#define MaxN 100

int T,N,Sol;
int A[MaxN],B[MaxN];

void citire(void)
{
    cin >> N;
    for(int i=1;i<=N;i++)
        cin >> A[i];
    for(int i=1;i<=N;i++)
        cin >> B[i];
}

inline int minFromVector(void)
{
    int Min = (1<<29), Poz = 0;

    for(int i=1;i<=N;i++)
        if(Min > A[i])
            Min = A[i], Poz = i;

    return Poz;
}

inline int allZero(void)
{
    for(int i=1;i<=N;i++)
        if(A[i])
            return 0;

    return 1;
}

inline void afisare(void)
{
    for(int i=1;i<=N;i++)
        cout << A[i] << " ";

    cout << "\n";
}

inline int nuSeMaiPoate(void)
{
    int nr = 0;

    for(int i=1;i<=N;i++)
        nr += (A[i] < 0);

    return (nr > 1);
}

inline int abs(int a)
{
    if(a < 0)
        return -a;
    return a;
}

void Rezolvare(void)
{
    int Poz;

    if(N == 1)
    {
        if(B[1] <= A[1])
            Sol = A[1]-B[1];
        else
            Sol = -1;

        return ;
    }
    else if(N == 2)
    {
        if(B[1] - A[1] + B[2] - A[2] == 0)
            Sol = abs(B[1] - A[1]);
        else
            Sol = -1;

        return ;
    }

    for(int i=1;i<=N;i++)
        A[i] = B[i] - A[i];

    if(allZero())
    {
        Sol = 0;
        return ;
    }

    for(Sol = 1;;++Sol)
    {
        Poz = minFromVector();

        ++ A[Poz];
        for(int j=1;j<=N;j++)
            if(j != Poz)
                -- A[j];

        if(nuSeMaiPoate())
        {
            Sol = -1;
            return ;
        }

        if(allZero())
            return ;
    }
}

int main()
{
  freopen("input.txt","r",stdin);
    cin >> T;
    ifstream f("output.txt");
    for(int i=1;i<=T;i++)
    {
        citire();
        Rezolvare();
        int rm;
        f>>rm;
        if(rm!=Sol) {
          cerr<<"Gresit"<<rm<<' '<<Sol;
          while(1);
        }else cerr<<"corect\n"<<Sol<<'\n';
    }
}
