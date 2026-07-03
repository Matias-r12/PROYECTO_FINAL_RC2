//Nombre de los integrantes: Matias Rojas
//Fecha 29/6/2026
//Descripcion:Caso 4,Citas medicas
#include <stdio.h>
#include <string.h>
typedef struct{
int Cit;
char Paciente[16];
char Especialidad[16];
int FechaD;
int FechaM;
int FechaA;
int HoraH;
int HoraM;
char Doc[16];
}citas;
void escribircita(citas* e, citas* arr, int pos);
void buscarCita(citas *a, int tam);
int fechaValida(int dia, int mes, int anio);
int horaValida(int hora, int minuto);
int fechaHoraRepetida(citas *arr, int n, citas *nueva);
void mostrarcita(citas*a,int tam);
void guardararchivo(citas*a,int tam);

int main()
{
    int cont;
    printf("\nIngrese la cantidad total de citas que quieres guardar :");
    scanf("%d",&cont);
    citas P1[cont];
 
  for(int i = 0; i < cont; i++){
        printf("\n--- Cita %d ---\n", i + 1);
        P1[i].Cit = i + 1;
        escribircita(&P1[i], P1, i);  
    }
}
void mostrarcita(citas*a,int tam){
    for (int i = 0; i < tam; i++)
    {
    printf("C%03d",a[i].Cit);
    printf(",%s",a[i].Paciente);
    printf(",%s",a[i].Especialidad);
    printf(",%02d/",a[i].FechaD);
    printf("%02d/",a[i].FechaM);
    printf("%02d/",a[i].FechaA);
    printf(",%02d",a[i].HoraH);
    printf(":%02d",a[i].HoraM);
    printf(",Dr.%s",a[i].Doc);
    

    }
}
int fechaValida(int dia, int mes, int año){

    if(año < 1)
        return 0;

    if(mes < 1 || mes > 12)
        return 0;

    if(dia < 1 || dia > 31)
        return 0;

    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return 0;

    if(mes == 2 && dia > 29)
        return 0;

    return 1;
}


void escribircita(citas *e, citas *arr,int pos){
    
  getchar(); 

    printf("\nIngrese el Nombre del paciente: ");
    fgets(e->Paciente, sizeof(e->Paciente), stdin);
    e->Paciente[strcspn(e->Paciente, "\n")] = '\0';

    printf("Ingrese la especialidad: ");
    fgets(e->Especialidad, sizeof(e->Especialidad), stdin);
    e->Especialidad[strcspn(e->Especialidad, "\n")] = '\0';

    
    do {
        printf("\nIngrese la Fecha");
        printf("\nDia: ");
        scanf("%d",&e->FechaD);
        printf("Mes: ");
        scanf("%d",&e->FechaM);
        printf("Año: ");
        scanf("%d",&e->FechaA);

        printf("\nIngrese la Hora (24 horas)");
        printf("\nHora: ");
        scanf("%d",&e->HoraH);
        printf("Minutos: ");
        scanf("%d",&e->HoraM);

        
        if(!fechaValida(e->FechaD,e->FechaM,e->FechaA)){
        printf("\nERROR: Fecha invalida.\n");
    }

        if(!horaValida(e->HoraH,e->HoraM)){
        printf("\nERROR: Hora invalida.\n");
    }
 
        if(fechaHoraRepetida(arr, pos, e)){
            printf("\nERROR: Ya existe una cita en esa fecha y hora. Intente nuevamente.\n");
        }
         
    } while(
    !fechaValida(e->FechaD,e->FechaM,e->FechaA) ||
    !horaValida(e->HoraH,e->HoraM) ||
    fechaHoraRepetida(arr, pos, e));
        
    getchar(); 

    printf("Ingrese el nombre del doctor: ");
    fgets(e->Doc, sizeof(e->Doc), stdin);
    e->Doc[strcspn(e->Doc, "\n")] = '\0';

}

