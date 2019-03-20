#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <windows.h> 

struct plaza{
	int planta;
	int numero_plaza;
	char cuadrante_plaza;
	char tipo_plaza;
	int estado_plaza;
	int fecha_entrada_plaza;
	int fecha_salida_plaza;
};
	
int main(){
	int numerodeplanta;
	printf("selecciona el numero de planta");
	scanf("%d",&numerodeplanta);
	int i,k,j;
	int m1 [5][10];
	
	switch(numerodeplanta){
		case 4:
	  	  
		   for (i=0;i<=5;i++){
	     	    for (j=1;j<=30;j++){
	     	    	m1[i][j]=j;
				    printf("%d",m1[i][j]);
		          	printf("\t");
	     	        printf("|\t");
	     	}
	       }
	    break;   
	    
	    case 1:
	  	  
		   printf("\t");
		   for (i=1;i<=10;i++){
	     	   
				printf("%d",i);
		      	printf("\t");
	     	    printf("|\t");
		        	
			}
	    break;
	
    	case 2:
    	    for	(k=0;k<=10;k++){
	
    	       if (k!=5){	   
		        printf("\t");
	         	printf("|\t");
	           }
		       
		       else{
			        for (i=1;i<=5;i++){
			        	printf("%d",i);
		                printf("\t");
		                printf("|\t");
		            }
	        	}
	    	}
        break; 
        
        case 3:
        
	  	    for	(k=0;k<=10;k++){
	           
    	       if (k!=5){	   
		    
	         	printf("|\t");
	           }
		       
		       else{
			        for (i=1;i<=5;i++){
			        	printf("%d",i);
		                printf("\t");
		                printf("|\t");
		            }
	        	}
	    	}
	    break;
	    
	    case 5:
        
	  	    
		    for (k=0;k<=100;k++){
				
			printf("|\t"); 
			   //las dos primeras filas
	           
		    while   (k==49){               //fila numerica
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
	     	          	
						if (m1[i][j]==19){               //condicion para imprimir el cuadrante
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
	    }
	    	
	    	printf("\n\n\n");
	    	k=22;
	    }
	    
	    
	    	
	    
}

	
