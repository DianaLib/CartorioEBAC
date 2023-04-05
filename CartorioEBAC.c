#include <stdio.h> //biblioteca de comunica��o com o  usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
    scanf("%s", cpf); // %s refere-se a string
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
    fprintf(file,cpf); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,"\n"); //espa�o de linha 
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",nome); //refere-se a string
    fclose(file);
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,nome); // salva a variavel
    fclose(file); // fecha arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,","); 
    fclose(file); //fecha o arquivo
        
    printf("Digite o sobrenome a ser cadastrado: "); //coletando inform��es do usu�rio
    scanf("%s",sobrenome); //salva o valor da variavel
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome); //salva a vari�vel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); 
    fprintf(file,"\n");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause"); //pausa na tela 
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo as linguagens
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Desculpe, n�o foi poss�vel localizar o arquivo.\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio deletado com sucesso! \n\n O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
}


int main ()
{
    int opcao=0; //Definindo as vari�veis
    int laco=1;
    
	for(laco=1; laco=1;)
	{
		system("cls"); //respons�vel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo as linguagens
	
	printf ("###Cart�rio EBAC###\n\n"); //In�cio do menu
	printf ("Escolha a op��o desejada do menu:\n\n");
	printf ("\t1 Registro de nomes\n");
	printf ("\t2 Consultar nomes\n");
	printf ("\t3 Deletar nomes\n\n");
	printf("Op��o: "); //Fim do menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	system("cls"); //respons�vel por limpar a tela
	
	
	switch(opcao) //in�cio da sele��o do menu
	{
		case 1:
		registro(); //chamada de fun��es
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Desculpe, essa op��o n�o esta dispon�vel!\n");
		system("pause");
		break;
		//fim da sele��o	
	}
	
}
}
