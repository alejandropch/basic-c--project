#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Cuentos
{
private:

public:
	Cuentos() {}
	~Cuentos() {}
	void Leer_cuentos(string idioma, int n_lec) {
		string line;
		string texto;

		system("cls");

		ifstream archivo(string("Cuentos/Cuento") + to_string(n_lec) + "_" + idioma + string(".txt"));
		while (getline(archivo, line)) {
			texto = texto + line + "\n";
		}
		archivo.close();
		cout << texto << endl;
	}
};

