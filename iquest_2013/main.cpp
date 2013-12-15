//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//string days[7];
//
//void inc(int &i) {
//  i=(i+1)%7;
//}
//
//void dec(int &i) {
//  i=(i-1+7)%7;
//}
//
//vector<string> rez;
//
//int lg[]={31,28,31,30,31,30,31,31,30,31 ,30,31};
//
//void push(int index) {
//  if(index==5) --index;
//  else if(index==6) index=0;
//  rez.push_back(days[index]);
//}
//
//int isLeap(int year) {
//  if (year%400==0) return 1;
//  if (year%100==0) return 0;
//  if (year%4==0) return 1;
//  return 0;
//}
//
//int main()
//{
//    days[0]="MON";
//    days[1]="TUE";
//    days[2]="WED";
//    days[3]="THU";
//    days[4]="FRI";
//    days[5]="SAT";
//    days[6]="SUN";
//    string cday="AAA";
//    int date,index,year;
//    char a,b,zz,zzz;
//    scanf("%c%c%c,%c%c,%c%c,%d",&cday[0],&cday[1],&cday[2],&a,&b,&zz,&zzz,&year);
//    date=(a-'0')*10+b-'0';
//    //cout<<cday<<' '<<date<<' '<<year;
//    for(int i=0; i<7; ++i) if(cday==days[i]) index=i;
//    for(;date!=10;) {
//      if(date<10) {
//        inc(index);
//        ++date;
//      }else {
//        dec(index);
//        --date;
//      }
//    }
//    push(index);
//    for(int i=0; i<11; ++i) {
//      index+=lg[i];
//      if(i==1 && isLeap(year)) ++index;
//      index%=7;
//      push(index);
//    }
//    for(int i=0; i<rez.size()-1; ++i) cout<<rez[i]<<',';
//    cout<<rez.back();
//    return 0;
//}
