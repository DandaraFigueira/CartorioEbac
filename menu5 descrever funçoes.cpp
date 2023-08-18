#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o responsavel por cadastrar os usuarios no sistemas
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o dasvarieaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s", cpf);//%s refere-se a string
		
	strcpy(arquivo, cpf);//responsavel pelos valores das string
	
	FILE *file; //cria orquivo no banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo e o w cria uma nova
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,nome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa�oes do usuario
	scanf("%s",sobrenome);//%S refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,sobrenome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa�oes do usuarios
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo,"a");//abre o arquivo
	fprintf(file,cargo);
	fclose(file);//fecha o arquivo
	
	system("pause");
	
}

int consulta()//consulta o bando de dados
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPf a ser consutato: ");
	scanf("%s",cpf);
	
	FILE *file;//arquivo
	file = fopen(cpf,"r");//abre o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa�oes do usuario: ");//informa�oes a ser mostrada
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()//deletar arquivo do banco de dados
{
	char cpf[40];
	
	printf("Digite o CPF do uduario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//remove o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");//abri o arquivo
	
	if(file == NULL);
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("\t4 - Sair do sistema\n\n.");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao); //armanezamento a escolha do usuario
									
		system("cls");//responsavel por limpar a tela
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1://chamada de fun�oes
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
			break;
									
			default:
			printf("Essa op��o n�o est� disponivel!!\n");
			system("pause");
			break;	//fim da sele��o
		}
	
	
	}
	
	

}
