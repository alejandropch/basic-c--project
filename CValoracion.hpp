#include <iostream>

using namespace std;

struct Nodo {
	int Puntos;
	int n_texto;
	Nodo* siguiente;
};

class Valoracion
{
private:
    int puntos[3];
    int n_textos[3];
    int puntos_tot;
    int auxT[3];
    int c;
public:
    Valoracion() { puntos_tot = 0; c = 0; }
    ~Valoracion() {}
	void Menu_Valoracion() {
        
        Nodo* lista = NULL;
        int opcion, puntos, n_texto;
        A:
        do {
            system("cls");
            cout << "\t .:Menu:. \n";
            cout << "1. Insertar Valoración a un texto \n";
            cout << "2. Mostrar Valoraciones (de menor a mayor) de los textos \n";
            cout << "3. Salir\n";
            cout << "Opcion:_";
            cin >> opcion;

            switch (opcion) {
            case 1: 
                cout << "\nDigite el # de texto que va a valorar: ";
                cin >> n_texto;
                for (int i = 0; i < c+1; i++) {
                    if (auxT[i] == n_texto) {
                        system("cls");
                        cout << "\nEl texto " << auxT[i] << " ya ha sido valorado";
                        //_sleep(1000);
                        goto A;
                    }
                }
                auxT[c] = n_texto;
                c++;
                cout << "\nDigite la valoraci�n del texto entre 1 al 10: ";
                cin >> puntos;
                insertarLista(lista, puntos, n_texto);
                cout << "\n";
                system("pause");
                break;
            case 2: 
                mostrarLista(lista);
                cout << "\n";
                system("pause");
                break;
            }

        } while (opcion != 3);
        system("cls");
	}
    void insertarLista(Nodo*& lista, int puntos, int n_text) {
        Nodo* nuevo_nodo = new Nodo();
        //asignar n al nuevo nodo
        nuevo_nodo->Puntos = puntos;
        nuevo_nodo->n_texto = n_text;

        Nodo* aux1 = lista;
        //para ordenar lista
        Nodo* aux2 = NULL;

        while ((aux1 != NULL) && (aux1->Puntos < puntos) && (aux1->n_texto < n_text)) {
            aux2 = aux1;
            aux1 = aux1->siguiente;

        }
        //va al principio

        if (lista == aux1) {

            lista = nuevo_nodo;
        }
        else {
            aux2->siguiente = nuevo_nodo;
        }

        nuevo_nodo->siguiente = aux1;

        cout << "\t Elemento " << puntos << " insertado a la lista correctamente \n\n";
    }

    void mostrarLista(Nodo* lista) {

        Nodo* actual = new Nodo();
        actual = lista;
        int indice = 0;

        cout << "\n\tValoraciones realizadas" << endl;
        while (actual != NULL) {
            puntos[indice] = actual->Puntos;
            n_textos[indice] = actual->n_texto;

            cout << "Texto " << n_textos[indice] << ": " << puntos[indice] << endl;
            indice++;

            actual = actual->siguiente;
        }

        int aux, aux1;
        //Algoritmo del metodo Burbuja
        for (int i = 0; i < indice - 1; i++) {
            for (int j = 0; j < indice - 1; j++) {
                if (puntos[j] > puntos[j + 1]) {
                    aux = puntos[j];
                    puntos[j] = puntos[j + 1];
                    puntos[j + 1] = aux;

                    aux1 = n_textos[j];
                    n_textos[j] = n_textos[j + 1];
                    n_textos[j + 1] = aux1;
                }
            }
        }

        cout << "\n\tOrden Ascendente: \n";
        for (int i = 0; i < indice; i++) {
            cout << "Texto " << n_textos[i] << ": " << puntos[i] << endl;
            puntos_tot = puntos_tot + puntos[i];
        }
        cout << "\nPuntos acumulados " << puntos_tot << " de 30" << endl;
    }
};