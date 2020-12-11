#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "validaciones.h"
#include "cliente.h"
#include "prestamo.h"
int menu_Informes(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC)
{
    int opcionMenu;
    int opcionMenuValid;
    int error = -1;
    do
    {
        informes_subMenu();
        opcionMenu = validations_getOption(&opcionMenuValid, "\nOpcion invalida.\n", 1, 11);

        if(!opcionMenu)
        {
            switch(opcionMenuValid)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
                error = 0;
                system("pause");
            }
        }
    }

    while(opcionMenuValid != 4);
    return error;
}
