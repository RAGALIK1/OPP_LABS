#include <iostream>
#include <string>
using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    int ISBN;

public:
    Carte() : titlu(""), autor(""), ISBN() {}

    Carte(string t, string a, int isbn) : titlu(t), autor(a), ISBN(isbn) {}

    string getTitlu() const { return titlu; }
    string getAutor() const { return autor; }
    int getISBN() const { return ISBN; }

    void afiseazaCarte() const {
        cout << "Titlu: " << titlu <<endl<< " Autor: " << autor<<endl<< " ISBN: " << ISBN << endl;
    }
};

class Biblioteca {
private:
    Carte carti[1000]; 
    int nCarti;

public:

    Biblioteca() : nCarti(0) {

    }

    void adaugaCarte(const Carte& carte) {
            carti[nCarti] = carte;
            nCarti++;
            cout << "Cartea \"" << carte.getTitlu() << "\" a fost adaugata" << endl;
    }

    void eliminaCarte(const string& titlu) {
        int b = 0;

        for (int i = 0; i < nCarti; ++i) {
            if (carti[i].getTitlu() == titlu) {
                b = 1;
                for (int j = i; j < nCarti - 1; ++j) {
                    carti[j] = carti[j + 1];
                }
                nCarti--;
                cout << "Cartea " << titlu << " a fost stearsa" << endl;
                break;
            }
        }
    }

    void afiseazaCarti() const {
        if (nCarti == 0) {
            cout << "Biblioteca este goala" << endl;
        } else {
            for (int i = 0; i < nCarti; ++i) {
                cout<<endl<<i+1<<": ";
                carti[i].afiseazaCarte();
            }
        }
    }
};

int main() {
    Biblioteca biblioteca;
    int n;
    cout<<"Cate carti aveti"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        string autor,titlu;
        int ibsn;
        cin>>titlu>>autor>>ibsn;
        Carte carte(titlu,autor,ibsn);
        biblioteca.adaugaCarte(carte);
    } 

    while(1){
        cout<<"Pentru afisare 1"<<endl<<" Pentru stergere 2"<<endl<<" Exit 0";
        int c;
        cin>>n;
        if(n==1){
            biblioteca.afiseazaCarti();
        }
        else if(n==2){
            string temp;
            cout<<"Dati titlu care doriti sal stergeti"<<endl;
            cin>>temp;
            biblioteca.eliminaCarte(temp);

        }
        else{ 
            break;
        }
    }    

    return 0;
}
