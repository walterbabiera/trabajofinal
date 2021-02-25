#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct usuarios
{
	char Usuario[10];
	char Contrasena[10];
	char ApeNom[60];	
};

struct veterinario
{
	char ApeNom[60];
	int Matricula;
	int DNI;
	char Telefono[25];
};

struct fecha
{
	int dd, mm, aa;
};

struct mascota
{
	char ApeNom[60];
	char Domicilio[60];
	int DNI_Dueno;
	char Localidad[60];
	fecha fechanacimiento;
	float Peso;
	char Telefono[25];
};

struct turnos
{
	int matriculaveterinario;
	fecha fechaturno;
	int DNI_Dueno;
	char detalle[380];	
	bool borrado;
};

bool iniciosesion();
void registromascota();
void registroturno();
void listadoturnos();

main()
{
	setlocale(LC_ALL,"spanish");// el idioma que toma el programa
	
	int opcionmenu, intentarnuevamente;
	
	bool usuarioconfirmado, iniciado=false;
	
	do{
		system("cls");
		
		printf("Módulo del Asistente\n");
		printf("==============================\n");
		
		printf("1.- Iniciar sesión\n");
		printf("2.- Registrar Mascota\n");
		printf("3.- Registrar turno\n");
		printf("4.- Listado de Atenciones por Veterinario y Fecha\n\n");
		
		printf("5.- Cerrar la aplicación\n\n");
		
		printf("Ingrese una opción: ");
		scanf("%d", &opcionmenu);
		
		switch(opcionmenu)
		{
			case 1:
				system("cls");
				
				printf("-INICIO DE SESIÓN-\n\n");
				
				usuarioconfirmado=iniciosesion(); //lamado a la funcion
				
				if(usuarioconfirmado==true)
				{
					printf("\n>Se ha iniciado sesión.");
					
					iniciado=true;
				}
				
				while(usuarioconfirmado==false)
				{
					printf("\nEl usuario o la contraseña ingresada son incorrectas.");
					
					printf("\n\n----------\n\n");
					
					do
					{
						printf("¿Quiere intentarlo nuevamente?");
						printf("\n1.- Si");
						printf("\n2.- No");
						
						printf("\n\nOpcion: ");
						scanf("%d", &intentarnuevamente);
						
						switch(intentarnuevamente)
						{
							case 1:
								//
							break;
							
							case 2:
								//
							break;
							
							default:
								printf("\nLa opción ingresada es inexistente. Intentelo nuevamente.");
							break;
						}
						
						printf("\n\n----------\n\n");												
						
					}while(intentarnuevamente!=1 && intentarnuevamente!=2);//pide ingresar el usuario y la contraseña de nuevo
					
					if(intentarnuevamente==1)
					{
						usuarioconfirmado=iniciosesion();
					}
					
					if(usuarioconfirmado==true)
					{
						printf("\n>Se ha iniciado sesión.");
						
						iniciado=true;
					}
					
					if(intentarnuevamente==2)
					{
						usuarioconfirmado=true;
					}
				}
				
				printf("\n>");
				system("pause");
			break;
			
			case 2:
				system("cls");
				
				printf("-REGISTRO DE MASCOTA-\n\n");
				
				if(iniciado==true)
				{
					registromascota();
					
					printf("\nLa mascota se ha registrado con éxito.\n");
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n>");
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				printf("-REGISTRO DE TURNO-\n\n");
				
				if(iniciado==true)
				{
					registroturno();
					
					printf("\nEl turno se ha registrado con éxito.\n");
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n>");
				
				system("pause");
			break;
			
			case 4:
				system("cls");
				
				printf("-LISTADO DE ATENCIONES-\n\n");
				
				if(iniciado==true)
				{
					listadoturnos();
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n\n>");
				system("pause");
			break;
			
			case 5:
				printf("\nUd. ha salido de la aplicación.\n\n>");
				
				system("pause");
			break;
			
			default:
				printf("\nUd. no ha seleccionado una opción existente.\n\n>");
				
				system("pause");
				
			break;
		}
		
	}while(opcionmenu!=5);
}

