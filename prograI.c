
/*   Proyecto Final
1. Realizar un sistema de venta de inmuebles en lenguaje C que maneje arreglos de 
estructuras.
2. Se manejará una estructura con los datos de los inmuebles, por ejemplo 
ubicación, metros cuadrados de terreno, metros cuadrados de construcción, 
tipo de construcción (casa, condominio, departamento, etc.), precio, tipo de 
crédito, identificador del vendedor, estado (vendida o en venta).
3. Se manejará una estructura de datos de los vendedores, por ejemplo un 
identificador, nombre, domicilio, fecha de contrato, teléfonos de ubicación.
4. Las opciones que se tendrán son: Alta, baja, venta, consulta, y 
modificación de inmueble; alta, baja, modificación y consulta de vendedor.
5. Al dar de alta un inmueble, se deberá dar el identificador del vendedor 
encargado de la venta del mismo, el cual se debe verificar que existe en el sistema.
6. Guardar en un archivo los datos de inmueble y poderlos recuperar.
7. Guardar en un archivo (distinto) los vendedores dados de alta.
8. Si requiere de datos adicionales, que considere necesarios dentro del sistema 
puede agregarlos.
9. Se calificará: que cumpla con los puntos especificados, iniciativa para la 
programación y creatividad.
10. Se entrega: Código fuente, programa ejecutable, manual de usuario (como 
usar el sistema, mediante ejemplos de pantallas, explicado a los usuarios que no 
necesariamente tienen conocimiento de computación) y manual técnico (como 
se realizó el programa, algoritmos, explicación de las estructuras 
y funciones principales utilizadas). 
11. Se entrega la documentación en un sobre, los códigos de manera 
digital, todo el equipo presente para su defensa.  */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024
struct inmu{
	char ubicacion[32];
	int metrosterr;
	int metroscons;
	char tipo[16];
	int precio;
	char tipocred[32];
	int estadoventa;
	int ID_vendedor;
	int selector;
};
struct vend{
	int id;
	char nombre[64];
	char domicilio[64];
	int fecha_contrato[3];
	int telefono1;
	int telefono2;
	int selector;
};
int conversor(int tama){
	int i;
	char buffer[7];
	fflush(stdin);
	fgets (buffer, tama, stdin);
	i = atoi (buffer);
	fflush(stdin);
	return i;
}
void asignacion(struct vend *vendedores,struct inmu *inmuebles){
	int x,i,j=0,sumaven=0, sumainmu=0;
	for(x=0;x<MAX;x++){
		sumaven=sumaven+vendedores[x].selector;
		sumainmu=sumainmu+inmuebles[x].selector;
	}
	
	for (i=0;i<MAX;i++){
		if(inmuebles[i].selector==1){
			if(vendedores[j].selector==1){
				inmuebles[i].ID_vendedor=vendedores[j].id;
				j++;
				sumaven--;
				sumainmu--;
				if ((sumaven==0)&&(sumainmu>=sumaven))
					j=0;
			}
		}
		
	}
}
int estado_venta(){
	int estado;
	do{
		printf("Vendida=0 / Disponible=1\n");
		estado=conversor(2);
	}while((estado<0)||(estado>1));
	return estado;
}
void modifi_inmuebles(struct inmu *inmuebles){
	int i=0;
	char nombre[30];
	printf("\nIngrese direccion del inmueble a buscar: ");
	fflush(stdin);
	gets(nombre);
	while (i<MAX && strcmp(inmuebles[i].ubicacion,nombre)!=0)
		i++;
	if (i==MAX)
		printf ("\nDato no encontrado");
	else{
		if (inmuebles[i].selector==1)
		{
			printf ("\nUbicación: %s",inmuebles[i].ubicacion);
			printf ("\nMetros cuadrados: %i",inmuebles[i].metrosterr);
			printf ("\nMetros de construccion: %i",inmuebles[i].metroscons);
			printf ("\nTipo: %s",inmuebles[i].tipo);
			printf ("\nPrecio: %i",inmuebles[i].precio);
			printf ("\nCredito disponible: %s",inmuebles[i].tipocred);
			printf ("\nEstado de Venta: %i",inmuebles[i].estadoventa);
			printf ("\nVendedor asignado: %i",inmuebles[i].ID_vendedor);
			
			printf("Ingrese la direccion de ubicacion del inmueble\n ");
			gets(inmuebles[i].ubicacion);		
			do{
				printf("\nIngrese el tamaño en metros cuadrados del terreno\n ");
				inmuebles[i].metrosterr=conversor(6); }while(inmuebles[i].metrosterr<=0);		
			do{
				printf("\nIngrese el tamaño en metros cuadrados de construccion (Si no la hay, ingresar cero)\n ");
				inmuebles[i].metroscons=conversor(6); }while(inmuebles[i].metroscons<=-1);		
			printf("\nDescriba el tipo de inmueble\n ");
			gets(inmuebles[i].tipo);
			do{
				printf("\nIntroduzca el precio del inmueble\n ");
				inmuebles[i].precio=conversor(10);	}while(inmuebles[i].precio<=0);
			printf("\nIngrese el tipo de credito para la venta\n ");
			gets(inmuebles[i].tipocred);
			printf("\nEstado de venta\n");
			inmuebles[i].estadoventa=estado_venta();
		}
		else
			printf("dato no encontrado");
	}
}
void modifi_vende(struct vend *vendedores){
	int i=0;
	char nombre[30];
	printf("\nIngrese el nombre a buscar: ");
	fflush(stdin);
	gets(nombre);
	while (i<MAX && strcmp(vendedores[i].nombre,nombre)!=0)
		i++;
	if (i==MAX)
		printf ("\nVendedor no encontrado");
	else
		if (vendedores[i].selector==1)
		{
			printf ("\nID: %d",vendedores[i].id);
			printf ("\nNombre: %s",vendedores[i].nombre);
			printf ("\nDomicilio: %s",vendedores[i].domicilio);
			printf ("\nfecha contrato: %i",vendedores[i].fecha_contrato[0]);
			printf ("/ %i",vendedores[i].fecha_contrato[1]);
			printf ("/ %i",vendedores[i].fecha_contrato[2]);
			printf ("\nTelefono 1: %i",vendedores[i].telefono1);
			printf ("\nTelefono 2: %i",vendedores[i].telefono2);
			{
				do{ 
					
					printf("\nIngrese el nuevo ID del vendedor: ");
					vendedores[i].id=conversor(7);}
				while( vendedores[i].id<=0);
				printf("\nIngrese nombre de nuevo vendedor: ");
				gets(vendedores[i].nombre);
				printf("\nIngrese domicilo de nuevo vendedor: ");
				gets(vendedores[i].domicilio);
				printf("\nIngresará la fecha de expiracion del contrato por día, mes, año:");
				do{printf("\nDia: ");
				vendedores[i].fecha_contrato[0]=conversor(3);
				}while((vendedores[i].fecha_contrato[0]<1)||(vendedores[i].fecha_contrato[0]>31));
				do{printf("\nMes: ");
				vendedores[i].fecha_contrato[1]=conversor(3);
				}while((vendedores[i].fecha_contrato[1]<1)||(vendedores[i].fecha_contrato[1]>12));
				do{printf("\nAnio: ");
				vendedores[i].fecha_contrato[2]=conversor(5);
				}while(vendedores[i].fecha_contrato[2]<=2012);
				printf("Ingrese teléfono 1");
				vendedores[i].telefono1=conversor(11);
				printf("Ingrese teléfono 1");
				vendedores[i].telefono2=conversor(11);}
		}
		else
			printf ("\nVendedor no encontrado");
}
void baja_inmuebles(struct inmu *inmuebles){
	int i=0;
	char nombre[30], op;
	
	printf("\nIngrese direccion del inmueble a buscar: ");
	fflush(stdin);
	gets(nombre);
	while (i<MAX && strcmp(inmuebles[i].ubicacion,nombre)!=0)
		i++;
	if (i==MAX)
		printf ("\nDato no encontrado");
	else
		if (inmuebles[i].selector==1)
		{
			printf ("\nUbicación: %s",inmuebles[i].ubicacion);
			printf ("\nMetros cuadrados: %i",inmuebles[i].metrosterr);
			printf ("\nTipo: %s",inmuebles[i].tipo);
			printf ("\nPrecio: %i",inmuebles[i].precio);
			printf ("\nconfirmar baja (s/n)");
			op = getchar();
			if (op=='s' || op=='S')
			{
				printf ("\nDando de baja...");
				inmuebles[i].selector=0;
			}
			getchar();
		}
		else
			printf ("\nDato no encontrado");
}
void baja_vendedores(struct vend *vendedores){
	int i=0;
	char nombre[30], op;
	
	printf("\nIngrese nombre del vendedor buscado: ");
	fflush(stdin);
	gets(nombre);
	while (i<MAX && strcmp(vendedores[i].nombre,nombre)!=0)
		i++;
	if (i==MAX)
		printf ("\nDato no encontrado");
	else
		if (vendedores[i].selector==1)
		{
			printf ("\nID: %d",vendedores[i].id);
			printf ("\nNombre: %s",vendedores[i].nombre);
			printf ("\nDomicilio: %s",vendedores[i].domicilio);
			printf ("\nfecha contrato: %i",vendedores[i].fecha_contrato[0]);
			printf ("/ %i",vendedores[i].fecha_contrato[1]);
			printf ("/ %i",vendedores[i].fecha_contrato[2]);
			printf ("\nconfirmar baja (s/n)");
			op = getchar();
			if (op=='s' || op=='S')
			{
				printf ("\nDando de baja...");
				vendedores[i].selector=0;
			}
			getchar();
		}
		else
			printf ("\nDato no encontrado");
}
void buscar_vende(struct vend *vendedores){
	int i=0;
	char nombre[30];
	printf("\nIngrese el nombre a buscar: ");
	fflush(stdin);
	gets(nombre);
	while (i<MAX && strcmp(vendedores[i].nombre,nombre)!=0)
		i++;
	if (i==MAX)
		printf ("\nVendedor no encontrado");
	else
		if (vendedores[i].selector==1)
		{
			printf ("\nID: %d",vendedores[i].id);
			printf ("\nNombre: %s",vendedores[i].nombre);
			printf ("\nDomicilio: %s",vendedores[i].domicilio);
			printf ("\nfecha contrato: %i",vendedores[i].fecha_contrato[0]);
			printf ("/ %i",vendedores[i].fecha_contrato[1]);
			printf ("/ %i",vendedores[i].fecha_contrato[2]);
			printf ("\nTelefono 1: %i",vendedores[i].telefono1);
			printf ("\nTelefono 2: %i",vendedores[i].telefono2);
		}
		else
			printf ("\nVendedor no encontrado");
}
void buscar_inmu(struct inmu *inmuebles){
	int i=0;
	char nombre[30];
	
	printf("\nIngrese direccion del inmueble a buscar: ");
	fflush(stdin);
	gets(nombre);
	while (i<MAX && strcmp(inmuebles[i].ubicacion,nombre)!=0)
		i++;
	if (i==MAX)
		printf ("\nDato no encontrado");
	else
		if (inmuebles[i].selector==1)
		{
			printf ("\nUbicación: %s",inmuebles[i].ubicacion);
			printf ("\nMetros cuadrados: %i",inmuebles[i].metrosterr);
			printf ("\nMetros de construccion: %i",inmuebles[i].metroscons);
			printf ("\nTipo: %s",inmuebles[i].tipo);
			printf ("\nPrecio: %i",inmuebles[i].precio);
			printf ("\nCredito disponible: %s",inmuebles[i].tipocred);
			printf ("\nEstado de Venta: %i",inmuebles[i].estadoventa);
			printf ("\nVendedor asignado: %i",inmuebles[i].ID_vendedor);
		}
		else
			printf ("\nDato no encontrado");
}
void alta_inmuebles(struct inmu *inmuebles){
	int i=0;
	while (i<MAX && inmuebles[i].selector!=0)
		i++;
	if (i<MAX)
	{
		inmuebles[i].selector=1;
		printf("Ingrese la direccion de ubicacion del inmueble\n ");
		fflush(stdin);
		gets(inmuebles[i].ubicacion);
		
		do{
			printf("\nIngrese el tamaño en metros cuadrados del terreno\n ");
			inmuebles[i].metrosterr=conversor(6); }while(inmuebles[i].metrosterr<=0);
		
		do{
			printf("\nIngrese el tamaño en metros cuadrados de construccion (Si no la hay, ingresar cero)\n ");
			inmuebles[i].metroscons=conversor(6); }while(inmuebles[i].metroscons<=-1);
		
		printf("\nDescriba el tipo de inmueble\n ");
		gets(inmuebles[i].tipo);
		do{
			printf("\nIntroduzca el precio del inmueble\n ");
			inmuebles[i].precio=conversor(10);	}while(inmuebles[i].precio<=0);
		
		printf("\nIngrese el tipo de credito para la venta\n ");
		gets(inmuebles[i].tipocred);
		printf("\nEstado de venta\n");
		inmuebles[i].estadoventa=estado_venta();
	}
	else
		printf ("\nEspacio insuficiente");
}
void alta_vendedores(struct vend *vendedores){
	int i=0;
	while (i<MAX && vendedores[i].selector!=0)
		i++;
	if (i<MAX){
		do{ vendedores[i].selector=1;
		printf("\nIngrese el nuevo ID del vendedor: ");
		vendedores[i].id=conversor(7);}
		while( vendedores[i].id<=0);
		printf("\nIngrese nombre de nuevo vendedor: ");
		gets(vendedores[i].nombre);
		printf("\nIngrese domicilo de nuevo vendedor: ");
		gets(vendedores[i].domicilio);
		printf("\nIngresará la fecha de expiracion del contrato por día, mes, año:");
		do{printf("\nDia: ");
		vendedores[i].fecha_contrato[0]=conversor(3);
		}while((vendedores[i].fecha_contrato[0]<1)||(vendedores[i].fecha_contrato[0]>31));
		do{printf("\nMes: ");
		vendedores[i].fecha_contrato[1]=conversor(3);
		}while((vendedores[i].fecha_contrato[1]<1)||(vendedores[i].fecha_contrato[1]>12));
		do{printf("\nAnio: ");
		vendedores[i].fecha_contrato[2]=conversor(5);
		}while(vendedores[i].fecha_contrato[2]<=2012);
		printf("Ingrese teléfono 1");
		vendedores[i].telefono1=conversor(11);
		printf("Ingrese teléfono 1");
		vendedores[i].telefono2=conversor(11);}
	else
		printf("\nEspacio insuficiente");
}
void consulta_vende(struct vend *vendedores){
	int x;
	printf("\nVendedores Registrados:");
	for (x=0; x<MAX; x++)
		if (vendedores[x].selector!=0)
		{
			printf ("\n\nID: %d",vendedores[x].id);
			printf ("\nNombre: %s",vendedores[x].nombre);
			printf ("\nDomicilio: %s",vendedores[x].domicilio);
			printf ("\nfecha contrato: %i",vendedores[x].fecha_contrato[0]);
			printf ("/ %i",vendedores[x].fecha_contrato[1]);
			printf ("/ %i",vendedores[x].fecha_contrato[2]);
			printf ("\nTelefono 1: %i",vendedores[x].telefono1);
			printf ("\nTelefono 2: %i",vendedores[x].telefono2);
		}
}
void consulta_inmu(struct inmu *inmuebles){
	int x;
	printf("\nInmuebles:");
	for (x=0; x<MAX; x++)
		if (inmuebles[x].selector!=0){
			printf ("\n\nUbicación: %s",inmuebles[x].ubicacion);
			printf ("\nMetros cuadrados: %i",inmuebles[x].metrosterr);
			printf ("\nMetros de construccion: %i",inmuebles[x].metroscons);
			printf ("\nTipo: %s",inmuebles[x].tipo);
			printf ("\nPrecio: %i",inmuebles[x].precio);
			printf ("\nCredito disponible: %s",inmuebles[x].tipocred);
			printf ("\nEstado de Venta: %i",inmuebles[x].estadoventa);
			printf ("\nVendedor asignado: %i",inmuebles[x].ID_vendedor);
		}
}
void menu(struct vend *vendedores,struct inmu *inmuebles){
	int bande=0;
	char opc;
	printf("\n   Menu de opciones\n");
	printf("\n1.- Inmuebles\n2.- Vendedores\n3.- Reasignar terrenos\n4.- Salir\n");
	do{
		printf("\n Opcion: ");
		fflush(stdin);
		opc=getchar();
		if(((int)opc==49)||((int)opc==50)||((int)opc==51)||((int)opc==52))
			bande++;
		else
			bande=0;
		fflush(stdin);}while (bande==0);
	switch(opc){
	case '1':{
		printf("\nMenu de inmuebles");
		printf("\n1. Altas");
		printf("\n2. Bajas");
		printf("\n3. Modificaciones");
		printf("\n4. Consulta");
		printf("\n5. Busqueda");
		printf("\n6. Regresar");
		do{
			printf("\n Opcion: ");
			fflush(stdin);
			opc=getchar();
			if(((int)opc==49)||((int)opc==50)||((int)opc==51)||((int)opc==52)||((int)opc==53)||((int)opc==54))
				bande++;
			else
				bande=0;
}while (bande==0);
		switch (opc){
		case '1': {alta_inmuebles(inmuebles);
		menu(vendedores,inmuebles);
		break;
		}
		case '2':{baja_inmuebles(inmuebles);
		menu(vendedores,inmuebles);
		break;
		}
		case '3':{ modifi_inmuebles(inmuebles);
		menu(vendedores,inmuebles);
		break;
		}
		case '4':{ consulta_inmu(inmuebles);
		menu(vendedores,inmuebles);
		break;
		}
		case '5':{ buscar_inmu(inmuebles);
		menu(vendedores,inmuebles);
		break;
		case '6':{menu(vendedores,inmuebles);break;}
		}
		
		}break;
	}
	case '2':{
		printf("\nMenu de vendedores");
		printf("\n1. Altas");
		printf("\n2. Bajas");
		printf("\n3. Modificaciones");
		printf("\n4. Consulta");
		printf("\n5. Busqueda");
		printf("\n6. Regresar");
		do{
			printf("\n Opcion: ");
			fflush(stdin);
			opc=getchar();
			if(((int)opc==49)||((int)opc==50)||((int)opc==51)||((int)opc==52)||((int)opc==53)||((int)opc==54))
				bande++;
			else
				bande=0;
}while (bande==0);
		switch (opc){
		case '1': {alta_vendedores(vendedores);
		menu(vendedores,inmuebles);
		break;
		}
		case '2':{baja_vendedores(vendedores)
			;menu(vendedores,inmuebles);
		break;
		}
		case '3':{modifi_vende(vendedores);
		menu(vendedores,inmuebles);
		break;
		}
		case '4':{consulta_vende(vendedores);
		menu(vendedores,inmuebles);
		break;
		}
		case '5':{buscar_vende(vendedores);
		menu(vendedores,inmuebles);
		break;
		}
		case '6':{menu(vendedores,inmuebles);
		break;}
		}
		break;
	}
	case '3':{
		asignacion(vendedores,inmuebles);
		menu(vendedores, inmuebles);
		break;
		}
	case '4':{
		printf("Terminando...");
		break;
	}
}
}
int main(){
	struct vend vendedores[MAX];
	struct inmu inmuebles[MAX];
	int i, j;
	FILE *terrenos;
	FILE *empleados;
	
	for (i=0; i<MAX; i++){
		vendedores[i].selector=0;
		inmuebles[i].selector=0;
	}
	if ((terrenos=fopen("terrenos.dat","r"))==NULL)
	{
		terrenos=fopen("terrenos.dat","w");
	}
	else
		{	
			for (j=0; j<MAX; j++)
				fread (&inmuebles[j],sizeof(struct inmu),1,terrenos);
			fclose(terrenos);
		} 
	
	if ((empleados=fopen("empleados.dat","r"))==NULL)
	{
		empleados=fopen("empleados.dat","w");
	}
	else
		{
			for (j=0; j<MAX; j++)
				fread (&vendedores[j],sizeof(struct vend),1,empleados);
			fclose(empleados);
		} 
	
	asignacion(vendedores,inmuebles);
	menu(vendedores, inmuebles);
	printf("Programa Finalizado");
	asignacion(vendedores,inmuebles);
	if ((terrenos=fopen("terrenos.dat","w"))!=NULL)
	{ 
		for (j=0; j<MAX; j++)
		{
			
			fwrite(&inmuebles[j],sizeof(struct inmu),1,terrenos);
		}
		
		fclose(terrenos);
	}
	else
		printf("\nError en archivo terrenos");
	if ((terrenos=fopen("empleados.dat","w"))!=NULL)
	{ 
		for (j=0; j<MAX; j++)
		{			
			fwrite(&vendedores[j],sizeof(struct vend),1,empleados);
		}
		fclose(empleados);
	}
	else
		printf("\nError en archivo empleados");
	fflush(stdin);
	getchar();
	return 0;
}
