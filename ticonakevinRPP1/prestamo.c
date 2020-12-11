#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "cliente.h"
#include "prestamo.h"

int inicializar_Prestamo(ePrestamo* lista, int tam)
{
    if(lista != NULL && tam > 0 && tam <= 100)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}

int altaPrestamo(ePrestamo listPrestamo[],int tamP, int id,eCliente listCliente[], int tamC)
{
    ePrestamo newPrestamo;

    int validIdCliente;
    int importValid;
    char importStr[50];
    char cuotasStr[50];
    int cuotasValid;

    if(listPrestamo!= NULL && tamP > 0 && listCliente != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(listCliente[i].isEmpty == 1)
            {
                newPrestamo.estado = 0;
                newPrestamo.isEmpty = 0;
                newPrestamo.id = id;
                // cliente
                mostrarClientes(listCliente,tamC);
                printf("\nIngrese el Id del Cliente: ");
                fflush(stdin);
                scanf("%d",&newPrestamo.idCliente);
                validIdCliente=findClienteById(listCliente,tamC,newPrestamo.idCliente);
                while(validIdCliente < 0)
                {
                    printf("\nDato invalido. Ingrese el ID del Cliente: ");
                    fflush(stdin);
                    scanf("%d",&newPrestamo.idCliente);
                    validIdCliente=findClienteById(listCliente,tamC,newPrestamo.idCliente);
                }
                // prestamo
                printf("\nIngrese el Importe Solicitado: ");
                fflush(stdin);
                scanf("%s",importStr);
                importValid = validarNumero(importStr);
                newPrestamo.importe = atoi(importStr);

                while(importValid!=0 || newPrestamo.importe <0 )
                {
                    printf("\nDato invalido. Ingrese el Importe Solicitado: ");
                    fflush(stdin);
                    scanf("%s",importStr);
                    importValid = validarNumero(importStr);
                    newPrestamo.importe = atoi(importStr);
                }

                // cuotas
                printf("\nIngrese la cantidad de Cuotas: ");
                fflush(stdin);
                scanf("%s",cuotasStr);

                cuotasValid = validarNumero(cuotasStr);
                newPrestamo.cantidadDeCuotas = atoi(cuotasStr);
                while(cuotasValid!=0 || newPrestamo.cantidadDeCuotas <0 )
                {
                    printf("\nDato invalido. Ingrese la cantidad de Cuotas: ");
                    fflush(stdin);
                    scanf("%s",cuotasStr);
                    cuotasValid = validarNumero(cuotasStr);
                    newPrestamo.cantidadDeCuotas = atoi(cuotasStr);
                }

                listPrestamo[i] = newPrestamo;
                return 0;
            }
            // printf("\nNo hay lugar para otra Cliente...\n");
        }
        printf("\nNo hay lugar para otro Prestamo...\n");
    }
    return -1;
}


void mostrarPrestamo(ePrestamo listPrestamo, eCliente listCliente[], int tamC)
{
    char descNombre[50];

    obtenerDescripcionCliente(listCliente, tamC,listPrestamo.idCliente, descNombre);
    printf("%5d         %10s           %10d         %10d  \n",
           listPrestamo.id,
           descNombre,
           listPrestamo.importe,
           listPrestamo.cantidadDeCuotas
          );
}

int mostrarPrestamos(ePrestamo listPrestamo[], int tamP, eCliente listCliente[], int tamC)
{
    int error = -1;
    if(listPrestamo != NULL && tamP > 0 && listCliente != NULL && tamC >0)
    {
        printf("                         Prestamos        \n"     );
        printf("----------------------------------------------------------------------\n");
        printf("   Id            Cliente              Importe             Cuotas      \n");
        printf("---------------------------------------------------------------------\n");
        for(int i = 0; i < tamP; i++)
        {
            if(listPrestamo[i].isEmpty != 1)
            {
                mostrarPrestamo(listPrestamo[i],listCliente,tamC);
            }
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int saldarPrestamo(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC)
{
    int error = -1;
    int idPrestamo;
    int indice;

    char confirmar;

    if(listPrestamo != NULL && tamP> 0)
    {
        system("cls");
        printf("                                           Modificar Estado                          \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        mostrarPrestamos(listPrestamo,tamP, listCliente, tamC);
        printf("\nIngrese ID del Prestamo: ");
        fflush(stdin);
        scanf("%d", &idPrestamo);
        indice = findPrestamoById(listPrestamo, tamP, idPrestamo);
        if(indice == -1)
        {
            system("cls");
            printf("\nLo sentimos. No hay un Prestamo con ese ID...\n");
        }
        else
        {
            // Estado
            printf("\nDesea cambiar el estado a Saldado?\n");
            //pedir confirmacion
            printf("Desea confirmar? s o n\n");
            fflush(stdin);
            scanf("%c", &confirmar);
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                printf("\nDato invalida. \nDesea confirmar? s o n\n");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
            }
            if(confirmar == 's')
            {
                listPrestamo[indice].estado = -1;
                listPrestamo[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 1;
            }
        }
    }
    return error;
}

int findPrestamoById(ePrestamo list[], int len,int id)
{
    int indice = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int activarPrestamo(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC)
{
    int error = -1;
    int idPrestamo;
    int indice;

    char confirmar;

    if(listPrestamo != NULL && tamP> 0)
    {
        system("cls");
        printf("                                           Modificar Estado                          \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        mostrarPrestamos(listPrestamo,tamP, listCliente, tamC);
        printf("\nIngrese ID del Prestamo: ");
        fflush(stdin);
        scanf("%d", &idPrestamo);
        indice = findPrestamoById(listPrestamo, tamP, idPrestamo);
        if(indice == -1)
        {
            system("cls");
            printf("\nLo sentimos. No hay un Prestamo con ese ID...\n");
        }
        else
        {
            // Estado
            printf("\nDesea cambiar el estado a Activo?\n");
            //pedir confirmacion
            printf("Desea confirmar? s o n\n");
            fflush(stdin);
            scanf("%c", &confirmar);
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                printf("\nDato invalida. \nDesea confirmar? s o n\n");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
            }
            if(confirmar == 's')
            {
                listPrestamo[indice].estado = 0;
                listPrestamo[indice].isEmpty = 0;
                error = 0;
            }
            else
            {
                error = 1;
            }
        }
    }
    return error;
}


int imprimirPrestamosDni(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC)
{
    int error = -1;
    int prestamoActualId;
    eCliente auxCliente;
    char dniStr[50];
    int isValiddni;
    int dniValid;
    int len;

    if(listPrestamo != NULL && tamP > 0 && listCliente != NULL && tamC > 0)
    {

        //pedir dni
        printf("\nIngrese el Dni: ");
        fflush(stdin);
        scanf("%s",dniStr);
        dniValid = validarNumero(dniStr);
        len = strlen(dniStr);
        auxCliente.dni = atoi(dniStr);
        isValiddni= findClienteByDni(listCliente,tamC,auxCliente.dni);
                    while(dniValid!=0 || len != 8 || isValiddni < 0)
        {
            printf("\nDato invalido. Reingrese el Dni: ");
            fflush(stdin);
            scanf("%s",dniStr);
            dniValid = validarNumero(dniStr);
            len = strlen(dniStr);
            auxCliente.dni = atoi(dniStr);
            isValiddni= findClienteByDni(listCliente,tamC,auxCliente.dni);
        }

        //listar Prestamos
        for(int i = 0; i < tamC; i++)
        {
            if(
                auxCliente.dni == listCliente[i].dni)
            {
                prestamoActualId = listCliente[i].dni;
                for(int j = 0; j < tamP; j++)
                {
                    if(prestamoActualId == listPrestamo[j].idCliente)
                    {
                        mostrarPrestamo(listPrestamo[j],listCliente, tamC);
                    }
                }
            }
        }

        error = 0;
    }

    return error;
}


