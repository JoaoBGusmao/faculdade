#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

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
		printf("%d       %s\n",i,categorias[i]);
	}
}

void addPost(Postagens *posts, Autor *autores,char categorias[100][100],Numeros *numeros) {
	system("cls");	
	SetColorAndBackground(0,0xFFF);
	printf("Digite o título da postagem:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",posts[numeros->Npostagens].titulo);
	
	SetColorAndBackground(0,0xFFF);
	printf("\nResuma sua postagem:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",posts[numeros->Npostagens].resumo);
	
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o ID do autor:\n");
	SetColorAndBackground(0xFFF,0);
	showAuthorList(autores,numeros);
	limpaTeclado();
	int autorId = 0;
	scanf("%d",&autorId);
	posts[numeros->Npostagens].autor = autores[autorId];
	
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o ID da categoria:\n");
	SetColorAndBackground(0xFFF,0);
	showCatList(categorias,numeros);
	limpaTeclado();
	int catId = 0;
	scanf("%d",&catId);
	strcpy(posts[numeros->Npostagens].categoria, categorias[catId]);
	
	Data data;
	data.ano = 2015;
	data.mes = 10;
	data.dia = 21;
	posts[numeros->Npostagens].data = data;
	
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o conteudo da postagem:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",posts[numeros->Npostagens].conteudo);
	
	numeros->Npostagens++;
	
}

void addCategory(char categorias[100][100], Numeros *numeros) {
	system("cls");
	SetColorAndBackground(0,0xFFF);
	printf("Categorias existente:\n");
	SetColorAndBackground(0xFFF,0);
	showCatList(categorias,numeros);
	limpaTeclado();
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o nome da nova categoria:\n");
	SetColorAndBackground(0xFFF,0);
	scanf("%[^\n]s",categorias[numeros->Ncat]);
	numeros->Ncat++;
}

void addAuthor(Autor *autores, Numeros *numeros) {
	system("cls");
	SetColorAndBackground(0,0xFFF);
	printf("Autores existente:\n");
	SetColorAndBackground(0xFFF,0);
	showAuthorList(autores,numeros);
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite o nome do novo autor:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",autores[numeros->Nautores].nome);
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite a idade do novo autor:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%d",&autores[numeros->Nautores].idade);
	SetColorAndBackground(0,0xFFF);
	printf("\nDigite algo sobre o novo autor:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	scanf("%[^\n]s",autores[numeros->Nautores].about);
	numeros->Nautores++;
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

void refreshAuthor(Autor *autores, Numeros *numeros, int deletedPos) {
	int i=0;
	int elemCount=0;
	Autor autoresAux[100];
	for(i=deletedPos;i<numeros->Nautores;i++) {
		strcpy(autores[i].nome,autores[i+1].nome);
		strcpy(autores[i].about,autores[i+1].about);
		autores[i].idade = autores[i+1].idade;
	}
	numeros->Nautores--;
}

void refreshCategory(char categorias[100][100], Numeros *numeros, int deletedPos) {
	int i=0;
	int elemCount=0;
	Autor autoresAux[100];
	for(i=deletedPos;i<numeros->Ncat;i++) {
		strcpy(categorias[i],categorias[i+1]);
	}
	numeros->Ncat--;
}

void refreshPosts(Postagens *posts, Numeros *numeros, int deletedPos) {
	int i=0;
	int elemCount=0;
	Autor autoresAux[100];
	for(i=deletedPos;i<numeros->Ncat;i++) {
		strcpy(posts[i].titulo,posts[i+1].titulo);
		strcpy(posts[i].categoria,posts[i+1].categoria);
		strcpy(posts[i].conteudo,posts[i+1].conteudo);
		strcpy(posts[i].resumo,posts[i+1].resumo);
		strcpy(posts[i].autor.about,posts[i+1].autor.about);
		posts[i].autor.idade = posts[i+1].autor.idade;
		strcpy(posts[i].autor.nome,posts[i+1].autor.nome);
		posts[i].data.ano = posts[i+1].data.ano;
		posts[i].data.mes = posts[i+1].data.mes;
		posts[i].data.dia = posts[i+1].data.dia;
	}
	numeros->Npostagens--;
}

void deleteAuthor(Autor *autores, Numeros *numeros) {
	system("cls");
	SetColorAndBackground(0,0xFFF);
	printf("Autores existente:\n");
	SetColorAndBackground(0xFFF,0);
	showAuthorList(autores,numeros);
	SetColorAndBackground(0,0xFFF);
	printf("Digite o ID do usuário a ser deletado:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	int deletar=0;
	scanf("%d",&deletar);
	refreshAuthor(autores,numeros,deletar);
}

void deleteCategory(char categorias[100][100], Numeros *numeros) {
	system("cls");
	SetColorAndBackground(0,0xFFF);
	printf("Categorias existente:\n");
	SetColorAndBackground(0xFFF,0);
	showCatList(categorias,numeros);
	SetColorAndBackground(0,0xFFF);
	printf("Digite o ID da categoria a ser deletada:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	int deletar=0;
	scanf("%d",&deletar);
	refreshCategory(categorias,numeros,deletar);
}

void deletePost(Postagens *posts, Numeros *numeros) {
	system("cls");
	SetColorAndBackground(0,0xFFF);
	printf("Postagens existente:\n");
	SetColorAndBackground(0xFFF,0);
	int i=0;
	for(i=0;i<numeros->Npostagens;i++) {
		printf("%d - %s Postado por %s\n",i,posts[i].titulo,posts[i].autor.nome);
	}
	SetColorAndBackground(0,0xFFF);
	printf("Digite o ID do post a ser deletado:\n");
	SetColorAndBackground(0xFFF,0);
	limpaTeclado();
	int deletar=0;
	scanf("%d",&deletar);
	refreshPosts(posts,numeros,deletar);
}

void showPosts(Postagens *posts, Autor *autores,char categorias[100][100],Numeros *numeros) {
	system("cls");
	int i;
	for(i=0;i<numeros->Npostagens;i++) {
		SetColorAndBackground(0,0xFFF);
		printf("%s\n",posts[i].titulo);
		SetColorAndBackground(0xFFF,0);
		printf("Postado em: %d/%d/%d na Categoria %s\n",posts[i].data.dia,posts[i].data.mes,posts[i].data.ano,posts[i].categoria);	
		printf("%s\n\n",posts[i].resumo);
		printf("%s\n\n",posts[i].conteudo);
		printf("Sobre o Autor:\n%s,%d anos\n%s",posts[i].autor.nome,posts[i].autor.idade,posts[i].autor.about);
		printf("------------------------------------------");
	}
	printf("\n\nAperte qualquer tecla para voltar...");
	getch();
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
		printf("5 - Deletar Categoria\n");
		printf("6 - Deletar Autor\n");
		printf("7 - Deletar Postagem\n");
		
		printf("\n\n\nEscolha um menu:");
		scanf("%d",&opcao);
		switch (opcao) {
			case 1:
				addPost(posts,autores,categorias,&numeros);
				break;
			case 2:
				showPosts(posts,autores,categorias,&numeros);
				break;
			case 3:
				addCategory(categorias,&numeros);
				break;
			case 4:
				addAuthor(autores,&numeros);
				break;
			case 5:
				deleteCategory(categorias,&numeros);
				break;
			case 6:
				deleteAuthor(autores,&numeros);
				break;
			case 7:
				deletePost(posts,&numeros);
				break;
		}
	}
}
