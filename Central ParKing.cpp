#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>  //para usar gotoxy e imprimir por coordenadas
#include <ctime>  //no hace falta creo
#include <time.h>

struct tipos_distintivo {
	char pegatina_cero[1];
	char pegatina_eco[1];
	char pegatina_c[1];
	char pegatina_b[1];
	char sin_pegatina[1];
};

struct plaza {
    int numero_plaza;    //i
	int planta;          //(i/45+1)	
	char tipo_plaza;     // (i/9+65)
	int estado_plaza; 
	char matricula[7]; 
	float hora_entrada;
	float min_entrada;
	float hora_salida;
	float min_salida;
    };
    
struct distintivo {
	char matricula[7];
	char tipo_etiqueta[1];
};

int coincide(struct plaza parking[],int plazaasignada);    
int esDigitoValido(char caracter);    
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int buscarPlazaLibre(struct plaza parking[],char tipovehiculo);
void plazas_de_aparcamiento(struct plaza parking[],int desde,int hasta); 
void leerDistintivo(char direccion2[],struct plaza parking[],struct distintivo ambiental[]);   
int calculartarifa(struct plaza parking[],struct distintivo ambiental[],struct tipos_distintivo pegatinas, int sicoincide);

void leerFichero(char direccion[],struct plaza parking[]);
void salvarFichero(char direccion[],struct plaza parking[]);
void gotoxy(short x, short y);
void fecha();



int main(){
	
 system("mode con: cols=81 lines=55");  // establece el tamaño de pantalla
 int x,y;	
 int opcioninicio,parpadeo,opcionregistro,opcionplanta,plazaasignada,matriculavalida,intentos,sicoincide;
 bool repite,repite2,repite3,repite4;     //establece la variable que permite repite la aparicion del menu con do en caso de defaul (digito no valido)
 int i,k,j;
 int m1 [15][15];	
 char tipovehiculo;	// para el menu
 char direccion[] = "plazas.txt";
 char direccion2[] = "export_distintivo_ambiental.txt";
 float precio;
 char auxmatricula[7];
 struct plaza parking[151];       // 150 de las plazas    la 0 de auxiliar y la sicoincide total 151
 struct distintivo ambiental[257199];
 struct tipos_distintivo pegatinas ={'O','E','C','B','S'};
 time_t t=time(NULL);
 struct tm today = *localtime(&t);
 int nplazas=150; // NO UTIL DE MOMENTO
 gotoxy( 25, 20); 
 printf("Bienvenido a Central Parking\n");
 Sleep(1000);
 gotoxy( 25, 24);
 printf("Cargando datos...\n");
 Sleep(1000);
 leerFichero(direccion,parking); 
 Sleep(500);
 leerDistintivo(direccion2,parking,ambiental);
 Sleep(1000);
 
 system ("cls");
 
 fecha();
 
 
/* 
 for (i=1;i<=5;i++){
 
						
							printf("\n%s \t %s\n", ambiental[i].matricula , ambiental[i].tipo_etiqueta );
}
getchar();
 */
 
 
/*
 for (i=1;i<=150;i++){
 
						
							printf("\n%d %d %c %d %s\n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula);
}
getchar();*/

do{
 system("color 0E"); //varia colorde consola yu letras	
 fecha();
 gotoxy( 22, 10);
 
 printf("\t           INICIO\n\n");
 printf("\t         Escoja entre una de las siguientes opciones:\n\n");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
 printf("\t\t       1 - Registrar Entrada o Salida         \n\n");	
 printf("\t\t       2 - Consultar estado del Parking       \n\n");
 printf("\t\t       3 - Consultar tarifas                  \n\n");

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
                 	case 1:{										
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
                 		if(tipovehiculo== 'C' || tipovehiculo== 'c' || tipovehiculo== 'M' || tipovehiculo== 'm'){
		 				
                 		system("cls");
                 		intentos=3;                                                                    // inicializa intentos con valor 0 para que si sales del menu vuelvas a tener 3 oportunidades cuenta regresiva
                 		plazaasignada=buscarPlazaLibre(parking,tipovehiculo);                          //funcion que busca una plaza en funcion de la ocupacion del parking y del tipo de vehiculo
                	 		if (plazaasignada!=-1){
                	 			do{
                			     	system("color 0E");               				
                			     	fecha();
                    		     	gotoxy(23, 12);
                    		     	printf("Indique la matricula de su vehiculo\n\n\t\t\t\t     ");
                    			 
                    		      	scanf("%s", parking[plazaasignada].matricula); 
                     			
					 		        matriculavalida = esMatriculaValida(parking[plazaasignada].matricula);  // funcion que valida la matricula introducida
							     	sicoincide=coincide(parking,plazaasignada);                             // funcion de coincidencia con matricula ya registrada
																								
                     			    if (matriculavalida == 0 && intentos>0 ){  	    	//cuando no es valida y quedan mas de 0 intentos (al menos 1)=llevas menos de 3 intentos 					    								              
					 					system("color 0C");  //texto se vuelve rojo			
					 					gotoxy(25, 17); 
                    			     	printf("La matricula no es valida\n\n\t\t\t Intentelo de nuevo %d \n",intentos);
                    			     	Sleep(2000);
                    			     	repite4=true;
                    			     	system("cls");
                    			     	intentos--;
                    			     	/*break;*/ //no lo ponemos para uqe no cierre el bucle do while
					 				    }
                     			    else if ((matriculavalida ==1 || matriculavalida==2) && intentos>0 && sicoincide==0){	   //cuando es valida y quedan mas de 0 intentos (al menos 1)=llevas menos de 3 intentos y es distinta de las que ya estan en el parking(no coincide)						 
                     			        parking[plazaasignada].estado_plaza=1;                         //asigna un 1(ocupada) a la plaza asignada
                     			        parking[plazaasignada].hora_entrada=today.tm_hour;                   //coge fecha actual para la plaza asignada
                     			        parking[plazaasignada].min_entrada=today.tm_min;
					   					gotoxy(24, 17);                  			
                     			        printf("Vehiculo aparcado correctamente\n");
                     			        Sleep(2000);
                     			        salvarFichero(direccion,parking);                              //guarda en el fichero los cambios
                     			        repite3=true;                    			        
					 					system("cls");
					 					break;  	//necesario									   										               			                                        			
                     		            }
                     		        else if (sicoincide!=0){                                           //cuando coincide con una matricula ya en el parking    
		 				 			    system("color 0C");
			 							gotoxy(24, 17);
									 	printf("El vehiculo ya esta en el parking");
									 	Sleep(2000);           		         	
                    		         	repite3=true;                    			        
					 					system("cls");
					 					break;
						 	    		}
                     		        else if (intentos<1){                                              //cuando no te quedan intentos
                    		         	system("color 0C");
                    		         	gotoxy(24, 17); 
                    			     	printf("Se ha quedado sin intentos\n");
                    			     	Sleep(2000);
                    		         	repite3=true;
                    			     	system("cls");  
		 								break;                    		         	
					 				    }							    	
                     	    	}
                     		    while(repite4);
                     		getchar();    //necesario para pausar tras aparcado correctamente
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
			 		    }
			 		    else{
		 			    	system("cls");
		 			    	repite3=true;
			 			}              	               						               		
			 	        break;
			         	}
			 	    case 2 :{
                 		intentos=3;  
				 		do{
				 		    system("color 0E");
                     		fecha();
                     		gotoxy(0, 12);  
                     		printf("\t\t               2-RECOGER VEHICULO             \n\n");
                  		
                     		printf("\t\t      Indique la matricula de su vehiculo\n\n\t\t\t\t"); 
                 		
                            gotoxy(28, 17); 				
                    		
                    		     	    
                    			 
                    		scanf("%s", parking[0].matricula);                          //uso el 0 de la estructura parking como almacenamiento temporal para la matricula que bamos a comparar con el resto( del 1 al 150)
                    			
						 	matriculavalida = esMatriculaValida(parking[0].matricula);  // funcion que valida la matricula introducida
							sicoincide=coincide(parking,0);                             // funcion de coincidencia con matricula ya registrada
																								
                    	 	if (matriculavalida == 0 && intentos>0 ){  		//	cuando es validay llevas menos de 3 intentos	o no coincide con ninguna matricula registrada					    								              
						 		system("color 0C");  //texto se vuelve rojo			
						 		gotoxy(25, 19); 
                    			printf("La matricula no es valida\n\n\t\t\t Intentelo de nuevo %d \n",intentos);
                    			Sleep(2000);
                    			repite4=true;
                    			system("cls");
                    			intentos--;
                    			/*break;*/ //no lo ponemos para uqe no cierre el bucle do while
					 		}
                     		else if (matriculavalida ==1 && intentos>0 && sicoincide!=0){	   //cuando es invalida o mas de 3 intentos	
                     			for(i=0;i<=7;i++){                                          //escribe guiones para la matricula vacia
                     			    if(i!=7){
                    	 		       	parking[sicoincide].matricula[i] = '-';                    			        		
							 		}
                     			    else {
				 					parking[sicoincide].matricula[i] = 0 ;
							 			}                    			        	
							 	}															 
                    	 	    parking[sicoincide].estado_plaza=0;                         //asigna un 1(ocupada) a la plaza en la que coincide con la 0 que es la auxiliar
                    	 		parking[sicoincide].hora_salida=today.tm_hour;                   //coge fecha actual para a plaza en la que coincide con la 0 que es la auxiliar
                    	 		parking[sicoincide].min_salida=today.tm_min;
						 		gotoxy(24, 17);     
										 
										 
								precio=calculartarifa(parking,ambiental,pegatinas,sicoincide); 
								printf("%.0f %0.f %.0f %0.f\n",parking[sicoincide].hora_entrada,parking[sicoincide].hora_salida,parking[sicoincide].min_entrada,parking[sicoincide].min_salida);
								printf("%0.f",precio); 
								Sleep(6000); 
										 
										 
								if(parking[sicoincide].tipo_plaza='C') {
									printf("Coche retirado correctamente\n");
								}
								else if(parking[sicoincide].tipo_plaza='M') {
									printf("Moto retirada correctamente\n");
								}              			
                    	 		        
                    	 		Sleep(2000);
                    	 		salvarFichero(direccion,parking);                              //guarda en el fichero los cambios
                    	 		repite3=true;                    			        
						 		system("cls");
						 		break;  	//necesario									   										               			                                        			
                    	 	    }
                    	 	else if (sicoincide==0 && intentos>1){                                           //cuando es igual a una matricula ya en el parking    
		 				 		system("color 0C");
			 					gotoxy(24, 17);
								printf("El vehiculo no esta en el parking");
								Sleep(2000);           		         	
                    		    repite3=true;                    			        
					 			system("cls");
		     					break;
						 	    }
                    	 	        
                    	 	else if (intentos<1){                                              //cuando no te quedan intentos
                    		    system("color 0C");
                    		    gotoxy(24, 17); 
                    			printf("Se ha quedado sin intentos\n");
                    			Sleep(2000);
                    		    repite3=true;
                    			system("cls");  
		 						break;                    		         	
		 						}							    	
                    	}
                    	while(repite4);																			
		 		        					    	
	 					break;
	 				    }				    	
		 		    case 4 :{
                     	system("cls");
			 			repite4=false;						 
                     	repite3=false;     //si no se pone no deja retroceder despues de haber entrado y retrocedido en en buble de repite3 ya que al salir se le asigna true
			 			repite=true;   						
		 				break;
		 			    }
			     	}
	 		}
	 		while(repite3);                              	     	    	
 	    	break; 	  
			   	
     	case 2:{
  		
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
 	    		gotoxy(22, 13);     
 	    	    printf("2 - CONSULTAR ESTADO DEL PARKING\n\n");
 	    	    Sleep(500);
 	    		printf("\t          Grafico: Seleccione el numero de planta.\n\n");
 	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
 	    		printf("\t\t          1          2          3          \n\n\n");
 	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
 	    		printf("\t    Listado: Seleccione el numero de planta equivalente.\n\n");
 	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
 	    		printf("\t\t         11         12         13          ");
 	    		
 	    		gotoxy(32, 52);
 	    		printf("4 - Volver\n");
 	    		scanf ("%d",&opcionplanta);
 	    		system("cls");
			  	    	    		
 	    		switch(opcionplanta) {
 	    			case 1:{	    				
 	    				system("color 0E");
 	    				printf("\n\n\t\t\t\t     PLANTA 1\n\n\n");
 	    				plazas_de_aparcamiento(parking,1,11); 
 	    				plazas_de_aparcamiento(parking,11,21); 
 	    				plazas_de_aparcamiento(parking,21,31); 
 	    				plazas_de_aparcamiento(parking,31,41); 
 	    				plazas_de_aparcamiento(parking,41,51);
	 					getch();
	 					system("cls");
	 					repite2=true;
	 					break;
	 					}
		 			case 2:{
                    	system("color 0E");
 	    				printf("\n\n\t\t\t\t     PLANTA 2\n\n\n");                    	
                    	plazas_de_aparcamiento(parking,51,61); 
 	    				plazas_de_aparcamiento(parking,61,71); 
 	    				plazas_de_aparcamiento(parking,71,81); 
 	    				plazas_de_aparcamiento(parking,81,91); 
 	    				plazas_de_aparcamiento(parking,91,101); 	    				
	 				    getch();
	 					system("cls");
	 					repite2=true;
	 					break;
		 				}
		 			case 3:{												    				
 	    				system("color 0E");
 	    				printf("\n\n\t\t\t\t     PLANTA 3\n\n\n"); 	    			
 	    				plazas_de_aparcamiento(parking,101,111);  
 	    				plazas_de_aparcamiento(parking,111,121);
 	    				plazas_de_aparcamiento(parking,121,131);
 	    				plazas_de_aparcamiento(parking,131,141);
 	    				plazas_de_aparcamiento(parking,141,151);
	 					getch();
	 					system("cls");
	 					repite2=true;
	 					break;    
			         	}
                    case 4:{
                     	system("cls");						 
                     	repite2=false;     //si no se pone no deja retroceder despues de haber entrado y retrocedido en en buble de repite2 ya que al salir se le asigna true
		 				repite=true;   						
		 				break;	
		 		    	}
		 		    case 11:{
		 		    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		 		    	printf("\n\n   N Plaza     Planta     Tipo Plaza     Estado     Matricula     Hora entrada   \n\n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada);
		 		    	for (i=1;i<=50;i++){ 
					     	if(parking[i].estado_plaza==0){						
				         		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					     		printf("     %2d          %d            %c            %d         %s         %0.f:%2.f    \n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada,parking[i].min_entrada);							
				     		}
				     		if(parking[i].estado_plaza==1){
							    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
                             	printf("     %2d          %d            %c            %d         %s         %0.f:%2.f    \n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada,parking[i].min_entrada);
				         	} 
	 					}
	 					getch();
	 					system("cls");
	 					repite2=true;
	 					break;						 	
		 		    	}
		 		    case 12:{
		 		    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		 		    	printf("\n\n   N Plaza     Planta     Tipo Plaza     Estado     Matricula     Hora entrada   \n\n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada);
		 		    	for (i=51;i<=100;i++){ 
					     	if(parking[i].estado_plaza==0){						
				         		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					     		printf("    %3d          %d            %c            %d         %s         %0.f:%2.f    \n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada,parking[i].min_entrada);							
				     		}
				     		if(parking[i].estado_plaza==1){
							    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
                             	printf("    %3d          %d            %c            %d         %s         %0.f:%2.f    \n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada,parking[i].min_entrada);
				         	}
	 					}
	 					getch();
	 					system("cls");
	 					repite2=true;
	 					break;						 	
		 		    	}
					case 13:{
		 		    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		 		    	printf("\n\n   N Plaza     Planta     Tipo Plaza     Estado     Matricula     Hora entrada   \n\n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada);
		 		    	for (i=101;i<=150;i++){ 
					     	if(parking[i].estado_plaza==0){						
				         		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
					     		printf("     %2d          %d            %c            %d         %s         %2.f:%2.f    \n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada,parking[i].min_entrada);							
				     		}
				     		if(parking[i].estado_plaza==1){
							    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
                             	printf("     %2d          %d            %c            %d         %s         %0.f:%2.f    \n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada,parking[i].min_entrada);
				         	}
	 					}
	 					getch();
	 					system("cls");
	 					repite2=true;
	 					break;						 	
		 		    	}	 							 	
 	    			default:{					
	                  	while (opcionplanta!=1 && opcionplanta!=2 ){
	                  		fflush(stdin);   //funcion necesaria para que limpie el buffer y no se repita el default en bucle en caso de indexar una letra en vez de un numero distinto de 1 y 2
	                  		system("cls");
	                  		gotoxy( 20, 20);
		                    printf("Por favor, introduce una opcion valida\n");
	     	                Sleep(1500);
	     	                system("cls");
	     	                repite2=true;
						 	break;						 	 			    	    		
	 		                }
		 				}
     				}	
	 		}
 	    	while (repite2);
	 		break;
	 		}
	 		
    	case 3:{
			
    		/*for (parpadeo=220; parpadeo>=0;parpadeo--){
				
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
            }*/
    		
 	    	printf("3 - Consultar tarifas\n");	
		    break;	
	    	}
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
int coincide(struct plaza parking[], int plaza){
	int i,coincide;		
	coincide=0;
	while(i<150 && i!=plaza){
	
		
		if( strcmp(parking[i].matricula,parking[plaza].matricula)==0){		// if si coincide 
		    /*coincide=1;*/
		    coincide=i; //se añade para que la funcion sirva para registrar la salida del parking ya que necesitamos saber que plaza es la quie coincide para cambiar su estado
		                //tambien modificamos las condiciones y en sicoincide==1 ponemos sicoincide!=0
		    
		    
		    break;
	    }			
    	else{
 	    	coincide=0;
 	    	i++;
    	}  
}
	return coincide;
}	
int buscarPlazaLibre(struct plaza parking[],char tipovehiculo) {
	char direccion[]= "plazas.txt";
	leerFichero(direccion,parking); //necesitamos que lea de nuevo el fichero para acctualizar la informacion de cuantos coches hay en cada planta y que sirva la comparacion si no se quedaria con la informacion previa a asignar la plaza y siempre la asignaria en la misma planta
	system("cls"); //para que no salga en pantalla datos cargados
	int i ;
	int j,k,l;
	int libre1,libre2,libre3;
	int plazalibre=-1;
	j=0;
	k=0;
	l=0;
	for (i=1;i<=50;i++) {
		if ( parking[i].estado_plaza == 1 && parking[i].planta == 1) { 		//cuenta los coches aparcados en la 1 planta	
		 	j++;
		}
	}	
	for (i=51;i<=100;i++) {
			
		if ( parking[i].estado_plaza == 1 && parking[i].planta == 2){
			k++;
		}
	}		
	for (i=101;i<=150;i++) {			    	
		if (parking[i].estado_plaza == 1 && parking[i].planta == 3){	
			l++;
			
    	}
	}///si no funciona hacer el bucle for por plantas de 1 a 50  50 100  100 150
	    
	 ////compara las tres plantas para asignar la plaza a la que menos coches tenga  	    
	if (j<k && j<l){ //si en la 1 hay menos aparca ahi
	    for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 1)){//-32 por si se digita en tipovehiculo una c para que sea igual que C
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	else if (k<j && k<l){//si en la 2 hay menos aparca ahi
		for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 2)){
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	else if (l<j && l<k){//si en la 3 hay menos aparca ahi
		for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 3)){
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	else if (j==k && k==l){//si en todas hay los mismos aparca en la 1
		for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 1)){
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	else if (j>k && k==l){//si en la 1 hay mas y en las otras hay los mismos aparca en la 2
		for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 2)){
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	else if (k>j && j==l){//si en la 2 hay mas y en las otras hay los mismos aparca en la 3
		for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 3)){
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	else if (l>j && j==k){//si en la 3 hay mas y en las otras hay los mismos aparca en la 1
		for (i=0;i<=150;i++){
	    	if ((parking[i].tipo_plaza == tipovehiculo || parking[i].tipo_plaza == tipovehiculo - 32) && (parking[i].estado_plaza == 0 && parking[i].planta == 1)){
	    		plazalibre=i;
	    		break;
			}
		}
		
	}
	/*printf("%d %d %d",j,k,l);*/   //para ver si funciona lo anterior en la funcion indica el numero de vehiculos por planta
	
	return plazalibre;
    }
int esDigitoValido(char caracter) {
	if (caracter >= '0' && caracter <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}
int esLetraValida(char caracter) {
	if (caracter >= 'a' && caracter <= 'z') {
		caracter = caracter - 32;
	}
	if (caracter > 'A' && caracter <= 'Z' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U') {
		return 1;
	}/*
	if(caracter > 'A' && caracter <= 'K' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U') {
		return 2;
	}*/
	else {
		return 0;
	}
}
int esMatriculaValida(char matricula[]) {
	int mvalida = 1, i, numero,longitud;
	for (i = 0; i < 7; i++) {
		if (i < 4) {
			numero = esDigitoValido(matricula[i]);
			if (numero == 0) {
				mvalida = 0;
			}
		}/*
		else if (i=4){
			numero = esLetraValida(matricula[i]);
			if (numero == 0 || numero==1) {
				mvalida = 0;
			}*/
		else if (i>4){
			numero = esLetraValida(matricula[i]);
			if (numero == 0 ) {
				mvalida = 0;
			}
		}
	}
	longitud=strlen(matricula); //compara la longitud de la matricula y si es mayor que 7 no es valida
	if (longitud > 7){
		mvalida = 0;
	}
		


	return mvalida;
}

void plazas_de_aparcamiento(struct plaza parking[],int desde,int hasta){
	int i,k,largodeplaza;
	k=0;
	if(parking[desde].tipo_plaza=='C'){
		largodeplaza=5;                        //con el valor de 5 imprime de largo 5 caracteres usadas para el coche y 3 para moto
	}
	else if (parking[desde].tipo_plaza=='M'){
		largodeplaza=3;
	}
	
	while(k<largodeplaza){
							 		
							 for (i=desde;i<=hasta;i++){                                             //bucle para "dibujar" las plazas por bloques segun el tipo
							 
						     	if(parking[i].estado_plaza==1 && i!=hasta){                           //dibuja las ocupadas
						         	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);	
						        	printf("|");
						        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 200);
						        	printf("       ");
						        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);
						        }
							 	else if (parking[i].estado_plaza==0 && i!=hasta) {                    //dibuja las libres
							     	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);	
						        	printf("|");
						        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
						         	printf("       ");
						        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);	
								}
								else if(i==hasta){								
							     	printf("|\n");
							    	k++;								
						    	    break;
						     	}
					    	    }
					        }
	if (k==largodeplaza){
						        
			 				    for (i=desde;i<=hasta-1;i++){
			 		
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);	
						    	printf("|");
						    		
						         	if(parking[i].estado_plaza==1 && i!=hasta){                           
			 	    			        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);    //ocupadas    207 letra blanca 
			 	    			        printf("  %3d  ",i);
					 	            	}
			 			            if(parking[i].estado_plaza==0 && i!=hasta){
			 			    	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);     //libres
			 			        	    printf("  %3d  ",i);		 			                           //un espacio menos precede al numero de plaza   	    								
						            	}                                           
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);	
						        }
						    	
	}
	printf("|\n\n\n\n");
}
	



void leerDistintivo(char direccion2[],struct plaza parking[],struct distintivo ambiental[]){
	int i;
	FILE*fp;
	fp=fopen (direccion2,"r");
	if (fp==NULL){
        printf("Error al abrir el fichero\n");
        return ; // Se termina el programa en este punto
    } 
 for (i=1;i<=257199;i++){
        fscanf(fp,"%s %s\n", &ambiental[i].matricula , &ambiental[i].tipo_etiqueta );
    }
    gotoxy( 25, 29);
    printf("Distintivos ambientales   OK\n");
    
    
    fclose(fp);
}
 //dentro de recoger coche si la operacion es corecta se despliega automaticamente el ticket


int calculartarifa(struct plaza parking[],struct distintivo ambiental[],struct tipos_distintivo pegatinas, int sicoincide){
	int i;
	float precio;
	for (i=0;i<=257199;i++){
	
	     if(parking[sicoincide].matricula==ambiental[i].matricula){
	     	if(strcmp(ambiental[i].tipo_etiqueta,pegatinas.pegatina_cero)==0){
	     		precio=((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))+((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada));
	     		break;
			 }
			else if(strcmp(ambiental[i].tipo_etiqueta,pegatinas.pegatina_eco)==0){
				precio=((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))+((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))*1/4 ;
				break;
			 }
			else if(strcmp(ambiental[i].tipo_etiqueta,pegatinas.pegatina_c)==0){
				precio=((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))+((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))*7/20 ;
				break;
			 }
			else if(strcmp(ambiental[i].tipo_etiqueta,pegatinas.pegatina_b)==0){
				precio=((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))+((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))*9/20 ;
				break;
			 }			
		    else if(strcmp(ambiental[i].tipo_etiqueta,pegatinas.sin_pegatina)==0){
		    	precio=((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))+((parking[sicoincide].hora_salida - parking[sicoincide].hora_entrada)*60+(parking[sicoincide].min_salida - parking[sicoincide].min_entrada))*11/20 ;
		    	break;
			 }
		 }
	
}
return precio;
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
        fscanf(pf,"%d %d %c %d %s %f %f\n", &parking[i].numero_plaza, &parking[i].planta, &parking[i].tipo_plaza, &parking[i].estado_plaza, &parking[i].matricula,&parking[i].hora_entrada, &parking[i].min_entrada);
    }
    gotoxy( 25, 27);
    printf("Estado del Parking        OK\n");
    
    
    fclose(pf);
}
void salvarFichero(char direccion[],struct plaza parking[]) {
	int i;
	FILE*pf;
    pf=fopen ("plazas.txt","w");   //donde    "plazas.txt" deberia ir  direccion pero no sobreescribe el archivo
    if (pf==NULL){
        printf("Error al abrir el fichero\n");
        return ; // Se termina el programa en este punto
    }

    for (i=1;i<=150;i++){
        fprintf(pf,"%d %d %c %d %s %0.f %2.f\n", parking[i].numero_plaza, parking[i].planta, parking[i].tipo_plaza, parking[i].estado_plaza, parking[i].matricula,parking[i].hora_entrada, parking[i].min_entrada);
    }
    fclose(pf);
}
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 
void fecha(){
 int tiempo;	
 int dia,mes,ano;	
 float hora,minutos;
 time_t t=time(NULL);
 
 struct tm today = *localtime(&t);
 
 hora=today.tm_hour;
 minutos=today.tm_min;
 dia=today.tm_mday;
 mes=today.tm_mon;
 ano=today.tm_year;
 
 gotoxy(63,0);
 if(minutos<10){
 	printf("%.0f:0%.0f  %d/%d/%d",hora,minutos,dia,mes+1,ano+1900);
 }
 else{
 printf("%.0f:%.0f  %d/%d/%d",hora,minutos,dia,mes+1,ano+1900);
}
 
 
}

