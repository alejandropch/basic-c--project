#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Niveles
{
private:
	int nivel;
	int n_niveles;
public:
	Niveles() {}
	~Niveles() {}

	void Seleccionar_opciones() {
		do{
		cout << "Ingrese el nivel que desea realizar: ";
		cin >> nivel;
		}while(nivel<0 || nivel>retornar_n_niveles());
	}
	void Mostrar_niveles() {
		string line;
		int cont=0;

		cout<<"\n\n\t\tMENÚ"<<endl<<endl;

		ifstream archivo("Niveles.txt");
		while (!archivo.eof()) {
			archivo>>line;
			cont++;
			cout<<"\t"<<cont<<". "<<line<<endl;
		}
		cout<<endl;
		archivo.close();
	}

	int retornar_n_niveles(){
		int cont=1;
		ifstream archivo("Niveles.txt",ifstream::in);
		while (archivo.good()) {
			if(archivo.get()=='\n')	cont++;
		}
		return cont;
	}

	int retornar_actual_nivel(){return nivel;}
};