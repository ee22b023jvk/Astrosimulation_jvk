#include <iostream>
#include <vector>
#include <cmath>

double G = 6.6743 * pow(10,-11);


using namespace std;

class celestialBody{
    public:
    double mass, radius, density, spin, distance_from_earth, surface_temp;
    string major_composition;                                             //major elements found in the planet
    
    double surfaceGravity(){
        return G*mass/radius*radius;
    }

};

class star : celestialBody{
    public:
    double Luminosity, wavelength;
    double intensityOfLightOnEarth(){
        return Luminosity/4*M_PI*pow(distance_from_earth, 2);
    }
};

class planet : celestialBody{
    public:
    int number_of_moons, number_of_rings;
    double orbial_speed;
    bool habitability;
};
