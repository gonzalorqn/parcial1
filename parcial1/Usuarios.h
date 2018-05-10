
#include "Productos.h"

typedef struct
{
    int idPropietario;
    char nombre[50];
    char apellido[50];
    char direccion[50];
    char numeroTarjeta[50];
    int estado;
}ePropietario;

int eProp_init(ePropietario propietarios[], int limite);
void eProp_hardCode(ePropietario propietarios[]);
int eProp_buscarLugarLibre(ePropietario propietarios[],int limite);
int eProp_siguienteId(ePropietario propietarios[],int limite);
int eProp_alta(ePropietario propietarios[],int limite);
int eProp_buscarPorId(ePropietario propietarios[] ,int limite, int id);
int eProp_modificacion(ePropietario propietarios[],int limite);
int eProp_baja(ePropietario propietarios[],eAutomoviles automoviles[],int limiteProp,int limiteAuto);
void eProp_mostrarUno(ePropietario propietarios);
void eProp_mostrar(ePropietario propietarios[], int cant);
int eAuto_alta(eAutomoviles automoviles[], ePropietario propietarios[],int limiteAuto, int limiteProp);
int eAuto_calcularEstadia(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp,int cual,int horas);

int eAuto_modificacion(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp);
void eProp_mostrarUsuarioConSusautomoviles(eAutomoviles automoviles[], int limiteAuto, ePropietario propietarios[], int limiteProp,int idUsu);
int eAuto_baja(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp);
int eAuto_compra(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp);
int eProp_calificacion(ePropietario propietarios[],int limite,int cual);
int eProp_listarPublicaciones(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp);
void eAuto_listarAutomoviles(eAutomoviles automoviles[], int limiteAuto, ePropietario propietarios[], int limiteProp);
void eProp_listarpropietarios(ePropietario propietarios[],int cant);
void eProp_mostrarUnoConCalificacion(ePropietario propietarios);
