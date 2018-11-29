#include <stdio.h>
#include <string.h>


//declaração de structs

struct candidatos{
   int numero;
   char nome[20];
   char partido[3];
   int votos;
};

//struts
struct candidatos presidente[3];
struct candidatos deputado[8];

//estanciação de funções
void presidentes();
void deputados();

double votos=0.0;

//menu principal
int main(){
	presidentes();
	deputados();
    int escolher=0,i;
  	do
	{
  		printf("escolha a opcao deseja\n");
  		printf("1-votos\n");
  		printf("2-relatorios\n");
  		printf("3-sair\n");
  		scanf("%d",&escolher);
  	    switch(escolher)
        {
          case 1:
             votar();  
          break;
          case 2:
             relatorio();      
          break;
          case 3:
          	system("cls");
          	printf("FIM \n");	
          break;	
          default:
             printf("comando invalido\n");
			 system("pause");
			 system("cls");               
        }
	}while(escolher !=3); 	
	system("pause");
}

//relatorios opções
int relatorio()
{
    system("cls");
	int escolher;
    do{
    printf("Digite a opcao desejado do relatorio\n");
    printf("1- Lista de candidatos \n");
    printf("2- Lista de candidatos com a sua quantidade de votos\n");
    printf("3- Apuracao Percentual de Votos\n");
    printf("4-Quantidade de candidatos eleitos por partido politico\n");
    printf("5-voltar");
    scanf("%d",&escolher);
    switch(escolher)
        {
          case 1:
              listaCandidatos();  
          break;
          case 2:
              votosCandidatos();
          break;
          case 3:
              apuracaoVotos();
          break;
          case 4:
          	  qtdCandPartido();
          break;	
          case 5:
          break;	
		  default:
		      printf("comando invalido\n");
			 system("pause");
			 system("cls");                 
        }
    }while(escolher!=5);
    system("cls");
}

//relatiro - apuração de votos em porcentagem

int apuracaoVotos()
{
   system("cls");
   int i;
   double total; 
   printf("apuracao de votos de cada candidato\n");
   printf("Presidente \n \n");
   printf("numero|  nome| partido |porcentagem de votos\n");
   for(i=0;i<3;i++)
   {
   	 total=((double)presidente[i].votos*100)/votos;
   	 printf("%d | %s | %s |%.2lf % \n",presidente[i].numero,presidente[i].nome,presidente[i].partido,total);
   }
   printf("\n");
   printf("Candidato \n \n");
   printf("numero|  nome| partido |porcentagem de votos\n");
   for(i=0;i<8;i++)
   { 	 
   	 total=( (double)deputado[i].votos * 100)/votos;
   	 printf("%d| %s| %s| %.2lf % \n",deputado[i].numero,deputado[i].nome,deputado[i].partido,total);
   }
   
   system("PAUSE");
   system("cls");
}

//relatorio - Total de votos por candidato
int votosCandidatos()
{   
	int i;
	ordenar();
    system("cls");
    printf("* - candidatos eleitos \n\n");
    
	printf("Presidente \n");
    printf("numero|  nome| partido | cargo | votos\n");
    
	//presidente
    for(i=0;i<3;i++)
    {
                    
      printf("%d %s %s P %d ",presidente[i].numero,presidente[i].nome,presidente[i].partido,presidente[i].votos );                 
      if(i == 0)
      {
         printf("*");  
      }
      printf("\n");
    }
    
    printf("\n\n");
    
    printf("Deputados \n");
    
    printf("numero|  nome| partido | cargo | votos\n");
    for(i=0;i<8;i++)
    {
                    
      printf("%d %s %s P %d ",deputado[i].numero,deputado[i].nome,deputado[i].partido,deputado[i].votos );                 
      if(i <= 2)
      {
         printf("*");  
      }
      printf("\n");
    }
   system("PAUSE");
   system("cls");    
}

//relatorio - lista de candidatos
int listaCandidatos()
{
	system("cls");
    int i; 
    printf("candidatos a presidencia \n");
    printf("numero|  nome| partido | cargo \n");
    for(i=0;i<3;i++)
    {
      printf("%d %s %s P \n",presidente[i].numero,presidente[i].nome,presidente[i].partido);                 
    }
    printf("\n\n");
	 
    printf("candidatos a deputado \n"); 
    printf("numero|  nome| partido | cargo\n"); 
    for(i=0;i<8;i++)
    {
       printf("%d %s %s D \n",deputado[i].numero,deputado[i].nome,deputado[i].partido);                 
    }
    system("PAUSE");
    system("cls");
    
}

//relatório - quantidade de políticos eleitos por patido
int qtdCandPartido()
{
	
	ordenar();
	system("cls");
	int def=0,xyz=0,abc=0,i;
	printf("Quantidade de candidatos eleitos por partido politico\n");
	//presidente
	for(i=0;i<3;i++)
	{
		if(i==0)
		{		
			if(strcmp(presidente[i].partido, "ABC") == 0)
			{
				abc++;
			}
			
			if(strcmp(presidente[i].partido, "XYZ") == 0)
			{
				xyz++;
			}
			
			if(strcmp(presidente[i].partido, "DEF") == 0)
			{
				def++;
			}
		}
    }
	
	//deputado
	for(i=0;i<8;i++)
	{
		if(i<3)
		{		
			if(strcmp(deputado[i].partido, "ABC") == 0)
			{
				abc++;
			}
			
			if(strcmp(deputado[i].partido, "XYZ") == 0)
			{
				xyz++;
			}
			
			if(strcmp(deputado[i].partido, "DEF") == 0)
			{
				def++;
			}
		}
    }
	
	printf("A quantidade de candidatos eleitos do partido ABC foi de %d \n",abc);  
	printf("A quantidade de candidatos eleitos do partido XYZ foi de %d \n",xyz);
	printf("A quantidade de candidatos eleitos do partido DEF foi de %d \n",def);
	
	system("PAUSE");
	system("cls");
}

//votação
int votar()
{
   system("cls");
   int numero,i,y=0;
   while(y < 1)
   {  
      printf("digite o numero de seu candidato a deputado");
      scanf("%d",&numero);
      for(i=0;i<8;i++)
      {
        if(numero==deputado[i].numero )
        {
           deputado[i].votos++;
           y++;
        }            
      }
   }
   while(y == 1)
   { 
      printf("digite o numero de seu candidato a presidencia");
      scanf("%d",&numero);
      for(i=0;i<3;i++)
      {
        if(numero==presidente[i].numero )
        {
           presidente[i].votos++;
           y++;
        }            
      }   
	}
	votos++;
	system("cls");
}

//ordenar por votos do maior para o menor
int ordenar()
{
  int i,y,auxVotos, auxNum;
  char auxNome[20], auxPartido[3];
  //presidente
  for(i=0;i<3;i++)
    {
      for(y=i+1;y<3;y++)
      {
          if(presidente[i].votos < presidente[y].votos)
          {
             auxVotos = presidente[i].votos;
             auxNum = presidente[i].numero;
             strcpy(auxNome , presidente[i].nome);
             strcpy(auxPartido , presidente[i].partido); 
             
             
             presidente[i].votos = presidente[y].votos;
             presidente[i].numero = presidente[y].numero;
             strcpy(presidente[i].nome , presidente[y].nome);
             strcpy(presidente[i].partido , presidente[y].partido);
             
             presidente[y].votos = auxVotos;
             presidente[y].numero =  auxNum ;
             strcpy(presidente[y].nome,auxNome);
             strcpy(presidente[y].partido,auxPartido);                              
          }
       }              
    }
	
	//Deputado
    for(i=0;i<8;i++)
    {
      for(y=i+1;y<8;y++)
      {
          if(deputado[i].votos < deputado[y].votos)
          {
             auxVotos = deputado[i].votos;
             auxNum = deputado[i].numero;
             strcpy(auxNome , deputado[i].nome);
             strcpy(auxPartido , deputado[i].partido); 
             
             
             deputado[i].votos = deputado[y].votos;
             deputado[i].numero = deputado[y].numero;
             strcpy(deputado[i].nome , deputado[y].nome);
             strcpy(deputado[i].partido , deputado[y].partido);
             
             deputado[y].votos = auxVotos;
             deputado[y].numero =  auxNum ;
             strcpy(deputado[y].nome,auxNome);
             strcpy(deputado[y].partido,auxPartido);                              
          }
       }              
    }
    	
}

//cadastro de candidatos a presidente
void presidentes(){
  int i,total=0;
  //numero
  for(i=0;i<3;i++)
  {                            
     presidente[i].numero= total+10;
     total=presidente[i].numero;               
  }  
  //nome
  strcpy(presidente[0].nome , "Jorge");
  strcpy(presidente[1].nome , "Marta"); 
  strcpy(presidente[2].nome , "Sergio");
  //partido
  strcpy(presidente[0].partido , "ABC");
  strcpy(presidente[1].partido , "XYZ"); 
  strcpy(presidente[2].partido , "DEF");

}

//cadastro de candidatos a deputado
void deputados(){
  int i,total=0;
  //numero
  for(i=0;i<8;i++)
  {                            
     deputado[i].numero = 1000+i+1;               
  } 
  //nome
  strcpy(deputado[0].nome , "Bruno");
  strcpy(deputado[1].nome , "Bruna"); 
  strcpy(deputado[2].nome , "Breno");
  strcpy(deputado[3].nome , "Bruno");
  strcpy(deputado[4].nome , "Nani");
  strcpy(deputado[5].nome , "Joao");
  strcpy(deputado[6].nome , "Joana");
  strcpy(deputado[7].nome , "Josmar");
  //partido
  strcpy(deputado[0].partido , "ABC");
  strcpy(deputado[1].partido , "ABC"); 
  strcpy(deputado[2].partido , "XYZ"); 
  strcpy(deputado[3].partido , "XYZ");
  strcpy(deputado[4].partido , "XYZ");
  strcpy(deputado[5].partido , "DEF");
  strcpy(deputado[6].partido , "DEF"); 
  strcpy(deputado[7].partido , "DEF"); 
  
}
