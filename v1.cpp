#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//login-registro
#define cadena_corta  20
#define filas 5
#define columnas 10 //definimos variables globales

//productos
#define maximacadena 1000
#define maximaventa 1000
#define maximoproducto 100

struct Login // se crea la estructura del área de login
{
  char username[cadena_corta];
  char clave[cadena_corta];
};
// VARIABLES GLOBALES //
int menuPrincipal(); //variables locales con volcado
int subMenuPrincipal();
void registroUsuario();
void productosVenta();
int menuarchivo();
int menumovimientos();
int menuayuda();
void registration();
void usuarios();
void clientes();
void productos(); //funcion de productos
void factura();
void crearpr(); // crear producto
void reportepr(); // reporte de producto
void mostrarpr(); //muestra todos los productos guardados en el stock
void editarpr(); // editar un producto en existencia a traves de su código
void eliminarpr(); // eliminar producto del lote a traves de su código
void reportedefacturas();
int login();
char letrann[10]="Letra \xA4";

// ESTRUCTURA DEL INVENTARIO DE PRODUCTOS
typedef struct {
	char descripcionpr[20];
	float preciouni;
	int codigopr, existepr;
} inventario;
// FIN ESTRUCTURA DEL INVENTARIO DE PRODUCTOS

struct unproducto{
	char nombrepr[maximacadena];
	int cantidadpr, preciopr;
};

enum // se declaran las variables principales
{
  ulogout,
  ulogueado,
  salir
};
int main()
{
  int estadoUsuario=ulogout;
  int seat[filas][columnas]={0};
  while(estadoUsuario != salir)
  {
    if(estadoUsuario==ulogout)
    {// El usuario no está logueado, se devolverá al menu principal 
      estadoUsuario = menuPrincipal();
    }
    else
    {// El usuario se ha logueado, irá al sub menu principal
      estadoUsuario=subMenuPrincipal();
    }
  }
  return 0;
}

int menuPrincipal() //Se colocan las opciones principales a llevar del programa
{
  int opcion;
  while (1){
    printf("\t***BIENVENIDO A NUESTRA TIENDA***\n---\nActualmente te encuentras en el apartado de Usuarios\n---\nDigita la opcion de tu preferencia:\n---\n1: Crear un nuevo usuario.\n2: Ingresar con un usuario ya existente.\n3: Salir del programa.\n");
	fflush(stdin);
    if (scanf("%d", &opcion)==1)
    {
      switch (opcion)
      {
      case 1:
        registroUsuario();
        break;
      case 2:
        if (login())
          return ulogueado;
        break;
      case 3:
        printf("Gracias por elegirnos\n");
        return salir;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
} 
int subMenuPrincipal(){
  int opcion=0;

  while(1)//Mientras sea verdadero se colocarán las opciones del submenu luego de haber ingresado al programa
  {
  	system("cls");
    printf("Ingresaste correctamente, a nuestra tienda:\n---\n");
    printf("1: Archivo\n2: Movimientos\n3: Ayuda\n4: Salir\n---\nDigita la opcion de tu preferencia:\n");
    if (scanf("%d", &opcion)==1){
    fflush(stdin);
	switch (opcion){
	case 1:
		system("cls");
        menuarchivo();
        break;
	case 2:
		system("cls");
        menumovimientos();
        break;
	case 3:
		system("cls");
      	menuayuda();
      	break;
	case 4:
        printf("Gracias por elegirnos\n");
        return salir;
	default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
		}
      }
    }
  }

int menuarchivo(){ // // Apartado de archivos del menu de opciones a elegir sobre usuarios/clientes/productos
	int opcion=0;
  while(1){
  	system("cls");
    printf("Actualmente te encuentras en el apartado de Archivos\n---\n1: Usuarios.\n2: Clientes.\n3: Productos.\n4: Salir.\n---\nDigita la opcion de tu preferencia: ");

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
        printf("Gracias por elegirnos\n");
        return salir;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
}

int menumovimientos(){ // Apartado de movimientos del menu de opciones a elegir sobre facturas/reportes
	int opcion;
  while (1)
  {
    printf("Actualmente te encuentras en el apartado de Movimientos\n---\n1: Nueva factura.\n2: Reporte de facturas.\n3: Salir.\n---\nDigita la opcion de tu preferencia: ");

    if (scanf("%d", &opcion)==1){
      switch ( opcion){
      case 1:
        factura();
        break;
      case 2:
        reportedefacturas();
        break;
      case 3:
        printf("Gracias por elegirnos\n");
        return salir;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;	
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
        printf("\n--- NOMBRE DEL SISTEMA ---\n\n*Technology Shop*\n\n");
        break;
      case 2:
      	system("cls");
        printf("\n--- Nombre de los Creadores ---\n\n*Aldana Eliannis   CI: 30453246   \n*Martinez Fabiana         CI: 304987516\n*Moya Enyer         CI: 30498773\n*Pulido Alejandro        CI: 30576458 \n*Isea Francisco        CI: 30293487\n\n");
        break;
      case 3:
      	system("cls");
      	printf("\n--- A%co y Semestre cursado ---\n\n SEMESTRE II (2)\n\n A%co: 2022\n\n", 164,164);
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
	printf("\nusuarios\n");
}

void clientes(){
	printf("\nclientes\n");
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
				salir;
				break;
		while(respuesta<1||respuesta>6){
			printf ("Por favor ingresa una opcion valida\n");
			scanf("%d", &respuesta);
			getch();
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
	  crearproducto=fopen("inventario.txt", "ab+");
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
	char descripcionpr[41], caracteres, existepr;
	inventario inve, invecodigopr, invedescripcionpr, inveexistepr, invepreciouni;
	int strcmp, codigopr;
	float preciouni;
	system("cls");
	  FILE*crearproducto;
  crearproducto=fopen("inventario.txt", "rb");
  if(crearproducto==NULL){
    printf("ARCHIVO NO ENCONTRADO\n");
    return productos(); 
}
    fread(&inve, sizeof(inve), 1, crearproducto);
    if (inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni){
  printf("Actualmente te encuentras en el apartado de los Productos Disponibles.\n---\n\t*** PRODUCTOS DISPONIBLES ***\n---\n");
  while(feof(crearproducto)==0){
   printf("Codigo del Producto: %i\nNombre del producto: %s\nCantidad disponible del Producto: %i\nPrecio del producto: %0.2f$\n---\n", inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni);
	fread(&inve, sizeof(inve), 1, crearproducto);
	}
  system("pause");
    fclose(crearproducto);
 	 return productos();
  system("cls");
	}
}

// FIN DE LA FUNCIÓN DE MOSTRAR PRODUCTOS EN EL LOTE //

// INICIO DE LA FUNCIÓN DE EDITAR PRODUCTO A TRAVÉS DE SU CÓDIGO //
void editarpr(){
    FILE*crearproducto;
    crearproducto=fopen("inventario.txt","r+b");
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
       	if (codigo==inve.codigopr){
		   printf("---\nCodigo del Producto: %i\nNombre del producto: %s\nCantidad disponible del Producto: %i\nPrecio del producto: %0.2f$\n---\n", inve.codigopr, inve.descripcionpr, inve.existepr, inve.preciouni);
				printf("Ingrese nuevo precio:\n");
			fflush(stdin);
        	scanf("%f", &inve.preciouni);
        int pos=ftell(crearproducto)-sizeof(inventario);
        fseek(crearproducto,pos,SEEK_SET);
        fwrite(&inve, sizeof(inventario), 1, crearproducto);
    	printf("Se modifico el precio para dicho producto.\n");
  		}
        if (codigo==inve.codigopr){
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
	
	
}
// FIN DE LA FUNCIÓN DE ELIMINAR PRODUCTO A TRAVÉS DE SU CÓDIGO //

void reportepr(){
	printf("XXXXXXXXXXXX");
}

void factura(){
	printf("\nfactura\n");
}

void reportedefacturas(){
	printf("\nreporte de facturas\n");
}

void registroUsuario() //funcion para el registro de usuarios
{
	system("cls");
  FILE*log=fopen("login.txt", "a+");
  struct Login l;
  printf("Actualmente te encuentras en el apartado de Registro\n---\nIngrese un usuario:\n");
  scanf("%s", l.username);
  printf("Ingrese una clave:\n");
  fflush(stdin);
  scanf("%s", l.clave);
  fwrite(&l, sizeof(l), 1, log); //se agrega el usuario y clave al log del archivo para guardar y utilizarlo como login
  fclose(log);
  printf("\n---\nSe ha registrado satisfactoriamente\n---");
  printf("\nTu nombre de usuario es: (%s) y tu clave de acceso es: (%s)\n---", l.username, l.clave); //usuario registrado
  printf("\nAhora ingresa con tu usuario y clave a la tienda para tu compra\n---\nSeras redireccionado al menu principal para tu logueo de usuario\n---\n");
  system("pause");
  system("cls");
  getchar();
}

int login()
{
  FILE *log; //abre el log del archivo
  struct Login lentrada, larchivo;
  log=fopen("login.txt", "r");
  if(log==NULL)
  {
    printf("ARCHIVO NO ENCONTRADO\n");
    return 0; // login fallido
  }
  system("cls");
  printf("Bienvenido al sistema de Login\n---\nIngresa tu nombre de usuario:\n");
  scanf("%s", lentrada.username);
  printf("Ingresa tu clave:\n");
  scanf("%s", lentrada.clave);
  fflush(stdin);
  while (fread(&larchivo,sizeof(larchivo), 1,log)) //lee la informacion de registro
  {
    if (strcmp(lentrada.username,larchivo.username) == 0
      && strcmp(lentrada.clave,larchivo.clave)==0)
    {
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
