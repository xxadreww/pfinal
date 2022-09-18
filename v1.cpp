/* -- VARIABLES ---

** PRODUCTOS **
descripcionpr = descripción del producto (nombre)
preciouni = precio del producto por unidad (float)
existepr = cantidad de existencia del producto por unidad (entero)
codigopr = codigo del producto (entero)
borrarpr = permite borrar el producto, 0= existe, 1= no existe
------------------------------

** PRODUCTOS EXTRA **
respuesta = respuesta de selección en el submenu de productos (entero)
-------------------------------

** EDITAR PRODUCTO **
codigo = codigo del producto para comparar (codigo==inve.codigopr) (1) (entero)
existe = 0 no existe producto actualmente, 1 existe el producto (la variable codigo determina si existe o no) (entero)
--------------------------------

** BORRAR PRODUCTO **
existeprbrr = 1 no existe el producto a borrar, 0 existe el producto a borrar (entero)
codigoprbrr = codigo del producto para comparar (codigoprbrr==inve.codigopr) (2) (entero)
opcionbrr = opción si desea o no borrar el producto (1. si, 2. no) (entero)
---------------------------------

** FACTURAS **
nomfact = nombre de la factura (cadena)
nomuser = nombre del usuario de la factura (cadena)
preciouni = precio por unidad de producto registrado en la factura (float)
totalfact = precio total de la factura ingresado luego de sumar los productos registrados en la factura (float)
cantidadfact = cantidad de productos comprado en la factura (float)
preciouni = ?
---------------------------------

** FACTURA (VOID) **
opfact = opcion de elegir dentro de la función factura (entero)
codprod = codigo de la factura para comparar (codigoprbrr==inve.codigopr) (3) (entero)
nomfactprinci = nombre de la factura para comparar (existe o no existe) (4) (entero)
---------------------------------

** REPORTE FACTURA **
existefact = existe o no existe la factura a buscar (nomfactprinci define si sí existe o no existe) (entero)
---------------------------------

** FACTURAS EXTRAS **
??
??
---------------------------------

*/





//Programa de venta de productos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

//login-registro
#define CADENA_CORTA  20
#define FILAS 5
#define COLUMNAS 10 //definimos variables globales

//productos
#define MAXIMA_CADENA 1000
#define MAXIMA_VENTA 1000
#define MAXIMO_PRODUCTO 100

struct Login // se crea la estructura del área de login
{
  char username[CADENA_CORTA];
  char clave[CADENA_CORTA];
};

// VARIABLES GLOBALES //
int menuPrincipal(); //variables locales con volcado
int subMenuPrincipal();
void registroUsuario();
void productosVenta();
int menuarchivo();
int menumovimientos();
int menuayuda();
void usuarios();
int edicionusuario();
void cdusuario();//cambio de usuario
void cdclave(); //cambio de clave
void takepassword(); 
void clientes();
void crearcliente();
void productos(); //funcion de productos
void factura();
void imprimirfactura();
void crearpr(); // crear producto
void reportepr(); // reporte de producto
void mostrarpr(); //muestra todos los productos guardados en el stock
void editarpr(); // editar un producto en existencia a traves de su código
void eliminarpr(); // eliminar producto del lote a traves de su código
void reportedefacturas();
int login();
void extra();
void extra2();

char letrann[10]="Letra \xA4";


// ESTRUCTURA DEL INVENTARIO DE PRODUCTOS
typedef struct {
	char descripcionpr[20];
	float preciouni;
	int codigopr, existepr; 
	int borrarpr; // en borrarpr es 0=existe 1=borrado
} inventario;
// FIN ESTRUCTURA DEL INVENTARIO DE PRODUCTOS

typedef struct {
	char nomfact[20], nomuser;
	float preciouni, totalfact;
	int cantidadfact, codigofact;
} facturas;

typedef struct {
	char ncliente[40];
	int  cdicliente;
} cliente;

typedef struct{
	int restainve;
	int restafact;
}restainventario;

restainventario resta;

enum // se declaran las variables principales
{
  ulogout,
  ulogueado,
  salir
};

int main(){
  int estadoUsuario=ulogout;
  while(estadoUsuario != salir){
    if(estadoUsuario==ulogout){// El usuario no está logueado, se devolverá al menu principal 
      estadoUsuario = menuPrincipal();
    }
    else{// El usuario se ha logueado, irá al sub menu principal
      estadoUsuario=subMenuPrincipal();
    }
  }
  return 0;
}

int menuPrincipal(){ //Se colocan las opciones principales a llevar del programa
  int opcion;
  system("cls");
  while (1){
    printf("\t***BIENVENIDO A NUESTRA TIENDA***\n---\nActualmente te encuentras en el apartado de Usuarios\n---\nDigita la opcion de tu preferencia:\n---\n1: Crear un nuevo usuario.\n2: Ingresar con un usuario ya existente.\n3: Salir del programa.\n");
	fflush(stdin);
    if (scanf("%d", &opcion)==1){
      switch (opcion){
      case 1:
        registroUsuario();
        break;
      case 2:
        if (login())
          return ulogueado;
        break;
      case 3:
        printf("Gracias por elegirnos\n");
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
} 

int subMenuPrincipal(){
  int opcion=0;
  while(1){//Mientras sea verdadero se colocarán las opciones del submenu luego de haber ingresado al programa
  	system("cls");
    printf("Ingresaste correctamente, a nuestra tienda:\n---\n");
    printf("1: Venta\n2: Archivo\n3: Movimientos\n4: Ayuda\n5: Salir\n---\nDigita la opcion de tu preferencia:\n");
    if (scanf("%d", &opcion)==1){
     fflush(stdin);
	 switch (opcion){
		 case 1:
			system("cls");
        	factura();
        	break;
		 case 2:
			system("cls");
        	menuarchivo();
        	break;
		 case 3:
			system("cls");
        	menumovimientos();
        	break;
	 	 case 4:
			system("cls");
      		menuayuda();
      		break;
		 case 5:
        	printf("Gracias por elegirnos\n");
        	return menuPrincipal();
        
		 default:
        	printf("Eleccion invalida, por favor ingrese un numero valido\n");
        	break;
			}
		}
	}
}

int menuarchivo(void){ // // Apartado de archivos del menu de opciones a elegir sobre usuarios/clientes/productos
	int opcion=0;
  while(1){
  	system("cls");
    printf("Actualmente te encuentras en el apartado de Archivos\n---\n1: Usuarios.\n2: Clientes.\n3: Productos.\n4: Editar el usuario.\n5: Salir.\n---\nDigita la opcion de tu preferencia: ");

    if (scanf("%d", &opcion)==1)
    {
      switch (opcion){
      case 1:
        usuarios();
        break;
      case 2:
        clientes();
        break;
      case 3:
        productos();
        break;
      case 4:
      	edicionusuario();
        break;
      case 5:
      	printf("Gracias por elegirnos\n");
        return salir;
      	break;        
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
}

int menumovimientos(){ // Apartado de movimientos del menu de opciones a elegir sobre facturas/reportes
	int opcion;
  while (1){
    printf("Actualmente te encuentras en el apartado de Movimientos\n---\n1: Reporte de facturas.\n2: Salir.\n---\nDigita la opcion de tu preferencia: ");

    if (scanf("%d", &opcion)==1){
      switch ( opcion){
      case 1:
        reportedefacturas();
        break;
      case 2:
        printf("Gracias por elegirnos\n");
        return salir;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;	
        return subMenuPrincipal();
      }
    }
  }
}

int menuayuda(){
	int opcion;
  while (1){
    printf("Submenu ayuda\n---\n1: Nombre del sistema.\n2: Informacion de los autores.\n3: A%co y semestre.\n4: Salir.\n---\nDigita la opcion de tu preferencia:", 164);
    if (scanf("%d", &opcion)==1){
      switch(opcion){
      case 1:
      	system("cls");
        printf("\n\t\tNOMBRE DEL SISTEMA \n\n\t\t*Technology Shop*\n\n");
        break;
      case 2:
      	system("cls");
        printf("\n\tNombre de los Creadores\n\n*Aldana Eliannis\tCI: 30453246\n*Martinez Fabiana\tCI: 30498516\n*Moya Enyer\t\tCI: 30498773\n*Pulido Alejandro\tCI: 30576458 \n*Isea Francisco\t\tCI: 30293487\n\n");
        break;
      case 3:
      	system("cls");
      	printf("\n\t\tA%co y Semestre cursado\n\n\t\tSEMESTRE II (2)\n\n\t\tA%co: 2022\n\n", 164,164);
      	break;
      case 4:
        return subMenuPrincipal();
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
			}
		} 
	 }
}

void usuarios(){
  FILE*log=fopen("login.dat", "r");
  struct Login l;
  system("cls");
  printf("\nLos usuarios registrados son:\n");
  while(!feof(log)){
  fread(&l, sizeof(l), 1, log);
  if(!feof(log)){
  printf("\n%s\n", l.username );
  }
  }
  printf("\n");
  system("pause");
  system("cls");
  getchar();
}

void clientes(){
	FILE*crearcliente=fopen("clientes.dat", "r");
  cliente c;
  system("cls");
  printf("\nLos clientes registrados son:\n");
  while(!feof(crearcliente)){
  fread(&c, sizeof(c), 1, crearcliente);
  if(!feof(crearcliente)){
  printf("\n%s %i\n", c.ncliente, c.cdicliente);
  }
  }
  printf("\n");
  system("pause");
  system("cls");
  getchar();
}

void crearcliente(){
	printf("\n");
	char fncliente[40];
	int cdicliente;
	cliente c;
	FILE*crearcliente;
	crearcliente=fopen("clientes.dat", "a+b");
  printf("\nDigita los datos del cliente: \n");
  printf("\nNombre del cliente: ");
    fflush(stdin);
	gets(c.ncliente);
   printf("\nNumero de cedula del cliente: ");
    fflush(stdin);
    scanf("%i", &c.cdicliente);
	fwrite(&c,sizeof(c),1,crearcliente);
	fclose(crearcliente);
	printf("\n");
}

int edicionusuario(){
	int opcion=0;
  while(1){
  	system("cls");
    printf("Actualmente te encuentras en el apartado de cambios y eliminacion\n---\n1: Editar nombre de usuario.\n2: Editar contrase%ca.\n3: Salir.\n---\nDigita la opcion de tu preferencia: ", 164);
    if (scanf("%d", &opcion)==1){
      switch (opcion){
      case 1:
        cdusuario();
        break;
      case 2:
        cdclave();
        break;
      case 3:
      	printf("Gracias por elegirnos\n");
        return salir;
      	break;        
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
}

void cdusuario(){
  system("cls");
    int num1, num2;
    srand(time(0)); 
number:
    num1 = rand();
    printf("\nEl numero al azar es %d\n", num1);
    printf("\nEscribe el numero de arriba:  ");
    scanf("%d", &num2);
    if (num1 == num2){
        struct Login l;
        char usu2[20];

        FILE *log = fopen("login.dat", "r");
        fread(&l, sizeof(l), 1, log);

        printf("\nIngresa un nuevo usuario:");
        scanf("%s",l.username);
    pas:
        printf("\nConfirma el nuevo usuario:");
        scanf("%s", usu2);
        if (strcmp(l.username, usu2)){
            printf("\n*******USUARIO INCORRECTO******\nIntentelo de nuevo.....\n");
            goto pas;
        }
        else{
            log = fopen("login.dat", "w");
            fwrite(&l, sizeof(l), 1, log);
            printf("\n*********CAMBIO DE USUARIO SATISFACTORIO*********");
            getch();
        }
        fclose(log);
    }
    else{
        printf("\nPor favor ingrese el numero correcto\n");
        goto number;
    }
}

void cdclave(){
  system("cls");

    int num1, num2;
    srand(time(0)); 

number:
    num1 = rand();
    printf("\nEl numero al azar es %d\n", num1);
    printf("Escribe el numero de arriba: ");
    scanf("%d", &num2);
    if (num1 == num2){
        struct Login l;
        char pass2[20];
        FILE *log = fopen("login.dat", "r");
        fread(&l, sizeof(l), 1, log);
        printf("Ingresa una nueva contrase%ca: ",164);
        takepassword(l.clave);
    pas:
        printf("\nConfirma la nueva contrase%ca: ",164);
        scanf("%s", pass2);
        if (strcmp(l.clave, pass2)){
            printf("*******CONTRASE%cA INCORRECTA******\nIntentelo de nuevo.....\n",164);
            goto pas;
        }
        else{
            log = fopen("login.dat", "w");
            fwrite(&l, sizeof(l), 1, log);
            printf("*********CAMBIO DE CONTRASE%cA SATISFACTORIO*********",164);
            getch();
        }
        fclose(log);
    }
    else{
        printf("Por favor ingrese el numero correcto\n");
        goto number;
    }
}

void takepassword(char pass[20]){
    int i=0;
    char ch;
    while (1){
        ch=getch();
        if (ch == 13){
            pass[i] = '\0';
            break;
        }
        else if (ch==8){
            if (i>0){
                i--;
                printf("\b \b");
            }
        }
        else if (ch==9||ch==32){
            continue;
        }
        else{
            pass[i++]=ch;
            printf("*");
        }
    }
}

// INICIO DEL APARTADO SUBMENU PARA LOS PRODUCTOS: AGREGAR/REPORTE/VER PRODUCTOS DISPONIBLES/MODIFICACION/ELIMINACION
void productos(){
	int respuesta;
		system("cls");
		printf("Submenu de Productos\n---\n1: Crear un nuevo producto.\n2. Reporte de un producto.\n3. Ver registro de productos en la Tienda.\n4. Editar un producto por su codigo.\n5. Eliminar un producto por su codigo.\n6. Salir.\n");
		fflush(stdin);
		scanf("%d", &respuesta);
		switch(respuesta){
			case 1:
				crearpr();
				break;
			case 2:
				reportepr();
				break;
			case 3:
				mostrarpr();
				break;
			case 4:
				editarpr();
				break;
			case 5:
				eliminarpr();
				break;
			case 6:
				subMenuPrincipal();
				break;
		while(respuesta<1||respuesta>6){
			printf ("Por favor ingresa una opcion valida\n");
			scanf("%d", &respuesta);
			
		}
	}
}
// FIN DEL APARTADO SUBMENU PARA LOS PRODUCTOS//


// INICIO DE LA FUNCIÓN DE CREAR PRODUCTO AL PROGRAMA //
void crearpr(){
	system("cls");
	char opcion, existepr, descripcionpr[41];
	float preciouni;
	int codigopr;
	inventario inve;
	FILE*crearproducto;
	  crearproducto=fopen("inventario.dat", "a+b");
  if(crearproducto==NULL)
  {
    printf("ARCHIVO NO ENCONTRADO\n");
    getch(); // login fallido
	}
	printf("Actualmente te encuentras en el apartado de Crear Producto\n---\n");
	printf("Ingresa el CODIGO del producto:\n");
	fflush(stdin);
	scanf("%i", &inve.codigopr);
	printf("Ingresa el NOMBRE del producto:\n");
	fflush(stdin);
	gets(inve.descripcionpr);
	printf("Ingresa la CANTIDAD de EXISTENCIA del producto:\n");
	fflush(stdin);
	scanf("%i", &inve.existepr);
	printf("Ingresa el PRECIO de unidad del producto:\n");
	fflush(stdin);
	scanf("%f", &inve.preciouni);
	inve.borrarpr=0;
	fwrite(&inve,sizeof(inve),1,crearproducto);
	fclose(crearproducto);
	printf("El producto se ha registrado satisfactoriamente\n");
	system("pause");
	system("cls");
	
	return productos();
}
// FIN DE LA FUNCIÓN DE CREAR PRODUCTO AL PROGRAMA //



// INICIO DE LA FUNCIÓN DE MOSTRAR PRODUCTOS EN EL LOTE //
void mostrarpr(){
	char descripcionpr[41], caracteres;
	inventario inve, invecodigopr, invedescripcionpr, inveexistepr, invepreciouni;
	int strcmp, codigopr, existepr;
	 facturas fact, factcantidadfact;
	float preciouni;
	system("cls");
	  FILE*crearproducto;
  crearproducto=fopen("inventario.dat", "r+b");
  if(crearproducto==NULL){
    printf("ARCHIVO NO ENCONTRADO\n");
    return productos(); 
}
    fread(&inve, sizeof(inve), 1, crearproducto);
  printf("Actualmente te encuentras en el apartado de los Productos Disponibles.\n---\n\t*** PRODUCTOS DISPONIBLES ***\n---\n");
  printf("\n\tCodigo\t|\tNombre\t\t|\tCantidad\t|\tPrecio\n\n");
  while(!feof(crearproducto)){
  	if(inve.borrarpr==0){
  		if(!feof(crearproducto)){
		printf("\n\t%i\t\t%s\t\t%d\t\t%0.2f\n", inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni);
	fflush(stdin);
			}
		}
	fread(&inve, sizeof(inve), 1, crearproducto);	
	}
	
	
 system("pause"); 
 fclose(crearproducto);
}
// FIN DE LA FUNCIÓN DE MOSTRAR PRODUCTOS EN EL LOTE //

void factura(){
	system("cls");
		FILE*factura;
    factura=fopen("factura.dat","a+b");
    	if (factura==NULL){
    	menumovimientos();
    }
    int opfact, codprod, cdicliente;
    char nomfactprinci, nomuser, fncliente, lncliente;
    inventario inve;
    facturas fact;
    cliente cli;
    
    char nomfact[21];
	float preciouni, totalfact;
	int cantidadfact, codigofact,auxresta=0;
    printf("Actualmente te encuentras en el apartado de Venta\n---\n");
    // Abro el archivo de inventario para modificar los productos disponibles
    	FILE*crearproducto;
    crearproducto=fopen("inventario.dat","r+b");
		if(crearproducto==NULL){
   		 printf("ARCHIVO NO ENCONTRADO\n");
   			 return productos(); 
				}
	mostrarpr();	//Llamo a la funcion para mostrar la cantidad de productos en el inventario
	printf("\nDigita el codigo del producto a comprar: ");
	scanf("%d", &codprod);	
	system("cls");
	fread(&inve,sizeof(inve),1,crearproducto);
	printf("\nCodigo\t|\tNombre\t|\tCantidad\t|\tPrecio\n\n");
		while(!feof(crearproducto)){	
     		if (codprod==inve.codigopr){		
		printf("%i\t \t%s\t \t%i\t \t%0.2f\n", inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni);
		printf("\nEste es el producto que deseas comprar?:\n1. Si.\n2. No.\n---\nDigita la opcion de tu preferencia: ");
			fflush(stdin);
        		scanf("%d", &opfact);
        	switch(opfact){
        		case 1:
        			if(inve.existepr>=1){
        crearcliente();
      	printf("\nDigita los datos del producto a comprar:\n\nNombre de usuario para registro: ");
      		fflush(stdin);
			scanf("%s", &fact.nomuser);
		printf("\nCodigo del producto: ");
        	fflush(stdin);
        	scanf("%i", &fact.codigofact);
        if(fact.codigofact!=inve.codigopr){
        	printf("Has introducido un dato incorrecto, vuelve a intentarlo.\n");
				system("pause");
					system("cls");
						break;
		}
    	printf("\nNombre del producto: ");
			fflush(stdin);
       		 fgets(fact.nomfact,20,stdin);
        printf("\nPrecio del producto por unidad: ");
       		fflush(stdin);
       			scanf("%f", &fact.preciouni);
        if(fact.preciouni!=inve.preciouni){
			printf("Haz introducido un dato incorrecto, vuelve a intentarlo.\n");
				system("pause");
					system("cls");
						break;
		}
        printf("nCantidad a comprar del producto: ");
        	scanf("%d", &fact.cantidadfact);
        int pos=ftell(crearproducto)-sizeof(inventario);
        fseek(crearproducto,pos,SEEK_SET);
        fwrite(&fact,sizeof(facturas),1,factura);
        if(fact.cantidadfact>inve.existepr){
        	printf("No hay suficientes productos en stock para dicha compra\n");
        		system("pause");
        	subMenuPrincipal();
		}
		printf("\nA%cadido al carrito\n",164);
		if (fact.cantidadfact!=0&&inve.borrarpr==0){
           	printf("\a\nPara confirmar que usted no es un bot resuelva la siguiente operacion\n");
           		auxresta=inve.existepr-fact.cantidadfact;
           	printf("%i - %i = %i\n",inve.existepr,fact.cantidadfact,auxresta);
           		fflush(stdin);
           			scanf("%i", &inve.existepr);
   			fwrite(&inve, sizeof(inventario),1,crearproducto);
           	    if(auxresta!=inve.existepr){
           	printf("\nCaptcha incorrecto\n");
        system("pause");
		break;	
			}
        fread(&inve,sizeof(inve),1,crearproducto);
        if(auxresta==inve.existepr){
        	printf("Compra exitosa\n\a");
        		printf("Para ver los cambios realizados reinicie el programa\n");
        	 extra2();
        break;
    }
		}
		case 2:
			fclose(crearproducto);
			fclose(factura);
			system("pause");
			system("cls");
			subMenuPrincipal();
				break;
		default:
			printf("Ingrese una opcion valida\n");
			scanf("%d", &opfact);
				break;
			
        }
		if(inve.existepr<=0){
			printf("No hay mas productos de este tipo disponibles.");
				system("pause");
					subMenuPrincipal();
					fclose(crearproducto);
					fclose(factura);
					}
		break;
    }
}
   	fread(&inve,sizeof(inve),1,crearproducto);	   	
}
		system("pause");
		fclose(crearproducto);
		fclose(factura);
		subMenuPrincipal();
}


void reportedefacturas(){//FUNCION REPORTAR FACTURA
    char nomfact[21], nomuser, nomfactprinci;
	float preciouni, totalfact;
	int cantidadfact, codigofact, existefact=0;
	facturas fact;
	inventario inve;
	system("cls");
	FILE*factura;
		factura=fopen("factura.dat", "r+b");
	if(factura==NULL){
    	printf("ARCHIVO NO ENCONTRADO\n");
    subMenuPrincipal(); 
	}
	FILE*crearproducto;
    crearproducto=fopen("inventario.dat","r+b");
		if(crearproducto==NULL){
   		 printf("ARCHIVO NO ENCONTRADO\n");
   			 subMenuPrincipal();
	}
	printf("Ingresa el nombre de usuario a buscar en la factura: \n");
	fflush(stdin);
	scanf("%s", &nomfactprinci);
	fread(&fact,sizeof(fact),1,factura);
  while(!feof(factura)){
   if(nomfactprinci==fact.nomuser){
	fact.totalfact=fact.preciouni*fact.cantidadfact;
	printf("Actualmente te encuentras en el apartado de la vista de facturas.\n---\n\t*** FACTURA ENCONTRADA ***\n---\n");
	
	
	
	printf("Codigo de la factura: %i\nNombre del producto: %sCantidad comprada del Producto: %i\nPrecio del producto comprado: %0.2f$\nPrecio total a pagar: %i\n---\n", fact.codigofact, fact.nomfact, inve.existepr, fact.preciouni, fact.totalfact);
	}
	fread(&fact,sizeof(fact),1,factura);
	existefact=1;
}
	if(nomfactprinci!=fact.nomuser){
		if(existefact==0){
	fread(&fact,sizeof(fact),1,factura);
	printf("\aERROR: No se encontro informacion de la factura con este nombre de usuario.\n");
  	system("pause");
  	system("cls");
    fclose(factura);
    fclose(crearproducto);
 	subMenuPrincipal();
 		}
	}
}

// INICIO DE LA FUNCIÓN DE EDITAR PRODUCTO A TRAVÉS DE SU CÓDIGO //
void editarpr(){
    FILE*crearproducto;
    crearproducto=fopen("inventario.dat","r+b");
		if(crearproducto==NULL){
   		 printf("ARCHIVO NO ENCONTRADO\n");
   			 return productos(); 
				}
    inventario inve;
    system("cls");
    printf("Actualmente te encuentras en el apartado de modificar productos\n---\n");
    printf("Ingrese el codigo de producto a modificar:\n");
    int codigo=0, existe=0;
    scanf("%i", &codigo);
    while(!feof(crearproducto)){
		fread(&inve,sizeof(inventario),1,crearproducto);
       	if (codigo==inve.codigopr&&inve.borrarpr==0){
		   printf("---\nCodigo del Producto: %i\nNombre del producto: %s\nCantidad disponible del Producto: %i\nPrecio del producto: %0.2f$\n---\n", inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni);
				printf("Ingrese nuevo precio:\n");
			fflush(stdin);
        	scanf("%f", &inve.preciouni);
        int pos=ftell(crearproducto)-sizeof(inventario);
        fseek(crearproducto,pos,SEEK_SET);
        fwrite(&inve, sizeof(inventario), 1, crearproducto);
    	printf("Se modifico el precio para dicho producto.\n");
  		}
        if (codigo==inve.codigopr&&inve.borrarpr==0){
           	printf("Ingrese nueva cantidad disponible:\n");
           	fflush(stdin);
           	scanf("%i", &inve.existepr);
        int pos=ftell(crearproducto)-sizeof(inventario);
        fseek(crearproducto,pos,SEEK_SET);
        fwrite(&inve, sizeof(inventario),1, crearproducto);
           printf("Se modifico la cantidad disponible para dicho producto.\n");
           existe=1;
        fclose(crearproducto);
           system("pause");
           break;
        productos();
			}
        }
    fread(&inve, sizeof(inventario), 1, crearproducto);
    if (existe==0){
        printf("No existe un producto con dicho codigo\n");
			fclose(crearproducto);
				getch();
		system("pause");
 	productos();
    }
}
// FIN DE LA FUNCIÓN DE EDITAR PRODUCTO A TRAVÉS DE SU CÓDIGO //


// INICIO DE LA FUNCIÓN DE ELIMINAR UN PRODUCTO A TRAVÉS DE SU CÓDIGO //
void eliminarpr(){
	    FILE*crearproducto;
    crearproducto=fopen("inventario.dat","r+b");
    if (crearproducto==NULL){
        return productos();
    }
    system("cls");
    inventario inve;
    	printf("Actualmente te encuentras en el apartado de eliminacion de productos.\n---\n\a\a\a\t***ATENCION***\n***ESCOGE EL CODIGO DEL PRODUCTO CON CUIDADO***.\n---\nIngrese el codigo de producto a borrar:\n---\n");
	int existeprbrr=0, codigoprbrr, opcionbrr=0;
	fflush(stdin);
    scanf("%i", &codigoprbrr);
    fread(&inve,sizeof(inventario),1,crearproducto);
    while (!feof(crearproducto)){
    	if (codigoprbrr==inve.codigopr&&inve.borrarpr==0){
    		printf("Estas seguro que deseas borrar el producto: %d.\n1. Si.\n2. No.\nDigite la opcion de su preferencia:\n", inve.codigopr);
    		scanf("%d", &opcionbrr);
    		switch (opcionbrr){
    			case 1:
    		inve.borrarpr=1;
    		int pos=ftell(crearproducto)-sizeof(inventario);
    		fseek(crearproducto,pos,SEEK_SET);
   			fwrite(&inve, sizeof(inventario),1,crearproducto);
    		printf("Se ha eliminado el producto con exito.\n");
    		existeprbrr=1;
    		fclose(crearproducto);
    		system("pause");
  			productos();
  				case 2:
  			system("pause");
  			break;
  			productos();
  				default:
  			printf("Digite una opcion valida.\n");
  			system("pause");
  			break;
			}
  		}
  	fread(&inve,sizeof(inventario),1,crearproducto);
    	}
    if (existeprbrr==0)
        printf("No existe un producto con dicho codigo\n");
   		fclose(crearproducto);
   		system("pause");
   		productos();
}
// FIN DE LA FUNCIÓN DE ELIMINAR PRODUCTO A TRAVÉS DE SU CÓDIGO //

//FUNCION AUX MOSTRAR PRODUCTOS A LA VENTA
void extra(){
	char descripcionpr[41], caracteres, existepr;
	inventario inve, invecodigopr, invedescripcionpr, inveexistepr, invepreciouni;
	int strcmp, codigopr;
	float preciouni;
	system("cls");
	  FILE*crearproducto;
  crearproducto=fopen("inventario.dat", "r+");
  if(crearproducto==NULL){
    printf("ARCHIVO NO ENCONTRADO\n");
    return productos(); 
}
    fread(&inve, sizeof(inve), 1, crearproducto);
  printf("Actualmente te encuentras en el apartado de los Productos Disponibles.\n---\n\t*** PRODUCTOS DISPONIBLES ***\n---\n");
  while(!feof(crearproducto)){
  	
   printf("Codigo del Producto: %i\nNombre del producto: %sPrecio del producto: %0.2f$\n---\n", inve.codigopr, inve.descripcionpr, inve.preciouni);
	fread(&inve, sizeof(inve), 1, crearproducto);
	}
 
    fclose(crearproducto);
}

void imprimirfactura(){
	
	 
}



//FUNCION AUX SEGUIR COMPRANDO
void extra2(){
	int sn;
	printf("Desea seguir comprando?:\n1. Si.\n2. No.\n---\nDigita la opcion de tu preferencia: ");
			fflush(stdin);
        		scanf("%d", &sn);
        	switch(sn){
        		case 1:
        			factura();
        			break;
        		case 2:
        			subMenuPrincipal();
        			break;
				}
}

// INICIO DE LA FUNCIÓN REPORTE DE PRODUCTO //
void reportepr(){
	FILE*crearproducto;
	  crearproducto=fopen("inventario.dat", "r");
	if(crearproducto==NULL){
    printf("ARCHIVO NO ENCONTRADO\n");
    getch(); // no existe archivo, localizacion de inventario fallido
	}
	char existepr, descripcionpr[41];
	float preciouni;
	int codp1;
	inventario inve;
	system("cls");
	printf("Actualmente te encuentras en el apartado de registro.\n---\nAqui podras conseguir productos a traves de su codigo.\n");
    printf("---\nIngrese el codigo de producto a consultar:");
    scanf("%d", &codp1);
    int existe=0;
    fread(&inve,sizeof(inventario),1,crearproducto);
    while(!feof(crearproducto)){
  	if(codp1==inve.codigopr&&inve.borrarpr==0){
  		existepr=1;
  		system("cls");
  		printf("\n\tCodigo\t|\tNombre\t|\tCantidad\t|\tPrecio\n\n");
		printf("\n\t%i\t\t%s\t\t%d\t\t%0.2f\n", inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni);
		system("pause");
		}
	fread(&inve, sizeof(inve), 1, crearproducto);	
	}
	fread(&inve,sizeof(inve), 1,crearproducto);	
    if (existepr==0){
    printf("No existe un producto con dicho codigo\n");
    system("pause");
    fclose(crearproducto);
    productos();
	}
	productos();
}
// FIN DE LA FUNCIÓN REPORTE DE PRODUCTO //



void registroUsuario(){ //funcion para el registro de usuarios
	system("cls");
  FILE*log=fopen("login.dat", "a+");
  struct Login l;
  printf("Actualmente te encuentras en el apartado de Registro\n---\nIngrese un usuario:\n");
  scanf("%s", l.username);
  printf("Ingrese una clave:\n");
  fflush(stdin);
  takepassword(l.clave);
  fwrite(&l, sizeof(l), 1, log); //se agrega el usuario y clave al log del archivo para guardar y utilizarlo como login
  fclose(log);
  printf("\n---\nSe ha registrado satisfactoriamente\n---");
  printf("\nTu nombre de usuario es: (%s) y tu clave de acceso es: (%s)\n---", l.username, l.clave); //usuario registrado
  printf("\nAhora ingresa con tu usuario y clave a la tienda para tu compra\n---\nSeras redireccionado al menu principal para tu logueo de usuario\n---\n");
  system("pause");
  system("cls");
  getchar();
}

int login(){
  FILE *log; //abre el log del archivo
  struct Login lentrada, larchivo;
  log=fopen("login.dat", "r");
  if(log==NULL){
    printf("ARCHIVO NO ENCONTRADO\n");
    return 0; // login fallido
  }
  system("cls");
  printf("Bienvenido al sistema de Login\n---\nIngresa tu nombre de usuario:\n");
  scanf("%s", lentrada.username);
  printf("Ingresa tu clave:\n");
  takepassword(lentrada.clave);
  fflush(stdin);
  while (fread(&larchivo,sizeof(larchivo), 1,log)){ //lee la informacion de registro
    if (strcmp(lentrada.username,larchivo.username) == 0
      && strcmp(lentrada.clave,larchivo.clave)==0){
      printf("\nHas ingresado satisfactoriamente al sistema\n");
      fclose(log);
      return 1; // login aprobado
    }
  }
  printf("\nSu usuario o clave es incorrecta\a\n");
  printf("Presiona cualquier tecla para continuar...\n");
  getchar();
  fclose(log);
  system("cls");
  return 0; // login fallido
}
