#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bibliotecas respons�vel por cuidar das string
  
int registrar() // fun��o respons�vel por cadastrar os usu�rios no sistema
	{
		//inicio da cria��o de vari�veis/string
		char arquivo[100];
		char cpf[100];
		char nome[100];
		char sobrenome[100];
		char cargo[100];
		//fim da cria��o das vari�veis
		printf("Digite o cpf a ser cadastrado: "); //respons�vel por copiar os valores da strings
		scanf("%s",cpf);//refere-se a strings
	
		strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
		
		FILE *file; //cria o arquivo //estou dizendo pro computador execultar o comando "FILE" que � ir atr�s do arquivo "file"
		file = fopen(arquivo,"w"); //cria o arquivo // aqui estou criando o arquivo "file"
		fprintf(file,cpf); //salvo o valor da vari�vel
		fclose(file); //fechando o arquivo
	
		file = fopen(arquivo,"a"); //to falando pro computador abrir o arquivo "file", e atualizar o arquivo.
		fprintf(file,","); //aqui estou incluindo uma virgula ap�s a resposta do usu�rio
		fclose(file); // aqui stou fechando o arquivo
	
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,nome);//salvo o valor da vari�vel
		fclose(file);//fechando o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,",");//aqui estou incluindo uma virgula ap�s a resposta do usu�rio
		fclose(file);//fechando o arquivo
	
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,sobrenome);//salvo o valor da vari�vel
		fclose(file);//fechando o arquivo
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,",");//aqui estou incluindo uma virgula ap�s a resposta do usu�rio
		fclose(file);//fechando o arquivo
	
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);	
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,cargo);//salvo o valor da vari�vel
		fclose(file);//fechando o arquivo
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,",");//aqui estou incluindo uma virgula ap�s a resposta do usu�rio
		fclose(file);//fechando o arquivo
	
		system("pause");
		system("cls");
	}

int consultar()
	{
		// fun��o respons�vel por consultar os usu�rios no sistema
		setlocale(LC_ALL, "Portuguse"); //definindo a linguagem
	
		char cpf[100];
		char conteudo[200];
	
		printf("Digite o cpf a ser consultado: ");
		scanf("%s",cpf);
	
		FILE *file; //estou falando pro computador execultar o comando "FILE", e procura o aquivo "file"
		file = fopen(cpf,"r");//abrir o arquivo "cpf" que se encontra no aquivo "file", e ler...
	
		if (file == NULL)//estou dizendo pro computador "if" se o cpf for nulo, o software respondera...
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!.");
		}
		while(fgets(conteudo, 200, file) != NULL)//enquanto vai buscar o conteudo, que tem o valor maximo de 200, dentro do aquivo file,
				//ele t� salvalndo na vari�vel conteudo, os 200 caracteres, que est�o dentro do file. parando apenas quando for nulo
				//enquanto ele estiver escrevendo na vari�vel conteudo,at� 200 valores, que est�o dentro do arquivo, enquanto n�o for nulo
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s",conteudo);
			printf("\n\n");
		}
		
	system("pause");
	system("cls");
	
}

int deletar()
{
	// fun��o respons�vel por deletar os usu�rios no sistema
	char cpf[100];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//remover o aquivo citado pelo usu�rio
	
	FILE *file;//estou falando pro computador execultar o comando "FILE", e procura o aquivo "file"
	file = fopen(cpf,"r");//abrir o arquivo "cpf" que se encontra no aquivo "file", e ler...
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.");
		system("pause");
  		system("cls");
	}
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		setlocale(LC_ALL, "Portuguese");
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes:\n\n");
		printf("\t2 - Consultar nomes:\n\n");
		printf("\t3 - Deleatr nomes\n\n");
		printf("\t4 - Sair do sistema:\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");//limpar a tela
		
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}
