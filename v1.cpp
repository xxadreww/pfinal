#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LONG_STRING 100
#define SHORT_STRING  20

struct Login
{
  char username[SHORT_STRING];
  char password[SHORT_STRING];
};

int handleMainMenu();
int handleloginMenu();
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

enum
{
  LOGGED_OUT,
  LOGGED_IN,
  EXIT
};

int main()
{	
int user_state = LOGGED_OUT;

  while  (user_state != EXIT)
  {
    if ( user_state == LOGGED_OUT)
    { 
      user_state = handleloginMenu();
    }
    else
    {
      user_state = handleMainMenu();
    }
  }
  return 0;
}

int handleloginMenu()
{
  int choice;
  while ( 1 )
  {
    printf("\n\nMenu de registro y login\n");
    printf("\n");
    printf("\n1 : Registro!!!\n");
    printf("2 : Login!!!\n");
    printf("3 : Salir\n");
    printf("Ingrese su eleccion: \n");

    if ( scanf("%d", &choice) == 1)
    {
      switch ( choice)
      {
      case 1:
        registration();
        break;
      case 2:
        if ( login())
          return LOGGED_IN;
        break;
      case 3:
        printf("Gracias por elegirnos!! \n");
        return EXIT;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
} 

int handleMainMenu()
{
  int choice;
  while ( 1 )
  {
    printf("\nBienvenido a nuestra tienda!!!\n");
    printf("\n");
    printf("\n1 : Archivo!!!\n");
    printf("2 : Movimientos!!!\n");
    printf("3 : Ayuda!!!\n");
    printf("4 : Salir\n");
    printf("Ingrese su eleccion: \n");

    if ( scanf("%d", &choice) == 1)
    {
      switch ( choice)
      {
      case 1:
        menuarchivo();
        break;
      case 2:
        menumovimientos();
        break;
      case 3:
      	menuayuda();
      	break;
      case 4:
        printf("Gracias por elegirnos!! \n");
        return EXIT;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
} 

int menuarchivo()
{
	int choice;
  while ( 1 )
  {
    printf("Submenu archivo\n");
    printf("\n");
    printf("\n1 : Usuarios\n");
    printf("2 : Clientes\n");
    printf("3 : Productos\n");
    printf("4 : Salir\n");
    printf("Ingrese su eleccion: \n");

    if ( scanf("%d", &choice) == 1)
    {
      switch ( choice)
      {
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
        printf("Gracias por elegirnos!! \n");
        return EXIT;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
      }
    }
  }
}

int menumovimientos()
{
	int choice;
  while ( 1 )
  {
    printf("Submenu movimientos\n");
    printf("\n");
    printf("\n1 : Nueva factura\n");
    printf("2 : Reporte de facturas\n");
    printf("3 : Salir\n");
    printf("Ingrese su eleccion: \n");

    if ( scanf("%d", &choice) == 1)
    {
      switch ( choice)
      {
      case 1:
        factura();
        break;
      case 2:
        reportedefacturas();
        break;
      case 3:
        printf("Gracias por elegirnos!! \n");
        return EXIT;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;	
      }
    }
  }
}

int menuayuda()
{
	int choice;
  while ( 1 )
  {
    printf("Submenu ayuda\n");
    printf("\n");
    printf("\n1 : Nombre del sistema\n");
    printf("2 : Informacion de los autores\n");
    printf("3 : Año y semestre\n");
    printf("4 : Salir\n");
    printf("Ingrese su eleccion: \n");

    if ( scanf("%d", &choice) == 1)
    {
      switch ( choice)
      {
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
        return EXIT;
      default:
        printf("Eleccion invalida, por favor ingrese un numero valido\n");
        break;
       }
    }
  }
}

void usuarios()
{
	printf("\nusuarios\n");
}

void clientes()
{
	printf("\nclientes\n");
}

void productos()
{
	printf("\nproductos\n");
}

void factura()
{
	printf("\nfactura\n");
}

void reportedefacturas()
{
	printf("\nreporte de facturas\n");
}


void registration()
{
  FILE *log = fopen("login.txt", "a+");
  struct Login l;
  printf("\nIngrese un usuario : ");
  scanf("%s", l.username);
  printf("\nIngrese una contrasena : ");
  scanf("%s", l.password);
  fwrite(&l, sizeof(l), 1, log);
  fclose(log);
  printf("\nSe ha registrado satisfactoriamente!!");
  printf("\nTu UserId es %s y tu contrasena es %s", l.username, l.password);
  printf("\nAhora ingresa con tu usuario y contrasena!!");
  printf("\nPresiona cualquier tecla para continuar ...");
  getchar();
}

int login()
{
  FILE *log;
  struct Login linput, lfile;
  log = fopen("login.txt", "r");
  if (log == NULL)
  {
    printf("ARCHIVO NO ENCONTRADO!!!\n");
    return 0;
  }
  printf("\nUserID : ");
  scanf("%s", linput.username);
  printf("\nPassword : ");
  scanf("%s", linput.password);
  while ( fread(&lfile, sizeof(lfile), 1, log)  )
  {
    if (strcmp(linput.username, lfile.username) == 0
      && strcmp(linput.password, lfile.password)==0)
    {
      printf("\nHa ingresado satisfactoriamente !!\n");
      fclose(log);
      return 1; 
    }
  }
  printf("\nSu usuario o contrasena es incorrecta !!\n");
  getchar();
  fclose(log);
  return 0; 
}
