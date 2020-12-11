#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "cliente.h"
#include "menu.h"
#include "prestamo.h"


#define TAM_C 10
#define TAM_P 10
int main()
{
    int validNewCliente;
    int validModificacion;
    int validSaldar;
    int validActivar;
    int validBaja;
    int validNewPrestamo;


    int idCliente = 20;
    int idPrestamos = 100;

    int menuPrincipal;
    int menuPrincipal_opcionSeleccionada;

    eCliente listClientes[TAM_C];
    ePrestamo listPrestamos[TAM_P];

    inicializar_Cliente(listClientes,TAM_C);
    inicializar_Prestamo(listPrestamos, TAM_C);

    do
    {
        menu_principal();
        menuPrincipal = validaciones_obtenerOpcion
                        (
                            &menuPrincipal_opcionSeleccionada,
                            "\nOpcion invalida, intente nuevamente\n",
                            1,
                            10
                        );
        if(!menuPrincipal)
        {
            switch(menuPrincipal_opcionSeleccionada)
            {

            case 1:
                validNewCliente = altaCliente(listClientes,TAM_C,idCliente);
                if(validNewCliente == 0)
                {
                    printf("\nOperacion exitosa\n");
                    idCliente++;
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                mostrarClientes(listClientes,TAM_C);
                break;
            case 2:
                validModificacion = modificarCliente(listClientes,TAM_C);
                if(!validModificacion)
                {
                    printf("\nModificacion exitosa.\n");
                }
                else if(validModificacion == 1)
                {
                    printf("\nModificacion cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 3:
                validBaja = bajaClientex(listClientes, TAM_C);
                if(!validBaja)
                {
                    printf("\nBaja exitosa.\n");
                }
                else if(validBaja == 1)
                {
                    printf("\nBaja cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 4:
                validNewPrestamo = altaPrestamo(listPrestamos,TAM_P, idPrestamos, listClientes, TAM_C);
                if(validNewPrestamo == 0)
                {
                    printf("\nOperacion exitosa\n");
                    idPrestamos++;
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                mostrarPrestamos(listPrestamos, TAM_P, listClientes, TAM_C);
                break;
            case 5:
                validSaldar = saldarPrestamo(listPrestamos,TAM_P,listClientes,TAM_C);
                if(validSaldar == 0)
                {
                    printf("\nOperacion exitosa. Estado Saldado\n");
                }
                else if(validSaldar == 1)
                {
                    printf("\nModificacion cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 6:
                validActivar = activarPrestamo(listPrestamos,TAM_P,listClientes,TAM_C);
                if(validActivar == 0)
                {
                    printf("\nOperacion exitosa. Estado Activo\n");
                }
                else if(validActivar == 1)
                {
                    printf("\nModificacion cancelada por usuario.\n");
                }
                else
                {
                    printf("\nHa ocurrido un problema. Intente nuevamente.\n");
                }
                break;
            case 7:
                break;
            case 8:
                mostrarPrestamos(listPrestamos,TAM_P,listClientes,TAM_C);
                imprimirPrestamosDni(listPrestamos,TAM_P,listClientes,TAM_C);
                break;
            case 9:
                break;
            case 10:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while( menuPrincipal_opcionSeleccionada != 12);

    return 0;
}
