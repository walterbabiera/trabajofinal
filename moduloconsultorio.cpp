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

bool iniciosesion(int &matric);
void calculoedad(int mm, int aa);
void listadoturnos(int matric);
void evolucion(int matric);

main()
{
	setlocale(LC_ALL,"spanish");
	
	int opcionmenu, intentarnuevamente, matric;
	
	bool usuarioconfirmado, iniciado=false;
	
	do{
		system("cls");
		
		printf("Módulo Consultorio Veterinario\n");
		printf("==============================\n");
		
		printf("1.- Iniciar sesión\n");
		printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
		printf("3.- Registrar Evolución de la Mascota\n\n");
		
		printf("4.- Cerrar la aplicación\n\n");
		
		printf("Ingrese una opción: ");
		scanf("%d", &opcionmenu);
		
		switch(opcionmenu)
		{
			case 1:
				system("cls");
				
				printf("-INICIO DE SESIÓN-\n\n");
				
				usuarioconfirmado=iniciosesion(matric);
				
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
						
					}while(intentarnuevamente!=1 && intentarnuevamente!=2);
					
					if(intentarnuevamente==1)
					{
						usuarioconfirmado=iniciosesion(matric);
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
				
				printf("-LISTA DE ESPERA-\n\n");
				
				if(iniciado==true)
				{
					listadoturnos(matric);
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
				
				printf("-REGISTRO DE EVOLUCIÓN-\n\n");
				
				if(iniciado==true)
				{
					evolucion(matric);
				}
				else
				{
					printf("Aún no se ha iniciado sesión.\n");
				}
				
				printf("\n>");
				system("pause");
			break;
			
			case 4:
				printf("\nUd. ha salido de la aplicación.\n\n>");
				
				system("pause");
			break;
			
			default:
				printf("\nUd. no ha seleccionado una opción existente.\n\n>");
				
				system("pause");
				
			break;
		}
		
	}while(opcionmenu!=4);
}

