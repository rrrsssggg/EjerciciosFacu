#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 10
#define TAM2 25

/////////////////////////////////////////////////////////////
//// estructuras
/////////////////////////////////////////////////////////////
typedef struct
	{
	int dd;
   	int mm;
   	int aaaa;
   }fecha;

typedef struct
	{
	char nomb[TAM2];
   	char ape[TAM2];
   	int dni;
   	fecha fecha_nac;
   	char car[TAM2];
   	int anio_in;
   	int cant_mat_ap;
   	int cant_mat_curso;
	char mail[50];
   	int tel;
   }alumno;


/////////////////////////////////////////////////////////////
//// prototipo de funciones
/////////////////////////////////////////////////////////////
void llenar_v(alumno v*);



/////////////////////////////////////////////////////////////
//// main
/////////////////////////////////////////////////////////////
void main ()
{
    alumno v[TAM];
	FILE * pf;
    int i;

    llenar_v(v);

	pf=fopen ("alumnos.txt","wt");

    if (!pf)
   	{
        printf ("\n\nNo hay memoria");
        getch ();
        exit (1);
    }

    for (i=0;i<TAM;i++)
        fwrite (&v[i],sizeof(alumno),1,pf);

    fclose (pf);
    getch();

}


/////////////////////////////////////////////////////////////
//// llenar_v
/////////////////////////////////////////////////////////////
void llenar_v (alumno *v)
{
	int *pfi = v+TAM;
	while(v < pfi)
    {
        printf ("\nIngresar nommbre: ");
        fflush (stdin);
        gets (v->nomb);
        printf ("Ingresar apellido: ");
        fflush (stdin);
        gets (v->ape);
        printf ("Ingresar DNI: ");
        fflush (stdin);
        scanf ("%d",&v->dni);
        printf ("Ingresar Fecha de Nacimiento en formato dd/mm/aaaa: ");
        scanf ("%d/%d/%d",&v->fecha_nac.dd,&v->fecha_nac.mm,&v->fecha_nac.aaaa);
        fflush (stdin);
        printf ("Ingresar carrera: ");
        gets (v->car);
        printf ("Ingresar anio de ingreso: ");
        scanf ("%d",&v->anio_in);
        printf ("Ingresar Cantidad de Materias Aprobadas: ");
        scanf ("%d",&v->cant_mat_ap);
        fflush(stdin);
        printf ("Ingresar cantidad de materias que estoy cursando: ");
        scanf ("%d",&v->cant_mat_curso);
        fflush (stdin);
        printf("Ingresar e-mail: ");
        gets(v->mail);
        printf("Ingresar Numero de telefono: ");
        scanf("%d",&v->tel);
        fflush (stdin);
        v++;
      }
}
