#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>  //para usar gotoxy e imprimir por coordenadas
#include <ctime>



struct plaza {
    int numero_plaza;    //i
	int planta;          //(i/45+1)	
	char tipo_plaza;     // (i/9+65)
	int estado_plaza; 
	char matricula[7]; 
	int hora_entrada;
	int hora_salida;
    };
    
    

int buscarPlazaLibre(struct plaza parking[],char tipovehiculo);    
void leerFichero(char direccion[],struct plaza parking[]);
void gotoxy(short x, short y);
int fecha();



int main(){
	
 system("mode con: cols=81 lines=55");  // establece el tamaño de pantalla
 int x,y;	
 int opcioninicio,parpadeo,opcionregistro,opcionplanta,plazaasignada;
 bool repite,repite2,repite3;     //establece la variable que permite repite la aparicion del menu con do en caso de defaul (digito no valido)
 int i,k,j;
 int m1 [15][15];	
 char tipovehiculo;	// para el menu
 char direccion[] = "plazas.txt";
 struct plaza parking[150];
 int nplazas=150; // NO UTIL DE MOMENTO
 gotoxy( 25, 20); 
 printf("Bienvenido a Central Parking\n");
 Sleep(1000);
 /*leerFichero (parking,&nplazas);*/
 Sleep(500);
 system ("cls");
 
 fecha();
leerFichero(direccion,parking); 

 for (i=1;i<=150;i++){
 
						
							printf("\n%d %d %c %d %s\n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula);
}
getchar();

do{
 system("color 0E"); //varia colorde consola yu letras	
 fecha();
 gotoxy( 22, 10);
 
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
            }*/
            
            do{            	
 	    		system("color 0E");
 	    		fecha();
 	    		gotoxy(22, 12);     
 	    	    printf("1 - REGISTRAR ENTRADA O SALIDA\n\n");
 	    	    Sleep(500);
 	    		printf("\t        Escoja entre una de las siguientes opciones:\n\n");
 	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
 	    		printf("\t\t             1-Dejar vehiculo             \n");
 	    		printf("\t\t             2-Recoger vehiculo           \n");
 	    		printf("\t\t             3-buscar vehiculo            \n");
 	    		gotoxy(32, 52);
 	    		printf("4 - Volver\n");
 	    		scanf ("%d",&opcionregistro);
 	    		system("cls");
                
                switch(opcionregistro) {
                	case 1:
                		system("color 0E");
                		fecha();
                		gotoxy(0, 12);  
                		printf("\t\t               1-DEJAR VEHICULO             \n\n");
                		printf("\t\t         Indique el tipo de vehiculo\n\n");
                		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
						printf("\t\t\t          C - Coche          \n\n");
						printf("\t\t\t          M - Moto           \n\n");
                		fflush(stdin);
                		scanf("%c",&tipovehiculo);
                		system("cls");
                		plazaasignada=buscarPlazaLibre(parking,tipovehiculo);
                			if (plazaasignada!=-1){
                				system("color 0E");
                				int u;
                				fecha();
                    			gotoxy(22, 12);
                    			parking[plazaasignada].estado_plaza=1;
                    			parking[plazaasignada].hora_entrada=fecha();
                    			Sleep(2000);
                    			
                    			printf(" %d\n\n\t\t\t",parking[plazaasignada].hora_entrada);
                    			printf("Indique la matricula de su %c\n\n\t\t\t",tipovehiculo);
                    			Sleep(3500);
                	    		break;
                	      	}
                	 	    else {
                		    	system("color 0E");
                		    	fecha();
                	    		gotoxy(20, 20);
                	    		printf("Lo sentimos, no hay plazas de %c disponibles",tipovehiculo);
                	    		Sleep(1500);
                	    		system("cls");
                	    		repite3=true;
                	    		break;
                		    }
                			
                			
							
                		getchar();	
                		
						
                		
				        break;
				        
				    case 4 :
                    	system("cls");						 
                    	repite3=false;     //si no se pone no deja retroceder despues de haber entrado y retrocedido en en buble de repite3 ya que al salir se le asigna true
						repite=true;   
						
						break;
				}
            
            
            
            }
            while(repite3);
            
            
            
 	    	
 	     	    	
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
            }*/
    		
    		
    		
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
 	    				printf("\n\n\t\t\t\t     PLANTA 1\n\n\n");
 	    				for (k=1;k<=242;k++){ //condicion para crear las plazas  LARGO DEL PARKING				
		                	printf("|\t");  //imprime barras			        	           
		                    while   (k==55){               //fila numerica       DA EL LARGO DE LAS PLAZAS   55 DE COCHE		    
		                	    i=0; //meter en el futuro el cuadrante a partir de la estructura		       	    
	     	                    for (j=1;j<=10;j++){
	     	                        m1[i][j]=i*10+j;
				                    printf("|   %d\t",m1[i][j]);    				        
		                        }
		                        printf("|\n\n\n\n");
		                        break; 
			             	}		            
		                    while   (k==110){               //fila numerica		       	    
				              	i=1; //meter en el futuro el cuadrante a partir de la estructura					
	     	                    for (j=1;j<=10;j++){

	     	                        m1[i][j]=i*10+j;
	     	                        printf("|   %d\t",m1[i][j]);
				                }     		                        
		                        printf("|\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==132){               //fila numerica       DA EL LARGO DE LAS PLAZAS   22 DE MOTO		       	    
				            	i=2; //meter en el futuro el cuadrante a partir de la estructura					
	     	                    for (j=1;j<=10;j++){
	     	                        m1[i][j]=i*10+j;	     	                      	
				                    printf("|   %d\t",m1[i][j]);				                     
		                        }
		                        printf("|\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==187){               //fila numerica		       	    
				            	i=3; //meter en el futuro el cuadrante a partir de la estructura  					
	     	                    for (j=1;j<=10;j++){      
	     	                        m1[i][j]=i*10+j;             //numeracion de las plazaS	     	            					            	
				                    printf("|   %d\t",m1[i][j]);				                       
		                        }
		                        printf("|\n\n\n\n");
		                        break;   
	                        }
	                        while   (k==242){               //fila numerica		       	    
				        	    i=4; //meter en el futuro el cuadrante a partir de la estructura  					
	     	                    for (j=1;j<=10;j++){      
	     	                        m1[i][j]=i*10+j;             //numeracion de las plazaS	     	            					        	    
				                    printf("|   %d\t",m1[i][j]);				                       
		                        }
		                        printf("|\n\n\n\n");
 	                        	break;
 	                        } 	                       
                        }                        
                        getch();
                        system("cls");
                        repite2=true;                       
                        break;
                        
                    case 2:
                    	system("color 0E");
 	    				printf("\n\n\t\t\t\t     PLANTA 2\n\n\n");
                    	for (k=1;k<=219;k++){ //condicion para crear las plazas  LARGO DEL PARKING				
		                	printf("|\t");  //imprime barras			        	           
		                    while   (k==55){               //fila numerica       DA EL LARGO DE LAS PLAZAS   55 DE COCHE		    
		                	    i=5; //meter en el futuro el cuadrante a partir de la estructura		       	    
	     	                    for (j=1;j<=10;j++){	     	        	
	     	                        m1[i][j]=i*10+j;	     	          						             						            				                    
				                    printf("|   %d\t",m1[i][j]);				                    				        
		                        }
		                        printf("|\n\n\n\n\n");
		                        break; 
			             	}		            
		                    while   (k==77){               //fila numerica                 MOTO		       	    
				              	i=6; //meter en el futuro el cuadrante a partir de la estructura					
	     	                    for (j=1;j<=10;j++){
	     	                        m1[i][j]=i*10+j;	     	            
				                    printf("|   %d\t",m1[i][j]);				                      
		                        }
		                        printf("|\n\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==132){               //fila numerica       DA EL LARGO DE LAS PLAZAS   COCHE		       	    
				            	i=7; //meter en el futuro el cuadrante a partir de la estructura					
	     	                    for (j=1;j<=10;j++){
	     	                        m1[i][j]=i*10+j;	     	            
				                    printf("|   %d\t",m1[i][j]);				                     
		                        }
		                        printf("|\n\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==154){               //fila numerica		       	    
				            	i=8; //meter en el futuro el cuadrante a partir de la estructura   					
	     	                    for (j=1;j<=10;j++){      
	     	                        m1[i][j]=i*10+j;             //numeracion de las plazaS
				                    printf("|   %d\t",m1[i][j]);
				                    }   
		                       
		                        printf("|\n\n\n\n\n");
		                        break;   
	                        }
	                        while   (k==219){               //fila numerica		       	    
				        	    i=9; //meter en el futuro el cuadrante a partir de la estructura   					
	     	                    for (j=1;j<=10;j++){      
	     	                        m1[i][j]=i*10+j;             //numeracion de las plazaS	     	            
				                    printf("|   %d\t",m1[i][j]);				                       
		                        }
		                        printf("|\n\n\n\n\n");
 	                        	break;
 	                        }
                        }
					    getch();
                        system("cls");
                        repite2=true;                       
                        break;
                        
                    case 3: 	    				
 	    				system("color 0E");
 	    				printf("\n\n\t\t\t\t     PLANTA 3\n\n\n");
 	    				for (k=1;k<=242;k++){ //condicion para crear las plazas  LARGO DEL PARKING				
		                	printf("|\t");  //imprime barras			        	           
		                    while   (k==55){               //fila numerica       DA EL LARGO DE LAS PLAZAS   55 DE COCHE		    
		                	    i=10; //meter en el futuro el cuadrante a partir de la estructura		       	    
	     	                    for (j=1;j<=10;j++){
	     	                        m1[i][j]=i*10+j;
				                    printf("|  %d\t",m1[i][j]);    				        
		                        }
		                        printf("|\n\n\n\n");
		                        break; 
			             	}		            
		                    while   (k==110){               //fila numerica		       	    
				              	i=11; //meter en el futuro el cuadrante a partir de la estructura					
	     	                    for (j=1;j<=10;j++){

	     	                        m1[i][j]=i*10+j;
	     	                        printf("|  %d\t",m1[i][j]);
				                }     		                        
		                        printf("|\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==132){               //fila numerica       DA EL LARGO DE LAS PLAZAS   22 DE MOTO		       	    
				            	i=12; //meter en el futuro el cuadrante a partir de la estructura					
	     	                    for (j=1;j<=10;j++){
	     	                        m1[i][j]=i*10+j;	     	                      	
				                    printf("|  %d\t",m1[i][j]);				                     
		                        }
		                        printf("|\n\n\n\n");
		                        break;   
	                        }	           
	                        while   (k==187){               //fila numerica		       	    
				            	i=13; //meter en el futuro el cuadrante a partir de la estructura  					
	     	                    for (j=1;j<=10;j++){      
	     	                        m1[i][j]=i*10+j;             //numeracion de las plazaS	     	            					            	
				                    printf("|  %d\t",m1[i][j]);				                       
		                        }
		                        printf("|\n\n\n\n");
		                        break;   
	                        }
	                        while   (k==242){               //fila numerica		       	    
				        	    i=14; //meter en el futuro el cuadrante a partir de la estructura  					
	     	                    for (j=1;j<=10;j++){      
	     	                        m1[i][j]=i*10+j;             //numeracion de las plazaS	     	            					        	    
				                    printf("|  %d\t",m1[i][j]);				                       
		                        }
		                        printf("|\n\n\n\n");
 	                        	break;
 	                        } 	                       
                        }                        
                        getch();
                        system("cls");
                        repite2=true;                       
                        break;    
												
                    case 4 :
                    	system("cls");						 
                    	repite2=false;     //si no se pone no deja retroceder despues de haber entrado y retrocedido en en buble de repite2 ya que al salir se le asigna true
						repite=true;   
						
						break;	
						
 	    			default:
	                  	while (opcionplanta!=1 && opcionplanta!=2 ){
	                  		fflush(stdin);   //funcion necesaria para que limpie el buffer y no se repita el default en bucle en caso de indexar una letra en vez de un numero distinto de 1 y 2
	                  		system("cls");
	                  		gotoxy( 20, 20);
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
int buscarPlazaLibre(struct plaza parking[],char tipovehiculo) {
	int i = 1;
	int j,k,l;
	int libre1,libre2,libre3;
	int plazalibre=-1;
	for (i=0;i<=150;i++) {
		if (parking[i].tipo_plaza == tipovehiculo /*|| parking[i].tipo_plaza == tipovehiculo + 32*/) {
			while (parking[i].estado_plaza == 0 && parking[i].planta == 1) {
				libre1 = i;
				j++;
				break;
			}
			while (parking[i].estado_plaza == 0 && parking[i].planta == 2){
				libre2 = i;
				k++;
				break;				
			}
			while (parking[i].estado_plaza == 0 && parking[i].planta == 3){
				libre3 = i;
				l++;
				break;
		    }
		    
		
	    }
	   
	    }
	if (j<k && j<l){////compara las tres plantas para asignar la plaza a la que menos coches tenga
		plazalibre=libre1;
	}
	else if (k<j && k<l){
		plazalibre=libre2;
	}
	else if (l<j || l<k){
		plazalibre=libre3;
	}
	else if (j==k && k==l){
		plazalibre=libre1;
	}
	else if (j>k && k==l){
		plazalibre=libre2;
	}
	else if (k>j && j==l){
		plazalibre=libre1;
	}
	else if (l>j && j==k){
		plazalibre=libre1;
	}
	return plazalibre;
    
}

void leerFichero(char direccion[],struct plaza parking[]) {
	int i;
	FILE*pf;
    pf=fopen (direccion,"r");
    if (pf==NULL){
        printf("Error al abrir el fichero\n");
        return ; // Se termina el programa en este punto
    }

    for (i=1;i<=150;i++){
        fscanf(pf,"%d %d %c %d %s\n", &parking[i].numero_plaza, &parking[i].planta, &parking[i].tipo_plaza, &parking[i].estado_plaza, &parking[i].matricula);
    }
    fclose(pf);
}
/*
} 
void salvarFichero(char nombreFichero[], struct plaza plazas[], int dim) {
	FILE*fichero;
	int i;
	fichero = fopen("plazas.txt", "w");

	if (ferror(fichero)){ // Equivalente a if(ferror(pf)!=0)
    perror("Error de lectura");
    clearerr(fichero);
	}
    else {
		gotoxy( 31, 25); 
		printf("Datos cargados\n");
		return; // return sale del programa
	}

	for (i = 0; i < dim; i++) {
		fprintf(fichero, "%d%d%d %d %c %d %s", &plazas[i].numero_plaza, &plazas[i].planta, &plazas[i].tipo_plaza,&plazas[i].estado_plaza,&plazas[i].matricula);
	}

	fclose(fichero);
}




void clearerr (FILE *fichero);
*/
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 
int fecha(){
 int tiempo;	
 int hora,minutos,dia,mes,ano;	
 time_t t=time(NULL);
 
 struct tm today = *localtime(&t);
 
 hora=today.tm_hour;
 minutos=today.tm_min;
 dia=today.tm_mday;
 mes=today.tm_mon;
 ano=today.tm_year;
 
 gotoxy(63,0);
 printf("%d:%d  %d/%d/%d",hora,minutos,dia,mes+1,ano+1900);
 
 tiempo=hora*60+minutos;
 
 return tiempo;
}

