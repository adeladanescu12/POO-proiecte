#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Interfata{
public:
    virtual ostream& Afisare(ostream&)const=0;
    virtual istream& Citire(istream&)=0;
};

class Dispozitiv:public Interfata{
protected:
    string numeDispozitiv;
    float pret;
    string firma;
    bool garantie;
public:

    Dispozitiv();
    Dispozitiv(string numeDispozitiv,float pret, string firma,bool garantie);
    Dispozitiv& operator=(const Dispozitiv& dis);
    Dispozitiv(const Dispozitiv& dis);

    virtual ostream& Afisare(ostream&)const;
    virtual istream& Citire(istream&);
    friend istream& operator>>(istream& in, Dispozitiv& p);
    friend ostream& operator<<(ostream& out, const Dispozitiv& p);

    virtual void calculeazaRata()=0; //calculeaza rata lunara in functie de pret

    ~Dispozitiv(){
    };
};
Dispozitiv::Dispozitiv() {
    this->numeDispozitiv="Necunoscut";
    this->pret=0;
    this->firma="Necunoscuta";
    this->garantie=false;
}
Dispozitiv::Dispozitiv(string numeDispozitiv, float pret, string firma, bool garantie) {
    this->numeDispozitiv=numeDispozitiv;
    this->pret=pret;
    this->firma=firma;
    this->garantie=garantie;
}
Dispozitiv::Dispozitiv(const Dispozitiv &dis) {
    this->numeDispozitiv=dis.numeDispozitiv;
    this->pret=dis.pret;
    this->firma=dis.firma;
    this->garantie=dis.garantie;
}
Dispozitiv& Dispozitiv::operator=(const Dispozitiv &dis) {
    if(this!=&dis)
    {
        this->numeDispozitiv=dis.numeDispozitiv;
        this->pret=dis.pret;
        this->firma=dis.firma;
        this->garantie=dis.garantie;
    }
    return *this;
}
ostream& Dispozitiv::Afisare(ostream& out)const{
    out<<"\nNumele dispozitivului este: "<<this->numeDispozitiv<<"\n";
    out<<"Pretul dispozitivului este: "<<this->pret<<"\n";
    out<<"Firma care a produs dispozitivului este: "<<this->firma<<"\n";
    if(this->garantie)
    {out<<"Dispozitivul are garantie";}
    else
    {out<<"Dispozitivul  NU are garantie";}
    return out;
}
istream& Dispozitiv::Citire(istream& in){

    cout<<"\nDati numele dispozitivului: ";
    in>>this->numeDispozitiv;
    cout<<"\nDati pretul dispozitivului: ";
    in>>this->pret;
    cout<<"\nDati firma care a produs dispozitivului: ";
    in>>this->firma;
    cout<<"\nDati garantia produsului[1-true/0-false]";
    in>>this->garantie;

    return in;

}
istream& operator>>(istream& in, Dispozitiv& dis)
{
    return dis.Citire(in);
}
ostream& operator<<(ostream& out, const Dispozitiv& dis)
{
    return dis.Afisare(out);
}



class Telefon:public virtual Dispozitiv{
protected:
    bool accesorii;
    bool tipMax;
public:
    Telefon();
    Telefon(string numeDispozitiv,float pret, string firma,bool garantie, bool accesorii, bool tipMax);
    Telefon& operator=(const Telefon& tel);
    Telefon(const Telefon& tel);

    ostream& Afisare(ostream&)const;
    istream& Citire(istream&);
    friend istream& operator>>(istream& in, Telefon& tel);
    friend ostream& operator<<(ostream& out, const Telefon& tel);

    void calculeazaRata();
    void afiseazaDimensiuniTip(); //afiseaza dimensiunile telefonul in functie de tipul ecranului (daca e de tip max sau nu)
    ~Telefon(){

    };

};
Telefon::Telefon():Dispozitiv(){
    this->accesorii=false;
    this->tipMax=false;
}
Telefon::Telefon(string numeDispozitiv,float pret, string firma,bool garantie, bool accesorii, bool tipMax):Dispozitiv(numeDispozitiv,pret,firma,garantie){
    this->accesorii=accesorii;
    this->tipMax=tipMax;
}
Telefon::Telefon(const Telefon &tel):Dispozitiv(tel) {
    this->accesorii = tel.accesorii;
    this->tipMax = tel.tipMax;
}
Telefon& Telefon::operator=(const Telefon& tel)
{
    if(this!=&tel)
    {
        Dispozitiv::operator=(tel);
        this->accesorii = tel.accesorii;
        this->tipMax = tel.tipMax;
    }
    return *this;
}

ostream& Telefon::Afisare(ostream& out) const{

    Dispozitiv::Afisare(out);
    if(this->accesorii)
    {out<<"\nDispozitivul vine cu acesorii";}
    else
    {out<<"\nDispozitivul nu vine cu acceosorii";}
    if(this->tipMax)
    {out<<"\nDispozitivul este de tip max";}
    else
    {out<<"\nDispozitivul nu este de tip max";}
    return out;
}
istream& Telefon::Citire(istream& in){

    Dispozitiv::Citire(in);
    cout<<"\nDispozitivul vine cu accesorii: [1-true/0-false]";
    in>>this->accesorii;
    cout<<"\nDispozitivul este de tip max: [1-true/0-false]";
    in>>this->tipMax;
    return in;
}
istream& operator>>(istream& in, Telefon& tel)
{
    return tel.Citire(in);
}
ostream& operator<<(ostream& out, const Telefon& tel)
{
    return tel.Afisare(out);
}
void Telefon::calculeazaRata(){
    cout<<"\nRata lunara este "<<(this->pret)/12<<endl;
}
void Telefon::afiseazaDimensiuniTip() {
    cout<<"Dimensiunile telefonului sunt:";
    if(this->tipMax)
    {   cout<<"\nLungime ";
        cout<<"160,8 mm";
        cout<<"\nLatime ";
        cout<<"78,1 mm ";
        cout <<"\nGrosime ";
        cout<<"7,65 mm";
    }
    else
    {   cout<<"\nLungime ";
        cout<<"146,7 mm";
        cout<<"\nLatime ";
        cout<<"71,5 mm";
        cout <<"\nGrosime ";
        cout<<"7,65 mm";
    }
    cout<<endl;
}

class Ceas:public virtual Dispozitiv{
protected:
    bool pietrePretioase;
    int ATM;
public:
    Ceas();
    Ceas(string numeDispozitiv,float pret, string firma,bool garantie, bool pietrePretioase, int ATM);
    Ceas& operator=(const Ceas& c);
    Ceas(const Ceas& c);

    ostream& Afisare(ostream&)const;
    istream& Citire(istream&);
    friend istream& operator>>(istream& in, Ceas& c);
    friend ostream& operator<<(ostream& out, const Ceas& c);

    void calculeazaRata();
    void verificareRezistenta(); //afiseaza rezistenta ceasului la apa in functie de rezistenta masurata in ATM(atmosfere)

    ~Ceas() {
    }

};
Ceas::Ceas():Dispozitiv(){
    this->pietrePretioase=false;
    this->ATM=0;
}
Ceas::Ceas(string numeDispozitiv,float pret, string firma,bool garantie, bool pietrePretioase, int ATM):Dispozitiv(numeDispozitiv,pret,firma,garantie){
    this->pietrePretioase=pietrePretioase;
    this->ATM=ATM;
}
Ceas::Ceas(const Ceas &c):Dispozitiv(c) {
    this->pietrePretioase=c.pietrePretioase;
    this->ATM=c.ATM;
}
Ceas& Ceas::operator=(const Ceas& c)
{
    if(this!=&c)
    {
        Dispozitiv::operator=(c);
        this->pietrePretioase=c.pietrePretioase;
        this->ATM=c.ATM;
    }
    return *this;
}
ostream& Ceas::Afisare(ostream& out) const{

    Dispozitiv::Afisare(out);
    if(this->pietrePretioase)
    {out<<"\nDispozitivul contine pietre pretioase";}
    else
    {out<<"\nDispozitivul NU contine pietre pretioase";}
    out<<"\nDispozitivul are rezistenta la apa de "<<this->ATM<<" ATM";
    return out;
}
istream& Ceas::Citire(istream& in){

    Dispozitiv::Citire(in);
    cout<<"\nDispozitivul contine pietre pretioase: [1-true/0-false]";
    in>>this->pietrePretioase;
    cout<<"\nDati rezistenta la apa in ATM";
    in>>this->ATM;
    return in;
}
istream& operator>>(istream& in, Ceas& c) {
    return c.Citire(in);
}
ostream& operator<<(ostream& out, const Ceas& c)
{
    return c.Afisare(out);
}
void Ceas::verificareRezistenta() {
    if(this->ATM==30)
    {cout<<"\nRezistenta la scufundari profesionale";}
    if(this->ATM==10)
    {cout<<"\nRezistenta inot dar nu la scufundari";}
    if(this->ATM==5)
    {cout<<"\nRezistenta la stropi de apa";}
}
void Ceas::calculeazaRata(){
    cout<<"\nRata lunara este "<<(this->pret)/12<<endl;
}


class Smartwatch: public Telefon, public Ceas{
protected:
    bool monitorizareFunctiiVitale;
    string sistemCompatibil;
public:
    Smartwatch();
    Smartwatch(string numeDispozitiv,float pret, string firma,bool garantie, bool accesorii, bool tipMax, bool pietrePretioase, int ATM, bool monitorizareFunctiiVitale,string sistemCompatibil);

    Smartwatch& operator=(const Smartwatch& sw);
    Smartwatch(const Smartwatch& sw);

    ostream& Afisare(ostream&)const;
    istream& Citire(istream&);
    friend istream& operator>>(istream& in, Smartwatch& sw);
    friend ostream& operator<<(ostream& out, const Smartwatch& sw);

    void calculeazaRata();
    void verificaCompatibilitate(string x); //verifica daca sistemul de operare dorit de client este compatibil cu smartwatchul


    ~Smartwatch() {

    }

};
Smartwatch::Smartwatch():Dispozitiv(),Telefon(),Ceas()
{
    this->monitorizareFunctiiVitale=false;
    this->sistemCompatibil="Necunoscuta";
}
Smartwatch::Smartwatch(string numeDispozitiv,float pret, string firma,bool garantie, bool accesorii, bool tipMax, bool pietrePretioase, int ATM, bool monitorizareFunctiiVitale,string sistemCompatibil):
        Dispozitiv(numeDispozitiv,pret,firma,garantie),
        Telefon(numeDispozitiv,pret,firma,garantie,accesorii,tipMax),
        Ceas(numeDispozitiv,pret,firma,garantie,pietrePretioase,ATM){
    this->monitorizareFunctiiVitale=monitorizareFunctiiVitale;
    this->sistemCompatibil=sistemCompatibil;
}
Smartwatch::Smartwatch(const Smartwatch& sw):Dispozitiv(sw),Telefon(sw),Ceas(sw)
{
    this->monitorizareFunctiiVitale=sw.monitorizareFunctiiVitale;
    this->sistemCompatibil=sw.sistemCompatibil;
}
Smartwatch& Smartwatch::operator=(const Smartwatch& sw)
{
    if(this!=&sw)
    {
        Telefon::operator=(sw);
        Ceas::operator=(sw);
        this->monitorizareFunctiiVitale=sw.monitorizareFunctiiVitale;
        this->sistemCompatibil=sw.sistemCompatibil;
    }
    return *this;
}

ostream& Smartwatch::Afisare(ostream& out) const{

    Dispozitiv::Afisare(out);

    if(this->accesorii)
    {out<<"\nDispozitivul vine cu acesorii";}
    else
    {out<<"\nDispozitivul nu vine cu acceosorii";}
    if(this->tipMax)
    {out<<"\nDispozitivul este de tip max";}
    else
    {out<<"\nDispozitivul nu este de tip max";}

    if(this->pietrePretioase)
    {out<<"\nDispozitivul contine pietre pretioase";}
    else
    {out<<"\nDispozitivul NU contine pietre pretioase";}
    out<<"\nDispozitivul are rezistenta la apa de "<<this->ATM<<" ATM";

    if(this->monitorizareFunctiiVitale)
    {out<<"\nDispozitivul poate monitoriza functiile vitale";}
    else
    {out<<"\nDispozitivul NU poate monitoriza functiile vitale";}
    out<<"\nDispozitivul este compatibil cu urmatoarul sistem de operare"<<this->sistemCompatibil;
    return out;
}
istream& Smartwatch::Citire(istream& in){

    Dispozitiv::Citire(in);
    cout<<"\nDispozitivul vine cu accesorii: [1-true/0-false]";
    in>>this->accesorii;
    cout<<"\nDispozitivul este de tip max: [1-true/0-false]";
    in>>this->tipMax;

    cout<<"\nDispozitivul contine pietre pretioase: [1-true/0-false]";
    in>>this->pietrePretioase;
    cout<<"\nDati rezistenta la apa in ATM";
    in>>this->ATM;

    cout<<"\nDispozitivul poate monitoriza functiile vitale [1-true/0-false]";
    in>>this->monitorizareFunctiiVitale;
    cout<<"\nDispozitivul este compatibil cu urmatoarul sistem de operare";
    in>>this->sistemCompatibil;
    return in;
}
istream& operator>>(istream& in, Smartwatch& sw) {
    return sw.Citire(in);
}
ostream& operator<<(ostream& out, const Smartwatch& sw)
{
    return sw.Afisare(out);
}
void Smartwatch::verificaCompatibilitate(string x){
    if(this->sistemCompatibil==x)
    {
        cout<<"\nSistemul de operare dorit este compatibil cu dispozitivul";
    }
    else
    {
        cout<<"\nSistemul de operare dorit nu este compatibil cu dispozitivul";
    }
}
void Smartwatch::calculeazaRata(){
    cout<<"\nRata lunara este "<<(this->pret)/12<<endl;
}

class Laptop:public virtual Dispozitiv{
protected:
    int memorieRAM;
    bool cititorDeAmprente;
public:
    Laptop();
    Laptop(string numeDispozitiv,float pret, string firma,bool garantie, int memorieRAM, bool cititorDeAmprente);
    Laptop& operator=(const Laptop& l);
    Laptop(const Laptop& l);

    ostream& Afisare(ostream&)const;
    istream& Citire(istream&);
    friend istream& operator>>(istream& in, Laptop& l);
    friend ostream& operator<<(ostream& out, const Laptop& l);

    void calculeazaRata();
    void potrivitPentruGaming();

    ~Laptop() {
    }

};
Laptop::Laptop():Dispozitiv(){
    this->memorieRAM=0;
    this->cititorDeAmprente=false;
}
Laptop::Laptop(string numeDispozitiv,float pret, string firma,bool garantie, int memorieRAM, bool cititorDeAmprente):Dispozitiv(numeDispozitiv,pret,firma,garantie){
    this->memorieRAM=memorieRAM;
    this->cititorDeAmprente=cititorDeAmprente;
}
Laptop::Laptop(const Laptop &l):Dispozitiv(l) {
    this->memorieRAM=l.memorieRAM;
    this->cititorDeAmprente=l.cititorDeAmprente;
}
Laptop& Laptop::operator=(const Laptop& l)
{
    if(this!=&l)
    {
        Dispozitiv::operator=(l);
        this->memorieRAM=l.memorieRAM;
        this->cititorDeAmprente=l.cititorDeAmprente;
    }
    return *this;
}
ostream& Laptop::Afisare(ostream& out) const{

    Dispozitiv::Afisare(out);
    out<<"\nDispozitivul are memorie"<<this->memorieRAM<<" RAM";
    if(this->cititorDeAmprente)
    {out<<"\nDispozitivul contine cititor de amprente";}
    else
    {out<<"\nDispozitivul NU contine cititor de amprente";}
    return out;
}
istream& Laptop::Citire(istream& in){

    Dispozitiv::Citire(in);
    cout<<"\nDati memoria in RAM";
    in>>this->memorieRAM;
    cout<<"\nDispozitivul contine cititor de amprente: [1-true/0-false]";
    in>>this->cititorDeAmprente;
    return in;
}
istream& operator>>(istream& in, Laptop& l) {
    return l.Citire(in);
}
ostream& operator<<(ostream& out, const Laptop& l)
{
    return l.Afisare(out);
}
void Laptop::potrivitPentruGaming() {
    if(this->memorieRAM==8)
    {cout<<"\npotrivit pentru gaming";};
    if(this->memorieRAM<8)
    {cout<<"\nnepotrivit pentru gaming";};
    if(this->memorieRAM>8)
    {cout<<"\nfoarte potrivit pentru gaming";};
}
void Laptop::calculeazaRata() {
    cout<<"\nRata lunara este "<<(this->pret)/12<<endl;
}

int main() {

    list<Telefon> listaTelefoane;
    list<Ceas> listaCeasuri;
    list<Smartwatch> listaSmartwatch;
    list<Laptop> listaLaptop;


    int k = 1;
    while (k == 1) {
        cout << "\n 1 Create";
        cout << "\n 2 Read";
        cout << "\n 3 Update";
        cout << "\n 4 Delete";
        cout << "\n 5 Stop";
        cout << "\n 6 Functionalitati";
        cout<<endl;
        int comanda;
        cin >> comanda;
        switch (comanda) {

            case 1: {
                int q = 1;
                while (q == 1) {
                    cout << "\nCreeaza:";
                    cout << "\n 1 Telefon";
                    cout << "\n 2 Ceas";
                    cout << "\n 3 Smartwatch";
                    cout << "\n 4 Laptop";
                    cout << "\n 5 Meniu";
                    int create;
                    cin >> create;
                    switch (create) {
                        case 1: {
                            Telefon a;
                            cin >> a;
                            listaTelefoane.push_back(a);
                            break;
                        }
                        case 2: {
                            Ceas a;
                            cin >> a;
                            listaCeasuri.push_back(a);
                            break;
                        }
                        case 3: {
                            Smartwatch a;
                            cin >> a;
                            listaSmartwatch.push_back(a);
                            break;
                        }
                        case 4: {
                            Laptop a;
                            cin >> a;
                            listaLaptop.push_back(a);
                            break;
                        }
                        case 5: {
                            q = 0;
                            break;
                        }
                        default: {
                            cout << "\nAti introdus un numar gresit";
                            break;
                        }

                    }
                }
                break;

            }
            case 2: {
                int q = 1;
                while (q == 1) {
                    cout << "\nAfiseaza:";
                    cout << "\n 1  Lista Telefon";
                    cout << "\n 2 Lista Ceas";
                    cout << "\n 3 Lista Smartwatch";
                    cout << "\n 4 Lista Laptop";
                    cout << "\n 5 Meniu";
                    int afiseaza;
                    cin >> afiseaza;
                    switch (afiseaza) {
                        case 1: {
                            list<Telefon>::iterator i;
                            i = listaTelefoane.begin();
                            while (i != listaTelefoane.end()) {
                                cout << (*i)<<endl;
                                advance(i, 1);
                            }
                            break;
                        }
                        case 2: {
                            list<Ceas>::iterator i;
                            i = listaCeasuri.begin();
                            while (i != listaCeasuri.end()) {
                                cout << (*i)<<endl;
                                advance(i, 1);
                            }
                            break;
                        }
                        case 3: {
                            list<Smartwatch>::iterator i;
                            i = listaSmartwatch.begin();
                            while (i != listaSmartwatch.end()) {
                                cout << (*i)<<endl;
                                advance(i, 1);
                            }
                            break;
                        }
                        case 4: {
                            list<Laptop>::iterator i;
                            i = listaLaptop.begin();
                            while (i != listaLaptop.end()) {
                                cout << (*i)<<endl;
                                advance(i, 1);
                            }
                            break;
                        }
                        case 5: {
                            q = 0;
                            break;
                        }
                        default: {
                            cout << "\nAti introdus un numar gresit";
                            break;
                        }

                    }
                }
                break;
            }
            case 3: {
                int q = 1;
                while (q == 1) {
                    cout << "\nPentru ce tip de dispozitiv doriti sa faceti update?";
                    cout << "\n 1 Telefon";
                    cout << "\n 2 Ceas";
                    cout << "\n 3 Smartwatch";
                    cout << "\n 4 Laptop";
                    cout << "\n 5 Meniu";
                    int update;
                    cin >> update;
                    switch (update) {
                        case 1: {
                            cout << "\nIntroduceti indexul elementului caruia doriti sa ii faceti update:" << endl;
                            int index;
                            cin >> index;
                            int ok=0;
                            int it = 0;
                            list<Telefon>::iterator i;
                            i = listaTelefoane.begin();
                            while (i != listaTelefoane.end()) {
                                if (it == index) {
                                    cout << "\nCu ce doriti sa faceti update?" << endl;
                                    Telefon a;
                                    cin >> a;
                                    *i = a;
                                    ok=1;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0)
                            {cout<<"Index introdus gresit";}

                            break;

                        }
                        case 2: {
                            cout << "\nIntroduceti indexul elementului caruia doriti sa ii faceti update:" << endl;
                            int index;
                            cin >> index;
                            int ok=0;
                            int it = 0;
                            list<Ceas>::iterator i;
                            i = listaCeasuri.begin();
                            while (i != listaCeasuri.end()) {
                                if (it == index) {
                                    cout << "\nCu ce doriti sa faceti update?" << endl;
                                    Ceas a;
                                    cin >> a;
                                    *i = a;
                                    ok=1;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0)
                            {cout<<"Index introdus gresit";}
                            break;

                        }
                        case 3: {
                            cout << "\nIntroduceti indexul elementului caruia doriti sa ii faceti update:" << endl;
                            int index;
                            cin >> index;
                            int ok=0;
                            int it = 0;
                            list<Smartwatch>::iterator i;
                            i = listaSmartwatch.begin();
                            while (i != listaSmartwatch.end()) {
                                if (it == index) {
                                    cout << "\nCu ce doriti sa faceti update?" << endl;
                                    Smartwatch a;
                                    cin >> a;
                                    *i = a;
                                    ok=1;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0)
                            {cout<<"Index introdus gresit";}
                            break;

                        }
                        case 4: {
                            cout << "\nIntroduceti indexul elementului caruia doriti sa ii faceti update:" << endl;
                            int index;
                            cin >> index;
                            int ok=0;
                            int it = 0;
                            list<Laptop>::iterator i;
                            i = listaLaptop.begin();
                            while (i != listaLaptop.end()) {
                                if (it == index) {
                                    cout << "\nCu ce doriti sa faceti update?" << endl;
                                    Laptop a;
                                    cin >> a;
                                    *i = a;
                                    ok=1;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0)
                            {cout<<"Index introdus gresit";}

                            break;


                        }
                        case 5: {
                            q = 0;
                            break;
                        }
                        default: {
                            cout << "\nAti introdus un numar gresit";
                            break;
                        }

                    }
                }
                break;

            }
            case 4: {
                int q = 1;
                while (q == 1) {
                    cout << "\nCe tip de dispozitiv doriti sa stergeti?";
                    cout << "\n 1 Telefon";
                    cout << "\n 2 Ceas";
                    cout << "\n 3 Smartwatch";
                    cout << "\n 4 Laptop";
                    cout << "\n 5 Meniu";
                    int stergere;
                    cin >> stergere;
                    switch (stergere) {
                        case 1: {
                            cout << "\nIntroduceti indexul elementului pe care doriti sa il stergeti" << endl;
                            int index;
                            cin >> index;
                            int it = 0;
                            int ok=0;
                            list<Telefon>::iterator i;
                            i = listaTelefoane.begin();
                            while (i != listaTelefoane.end()) {
                                if (it == index) {
                                    listaTelefoane.erase(i);
                                    ok=1;
                                    break;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0){cout<<"Ati introdus un nr gresit";}
                            break;

                        }
                        case 2: {
                            cout << "\nIntroduceti indexul elementului pe care doriti sa il stergeti" << endl;
                            int index;
                            cin >> index;
                            int it = 0;
                            int ok=0;
                            list<Ceas>::iterator i;
                            i = listaCeasuri.begin();
                            while (i != listaCeasuri.end()) {
                                if (it == index) {
                                    listaCeasuri.erase(i);
                                    ok=1;
                                    break;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0){cout<<"Ati introdus un nr gresit";}
                            break;


                        }
                        case 3: {
                            cout << "\nIntroduceti indexul elementului pe care doriti sa il stergeti" << endl;
                            int index;
                            cin >> index;
                            int it = 0;
                            int ok=0;
                            list<Smartwatch>::iterator i;
                            i = listaSmartwatch.begin();
                            while (i != listaSmartwatch.end()) {
                                if (it == index) {
                                    listaSmartwatch.erase(i);
                                    ok=1;
                                    break;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0){cout<<"Ati introdus un nr gresit";}
                            break;


                        }
                        case 4: {
                            cout << "\nIntroduceti indexul elementului pe care doriti sa il stergeti" << endl;
                            int index;
                            cin >> index;
                            int it = 0;
                            int ok=0;
                            list<Laptop>::iterator i;
                            i = listaLaptop.begin();
                            while (i != listaLaptop.end()) {
                                if (it == index) {
                                    listaLaptop.erase(i);
                                    ok=1;
                                    break;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if(ok==0){cout<<"Ati introdus un nr gresit";}
                            break;
                        }
                        case 5: {
                            q = 0;
                            break;
                        }
                        default: {
                            cout << "\nAti introdus un numar gresit";
                            break;
                        }

                    };
                }
                break;

            }
            case 5: {
                k = 0;
                break;
            }
            case 6: {
                int q = 1;
                while (q == 1) {
                    cout << "\nFunctie:";
                    cout << "\n 1 Afiseaza dimensiunile telefonului in functie de tipul acestuia";
                    cout << "\n 2 Afiseaza rezistenta ceasului la apa";
                    cout << "\n 3 Afiseaza daca sistemul de operare compatibil cu smartwatch-ul este cel dorit de client";
                    cout << "\n 4 Afiseaza daca laptopul este potrivit pentru gaming";
                    cout << "\n 5 Calculeaza rata";
                    cout << "\n 6 Meniu";
                    int functie;
                    cin >> functie;
                    switch (functie) {
                        case 1: {
                            cout << "\nIntroduceti indexul telefonului pentru care doriti sa efectuati functia";
                            int nr;
                            cin >> nr;
                            int it = 0;
                            list<Telefon>::iterator i;
                            i = listaTelefoane.begin();
                            while (i != listaTelefoane.end()) {
                                if (it == nr) {
                                    (i)->afiseazaDimensiuniTip();
                                }
                                advance(i, 1);
                                it++;
                            }
                            break;
                        }
                        case 2: {
                            cout << "\nIntroduceti indexul ceasului pentru care doriti sa efectuati functia";
                            int nr;
                            cin >> nr;
                            int it = 0;
                            list<Ceas>::iterator i;
                            i = listaCeasuri.begin();
                            while (i != listaCeasuri.end()) {
                                if (it == nr) {
                                    (i)->verificareRezistenta();
                                }
                                advance(i, 1);
                                it++;
                            }
                            break;

                        }
                        case 3: {
                            cout << "\nIntroduceti indexul smartwatchului pentru care doriti sa efectuati functia";
                            int nr;
                            cin >> nr;
                            int it = 0;
                            cout << "\nCu ce sistem de operare doriti sa verificati compatibilitatea";
                            string sistemop;
                            cin >> sistemop;
                            list<Smartwatch>::iterator i;
                            i = listaSmartwatch.begin();
                            while (i != listaSmartwatch.end()) {
                                if (it == nr) {
                                    (i)->verificaCompatibilitate(sistemop);
                                }
                                advance(i, 1);
                                it++;
                            }
                            break;


                        }
                        case 4: {
                            cout << "\nIntroduceti indexul laptopului pentru care doriti sa efectuati functia";
                            int nr;
                            cin >> nr;
                            int it = 0;
                            list<Laptop>::iterator i;
                            i = listaLaptop.begin();
                            while (i != listaLaptop.end()) {
                                if (it == nr) {
                                    (i)->potrivitPentruGaming();
                                }
                                advance(i, 1);
                                it++;
                            }
                            break;

                        }
                        case 5: {
                            int kk = 1;
                            while (k == 1) {
                                cout << "\nPentru ce tip de dispozitiv doriti sa calculati rata lunara?";
                                cout << "\n 1 Telefon";
                                cout << "\n 2 Ceas";
                                cout << "\n 3 Smartwatch";
                                cout << "\n 4 Laptop";
                                cout << "\n 5 Meniu";
                                int calculeaza;
                                cin >> calculeaza;
                                switch (calculeaza) {
                                    case 1: {
                                        cout
                                                << "\nIntroduceti indexul telefonului pentru care doriti sa efectuati functia";
                                        int nr;
                                        cin >> nr;
                                        int it = 0;
                                        list<Telefon>::iterator i;
                                        i = listaTelefoane.begin();
                                        while (i != listaTelefoane.end()) {
                                            if (it == nr) {
                                                (i)->calculeazaRata();
                                            }
                                            advance(i, 1);
                                            it++;
                                        }
                                        break;
                                    }
                                    case 2: {
                                        cout
                                                << "\nIntroduceti indexul ceasului pentru care doriti sa efectuati functia";
                                        int nr;
                                        cin >> nr;
                                        int it = 0;
                                        list<Ceas>::iterator i;
                                        i = listaCeasuri.begin();
                                        while (i != listaCeasuri.end()) {
                                            if (it == nr) {
                                                (i)->calculeazaRata();
                                            }
                                            advance(i, 1);
                                            it++;
                                        }
                                        break;

                                    }
                                    case 3: {
                                        cout
                                                << "\nIntroduceti indexul smartwatchului pentru care doriti sa efectuati functia";
                                        int nr;
                                        cin >> nr;
                                        int it = 0;
                                        list<Smartwatch>::iterator i;
                                        i = listaSmartwatch.begin();
                                        while (i != listaSmartwatch.end()) {
                                            if (it == nr) {
                                                (i)->calculeazaRata();
                                            }
                                            advance(i, 1);
                                            it++;
                                        }
                                        break;


                                    }
                                    case 4: {
                                        cout<< "\nIntroduceti indexul laptopului pentru care doriti sa efectuati functia";
                                        int nr;
                                        cin >> nr;
                                        int it = 0;
                                        list<Laptop>::iterator i;
                                        i = listaLaptop.begin();
                                        while (i != listaLaptop.end()) {
                                            if (it == nr) {
                                                (i)->calculeazaRata();
                                            }
                                            advance(i, 1);
                                            it++;
                                        }
                                        break;


                                    }
                                    case 5: {
                                        q = 0;
                                        break;
                                    }
                                    default: {
                                        cout << "\nAti introdus un numar gresit";
                                        break;
                                    }
                                }
                            }

                            break;
                        }
                        case 6: {
                            q = 0;
                            break;
                        }
                        default: {
                            cout << "\nAti introdus un numar gresit";
                            break;
                        }
                    }
                }
                break;
            }
            default: {
                cout<<"Ati introdus o valoare gresita";
                break;
            }
        }
        }

    return 0;
}
