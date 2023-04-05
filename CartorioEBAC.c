#include <stdio.h> //biblioteca de comunicação com o  usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
    scanf("%s", cpf); // %s refere-se a string
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
    fprintf(file,cpf); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,"\n"); //espaço de linha 
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
    scanf("%s",nome); //refere-se a string
    fclose(file);
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,nome); // salva a variavel
    fclose(file); // fecha arquivo
    
    file = fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file,","); 
    fclose(file); //fecha o arquivo
        
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informções do usuário
    scanf("%s",sobrenome); //salva o valor da variavel
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome); //salva a variável
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
		printf("Desculpe, não foi possível localizar o arquivo.\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário deletado com sucesso! \n\n O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}


int main ()
{
    int opcao=0; //Definindo as variáveis
    int laco=1;
    
	for(laco=1; laco=1;)
	{
		system("cls"); //responsável por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo as linguagens
	
	printf ("###Cartório EBAC###\n\n"); //Início do menu
	printf ("Escolha a opção desejada do menu:\n\n");
	printf ("\t1 Registro de nomes\n");
	printf ("\t2 Consultar nomes\n");
	printf ("\t3 Deletar nomes\n\n");
	printf("Opção: "); //Fim do menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	system("cls"); //responsável por limpar a tela
	
	
	switch(opcao) //início da seleção do menu
	{
		case 1:
		registro(); //chamada de funções
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Desculpe, essa opção não esta disponível!\n");
		system("pause");
		break;
		//fim da seleção	
	}
	
}
}
