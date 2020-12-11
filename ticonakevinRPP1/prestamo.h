#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
typedef struct{
    int id;
    int idCliente;
    int importe;
    int cantidadDeCuotas;
    int estado;
    int isEmpty;
}ePrestamo;

#endif // PRESTAMO_H_INCLUDED

int inicializar_Prestamo(ePrestamo* lista, int tam);
int altaPrestamo(ePrestamo listPrestamo[],int tamP, int id,eCliente listCliente[], int tamC);
void mostrarPrestamo(ePrestamo listPrestamo, eCliente listCliente[], int tamC);
int mostrarPrestamos(ePrestamo listPrestamo[], int tamP, eCliente listCliente[], int tamC);
int findPrestamoById(ePrestamo list[], int len,int id);
int saldarPrestamo(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC);
int activarPrestamo(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC);
int imprimirPrestamosDni(ePrestamo listPrestamo[],int tamP,eCliente listCliente[], int tamC);
