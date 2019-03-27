#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>  //para usar gotoxy e imprimir por coordenadas

/*


struct plaza[]{
	int planta;    (i/45+1)
	int numero_plaza; i
	char tipo_plaza; (i/9+65)
	int estado_plaza;  
	int fecha_entrada_plaza;
	int fecha_salida_plaza;
    };*/
    

    
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}  

int main(){
	
 system("mode con: cols=81 lines=55");  // establece el tamaño de pantalla
 int x,y;	
 int opcioninicio,parpadeo,opcionplanta;
 bool repite,repite2;     //establece la variable que permite repite la aparicion del menu con do en caso de defaul (digito no valido)
 int i,k,j;
 int m1 [10][10];	
 char bajar;	
 gotoxy( 24, 25); 
 printf("Bienvenido a Central Parking\n");
 Sleep(1000);
 system ("cls");
 
 

do{
 system("color 0E"); //varia colorde consola yu letras	
 
 gotoxy( 20, 10);
 
 printf("\t           INICIO\n");
 printf("\t         Escoja entre una de las siguientes opciones:\n");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
 printf("\t\t       1 - Registrar Entrada o Salida         \n");	
 printf("\t\t       2 - Consultar estado del Parking       \n");
 printf("\t\t       3 - Consultar tarifas                  \n");

 scanf("%d",&opcioninicio);
 
 system("cls");
 
    switch(opcioninicio) {
    	case 1:
			
			/*for (parpadeo=220; parpadeo>=0;parpadeo--){
				
			     gotoxy( 10, 22);
            
			     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);  //varia color de fondo y letras
                 printf("\t       1 - Registrar Entrada o Salida         \n");	
 
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                 printf("\t\t       2 - Consultar estado del Parking       \n");
                 printf("\t\t       3 - Consultar tarifas                  \n");
           
		         Sleep(240);        // tiempo que permanece el texto antes de borrarse
                 system ("cls");
                 Sleep(parpadeo);          // tiempo de parpadeo en funcion de la variable
            
                 parpadeo=((parpadeo-20)^(9/10))-12;    //funcion que incrementa la velocidad de parpadeo como en una parabola (el exponente aproximado a 1 hace que esta sea parabola sea menos pronunciada)
            }
            */
            system("color 0E");
 	    	printf("1 - Registrar Entrada o Salida\n");
 	    	
 	    	
 	    	
 	    	break;
 	    	
    	case 2:
  		
			/*for (parpadeo=220; parpadeo>=0;parpadeo--){
				
			     gotoxy( 10, 12);
            
			     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                 printf("\t       1 - Registrar Entrada o Salida         \n");	
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);  //varia color de fondo y letras
                 printf("\t\t       2 - Consultar estado del Parking       \n");
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                 printf("\t\t       3 - Consultar tarifas                  \n");
           
		         Sleep(240);        // tiempo que permanece el texto antes de borrarse
                 system ("cls");
                 Sleep(parpadeo);          // tiempo de parpadeo en funcion de la variable
            
                 parpadeo=((parpadeo-20)^(9/10))-12;    //funcion que incrementa la velocidad de parpadeo como en una parabola (el exponente aproximado a 1 hace que esta sea parabola sea menos pronunciada)
            }
    		*/
    		
    		
 	    	do{
 	    		system("color 0E");
 	    		gotoxy(23, 13);     
 	    	    printf("2 - CONSULTAR ESTADO DEL PARKING\n\n");
 	    	    Sleep(500);
 	    		printf("\t      Seleccione el numero de planta sotano a consultar\n\n");
 	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
 	    		printf("\t\t          1          2          3          ");
 	    		gotoxy(32, 52);
 	    		printf("4 - Volver\n");
 	    		scanf ("%d",&opcionplanta);
 	    		system("cls");
			 
 	    	
 	    		
 	    		switch(opcionplanta) {
 	    			case 1:
 	    				system("color 0E");
 	    				printf("\t\t\t\t PLANTA 1\n");
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
                    case 2:
                    	system("color 0E");
 	    				printf("\t\t\t\t PLANTA 2\n");
                    	for (k=0;k<=189;k++){ //condicion para crear las plazas  LARGO DEL PARKING				
		                	printf("|\t");  //imprime barras			        	           
		                    while   (k==49){               //fila numerica       DA EL LARGO DE LAS PLAZAS   50 DE COCHE
		    
		                	    i=5; //meter en el futuro el cuadrante a partir de la estructura
		       	    
	     	                    for (j=1;j<=10;j++){
	     	        	
	     	                        m1[i][j]=i*9+j;
	     	          	
					             	if (m1[i][j]==55){               //condicion para imprimir el cuadrante
		                            	m1[i][j]='F';         //introducir la direccion al cuadrante de la estructura
		                            	printf("|   %c\t",m1[i][j]);
					            	}  
				                    else{
				                        printf("|   %d\t",m1[i][j]);
				                    }				        
		                        }
		                        printf("\n\n\n");
		                        break; 
			             	}		            
		                    while   (k==69){               //fila numerica                 MOTO
		       	    
				              	i=6; //meter en el futuro el cuadrante a partir de la estructura
					
	     	                    for (j=1;j<=10;j++){

	     	                        m1[i][j]=i*9+j;
	     	            
						            if (m1[i][j]==64){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion
		                            	m1[i][j]='B';         //introducir la direccion al cuadrante de la estructura
		                            	printf("|   %c\t",m1[i][j]);
					            	}  
				                    else{
				                    printf("|   %d\t",m1[i][j]);
				                    }   
		                        }
		                        printf("\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==119){               //fila numerica       DA EL LARGO DE LAS PLAZAS   COCHE
		       	    
				            	i=7; //meter en el futuro el cuadrante a partir de la estructura
					
	     	                    for (j=1;j<=10;j++){

	     	                        m1[i][j]=i*9+j;
	     	            
					            	if (m1[i][j]==73){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion  //tambien sumando de 9 en 9
		                            	m1[i][j]='C';         //introducir la direccion al cuadrante de la estructura
		                            	printf("|   %c\t",m1[i][j]);
					            	}  
				                   else{
				                        printf("|   %d\t",m1[i][j]);
				                   }   
		                        }
		                        printf("\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==139){               //fila numerica
		       	    
				            	i=8; //meter en el futuro el cuadrante a partir de la estructura   
					
	     	                    for (j=1;j<=10;j++){      

	     	                        m1[i][j]=i*9+j;             //numeracion de las plazaS
	     	            
					            	if (m1[i][j]==82){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion  //tambien sumando de 9 en 9
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
	                        while   (k==189){               //fila numerica
		       	    
				        	    i=9; //meter en el futuro el cuadrante a partir de la estructura   
					
	     	                    for (j=1;j<=10;j++){      

	     	                        m1[i][j]=i*9+j;             //numeracion de las plazaS
	     	            
					        	    if (m1[i][j]==91){               //condicion para imprimir el cuadrante poner i= al cuadrante cmo condicion  //tambien sumando de 9 en 9
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
                    case 4 :
                    	system("cls"); 
						repite=true;   
						break;	
						
 	    			default:
	                  	while (opcionplanta!=1 && opcionplanta!=2){
	                  		system("cls");
	                  		gotoxy( 25, 25);
		                    printf("Por favor, introduce una opcion valida: 1,2\n");
	     	                Sleep(1500);
	     	                system("cls");
	     	                repite2=true;
			                break;						 
				        }	    		
			    }
            }
 	    	while (repite2);
 	       		
 		
 	    	
            break;
            
    	case 3:
    		for (parpadeo=220; parpadeo>=0;parpadeo--){
				
			     gotoxy( 10, 22);
            
			     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                 printf("\t       1 - Registrar Entrada o Salida         \n");	
                 printf("\t\t       2 - Consultar estado del Parking       \n");
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_INTENSITY);  //varia color de fondo y letras
                 printf("\t\t       3 - Consultar tarifas                  \n");
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
           
		         Sleep(240);        // tiempo que permanece el texto antes de borrarse
                 system ("cls");
                 Sleep(parpadeo);          // tiempo de parpadeo en funcion de la variable
            
                 parpadeo=((parpadeo-20)^(9/10))-12;    //funcion que incrementa la velocidad de parpadeo como en una parabola (el exponente aproximado a 1 hace que esta sea parabola sea menos pronunciada)
            }
    		
 	    	printf("3 - Consultar tarifas\n");	
		    break;	
		    
    	default:
	    	while (opcioninicio!=1 && opcioninicio!=2 && opcioninicio!=3){
		    printf("Por favor, introduce una opcion valida: 1,2,3\n");
	     	Sleep(2000);
	     	system("cls");
	     	repite=true;
			break;	
		    }
   }
}
while (repite);

return 0 ;
 
}

/*void menu()*/

