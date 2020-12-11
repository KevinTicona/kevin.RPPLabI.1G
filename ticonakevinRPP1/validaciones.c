#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"


int validations_getOption(int* pResult, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
            {
                *pResult = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}

int validations_charOnly(char* str)
{
    int i = 0;
    while (str[i])
    {
        if (!isalpha(str[i]) && str[i] != ' ' && str[i] != '-'&& str[i] != '_')
        {
            return -1;
        }
        i++;
    }

    return 0;
}

int validations_isValidNumber(char* str)
{
    int retorno = 1;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int validarNumero(char num[])
{

    int i = 0;
    int sw = 0;
    int j;
    j=strlen(num);

    while(i<j && sw == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else
        {
            sw = 1;
        }
    }
    return sw;
}

void validations_formatStr(char* str)
{
    int len;
    strlwr(str);
    str[0] = toupper(str[0]);
    len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            i++;
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = toupper(str[i]);
            }
        }
    }
}

int validations_isValidName(char* nombre)
{
    int len = strlen(nombre);
    int valid = validations_charOnly(nombre);
    if(len > 0 && len < 100 && !valid)
    {
        return 1;
    }

    return 0;
}

int validations_isValidSex(char* sex)
{
    strlwr(sex);
    if(strcmp(sex,"m") == 0 || strcmp(sex,"f") == 0)
    {
        return 1;
    }
    return 0;
}

int validations_isValidEdad(char* edad)
{
    int resultadoValido = validations_isValidNumber(edad);

    int intEdad;

    if(resultadoValido == 1)
    {
        intEdad = atoi(edad);
        if(intEdad >= 0 && intEdad <= 15)
        {
            return 1;
        }
    }

    return 0;
}

int validations_isValidDni(char* dni)
{
    int resultadoValido = validations_isValidNumber(dni);
    int len = strlen(dni);

    if(resultadoValido == 1 && len >=11)
    {
        return 1;

    }

    return 0;
}

void formatName(char name[])
{
    int len;
    strlwr(name);
    name[0] = toupper(name[0]);
    len = strlen(name);
    for(int i = 0; i < len; i++)
    {
        if(name[i] == ' ')
        {
            i++;
            if(name[i] >= 'a' && name[i] <= 'z')
            {
                name[i] = toupper(name[i]);
            }
        }
    }
}

int validaciones_obtenerOpcion(int* pResultado, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResultado != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
            {
                *pResultado = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}

/** \brief Validate that if what is entered is an array of characters
 *
* \return int Return (-1) if Error [Invalid length] - (0) if Ok
 *
 */

int validarCadena(char cadena[])
{

    int i = 0;
    int sw = 0;
    int j;
    j=strlen(cadena);

    while(i<j && sw == 0)
    {
        if(isalpha(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            sw = 1;
        }
    }
    return sw;
}

/** \brief Take the character array and put the first character in uppercase
 */
void orderName(char name[])
{

    int len;
    strlwr(name);
    name[0] = toupper(name[0]);
    len = strlen(name);
    for(int i = 0; i < len; i++)
    {
        if(name[i] == ' ')
        {
            i++;
            if(name[i] >= 'a' && name[i] <= 'z')
            {
                name[i] = toupper(name[i]);
            }
        }
    }
}
