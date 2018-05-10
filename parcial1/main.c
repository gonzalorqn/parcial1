#include <stdio.h>
#include <stdlib.h>
#include "Usuarios.h"
#define TAMPROPIETARIOS 100
#define TAMAUTOMOVILES 20

int main()
{
    eAutomoviles listaDeAutomoviles[TAMAUTOMOVILES];
    ePropietario listaDePropietarios[TAMPROPIETARIOS];

    eAuto_init(listaDeAutomoviles, TAMAUTOMOVILES);
    eAuto_hardCode(listaDeAutomoviles);

    eProp_init(listaDePropietarios,TAMPROPIETARIOS);
    eProp_hardCode(listaDePropietarios);

    int opcion;
    int index;
    do
    {
        printf("1. ALTA DE PROPIETARIO\n2. MODIFICACION DE PROPIETARIO\n3. BAJA DE PROPIETARIO\n4. INGRESO DEL AUTOMOVIL\n5. EGRESO DEL AUTOMOVIL\n6. \n7. \n8. \n9. LISTAR AUTOMOVILES\n10. LISTAR PROPIETARIOS\n11. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            index = eProp_alta(listaDePropietarios, TAMPROPIETARIOS);
            if(index == 0)
            {
                printf("Propietario ingresado\n\n");
            }
            else
            {
                printf("No hay lugar\n\n");
            }
            break;

        case 2:
            index = eProp_modificacion(listaDePropietarios, TAMPROPIETARIOS);
            if(index == 0)
            {
                printf("Propietario modificado\n\n");
            }
            else
            {
                printf("ID incorrecto\n\n");
            }
            break;

        case 3:
            index = eProp_baja(listaDePropietarios, listaDeAutomoviles, TAMPROPIETARIOS, TAMAUTOMOVILES);
            if(index == 0)
            {
                printf("Propietario dado de baja\n\n");
            }
            else
            {
                printf("ID incorrecto\n\n");
            }
            break;

        case 4:
            index = eAuto_alta(listaDeAutomoviles, listaDePropietarios, TAMAUTOMOVILES, TAMPROPIETARIOS);
            if(index == 0)
            {
                printf("Automovil ingresado\n\n");
            }
            else if(index == -3)
            {
                printf("ID incorrecto\n\n");
            }
            else
            {
                printf("No hay lugar\n\n");
            }
            break;

        case 5:
            index = eAuto_baja(listaDeAutomoviles,listaDePropietarios,TAMAUTOMOVILES,TAMPROPIETARIOS);
            if(index == 0)
            {
                printf("Automovil dado de baja\n\n");
            }
            else
            {
                printf("ID de automovil incorrecto\n\n");
            }
            break;

        case 6:
            index = eAuto_modificacion(listaDeAutomoviles,listaDePropietarios,TAMAUTOMOVILES,TAMPROPIETARIOS);
            if(index == 0)
            {
                printf("Producto modificado\n\n");
            }
            else if(index == -3)
            {
                printf("ID de producto incorrecto\n\n");
            }
            else
            {
                printf("ID de usuario incorrecto\n\n");
            }
            break;

        case 7:
            index = eAuto_compra(listaDeAutomoviles,listaDePropietarios,TAMAUTOMOVILES,TAMPROPIETARIOS);
            if(index == 0)
            {
                printf("Producto comprado\n\n");
            }
            else if(index == -3)
            {
                printf("No hay stock\n\n");
            }
            else
            {
                printf("ID de producto incorrecto\n\n");
            }
            break;

        case 8:
            index = eProp_listarPublicaciones(listaDeAutomoviles,listaDePropietarios,TAMAUTOMOVILES,TAMPROPIETARIOS);
            if(index == 0)
            {

            }
            else
            {
                printf("ID de usuario incorrecto\n\n");
            }
            break;

        case 9:
            eAuto_listarAutomoviles(listaDeAutomoviles,TAMAUTOMOVILES,listaDePropietarios,TAMPROPIETARIOS);
            break;

        case 10: eProp_mostrar(listaDePropietarios,TAMPROPIETARIOS);
                 printf("\n");
            //eProp_listarPropietarios(listaDePropietarios,TAMPROPIETARIOS);
            break;
        }

    }
    while(opcion!=11);

    return 0;
}
