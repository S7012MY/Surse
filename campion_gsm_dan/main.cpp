#include <stdio.h>
#include <math.h>

using namespace std;

struct Patrat {
    double X1;
    double Y1;
    double X2;
    double Y2;
};

struct Punct {
    int X;
    int Y;
    double Arie;
};

int N;
Punct Centre[200];
Patrat oras;

int SOL;

double arie(Patrat p) {
    //printf("%lf %lf %lf %lf\n", p.X2, p.X1, p.Y2, p.Y1);
    return (p.X2 - p.X1) * (p.Y2 - p.Y1);
}

double dist(double X1, double Y1, Punct P2) {
    return (P2.X - X1) * (P2.X - X1) +
            (P2.Y - Y1) * (P2.Y - Y1);
}

int apel;

void calculeaza(Patrat p) {
    ++apel;
    double Arie = arie(p);
    int i;
    //printf("%lf\n", Arie);
    if (Arie < 1e-3) { // de aici reglezi precizia rezultatului vs timpul de executie
        return;
    }
    int distMaxPunct11 = -1;
    int distMaxPunct12 = -1;
    int distMaxPunct21 = -1;
    int distMaxPunct22 = -1;
    double distMax11 = 1e9;
    double distMax12 = 1e9;
    double distMax21 = 1e9;
    double distMax22 = 1e9;
    double d;

    for (i = 0; i < N; ++i) {
        d = dist(p.X1, p.Y1, Centre[i]);
        if (distMax11 > d) {
            distMax11 = d;
            distMaxPunct11 = i;
        }
        d = dist(p.X1, p.Y2, Centre[i]);
        if (distMax12 > d) {
            distMax12 = d;
            distMaxPunct12 = i;
        }
        d = dist(p.X2, p.Y1, Centre[i]);
        if (distMax21 > d) {
            distMax21 = d;
            distMaxPunct21 = i;
        }
        d = dist(p.X2, p.Y2, Centre[i]);
        if (distMax22 > d) {
            distMax22 = d;
            distMaxPunct22 = i;
        }
    }
    if (distMaxPunct11 == distMaxPunct12 &&
            distMaxPunct11 == distMaxPunct21 &&
            distMaxPunct11 == distMaxPunct22) {
        //printf("%d %d %lf\n", distMaxPunct11->X, distMaxPunct11->Y, distMaxPunct11->Arie, Arie);
        Centre[distMaxPunct11].Arie += Arie;
    } else {
        Patrat P11;
        Patrat P12;
        Patrat P21;
        Patrat P22;
        double PXM = (p.X1 + p.X2) / 2;
        double PYM = (p.Y1 + p.Y2) / 2;
        P11.X1 = p.X1;
        P11.X2 = PXM;
        P11.Y1 = p.Y1;
        P11.Y2 = PYM;
        P12.X1 = PXM;
        P12.X2 = p.X2;
        P12.Y1 = p.Y1;
        P12.Y2 = PYM;
        P21.X1 = p.X1;
        P21.X2 = PXM;
        P21.Y1 = PYM;
        P21.Y2 = p.Y2;
        P22.X1 = PXM;
        P22.X2 = p.X2;
        P22.Y1 = PYM;
        P22.Y2 = p.Y2;
        calculeaza(P11);
        calculeaza(P12);
        calculeaza(P21);
        calculeaza(P22);
    }
}

int main(void) {
    int i;
    FILE *in, *out;

    // citirea datelor
    in = fopen("gsm.in", "r");
    fscanf(in, "%d", &N);
    for(i = 0; i < N; ++i) {
        fscanf(in, "%d %d", &Centre[i].X, &Centre[i].Y);
    }
    fscanf(in, "%lf %lf %lf %lf", &oras.X1, &oras.Y1, &oras.X2, &oras.Y2);
    fclose(in);

    // calcularea solutiei
    calculeaza(oras);

    for (i = 0; i < N; ++i) {
        printf("%.2lf\n", Centre[i].Arie);
    }
    printf("\n");

    double arieMax = -1;
    for (i = 0; i < N; ++i) {
        Centre[i].Arie = ceil(Centre[i].Arie);
        if (arieMax < Centre[i].Arie - 1e-4) {
            arieMax = Centre[i].Arie;
            SOL = i + 1;
        }
    }

    // afisarea solutiei
    out = fopen("gsm2.out", "w");
    fprintf(out, "%d\n", SOL);
    fclose(out);

    printf("apeluri recursive = %d\n", apel);
    return 0;
}
