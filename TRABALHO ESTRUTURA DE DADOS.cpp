#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


struct cadastrar
{
	char nome_materia[50];
	int codigo_m;
	
}reg[3];

struct Aluno 
{
	char nome_aluno[50];
	int cod_aluno;
	char nome_mat[50];
	int cod_mat;
	char conceito[50];
	
}estudante[3];

struct lancar_nota
{
	float av1;
	float av2;
	float av3;


}notas[3];

int j,i,procura_codigo,opcao,ac = 0;
char procura_nome[100];


int cadastrar_disciplina();
int cadastrar_Aluno();
int lancar_nota();
int alterar_nota();
int relatorio_estudantes();


int main()
{
	setlocale(LC_ALL,"portuguese");
	int opc;
	
	for(i=0;i<=2;i++)
   {
   	 notas[i].av1 = -1;
   	 notas[i].av2 = -1;
   	 notas[i].av3 = -1; 
   }
	
  do{
  	
     system("cls");
  	 printf("\n Digite [1] CADASTRAR DISCIPLINA  \n");
  	 printf("\n Digite [2] CADASTRAR ALUNO \n ");
  	 printf("\n Digite [3] LANÇAR NOTA \n");
  	 printf("\n Digite [4] ALTERAR NOTA \n");
  	 printf("\n Digite [5] RELATÓRIO DOS ESTUDANTES \n");
  	 printf("\n Digite [6] FIM \n");
  	 printf("\n Escolha sua opcao: ");
  	 scanf("%d", &opc);
  	 
  	 
  	switch(opc)
  	{
  		case 1 : cadastrar_disciplina ();
  				 break;
  			         	 
		case 2 : cadastrar_Aluno ();
		         break;
		    
					 
		case 3 : lancar_nota();
			  	 break;		     
  			         
	    case 4 :alterar_nota();
	       	    break;
	    
		case 5 :relatorio_estudantes();
				break;
		
		case  6 : 
		       printf(" ----  FIM ------");
		       break;
		     
		default : printf("\n Opção não encontrada \n");     
			            	  
  }
  
  }while(opc!=6);
}

cadastrar_disciplina ()
{
	printf("\n ***CADASTRO DE DISCIPLINA *** \n");
	for (i=0; i<=2; i++)
	{
		printf("\n Digite o %dº nome da Disciplina: ", i+1);
		fflush (stdin);
		gets (reg[i].nome_materia);
		strupr(reg[i].nome_materia);
		printf("\n Digite o %dº seu código da Matéria: ",i+1);
		scanf("%d",&reg[i].codigo_m );
	}
	return(0);
}

cadastrar_Aluno ()
{
	int teste,cont = 0;
	
	printf("\n ***CADASTRO DE ALUNOS *** \n");
	
	for (i=0; i<=2; i++)
	{
		printf ("\n Digite o %d° nome: ", i+1 );
		fflush (stdin);
		gets (estudante[i].nome_aluno);
		strupr(estudante[i].nome_aluno);
		printf("\n Digite o seu código: ");
		scanf("%d",&estudante[i].cod_aluno );
		printf("\n Digite 1 para escrever o nome da materia \n ou 2 para o codigo dela, que voce esta estudando\n");
		scanf("%d",&teste);
		
		while(teste == 1)
		{
		printf("Materia : \n");
		fflush(stdin);
		gets(estudante[i].nome_mat);
		strupr(estudante[i].nome_mat);
		
		for(j=0; j<=2; j++)
		{
		  if(strcmp(estudante[i].nome_mat,reg[j].nome_materia) == 0)
		  {
		    teste = -1;
		  }
		  
		  else 
		  cont = cont + 1;
		}
		if(cont==3)
		{
		printf("\n Materia nao encontrada \n");
		teste == 1;
		}
		
		
		}
		
	  while(teste == 2)
	  {
		printf("Codigo: \n");
		scanf("%d",&estudante[i].cod_mat);  
		  for(j=0;j<=2;j++)
		  {
		     if(estudante[i].cod_mat == reg[j].codigo_m)
		     {
		       teste = -1;
		     }
		     
		     else
		     cont = cont + 1;
		  }
		  if(cont==3)
		  {
		  printf("\n Materia nao encontrada \n");
		  teste = 2;
		  }
	   }
	
	}
	return (0);
}

lancar_nota()
{ 	
	printf("\n ***LANÇAR NOTAS *** \n");
	printf("\n [1] Digite 1 para procurar pelo nome \n");
	printf("\n [2] Digite 2 para procurar pelo codigo \n");
	printf("\n Digite qualquer outra tecla para sair \n");
	scanf("%d",&opcao);
	
	switch(opcao)
	{
		case 1 :
		
		 printf("\n Digite o nome que voce quer procurar \n");
     	 scanf("%s",&procura_nome);
     	 strupr(procura_nome);
     	 
			for(i=0; i<=2;i++)
			{
	
				if(strcmp(procura_nome, estudante[i].nome_aluno) == 0)
				{
	
	 			printf("\n Digite a primeira nota : \n");
	 			scanf("%f",&notas[i].av1);
	
	 			printf("\n Digite a segunda nota : \n");
	 			scanf("%f",&notas[i].av2);
	
	 			printf("\n Digite a terceira nota : \n");
	 			scanf("%f",&notas[i].av3);
    			}
				
						
    		}  
    	 break;	
    	 
    	 case 2 : 
    	 	printf("\n Digite o codigo que voce quer procurar \n");
     		scanf("%d",&procura_codigo);
     		
     		for(i=0; i<=2;i++)
			{
	
				if(procura_codigo == estudante[i].cod_aluno)
				{
	
    	
	 			printf("\n Digite a primeira nota : \n");
	 			scanf("%f",&notas[i].av1);
	
	 			printf("\n Digite a segunda nota : \n");
	 			scanf("%f",&notas[i].av2);
	
	 			printf("\n Digite a terceira nota : \n");
	 			scanf("%f",&notas[i].av3);
    			}
						
    		}
     	 break;			   
    }
    for(i=0;i<=2;i++)
	{	
		if(notas[i].av1 >= 0  )
		{
			printf("\n As notas do %dº aluno  são : \n",i + 1);
			
			printf("\n Nota 1 - %2.1f \n",notas[i].av1);
			printf("\n Nota 2 - %2.1f \n",notas[i].av2);
			printf("\n Nota 3 - %2.1f \n",notas[i].av3);
			ac = i;
		}			
	}
	if(notas[0].av1 <0)
	{
	  printf("\n Notas do primeiro aluno não encontradas \n");	
	}	
	if(notas[1].av1 <0)
	{
	  printf("\n Notas do segundo aluno não encontradas \n");	
	}
	if(notas[2].av1 <0)
	{
	  printf("\n Notas do terceiro aluno não encontradas \n");		
	}
     return (0);
}

alterar_nota()
{
	printf("\n ***ALTERAR NOTAS *** \n");
	printf("\n [1] Digite 1 para procurar pelo nome \n");
	printf("\n [2] Digite 2 para procurar pelo codigo \n");
	printf("\n Digite qualquer outra tecla para sair \n");
	scanf("%d",&opcao);
	
	  switch(opcao)
	  {
	   case 1 :	
		   printf("\n Digite o nome que voce quer procurar \n");
     	   scanf("%s",&procura_nome);
     	   strupr(procura_nome);
     	   
     	   	for(i=0; i<=2;i++)
			{
				if(strcmp(procura_nome, estudante[i].nome_aluno) == 0)
				{
					if(notas[i].av1 >= 0  )
					{	
						printf("\n Nota 1 - %2.1f \n",notas[i].av1);
						printf("\n Nota 2 - %2.1f \n",notas[i].av2);
						printf("\n Nota 3 - %2.1f \n",notas[i].av3);
						ac = i;
					}
				}
			}
			
			printf("\n Escolha a Nota a ser substituida \n");
			printf("\n [1] Nota 1 \n");
			printf("\n [2] Nota 2 \n");
			printf("\n [3] Nota 3 \n");
			scanf("%d",&opcao);
			
			switch(opcao)
			{
				case 1 : 
						 notas[ac].av1 = 0;
						 printf("\n Digite a nova nota 1 \n");
						 scanf("%f",&notas[ac].av1);				
				break;
				
				case 2 : printf("\n Digite a nova nota 2 \n");
						 scanf("%f",&notas[ac].av2);				
				break;
						
				case 3 : printf("\n Digite a nova nota 3 \n");
						 scanf("%f",&notas[ac].av3);				
				break;
			}
	   printf("\n Notas atualizadas do aluno %d \n",ac);
	   printf("\n %2.1f \n",notas[ac].av1);
	   printf("\n %2.1f \n",notas[ac].av2);
	   printf("\n %2.1f \n",notas[ac].av3);		
	   break;
	   
	   case 2 : 	
	   		printf("\n Digite o codigo que voce quer procurar \n");
     		scanf("%d",&procura_codigo);
     		
     		 for(i=0; i<=2;i++)
			 {
				if(procura_codigo == estudante[i].cod_aluno)
				{ 
					if(notas[i].av1 >= 0  )
					{	
						printf("\n Notas atuais do aluno %d \n",i+1);
						printf("\n Nota 1 - %2.1f \n",notas[i].av1);
						printf("\n Nota 2 - %2.1f \n",notas[i].av2);
						printf("\n Nota 3 - %2.1f \n",notas[i].av3);
						ac = i;
					}	
				}	
			}
			printf("\n Escolha a Nota a ser substituida \n");
			printf("\n [1] Nota 1 \n");
			printf("\n [2] Nota 2 \n");
			printf("\n [3] Nota 3 \n");
			scanf("%d",&opcao);
				switch(opcao)
				{
					case 1 : 
					printf("\n Digite a nova nota 1 \n");
					scanf("%f",&notas[ac].av1);				
					break;
				
					case 2 : 
					printf("\n Digite a nova nota 2 \n");
					scanf("%f",&notas[ac].av2);				
					break;
						
					case 3 : 
					printf("\n Digite a nova nota 3 \n");
					scanf("%f",&notas[ac].av3);				
			    	break;
				}
		printf("\n Notas atualizadas do aluno %d \n",ac);
		printf("\n %2.1f \n",notas[ac].av1);
		printf("\n %2.1f \n",notas[ac].av2);
		printf("\n %2.1f \n",notas[ac].av3);	
		break;							
	   }
	
	return(0);
} 

relatorio_estudantes()
{   
	printf("\n ***RELATORIO DE ESTUDANTES *** \n");
	float media;
	int contador;
	
	for(i=0;i<=2;i++)
	{
	   contador = 0;	
	   media = 0;	
	   printf("\n O codigo o %dº aluno é : %d \n",i+1,estudante[i].cod_aluno);
	   printf("\n O nome do %dº aluno é : %s \n",i+1,estudante[i].nome_aluno);
	   printf("\n A disciplina que o %dº aluno estuda é : %s \n",i+1,estudante[i].nome_mat);
	   printf("\n A 1º nota do %dº aluno é : %2.1f \n",i+1,notas[i].av1);
	   printf("\n A 2º nota do %dº aluno é : %2.1f \n",i+1,notas[i].av2);
	   printf("\n A 3º nota do %dº aluno é : %2.1f \n",i+1,notas[i].av3);
	   media = (notas[i].av1 + notas[i].av2 + notas[i].av3)/3;
	   printf("\n A media do %dº aluno é : %2.1f \n" ,i+1,media);
	   
	   if(media >=8.5 && media <=10.0)
	   {
	     printf("\n Conceito do  %dº aluno é A \n",i+1);
	   }
	   if(media >= 7.0 && media <=8.4)
	   {
	    printf("\n Conceito do  %dº aluno é B \n",i+1);
	   }
	   if(media >= 6.0 && media <=6.9)
	    {
	    printf("\n Conceito do  %dº aluno é C \n",i+1);
	   }
	   if(media >= 4.0 && media <=5.9)
	   {
	    printf("\n Conceito do  %dº aluno é D \n",i+1);
	   }
	   if(media < 4 )
	   {
	    printf("\n Conceito do  %dº aluno é F \n",i+1);
	   }
	   
	   
	   if(media < 6 && media >3)
	   printf("\n Aluno reprovado por nota \n");

	   if(media<3)
	   printf("\n Aluno reprovado por falta \n");

	   if(media>=6)
	   printf("\n Aluno Aprovado \n");	
	   
	   printf("\n ----------------------- \n");

	}
	
		return(0);
}

