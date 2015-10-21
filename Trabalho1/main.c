#include<stdio.h>
#include<string.h>
#include<windows.h>
//PT1:
//No trabalho, precisamos utilizar vários structs dentro de outros
//Editar registros
//Deletar os registros
//Cadatrar novos registros

//PT2:

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void limpaTeclado() {
	fflush(stdin);
}

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

int getElemNum(Postagens *posts) {
	int i =0;
	int num=0;
	for(i=0;i<100;i++) {
		if(strcmp(posts[i].titulo,"") == 0) return num;
		num++;
	}
	return 0;
}

void addPost(Postagens *posts) {
	system("cls");	
	SetColorAndBackground(0,0xFFF);
	printf("Digite o título da postagem:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",posts[getElemNum(posts)].titulo);
	SetColorAndBackground(0,0xFFF);
	printf("\nResuma sua postagem:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",posts[getElemNum(posts)].resumo);
	
}

int main() {
	SetColorAndBackground(0xFFF,0);
	Postagens posts[100];
	int opcao;
	while(true) {
		opcao=0;
		system("cls");
		printf("Blog dojão\n");
		printf("1 - Adicionar Postagem\n");
		printf("2 - Visualizar Postagens\n");
		printf("3 - Adicionar Categoria\n");
		printf("4 - Adicionar Autor\n");
		
		printf("\n\n\nEscolha um menu:");
		scanf("%d",&opcao);
		if(opcao == 1) {
			addPost(posts);
		}
	}
}
