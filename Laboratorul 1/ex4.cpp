#include <iostream>
using namespace std;


class ParteaB;

class ParteaA {
private:
    int x;

public:

    ParteaA(int a) : x(a) {}

    friend class ParteaB;

    void afiseazaA() {
        cout << "Cordonata x: " << x << endl;
    }
};

class ParteaB {
private:
    int y;

public:

    ParteaB(int a) : y(a) {}

    friend class ParteaA;

    void afiseazaSecrete(ParteaA& objA) {
        cout << "ParteaA din ParteaB: x = " << objA.x << endl;
        cout << "Cordonata din ParteaB: " << y << endl;
    }
};

int main() {
    
    ParteaA objA(100);
    ParteaB objB(200);

    objB.afiseazaSecrete(objA);

    return 0;
}
