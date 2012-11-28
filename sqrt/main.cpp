/*
Colectia personala de operatii pe numere mari - C++ ( classes )
Implementate de Robert Simoiu
Incluzand extragerea radacinii patrate cu un numar finit de zecimale
*/

# include <cmath>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std ;

char rez[100000];

/*
precizare :
1. Daca vreti sa faceti a = b + c, in loc de a += b , trebuie pus in loc de void operator += ( ... )
Mare operator + ( ... ) , si sa returnati un vector Mare ( exemplu prima functie, Mare operator + ( Mare& ) )
2. Base inseamna baza si nbase numarul maxim de cifre al unui numar din baza base
*/

# define MAX 100 // * nbase = numarul de cifre
# define verf( X, i ) ( i <= X[0] ? X[i] : 0 )
# define A ( *this )

class Mare : protected vector < int > {
    static const int base = 1000000000, nbase = 9 ;
public :
    Mare ( ) ;
    Mare ( int ) ;

    void operator   = ( char* ) ;
    void operator  += ( Mare& ) ;
    void operator  *= ( int ) ;
    void operator  *= ( Mare& ) ;
    void operator  -= ( Mare& ) ;
    void operator <<= ( int ) ;
    void operator >>= ( int ) ;
    void operator  /= ( int ) ;
    void operator  /= ( Mare& ) ;
    void operator  %= ( int ) ;
    void operator  %= ( Mare& ) ;
    void operator  ++ ( void ) ;
    void operator  ++ ( int ) ;
    void operator  -- ( void ) ;
    void operator  -- ( int ) ;

    Mare operator  + ( Mare& ) ;

    int  zero         ( void ) ;
    int  comparare    ( Mare& ) ;

    bool operator  <  ( Mare& ) ;
    bool operator  <= ( Mare& ) ;
    bool operator  >  ( Mare& ) ;
    bool operator  >= ( Mare& ) ;
    bool operator  == ( Mare& ) ;
    bool operator  != ( Mare& ) ;

    void operator  |= ( Mare& ) ;
    void operator  &= ( Mare& ) ;
    void operator  ^= ( Mare& ) ;

    void afis           ( void ) ;
    void afis_rad       ( int ) ;
    void obtain         ( int, int* ) ;
    void pow            ( int ) ;
    void radical_cb     ( Mare& ) ;
    void radical_normal ( Mare&, int ) ;
    void transform_2    ( int* ) ;
    void transform_10   ( int* ) ;
    void transform_210  ( int* ) ;

} ;

Mare :: Mare () { // A = 0
    this -> resize ( MAX ) ;
}

Mare :: Mare ( int X ) { // A = X
    this -> resize ( MAX ) ;
    for ( A[0] = 0; X ; X /= base ) {
        A[ ++A[0] ] = X % base ;
    }
}

void Mare :: operator = ( char *X ) { // A = X ( sir )
    A[0] = 0;
    if ( X ) {
        for ( int h = strlen ( X ) ; h > 0 ; h -= nbase ) {
            ++A[0] ;
            for ( int i = max ( 0, h - nbase ) ; i < h; ++i ) {
                A[ A[0] ] = A[ A[0] ] * 10 + X[i] - '0' ;
            }
        }
    }
}

void Mare :: operator += ( Mare &B ) { // A += B
    int i, t = 0;
    for ( i = 1; i <= A[0] || i <= B[0] || t; ++i, t /= base )
        A[i] = ( t += verf ( A, i ) + verf ( B, i ) ) % base ;
    A[0] = i - 1;
}

void Mare :: operator *= ( int B ) { // A *= B
    int i = 1;
    for ( long long t = 0; i <= A[0] || t; ++i, t /= base )
        A[i] = ( t += 1LL * verf ( A, i ) * B ) % base ;
    A[0] = i - 1;
}

void Mare :: operator *= ( Mare &B ) { // A *= B
    Mare C  ;
    for ( int i = 1, j; i <= A[0]; ++i ) {
        long long t = 0 ;
        for ( j = 1; j <= B[0] || t; ++j, t /= base)
            C[i + j - 1] = ( t += C[i + j - 1] + 1LL * verf ( A, i ) * verf ( B, j ) ) % base;
        if ( i + j - 2 > C[0] )
            C[0] = i + j - 2;
    }

    A = C ;
}

void Mare :: operator -= ( Mare &B ) { // A -= B, ∀ A ≥ B
    int t = 0;
    for ( int i = 1; i <= A[0]; ++i ) {
        t = ( A[i] -= verf ( B, i ) + t ) < 0 ;
        A[i] += t * base ;
    }
    for ( ; A[0] > 1 && !A[A[0]]; --A[0] ) ;
}

void Mare :: operator <<= ( int Count ) { // A *= 10^Count
    if ( Count ) {
        if ( A.zero () ) A = 1 ;
        Mare sol = 10 ;
        sol.pow ( Count ), A *= sol ;
    }
}

void Mare :: operator >>= ( int Count ) { // A /= 10^Count
    if ( Count ) {
        Mare sol = 10 ;
        sol.pow ( Count ), A /= sol ;
    }
}

void Mare :: operator /= ( int B ) { // A /= B
    long long t = 0;
    for ( int i = A[0]; i > 0; i--, t %= B )
        A[i] = ( t = 1LL * t * base + A[i] ) / B ;
    for ( ; A[0] > 1 && !A[ A[0] ]; --A[0] ) ;
}

# define ck ( i / nbase + ( i % nbase != 0 ) )

void Mare :: operator /= ( Mare &B ) { // A /= B
    int X[MAX * nbase];
    Mare R = 0, T ;

    A.transform_10 ( X ) ;
    fill_n ( A.begin () + 1, A[0], 0 ) ;
    for ( int i = X[0]; i ; --i ) {
        R *= R.zero () ? 0 : 10, T = X[i], R += T ;
        for ( A[ ck ] *= 10; B <= R ; ++A[ ck ], R -= B ) ;
    }

    for ( ; !A[ A[0] ] && A[0] > 1 ; --A[0] ) ;
}

void Mare :: operator %= ( int B ) { // A %= B
    long long t = 0;
    for ( int i = A[0]; i ; --i )
        t = ( 1LL * t * base + A[i] ) % B ;
    A = t ;
}

void Mare :: operator %= ( Mare &B ) { // A %= B
    int X[MAX * nbase] ; Mare R = 0, T, C ;

    A.transform_10 ( X ) ;
    fill_n ( C.begin () + 1, A[0], 0 ) ;
    for ( int i = X[0]; i ; --i ) {
        R *= R.zero () ? 0 : 10, T = X[i], R += T ;
        for ( C[ ck ] *= 10; B <= R ; ++C[ ck ], R -= B ) ;
    }

    A = R ;
}

# undef ck

void Mare :: operator ++ ( void ) { // ++A
    Mare B = 1 ;
    A += B ;
}

void Mare :: operator ++ ( int ) { // A++
    ++A ;
}

void Mare :: operator -- ( void ) { // --A
    Mare B = 1 ;
    A -= B ;
}

void Mare :: operator -- ( int ) { // A--
    --A ;
}

Mare Mare :: operator + ( Mare &B ) { // C = A + B
    int i, t = 0; Mare C ;

    for ( i = 1; i <= A[0] || i <= B[0] || t; ++i, t /= base )
        C[i] = ( t += verf ( A, i ) + verf ( B, i ) ) % base ;
    C[0] = i - 1;

    return C ;
}

int Mare :: zero ( void ) { // A == 0 ?
    return A[0] == 0 || A[0] == 1 && A[1] == 0 ;
}

int Mare :: comparare ( Mare &B ) {
    for ( ; A[0] && !A[A[0]] ; --A[0] ) ;
    for ( ; B[0] && !B[B[0]] ; --B[0] ) ;

    if ( A[0] < B[0] ) return -1;
    else if ( A[0] > B[0] ) return 1;

    for ( int i = A[0]; i > 0; --i )
        if ( A[i] < B[i] ) return -1;
        else if ( A[i] > B[i] ) return 1;

    return 0;
}

bool Mare :: operator < ( Mare &B ) { // A < B ?
    return A.comparare ( B ) == -1 ;
}

bool Mare :: operator <= ( Mare &B ) { // A <= B ?
    return A.comparare ( B ) != 1 ;
}

bool Mare :: operator > ( Mare &B ) { // A > B ?
    return A.comparare ( B ) == 1 ;
}

bool Mare :: operator >= ( Mare &B ) {// A >= B ?
    return A.comparare ( B ) != -1 ;
}

bool Mare :: operator == ( Mare &B ) {// A == B ?
    return A.comparare ( B ) == 0 ;
}

bool Mare :: operator != ( Mare &B ) {// A != B ?
    return A.comparare ( B ) != 0 ;
}

void Mare :: operator |= ( Mare &B ) { // A |= B
    int X[MAX * nbase], Y[MAX * nbase] ;
    A.transform_2 ( X ) , B.transform_2 ( Y ) ;
    for ( int i = 1; i <= X[0] && i <= Y[0]; ++i )
        X[i] |= Y[i] ;
    if ( X[0] < Y[0] ) {
        for ( int i = X[0] + 1 ; i <= Y[0] ; ++i )
            X[i] = Y[i] ;
        X[0] = Y[0] ;
    }
    A.transform_210 ( X ) ;
}

void Mare :: operator &= ( Mare &B ) { // A &= B
    int X[MAX * nbase], Y[MAX * nbase] ;
    A.transform_2 ( X ) , B.transform_2 ( Y ) ;
    for ( int i = 1; i <= X[0] && i <= Y[0]; ++i )
        X[i] &= Y[i] ;
    X[0] = min ( X[0], Y[0] ) ;
    A.transform_210 ( X ) ;
}

void Mare :: operator ^= ( Mare &B ) { // A ^= B
    int X[MAX * nbase], Y[MAX * nbase] ;
    A.transform_2 ( X ) , B.transform_2 ( Y ) ;
    for ( int i = 1; i <= X[0] && i <= Y[0]; ++i )
        X[i] ^= Y[i] ;

    if ( X[0] < Y[0] ) {
        for ( int i = X[0] + 1 ; i <= Y[0] ; ++i )
            X[i] = Y[i] ;
        X[0] = Y[0] ;
    }
    A.transform_210 ( X ) ;
}

void Mare :: radical_cb ( Mare &B ) { // B = sqrt ( A ) ; doar parte intreaga
    Mare cnt, X ;

    for ( cnt = 1; cnt < A; cnt *= 2 ) ;
    for ( B[0] = 1 ; ! cnt.zero () ; cnt /= 2 ) {
        X = cnt, X += B, X *= X ;
        if ( X <= A )
            B += cnt ;
    }
}

void Mare :: afis ( void ) { // afisarea
    sprintf (rez, "%d", A[ A[0] ] ) ;
    for ( int i = A[0] - 1; i ; --i ) {
        sprintf (rez+strlen(rez), "%09d", A[i] ) ;
    }
}

void Mare :: afis_rad ( int nrzecimale ) { // afisarea radicalului
    int X[MAX * nbase] ;

    A.transform_10 ( X ) ;
    for ( int i = X[0]; i > nrzecimale ; --i )
        printf ( "%d", X[i] ) ;
    printf ( "." ) ;
    for ( int i = nrzecimale ; i ; --i ) {
        printf ( "%d", X[i] ) ;
    }
}

void Mare :: obtain ( int x, int *X ) {
    int S[10] = { 0 } ;
    for ( int i = A[x]; i  ; i /= 10 )
        S[ ++S[0] ] = i % 10 ;
    for ( int i = 1; i <= S[0] ; ++i )
        X[ ++X[0] ] = S[i] ;
    if ( x != A[0] )
        for ( int i = S[0]; i < nbase; ++i )
            X[ ++X[0] ] = 0 ;
}

void Mare :: pow ( int P ) { // A = A^P
    Mare B = 1 ;
    for ( ; P ; P >>= 1 ) {
        if ( P & 1 )
            B *= A ;
        A *= A ;
    }
    A = B ;
}

void Mare :: transform_2 ( int *X ) { // baza 'base' -> baza 2
    Mare B = A ;
    X[0] = 0 ;
    for ( ; !B.zero () ; X[ ++X[0] ] = B[ 1 ] & 1, B /= 2 ) ;
}

void Mare :: transform_10 ( int *X ) { // baza 'base' -> baza 10
    X[0] = 0 ;
    for ( int i = 1; i <= A[0]; ++i )
        obtain ( i, X ) ;
}

void Mare :: transform_210 ( int *X ) { // baza 2 -> baza 'base'
    Mare B = 1 ; A = 0 ;
    for ( int i = 1; i <= X[0]; ++i, B *= 2 ) {
        if ( X[i] == 1 ) A += B ;
    }
}

void Mare :: radical_normal ( Mare &B, int nrzecimale ) {
    int AUX = 0, i , j = 0 ; int X[MAX * nbase] ;
    Mare C, D, E, F, U = 9 , Z = 1 ;

    A.transform_10 ( X ), i = X[0] ;
    X[0] & 1 ? AUX = X[i--] : ( AUX = X[i--], AUX *= 10, AUX += X[i--] ) ;

    int aux = static_cast < int > ( sqrt ( AUX ) ) ;

    B = aux ;

    if ( X[0] > 2 ) {
        AUX -= aux * aux;

        E = AUX, E <<= 1, F = X[i--] ;

        if ( AUX ) E += F, E <<= 1 ;
        else E = F ;

        if ( AUX == 0 && X[i + 1] ) E <<= 1 ;

        F = X[i--], E += F, C = E, F = B, F *= 2, E = F ;

        D = C, D >>= 1, D /= E, U < D ? D = 9 : 0 ;
        E <<= 1, E += D, E *= D ;

        while ( C < E )
            D -= Z, F = B, F *= 2, E = F, E <<= 1, E += D, E *= D ;

        C -= E, B <<= 1, B += D ;
    } else {
        C = AUX - ( aux * aux ) ;
    }

    if ( !C.zero () || i > 0 ) {
        for ( i = i; i > 0 || j < nrzecimale ; ) {
            if ( i > 0 ) {
                E = X[i--], F = 0, F <<= 1, F = E, E = X[i--];
                if ( X[i + 2] ) F <<= 1, F += E ;
                else F = E ;
            } else {
                ++j, F = 0 ;
                if ( j == 1 && C.zero () ) {
                    for ( int i = 1; i <= nrzecimale ; ++i )
                        B <<= 1 ;
                    return ;
                }
            }
            if ( !C.zero () || i == 3 + ( X[0] % 2 == 0 ) && AUX ) {
                C <<= 2, C += F ;
            } else {
                C = F ;
            }

            F = B, F *= 2, E = F ;
            D = C, D >>= 1, D /= E, U < D ? D = 9 : 0 ;
            E <<= 1, E += D, E *= D ;

            while ( C < E )
                D -= Z, F = B, F *= 2, E = F, E <<= 1, E += D, E *= D ;

            C -= E, B <<= 1, B += D ;
        }
    } else {
        for ( int i = 1; i <= nrzecimale ; ++i )
            B <<= 1 ;
    }
}

# undef A

Mare a,b,c;

int main ( void ) {
    int x,k,nr;
    freopen("sqrt.in","r",stdin);
    freopen("sqrt.out","w",stdout);
    scanf("%d %d",&x,&k);
    nr=sqrt(x);

    a=x;
    a.radical_normal(b,k);
    b.afis();
    int i=0;
    for(;nr;nr/=10,++i);
    //fprintf(stderr,"%d ",i);
    i=1;
    for(;rez[i];++i) printf("%c",rez[i]);
}
