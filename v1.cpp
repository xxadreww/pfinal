#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define cadena_corta  20
#define filas 5
#define columnas 10 //definimos variables globales

struct Login // se crea la estructura del área de login
{
  char username[cadena_corta];
  char clave[cadena_corta];
};

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
void productos();
void factura();
void reportedefacturas();
int login();
char letrann[10]="Letra \xA4";

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
    printf("Bienvenido a nuestra tienda\n---\nActualmente te encuentras en el apartado de Usuarios\n---\nDigita la opcion de tu preferencia:\n---\n1: Crear un nuevo usuario\n2: Ingresar con un usuario ya existente\n3: Salir del programa.\n");
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
	system("cls");
  int opcion=0;

  while(1)//Mientras sea verdadero se colocarán las opciones del submenu luego de haber ingresado al programa
  {
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
    printf("Actualmente te encuentras en el apartado de Archivos\n---\n1: Usuarios.\n2: Clientes\n3: Productos\n4: Salir\n---\nDigita la opcion de tu preferencia: ");

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
        printf("\nXXXXXXXXXXXXXXXX\n");
        break;
      case 2:
        printf("\nXXXXXXXXXXXXXXXX\n");
        break;
      case 3:
      	printf("\nXXXXXXXXXXXXXXXX\n");
      	break;
      case 4:
        printf("Gracias por elegirnos!! \n");
        return salir;
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

void productos(){
	printf("\nproductos\n");
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
  FILE *log = fopen("login.txt", "a+");
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
