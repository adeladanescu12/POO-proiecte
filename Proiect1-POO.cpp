#include <iostream>
#include <string.h>

using namespace std;

class Agent{
private:
    char* nume;
    char initiala;
    string prenume;
    float salariu;
    float* oreMuncaInUltimeleZile;//cate ore a muncit agentul de turism in ultimele n zile
    int nZile;

    const int idAgent;
    static int contorId;

public:
    Agent();
    Agent(char* nume,char initiala, string prenume,float salariu, float* oreMuncaInUltimeleZile, int nZile);
    Agent(char* nume, string prenume);
    Agent(char* nume, string prenume,float salariu);
    Agent(const Agent& ag);
    Agent& operator= (const Agent& ag);

    friend istream& operator>>(istream& in, Agent& ag);
    friend ostream& operator<<(ostream& out,const Agent& ag);

    char operator[](int index);

    const Agent& operator++();
    Agent operator++(int);
    Agent operator+=(float x);
    Agent operator+(float y);
    Agent operator+(Agent ag);
    friend Agent operator+(float y, Agent ag);

    const Agent& operator--();
    Agent operator--(int);
    Agent operator-=(float x);
    Agent operator-(float y);
    Agent operator-(Agent ag);
    friend Agent operator-(float y, Agent ag);


    bool operator<(const Agent& ag);
    bool operator==(const Agent& ag);

    explicit operator int();


    void setNume(char* nume);
    void setPrenume(string prenume);
    void setInitiala(char initiala);
    void setSalariu(float salariu);
    void setOreMuncaInUltimeleZile(float * oreMuncaInUltimeleZile, int nZile);


    const char* getNume();
    string getPrenume();
    char getInitiala();
    float getSalariu();
    const float* getOreMuncaInUltimeleZile();
    int getNZile();
    static int getContorId();
    const int getIdAgent();

    void verificareRaportSalariuOreLucrate(); //in functie de nr de ore lucrate in ultimele n zile si salariu, agentul primeste marire sau micsorare de salariu


    ~Agent();
};

void  Agent::setNume(char* nume)
{
    if(this->nume!=NULL)
        delete[] this->nume;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);

}
void  Agent::setInitiala(char initiala)
{

    this->initiala=initiala;
}
void  Agent::setPrenume(string prenume){
    this->prenume=prenume;
}
void  Agent::setSalariu(float salariu)
{

    this->salariu=salariu;
}
void Agent::setOreMuncaInUltimeleZile(float * oreMuncaInUltimeleZile, int nZile)
{
    if(this->oreMuncaInUltimeleZile!=NULL)
        delete[] this->oreMuncaInUltimeleZile;
    this->nZile=nZile;
    this->oreMuncaInUltimeleZile=new float[this->nZile];
    for(int i=0; i<this->nZile; i++)
        this->oreMuncaInUltimeleZile[i]=oreMuncaInUltimeleZile[i];

}


const char*  Agent::getNume()
{
    return this->nume;
}
string Agent::getPrenume() {
    return this->prenume;
}
char Agent::getInitiala()
{

    return this->initiala;
}
float Agent::getSalariu()
{

    return this->salariu;
}
const float* Agent::getOreMuncaInUltimeleZile()
{
    return this->oreMuncaInUltimeleZile;
}
int  Agent::getNZile()
{
    return this->nZile;
}


char Agent::operator[](int index) {

    if (0 <= index && index < strlen(this->nume) + 1)
        return this->nume[index];
    cout << "Index introdus gresit";

}


const Agent& Agent::operator++(){
    this->salariu++;
    return *this;
}
Agent Agent::operator++(int) {
    Agent aux(*this);
    this->salariu++;
    return aux;
}
Agent Agent::operator+=(float x){
    this->salariu+=x;
    return *this;
}
Agent Agent::operator+(float y){
    Agent aux = *this;
    aux.salariu = aux.salariu + y;
    return aux;
}
Agent Agent::operator+(Agent ag){
    ag.prenume = ag.prenume + " + " + this->prenume;
    ag.salariu=ag.salariu + this->salariu;

    return ag;
}
Agent operator+(float y, Agent ag){
    ag.salariu = ag.salariu + y;
    return ag;
}


const Agent& Agent::operator--(){
    this->salariu--;
    return *this;
}
Agent Agent::operator--(int) {
    Agent aux(*this);
    this->salariu--;
    return aux;
}
Agent Agent::operator-=(float x){
    this->salariu-=x;
    return *this;
}
Agent Agent::operator-(float y){
    Agent aux = *this;
    aux.salariu = aux.salariu - y;
    return aux;
}
Agent Agent::operator-(Agent ag){
    ag.prenume = ag.prenume + " - " + this->prenume;
    ag.salariu=ag.salariu - this->salariu;

    return ag;
}
Agent operator-(float y, Agent ag){
    ag.salariu = ag.salariu - y;
    return ag;
}


bool Agent::operator<(const Agent& ag) {
    if (this->salariu < ag.salariu)
        return true;
    return false;
}
bool Agent::operator==(const Agent& ag) {
    if (this->salariu == ag.salariu)
        return true;
    return false;
}

istream& operator>>(istream& in, Agent& ag){
    cout<<"Nume:";
    char aux[100];
    in>>aux;

    if(ag.nume!=NULL)
        delete[] ag.nume;
    ag.nume=new char[strlen(aux)+1];
    strcpy(ag.nume,aux);

    cout<<"\nInitiala: ";
    in>>ag.initiala;

    cout<<"\nPrenume: ";
    in>>ag.prenume;

    cout<<"\nSalariu: ";
    in>>ag.salariu;

    cout<<"\nPe cate zile contorizam? ";
    in>>ag.nZile;
    cout<<"\nOre lucrate: ";

    if(ag.oreMuncaInUltimeleZile!=NULL)
        delete[] ag.oreMuncaInUltimeleZile;
    ag.oreMuncaInUltimeleZile=new float[ag.nZile];
    for(int i=0; i<ag.nZile; i++)
        in>>ag.oreMuncaInUltimeleZile[i];

    return in;
}
ostream& operator<<(ostream& out,const Agent& ag){
    out<<"\nNume: "<<ag.nume;
    out<<"\nInitiala: "<<ag.initiala;
    out<<"\nPrenume: "<<ag.prenume;
    out<<"\nSalariu: "<<ag.salariu;
    out<<"\nIn ultimele "<<ag.nZile<<" agentul de turism a lucrat: ";
    for(int i=0; i<ag.nZile; i++)
        out<<ag.oreMuncaInUltimeleZile[i]<<" ore, ";
    return out;
}


Agent::Agent() :idAgent(contorId++)
{
    this->nume = new char[strlen("Anonim") + 1];
    strcpy(this->nume, "Anonim");
    this->initiala = '/';
    this->prenume = "Anonim";
    this->salariu=0;
    this->oreMuncaInUltimeleZile = NULL;
    this->nZile = 0;

}
Agent::Agent(char* nume, char initiala, string prenume, float salariu, float* oreMuncaInUltimeleZile, int nZile):idAgent(contorId++){

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->initiala = initiala;
    this->prenume = prenume;
    this->salariu = salariu;
    this->nZile = nZile;
    this->oreMuncaInUltimeleZile = new float[this->nZile];
    for (int i = 0; i < this->nZile; i++)
        this->oreMuncaInUltimeleZile[i] = oreMuncaInUltimeleZile[i];

}
Agent::Agent(char *nume, string prenume):idAgent(contorId++){
    this->nume = new char[strlen(nume) + 1];
    this->initiala = '/';
    strcpy(this->nume, nume);
    this->prenume = prenume;
    this->salariu=0;
    this->oreMuncaInUltimeleZile = NULL;
    this->nZile = 0;
}
Agent::Agent(char *nume, string prenume, float salariu):idAgent(contorId++){
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->initiala = '/';
    this->prenume = prenume;
    this->salariu = salariu;
    this->oreMuncaInUltimeleZile = NULL;
    this->nZile = 0;
}
Agent::Agent(const Agent& ag) :idAgent(ag.idAgent)
{

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, ag.nume);

    this->initiala = ag.initiala;

    this->prenume = ag.prenume;

    this->salariu = ag.salariu;

    this->nZile = ag.nZile;
    this->oreMuncaInUltimeleZile = new float[this->nZile];
    for (int i = 0; i < this->nZile; i++)
        this->oreMuncaInUltimeleZile[i] = ag.oreMuncaInUltimeleZile[i];
}
Agent& Agent::operator= (const Agent& ag)
{

    if (this != &ag)
    {

        if (this->nume != NULL)
            delete[] this->nume;
        if (this->oreMuncaInUltimeleZile != NULL)
            delete[] this->oreMuncaInUltimeleZile;

        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, ag.nume);

        this->initiala = ag.initiala;
        this->prenume = ag.prenume;
        this->salariu = ag.salariu;
        this->nZile = ag.nZile;
        this->oreMuncaInUltimeleZile = new float[this->nZile];
        for (int i = 0; i < this->nZile; i++)
            this->oreMuncaInUltimeleZile[i] = ag.oreMuncaInUltimeleZile[i];


    }

    return *this;

}

void Agent::verificareRaportSalariuOreLucrate() {
    float medieOre=0;
    if(this->nZile>0)
    {
        for(int i =0; i < this->nZile; i++)
        {
            medieOre=medieOre + this->oreMuncaInUltimeleZile[i];
        }
        medieOre=medieOre/this->nZile;
    }
    if(medieOre>8 && this->salariu<=5000){cout<<"\nAgentul de turism a lucrat peste program si primeste o marire de salariu.";}
    if(medieOre>8 && this->salariu>5000){cout<<"\nAgentul de turism a lucrat peste program si beneficiaza deja de o marire de salariu.";}
    if(medieOre==8){cout<<"\nAgentul a lucrat numarul de ore aferent salariului";}
    if(medieOre<8){cout<<"\nAgentul nu a lucrat numarul de ore aferent salariului si i se va micsora salariul";}

}
Agent::operator int(){
    return (int)this->salariu;
}
int Agent::getContorId() {
    return Agent::contorId;
}
const int Agent::getIdAgent() {
    return this->idAgent;
}
Agent::~Agent()
{
    if (this->nume != NULL)
        delete[] this->nume;
    if (this->oreMuncaInUltimeleZile != NULL)
        delete[] this->oreMuncaInUltimeleZile;
}
int Agent::contorId=1000;

//----------------------------------------------------------------------------------------------------------------------------------------------//
class Sediu{
private:
    char* oras; //orasul din care e sediul care face parte din agentie
    int vechime;
    float* IncasariUltimiiNAni; //Incasarile pe an in ultimii n ani
    int nAni;
    float notaReview; //nota acordata sediului pe baza reviewurilor primite
    Agent* listaAgenti; //lista agentii de turism angajati la sediu
    int lungimeLista;


public:
    Sediu();
    Sediu(char* oras, int vechime,  float* IncasariUltimiiNAni, int nAni, float notaReview, Agent* listaAgenti,int lungimeLista);
    Sediu(char* oras);
    Sediu(char* oras, int vechime);
    Sediu(const Sediu& sd);
    Sediu& operator= (const Sediu& sd);

    friend istream& operator>>(istream& in, Sediu& sd);
    friend ostream& operator<<(ostream& out,const Sediu& sd);

    friend Sediu operator+(Sediu sd, const Agent& ag);
    friend Sediu operator+(const Agent& ag, Sediu sd);

    float operator[](int index);

    const Sediu& operator++();
    Sediu operator++(int); //
    Sediu operator+=(int x);
    Sediu operator+(int y);
    Sediu operator+(Sediu sd);
    friend Sediu operator+(int y, Sediu sd);

    const Sediu& operator--();
    Sediu operator--(int);
    Sediu operator-=(int x);
    Sediu operator-(int y);
    Sediu operator-(Sediu sd);
    friend Sediu operator-(int y, Sediu sd);

    bool operator<(const Sediu& sd);
    bool operator==(const Sediu& sd);

    explicit operator int();

    void setOras(char* oras);
    void setVechime(int vechime);
    void setIncasariUltimiiNAni(float* IncasariUltimiiNAni, int nAni);
    void setNotaReview(float notaReview);

    const char* getOras();
    int getVechime();
    const float* getIncasariUltimiiNAni();
    int getnAni();
    float getNotaReview();

    void celMaiMareSiMicCastig(); //functia da cel mai mare si mai mic castig din ultimii n ani
    ~Sediu();

};

void Sediu::setOras(char* oras){
    if(this->oras!=NULL)
        delete[] this->oras;
    this->oras=new char[strlen(oras)+1];
    strcpy(this->oras,oras);
}
void Sediu::setVechime(int vechime){
    this->vechime=vechime;
}
void Sediu::setIncasariUltimiiNAni(float* IncasariUltimiiNAni, int nAni){
    if(this->IncasariUltimiiNAni!=NULL)
        delete[] this->IncasariUltimiiNAni;
    this->nAni=nAni;
    this->IncasariUltimiiNAni=new float[this->nAni];
    for(int i=0; i<this->nAni; i++)
        this->IncasariUltimiiNAni[i]=IncasariUltimiiNAni[i];
}
void Sediu::setNotaReview(float notaReview) {
    this->notaReview=notaReview;
}

const char*  Sediu::getOras() {
    return this->oras;
}
int Sediu::getVechime() {
    return this->vechime;
}
const float* Sediu::getIncasariUltimiiNAni(){     //??????????????trb si const
    return this->IncasariUltimiiNAni;
}
int Sediu::getnAni() {
    return this->nAni;
}
float Sediu::getNotaReview(){
    return this->notaReview;
}

float Sediu::operator[](int index) {

    if (0 <= index && index < this->nAni)
        return this->IncasariUltimiiNAni[index];
    cout << "Index introdus gresit";

}

const Sediu& Sediu::operator++(){
    this->vechime++;
    return *this;
}
Sediu Sediu::operator++(int){
    Sediu aux(*this);
    this->vechime++;
    return aux;
}
Sediu Sediu::operator+=(int x){
    this->vechime+=x;
    return *this;
}
Sediu Sediu::operator+(int y){
    Sediu aux = *this;
    aux.vechime = aux.vechime + y;
    return aux;
}
Sediu Sediu::operator+(Sediu sd){

    sd.vechime=sd.vechime + this->vechime;

    return sd;
}
Sediu operator+(int y, Sediu sd){
    sd.vechime = sd.vechime + y;
    return sd;
}

const Sediu& Sediu::operator--(){
    this->vechime--;
    return *this;
}
Sediu Sediu::operator--(int){
    Sediu aux(*this);
    this->vechime--;
    return aux;
}
Sediu Sediu::operator-=(int x){
    this->vechime-=x;
    return *this;
}
Sediu Sediu::operator-(int y){
    Sediu aux = *this;
    aux.vechime = aux.vechime - y;
    return aux;
}
Sediu Sediu::operator-(Sediu sd){

    sd.vechime=sd.vechime - this->vechime;

    return sd;
}
Sediu operator-(int y, Sediu sd){
    sd.vechime = sd.vechime - y;
    return sd;
}

Sediu::operator int(){
    return (int)this->notaReview;
}

bool Sediu::operator==(const Sediu& sd) {
    if (this->vechime == sd.vechime)
        return true;
    return false;
}
bool Sediu::operator<(const Sediu& sd) {
    if (this->vechime < sd.vechime)
        return true;
    return false;
}

istream& operator>>(istream& in, Sediu& sd){
    cout<<"Oras:";
    char aux[100];
    in>>aux;

    if(sd.oras!=NULL)
        delete[] sd.oras;
    sd.oras=new char[strlen(aux)+1];
    strcpy(sd.oras,aux);

    cout<<"\nVechime: ";
    in>>sd.vechime;

    cout<<"\nPe cati ani contorizam? ";
    in>>sd.nAni;
    cout<<"\nIncasari: ";

    if(sd.IncasariUltimiiNAni!=NULL)
        delete[] sd.IncasariUltimiiNAni;
    sd.IncasariUltimiiNAni=new float[sd.nAni];
    for(int i=0; i<sd.nAni; i++)
        in>>sd.IncasariUltimiiNAni[i];

    cout<<"\nNota review: ";
    in >>sd.notaReview;

    cout << "\nNr agenti: ";
    in >> sd.lungimeLista;
    cout << "\nAgentii: ";
    if (sd.listaAgenti != NULL)
        delete[] sd.listaAgenti;
    sd.listaAgenti = new Agent[sd.lungimeLista];
    for (int i = 0; i < sd.lungimeLista; i++)
        cin >> sd.listaAgenti[i];


    return in;
}
ostream& operator<<(ostream& out,const Sediu& sd){
    out<<"\nOras: "<<sd.oras;
    out<<"\nVechime: "<<sd.vechime;
    out<<"\nIn ultimii "<<sd.nAni<<" ani incasarile din acest sediu au fost: ";
    for(int i=0; i<sd.nAni; i++)
        out<<sd.IncasariUltimiiNAni[i]<<", ";
    out<<"\nNota Review: " <<sd.notaReview<<endl;
    out << "\nAgentii sunt: "<< endl;
    for (int i = 0; i < sd.lungimeLista; i++)
        out << sd.listaAgenti[i] << "\n";

    return out;
}

Sediu operator+(const Agent& ag, Sediu sd) {
    Agent* listaAgentiAux;
    listaAgentiAux = new Agent[sd.lungimeLista];
    for (int i = 0; i < sd.lungimeLista; i++) {
        listaAgentiAux[i] = sd.listaAgenti[i];
    }
    if (sd.listaAgenti != NULL)
        delete[] sd.listaAgenti;

    sd.lungimeLista++;

    sd.listaAgenti = new Agent[sd.lungimeLista];
    for (int i = 0; i < sd.lungimeLista - 1; i++)
        sd.listaAgenti[i] = listaAgentiAux[i];

    sd.listaAgenti[sd.lungimeLista - 1] = ag;

    if (listaAgentiAux != NULL)
        delete[] listaAgentiAux;
    return sd;
}


Sediu operator+(Sediu sd, const Agent& ag) {

    Agent* listaAgentiAux;
    listaAgentiAux = new Agent[sd.lungimeLista];
    for (int i = 0; i < sd.lungimeLista; i++) {
        listaAgentiAux[i] = sd.listaAgenti[i];
    }
    if (sd.listaAgenti != NULL)
        delete[] sd.listaAgenti;

    sd.lungimeLista++;

    sd.listaAgenti = new Agent[sd.lungimeLista];
    for (int i = 0; i < sd.lungimeLista - 1; i++)
        sd.listaAgenti[i] = listaAgentiAux[i];

    sd.listaAgenti[sd.lungimeLista - 1] = ag;

    if (listaAgentiAux != NULL)
        delete[] listaAgentiAux;
    return sd;
}


Sediu::Sediu() {

    this->oras = new char[strlen("Necunoscut") + 1];
    strcpy(this->oras, "Necunoscut");

    this->vechime = 0;

    this->IncasariUltimiiNAni = NULL;

    this->nAni = 0;
    this->notaReview = 0;
    this->listaAgenti = 0;
    this->lungimeLista=0;
}
Sediu::Sediu(char *oras, int vechime, float* IncasariUltimiiNAni, int nAni, float notaReview, Agent* listaAgenti,int lungimeLista) {

    this->oras = new char[strlen(oras) + 1];
    strcpy(this->oras, oras);

    this->vechime = vechime;

    this->nAni = nAni;

    this->IncasariUltimiiNAni = new float[this->nAni];
    for (int i = 0; i < this->nAni; i++)
        this->IncasariUltimiiNAni[i] = IncasariUltimiiNAni[i];
    this->notaReview = notaReview;

    this->lungimeLista = lungimeLista;
    this->listaAgenti = new Agent[lungimeLista];
    for (int i = 0; i < lungimeLista; i++)
        this->listaAgenti[i] = listaAgenti[i];
}
Sediu::Sediu(char *oras){
    this->oras = new char[strlen(oras) + 1];
    strcpy(this->oras, oras);
    this->vechime = 0;
    this->IncasariUltimiiNAni = NULL;
    this->nAni = 0;
    this->notaReview = 0;
    this->listaAgenti = 0;
    this->lungimeLista=0;
}
Sediu::Sediu(char *oras, int vechime){
    this->oras = new char[strlen(oras) + 1];
    strcpy(this->oras, oras);
    this->vechime = vechime;

    this->IncasariUltimiiNAni = NULL;
    this->nAni = 0;
    this->notaReview = 0;
    this->listaAgenti = 0;
    this->lungimeLista=0;
}
Sediu::Sediu(const Sediu &sd) {
    this->oras = new char[strlen(sd.oras) + 1];
    strcpy(this->oras, sd.oras);

    this->vechime = sd.vechime;

    this->nAni = sd.nAni;
    this->IncasariUltimiiNAni = new float[this->nAni];
    for (int i = 0; i < this->nAni; i++)
        this->IncasariUltimiiNAni[i] = sd.IncasariUltimiiNAni[i];
    this->notaReview = sd.notaReview;

    this->lungimeLista = sd.lungimeLista;
    this->listaAgenti = new Agent[sd.lungimeLista];
    for (int i = 0; i < sd.lungimeLista; i++)
        this->listaAgenti[i] = sd.listaAgenti[i];
}
Sediu &Sediu::operator=(const Sediu &sd) {
    if(this!=&sd){

        if(this->oras!=NULL)
            delete[] this->oras;
        if(this->IncasariUltimiiNAni!=NULL)
            delete[] this->IncasariUltimiiNAni;


        this->oras=new char[strlen(sd.oras)+1];
        strcpy(this->oras,sd.oras);

        this->vechime=sd.vechime;

        this->nAni=sd.nAni;
        this->IncasariUltimiiNAni = new float[this->nAni];
        for (int i = 0; i < this->nAni; i++)
            this->IncasariUltimiiNAni[i] = sd.IncasariUltimiiNAni[i];

        this->notaReview = sd.notaReview;

        this->lungimeLista = sd.lungimeLista;
        this->listaAgenti = new Agent[sd.lungimeLista];
        for (int i = 0; i < sd.lungimeLista; i++)
            this->listaAgenti[i] = sd.listaAgenti[i];
    }

    return *this;
}



void Sediu::celMaiMareSiMicCastig() {
    float mic=0, mare=0;
    if(this->nAni>0)
    {
        mic=IncasariUltimiiNAni[0];
        mare=0;
        for(int i=0; i<this->nAni; i++)
        {
            if(mic>this->IncasariUltimiiNAni[i]){mic=this->IncasariUltimiiNAni[i];}
            if(mare<this->IncasariUltimiiNAni[i]){mare=this->IncasariUltimiiNAni[i];}
        }
    }
    cout<<"\nCea mai mare incasare din ultimii "<<nAni<<" ani este: "<<mare<<" si cea mai mica incasare este: "<<mic;
}
Sediu::~Sediu() {
    if(this->oras!=NULL)
        delete[] this->oras;
    if(this->IncasariUltimiiNAni!=NULL)
        delete[] this->IncasariUltimiiNAni;
    if(this->listaAgenti!=NULL)
        delete[] this->listaAgenti;
}


//-------------------------------------------------------------------------------------------------------------------------------//
class Client{
private:
    char* nume;
    string prenume;
    string destinatieDorita;
    float buget;
    bool bugetFlexibil; //1 daca clientul are bugetul flexibil si 0 daca nu
    int nrVacantePlanificateCuAgentia; //numarul de vacante pe care le-a planificat clientul cu agentia pana acum

public:
    Client();
    Client(char* nume, string prenume, string destinatieDorita, float buget, bool bugetFlexibil, int nrVacantePlanificateCuAgentia);
    Client(char* nume, string prenume);
    Client(char* nume, string prenume, int nrVacantePlanificateCuAgentia);
    Client(const Client& ct);
    Client& operator= (const Client& ct);

    friend istream& operator>>(istream& in, Client& ct);
    friend ostream& operator<<(ostream& out,const Client& ct);

    char operator[](int index);

    const Client& operator++();
    Client operator++(int);
    Client operator+=(int x);
    Client operator+(int y);
    Client operator+(Client ct);
    friend Client operator+(int y, Client ct);

    const Client& operator--();
    Client operator--(int);
    Client operator-=(int x);
    Client operator-(int y);
    Client operator-(Client ct);
    friend Client operator-(int y, Client ct);


    bool operator<(const Client& ct);
    bool operator==(const Client& ct);
    explicit operator int();

    void setNume(char* nume);
    void setPrenume(string prenume);
    void setDestinatieDorita(string destinatieDorita);
    void setBuget(float buget);
    void setBugetFlexibil(bool bugetFlexibil);
    void setNrVacantePlanificateCuAgentia(int nrVacantePlanificateCuAgentia);


    const char* getNume();
    string getPrenume();
    string getDestinatieDorita();
    float getBuget();
    bool getBugetFlexibil();
    int getNrVacantePlanificateCuAgentia();

    void VerificareClientFidel();

    ~Client();

};
void Client::setNume(char *nume){
    if(this->nume!=NULL)
        delete[] this->nume;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}
void Client::setPrenume(string prenume){
    this->prenume=prenume;
}
void Client::setDestinatieDorita(string destinatieDorita){
    this->destinatieDorita=destinatieDorita;
}
void Client::setBuget(float buget){
    this->buget=buget;
}
void Client::setBugetFlexibil(bool bugetFlexibil){
this-> bugetFlexibil= bugetFlexibil;
}
void Client::setNrVacantePlanificateCuAgentia(int nrVacantePlanificateCuAgentia){
this-> nrVacantePlanificateCuAgentia= nrVacantePlanificateCuAgentia;
}

const char*  Client::getNume(){
    return this->nume;
}
string Client::getPrenume() {
    return this->prenume;
}
string Client::getDestinatieDorita() {
    return this->destinatieDorita;
}
float Client::getBuget() {
    return this->buget;
}
bool Client::getBugetFlexibil() {
    return this->bugetFlexibil;
}
int Client::getNrVacantePlanificateCuAgentia() {
    return this->nrVacantePlanificateCuAgentia;
}

Client::operator int(){
    return (int)this->buget;
}

char Client::operator[](int index) {

    if (0 <= index && index < strlen(this->nume) + 1)
        return this->nume[index];
    cout << "Index introdus gresit";

}

const Client& Client::operator++(){
    this->nrVacantePlanificateCuAgentia++;
    return *this;
}
Client Client::operator++(int) {
    Client aux(*this);
    this->nrVacantePlanificateCuAgentia++;
    return aux;
}
Client Client::operator+=(int x){
    this->nrVacantePlanificateCuAgentia+=x;
    return *this;
}
Client Client::operator+(int y){
    Client aux = *this;
    aux.nrVacantePlanificateCuAgentia = aux.nrVacantePlanificateCuAgentia + y;
    return aux;
}
Client Client::operator+(Client ct){
    ct.prenume = ct.prenume + " + " + this->prenume;
    ct.nrVacantePlanificateCuAgentia=ct.nrVacantePlanificateCuAgentia + this->nrVacantePlanificateCuAgentia;

    return ct;
}
Client operator+(int y, Client ct){
    ct.nrVacantePlanificateCuAgentia = ct.nrVacantePlanificateCuAgentia + y;
    return ct;
}

const Client& Client::operator--(){
    this->nrVacantePlanificateCuAgentia--;
    return *this;
}
Client Client::operator--(int) {
    Client aux(*this);
    this->nrVacantePlanificateCuAgentia--;
    return aux;
}
Client Client::operator-=(int x){
    this->nrVacantePlanificateCuAgentia-=x;
    return *this;
}
Client Client::operator-(int y){
    Client aux = *this;
    aux.nrVacantePlanificateCuAgentia = aux.nrVacantePlanificateCuAgentia - y;
    return aux;
}
Client Client::operator-(Client ct){
    ct.prenume = ct.prenume + " - " + this->prenume;
    ct.nrVacantePlanificateCuAgentia=ct.nrVacantePlanificateCuAgentia - this->nrVacantePlanificateCuAgentia;

    return ct;
}
Client operator-(int y, Client ct){
    ct.nrVacantePlanificateCuAgentia = ct.nrVacantePlanificateCuAgentia - y;
    return ct;
}


bool Client::operator<(const Client& ct) {
    if (this->nrVacantePlanificateCuAgentia < ct.nrVacantePlanificateCuAgentia)
        return true;
    return false;
}
bool Client::operator==(const Client& ct) {
    if (this->nrVacantePlanificateCuAgentia == ct.nrVacantePlanificateCuAgentia)
        return true;
    return false;
}


istream& operator>>(istream& in, Client& ct){
    cout<<"Nume:";
    char aux[100];
    in>>aux;

    if(ct.nume!=NULL)
        delete[] ct.nume;
    ct.nume=new char[strlen(aux)+1];
    strcpy(ct.nume,aux);

    cout<<"\nPrenume: ";
    in>>ct.prenume;

    cout<<"\nDestinatieDorita: ";
    in>>ct.destinatieDorita;

    cout<<"\nBuget: ";
    in>>ct.buget;

    cout<<"\nBuget flexibil [1-true/0-false] ";
    in>>ct.bugetFlexibil;

    cout<<"\nnrVacantePlanificateCuAgentia: ";
    in>>ct.nrVacantePlanificateCuAgentia;

    return in;
}
ostream& operator<<(ostream& out,const Client& ct){
    out<<"\nNume: "<<ct.nume;
    out<<"\nPrenume: "<<ct.prenume;
    out<<"\nDestinatia dorita: "<<ct.destinatieDorita;
    out<<"\nBuget: "<<ct.buget;
    out<<"\nBuget flexibil: ";
    if(ct.bugetFlexibil) out<<"da";
    else out<<"nu";
    out<<"\nNumarul de vacante planificate cu agentia pana in prezent: "<<ct.nrVacantePlanificateCuAgentia;

    return out;
}

Client::Client(){

    this->nume = new char[strlen("Anonim") + 1];
    strcpy(this->nume, "Anonim");

    this->prenume = "Anonim";

    this->destinatieDorita = "Necunoscuta";

    this->buget = 0;
    this->bugetFlexibil = false;
    this->nrVacantePlanificateCuAgentia = 0;
}
Client::Client(char *nume, string prenume, string destinatieDorita, float buget, bool bugetFlexibil, int nrVacantePlanificateCuAgentia) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->prenume = prenume;
    this->destinatieDorita = destinatieDorita;
    this->buget = buget;
    this->bugetFlexibil = bugetFlexibil;
    this->nrVacantePlanificateCuAgentia = nrVacantePlanificateCuAgentia;

}
Client::Client(char *nume, string prenume) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->prenume = prenume;
    this->destinatieDorita = "Necunoscuta";
    this->buget = 0;
    this->bugetFlexibil = false;
    this->nrVacantePlanificateCuAgentia = 0;
}
Client::Client(char *nume, string prenume, int nrVacantePlanificateCuAgentia) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->prenume = prenume;
    this->destinatieDorita = "Necunoscuta";
    this->buget = 0;
    this->bugetFlexibil = false;
    this->nrVacantePlanificateCuAgentia = nrVacantePlanificateCuAgentia;
}
Client::Client(const Client& ct){
    this->nume = new char[strlen(ct.nume) + 1];
    strcpy(this->nume, ct.nume);

    this->prenume = ct.prenume;
    this->destinatieDorita = ct.destinatieDorita;
    this->buget = ct.buget;
    this->bugetFlexibil = ct.bugetFlexibil;
    this->nrVacantePlanificateCuAgentia = ct.nrVacantePlanificateCuAgentia;

}
Client& Client::operator=(const Client& ct){
    if(this!=&ct){

        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume = new char[strlen(ct.nume) + 1];
        strcpy(this->nume, ct.nume);

        this->prenume = ct.prenume;
        this->destinatieDorita = ct.destinatieDorita;
        this->buget = ct.buget;
        this->bugetFlexibil = ct.bugetFlexibil;
        this->nrVacantePlanificateCuAgentia = ct.nrVacantePlanificateCuAgentia;

    }

    return *this;
}

void Client::VerificareClientFidel(){
    if(this->nrVacantePlanificateCuAgentia>=5)
    {cout << "Clientul este fidel";}
    else if((this->nrVacantePlanificateCuAgentia>=1) && (this->nrVacantePlanificateCuAgentia<5))
    {cout << "Este un client obisnuit";}
    else if(this->nrVacantePlanificateCuAgentia==0)
    {cout << "Clientul este nou";}
}


Client::~Client() {
    if(this->nume!=NULL)
        delete[] this->nume;
}


//-------------------------------------------------------------------------------------------------------------------------------//
class OfertaVacanta{
private:
    char* destinatie;
    string dataPlecare;
    int nrZile;
    int nrPersoane; //nr persoane pe vacanta
    double pret;    //pretul total al vacantei
public:
    OfertaVacanta();
    OfertaVacanta(char* destinatie, string dataPlecare, int nrZile, int nrPersoane, double pret);
    OfertaVacanta(char* destinatie);
    OfertaVacanta(char* destinatie, double pret);
    OfertaVacanta(const OfertaVacanta& ov);
    OfertaVacanta& operator= (const OfertaVacanta& ov);

    friend istream& operator>>(istream& in, OfertaVacanta& ov);
    friend ostream& operator<<(ostream& out,const OfertaVacanta& ov);

    char operator[](int index);

    const OfertaVacanta& operator++();
    OfertaVacanta operator++(int);
    OfertaVacanta operator+=(int x);
    OfertaVacanta operator+(int y);
    OfertaVacanta operator+(OfertaVacanta ov);
    friend OfertaVacanta operator+(int y, OfertaVacanta ov);

    const OfertaVacanta& operator--();
    OfertaVacanta operator--(int);
    OfertaVacanta operator-=(int x);
    OfertaVacanta operator-(int y);
    OfertaVacanta operator-(OfertaVacanta ov);
    friend OfertaVacanta operator-(int y, OfertaVacanta ov);


    bool operator<(const OfertaVacanta& ov);
    bool operator==(const OfertaVacanta& ov);

    explicit operator int();

    void setDestinatie(char* destinatie);
    void setDataPlecare(string dataPlecare);
    void setNrZile(int nrZile);
    void setNrPersoane(int nrPersoane);
    void setpret(double pret);


    const char* getDestinatie();
    string getDataPlecare();
    int getNrZile();
    int getNrPersoane();
    double getpret();

    void CalculeazaPretPeZiDePersoana();

    ~OfertaVacanta();


};
void OfertaVacanta::setDestinatie(char* destinatie){
    if(this->destinatie!=NULL)
        delete[] this->destinatie;
    this->destinatie=new char[strlen(destinatie)+1];
    strcpy(this->destinatie,destinatie);
}
void OfertaVacanta::setDataPlecare(string dataPlecare) {
    this->dataPlecare=dataPlecare;
}
void OfertaVacanta::setNrZile(int nrZile) {
    this->nrZile=nrZile;
}
void OfertaVacanta::setNrPersoane(int nrPersoane) {
    this->nrPersoane=nrPersoane;
}
void OfertaVacanta::setpret(double pret) {
    this->pret=pret;
}

const char*  OfertaVacanta::getDestinatie() {
    return this->destinatie;
}
string  OfertaVacanta::getDataPlecare() {
    return this->dataPlecare;
}
int  OfertaVacanta::getNrZile() {
    return this->nrZile;
}
int  OfertaVacanta::getNrPersoane() {
    return this->nrPersoane;
}
double  OfertaVacanta::getpret() {
    return this->pret;
}

OfertaVacanta::operator int(){
    return (int)this->pret;
}

char OfertaVacanta::operator[](int index) {

    if (0 <= index && index < strlen(this->destinatie) + 1)
        return this->destinatie[index];
    cout << "Index introdus gresit";

}

const OfertaVacanta& OfertaVacanta::operator++(){
    this->nrZile++;
    return *this;
}
OfertaVacanta OfertaVacanta::operator++(int) {
    OfertaVacanta aux(*this);
    this->nrZile++;
    return aux;
}
OfertaVacanta OfertaVacanta::operator+=(int x){
    this->nrZile+=x;
    return *this;
}
OfertaVacanta OfertaVacanta::operator+(int y){
    OfertaVacanta aux = *this;
    aux.nrZile = aux.nrZile + y;
    return aux;
}
OfertaVacanta OfertaVacanta::operator+(OfertaVacanta ov){

    ov.nrZile=ov.nrZile + this->nrZile;

    return ov;
}
OfertaVacanta operator+(int y, OfertaVacanta ov){
    ov.nrZile = ov.nrZile + y;
    return ov;
}

const OfertaVacanta& OfertaVacanta::operator--(){
    this->nrZile--;
    return *this;
}
OfertaVacanta OfertaVacanta::operator--(int) {
    OfertaVacanta aux(*this);
    this->nrZile--;
    return aux;
}
OfertaVacanta OfertaVacanta::operator-=(int x){
    this->nrZile-=x;
    return *this;
}
OfertaVacanta OfertaVacanta::operator-(int y){
    OfertaVacanta aux = *this;
    aux.nrZile = aux.nrZile - y;
    return aux;
}
OfertaVacanta OfertaVacanta::operator-(OfertaVacanta ov){

    ov.nrZile=ov.nrZile - this->nrZile;

    return ov;
}
OfertaVacanta operator-(int y, OfertaVacanta ov){
    ov.nrZile = ov.nrZile - y;
    return ov;
}

bool OfertaVacanta::operator<(const OfertaVacanta& ov) {
    if (this->nrZile < ov.nrZile)
        return true;
    return false;
}
bool OfertaVacanta::operator==(const OfertaVacanta& ov) {
    if (this->nrZile == ov.nrZile)
        return true;
    return false;
}

istream& operator>>(istream& in, OfertaVacanta& ov){
    cout<<"Destinatie:";
    char aux[100];
    in>>aux;

    if(ov.destinatie!=NULL)
        delete[] ov.destinatie;
    ov.destinatie=new char[strlen(aux)+1];
    strcpy(ov.destinatie,aux);

    cout<<"\nData plecare: ";
    in>>ov.dataPlecare;

    cout<<"\nNumar zile vacanta: ";
    in>>ov.nrZile;

    cout<<"\nNumar persoane: ";
    in>>ov.nrPersoane;

    cout<<"\nPretul vacantei: ";
    in>>ov.pret;


    return in;
}
ostream& operator<<(ostream& out,const OfertaVacanta& ov){
    out<<"\nDestinatie: "<<ov.destinatie;
    out<<"\nData plecare: "<<ov.dataPlecare;
    out<<"\nNumar zile vacanta: "<<ov.nrZile;
    out<<"\nNumar persoane: "<<ov.nrPersoane;
    out<<"\nPretul vacantei: "<<ov.pret;

    return out;
}

OfertaVacanta::OfertaVacanta(){

    this->destinatie = new char[strlen("Necunoscuta") + 1];
    strcpy(this->destinatie, "Necunoscuta");

    this->dataPlecare = "00/00/0000";
    this->nrZile = 0;
    this->nrPersoane = 0;
    this->pret = 0;
}
OfertaVacanta::OfertaVacanta(char* destinatie, string dataPlecare, int nrZile, int nrPersoane, double pret) {
    this->destinatie = new char[strlen(destinatie) + 1];
    strcpy(this->destinatie, destinatie);

    this->dataPlecare = dataPlecare;
    this->nrZile = nrZile;
    this->nrPersoane = nrPersoane;
    this->pret = pret;
}
OfertaVacanta::OfertaVacanta(char *destinatie) {
    this->destinatie = new char[strlen(destinatie) + 1];
    strcpy(this->destinatie, destinatie);
    this->dataPlecare = "00/00/0000";
    this->nrZile = 0;
    this->nrPersoane = 0;
    this->pret = 0;
}
OfertaVacanta::OfertaVacanta(char *destinatie, double pret){
    this->destinatie = new char[strlen(destinatie) + 1];
    strcpy(this->destinatie, destinatie);
    this->dataPlecare = "00/00/0000";
    this->nrZile = 0;
    this->nrPersoane = 0;
    this->pret = pret;
}
OfertaVacanta::OfertaVacanta(const OfertaVacanta& ov){
    this->destinatie = new char[strlen(ov.destinatie) + 1];
    strcpy(this->destinatie, ov.destinatie);

    this->dataPlecare = ov.dataPlecare;
    this->nrZile = ov.nrZile;
    this->nrPersoane = ov.nrPersoane;
    this->pret = ov.pret;

}
OfertaVacanta &OfertaVacanta::operator=(const OfertaVacanta &ov){
    if(this!=&ov){

        if(this->destinatie!=NULL)
            delete[] this->destinatie;


        this->destinatie=new char[strlen(ov.destinatie)+1];
        strcpy(this->destinatie,ov.destinatie);

        this->dataPlecare=ov.dataPlecare;
        this->nrZile=ov.nrZile;
        this->nrPersoane=ov.nrPersoane;
        this->pret=ov.pret;
    }

    return *this;
}

void OfertaVacanta::CalculeazaPretPeZiDePersoana(){
    float pretPeZi;
    if(this->nrZile>1)
    {pretPeZi=this->pret/this->nrZile;}
    else
    {pretPeZi=this->pret;}
    cout<<"Pretul pe care trebuie sa il plateasca o persoana pe zi este: ";
    if(this->nrPersoane==1)
    {cout << pretPeZi;}
    else
    {cout << pretPeZi/this->nrPersoane;}

}

OfertaVacanta::~OfertaVacanta(){
    if(this->destinatie!=NULL)
        delete[] this->destinatie;
}

int main() {

    return 0;
}
