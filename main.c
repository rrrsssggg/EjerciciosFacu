#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TAM 10
#define TAM2 25

typedef struct
	{int dd;
   int mm;
   int aaaa;
   }fecha;

typedef struct
	{char nomb[TAM2];
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

void llenar_v(alumno v[]);

void main ()
{
	alumno v[TAM];
	FILE * pf;
   int i;

   llenar_v(v);

	pf=fopen ("alumnos.dat","wb");

   if (pf==NULL)
   	{printf ("\n\nNo se pudo abrir el archivo...");
      getch ();
      exit (1);
      }

   for (i=0;i<TAM;i++)
   	fwrite (&v[i],sizeof (alumno),1,pf);

   fclose (pf);

   getch();

}


void llenar_v (alumno v[])
{
	int i;
	for(i=0;i<TAM;i++)
		{
      	printf ("\nIngresar nommbre: ");
         fflush (stdin);
         gets (v[i].nomb);
         /*printf ("Ingresar apellido: ");
         fflush (stdin);
         gets (v[i].ape);
         printf ("Ingresar DNI: ");
         fflush (stdin);
         scanf ("%d",&v[i].dni);
         printf ("Ingresar Fecha de Nacimiento en formato dd/mm/aaaa: ");
         scanf ("%d%d%d", &v[i].fecha_nac.dd,&v[i].fecha_nac.mm,&v[i].fecha_nac.aaaa);
         fflush (stdin);
         printf ("Ingresar carrera: ");
         gets (v[i].car);
         printf ("Ingresar anio de ingreso: ");
         scanf ("%d",&v[i].anio_in);
         printf ("Ingresar Cantidad de Materias Aprobadas: ");
         scanf ("%d",&v[i].cant_mat_ap);
         fflush(stdin);
         printf ("Ingresar cantidad de materias que estoy cursando: ");
         scanf ("%d",&v[i].cant_mat_curso);
         fflush (stdin);
         printf("Ingresar e-mail: ");
         gets(v[i].mail);
         */
         printf("Ingresar Numero de telefono: ");
         scanf("%d",v[i].tel);
         fflush (stdin);
      }
}
