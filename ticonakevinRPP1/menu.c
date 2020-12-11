#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void menu_principal()
{
    system("cls");
    printf(" *** Menu de Opciones *** \n");
    printf("1- Alta del Cliente.\n");
    printf("2- Modificar datos del Cliente.\n");
    printf("3- Baja de Cliente.\n");
    printf("4- Prestamo.\n");
    printf("5- Saldar Prestamo.\n");
    printf("6- Reanudar Prestamo.\n");
    printf("7- Imprimir Clientes.\n");
    printf("8- Imprimir Prestamos.\n");
    printf("9- Informar Clientes.\n");
    printf("10- Informar Clientes.\n");
    printf("\n Eliga una de las Opciones: ");
}


void informes_subMenu()
{
    system("cls");

    printf(" *** Menu de Informes *** \n");
    printf("1.a_ Clientes con mas prestamos Activos.\n");
    printf("2.b_ Clientes con mas prestamos Saldados.\n");
    printf("3.c_ Clientes con mas prestamos.\n");
    printf("4. Volver al menu principal.\n");
}
