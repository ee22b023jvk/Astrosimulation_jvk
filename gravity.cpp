#include <iostream>
#include <vector>
#include <cmath>

#define dl double

dl const G = 6.6743 * pow(10,-11);

using namespace std;

vector <dl> F(dl m1, dl x1, dl y1, dl z1, dl m2, dl x2, dl y2, dl z2){       //mass and coordinate of center of mass as paramters
    vector <dl> v;
    dl x = x2 - x1, y = y2 - y1, z = z2 - z1;
    
    dl r = sqrt(x*x + y*y + z*z);                                            //distance between COM


    v.push_back(G*m1*m2*x/pow(r, 3));
    v.push_back(G*m1*m2*y/pow(r, 3));
    v.push_back(G*m1*m2*z/pow(r, 3));                                        //components of force

    return v;
}

int main(){
    dl m1, x1, y1, z1, m2, x2, y2, z2;
    cout << "Enter mass and coordinates of first point mass" << endl;
    cin >> m1 >> x1 >> y1 >> z1;
    cout << "Enter mass and coordinates of second point mass" << endl;
    cin >> m2 >> x2 >> y2 >> z2;

    vector <dl> v = F(m1, x1, y1, z1, m2, x2, y2, z2);

    cout << '(' << v[0] << ',' << v[1] << ',' << v[2] << ')' << endl;

    return 0;
}