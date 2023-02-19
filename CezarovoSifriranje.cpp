#include <iostream>
#include<string>
using namespace std;
/*
 *  Potrebno je napraviti program koji vrsi Cezarovo sifriranje sa kljucem
 *  (pomjeranje svakog karaktera za odredjeni kljuc)
 *  Kljuc 3
 *  a -> d
 *  Korisnik unosi jedan tekst - sve mala slova
 *  1. Ako barem jedan karatker nije malo slovo ispisati
 *      [GRESKA] Invalid karakter
 *  2. Ako je broj unesenih karaktera veci od 200 ispisati
 *      [GRESKA] Veliki broj karaktera
 *
 *  Kljuc za rotaciju je 256%(broj slova)
 *  a) Ako je ostatak 0, ispisati tekst unazad
 *  b) inace izvrsiti Cezarovo sifriranje
 *
 *  Primjer:
 *  Unesite tekst: Edin Tabak
 *  [GRESKA] Invalid karakter
 *
 *  Unesite tekst: four
 *  Sifrirani tekst: ruof
 *
 *  Unesite tekst: bruteforce
 *  Sifrirani tekst: hxazkluxik
 *
 */
int main() {
    string tekst;
    cout<<"Unesi tekst(malim slovima): ";
    getline(cin,tekst);

    int x,brojSlova=0;

    for (int i = 0; i <= tekst.size(); ++i) {
        x=tekst[i];
        if(x!=0 && x!=32){
            if (x<97 || x>122) {
                cout << "[GRESKA] Invalid karakter." << endl;
                system("pause");
                return 0;
            }
        }
        if (x>96 && x<123) {
            brojSlova++;
        }
    }
    if (tekst.size()>200){
        cout<<"[GRESKA] Veliki broj karaktera."<<endl;
        system("pause");
        return 0;
    }
    cout<<"Broj slova iznosi: "<<brojSlova<<endl;

    int kljucRotacije;
    kljucRotacije=256%brojSlova;
    cout<<"Kljuc rotacije iznosi: "<<kljucRotacije<<endl;
    if (kljucRotacije == 0) {
        for (int i = tekst.size(); i >0; i--) {
            cout << tekst[i - 1];
        }
        cout<<endl;
    }
    else{
        cout<<"Sifrirani tekse: ";
        for (int i = 0; i < tekst.size(); ++i) {
            if (int(tekst[i]+kljucRotacije)>122)
            {
                cout << char(int(tekst[i]) + kljucRotacije-25);
            }
            else
            {
                if(tekst[i]==32)
                {
                    cout << char(int(tekst[i]));
                }
                else {
                    cout << char(int(tekst[i]) + kljucRotacije);
                }
            }
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}