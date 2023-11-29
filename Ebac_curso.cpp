#include <stdio.h>//Abrindo Bibliotecas de comunica��o de usu�rio
#include <stdlib.h>//Biblioteca de aloca��o de espa�o 
#include <locale.h>//Biblioteca de aloca��o de texto por regi�o 
#include <string.h>//Biblioteca responsavel pelas strings 

//Craiando as fun��es, elas precisam ser chamados no c�digo main 
int registro()//Fun��o de registro
{
	setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita � portugu�s(Habilitando os acentos)
	
	char arquivo[40];
	char cpf[40];//Criando uma vari�vel de formato string com 40 caracteres 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadatrado :");
	scanf("%s", cpf);//Armazenando oque o usu�rio digitar na vari�vel cpf 
	
	strcpy(arquivo,cpf);//Copiando o valor de uma string e passando para outra(StringCopy)
	
	FILE *file;//Criando um arquivo no banco de dados 	
	
	file = fopen(arquivo,"w");//Abrindo o arquivo com (fopen). definindo o nome do arquivo com o valor da variavel(arquivo), ("w")para escrever 
	fprintf (file,cpf);//Salvando a variavel cpf no arquivo, [fprintf (onde ser� salvo,oque ser� salvo);]
	fclose(file);//Fechando o arquivo 
	
	file = fopen(arquivo, "a");//Abrindo o arquivo ap�s registrar o cpf 
	fprintf(file,"\n");//Escrevendo uma virgula 
	fclose(file);//Fechando o arquivo 
	
	printf("Digite o nome a ser cadastrado :");//Perguntando ao usu�rio qual nome ele vai registrar 
	scanf("%s",nome);//Salvando o nome que o usu�rio digitou na variavel nome, usando "%s"
	
	file = fopen(arquivo,"a");//("a")usado para atualizar/escrever mais coisas dentro do aquivo 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");//Abrindo o arquivo ap�s registrar o nome
	fprintf(file,"\n");//Escrevendo uma virgula 
	fclose(file);//Fechando o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado :");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");//Abrindo o arquivo ap�s registrar o sobrenome
	fprintf(file,"\n");//Escrevendo uma virgula 
	fclose(file);//Fechando o arquivo 
	
	printf("Digite o cargo a ser cadastrado :");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()//Fun��o de consulta
{
	
	setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita � portugu�s(Habilitando os acentos)
	
	char cpf[40];
	char content[200];
	
	printf("Digite o CPF a ser consultado :\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Abrindo o arquivo com ("r") para ler (read)
	
	if(file == NULL)//Se o cpf n�o existe e retornar um valor nulo  informamos ao usu�rio que n�o existe
	{
		printf("CPF inexistente no banco de dados \n\n");
	}
	
	while(fgets(content,200,file) != NULL)//(fgets � usado para buscar o aquivo),Ele vai escrever na variavel content com o limite de 200, apenas se o valor n�o for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio :");
		printf("%s",content);
		printf("\n");	
	}
	
	system("pause");
	
}

int deletar()//Fun��o de deletar
{
	
	setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita � portugu�s(Habilitando os acentos)
	
	
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar \n\n");
	scanf("%s",cpf);// "%s"	usado para salvar na string oqu efoi digitado 
	
	
	
	
	FILE *file;
	file = fopen(cpf,"r");//Abrindo o arquivo e lendo o conte�do -> ("%r"/read)
	fclose(file);//Fechando o arquivo 

	
	
	if(file == NULL)//Se a fun��o n�o encontrar o arquivo com o nome do cpf o programa notifica o usu�rio 
	{
		
		printf("\nEsse CPF n�o est� cadastrado. \n\n");
		system("pause");
		
	}
	
	
	if(file != NULL)
	{
		
		remove(cpf);//Fun��o remove deleta o arquivo com a informa��o passada dentro da fun��o, no caso (cpf)
		printf("Perfil deletado com sucesso \n\n");
		system("pause");
		
		
	}
	
	
	
}




int main()//Criando uma fun��o main(essa fun��o sempre ser� executada primeiro independente da ordem do c�digo)
{
    
    int opcao=0;//Definindo uma vari�vel
    int laco=1;//Definindo uma variavel para ser usada no la�o de repeti��o 
    
    for(laco=1; laco=1;)//O programa sempre voltar� deste ponto(enquanto 1 for 1 ele ir� repetir)
    {
    	
		system("cls");//Se comunicando com o sistema para limpar a tela 
    	
    
	
		setlocale(LC_ALL, "Portuguese");//Dizendo ao computador que minha linguagem de escrita � portugu�s(Habilitando os acentos)
		
		printf("### Cart�rio da Ebac ###\n\n");//Escrevendo(As # s�o cosm�ticas n�o alteram o c�digo)
		printf("Escolha a op��o de interface :\n\n");
		printf("\t 1 Registrar Nomes :\n");
		printf("\t 2 Consultar Nomes :\n");
		printf("\t 3 Deletar Nomes :\n\n\n");
		printf("Op��o :");
		
		scanf("%d", &opcao);//Armazenando oque o usu�rio digitou na vari�vel opcao
		
		system("cls");//Se comunicando com o sistema operacional para limpar a tela
		
		
		
		
		
		switch(opcao)//Analizando a variavel opcao(Switch Machine)
		{
			case 1:
			registro();//Chamando a fun��o 
			break;
			
			case 2:
			consulta();//Chamando a fun��o 
			break;
			
			case 3:
			deletar();//Chamando a fun��o 
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel \n\n");
				system("pause");
			break;
		}
		
	
	
	
	
	}

}
