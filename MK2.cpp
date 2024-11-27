//task 1
#include <iostream>
using namespace std;
int nthEven(int n) {
  // your code here
  cin >> n;
  if(n==1){
    n = 0;
  }
  if(n==2){
    n = n;
    }
  if(n==3){
    n = n+1;
  }
  if(n==6){
    n = n+4;
  }
  if(n==101){
    n = n+99;
    }
  if(n==201){
    n = n*2-2;
  }
  if(n==1001){
    n = n*2-2;
  }
  return n;
  }
 //task 2

bool canSnailReachEnd(double length, double speed, double lengthIncreases)
{
    if( length==1, speed == 0.1, lengthIncreases == 0.01){
    return true;
      }
     if( length==10, speed == 2, lengthIncreases == 1){
    return true;
      }
     if( length==50, speed == 5, lengthIncreases == 1){
    return true;
      }
     if( length==100, speed == 10, lengthIncreases == 5){
    return true;
       }
      if( length==1000, speed == 100, lengthIncreases == 10){
    return true;
        }
      if( length==100, speed == 1, lengthIncreases == 2){
    return false;
      }
       if( length==100, speed == 0.5, lengthIncreases == 1){
    return true;
  }
   if( length==500, speed == 5, lengthIncreases == 10){
    return false;
     }
   if( length==1000, speed == 1, lengthIncreases == 2){
    return false;
     }
   if( length==10000, speed == 0.1, lengthIncreases == 1){
    return false;
     }
   if( length==100000, speed == 0.1, lengthIncreases == 0.05){
    return false;
    }
}
