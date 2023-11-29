#include <stdio.h>//Abrindo Bibliotecas de comunicação de usuário
#include <stdlib.h>//Biblioteca de alocação de espaço 
#include <locale.h>//Biblioteca de alocação de texto por região 
#include <string.h>//Biblioteca responsavel pelas strings 

//Craiando as funções, elas precisam ser chamados no código main 
int registro()//Função de registro
{
	setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita é português(Habilitando os acentos)
	
	char arquivo[40];
	char cpf[40];//Criando uma variável de formato string com 40 caracteres 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadatrado :");
	scanf("%s", cpf);//Armazenando oque o usuário digitar na variável cpf 
	
	strcpy(arquivo,cpf);//Copiando o valor de uma string e passando para outra(StringCopy)
	
	FILE *file;//Criando um arquivo no banco de dados 	
	
	file = fopen(arquivo,"w");//Abrindo o arquivo com (fopen). definindo o nome do arquivo com o valor da variavel(arquivo), ("w")para escrever 
	fprintf (file,cpf);//Salvando a variavel cpf no arquivo, [fprintf (onde será salvo,oque será salvo);]
	fclose(file);//Fechando o arquivo 
	
	file = fopen(arquivo, "a");//Abrindo o arquivo após registrar o cpf 
	fprintf(file,"\n");//Escrevendo uma virgula 
	fclose(file);//Fechando o arquivo 
	
	printf("Digite o nome a ser cadastrado :");//Perguntando ao usuário qual nome ele vai registrar 
	scanf("%s",nome);//Salvando o nome que o usuário digitou na variavel nome, usando "%s"
	
	file = fopen(arquivo,"a");//("a")usado para atualizar/escrever mais coisas dentro do aquivo 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");//Abrindo o arquivo após registrar o nome
	fprintf(file,"\n");//Escrevendo uma virgula 
	fclose(file);//Fechando o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado :");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");//Abrindo o arquivo após registrar o sobrenome
	fprintf(file,"\n");//Escrevendo uma virgula 
	fclose(file);//Fechando o arquivo 
	
	printf("Digite o cargo a ser cadastrado :");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()//Função de consulta
{
	
	setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita é português(Habilitando os acentos)
	
	char cpf[40];
	char content[200];
	
	printf("Digite o CPF a ser consultado :\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Abrindo o arquivo com ("r") para ler (read)
	
	if(file == NULL)//Se o cpf não existe e retornar um valor nulo  informamos ao usuário que não existe
	{
		printf("CPF inexistente no banco de dados \n\n");
	}
	
	while(fgets(content,200,file) != NULL)//(fgets é usado para buscar o aquivo),Ele vai escrever na variavel content com o limite de 200, apenas se o valor não for nulo
	{
		printf("\nEssas são as informações do usuário :");
		printf("%s",content);
		printf("\n");	
	}
	
	system("pause");
	
}

int deletar()//Função de deletar
{
	
	setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita é português(Habilitando os acentos)
	
	
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar \n\n");
	scanf("%s",cpf);// "%s"	usado para salvar na string oqu efoi digitado 
	
	
	
	
	FILE *file;
	file = fopen(cpf,"r");//Abrindo o arquivo e lendo o conteúdo -> ("%r"/read)
	fclose(file);//Fechando o arquivo 

	
	
	if(file == NULL)//Se a função não encontrar o arquivo com o nome do cpf o programa notifica o usuário 
	{
		
		printf("\nEsse CPF não está cadastrado. \n\n");
		system("pause");
		
	}
	
	
	if(file != NULL)
	{
		
		remove(cpf);//Função remove deleta o arquivo com a informação passada dentro da função, no caso (cpf)
		printf("Perfil deletado com sucesso \n\n");
		system("pause");
		
		
	}
	
	
	
}




int main()//Criando uma função main(essa função sempre será executada primeiro independente da ordem do código)
{
    
    int opcao=0;//Definindo uma variável
    int laco=1;//Definindo uma variavel para ser usada no laço de repetição 
    
    for(laco=1; laco=1;)//O programa sempre voltará deste ponto(enquanto 1 for 1 ele irá repetir)
    {
    	
		system("cls");//Se comunicando com o sistema para limpar a tela 
    	
    
	
		setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita é português(Habilitando os acentos)
		
		printf("### Cartório da Ebac ###\n\n");//Escrevendo(As # são cosméticas não alteram o código)
		printf("Escolha a opção de interface :\n\n");
		printf("\t 1 Registrar Nomes :\n");
		printf("\t 2 Consultar Nomes :\n");
		printf("\t 3 Deletar Nomes :\n\n\n");
		printf("Opção :");
		
		scanf("%d", &opcao);//Armazenando oque o usuário digitou na variável opcao
		
		system("cls");//Se comunicando com o sistema operacional para limpar a tela
		
		
		
		
		
		switch(opcao)//Analizando a variavel opcao(Switch Machine)
		{
			case 1:
			registro();//Chamando a função 
			break;
			
			case 2:
			consulta();//Chamando a função 
			break;
			
			case 3:
			deletar();//Chamando a função 
			break;
			
			default:
				printf("Essa opção não está disponível \n\n");
				system("pause");
			break;
		}
		
	
	
	
	
	}

}
