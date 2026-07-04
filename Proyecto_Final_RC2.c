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
void actualizarCita(citas *a, int tam);

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
    mostrarcita(P1,cont);
    guardararchivo(P1,cont);
    printf("\nSe han guardado los datos en citas.csv");
    buscarCita(P1, cont);
    return 0;
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
void buscarCita(citas *a, int tam){

    int codigo;
    int encontrado = 0;
    printf("\nBusca una cita,ingrese el codigo de la cita para ver sus datos: \n");
    scanf("%d",&codigo);

    for(int i = 0; i < tam; i++){

        if(a[i].Cit == codigo){

            printf("\nCita encontrada:\n");

            printf("Codigo: C%03d\n", a[i].Cit);
            printf("Paciente: %s \n",
                   a[i].Paciente);

            printf("Especialidad: %s\n",
                   a[i].Especialidad);

            printf("Fecha: %02d/%02d/%04d\n",
                   a[i].FechaD,
                   a[i].FechaM,
                   a[i].FechaA);

            printf("Hora: %02d:%02d\n",
                   a[i].HoraH,
                   a[i].HoraM);

            printf("Doctor: Dr.%s\n",
                   a[i].Doc);
                
char opcion;

printf("\n¿Desea actualizar esta cita? (S/N): ");
scanf(" %c", &opcion);

if(opcion == 'S' || opcion == 's'){

    getchar();

    printf("\nNuevo nombre del paciente: ");
    fgets(a[i].Paciente, sizeof(a[i].Paciente), stdin);
    a[i].Paciente[strcspn(a[i].Paciente, "\n")] = '\0';

    printf("Nueva especialidad: ");
    fgets(a[i].Especialidad, sizeof(a[i].Especialidad), stdin);
    a[i].Especialidad[strcspn(a[i].Especialidad, "\n")] = '\0';

    printf("Nuevo doctor: ");
    fgets(a[i].Doc, sizeof(a[i].Doc), stdin);
    a[i].Doc[strcspn(a[i].Doc, "\n")] = '\0';

    printf("Nuevo dia: ");
    scanf("%d", &a[i].FechaD);

    printf("Nuevo mes: ");
    scanf("%d", &a[i].FechaM);

    printf("Nuevo año: ");
    scanf("%d", &a[i].FechaA);

    printf("Nueva hora: ");
    scanf("%d", &a[i].HoraH);

    printf("Nuevo minuto: ");
    scanf("%d", &a[i].HoraM);

    printf("\nCita actualizada correctamente.\n");
}
else{
    printf("\nLa cita no fue modificada.\n");
}

            encontrado = 1;
            break;
        }
    }

    if(encontrado == 0){
        printf("\nNo existe una cita con ese codigo.\n");
    }
}
int fechaHoraRepetida(citas *arr, int n, citas *nueva){
    for(int i = 0; i < n; i++){
        if(arr[i].FechaD == nueva->FechaD &&
           arr[i].FechaM == nueva->FechaM &&
           arr[i].FechaA == nueva->FechaA &&
           arr[i].HoraH  == nueva->HoraH &&
           arr[i].HoraM  == nueva->HoraM){
            return 1; 
        }
    }
    return 0; 
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

int horaValida(int hora, int minuto){

    if(hora < 0 || hora > 23)
        return 0;

    if(minuto < 0 || minuto > 59)
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

void guardararchivo(citas*a,int tam){
  FILE *Archivo=fopen("citas.csv","w");
  for (int i = 0; i < tam; i++)
  {
    fprintf(Archivo,"C%03d,%s,%s,%02d/%02d/%02d,%02d:%02d,Dr.%s\n",
        a[i].Cit,
        a[i].Paciente,
        a[i].Especialidad,
        a[i].FechaD,
        a[i].FechaM,
        a[i].FechaA,
        a[i].HoraH,
        a[i].HoraM,
        a[i].Doc);
  }
  fclose(Archivo);
}

