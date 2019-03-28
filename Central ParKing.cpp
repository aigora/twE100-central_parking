#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <windows.h> 

struct plaza{
	int planta;
	int numero_plaza;
	char tipo_plaza;
	int estado_plaza;
	int fecha_entrada_plaza;
	int fecha_salida_plaza;
	
	
};

int main(){
	
 int opcioninicio;
 int i,k,j;
 int m1 [5][10];	
	
 system("color 0E");
 printf("Bienvenido a Central Parking\n");
 Sleep(1000);
 system ("cls");
 
 printf("INICIO\nEscoja entre una de las siguientes opciones:\n");
 
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_INTENSITY);
 
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
 		system("mode con: cols=80 lines=55");
 		printf("2 - Consultar estado del Parking\n");
 		Sleep(1000);
 		
 		for (k=0;k<=219;k++){ //condicion para crear las plazas  LARGO DEL PARKING
				
		    	printf("|\t");  //imprime barras
			        
	           
		        while   (k==49){               //fila numerica       DA EL LARGO DE LAS PLAZAS   50 DE COCHE
		    
		       	    i=0; //meter en el futuro el cuadrante a partir de la estructura
		       	    
	     	        for (j=1;j<=10;j++){
	     	        	
	     	            m1[i][j]=i*9+j;
	     	          	
						if (m1[i][j]==10){               //condicion para imprimir el cuadrante
		                 	m1[i][j]='A';         //introducir la direccion al cuadrante de la estructura
		                	printf("|   %c\t",m1[i][j]);
						}  
				        else{
				             printf("|   %d\t",m1[i][j]);
				        }
				        
		            }
		            printf("\n\n\n");
		            break; 
				}
		            
		        while   (k==99){               //fila numerica
		       	    
					i=1; //meter en el futuro el cuadrante a partir de la estructura
					
	     	        for (j=1;j<=10;j++){

	     	            m1[i][j]=i*9+j;
	     	            
						if (m1[i][j]==19){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion
		                	m1[i][j]='B';         //introducir la direccion al cuadrante de la estructura
		                	printf("|   %c\t",m1[i][j]);
						}  
				        else{
				            printf("|   %d\t",m1[i][j]);
				        }   
		            }
		            printf("\n\n\n");
		            break;   
	           }
	           
	            while   (k==119){               //fila numerica       DA EL LARGO DE LAS PLAZAS   20 DE MOTO
		       	    
					i=2; //meter en el futuro el cuadrante a partir de la estructura
					
	     	        for (j=1;j<=10;j++){

	     	            m1[i][j]=i*9+j;
	     	            
						if (m1[i][j]==28){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion  //tambien sumando de 9 en 9
		                	m1[i][j]='C';         //introducir la direccion al cuadrante de la estructura
		                	printf("|   %c\t",m1[i][j]);
						}  
				        else{
				            printf("|   %d\t",m1[i][j]);
				        }   
		            }
		            printf("\n\n\n");
		            break;   
	           }
	           
	            while   (k==169){               //fila numerica
		       	    
					i=3; //meter en el futuro el cuadrante a partir de la estructura   
					
	     	        for (j=1;j<=10;j++){      

	     	            m1[i][j]=i*9+j;             //numeracion de las plazaS
	     	            
						if (m1[i][j]==37){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion  //tambien sumando de 9 en 9
		                	m1[i][j]='D';         //introducir la direccion al cuadrante de la estructura
		                	printf("|   %c\t",m1[i][j]);
						}  
				        else{
				            printf("|   %d\t",m1[i][j]);
				        }   
		            }
		            printf("\n\n\n");
		            break;   
	           }
	            while   (k==219){               //fila numerica
		       	    
					i=4; //meter en el futuro el cuadrante a partir de la estructura   
					
	     	        for (j=1;j<=10;j++){      

	     	            m1[i][j]=i*9+j;             //numeracion de las plazaS
	     	            
						if (m1[i][j]==46){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion  //tambien sumando de 9 en 9
		                	m1[i][j]='E';         //introducir la direccion al cuadrante de la estructura
		                	printf("|   %c\t",m1[i][j]);
						}  
				        else{
				            printf("|   %d\t",m1[i][j]);
				        }   
		            }
		            printf("\n\n\n");
 	        	break;
 	            }
        }
        break;	
 	case 3:
 		printf("3 - Consultar tarifas\n");	
		 break;	
	default:
		while (opcioninicio!=1 && opcioninicio!=2 && opcioninicio!=3){
		printf("Introduce una opcion valida: 1,2,3\n");
		system("pause");
		scanf("%d",&opcioninicio);	
		}
			
}
return 0 ;
 
}

