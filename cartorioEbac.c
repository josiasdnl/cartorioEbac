#include <stdio.h>  //biblioteca de comunicação com o usuário (io = input/output)
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro() //Função destinada a registrar novos usuários no sistema
{
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o CPF a ser cadastrado: "); //Início do questionário para coleta de informações do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia valores das strings
	
	FILE *fp;
	fp = fopen(arquivo,"w"); //Abrir (criar) arquivo ("w": write)
	fprintf(fp,"\tCPF: %s \n", cpf); //Salvar valor da variável no arquivo
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

int consulta() //Função destinada a buscar usuários que já fazem parte do sistema
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
		printf("O CPF digitado não está cadastrado no sistema. \n");
	}
		else{
			printf("Informações do Registro: \n\n");	
		}
	
	while(fgets(cadastro,200,fp) != NULL){ //Busca informações associadas ao CPF digitado
			printf("%s", cadastro);
	}
	
	fclose(fp);
	
	printf("\n\n");
	
	system("pause");
	
}

int deletar() //Função para deletar usuários
{
	char cpf[40];
	char cadastro[200];
	int opcao=0;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Para apagar um usuário do sistema, digite seu CPF: ");
	scanf("%s",cpf);

	system("cls");

	FILE *fp;
	fp = fopen(cpf, "r");
	
	
	if(fp == NULL){
		printf("O CPF digitado não está cadastrado no sistema. \n\n");
	}
		else{	
		
		printf("Informações do Registro: \n\n");
		
		while(fgets(cadastro,200,fp) != NULL){ //Exibe informações do usuário
			printf("%s", cadastro);
		}
			
		printf("\nTem certeza de que deseja deletar todas as informações do usuário? \n"); //Solicita confirmação antes de excluir
		printf("\t1 - Sim \n");
		printf("\t2 - Não \n\n");
		printf("Opção: ");
		scanf("%d", &opcao);
	
		system("cls");
	
		fclose(fp);
	
		switch(opcao){	
	
			case 1:
			remove(cpf);
			printf("Usuário deletado com sucesso! \n\n\n");
			break;
			
			case 2:
			printf("Procedimento cancelado! \n\n\n");
			break;
			
			default:
			printf("Essa opção não está disponível. \n\n\n");	
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
	
	for(x=1;x=1;){ //Laço de repetição
	
		system("cls"); //Limpa a tela toda vez que o usuário volta ao Menu Principal
				
		printf("### CARTÓRIO DA EBAC ###\n\n"); //Início do menu
		printf("Escolha uma das opções abaixo: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		scanf("%d", &opcao); //Fim do menu
	
		system("cls");							 
	
		switch(opcao){ //Início da condicional
			
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
			printf("Essa opção não está disponível.\n\n");
			system("pause");
			break;
		}
	}
}
