#include <stdio.h>  //biblioteca de comunica��o com o usu�rio (io = input/output)
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //Fun��o destinada a registrar novos usu�rios no sistema
{
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o CPF a ser cadastrado: "); //In�cio do question�rio para coleta de informa��es do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia valores das strings
	
	FILE *fp;
	fp = fopen(arquivo,"w"); //Abrir (criar) arquivo ("w": write)
	fprintf(fp,"\tCPF: %s \n", cpf); //Salvar valor da vari�vel no arquivo
	fclose(fp); //Fechar arquivo

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	fp = fopen(arquivo,"a"); //Abrir ("a": append)
	fprintf(fp,"\tNome completo: %s ",nome);
	fclose(fp); //Fechar
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	fp = fopen(arquivo,"a");
	fprintf(fp,"%s \n",sobrenome);
	fclose(fp);
	
	printf("Digite o cargo da pessoa a ser cadastrada: ");
	scanf("%s",cargo);
	
	fp = fopen(arquivo,"a");
	fprintf(fp,"\tCargo: %s \n",cargo);
	fclose(fp);

	printf("\n\n");

	system("pause");
}

int consulta() //Fun��o destinada a buscar usu�rios que j� fazem parte do sistema
{
	char cpf[40];
	char cadastro[200];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o CPF a ser consultado: "); //Primer key: CPF
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *fp;
	fp = fopen(cpf, "r");
	
	if(fp == NULL){
		printf("O CPF digitado n�o est� cadastrado no sistema. \n");
	}
		else{
			printf("Informa��es do Registro: \n\n");	
		}
	
	while(fgets(cadastro,200,fp) != NULL){ //Busca informa��es associadas ao CPF digitado
			printf("%s", cadastro);
	}
	
	fclose(fp);
	
	printf("\n\n");
	
	system("pause");
	
}

int deletar() //Fun��o para deletar usu�rios
{
	char cpf[40];
	char cadastro[200];
	int opcao=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Para apagar um usu�rio do sistema, digite seu CPF: ");
	scanf("%s",cpf);

	system("cls");

	FILE *fp;
	fp = fopen(cpf, "r");
	
	
	if(fp == NULL){
		printf("O CPF digitado n�o est� cadastrado no sistema. \n\n");
	}
		else{	
		
		printf("Informa��es do Registro: \n\n");
		
		while(fgets(cadastro,200,fp) != NULL){ //Exibe informa��es do usu�rio
			printf("%s", cadastro);
		}
			
		printf("\nTem certeza de que deseja deletar todas as informa��es do usu�rio? \n"); //Solicita confirma��o antes de excluir
		printf("\t1 - Sim \n");
		printf("\t2 - N�o \n\n");
		printf("Op��o: ");
		scanf("%d", &opcao);
	
		system("cls");
	
		fclose(fp);
	
		switch(opcao){	
	
			case 1:
			remove(cpf);
			printf("Usu�rio deletado com sucesso! \n\n\n");
			break;
			
			case 2:
			printf("Procedimento cancelado! \n\n\n");
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel. \n\n\n");	
			break;
		}
	}

	system("pause");
	
}

int main() //Menu Principal
{
	int opcao=0;
	int x=1;

	setlocale(LC_ALL,"Portuguese");
	
	for(x=1;x=1;){ //La�o de repeti��o
	
		system("cls"); //Limpa a tela toda vez que o usu�rio volta ao Menu Principal
				
		printf("### CART�RIO DA EBAC ###\n\n"); //In�cio do menu
		printf("Escolha uma das op��es abaixo: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		scanf("%d", &opcao); //Fim do menu
	
		system("cls");							 
	
		switch(opcao){ //In�cio da condicional
			
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n\n");
			system("pause");
			break;
		}
	}
}
