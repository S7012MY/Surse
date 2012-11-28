#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265
using namespace std;

class Point {
public:
    double x,y;
    Point operator + (Point b) {
        Point ret;
        ret.x=this->x+b.x;
        ret.y=this->y+b.y;
        return ret;
    }
};

double degToRad(double deg) {
    return deg*PI/180.0;
}

double radToDeg(double rad) {
    return 180*rad/PI;
}

class MarsRover {
public:
    double maxSteeringAngle,wheelBase,distance;
    bool degNeg;

    Point position;
    double direction;

    void setSteeringAngle(double angle) {
       degNeg=angle<0;
        maxSteeringAngle=fabs(angle)*PI/180.0;
    }

    double getSteeringAngle() {
        return 180.0*maxSteeringAngle/PI;
    }

    double getTurnRadius(double steeringAngle) {
        return wheelBase/sin(steeringAngle);
    }

    double getDirection(double steeringAngle) {
        double alpha = distance/(getTurnRadius(steeringAngle));
        for(;alpha>=2.0*PI;alpha-=2*PI);
        for(;alpha<0;alpha+=2*PI);
        if(degNeg) {
            alpha=2*PI-alpha;
        }
        return alpha;
    }

    double returnDirection(double steeringAngle) {
        return radToDeg(getDirection(steeringAngle));
    }

    Point getPosition() {
        return position;
    }

    void move(double distance, double steeringAngle) {
        Point ret;
        if(maxSteeringAngle==0) {
            ret.x=0;
            ret.y=distance;
        }
        else {
            ret.x=-cos(getDirection(steeringAngle))*getTurnRadius(steeringAngle)+getTurnRadius(steeringAngle);
            ret.y=sin(getDirection(steeringAngle))*getTurnRadius(steeringAngle);
            if(degNeg) {
                ret.x=-ret.x;
                ret.y=-ret.y;
            }
        }
    }

};

int main()
{
    double wb,dst,sa;
    MarsRover r;
    cin>>wb>>dst>>sa;
    r.distance=dst;
    r.wheelBase=wb;
    r.setSteeringAngle(sa);

    //cout<<r.getTurnRadius()<<' ';
    Point rez=r.getPosition();
    cout<<fixed<<setprecision(2)<<rez.x<<' '<<rez.y<<' '<<r.returnDirection();
    return 0;
}
