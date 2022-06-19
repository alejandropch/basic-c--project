#include "CControl.hpp"
#include <conio.h>
class CMenu
{
private:
    CControl*objC;
    //App* objApp;
	CUsuario* objU;
	//CHistorias* objHistorias;
	//Valoracion* objV = new Valoracion();
	int op;
	int aux;
    int numData;
    int auxL;

	string codigoU;
	string name;
	string desLang; //desired language
	string auxPunt;
	string auxProgr;

	bool found;

	void userList() {
        system("cls");
	    cout << "Código" << "\t" << "Nombre" << "\t" << "Idioma Deseado" << "\t" << "Puntaje";
	    cout << "\t" << "Progreso";
	    string line;
	    ifstream arch("users.txt");
	    if (arch.is_open()) {
		    while (getline(arch, line)) {
			cout << line << "\n";
		}
		arch.close();
	    }
	    _getch();
    }

	void registerUser() {
        system("cls");
	    cout << "Ingrese su nombre:";
	    cin.ignore(); getline(cin, name);
	    cout << "¿Que lenguaje deseas aprender? (1: Ingles 2:Frances)";
	    cin >> auxL; desLang = languages[auxL-1];
	    objU->registrar(name, desLang);
	    cout << "¡Usuario Registrado!";
	    cout << "Su código es:" << objU->getCod();
	    objU->guardarUsuario();
	    _getch();
    }

	void programa() {
        system("cls");
	    cout << "Ingrese su código:"; cin >> codigoU;
	    string line;
	    ifstream archivo("users.txt");
	    if (archivo.is_open()) {
		    while (getline(archivo, line)) {
			    size_t found = line.find(codigoU);
			    if (found != string::npos) {
                    found=true;
				    cout << "¡Usuario Encontrado!\n";
				    stringstream s(line);
				    string word;
				    s >> codigoU >> name >> desLang >> auxPunt >> auxProgr;
				    objU->encontrar(codigoU, name, desLang, auxPunt, auxProgr);
			    }
		    }
		archivo.close();
	    }
	    _getch();
	    if (found) {
            //Comienza aplicación

	    }
	    else {
		cout << "Por favor, registrese para comenzar.";
	    }
	    _getch();
    }

	void creditos(){
        system("cls");
		cout << "======================Créditos======================\n";
		cout << "•	Jhosaim Ricardo Pocohuanca Pineda - u202115595\n";
		cout << "•	Alejandro Alberto Pachas Chavez  - u201917598\n";
		cout << "•	Jak Cristian Campos Espinoza  - u20211a184\n";
		cout << "====================================================\n";
		_getch();
    }

    void opciones(){
        system("cls");
        cout << "APRENDIZAJE BÁSICO DE INGLES Y FRANCES";
        cout << "1- Generar datos\n";
        cout << "2- Registrar usuario\n";
        cout << "3- Mostrar lista de usuarios\n";
        cout << "4- Ingresar al programa\n";
        cout << "5- Creditos\n";
        cout << "6- Salir\n";
        cout << "7- Indexar en arbol binario de busqueda\n";
        cout << "8- Ordenar por ID VUELO\n";
        cout << "9- Hash Table\n";
    }

public:

    void empezarMenu() {

        while (op!=6) {
            opciones();
            cin >> op;
            switch (op) {
            case 1: {
                objC->generateData(numData);
            } break;
            case 2: {
                registerUser();
            } break;
            case 3: {
                userList();
            } break;
            case 4: {
                programa();
            } break;
            case 5: {
                creditos();
            }
            default: break;
            case 7: {
                objC->indexData();
            } break;
            case 8: {
                objC->sortByID();
            }
            case 9: {
                objC->generateHT();
            }
            }
        }

    }

	CMenu() {
        objC = new CControl();
        objU = new CUsuario();
	    //objApp = new App();
	    //objHistorias = new CHistorias();
        op = 0;
	    aux = 0;
        numData = 0;
        auxL = 0;
        codigoU = "";
	    name = "";
	    desLang = "";
	    auxPunt = "";
	    auxProgr = "";
	    found = false;
    }

	~CMenu() {
        delete objC;
        delete objU;
	    //delete objApp;
	    //delete objHistorias;
	    //delete objV;
    }
};