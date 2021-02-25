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
	setlocale(LC_ALL,"spanish");
	
	int opcionmenu, intentarnuevamente;
	
	bool usuarioconfirmado, iniciado=false;
	
	do{
		system("cls");
		
		printf("M�dulo del Asistente\n");
		printf("==============================\n");
		
		printf("1.- Iniciar sesi�n\n");
		printf("2.- Registrar Mascota\n");
		printf("3.- Registrar turno\n");
		printf("4.- Listado de Atenciones por Veterinario y Fecha\n\n");
		
		printf("5.- Cerrar la aplicaci�n\n\n");
		
		printf("Ingrese una opci�n: ");
		scanf("%d", &opcionmenu);
		
		switch(opcionmenu)
		{
			case 1:
				system("cls");
				
				printf("-INICIO DE SESI�N-\n\n");
				
				usuarioconfirmado=iniciosesion();
				
				if(usuarioconfirmado==true)
				{
					printf("\n>Se ha iniciado sesi�n.");
					
					iniciado=true;
				}
				
				while(usuarioconfirmado==false)
				{
					printf("\nEl usuario o la contrase�a ingresada son incorrectas.");
					
					printf("\n\n----------\n\n");
					
					do
					{
						printf("�Quiere intentarlo nuevamente?");
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
								printf("\nLa opci�n ingresada es inexistente. Intentelo nuevamente.");
							break;
						}
						
						printf("\n\n----------\n\n");												
						
					}while(intentarnuevamente!=1 && intentarnuevamente!=2);//pide ingresar el usuario y la contrase�a de nuevo
					
					if(intentarnuevamente==1)
					{
						usuarioconfirmado=iniciosesion();
					}
					
					if(usuarioconfirmado==true)
					{
						printf("\n>Se ha iniciado sesi�n.");
						
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
					
					printf("\nLa mascota se ha registrado con �xito.\n");
				}
				else
				{
					printf("A�n no se ha iniciado sesi�n.\n");
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
					
					printf("\nEl turno se ha registrado con �xito.\n");
				}
				else
				{
					printf("A�n no se ha iniciado sesi�n.\n");
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
					printf("A�n no se ha iniciado sesi�n.\n");
				}
				
				printf("\n\n>");
				system("pause");
			break;
			
			case 5:
				printf("\nUd. ha salido de la aplicaci�n.\n\n>");
				
				system("pause");
			break;
			
			default:
				printf("\nUd. no ha seleccionado una opci�n existente.\n\n>");
				
				system("pause");
				
			break;
		}
		
	}while(opcionmenu!=5);
}

bool iniciosesion()
{
	FILE *arch;
	
	usuarios comparacion;
	
	bool confirmacion=false;
	
	char usuario[15], contrasena[35];	
		
	arch=fopen("Usuarios.dat", "rb");
	
	if(arch==NULL)
	{
		printf("No existe ning�n usuario registrado hasta el momento.");
		
		confirmacion=false;
	}
	else
	{
		printf("Usuario: ");
		_flushall();
		
		gets(usuario);
		
		printf("Contrase�a: ");
		_flushall();
		
		gets(contrasena);
		
		fread(&comparacion, sizeof(usuarios), 1, arch);//revisar 
	
		while(!feof(arch))
		{
			if(strcmp(usuario, comparacion.Usuario)==0)//revisar que hace esto
			{
				if(strcmp(contrasena, comparacion.Contrasena)==0)
				{
					confirmacion=true;
					
					fseek(arch, 0, SEEK_END); 
				}
			}
			
			fread(&comparacion, sizeof(usuarios), 1, arch);
		}
	}
	
	return confirmacion;
}

void registromascota()
{
	FILE *arch;
	
	mascota registro;
	
	printf("Nombre de la mascota: ");
	_flushall();
	
	gets(registro.ApeNom);
	
	printf("\nDomicilio: ");
	_flushall();
	
	gets(registro.Domicilio);
	
	printf("\nFecha de nacimiento: ");
	printf("\nDia: ");
	scanf("%d", &registro.fechanacimiento.dd);	
	printf("Mes: ");
	scanf("%d", &registro.fechanacimiento.mm);
	printf("A�o: ");
	scanf("%d", &registro.fechanacimiento.aa);
	
	printf("\nLocalidad: ");
	_flushall();
	
	gets(registro.Localidad);
	
	printf("\nPeso: ");
	scanf("%f", &registro.Peso);
	
	printf("\nN�mero telefonico del due�o: ");
	_flushall();
	
	gets(registro.Telefono);
	
	arch=fopen("Mascotas.dat", "ab+");//crea y abre el archivo 
	
	fwrite(&registro, sizeof(mascota), 1, arch);//revisar que hace fwrite
	
	fclose(arch);
}
void registroturno()
{
	FILE *arch;
	
	int matricula, dni;
	
	bool matriculaencontrada=false, dniencontrado=false;
	
	usuarios aux;
	veterinario aux2;
	mascota aux3;
	
	turnos registro;
	
	printf("Matricula de veterinario que va a atender a la mascota: ");
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
	
	fclose(arch);
	
	while(matriculaencontrada==false)
	{
		printf("\n>La matricula ingresada no pertenece a ning�n veterinario. Intentelo nuevamente.\n\n");
		
		printf("Matricula de veterinario que va a atender a la mascota: ");
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
		
		fclose(arch);
	}
	
	registro.matriculaveterinario=matricula;
	
	printf("\nFecha de la consulta: ");
	printf("\nDia: ");
	scanf("%d", &registro.fechaturno.dd);	
	printf("Mes: ");
	scanf("%d", &registro.fechaturno.mm);
	printf("A�o: ");
	scanf("%d", &registro.fechaturno.aa);
	
	printf("\nDNI del due�o: ");
	scanf("%d", &dni);
	
	arch=fopen("Mascotas.dat", "rb");
	
	fread(&aux3, sizeof(mascota), 1, arch);//revisar que hace
	
	while(!feof(arch))
	{
		if(dni==aux3.DNI_Dueno)
		{
			dniencontrado=true;
		}
		
		fread(&aux3, sizeof(mascota), 1, arch);
	}
	
	fclose(arch);
	
	while(dniencontrado==false)
	{
		printf("\n>EL DNI no pertenece a ning�n due�o registrado. Intentelo nuevamente.\n\n");
		
		printf("DNI del due�o: ");
		scanf("%d", &dni);
		
		arch=fopen("Mascotas.dat", "rb");
		
		fread(&aux3, sizeof(mascota), 1, arch);
		
		while(!feof(arch))
		{
			if(dni==aux3.DNI_Dueno)
			{
				dniencontrado=true;
			}
			
			fread(&aux3, sizeof(mascota), 1, arch);
		}
		
		fclose(arch);
	}
	
	registro.DNI_Dueno=dni;
	
	registro.detalle[0]='-';
	
	registro.borrado=false;
	
	arch=fopen("Turnos.dat", "ab+");
	
	fwrite(&registro, sizeof(turnos), 1, arch);
	
	fclose(arch);
}

void listadoturnos()
{
	FILE *arch, *arch2;
	
	turnos registro;
	mascota aux;
	
	int i, dni;
	
	char mascotas[60];
	
	arch=fopen("Turnos.dat", "rb");
	arch2=fopen("Mascotas.dat", "rb");
	
	if(arch==NULL)
	{
		printf("Todav�a no se han registrado turnos.\n");
	}
	else
	{	
		printf("%*s|%*s|%*s\n", -14, "FECHA", -12, "MATRICULA", -30, "MASCOTA");//busca la fecha del turno la matricula del veterinario y la mascota
	
		for(i=0;i<50;i++)
		{
			printf("=");
		}
		
		printf("\n");
		
		fread(&registro, sizeof(turnos), 1, arch);

		while(!feof(arch))
		{
			dni=registro.DNI_Dueno;
			
			fread(&aux, sizeof(mascota), 1, arch2);
			
			while(!feof(arch2))
			{	
				if(dni==aux.DNI_Dueno)
				{
					strcpy(mascotas, aux.ApeNom);
				}
				
				fread(&aux, sizeof(mascota), 1, arch2);
			}
			
			fseek(arch2, 0, SEEK_SET);
			
			if(registro.borrado==false)
			{
				printf("%-0.2d/%-0.2d/%*d|%*d|%*s\n", registro.fechaturno.dd, registro.fechaturno.mm, -8, registro.fechaturno.aa, -12, registro.matriculaveterinario, -30, mascotas);//busca dentro del registro
			}
			
			fread(&registro, sizeof(turnos), 1, arch);
		}
		
		fclose(arch);
		
		fclose(arch2);
	}
	
}
