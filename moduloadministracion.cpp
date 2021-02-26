/*
                                            UTN-FRT     AyED     Comision:1k1  
                                            
										Nombre y apellido:   Alvarez Navarro Guadalupe	 Legajo	   50438   
										Nombre y apellido:   Babiera Walter Alberto  	 Legajo	   49923    */
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
	system("color 0C");
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

bool verificacionnombre(int vou, char nombre[15])
{
	int i, tamano, contadormayusculas=0, contadordigitos=0;
	
	bool controldigitos, filtro, verificacion;
	
	usuarios aux;
	
	tamano=strlen(nombre);
	
	
	if(tamano<6 || tamano>10)
	{
		verificacion=false;
		
		return verificacion;
	}
		
	for(i=0;i<tamano;i++)
	{
		controldigitos=false;
		
		if(nombre[i]==33 || nombre[i]==42 || nombre[i]==43 || nombre[i]==45 || nombre[i]==47 || nombre[i]==63 || nombre[i]==168 || nombre[i]==173)
		{
			controldigitos=true;
			
			if(i!=0)
			{
				contadordigitos++;
			}
		}
		else
		{
			if(nombre[i]<=57 && nombre[i]>=48)
			{
				controldigitos=true;
				
				if(i!=0)
				{
					contadordigitos++;
				}
			}
			else
			{
				if(nombre[i]<=90 && nombre[i]>=65)
				{
					controldigitos=true;
					
					if(i!=0)
					{
						contadormayusculas++;
					}
				}
				else
				{
					if(nombre[i]<=122 && nombre[i]>=97)
					{
						controldigitos=true;
						
						if(i==0)
						{
							filtro=true;
						}
					}
				}
			}
		}
		
		if(controldigitos==false)
		{
			verificacion=false;
			
			return verificacion;
		}
	}
	
	if(filtro==true && contadormayusculas>=2 && contadordigitos<=3)
	{
		verificacion=true;
	}
	else
	{
		verificacion=false;
		
		return verificacion;
	}
	
	FILE *arch;
	
	if(vou==0)
	{
		arch=fopen("Veterinarios.dat", "rb");
	
		if(arch==NULL)
		{
			verificacion=true;
		}
		else
		{
			fread(&aux, sizeof(usuarios), 1, arch);
			
			while(!feof(arch))
			{
				if(strcmp(nombre, aux.Usuario)==0)
				{
					verificacion=false;
					
					return verificacion;
				}
				
				fread(&aux, sizeof(usuarios), 1, arch);
			}
		}
	}
	else
	{
		arch=fopen("Usuarios.dat", "rb");
	
		if(arch==NULL)
		{
			verificacion=true;
		}
		else
		{
			fread(&aux, sizeof(usuarios), 1, arch);
			
			while(!feof(arch))
			{
				if(strcmp(nombre, aux.Usuario)==0)
				{
					verificacion=false;
					
					return verificacion;
				}
				
				fread(&aux, sizeof(usuarios), 1, arch);
			}
		}
	}
	
	fclose(arch);
	
	return verificacion;
}


bool verificacioncontrasena(char contra[35])
{
	int i, tamano, contadormayusculas=0, contadorminusculas=0, contadornumeros=0, numdigito;
	
	bool controldigitos, filtro, verificacion;
	
	tamano=strlen(contra);
	

	
	if(tamano<6 || tamano>32)
	{
		verificacion=false;
		
		return verificacion;
	}
	
	for(i=0;i<tamano;i++)
	{	
		if(contra[i]==32 || contra[i]==33 || contra[i]==40 || contra[i]==44 || contra[i]==45 || contra[i]==46 || contra[i]==58 || contra[i]==59 || contra[i]==63 || contra[i]==91 || contra[i]==95 || contra[i]==168 || contra[i]==173)
		{
			verificacion=false;
			
			return verificacion;
		}
		else
		{
			if(contra[i]<=57 && contra[i]>=48)
			{
				contadornumeros++;
				
				numdigito=contra[i];
				
		
				
				if(contra[i+1]==numdigito+1)
				{
					if(contra[i+2]==numdigito+2)
					{
						verificacion=false;
						
						return verificacion;
					}
				}
			}
			else
			{
				if(contra[i]<=90 && contra[i]>=65)
				{
					contadormayusculas++;
					
					numdigito=contra[i];
					
					if(contra[i+1]==numdigito+1 || contra[i+1]==numdigito+33)
					{
						verificacion=false;
						
						return verificacion;
					}
				}
				else
				{
					if(contra[i]<=122 && contra[i]>=97)
					{	
						contadorminusculas++;
						
						numdigito=contra[i];
						
						if(contra[i+1]==numdigito+1 || contra[i+1]==numdigito-31)
						{
							verificacion=false;
							
							return verificacion;
						}
						
					}
				}
			}
		}
	}
	
	if(contadormayusculas>0 && contadorminusculas>0 && contadornumeros>0)
	{
		verificacion=true;
		
		return verificacion;
	}
	else
	{
		verificacion=false;
		
		return verificacion;
	}
}

void registracionconfirmada(int vou, char nombre[15], char contra[35])
{
	int tamano;
	
	char apenom[60];
	
	printf("\n----------\n\n");
	
	printf("-DATOS DE USUARIO\n\n");
	
	printf("Ingresar apellido y nombre: ");
	_flushall();
				
	gets(apenom);
	
	tamano=strlen(apenom);
	
	if(tamano==0)
	{
		printf("\n>El campo no puede permanecer vacio. Vuelva a intentarlo.\n\n");
		
		printf("Ingresar apellido y nombre: ");
		_flushall();
					
		gets(apenom);
		
		tamano=strlen(apenom);
	}
	
	FILE *arch;
	
	if(vou==0)
	{
		arch=fopen("Veterinarios.dat", "ab+");
	
		usuarios confirmado;
		veterinario datosconfirmado;
		
		strcpy(confirmado.Usuario, nombre);
		strcpy(confirmado.Contrasena, contra);
		strcpy(confirmado.ApeNom, apenom);
		
		fwrite(&confirmado, sizeof(usuarios), 1, arch);
		
		strcpy(datosconfirmado.ApeNom, apenom);
		
		printf("\nIngresar matricula del veterinario: ");
		scanf("%d", &datosconfirmado.Matricula);
		
		printf("\n Ingresar DNI del veterinario: ");
		scanf("%d", &datosconfirmado.DNI);
		
		printf("\nIngresar número telefonico del veterinario: ");
		_flushall();
		
		gets(datosconfirmado.Telefono);
		
		fwrite(&datosconfirmado, sizeof(veterinario), 1, arch);
	}
	else
	{
		arch=fopen("Usuarios.dat", "ab+");
	
		usuarios confirmado;
		
		strcpy(confirmado.Usuario, nombre);
		strcpy(confirmado.Contrasena, contra);
		strcpy(confirmado.ApeNom, apenom);
		
		fwrite(&confirmado, sizeof(usuarios), 1, arch);
	}
	
	
	fclose(arch);
}

void atencionporveterinarios()
{
	FILE *archturnos, *archmascotas;
	
	int mes;
	
	bool existe=false;
	
	turnos auxturnos;
	mascota auxmascotas;
	
	printf("Ingresar mes del que quiere conocer las atenciones: ");
	scanf("%d", &mes);
	
	archturnos=fopen("Turnos.dat", "rb");
	
	if(archturnos==NULL)
	{
		printf("Aun no se ha registrado ningún turno.\n");
	}
	else
	{
		fread(&auxturnos, sizeof(turnos), 1, archturnos);
	
		while(!feof(archturnos))
		{
			if(auxturnos.fechaturno.mm==mes && auxturnos.borrado==true)
			{
				printf("\n----------\n\n");
				
				printf("Fecha de atención: %-0.2d/%-0.2d/%d", auxturnos.fechaturno.dd, auxturnos.fechaturno.mm, auxturnos.fechaturno.aa);
								
				printf("\nDNI del dueño: %d", auxturnos.DNI_Dueno);
				
				printf("\nMatricula del veterinario que atendió: %d", auxturnos.matriculaveterinario);
				
				printf("\nDetalle de la consulta: %s", auxturnos.detalle);
				
				printf("\n\n");
				
				existe=true;
			}
			
			fread(&auxturnos, sizeof(turnos), 1, archturnos);
		}
		
		if(existe==false)
		{
			printf("\n>No se ha realizado ningún turno en el mes seleccionado.\n\n");
		}
	}	
}

void ranking()
{
	FILE *archveterinario, *archturnos;
	
	int mes, matricula, cont, matriculamayor, contmayor=0;
	
	usuarios auxusuarios;
	veterinario auxveterinario;
	turnos auxturnos;
	
	archveterinario=fopen("Veterinarios.dat", "rb");
	
	if(archveterinario==NULL)
	{
		printf("Aún no se han registrado veterinarios.\n");
	}
	else
	{
		archturnos=fopen("Turnos.dat", "rb");
	
		if(archturnos==NULL)
		{
			printf("Aún no se han registrado turnos.\n");
		}
		else
		{
			printf("Ingresar mes del que quiere conocer el ranking: ");
			scanf("%d", &mes);
			
			printf("\n\n");
			
			fread(&auxusuarios, sizeof(usuarios), 1, archveterinario);
			while(!feof(archveterinario))
			{
				cont=0;
				
				fread(&auxveterinario, sizeof(veterinario), 1, archveterinario);
				
				matricula=auxveterinario.Matricula;
				
				fread(&auxturnos, sizeof(turnos), 1, archturnos);
				
				while(!feof(archturnos))
				{
					if(matricula==auxturnos.matriculaveterinario)
					{
						if(auxturnos.borrado==true && mes==auxturnos.fechaturno.mm)
						{
							cont++;
						}
					}
					
					fread(&auxturnos, sizeof(turnos), 1, archturnos);
				}
				
				fseek(archturnos, 0, SEEK_SET); 
				
				printf("Matricula: %d", matricula);
				printf("\nCantidad de atenciones: %d", cont);
				
				printf("\n\n----------\n\n");
				
				if(cont>contmayor)
				{
					contmayor=cont;
					matriculamayor=matricula;
				}
				
				fread(&auxusuarios, sizeof(usuarios), 1, archveterinario);
			}
		}
		
		if(contmayor==0)
		{
			printf("Ningún veterinario a realizado atenciones en este periodo.\n");	
		}
		else
		{
			printf("Matricula de veterinario ganador del ranking: %d\n", matriculamayor);
		}
	}
}
