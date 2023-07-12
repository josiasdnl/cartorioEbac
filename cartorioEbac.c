#include <stdio.h>	//Comunica��o com o usu�rio (input/output)
#include <stdlib.h>	//Aloca��o de espa�o em mem�ria
#include <locale.h>	//Localiza��o de idioma por regi�o
#include <string.h>	//Manipula��o de strings

#define MAX_USUARIOS 100 //M�ximo de elementos que a array "usuario" poder� armazenar

//Estrutura de dados que ir� receber as vari�veis "email" e "senha"
typedef struct { 
	char email[20];
	char senha[20];
} dadosDeLogin; //Nome atribu�do � estrutura

//Cria��o de uma array nomeada "usuarios" para receber os dados da estrutura "dadosDeLogin" obedecendo ao limite de 100 usu�rios
dadosDeLogin usuarios[MAX_USUARIOS];  
int numUsuario=0; //Contador

int criarConta() {
	
	if(numUsuario >= MAX_USUARIOS) {
		printf("\n\n!!! Limite de usu�rios atingido \n\n\n");
		return;
	}
	
	//Solicita��o dos dados para criar nova conta
	printf("-------------------------------------------------------\n");
   	printf("\t\tCRIE UMA CONTA \n");
 	printf("-------------------------------------------------------\n\n");
 	printf("Digite os dados solicitados abaixo: \n");
 	
	 printf("\tEmail: ");
 	scanf("%s", usuarios[numUsuario].email);
 	
 	printf("\tSenha: ");
 	scanf("%s", usuarios[numUsuario].senha);
	
	//Verificar se o email j� est� cadastrado no sistema
 	int i=0;
 	for(i=0; i < numUsuario; i++) {
 		if (strcmp(usuarios[i].email, usuarios[numUsuario].email) == 0) { //Caso o email j� esteja no sistema, o valor do retorno ser� 0
 			printf("\n\n !!! Esse usu�rio j� est� cadastrado no sistema. Fa�a login ou tente novamente. \n\n\n");
 			system("pause");
 			return;
		 }
	}
 	
 	printf("\n\nCadastro realizado com sucesso! \n\n\n");
	
	numUsuario++; //Incremento do contador
	
	system("pause");
}

int fazerLogin() {
	char email[20];
	char senha[20];
	
	printf("-------------------------------------------------------\n");
   	printf("\t\t\tLOGIN \n");
 	printf("-------------------------------------------------------\n\n");
	
	// Solicitar email e senha
    printf("Email: ");
    scanf("%s", email);

    printf("Senha: ");
    scanf("%s", senha);

    // Verificar se o email e a senha correspondem a um cadastro v�lido
    int i;
	for (i = 0; i < numUsuario	; i++) {
        if (strcmp(usuarios[i].email, email) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
        	system("cls");
        	printf("\n\nConectando � sua conta... \n\n\n");
        	system("pause");
            return 1; // Login bem-sucedido
        }
    }

    printf("\n\n!!! Usu�rio ou senha inv�lidos.\n\n");
    system("pause");
    return 0; // Login falhou
}

int telaLogin() {
	int opcao=0;
	int i=1;
	
	for(i=1; i==1; ) {

		system("cls");
	
		printf("---------------------------------------------------------------- \n");
		printf("\t\t� BOM VER VOC� POR AQUI DE NOVO! \n");
		printf("Sistema interno de registro para alunos e colaboradores da EBAC \n");
		printf("---------------------------------------------------------------- \n\n");
		printf("Escolha uma das op��es abaixo: \n");
		printf("\t1 - Criar conta \n");
		printf("\t2 - Fazer login \n");
		printf("\t3 - Fechar programa \n\n");
		printf("Op��o: ");
		scanf("%d", &opcao);
	
		system("cls");
	
		switch (opcao) {
			case 1:
				criarConta();
				break;
		
			case 2:
				if(fazerLogin()) {
					return; //Sai da fun��o e vai para o Menu Principal
				}
				break;
		
			case 3:
				printf("\n\nEncerrando sistema... \n\n\n");
				system("pause");
				exit(0); //Encerra o programa
		
			default:
				printf("\n\n!!! Essa op��o n�o est� dispon�vel. \n\n\n");
				system("pause");
		}
	}
}

int registrarNomes() {
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("---------------------------------------------------------------- \n");
	printf("\t\t REGISTRAR NOVO USU�RIO \n");
	printf("---------------------------------------------------------------- \n\n");
	
	//Solicitar informa��es ao usu�rio
	//IN�CIO
	printf("Digite os dados solicitados abaixo. \n"); 
	printf("\t CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia dados da string "cpf" para a string "arquivo"
	
	printf("\t Nome: ");
	scanf("%s", nome);
	printf("\t Sobrenome: ");
	scanf("%s", sobrenome);
	printf("\t Cargo: ");
	scanf("%s", cargo);
	printf("\n\n");
	//FIM
	
	//Cria��o de um arquivo para registrar os dados coletados
	FILE *fp;
	fp = fopen(arquivo, "a"); //Arquivo aberto para receber os dados ("a", append)
	fprintf(fp, "\tCPF: %s \n", cpf);
	fprintf(fp, "\tNome completo: %s %s \n", nome, sobrenome);
	fprintf(fp, "\tCargo: %s \n", cargo);
	fclose(fp); //Arquivo fechado
	
	
	system("cls");
	
	printf("\n\nNovo usu�rio registrado com sucesso! \n\n\n");
	
	system("pause");
}

int consultarNomes() {
	char cpf[40];
	char consulta[200];
		
	printf("---------------------------------------------------------------- \n");
	printf("\t\t CONSULTAR USU�RIOS NO SISTEMA \n");
	printf("---------------------------------------------------------------- \n\n");
	printf("Digite o CPF do usu�rio que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *fp; //Acessando arquivo para leitura ("r", read)
	fp = fopen(cpf, "r"); //ABRIR
	
		if(fp == NULL) {
			printf("\n\n!!! O CPF digitado n�o est� cadastrado no sistema. \n");
		}
	
		if(fp != NULL) {
			printf("\n\nInforma��es do usu�rio: \n");
			
			while(fgets(consulta, 200, fp) != NULL) {
				printf("%s", consulta);
			}
		}

	fclose(fp); //FECHAR
	
	printf("\n\n");
	
	system("pause");
}

int deletarNomes() {
	char cpf[40];
	char consulta[200];
	int opcao;
	
	printf("---------------------------------------------------------------- \n");
	printf("\t\t DELETAR USU�RIO DO SISTEMA \n");
	printf("---------------------------------------------------------------- \n\n");
	printf("Para apagar as informa��es de um usu�rio, digite seu CPF: ");
	scanf("%s", cpf);
	
	FILE *fp; //Acessando arquivo para leitura
	fp = fopen(cpf, "r"); //ABRIR
	
		if(fp == NULL) {
			printf("\n\n!!! O CPF digitado n�o est� cadastrado no sistema. \n\n\n");
		}
		
		else {
			printf("\n\nInforma��es do usu�rio: \n");
				
			while(fgets(consulta, 200, fp) != NULL) {
				printf("%s", consulta);
			}
		
			//Solicitar confirma��o antes de deletar as inofrma��es
			printf("\n\n---------------------------------------------------------------- \n\n");	
			printf("\nTem certeza de que deseja deletar todas as informa��es do usu�rio? \n");
			printf("\t1 - Sim \n");
			printf("\t2 - N�o \n\n");
			printf("Op��o: ");
			scanf("%d", &opcao);
			
			system("cls");
	
	fclose(fp); //FECHAR
	
			switch (opcao) {
				case 1:
					remove(cpf);
					printf("\n\nUsu�rio deletado com sucesso! \n\n\n");
					break;
			
				case 2:
					printf("\n\nProcedimento cancelado! \n\n\n");
					break;
			
				default:
					printf("\n\n!!! Essa op��o n�o est� dispon�vel.\n\n\n");
			}
		}
	
	system("pause");
}

int menuPrincipal() {
	int opcao=0;
	int x=1;
	
	for(x=1; x==1; ) { //Loop que mant�m o usu�rio no Menu Principal enquanto ele n�o fizer o logout da conta
	
		system("cls");
	
		printf("---------------------------------------------------------------- \n");
		printf("\t\tREGISTRO DE ALUNOS E COLABORADORES \n");
		printf("---------------------------------------------------------------- \n\n");
		printf("Escolha uma das op��es abaixo: \n");
		printf("\t1 - Novo registro \n");
		printf("\t2 - Consultar o sistema \n");
		printf("\t3 - Deletar usu�rio \n\n");
		printf("\t4 - Logout \n\n");
		printf("Op��o: ");
		scanf("%d", &opcao);
	
		system("cls");
	
		switch (opcao) {
			case 1:
				registrarNomes();
				break;
		
			case 2:
				consultarNomes();
				break;
		
			case 3:
				deletarNomes();
				break;
		
			case 4:
				printf("\n\nDesconectando da sua conta... \n\n\n");
				system("pause");
				return(0);
				break;
			
			default:
				printf("\n\n!!! Essa op��o n�o est� dispon�vel. \n\n\n");
				system("pause");
		}
	}
}

int main() {
	int x=1;
	
	setlocale(LC_ALL, "Portuguese");
	
	for(x=1; x==1; ) {
		telaLogin();
		menuPrincipal();
	}
}
