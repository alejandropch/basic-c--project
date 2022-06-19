#include <iostream>
#include <conio.h>
#include "CMenu.hpp"
#include "CMenu2.hpp"

int main(){
    srand(time(0));
    setlocale(LC_ALL, "es_ES");
    /*CMenu* objMenu = new CMenu();
	objMenu->empezarMenu();
	delete objMenu;*/

    Menu* objM=new Menu();
    A:
    objM->Navbar();
	objM->Bienvenida();
    objM->mostrar_frase();

    while (true) {
		if (kbhit())
		{
			//Capturar la tecla presionada
			char t = getch();
			if (toupper(t) == 'R') { system("cls"); objM->Navbar();objM->Mostrar_levels();objM->Seleccionar_options();objM->Mostrar_cuento();}
			if (toupper(t) == 'P') { system("cls"); goto A; }
			//obj->Mostrar_menu_cuentos(toupper(t));
			//flushall();
		}
		//_sleep(100);
	}
	system("pause");
	delete objM;

    return 0;
}