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

bool verificacionnombre(int vou, char nombre[15]);
bool verificacioncontrasena(char contra[35]);
void registracionconfirmada(int vou, char nombre[15], char contra[35]);
void atencionporveterinarios();
void ranking();
main()
{
	setlocale(LC_ALL,"spanish");
	
	int opcionmenu, veterionarioasistente;
	
	char usuario[15], contrasena[35], apellidonombre[60];
	
	bool filtronombre, filtrocontrasena;
	
	do
	{
		system("cls");
		
		printf("Módulo de Administración\n");
		printf("==============================\n");
		
		printf("1.- Registrar Veterinario\n");
		printf("2.- Registrar Usuario Asistente\n");
		printf("3.- Atenciones por Veterinarios\n");
		printf("4.- Ranking de Veterinarios por Atenciones\n\n");
		
		printf("5.- Cerrar la aplicación\n\n");
		
		printf("Ingrese una opción: ");
		scanf("%d", &opcionmenu);
		
		switch(opcionmenu)
		{
			case 1:
				system("cls");
				
				veterionarioasistente=0;
				
				printf("REGISTRAR VETERINARIO\n\n");
				
				printf("-NOMBRE DE USUARIO\n\n");
								
				printf("Condiciones para nombre de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
				printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
				printf("> Ser único para cada usuario registrado.\n");
				printf("> Comenzar con una letra minúscula.\n");
				printf("> Tener al menos 2 letras mayúsculas.\n");
				printf("> Tener como máximo 3 dígitos.\n\n");
				
				printf("Ingrese nombre de usuario: ");
				_flushall();
				gets(usuario);
				
				filtronombre=verificacionnombre(veterionarioasistente, usuario);
				
				while(filtronombre==false)
				{
					printf("\n----------\n\n");
					
					printf("El nombre de usuario ingresado es invalido o ya fue registrado.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
					printf("Condiciones para nombre de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
					printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
					printf("> Ser único para cada usuario registrado.\n");
					printf("> Comenzar con una letra minúscula.\n");
					printf("> Tener al menos 2 letras mayúsculas.\n");
					printf("> Tener como máximo 3 dígitos.\n\n");
					
					printf("Ingrese nombre de usuario: ");
					_flushall();
					gets(usuario);
					
					filtronombre=verificacionnombre(veterionarioasistente, usuario);
				}
				
				printf("\n-NOMBRE CORRECTO-\n");
				
				printf("\n----------\n\n");
				
				printf("-CONTRASEÑA DE USUARIO\n\n");
				
				printf("Condiciones para contraseña de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
				printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
				printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
				printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
				printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
				
				printf("Ingrese contraseña de usuario: ");
				_flushall();//guarda la contraseña
				gets(contrasena);
				
				filtrocontrasena=verificacioncontrasena(contrasena);
				
				while(filtrocontrasena==false)
				{
					printf("\n----------\n\n");
					
					printf("La contraseña del usuario ingresada es invalida.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
						printf("Condiciones para contraseña de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
					printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
					printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
					printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
					printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
					
					printf("Ingrese contraseña de usuario: ");
					_flushall();
					gets(contrasena);
					
					filtrocontrasena=verificacioncontrasena(contrasena);
				}
				
				printf("\n-CONTRASEÑA CORRECTA-\n\n");
				
				registracionconfirmada(veterionarioasistente, usuario, contrasena);
				
				printf("\n\n>>>USUARIO REGISTRADO CORRECTAMENTE<<<\n");
				
				printf("\n>");
				system("pause");
			break;
		
			
			case 2:
				system("cls");
				
				veterionarioasistente=1;
				
				printf("REGISTRAR USUARIO ASISTENTE\n\n");
				
				printf("-NOMBRE DE USUARIO\n\n");
								
				printf("Condiciones para nombre de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
				printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
				printf("> Ser único para cada usuario registrado.\n");
				printf("> Comenzar con una letra minúscula.\n");
				printf("> Tener al menos 2 letras mayúsculas.\n");
				printf("> Tener como máximo 3 dígitos.\n\n");
				
				printf("Ingrese nombre de usuario: ");
				_flushall();
				gets(usuario);
				
				filtronombre=verificacionnombre(veterionarioasistente, usuario);
				
				while(filtronombre==false)
				{
					printf("\n----------\n\n");
					
					printf("El nombre de usuario ingresado es invalido o ya fue registrado.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
					printf("Condiciones para nombre de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 10 caracteres.\n");
					printf("- Podran ser letras, números y/o simbolos del conjunto {+,-,/,*,?,¿,!,¡}\n\n");
					printf("> Ser único para cada usuario registrado.\n");
					printf("> Comenzar con una letra minúscula.\n");
					printf("> Tener al menos 2 letras mayúsculas.\n");
					printf("> Tener como máximo 3 dígitos.\n\n");
					
					printf("Ingrese nombre de usuario: ");
					_flushall();
					gets(usuario);
					
					filtronombre=verificacionnombre(veterionarioasistente, usuario);
				}
				
				printf("\n-NOMBRE CORRECTO-\n");
				
				printf("\n----------\n\n");
				
				printf("-CONTRASEÑA DE USUARIO\n\n");
				
				printf("Condiciones para contraseña de usuario\n");
				
				printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
				printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
				printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
				printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
				printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
				
				printf("Ingrese contraseña de usuario: ");
				_flushall();
				gets(contrasena);
				
				filtrocontrasena=verificacioncontrasena(contrasena);
				
				while(filtrocontrasena==false)
				{
					printf("\n----------\n\n");
					
					printf("La contraseña del usuario ingresada es invalida.\n");
					printf("Por favor, vuelva a intentarlo.\n");
					
					printf("\n----------\n\n");
					
						printf("Condiciones para contraseña de usuario\n");
				
					printf("- Cantidad mínima 6 caracteres. Cantidad máxima 32 caracteres.\n");
					printf("- Debe contener al menos una mayúscula, una minúscula y un número.\n");
					printf("- No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos.\n");
					printf("- No debe tener más de 3 caracteres numéricos consecutivos\n");
					printf("- No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n\n");
					
					printf("Ingrese contraseña de usuario: ");
					_flushall();
					gets(contrasena);
					
					filtrocontrasena=verificacioncontrasena(contrasena);
				}
				
				printf("\n-CONTRASEÑA CORRECTA-\n\n");
				
				registracionconfirmada(veterionarioasistente, usuario, contrasena);
				
				printf("\n\n>>>USUARIO REGISTRADO CORRECTAMENTE<<<\n");
				
				printf("\n>");
				system("pause");
			break;
			
			case 3:
				system("cls");
				
				printf("ATENCIONES POR VETERINARIOS\n\n");
				
				atencionporveterinarios();
				
				printf(">");
				system("pause");
			break;
			
			case 4:
				system("cls");
				
				printf("RANKING DE VETERINARIOS POR ATENCIONES\n\n");
				
				ranking();
				
				printf("\n>");
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

