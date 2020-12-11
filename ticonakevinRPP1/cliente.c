#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "cliente.h"


int inicializar_Cliente(eCliente* lista, int tam)
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

int altaCliente(eCliente listCliente[], int tamC, int id)
{
    eCliente newCliente;
    char dniStr[31];
    int dniValid;
    int len;
    int flag;

    if(listCliente != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(listCliente[i].isEmpty == 1)
            {
                newCliente.isEmpty = 0;
                newCliente.id = id;

                //Nombre
                printf("\nIngrese el Nombre: ");
                fflush(stdin);
                gets(newCliente.nombre);
                flag = validarCadena(newCliente.nombre);
                while(strlen(newCliente.nombre) ==0 || strlen(newCliente.nombre)> 20 || flag != 0 )
                {
                    printf("\nDato invalido. Reingrese el nombre: ");
                    fflush(stdin);
                    gets(newCliente.nombre);
                    flag = validarCadena(newCliente.nombre);
                }

                //Apellido
                printf("\nIngrese el Apellido: ");
                fflush(stdin);
                gets(newCliente.apellido);
                flag = validarCadena(newCliente.apellido);
                while(strlen(newCliente.apellido) ==0 || strlen(newCliente.apellido)> 20 || flag != 0)
                {
                    printf("\nDato invalido. Reingrese el Apellido: ");
                    fflush(stdin);
                    gets(newCliente.apellido);
                    flag = validarCadena(newCliente.apellido);
                }
                //cuil
                printf("\nIngrese el Dni: ");
                fflush(stdin);
                scanf("%s",dniStr);

                dniValid = validarNumero(dniStr);
                len = strlen(dniStr);
                newCliente.dni = atoi(dniStr);
                while(dniValid!=0 || len != 8 )
                {
                    printf("\nDato invalido. Reingrese el Dni: ");
                    fflush(stdin);
                    scanf("%s",dniStr);
                    dniValid = validarNumero(dniStr);
                    len = strlen(dniStr);
                    newCliente.dni = atoi(dniStr);
                }

                listCliente[i] = newCliente;
                return 0;
            }
            // printf("\nNo hay lugar para otra Cliente...\n");
        }
        printf("\nNo hay lugar para otro Cliente...\n");
    }
    return -1;
}


int modificarCliente(eCliente listCliente[], int tamC)
{
    eCliente newCliente;
    int error = -1;
    int id;
    int indice;
    int opcion;
    int dniValid;
    int len;

    char dniStr[31];
    char confirmar;

    if(listCliente != NULL && tamC> 0)
    {
        system("cls");
        printf("                                           Modificar Clientes                          \n");
        printf("------------------------------------------------------------------------------------------------------\n");
        mostrarClientes(listCliente, tamC);
        printf("\nIngrese ID del Cliente que desea modificar: ");
        fflush(stdin);
        scanf("%d", &id);
        indice = findClienteById(listCliente, tamC, id);
        if(indice == -1)
        {
            system("cls");
            printf("\nLo sentimos. No hay un Cliente con ese ID...\n");
        }
        else
        {
            system("cls");
            printf("\n                    *** Listado de Clientes ***                    \n");
            printf("-----------------------------------------------------------------------\n");
            printf(" ID             CUIL                Nombre              Apellido          \n");
            printf("-----------------------------------------------------------------------\n");
            mostrarClientes(listCliente,tamC);
            printf("\nModificar:\n");
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Cuil\n");
            printf("Ingrese el numero la opcion que desea Modificar: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("\nIngrese el nuevo Nombre: ");
                fflush(stdin);
                gets(newCliente.nombre);
                formatName(newCliente.nombre);
                while(strlen(newCliente.nombre) ==0 || strlen(newCliente.nombre)> 20 )
                {
                    printf("\nNo ingreso ningun dato. Ingrese el nuevo Nombre: ");
                    fflush(stdin);
                    gets(newCliente.nombre);
                    formatName(newCliente.nombre);
                }
                //pedir confirmacion
                printf("Desea Modificarlo? s o n\n");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
                while(confirmar != 's' && confirmar != 'n')
                {
                    printf("\nDato invalida. \nDesea Modificarlo? s o n\n");
                    fflush(stdin);
                    scanf("%c", &confirmar);
                    confirmar = tolower(confirmar);
                }

                if(confirmar == 's')
                {
                    strcpy(listCliente[indice].nombre,newCliente.nombre);
                    error = 0;
                }
                else
                {
                    error = 1;
                }
                break;
            case 2:
                printf("\nIngrese el nuevo Apellido: ");
                fflush(stdin);
                gets(newCliente.apellido);
                formatName(newCliente.apellido);
                while(strlen(newCliente.apellido) ==0 || strlen(newCliente.apellido)> 20 )
                {
                    printf("\nNo ingreso ningun dato. Ingrese el Apellido: ");
                    fflush(stdin);
                    gets(newCliente.apellido);
                    formatName(newCliente.apellido);
                }
                printf("Desea Modificarlo? s-si n-no\n");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
                while(confirmar != 's' && confirmar != 'n')
                {
                    printf("\nDato invalida. \nDesea Modificarlo? s o n\n");
                    fflush(stdin);
                    scanf("%c", &confirmar);
                    confirmar = tolower(confirmar);
                }
                if(confirmar == 's')
                {
                    strcpy(listCliente[indice].apellido,newCliente.apellido);
                    error = 0;
                }
                else
                {
                    error = 1;
                }
                break;
            case 3:
                printf("\nIngrese el nuevo CUIL: ");
                fflush(stdin);
                scanf("%s",dniStr);
                dniValid = validarNumero(dniStr);
                len = strlen(dniStr);
                newCliente.dni = atoi(dniStr);
                while(dniValid!=0 || len != 8 )
                {
                    printf("\nDato invalido. Reingrese el CUIL: ");
                    fflush(stdin);
                    scanf("%s",dniStr);
                    dniValid = validarNumero(dniStr);
                    len = strlen(dniStr);
                    newCliente.dni = atoi(dniStr);
                }
                printf("Desea Modificarlo? s-si n-no\n");
                fflush(stdin);
                scanf("%c", &confirmar);
                confirmar = tolower(confirmar);
                while(confirmar != 's' && confirmar != 'n')
                {
                    printf("\nDato invalida. \nDesea Modificarlo? s o n\n");
                    fflush(stdin);
                    scanf("%c", &confirmar);
                    confirmar = tolower(confirmar);
                }
                if(confirmar == 's')
                {
                    listCliente[indice].dni = newCliente.dni;
                    error = 0;
                }
                else
                {
                    error = 1;
                }
                break;
            default:
                printf("Opcion invalida");
                break;
            }
        }
    }
    return error;
}

void mostrarCliente(eCliente listCliente)
{
    orderName(listCliente.nombre);
    orderName(listCliente.apellido);

    printf("%5d       %10s          %10s       %20d  \n",
           listCliente.id,
           listCliente.nombre,
           listCliente.apellido,
           listCliente.dni
          );
}

int mostrarClientes(eCliente* listClientes, int tamC)
{
    if(listClientes != NULL && tamC > 0 && tamC <= 100 )
    {
        system("cls");
        printf("\n                    *** Listado de Clientes ***                    \n");
        printf("-----------------------------------------------------------------------\n");
        printf("  Id              Nombre                  Apellido             Dni \n");
        printf("------------------------------------------------------------------------\n");
        for(int i = 0; i < tamC; i++)
        {
            if(listClientes[i].isEmpty != 1)
            {
                mostrarCliente(listClientes[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

int findClienteById(eCliente list[], int len,int id)
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


int bajaCliente(eCliente* listCliente, int tamC)
{
    int error = -1;
    int id;
    int indice;
    char confirmation;

    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(listCliente != NULL && tamC > 0 && tamC <= 100 )
    {
        mostrarClientes(listCliente,tamC);
        printf("\nIngrese ID del Cliente que desea eliminar: ");
        fflush(stdin);
        scanf("%d", &id);
        indice = findClienteById(listCliente, tamC, id);
        if(indice == -1)
        {
            printf("No hay bicicletas con ese ID\n");
        }
        else
        {
            system("cls");
            printf("--------------------------------------------------------------------------\n");
            printf("  ID             Dni                Nombre                Apellido          \n");
            printf("--------------------------------------------------------------------------\n");
            mostrarCliente(listCliente[indice]);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                listCliente[indice].isEmpty = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}

int obtenerDescripcionCliente(eCliente lista[], int len, int ID, char descripcion[])
{
    int error = -1;

    if(lista != NULL && descripcion != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == ID)
            {
                strcpy(descripcion,lista[i].nombre);
                error = 0;
                break;
            }
        }
    }

    return error;
}


void mostrarClienteCompleto(eCliente listCliente)
{
    orderName(listCliente.nombre);
    orderName(listCliente.apellido);

    printf("%5d       %10s          %10s       %20d      %5d\n",
           listCliente.id,
           listCliente.nombre,
           listCliente.apellido,
           listCliente.dni,
           listCliente.cantidadPrestamos
          );
}

int mostrarClientesCompleto(eCliente* listClientes, int tamC)
{
    if(listClientes != NULL && tamC > 0 && tamC <= 100 )
    {
        system("cls");
        printf("\n                    *** Listado de Clientes ***                    \n");
        printf("-----------------------------------------------------------------------------------------------\n");
        printf("  Id              Nombre                  Apellido             Dni       Cantidad de Prestamos  \n");
        printf("------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tamC; i++)
        {
            if(listClientes[i].isEmpty != 1)
            {
                mostrarClienteCompleto(listClientes[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

int bajaClientex(eCliente* listCliente, int tamC)
{
    int error = -1;
    int id;
    int indice;
    char confirmation;

    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(listCliente != NULL && tamC > 0 && tamC <= 100 )
    {
        mostrarClientes(listCliente,tamC);
        printf("\nIngrese ID del Cliente que desea eliminar: ");
        fflush(stdin);
        scanf("%d", &id);
        indice = findClienteById(listCliente, tamC, id);
        if(indice == -1)
        {
            printf("No hay bicicletas con ese ID\n");
        }
        else
        {
            system("cls");
            printf("--------------------------------------------------------------------------\n");
            printf("  ID             Dni                Nombre                Apellido          \n");
            printf("--------------------------------------------------------------------------\n");
            mostrarCliente(listCliente[indice]);
            printf("Confirmar baja? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                listCliente[indice].isEmpty = 1;
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}

int findClienteByDni(eCliente list[], int len,int dni)
{
    int indice = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].dni == dni && list[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

