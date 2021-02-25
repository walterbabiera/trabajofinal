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
bool iniciosesion(int &matric)
{
	int matricula;
	char contrasena[35];
	bool matriculaencontrada=false, contrasenaencontrada=false, iniciada;
	
	veterinario registro;
	
	usuarios aux;
	veterinario aux2;
	
	FILE *arch;//solo busca
	
	printf("Matrícula de veterinario: ");
	scanf("%d", &matricula);
	
	arch=fopen("Veterinarios.dat", "rb");
	
	fread(&aux, sizeof(usuarios), 1, arch);
		
	while(!feof(arch))
	{
		fread(&aux2, sizeof(veterinario), 1, arch);
		
		if(matricula==aux2.Matricula)
		{
			matriculaencontrada=true;
		}
		
		fread(&aux, sizeof(usuarios), 1, arch);
	}
	
	fseek(arch, 0, SEEK_SET);
	
	printf("Contraseña: ");
	_flushall();
	
	gets(contrasena);
	
	fread(&aux, sizeof(usuarios), 1, arch);
		
	while(!feof(arch))
	{
		//printf("\n>%s<\n", aux.Contrasena);
		
		if(matriculaencontrada==true && strcmp(contrasena, aux.Contrasena)==0)
		{
			contrasenaencontrada=true;	
		}
		
		fread(&aux2, sizeof(veterinario), 1, arch);
		
		fread(&aux, sizeof(usuarios), 1, arch);
	}
	
	fclose(arch);
	
	if(matriculaencontrada==true && contrasenaencontrada==true)
	{
		iniciada=true;
	}
	else
	{
		iniciada=false;
	}
	
	matric=matricula;//declara la matricula
	
	return iniciada;
}

void calculoedad(int mm, int aa)
{
	int mes=12, ano=2020, edad;
	
	if(aa==ano)
	{
		edad=mes-mm;
		
		printf("Aprox %d mes/es", edad);
	}
	else
	{
		edad=ano-aa;
		
		printf("Aprox %d año/s", edad);
	}
}

void listadoturnos(int matric)
{
	FILE *archturnos, *archmascotas;
	
	int i, cant=0, dni, dnis[100];
	
	bool usado;
	
	turnos auxturnos;
	mascota auxmascotas;
	
	archturnos=fopen("Turnos.dat", "rb");
	
	if(archturnos==NULL)
	{
		printf("Aún no se han registrado turnos.\n");
	}
	else
	{
		archmascotas=fopen("Mascotas.dat", "rb");
		
		if(archmascotas==NULL)
		{
			printf("Aún no se han registrado mascotas.\n");
		}
		else
		{
			printf(">Turnos de veterinario c/ matricula %d<\n\n", matric);
			
			fread(&auxturnos, sizeof(turnos), 1, archturnos);
			
			while(!feof(archturnos))
			{
				//printf("\n\n%d\n\n", auxturnos.matriculaveterinario);
				
				if(auxturnos.matriculaveterinario==matric)
				{
					//printf("\n\pasa\n\n");
					
					usado=true;
					
					dni=auxturnos.DNI_Dueno;
					
					dnis[cant]=dni;
					
					for(i=0;i<cant;i++)
					{
						//printf("\n\nentra for\n\n");
						
						if(dnis[i]==dni)
						{
							usado=false;
						}
					}
					
					cant++;//incrementa la cantidad de turnos usados
					
					if(usado==true)
					{
						fread(&auxmascotas, sizeof(mascota), 1, archmascotas);
					
						while(!feof(archmascotas))
						{
							//printf("\n\nentrada archmascotas\n\n");
							
							//printf("\n\n%s\n\n", auxmascotas.ApeNom);
							
							if(auxmascotas.DNI_Dueno==dni && auxturnos.borrado==false)
							{
								printf("Fecha de atención: %-0.2d/%-0.2d/%d", auxturnos.fechaturno.dd, auxturnos.fechaturno.mm, auxturnos.fechaturno.aa);
								
								printf("\nnombre de mascota: %s", auxmascotas.ApeNom);
								
								printf("\nDNI dueño: %d", auxmascotas.DNI_Dueno);
								
								printf("\nLocalidad: %s", auxmascotas.Localidad);
								
								printf("\nEdad: ");
								
								calculoedad(auxmascotas.fechanacimiento.mm, auxmascotas.fechanacimiento.aa);
								
								printf("\nPeso: %.2f", auxmascotas.Peso);
								
								printf("\n\n");	
							}
							
							fread(&auxmascotas, sizeof(mascota), 1, archmascotas);
						}
						
						fseek(archmascotas, 0, SEEK_SET);
					}
					
				}
				
				fread(&auxturnos, sizeof(turnos), 1, archturnos);
				
				//system("pause");
			}
		}
	}
	
	fclose(archturnos);
	fclose(archmascotas);
}
void evolucion(int matric)
{
	FILE *archturnos, *archmascotas;
	
	int dni, pos;
	
	char ApeNom[60];
	
	bool band=false, encontrado=false;
	
	turnos auxturnos;
	mascota auxmascotas;
	
	archturnos=fopen("Turnos.dat", "r+b");
	
	if(archturnos==NULL)
	{
		printf("Aún no se han registrado turnos.\n");
	}
	else
	{
		archmascotas=fopen("Mascotas.dat", "rb");
		
		if(archmascotas==NULL)
		{
			printf("Aún no se han registrado mascotas.\n");
		}
		else
		{
			printf("Ingresar apellido y nombre de mascota que se atendió: ");
			_flushall();
			
			gets(ApeNom);
			
			fread(&auxturnos, sizeof(turnos), 1, archturnos);
			
			while(feof(archturnos)==0 && band==false)
			{	
			
				if(auxturnos.matriculaveterinario==matric)
				{
						dni=auxturnos.DNI_Dueno;
					
						fread(&auxmascotas, sizeof(mascota), 1, archmascotas);
						
						while(!feof(archmascotas) && band==false)
						{	
							if(strcmp(ApeNom, auxmascotas.ApeNom)==0 && dni==auxmascotas.DNI_Dueno && auxturnos.borrado==false)
							{
								printf("Detalle de atención (hasta 380 caracteres): ");
								gets(auxturnos.detalle);
								
								auxturnos.borrado=true;
								
								pos=ftell(archturnos)-sizeof(turnos);//revisar que hace ftell
			
								fseek(archturnos, pos, SEEK_SET);
								
								fwrite(&auxturnos, sizeof(turnos), 1, archturnos);
								
								encontrado=true;
								
								band=true;

							}
							else
							{
								fread(&auxmascotas, sizeof(mascota), 1, archmascotas);
							}

						}
						
						fseek(archmascotas, 0, SEEK_SET);
						
						if(encontrado==false)
						{
							fread(&auxturnos, sizeof(turnos), 1, archturnos);	
						}			
				}
				else
				{
					fread(&auxturnos, sizeof(turnos), 1, archturnos);
				}
				
			}
			
			if(encontrado==false)
			{
				printf("El nombre ingresado no corresponde a ninguna mascota con turno.\n\n");
			}
		}
	}
	
	fclose(archturnos);
	fclose(archmascotas);
	
}
