#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Frases{
private:
	int n_frase;
public:
    Frases(){n_frase=1+rand() % 41;}
    ~Frases(){}
    void Leer_frases(string idioma) {
		string lineI,lineE;
		string textoE,textoI;

		ifstream archivoI(string("Frases/Frases") + "_" + idioma + string(".txt"));
		ifstream archivoE(string("Frases/Frases_Espanol.txt"));
		for(int i=0; i<n_frase;i++){
			getline(archivoI, lineI);
			textoI=lineI;
			getline(archivoE, lineE);
			textoE=lineE;
		}
/*
		while (getline(archivo, line)) {
			texto = texto + line + "\n";
		}*/
		archivoI.close();
		archivoE.close();
		cout << textoI << " - " <<textoE<<endl;
	}
    void Cambiar_frase(int nuevo){n_frase=nuevo;}
    int retornar_nfrase(){return n_frase;}
};