#include <iostream>
#include <cmath>

using namespace std;

float df(float t, float x){
    return sin(x*t);
}

float Runge(float *t ,float x, float h){     //Runge 4th order method
    float k1 = df(*t, x);
    float k2 = df(*t + h/2, x + h*k1/2);
    float k3 = df(*t + h/2, x + h*k2/2);
    float k4 = df(*t + h, x + h*k3);

    *t += h;

    return x + (k1 + 2*k2 + 2*k3 + k4)*h/6;

}

int main(){
    float x = 1, t = 0, h = 0.1;       //initial condition
    int n = 100;              //number of points
    float ans[n][2] = {};
    ans[0][0] = t;
    ans[0][1] = x;

    for(int i = 1; i < n; i++){
        ans[i][0] = t + h;
        ans[i][1] = Runge(&t, x, h);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }

}