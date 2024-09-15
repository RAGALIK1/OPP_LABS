#include <iostream>
using namespace std;

class Vehicul {
protected:
    int vitezaMaxima;
    int anulFabricarii;

public:
    Vehicul(int viteza, int anul) : vitezaMaxima(viteza), anulFabricarii(anul) {}

    void afiseazaDetalii() {
        cout << "Viteza: " << vitezaMaxima << " km/h" << endl;
        cout << "Anul fabricarii: " << anulFabricarii << endl;
    }
};

class Masina : public Vehicul {
private:
    string marca;
    string modelul;

public:
    Masina(string m, string mo, int viteza, int anul) 
        : Vehicul(viteza, anul), marca(m), modelul(mo) {}

    void afiseazaDetalii() {
        cout << "Marca: " << marca << endl;
        cout << "Modelul: " << modelul << endl;
        Vehicul::afiseazaDetalii();
    }
};

int main() {
    Masina masina("Toyota", "Corolla", 200, 2002);
    masina.afiseazaDetalii();

    return 0;
}
