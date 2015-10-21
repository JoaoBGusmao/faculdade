#include<stdio.h>
#include<string.h>
#include<windows.h>
//PT1:
//No trabalho, precisamos utilizar vários structs dentro de outros
//Editar registros
//Deletar os registros
//Cadatrar novos registros

//PT2:
//Usar funções
void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void limpaTeclado() {
	fflush(stdin);
}

typedef struct Numeros {
	int Npostagens = 0;
	int Nautores = 0;
	int Ncat = 0;
} Numeros;

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
	char categoria[100];
	Data data;
	Autor autor;
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

void showAuthorList(Autor *autores, Numeros *numeros) {
	int i = 0;
	printf("ID      Nome            Idade\n");
	for(i=0;i < numeros->Nautores;i++) {
		printf("%d    %-20s %d\n",i,autores[i].nome,autores[i].idade);
	}
}

void showCatList(char categorias[100][100], Numeros *numeros) {
	int i = 0;
	printf("ID      Categoria\n");
	for(i=0;i < numeros->Ncat;i++) {
		printf("%d      %s\n",i,categorias[i]);
	}
}

void addPost(Postagens *posts, Autor *autores,char categorias[100][100],Numeros *numeros) {
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
	
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o ID do autor:\n");
	SetColorAndBackground(0xFFF,0);
	showAuthorList(autores,numeros);
	limpaTeclado();
	int autorId = 0;
	scanf("%d",&autorId);
	posts[getElemNum(posts)].autor = autores[autorId];
	
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o ID da categoria:\n");
	SetColorAndBackground(0xFFF,0);
	showCatList(categorias,numeros);
	limpaTeclado();
	int catId = 0;
	scanf("%d",&catId);
	//strcpy(posts[getElemNum(posts)].categoria, categorias[catId]);
	
	numeros->Npostagens++;
	
}

void addPrePosts(Autor *autores, char categorias[100][100],Numeros *numeros) {
	strcpy(autores[0].nome,"Joao Gusmao");
	autores[0].idade = 19;
	strcpy(autores[0].about,"Sobre eu");
	
	strcpy(autores[1].nome,"Jao dasmao");
	autores[1].idade = 21;
	strcpy(autores[1].about,"Sobre eu2");
	numeros->Nautores = 2;
	
	strcpy(categorias[0],"Noticias");
	strcpy(categorias[1],"Entretenimento");
	numeros->Ncat = 2;
}

int main() {
	SetColorAndBackground(0xFFF,0);
	Postagens posts[100];
	Autor autores[100];
	char categorias[100][100];
	Numeros numeros;
	int opcao;
	addPrePosts(autores,categorias,&numeros);
	while(true) {
		opcao=0;
		system("cls");
		printf("Blog dojão\n");
		printf("1 - Adicionar Postagem\n");
		printf("2 - Visualizar Postagens\n");
		printf("3 - Adicionar Categoria\n");
		printf("4 - Adicionar Autor\n");
		printf("Numero de post: %d",numeros.Npostagens);
		printf("\n\n\nEscolha um menu:");
		scanf("%d",&opcao);
		if(opcao == 1) {
			addPost(posts,autores,categorias,&numeros);
		}
	}
}
