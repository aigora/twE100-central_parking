#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <windows.h> 


int main(){
 int opcioninicio;	
	
 system("color 0E");
 printf("Bienvenido a Central Parking\n");
 Sleep(2000);
 system ("cls");
 
 printf("INICIO\nEscoja entre una de las siguientes opciones:\n");
 printf("1 - Registrar Entrada o Salida\n");
 printf("2 - Consultar estado del Parking\n");
 printf("3 - Consultar tarifas\n");
 
 scanf("%d",&opcioninicio);
 
 system("cls");
 
 switch(opcioninicio) {
 	case 1:
 		printf("1 - Registrar Entrada o Salida\n");
 		break;
 	case 2:
 		printf("2 - Consultar estado del Parking\n");
 		break;
 	case 3:
 		printf("3 - Consultar tarifas\n");	
		 break;	
	default:
		printf("Introduce una opcion valida: 1,2,3");
		
}
 
return 0;
 
}

