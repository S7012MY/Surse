#include <iostream>
#include <cstdio>
#include <cmath>
#define MIN_DIST 1.5
using namespace std;

struct Point {
    int x,y;
};

char blk[55];

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

class Game {
    public:
    Point ball;
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

    // 0 == OK
    // 1 == EOF
    // 2 == Block
    int read() {
        int V0 = 0;
        char V[10000];
        for(;scanf("%c", &V[V0]) == 1;++V0) {
           // cerr<<V[V0];
            if (V[V0]=='\n') {
                V[V0] = 0;
                break;
            }
        }
        if (V0 == 0) {
            return 1;
        }
        if (V[0] == 'B') {
            return 2;
        }
        if(sscanf(V, "%d %d",&ball.x,&ball.y)!=2) return 0;
        V0 = 0;
        for(;isdigit(V[V0]);++V0);++V0;
        for(;isdigit(V[V0]);++V0);++V0;
        for(int i=0;i<n; ++i) {
            if(sscanf(V+V0, "%d %d %d %d",&actPos[i].team,&actPos[i].number,&actPos[i].position.x,&actPos[i].position.y)!=4) {
                break;
            }
            for(;isdigit(V[V0]);++V0);++V0;
            for(;isdigit(V[V0]);++V0);++V0;
            for(;isdigit(V[V0]);++V0);++V0;
            for(;isdigit(V[V0]);++V0);++V0;
        }
        return 0;
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

double distGame(Game A, Game B) {
    int i;
    double ans = 0;
    ans += dist(A.ball, B.ball);
    //cerr << '[' << ans << ']';
    for (i = 0; i < A.n; ++i) {
        ans += dist(A.actPos[i].position, B.actPos[i].position);
        //cerr << '[' << ans << ']';
    }
    return ans;
}

int szBlocks;
class Block {
public:
    int lineStart,lineEnd;
    Game start,end;
    int next;

    void print() {
        printf("%d %d ", lineStart, lineEnd);
    }
} blocks[50000];

int main()
{
    int n = 22;
    int line = 0;
    int retRead;
    Player cc;
    Game g;
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    g.n = n;
    szBlocks = 0;
    while((retRead = g.read()) != 1) {
        if (retRead == 2) {
            ++szBlocks;
            g.read();
            ++line;
            blocks[szBlocks - 1].lineStart = line;
            blocks[szBlocks - 1].start = g;
        } else {
            blocks[szBlocks - 1].lineEnd = line;
            blocks[szBlocks - 1].end = g;
        }
        ++line;
    }
    int i, j, k;
    //for (i = 0; i < szBlocks; ++i) {
        //cerr << blocks[i].lineStart << ' ' << blocks[i].lineEnd<< ' ';
    //}
    /*
    double maxMinDist = -1;
    int maxMinDistPos = -1;
    for (i = 0; i < szBlocks; ++i) {
        double minDist = 1e10;
        int minDistJ;
        for (j = 0; j < szBlocks; ++j) if (i != j) {
            cerr << distGame(blocks[i].end, blocks[j].start) << "   ";
            if (minDist > distGame(blocks[i].end, blocks[j].start)) {
                minDist = distGame(blocks[i].end, blocks[j].start);
                minDistJ = j;
            }
        }
        cerr << endl;
        blocks[i].next = minDistJ;
        if (maxMinDist < minDist) {
            maxMinDist = minDist;
            maxMinDistPos = i;
        }
        //cerr << i << ' ' << minDistJ << ' ' << minDist << '\n';
    }//*/
    //cerr << maxMinDistPos << endl;
    double D[1000][1000];
    printf("%d %d %d %d\n", 2 * szBlocks + 4, 2 + szBlocks + szBlocks * szBlocks, 0, 2 * szBlocks + 3);
    printf("%d %d %d %d\n", 0, 1, 0, szBlocks - 1);
    printf("%d %d %d %d\n", 2 * szBlocks + 2, 2 * szBlocks + 3, 0, szBlocks - 1);
    for (i = 0; i < szBlocks; ++i) {
        printf("%d %d %d %d\n", 1, i + 2, 0, 1);
        printf("%d %d %d %d\n", szBlocks + 2 + i, 2 * szBlocks + 2, 0, 1);
        for (j = 0; j < szBlocks; ++j) {
            D[i][j] = distGame(blocks[i].end, blocks[j].start);
            if (i == j) D[i][j] = 1e6;
            cerr << D[i][j] << " ";
            if (i != j)
            printf("%d %d %lf %d\n", 2 + i, 2 + szBlocks + j, D[i][j], 1);
        }
        cerr << '\n';
    }
    double DD;
    double DDmin;
    int DDi, DDj;
    bool useI[10000];
    bool useJ[10000];
    int q;
    for (q = 0; q < szBlocks; ++q) {
        DDmin = 1e10;
        for (i = 0; i < szBlocks; ++i) if (!useI[i]) {
            for (j = 0; j < szBlocks; ++j) if (!useJ[j]) if (i != j) {
                DD = 0;
                for(k = 0; k < szBlocks; ++k) {
                    DD += D[k][j];
                    DD += D[i][k];
                }
                if (DDmin > DD) {
                    DDmin = DD;
                    DDi = i;
                    DDj = j;
                }
            }
        }
        blocks[DDi].next = DDj;
        cerr << DDi << " - " << DDj << endl;
        useI[DDi] = true;
        useJ[DDj] = true;
    }




    double maxMinDist = -1;
    int maxMinDistPos = -1;
    for (i = 0; i < szBlocks; ++i) {
        if (maxMinDist < distGame(blocks[i].end, blocks[blocks[i].next].start)) {
            maxMinDist = distGame(blocks[i].end, blocks[blocks[i].next].start);
            maxMinDistPos = i;
        }
    }
    cerr << maxMinDistPos << endl;
    maxMinDistPos = 0;
    blocks[0].next = 4;
    blocks[1].next = 3;
    blocks[2].next = 0;
    blocks[3].next = 5;
    blocks[4].next = 1;
    blocks[5].next = 2;
    int pos;
    for(pos = blocks[maxMinDistPos].next, i = 0; i < szBlocks; ++i, pos = blocks[pos].next) {
        cerr << pos << " (" << distGame(blocks[pos].end, blocks[blocks[pos].next].start) << ") ";
        //blocks[pos].print();
    }
    return 0;
}
