#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

/*
    int idPropietario;
    char nombre[50];
    char apellido[50];
    char direccion[50];
    char numeroTarjeta[50];
    int estado;
*/

int eProp_init(ePropietario propietarios[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && propietarios != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            propietarios[i].estado = 0;
            propietarios[i].idPropietario = 0;
        }
    }
    return retorno;
}

void eProp_hardCode(ePropietario propietarios[])
{
    int id[4] = {1,2,3,4};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa"};
    char apellido[][50]= {"Lopez","Perez","Gutierrez","Gomez"};
    char direccion[][50]= {"Mitre","9 de Julio","Rivadavia","Alsina"};
    char numeroTarjeta[][50] = {"111-111","222-222","333-333","444-444"};

    int i;

    for(i=0; i<4; i++)
    {
        propietarios[i].idPropietario=id[i];
        propietarios[i].estado = 1;
        strcpy(propietarios[i].nombre, nombre[i]);
        strcpy(propietarios[i].apellido, apellido[i]);
        strcpy(propietarios[i].direccion, direccion[i]);
        strcpy(propietarios[i].numeroTarjeta, numeroTarjeta[i]);

    }

}

int eProp_buscarLugarLibre(ePropietario propietarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(propietarios[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProp_siguienteId(ePropietario propietarios[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(propietarios[i].estado == 1)
            {
                    if(propietarios[i].idPropietario>retorno)
                    {
                         retorno=propietarios[i].idPropietario;
                    }

            }
        }
    }

    return retorno+1;
}

int eProp_alta(ePropietario propietarios[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        indice = eProp_buscarLugarLibre(propietarios,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eProp_siguienteId(propietarios,limite);

            retorno = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(propietarios[indice].nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(propietarios[indice].apellido);
            printf("Ingrese direccion: ");
            fflush(stdin);
            gets(propietarios[indice].direccion);
            printf("Ingrese numero de tarjeta: ");
            fflush(stdin);
            gets(propietarios[indice].numeroTarjeta);
            propietarios[indice].idPropietario = id;
            propietarios[indice].estado = 1;
        }
    }
    return retorno;
}

int eProp_buscarPorId(ePropietario propietarios[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(propietarios[i].estado == 1 && propietarios[i].idPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProp_modificacion(ePropietario propietarios[],int limite)
{
    int retorno = -1;
    int id;
    char seguir;
    int indice;

    if(limite > 0 && propietarios != NULL)
    {
        retorno = -2;
        eProp_mostrar(propietarios,limite);
        printf("Ingrese ID a modificar: ");
        scanf("%d", &id);

        indice = eProp_buscarPorId(propietarios,limite,id);

        printf("Esta seguro? s/n ");
        scanf("%s", &seguir);
        printf("\n");

        if(indice == -2 || indice == -1 || seguir == 'n')
        {

        }

        else
        {
            retorno = 0;
            printf("Ingrese numero de tarjeta: ");
            fflush(stdin);
            gets(propietarios[indice].numeroTarjeta);
            propietarios[indice].estado = 1;
        }
    }
    return retorno;
}

int eProp_baja(ePropietario propietarios[],eAutomoviles automoviles[],int limiteProp,int limiteAuto)
{
    int retorno = -1;
    int id;
    int indice;
    char seguir;
    int i;

    if(limiteProp > 0 && propietarios != NULL && limiteAuto > 0 && automoviles != NULL)
    {
        retorno = -2;
        eProp_mostrar(propietarios,limiteProp);
        printf("Ingrese ID a dar de baja: ");
        scanf("%d", &id);

        indice = eProp_buscarPorId(propietarios,limiteProp,id);
        printf("Esta seguro? s/n ");
        scanf("%s", &seguir);
        printf("\n");

        if(indice == -2 || indice == -1 || seguir == 'n')
        {

        }

        else
        {
            retorno = 0;
            propietarios[indice].estado = 0;

            for(i=0;i<limiteAuto;i++)
            {
                if(automoviles[i].idPropietario == propietarios[indice].idPropietario)
                {
                    automoviles[i].estado = 0;
                }
            }

        }
    }
    return retorno;
}

void eProp_mostrarUno(ePropietario propietarios)
{
    printf("%d %s %s %s\n",propietarios.idPropietario, propietarios.nombre, propietarios.apellido, propietarios.numeroTarjeta);
}

void eProp_mostrar(ePropietario propietarios[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(propietarios[i].estado == 1)
        {
            eProp_mostrarUno(propietarios[i]);
        }
    }
}


int eAuto_alta(eAutomoviles automoviles[], ePropietario propietarios[],int limiteAuto, int limiteProp)
{
    int retorno = -1;
    int id;
    int idProp;
    int indice;
    int auxMarca;
    int i;

    if(limiteAuto > 0 && automoviles != NULL && limiteProp > 0 && propietarios != NULL)
    {
        retorno = -2;
        indice = eAuto_buscarLugarLibre(automoviles,limiteAuto);
        if(indice >= 0)
        {
            retorno = -3;
            id = eAuto_siguienteId(automoviles,limiteAuto);

            eProp_mostrar(propietarios,limiteProp);
            printf("Ingrese ID propietario: ");
            scanf("%d", &idProp);
            for(i=0;i<limiteProp;i++)
            {
                if(idProp == propietarios[i].idPropietario && propietarios[i].estado == 1)
                {
                    retorno = 0;
                    printf("Ingrese patente: ");
                    fflush(stdin);
                    gets(automoviles[indice].patente);
                    do
                    {
                        printf("Ingrese marca (1,2,3,4): ");
                        scanf("%d", &auxMarca);
                    }while(auxMarca<1 || auxMarca>4);
                    automoviles[indice].idAutomovil = id;
                    automoviles[indice].estado = 1;
                    automoviles[indice].idPropietario = idProp;
                    automoviles[indice].marca = auxMarca;

                }
            }
        }
    }
    return retorno;
}

int eAuto_modificacion(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp)
{
    int retorno = -1;
    int id;
    int idProd;
    int indice;

    if(limiteProp > 0 && propietarios != NULL && limiteAuto > 0 && automoviles != NULL)
    {
        retorno = -2;
        eProp_mostrar(propietarios,limiteProp);
        printf("Ingrese ID de usuario: ");
        scanf("%d", &id);

        indice = eProp_buscarPorId(propietarios,limiteProp,id);

        if(indice == -2 || indice == -1)
        {

        }

        else
        {
            retorno = -3;
            //eProp_mostrarUsuarioConSusAutomoviles(automoviles,limiteAuto,propietarios,limiteProp,id);
            printf("Ingrese ID de producto: ");
            scanf("%d", &idProd);

            indice = eAuto_buscarPorId(automoviles,limiteAuto,idProd);

            if(indice == -2 || indice == -1 || automoviles[indice].idPropietario != id)
            {

            }

            else
            {
                retorno = 0;
                printf("Ingrese nuevo precio: ");
                //scanf("%f", &automoviles[indice].precio);
                printf("Ingrese stock: ");
                //scanf("%d", &automoviles[indice].stock);
                automoviles[indice].estado = 1;
            }

        }
    }
    return retorno;
}

void eProp_mostrarPropietarioConSusautomoviles(eAutomoviles automoviles[], int limiteAuto, ePropietario propietarios[], int limiteProp,int idUsu)
{
    int i;
    int j;
    for(i=0;i<limiteProp;i++)
    {
        if(propietarios[i].estado == 1 && propietarios[i].idPropietario == idUsu)
        {
            printf("%s:\n",propietarios[i].nombre);
            for(j=0;j<limiteAuto;j++)
            {
                if(propietarios[i].idPropietario == automoviles[j].idPropietario && automoviles[j].estado == 1)
                {
                    //printf("%d - %s - %.2f - %d - %d\n",automoviles[j].idAutomovil,automoviles[j].patente,automoviles[j].precio,automoviles[j].cantidadVendida,automoviles[j].stock);
                }
            }
            printf("\n");

        }
    }
}

int eAuto_baja(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp)
{
    int retorno = -1;
    int id;
    int indice;
    int horas;
    int estadia;

    if(limiteProp > 0 && propietarios != NULL && limiteAuto > 0 && automoviles != NULL)
    {
        retorno = -2;
        eAuto_listarAutomoviles(automoviles,limiteAuto,propietarios,limiteProp);
        printf("Ingrese ID de automovil: ");
        scanf("%d", &id);

        indice = eAuto_buscarPorId(automoviles,limiteAuto,id);

        if(indice == -2 || indice == -1)
        {

        }
        else
        {
            retorno = 0;
            automoviles[indice].estado = 0;
            horas = eAuto_devolverHorasEstadia();
            estadia = eAuto_calcularEstadia(automoviles,propietarios,limiteAuto,limiteProp,id,horas);
            printf("Horas: %d \n", horas);
            printf("Estadia: %d \n", estadia);

        }

    }

    return retorno;
}

int eAuto_calcularEstadia(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp,int cual,int horas)
{
    int estadia = -1;
    eAuto_listarAutomoviles(automoviles,limiteAuto,propietarios,limiteProp);

    if(automoviles != NULL)
    {
        estadia = 0;
        printf("%d \n", automoviles[cual].marca);
        /*if(strcmp(automoviles[cual].marca, "ALPHA_ROMEO")== 0)
        {
            estadia = horas * 150;
        }
        else if(strcmp(automoviles[cual].marca, "FERRARI")== 0)
        {
            estadia = horas * 175;
        }
        else if(strcmp(automoviles[cual].marca, "AUDI")== 0)
        {
            estadia = horas * 200;
        }
        else if(strcmp(automoviles[cual].marca, "OTRO") == 0)
        {
            estadia = horas * 250;
        }*/
    }
    return estadia;
}

int eAuto_compra(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp)
{
    int retorno = -1;
    int id;
    int indice;
    int indiceProp;
    int calif;

    if(limiteProp > 0 && propietarios != NULL && limiteAuto > 0 && automoviles != NULL)
    {
        retorno = -2;
        printf("Ingrese ID de producto: ");
        scanf("%d", &id);

        indice = eAuto_buscarPorId(automoviles,limiteAuto,id);

        if(indice == -2 || indice == -1)
        {

        }
        //else if(automoviles[indice].stock == 0)
        //{
            //retorno = -3;
        //}
        else
        {
            retorno = 0;
            //automoviles[indice].stock--;
            //automoviles[indice].cantidadVendida++;
            //indiceProp = eProp_buscarPorId(propietarios,limiteProp,automoviles[indice].idPropietario);
            //calif = eProp_calificacion(propietarios,limiteProp,indiceProp);
        }

    }

    return retorno;
}

int eProp_calificacion(ePropietario propietarios[],int limite,int cual)
{
    int retorno = -1;
    int calif;
    if(limite > 0 && propietarios != NULL)
    {
        retorno = 0;
        do
        {
            printf("Ingrese calificacion del vendedor: ");
            scanf("%d", &calif);
        }while(calif < 1 || calif > 10);
        //propietarios[cual].promCalificaciones = ((propietarios[cual].promCalificaciones * propietarios[cual].contCalificaciones) + calif) / (propietarios[cual].contCalificaciones + 1);
        //propietarios[cual].contCalificaciones++;
    }
    return retorno;
}

int eProp_listarPublicaciones(eAutomoviles automoviles[],ePropietario propietarios[],int limiteAuto,int limiteProp)
{
    int retorno = -1;
    int id;
    int idProd;
    int indice;

    if(limiteProp > 0 && propietarios != NULL && limiteAuto > 0 && automoviles != NULL)
    {
        retorno = -2;
        eProp_mostrar(propietarios,limiteProp);
        printf("Ingrese ID de usuario: ");
        scanf("%d", &id);

        indice = eProp_buscarPorId(propietarios,limiteProp,id);

        if(indice == -2 || indice == -1)
        {

        }

        else
        {
            retorno = 0;
            //eProp_mostrarUsuarioConSusAutomoviles(automoviles,limiteAuto,propietarios,limiteProp,id);
        }
    }

    return retorno;
}

void eAuto_listarAutomoviles(eAutomoviles automoviles[], int limiteAuto, ePropietario propietarios[], int limiteProp)
{
    int i;
    int j;

    printf("ID - Patente - Marca - Propietario\n");
    for(j=0;j<limiteAuto;j++)
    {
        if(automoviles[j].estado == 1)
        {
            switch(automoviles[j].marca)
            {
                case 1: printf("%d - %s - ALPHA_ROMEO - ",automoviles[j].idAutomovil,automoviles[j].patente);
                    break;
                case 2: printf("%d - %s - FERRARI - ",automoviles[j].idAutomovil,automoviles[j].patente);
                    break;
                case 3: printf("%d - %s - AUDI - ",automoviles[j].idAutomovil,automoviles[j].patente);
                    break;
                case 4: printf("%d - %s - OTRO - ",automoviles[j].idAutomovil,automoviles[j].patente);
                    break;
            }


            for(i=0;i<limiteProp;i++)
            {
                if(propietarios[i].estado == 1 && propietarios[i].idPropietario == automoviles[j].idPropietario)
                {
                    printf("%s\n",propietarios[i].nombre);
                }
            }
        }

    }
    printf("\n");
}

void eProp_listarPropietarios(ePropietario propietarios[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(propietarios[i].estado == 1)
        {
            eProp_mostrarUnoConCalificacion(propietarios[i]);
        }
    }
    printf("\n");
}

void eProp_mostrarUnoConCalificacion(ePropietario propietarios)
{
//    printf("%s - %.2f\n",propietarios.nombre,propietarios.promCalificaciones);
}

