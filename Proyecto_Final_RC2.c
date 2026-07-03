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


