#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel de cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//In�cio da cria��o de vari�veis/strings
	char arquivo [40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever 
	fprintf(file, cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo 
	
	file = fopen (arquivo, "a"); //Acessa o arquivo
	fprintf(file,","); //Atualiza o valor dessa vari�vel(?) (n�o sei muito bem o que � essa v�rgula)
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s" ,nome); //&s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,nome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Acessa o arquivo
	fprintf(file,","); //
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando a inform��o do usu�rioa
	scanf("%s" ,sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,sobrenome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Acessa o arquivo
	fprintf(file,","); //
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando a informa��o do usu�rio
	scanf("%s" ,cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,cargo); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //pausa 
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio das cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
    scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //ler o arquivo
	
	if(file == NULL) //"se", condi��o
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pause
		
	
}

int deletar()
{
	//in�cio da cria��o de vari�veis
	char cpf[40];
	//Fim da cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usu�rio 
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //Remover
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Ler o arquivo
	
	if(file == NULL); //"se", condi��o
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause"); //Pausar
	}
	
	
	
}


int main()
{
    int opcao=0; // Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
		system("cls"); //Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes \n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n\n");	
		printf("Opc�o:  "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls");
    
    	switch(opcao) //In�cio da sele��o do menu
    	{
    		case 1:
    		registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta(); 
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
	    	system("pause");
			break; 	            
		}
	
	}
}
