#include <iostream>
#include <fstream>
#include "CNiveles.hpp"
#include "CCuentos.hpp"
#include "CValoracion.hpp"
#include "CFrases.hpp"
using namespace std;

class Menu
{
private:
	string user_name="Jak";
	string Curso="Ingles";
	Niveles* objN = new Niveles();
	Cuentos* objC = new Cuentos();
	Valoracion* objV = new Valoracion();
	Frases* objF=new Frases();
public:
	Menu() {}
	~Menu() { delete objN; delete objC; }
	void Seleccionar_options() {
		objN->Seleccionar_opciones();
	}
	void Mostrar_levels() {
		objN->Mostrar_niveles();
	}
	void Menu_Valoracion() {
		objV->Menu_Valoracion();
	}
	void Navbar() {
		system("cls");
		cout<<"Usuario: "<<user_name<<"\t\t\t"<<"Curso: "<<Curso<<"\t\t\t"<<"Lecturas (R)"<<endl;
		cout<<"________________________________________________________________________________________"<<endl;
	}

	void Bienvenida(){
cout<<endl;
cout<<"\n ____  _                           _     _      "  ;    
cout<<"\n| __ )(_) ___ _ ____   _____ _ __ (_) __| | ___  ___ " ;
cout<<"\n|  _ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\/ __| ";
cout<<"\n| |_) | |  __/ | | \\ V /  __/ | | | | (_| | (_) \\__ \\ ";
cout<<"\n|____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/|___/ ";
cout<<endl;                                                    
cout<<"\n\t\t\t  __ _ "; 
cout<<"\n\t\t\t / _` | ";
cout<<"\n\t\t\t| (_| | ";
cout<<"\n\t\t\t \\__,_| ";
cout<<endl;        
cout<<"\n ____              _ _                  ____  ";
cout<<"\n|  _ \\ _   _  ___ | (_)_ __   __ _  ___|___ \\ ";
cout<<"\n| | | | | | |/ _ \\| | | '_ \\ / _` |/ _ \\ __) |";
cout<<"\n| |_| | |_| | (_) | | | | | | (_| | (_) / __/ ";
cout<<"\n|____/ \\__,_|\\___/|_|_|_| |_|\\__, |\\___/_____|";
cout<<"\n                             |___/            ";
							 
	}

	void Mostrar_cuento() {
		cout<<endl;
		//if (tecla == 'R') {
			objC->Leer_cuentos(retornar_curso(), objN->retornar_actual_nivel());
		//}
	}

	void mostrar_frase(){
		cout<<"\nLa frase del día es: "<<endl;
		objF->Leer_frases(Curso);
		objF->Cambiar_frase(1+rand() % 5);
	}

	string retornar_username(){return user_name;}
	string retornar_curso(){return Curso;}
	void cambiar_curso(string nuevo){Curso = nuevo;}
};

