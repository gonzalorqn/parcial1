
typedef struct
{
    int idAutomovil;
    char patente[50];
    int marca;
    int idPropietario;
    int estado;
}eAutomoviles;

int eAuto_init(eAutomoviles automoviles[], int limite);
void eAuto_hardCode(eAutomoviles automoviles[]);
int eAuto_buscarLugarLibre(eAutomoviles automoviles[],int limite);
int eAuto_siguienteId(eAutomoviles automoviles[],int limite);
int eAuto_buscarPorId(eAutomoviles automoviles[] ,int limite, int id);
int eAuto_devolverHorasEstadia(void);
