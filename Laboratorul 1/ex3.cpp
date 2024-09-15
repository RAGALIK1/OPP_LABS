#include <iostream>
using namespace std;

class Vehicul {
protected:
    int vitezaMaxima;

public:
    Vehicul(int viteza) {
        vitezaMaxima = viteza;
        cout << "Constructorul clasei Vehicul  Viteza: " << vitezaMaxima << " km/h" << endl;
    }

    ~Vehicul() {
        cout << "Destructorul-Vehicul " << endl;
    }
};

class Masina : public Vehicul {
private:
    string marca;

public:
    Masina(string m, int viteza) : Vehicul(viteza) {
        marca = m;
        cout << "Constructorul clasei Masina Marca: " << marca << endl;
    }

    ~Masina() {
        cout << "Destructorul-Masina " << endl;
    }
};

int main() {

    Masina masina1("Toyota", 180);

    return 0;
}
