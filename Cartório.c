#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável de cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema 
{
	//Início da criação de variáveis/strings
	char arquivo [40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever 
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo 
	
	file = fopen (arquivo, "a"); //Acessa o arquivo
	fprintf(file,","); //Atualiza o valor dessa variável(?) (não sei muito bem o que é essa vírgula)
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s" ,nome); //&s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,nome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Acessa o arquivo
	fprintf(file,","); //
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando a informção do usuárioa
	scanf("%s" ,sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,sobrenome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen (arquivo, "a"); //Acessa o arquivo
	fprintf(file,","); //
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando a informação do usuário
	scanf("%s" ,cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,cargo); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	system("pause"); //pausa 
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início das criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
    scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //ler o arquivo
	
	if(file == NULL) //"se", condição
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pause
		
	
}

int deletar()
{
	//início da criação de variáveis
	char cpf[40];
	//Fim da criação de variáveis
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação do usuário 
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //Remover
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Ler o arquivo
	
	if(file == NULL); //"se", condição
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause"); //Pausar
	}
	
	
	
}


int main()
{
    int opcao=0; // Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
		system("cls"); //Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes \n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n\n");	
		printf("Opcão:  "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usuário
	
    	system("cls");
    
    	switch(opcao) //Início da seleção do menu
    	{
    		case 1:
    		registro(); //Chamada de funções
			break;
			
			case 2:
			consulta(); 
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
	    	system("pause");
			break; 	            
		}
	
	}
}
