#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MIN_DIST 1.5
using namespace std;

struct Point {
    int x,y;
} ball;

double dist(Point a, Point b) {
    return sqrt(((double)a.x-b.x)*((double)a.x-b.x)+((double)a.y-b.y)*((double)a.y-b.y));
}

struct Player {
    Point position;
    int team,number;
    int possesion;
    double distance;
};

enum State {
    MaiMulti,
    Unul,
    Zero
};

bool cmp(const Player &a,const Player &b) {
    return dist(a.position,ball)<dist(b.position,ball);
}

class Game {
    public:
    int n;
    State actState,lastState;
    int actPosTeam,lastPosTeam,actPosPlayer,lastPosPlayer;
    int passes1,passes2,canPass;

    Player actPos[205],lastPos[205];

    Game() {
        n=0;
        passes1=0;
        passes2=0;
        canPass=0;
    }
    void order() {
        sort(actPos,actPos+n,cmp);
    }
    void addPlayer(Player a) {
        actPos[n]=a;
        actPos[n].distance=0;
        actPos[n].possesion=0;
        lastPos[n].distance=0;
        lastPos[n].possesion=0;
        lastState=Zero;
        ++n;
    }
    void print() {
        cout<<"1 "<<passes1<<" 2 "<<passes2;
    }

    void update() {
        if(actState!=Zero) {
            lastState=actState;
            lastPosTeam=actPosTeam;
            lastPosPlayer=actPosPlayer;
            actState=Zero;
            canPass=0;
        } else {
            canPass = 1;
        }
        for(int i=0; i<n; ++i) {
            lastPos[i]=actPos[i];
        }
    }

    bool read() {
        if(scanf("%d %d",&ball.x,&ball.y)!=2) return 0;
        for(int i=0;i<n; ++i) {
            if(scanf("%d %d %d %d",&actPos[i].team,&actPos[i].number,&actPos[i].position.x,&actPos[i].position.y)!=4) {
                break;
            }
        }
        return 1;
    }
    void computePos() {
        for(int i=0; i<n; ++i)
            if(dist(actPos[i].position,ball)<=MIN_DIST)
                actPos[i].possesion = lastPos[i].possesion + 1;
    }
    void computeDistance() {
        for(int i=0; i<n; ++i)
            actPos[i].distance=lastPos[i].distance+dist(actPos[i].position,lastPos[i].position);
    }

    void evalPos() {
        int numPlayers=0;
        for(int i=0; i<n; ++i) if(dist(actPos[i].position,ball)<=MIN_DIST) {
            ++numPlayers;
            actPosPlayer=actPos[i].number;
            actPosTeam=actPos[i].team;
            cerr<<actPosTeam<<" "<<actPosPlayer<<endl;
        }
        cerr<<endl;
        if(0==numPlayers) actState=Zero;
        else if(1==numPlayers) actState=Unul;
        else actState=MaiMulti;
    }

    void checkPasses() {
        if(lastState==Unul && actState==Unul &&
           lastPosTeam==actPosTeam && lastPosPlayer!=actPosPlayer && canPass) {
               if(actPosTeam==1) ++passes1;
               else ++passes2;
           }
    }
};

int main()
{
    Player cc;
    Game g;
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d",&ball.x,&ball.y);

    for(;scanf("%d %d %d %d",&cc.team,&cc.number,&cc.position.x,&cc.position.y)==4;) {
        g.addPlayer(cc);
        char c;
        scanf("%c",&c);
        if(c=='\n') break;
    }
    g.evalPos();
    g.update();
    for(;g.read();) {
        g.evalPos();
        g.checkPasses();
        g.update();
    }
    g.print();
    return 0;
}
