#include<stdio.h>
#include<windows.h>
//No trabalho, precisamos utilizar vários structs dentro de outros
//Buscar os dados de um txt
//Editar registros
//Deletar os registros
//Cadatrar novos registros

typedef struct Categoria {
	char nome[50];
	int idade;
	char about[250];
} Categoria;

typedef struct Autor {
	char nome[50];
	int idade;
	char about[250];
} Autor;

typedef struct Data {
	int dia;
	int mes;
	int ano;
} Data;


typedef struct Postagens {
	char titulo[250];
	char resumo[250];
	char conteudo[250];
	Data data;
	Autor autor;
	Categoria categoria;
} Postagens;

void addPost() {
	system("cls");
	printf("Digite o título da postagem:\n");
	scanf("%s",);
}

int main() {
	int opcao;
	printf("Blog dojão\n");
	printf("1 - Adicionar Postagem\n");
	printf("2 - Visualizar Postagens\n");
	printf("3 - Adicionar Categoria\n");
	printf("4 - Adicionar Autor\n");
	printf("\n\n\nEscolha um menu:");
	scanf("%d",&opcao);
	if(opcao == 1) {
		addPost();
	}
}
