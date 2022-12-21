#include <iostream>
#include <iterator>
#include <list>
#include<typeinfo>
#include<vector>
using namespace std;

class Interfata
{
public:
    virtual ostream& Afisare(ostream&)const=0;
    virtual istream& Citire(istream&)=0;
};

template<typename T1>
class RataLunara
{
private:
    T1 pret;
    int nr_luni;
public:
    void setPret(T1 pret)
    {
        this->pret=pret;
    }
    T1 getPret()
    {
        return this->pret;
    }
    void setLuni(int nr_luni)
    {
        this->nr_luni=nr_luni;
    }
    int getLuni()
    {
        return this->nr_luni;
    }
    //---------//
    T1 getRata()
    {
        return (this->pret)/(this->nr_luni);
    }

};

template<typename T1, typename T2>
T1 suma(T1 a, T2 b)
{
    return a+b;
}

class Dispozitiv:public Interfata
{
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

    ~Dispozitiv()
    {
    };
};
Dispozitiv::Dispozitiv()
{
    this->numeDispozitiv="Necunoscut";
    this->pret=0;
    this->firma="Necunoscuta";
    this->garantie=false;
}
Dispozitiv::Dispozitiv(string numeDispozitiv, float pret, string firma, bool garantie)
{
    this->numeDispozitiv=numeDispozitiv;
    this->pret=pret;
    this->firma=firma;
    this->garantie=garantie;
}
Dispozitiv::Dispozitiv(const Dispozitiv &dis)
{
    this->numeDispozitiv=dis.numeDispozitiv;
    this->pret=dis.pret;
    this->firma=dis.firma;
    this->garantie=dis.garantie;
}
Dispozitiv& Dispozitiv::operator=(const Dispozitiv &dis)
{
    if(this!=&dis)
    {
        this->numeDispozitiv=dis.numeDispozitiv;
        this->pret=dis.pret;
        this->firma=dis.firma;
        this->garantie=dis.garantie;
    }
    return *this;
}
ostream& Dispozitiv::Afisare(ostream& out)const
{
    out<<"\nNumele dispozitivului este: "<<this->numeDispozitiv<<"\n";
    out<<"Pretul dispozitivului este: "<<this->pret<<"\n";
    out<<"Firma care a produs dispozitivului este: "<<this->firma<<"\n";
    if(this->garantie)
    {
        out<<"Dispozitivul are garantie";
    }
    else
    {
        out<<"Dispozitivul  NU are garantie";
    }
    return out;
}
istream& Dispozitiv::Citire(istream& in)
{

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



class Telefon:public virtual Dispozitiv
{
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
    ~Telefon()
    {

    };

};
Telefon::Telefon():Dispozitiv()
{
    this->accesorii=false;
    this->tipMax=false;
}
Telefon::Telefon(string numeDispozitiv,float pret, string firma,bool garantie, bool accesorii, bool tipMax):Dispozitiv(numeDispozitiv,pret,firma,garantie)
{
    this->accesorii=accesorii;
    this->tipMax=tipMax;
}
Telefon::Telefon(const Telefon &tel):Dispozitiv(tel)
{
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

ostream& Telefon::Afisare(ostream& out) const
{

    Dispozitiv::Afisare(out);
    if(this->accesorii)
    {
        out<<"\nDispozitivul vine cu acesorii";
    }
    else
    {
        out<<"\nDispozitivul nu vine cu acceosorii";
    }
    if(this->tipMax)
    {
        out<<"\nDispozitivul este de tip max";
    }
    else
    {
        out<<"\nDispozitivul nu este de tip max";
    }
    return out;
}
istream& Telefon::Citire(istream& in)
{

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
void Telefon::calculeazaRata()
{
    float adaos=0;
    if(this->accesorii)
    {
        adaos=adaos+150.5;
    }
    if(this->tipMax)
    {
        adaos=adaos+550.5;
    }
    double pretNou=pret;
    pretNou=suma(pretNou, adaos);
    cout<<"In cate luni vrei sa platesti rata?";
    try
    {
        int nr;
        cin >> nr;
        RataLunara<double> rataT;
        rataT.setLuni(nr);
        rataT.setPret(pretNou);
        cout << pretNou << endl;
        cout << typeid(pretNou).name();
        if(nr!=0 && nr>3)
            cout << "\nRata lunara este " << rataT.getRata() << endl;
        else
        {
            throw string("Numarul de luni introdus invalid");
        }
    }
    catch(string s)
    {
        cout<<s<<endl;
    }

}
void Telefon::afiseazaDimensiuniTip()
{
    cout<<"Dimensiunile telefonului sunt:";
    if(this->tipMax)
    {
        cout<<"\nLungime ";
        cout<<"160,8 mm";
        cout<<"\nLatime ";
        cout<<"78,1 mm ";
        cout <<"\nGrosime ";
        cout<<"7,65 mm";
    }
    else
    {
        cout<<"\nLungime ";
        cout<<"146,7 mm";
        cout<<"\nLatime ";
        cout<<"71,5 mm";
        cout <<"\nGrosime ";
        cout<<"7,65 mm";
    }
    cout<<endl;
}

class Ceas:public virtual Dispozitiv
{
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

    ~Ceas()
    {
    }

};
Ceas::Ceas():Dispozitiv()
{
    this->pietrePretioase=false;
    this->ATM=0;
}
Ceas::Ceas(string numeDispozitiv,float pret, string firma,bool garantie, bool pietrePretioase, int ATM):Dispozitiv(numeDispozitiv,pret,firma,garantie)
{
    this->pietrePretioase=pietrePretioase;
    this->ATM=ATM;
}
Ceas::Ceas(const Ceas &c):Dispozitiv(c)
{
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
ostream& Ceas::Afisare(ostream& out) const
{

    Dispozitiv::Afisare(out);
    if(this->pietrePretioase)
    {
        out<<"\nDispozitivul contine pietre pretioase";
    }
    else
    {
        out<<"\nDispozitivul NU contine pietre pretioase";
    }
    out<<"\nDispozitivul are rezistenta la apa de "<<this->ATM<<" ATM";
    return out;
}
istream& Ceas::Citire(istream& in)
{

    Dispozitiv::Citire(in);
    cout<<"\nDispozitivul contine pietre pretioase: [1-true/0-false]";
    in>>this->pietrePretioase;
    cout<<"\nDati rezistenta la apa in ATM";
    in>>this->ATM;
    return in;
}
istream& operator>>(istream& in, Ceas& c)
{
    return c.Citire(in);
}
ostream& operator<<(ostream& out, const Ceas& c)
{
    return c.Afisare(out);
}
void Ceas::verificareRezistenta()
{
    if(this->ATM==30)
    {
        cout<<"\nRezistenta la scufundari profesionale";
    }
    if(this->ATM==10)
    {
        cout<<"\nRezistenta inot dar nu la scufundari";
    }
    if(this->ATM==5)
    {
        cout<<"\nRezistenta la stropi de apa";
    }
}
void Ceas::calculeazaRata()
{
    float adaos=0;
    if(this->pietrePretioase)
    {
        adaos=adaos+170.5;
    }
    if(this->ATM)
    {
        adaos=adaos+100;
    }
    int pretNou=pret;
    pretNou=suma(pretNou, adaos);
    cout<<"In cate luni vrei sa platesti rata?";
    int nr;
    cin>>nr;
    RataLunara<int>rataC;
    rataC.setLuni(nr);
    rataC.setPret(pretNou);
    cout<<pretNou<<endl;
    cout<<typeid(pretNou).name();
    if(nr!=0 && nr>3)
        cout << "\nRata lunara este " << rataC.getRata() << endl;
    else
    {
        throw string("Numarul de luni introdus invalid");
    }

}


class Smartwatch: public Telefon, public Ceas
{
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


    ~Smartwatch()
    {

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
    Ceas(numeDispozitiv,pret,firma,garantie,pietrePretioase,ATM)
{
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

ostream& Smartwatch::Afisare(ostream& out) const
{

    Dispozitiv::Afisare(out);

    if(this->accesorii)
    {
        out<<"\nDispozitivul vine cu acesorii";
    }
    else
    {
        out<<"\nDispozitivul nu vine cu acceosorii";
    }
    if(this->tipMax)
    {
        out<<"\nDispozitivul este de tip max";
    }
    else
    {
        out<<"\nDispozitivul nu este de tip max";
    }

    if(this->pietrePretioase)
    {
        out<<"\nDispozitivul contine pietre pretioase";
    }
    else
    {
        out<<"\nDispozitivul NU contine pietre pretioase";
    }
    out<<"\nDispozitivul are rezistenta la apa de "<<this->ATM<<" ATM";

    if(this->monitorizareFunctiiVitale)
    {
        out<<"\nDispozitivul poate monitoriza functiile vitale";
    }
    else
    {
        out<<"\nDispozitivul NU poate monitoriza functiile vitale";
    }
    out<<"\nDispozitivul este compatibil cu urmatoarul sistem de operare"<<this->sistemCompatibil;
    return out;
}
istream& Smartwatch::Citire(istream& in)
{

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
istream& operator>>(istream& in, Smartwatch& sw)
{
    return sw.Citire(in);
}
ostream& operator<<(ostream& out, const Smartwatch& sw)
{
    return sw.Afisare(out);
}
void Smartwatch::verificaCompatibilitate(string x)
{
    if(this->sistemCompatibil==x)
    {
        cout<<"\nSistemul de operare dorit este compatibil cu dispozitivul";
    }
    else
    {
        cout<<"\nSistemul de operare dorit nu este compatibil cu dispozitivul";
    }
}
void Smartwatch::calculeazaRata()
{
    int adaos=0;
    if(this->monitorizareFunctiiVitale)
    {
        adaos=adaos+200;
    }
    float pretNou=pret;
    pretNou=suma(pretNou, adaos);
    cout<<"In cate luni vrei sa platesti rata?";
    int nr;
    cin>>nr;
    RataLunara<float>rataS;
    rataS.setLuni(nr);
    rataS.setPret(pretNou);
    cout<<pretNou<<endl;
    cout<<typeid(pretNou).name();
    if(nr!=0 && nr>3)
        cout << "\nRata lunara este " << rataS.getRata() << endl;
    else
    {
        throw string("Numarul de luni introdus invalid");
    }

}

class Magazin
{
private:
    string numeM;
    string locatie;
public:
    Magazin();
    Magazin(string numeM, string locatie);
    Magazin(const Magazin& m);
    Magazin& operator=(const Magazin& m);
    friend ostream& operator<<(ostream& out,const Magazin& m);
    friend istream& operator>>(istream& in, Magazin& m);
    void setNumeM(string numeM);
    string getNumeM();
    ~Magazin() {}

};

void Magazin::setNumeM(string numeM)
{
    this->numeM=numeM;
}

string Magazin::getNumeM()
{
    return this->numeM;
}


Magazin::Magazin()
{
    this->numeM="anonim";
    this->locatie="necunoscuta";
}
Magazin::Magazin(string numeM, string locatie)
{
    this->numeM=numeM;
    this->locatie=locatie;
}
Magazin::Magazin(const Magazin &m)
{
    this->numeM=m.numeM;
    this->locatie=m.locatie;
}
Magazin& Magazin::operator=(const Magazin &m)
{
    if(this!=&m)
    {
        this->numeM=m.numeM;
        this->locatie=m.locatie;
    }
    return *this;
}
istream& operator>>(istream& in, Magazin& m)
{
    cout<<"\nNumele magazinului este: ";
    in>>m.numeM;
    cout<<"\nLocatia este: ";
    in>>m.locatie;
    return in;
}
ostream& operator<<(ostream& out, const Magazin& m)
{
    out<<"\nNumele magazinului este: "<<m.numeM;
    out<<"\nLocatia este: "<<m.locatie;
    return out;
}
class Singletone{
private:
    static Singletone *obiect;


    Singletone(){

    }
public:
    static Singletone* getInstance(){
        if(!obiect)
            obiect=new Singletone();


        return obiect;
    }
    void Meniu()
    {list<Magazin> listaMagazine;
    vector<Dispozitiv*> listaDispozitive;

    int k = 1;
    while (k == 1) {
        cout << "\n 1 Create";
        cout << "\n 2 Read";
        cout << "\n 3 Update";
        cout << "\n 4 Delete";
        cout << "\n 5 Stop";
        cout << "\n 6 Functionalitati";
        cout << endl;
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
                    cout << "\n 4 Magazin";
                    cout << "\n 5 Meniu";
                    int create;
                    cin >> create;
                    switch (create) {
                        case 1: {
                            Telefon a;
                            cin >> a;
                            listaDispozitive.push_back(new Telefon(a));
                            break;
                        }
                        case 2: {
                            Ceas a;
                            cin >> a;
                            listaDispozitive.push_back(new Ceas(a));
                            break;
                        }
                        case 3: {
                            Smartwatch a;
                            cin >> a;
                            listaDispozitive.push_back(new Smartwatch(a));
                            break;
                        }
                        case 4: {
                            Magazin a;
                            cin >> a;
                            listaMagazine.push_back(a);
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
                    cout << "\n 1  Lista Dispozitive";
                    cout << "\n 2 Lista Magazine";
                    cout << "\n 3 Meniu";
                    int afiseaza;
                    cin >> afiseaza;
                    switch (afiseaza) {
                        case 1: {
                            for (int i = 0; i < listaDispozitive.size(); i++)
                                cout << *listaDispozitive[i];
                            break;
                        }
                        case 2: {
                            list<Magazin>::iterator i;
                            i = listaMagazine.begin();
                            while (i != listaMagazine.end()) {
                                cout << (*i) << endl;
                                advance(i, 1);
                            }
                            break;
                        }
                        case 3: {
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
                cout << "\nPentru ce doriti sa faceti update?";
                cout << "\n1-Lista Dispozitive";
                cout << "\n2-Magazin";
                cout << "\n3-Meniu";
                cout << endl;
                int q1;
                cin >> q1;
                switch (q1) {

                    case 1: {
                        cout << "\nIntroduceti indexul elementului caruia doriti sa il inlocuiti:" << endl;
                        int index;
                        cin >> index;
                        int it = 0;
                        int q = 1;
                        while (q == 1) {
                            cout << "\nCu ce tip de dispozitiv doriti sa il inlocuiti?";
                            cout << "\n 1 Telefon";
                            cout << "\n 2 Ceas";
                            cout << "\n 3 Smartwatch";
                            cout << "\n 4 Meniu";
                            int update;
                            cin >> update;
                            switch (update) {
                                case 1: {
                                    int ok = 0;
                                    for (int i = 0; i < listaDispozitive.size(); i++) {
                                        if (i == index) {
                                            ok = 1;
                                            delete listaDispozitive[index];
                                            Telefon a;
                                            cin >> a;
                                            listaDispozitive[index] = new Telefon(a);
                                        }
                                    }
                                    if (ok == 0) {
                                        cout << "index introdus gresit";
                                    }
                                    break;

                                }
                                case 2: {
                                    int ok = 0;
                                    for (int i = 0; i < listaDispozitive.size(); i++) {
                                        if (i == index) {
                                            ok = 1;
                                            delete listaDispozitive[index];
                                            Ceas a;
                                            cin >> a;
                                            listaDispozitive[index] = new Ceas(a);
                                        }
                                    }
                                    if (ok == 0) {
                                        cout << "index introdus gresit";
                                    }
                                    break;

                                }
                                case 3: {
                                    int ok = 0;
                                    for (int i = 0; i < listaDispozitive.size(); i++) {
                                        if (i == index) {
                                            ok = 1;
                                            delete listaDispozitive[index];
                                            Smartwatch a;
                                            cin >> a;
                                            listaDispozitive[index] = new Smartwatch(a);
                                        }
                                    }
                                    if (ok == 0) {
                                        cout << "index introdus gresit";
                                    }
                                    break;

                                }
                                case 4: {
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
                        cout << "\nIntroduceti indexul elementului caruia doriti sa ii faceti update:" << endl;
                        int index;
                        cin >> index;
                        int ok = 0;
                        int it = 0;
                        list<Magazin>::iterator i;
                        i = listaMagazine.begin();
                        while (i != listaMagazine.end()) {
                            if (it == index) {
                                cout << "\nCu ce doriti sa faceti update?" << endl;
                                Magazin a;
                                cin >> a;
                                *i = a;
                                ok = 1;
                            }
                            advance(i, 1);
                            it++;
                        }
                        if (ok == 0) { cout << "Index introdus gresit"; }

                        break;
                    }
                    case 3: {
                        q1 = 0;
                        break;
                    }
                    default: {
                        cout << "Ati introdus o valoare gresita";
                        break;
                    }

                }
            }
            case 4: {
                int q = 1;
                while (q == 1) {
                    cout << "\nSterge:";
                    cout << "\n 1 Dispozitiv";
                    cout << "\n 2 Magazin";
                    cout << "\n 3 Meniu";
                    int sterge;
                    cin >> sterge;
                    switch (sterge) {
                        case 1: {
                            cout << "\nIntroduceti indexul elementului pe care doriti sa il stergeti" << endl;
                            int index;
                            cin >> index;
                            int ok = 0;
                            for (int i = 0; i < listaDispozitive.size(); i++) {
                                if (i == index) {
                                    ok = 1;
                                    delete listaDispozitive[index];
                                }
                            }
                            if (ok == 0) {
                                cout << "index introdus gresit";
                            }
                            break;
                        }
                        case 2: {
                            cout << "\nIntroduceti indexul elementului pe care doriti sa il stergeti" << endl;
                            int index;
                            cin >> index;
                            int it = 0;
                            int ok = 0;
                            list<Magazin>::iterator i;
                            i = listaMagazine.begin();
                            while (i != listaMagazine.end()) {
                                if (it == index) {
                                    listaMagazine.erase(i);
                                    ok = 1;
                                    break;
                                }
                                advance(i, 1);
                                it++;
                            }
                            if (ok == 0) { cout << "Ati introdus un nr gresit"; }
                            break;
                        }
                        case 3: {
                            q = 0;
                            break;
                        }
                        default: {
                            cout << "Ati introdus o valoare gresita";
                            break;
                        }
                    }
                }
            }
            case 5: {
                k = 0;
                break;
            }
            case 6: {
                cout << "Functii";
                int q = 1;
                while (q == 1) {
                    cout << "\nFunctie:";
                    cout << "\n 1 Afiseaza dimensiunile telefonului in functie de tipul acestuia";
                    cout << "\n 2 Afiseaza rezistenta ceasului la apa";
                    cout
                            << "\n 3 Afiseaza daca sistemul de operare compatibil cu smartwatch-ul este cel dorit de client";
                    cout << "\n 4 Calculeaza rata";
                    cout << "\n 5 Meniu";
                    int functie;
                    cin >> functie;
                    switch (functie) {
                        case 1:
                {
                    cout << "\nIntroduceti indexul telefonului pentru care doriti sa efectuati functia";
                    int nr;
                    cin >> nr;

                    try
                    {
                        if(0<=nr && nr<listaDispozitive.size())
                        {
                            try
                            {
                                Telefon& tel=dynamic_cast<Telefon&>(*listaDispozitive[nr]);

                                tel.afiseazaDimensiuniTip();
                            }
                            catch(exception& e)
                            {
                                cout<<e.what()<<endl;
                            }

                        }
                        else throw  string ("Bad contor");
                    }

                    catch( string s)
                    {

                        cout<<s<<endl;


                    }





                    break;
                }
                        case 2:
                {
                    cout << "\nIntroduceti indexul ceasului pentru care doriti sa efectuati functia";
                    int nr;
                    cin >> nr;

                    try
                    {
                        if(0<=nr && nr<listaDispozitive.size())
                        {
                            try
                            {
                                Ceas& cs=dynamic_cast<Ceas&>(*listaDispozitive[nr]);

                                cs.verificareRezistenta();
                            }
                            catch(exception& e)
                            {
                                cout<<e.what()<<endl;
                            }

                        }
                        else throw  string ("Bad contor");
                    }

                    catch( string s)
                    {

                        cout<<s<<endl;


                    }





                    break;
                }
                        case 3:
                {
                    cout << "\nIntroduceti indexul smartwatchului pentru care doriti sa efectuati functia";
                    int nr;
                    cin >> nr;

                    try
                    {
                        if(0<=nr && nr<listaDispozitive.size())
                        {
                            try
                            {
                                Smartwatch& sw=dynamic_cast<Smartwatch&>(*listaDispozitive[nr]);

                                sw.verificaCompatibilitate("ios");
                            }
                            catch(exception& e)
                            {
                                cout<<e.what()<<endl;
                            }

                        }
                        else throw  string ("Bad contor");
                    }

                    catch( string s)
                    {

                        cout<<s<<endl;


                    }





                    break;
                }
                        case 4:
                {
                    cout << "\nIntroduceti indexul dispozitivului pentru care doriti sa calculati rata";
                    int nr;
                    cin >> nr;

                    try
                    {
                        if(0<=nr && nr<listaDispozitive.size())
                        {
                             listaDispozitive[nr]->calculeazaRata();

                        }
                        else throw  string ("Bad contor");
                    }

                    catch( string s)
                    {

                        cout<<s<<endl;


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

            }
            default: {
                cout << "Ati introdus o valoare gresita";
                break;
            }

        }
    }

    }


};
Singletone* Singletone::obiect=0;


int main() {
     Singletone *meniulMeu=meniulMeu->getInstance();
     meniulMeu->Meniu();


    return 0;
}
