#include <stdio.h> //biblioteca de comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bibliotecas responsável por cuidar das string
  
int registrar() // função responsável por cadastrar os usuários no sistema
	{
		//inicio da criação de variáveis/string
		char arquivo[100];
		char cpf[100];
		char nome[100];
		char sobrenome[100];
		char cargo[100];
		//fim da criação das variáveis
		printf("Digite o cpf a ser cadastrado: "); //responsável por copiar os valores da strings
		scanf("%s",cpf);//refere-se a strings
	
		strcpy(arquivo,cpf); //Responsável por copiar os valores das string
		
		FILE *file; //cria o arquivo //estou dizendo pro computador execultar o comando "FILE" que é ir atrás do arquivo "file"
		file = fopen(arquivo,"w"); //cria o arquivo // aqui estou criando o arquivo "file"
		fprintf(file,cpf); //salvo o valor da variável
		fclose(file); //fechando o arquivo
	
		file = fopen(arquivo,"a"); //to falando pro computador abrir o arquivo "file", e atualizar o arquivo.
		fprintf(file,","); //aqui estou incluindo uma virgula após a resposta do usuário
		fclose(file); // aqui stou fechando o arquivo
	
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,nome);//salvo o valor da variável
		fclose(file);//fechando o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,",");//aqui estou incluindo uma virgula após a resposta do usuário
		fclose(file);//fechando o arquivo
	
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,sobrenome);//salvo o valor da variável
		fclose(file);//fechando o arquivo
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,",");//aqui estou incluindo uma virgula após a resposta do usuário
		fclose(file);//fechando o arquivo
	
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);	
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,cargo);//salvo o valor da variável
		fclose(file);//fechando o arquivo
	
		file = fopen(arquivo,"a");//aqui estou pedindo pro computador atualizar o arquivo.
		fprintf(file,",");//aqui estou incluindo uma virgula após a resposta do usuário
		fclose(file);//fechando o arquivo
	
		system("pause");
		system("cls");
	}

int consultar()
	{
		// função responsável por consultar os usuários no sistema
		setlocale(LC_ALL, "Portuguse"); //definindo a linguagem
	
		char cpf[100];
		char conteudo[200];
	
		printf("Digite o cpf a ser consultado: ");
		scanf("%s",cpf);
	
		FILE *file; //estou falando pro computador execultar o comando "FILE", e procura o aquivo "file"
		file = fopen(cpf,"r");//abrir o arquivo "cpf" que se encontra no aquivo "file", e ler...
	
		if (file == NULL)//estou dizendo pro computador "if" se o cpf for nulo, o software respondera...
		{
			printf("Não foi possivel abrir o arquivo, não localizado!.");
		}
		while(fgets(conteudo, 200, file) != NULL)//enquanto vai buscar o conteudo, que tem o valor maximo de 200, dentro do aquivo file,
				//ele tá salvalndo na variável conteudo, os 200 caracteres, que estão dentro do file. parando apenas quando for nulo
				//enquanto ele estiver escrevendo na variável conteudo,até 200 valores, que estão dentro do arquivo, enquanto não for nulo
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s",conteudo);
			printf("\n\n");
		}
		
	system("pause");
	system("cls");
	
}

int deletar()
{
	// função responsável por deletar os usuários no sistema
	char cpf[100];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//remover o aquivo citado pelo usuário
	
	FILE *file;//estou falando pro computador execultar o comando "FILE", e procura o aquivo "file"
	file = fopen(cpf,"r");//abrir o arquivo "cpf" que se encontra no aquivo "file", e ler...
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.");
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
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes:\n\n");
		printf("\t2 - Consultar nomes:\n\n");
		printf("\t3 - Deleatr nomes\n\n");
		printf("\t4 - Sair do sistema:\n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");//limpar a tela
		
		switch(opcao) //inicio da seleção
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
			printf("Essa opção não está disponivel!\n\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
