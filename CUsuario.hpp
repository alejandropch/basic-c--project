#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>
#include "fstream"

using namespace std;

string languages[2] = {"Ingles","Frances"};

class CUsuario
{
private:
	string nombre;
	string idiomaDeseado;
	double puntaje;
	double progreso;
	int nivel;
	int cod;
	string aux;
	string auxCod;

public:
	CUsuario() {
        nombre = idiomaDeseado = aux = "";
	    puntaje = 0;
	    progreso = 0;
	    cod = 0;
    }

	~CUsuario() {

    }

	void registrar(string n, string iD) {
        nombre = n;
	    idiomaDeseado = iD;
	    cod = rand() % 100+100;
    }

	void encontrar(string auxCod, string n, string iD, string auxPunt, string auxProg){
        cod = stoi(auxCod);
		this->auxCod = auxCod;
		nombre = n;
		idiomaDeseado = iD;
		puntaje = stoi(auxPunt);
		progreso = stoi(auxProg);
    }
	void guardarUsuario();
	void guardarProgresoUsuario();
	string getNombre();
	string getIdiomaDeseado();
	double getPuntaje();
	double getProgreso();
	int getCod();
	void setPuntaje(double punt);
	void setProgreso(double pro);
	int getNivel();

};

void CUsuario::guardarProgresoUsuario() {
	ofstream archivo("users.txt",ios::out);
	archivo << cod << "\t\t" << nombre << "\t" << idiomaDeseado << "\t\t" << puntaje << "\t"
		<< progreso << endl;	
}

void CUsuario::guardarUsuario() {
	ofstream archivo("users.txt", ios::app);
	archivo << cod << "\t\t" << nombre << "\t" << idiomaDeseado << "\t\t" << puntaje << "\t"
		<< progreso << endl;
}

string CUsuario::getNombre() { return nombre; }
string CUsuario::getIdiomaDeseado() { return idiomaDeseado; }
double  CUsuario::getPuntaje() { return puntaje; }
double  CUsuario::getProgreso() { return progreso; }
void  CUsuario::setPuntaje(double punt) { puntaje+=punt; }
void  CUsuario::setProgreso(double pro) { progreso+=pro; }
int  CUsuario::getNivel() { return nivel; }
int  CUsuario::getCod() { return cod; }