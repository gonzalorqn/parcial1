#include <stdio.h>
#include "Productos.h"
#include <string.h>

/*
    int idAutomovil;
    char patente[50];
    int marca;
    int idPropietario;
    int estado;
*/

int eAuto_init(eAutomoviles automoviles[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && automoviles != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            automoviles[i].estado = 0;
            automoviles[i].idAutomovil = 0;
        }
    }
    return retorno;
}


void eAuto_hardCode(eAutomoviles automoviles[])
{
    int id[] = {1,2,3,4,5,6,7,8,9,10};
    char patente[][50]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int idPropietario[]= {2,1,2,1,3,3,4,1,4,3};

    int i;

    for(i=0; i<10; i++)
    {
        automoviles[i].idAutomovil=id[i];
        automoviles[i].idPropietario=idPropietario[i];
        automoviles[i].estado = 1;
        strcpy(automoviles[i].patente, patente[i]);
        automoviles[i].marca = marca[i];
    }
}

int eAuto_buscarLugarLibre(eAutomoviles automoviles[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && automoviles != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(automoviles[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAuto_siguienteId(eAutomoviles automoviles[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && automoviles != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(automoviles[i].estado == 1)
            {
                    if(automoviles[i].idAutomovil>retorno)
                    {
                         retorno=automoviles[i].idAutomovil;
                    }

            }
        }
    }

    return retorno+1;
}

int eAuto_buscarPorId(eAutomoviles automoviles[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && automoviles != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(automoviles[i].estado == 1 && automoviles[i].idAutomovil == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAuto_devolverHorasEstadia(void)
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas;
}
