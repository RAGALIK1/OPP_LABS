#include <iostream>
#include <string>
using namespace std;

class Carte {
private:
    string titlu;
    int pagini;

public:
    Carte(string n, int v) {
        titlu = n;
        pagini = v;
    }

    void setTitlu(string n) {
        titlu = n;
    }

    void setPagini(int v) {
            pagini = v;
    }

    string getTitlu() {
        return titlu;
    }

    int getPagini() {
        return pagini;
    }

    void afiseazaCarti() {
        cout << "Titlu: " << titlu <<endl<< "Pagini: " << pagini << endl;
    }
};

int main() {

    Carte Carte1("Anatol", 25);
    Carte1.afiseazaCarti();
    Carte1.setTitlu("Vita de vie");
    Carte1.setPagini(30);
    Carte1.afiseazaCarti();

    return 0;
}
