#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* fptr;

#define MAX_LIVROS 100

typedef struct Livro
{
    char nomeLivro[100];
    char autorLivro[100];
    char ano[100];
    char ISBN[100];
}livro;
livro list[MAX_LIVROS];
int totalLivros = 0;

struct genero 
{
    char nomeCategoria[50];
    struct Livro livros[100];
    int totalLivros;
}genero;

struct genero generos[10];
int totalCategorias = 0;

/*Criacao OK*/
void criaCategoria()
{
    int choice;
    if(totalCategorias >= 10){
        printf("Voce atingiu o limite de categorias!\n");
        return;
    }
    printf("Digite qual o nome da categoria: ");
    scanf(" %[^\n]", generos[totalCategorias].nomeCategoria);
    totalCategorias++;
    printf("Categoria adicionada!\n");
}

/*Pronto!*/
void alocaLivros()
{
    char nameBusca[100];
    char categoriaBusca[100];
    printf("Qual o nome do livro que voce deseja alocar a alguma categoria? ");
    scanf(" %[^\n]", nameBusca);
    for(int i = 0; i<totalLivros; i++)
    {
        if(strcmp(list[i].nomeLivro, nameBusca) == 0){
            printf("Qual o nome da categoria que voce deseja adicionar este livro? ");
            scanf(" %[^\n]", categoriaBusca);
            for(int j = 0; j<totalCategorias; j++)
            {
                if(strcmp(generos[j].nomeCategoria, categoriaBusca) == 0)
                {
                    generos[j].livros[generos[j].totalLivros] = list[i];
                    printf("O nome desse livro foi adicionado a esta categoria!\n");
                    generos[j].totalLivros++;
                    return;
                }
            }
        }
        }
    }

/*Pronto!*/
void postLivro()
{
    if(totalLivros>=MAX_LIVROS)
    {
        printf("Sua biblioteca está lotada!\n");
        return;
    }

    printf("Qual o nome do livro? ");
    scanf(" %[^\n]", list[totalLivros].nomeLivro);

    printf("Qual o nome do autor do livro?");
    scanf(" %[^\n]", list[totalLivros].autorLivro);

    printf("Qual o ano de lancamento do livro? ");
    scanf(" %[^\n]", list[totalLivros].ano);

    printf("Qual o ISBN do livro? ");
    scanf(" %[^\n]", list[totalLivros].ISBN);

    totalLivros++;
}
/*SEMI*/
void editLivro()
{
    char nomeBusca[100];
    printf("Qual nome do livro que voce deseja buscar para editar? ");
    scanf(" %[^\n]", nomeBusca);
    char newName[100];
    int found = 0;
    for(int i = 0; i<totalLivros; i++){
        if(strcmp(list[i].nomeLivro, nomeBusca) == 0){
            found = 1;
            printf("Livro encontrado!\n");
            int choice;
            printf("O que voce deseja alterar? 1 - Nome, 2 - Autor, 3 - Ano, 4 - ISBN: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Qual sera o novo nome? ");
                scanf(" %[^\n]", newName);

                strcpy(list[i].nomeLivro, newName);

                printf("Nome alterado com sucesso, novo nome: %s\n", list[i].nomeLivro);
                
                break;
            
            default:
                break;
            }
        }
    }
    if(!found){
        printf("Livro nao encontrado!\n");
        return;
    }
}
/*Pronto*/
void listarLivros()
{
    if(totalCategorias == 0)
    {
        printf("Voce nao possui nenhuma categoria criada.\n");
        return;
    }
    for(int i=0;i<totalCategorias;i++){
        if(generos[i].totalLivros == 0)
        {
            printf("Voce nao possui livros nessa categoria!\n");
            continue;
        }
        printf("\nCategoria: %s\n", generos[i].nomeCategoria);
        for(int j = 0; j<generos[i].totalLivros; j++ )
        {
            printf("Livro: %s\nAno: %s\nAutor: %s\nISBN: %s\n", generos[i].livros[j].nomeLivro, generos[i].livros[j].ano, generos[i].livros[j].autorLivro, generos[i].livros[j].ISBN);
        }
    }
}
/*Pronto*/
void removeLivro()
{
    int found = 0;
    char nomeBuscaDelete[100];
    printf("Qual o nome do livro que voce deseja deletar? ");
    scanf(" %[^\n]", nomeBuscaDelete);
    for(int i=0;i<totalLivros;i++)
        {
            char deleted[] = "";
            if(strcmp(list[i].nomeLivro, nomeBuscaDelete) == 0)
            {
                strcpy(list[i].nomeLivro, deleted);
                strcpy(list[i].ano, deleted);
                strcpy(list[i].ISBN, deleted);
                strcpy(list[i].autorLivro, deleted);
                found = 1;
                printf("Livro deletado\n");
            }
        }
    if(!found)
    {
        printf("Livro nao encontrado!\n");
        return;
    }
}
/*Pronto*/
void buscaLivro()
{
    char bookname[100];
    if(totalLivros==0){
        printf("Voce nao possui livros em sua biblioteca!\n");
        return;
    }
    int found = 0;
    printf("Qual o nome do livro que voce deseja saber as informacoes?");
    scanf(" %[^\n]", bookname);
    for(int i=0;i<totalLivros;i++)
    {
        if(strcmp(list[i].nomeLivro, bookname) == 0){
            found = 1;
            printf("Nome do Livro: %s\nAutor do Livro: %s\nAno do Livro: %s\nISBN: %s\n", list[i].nomeLivro, list[i].autorLivro, list[i].ano, list[i].ISBN);
        } 
    }
    if(found == 0){
        printf("Livro nao encontrado!\n");
        return;
    }
    
}
/*Pronto*/
void salvaLivrosNoTXT()
{
    fptr = fopen("biblioteca.txt", "w");
    if(fptr == NULL){
        printf("Erro ao carregar arquivo!\n");
        return;
    }
    for(int i = 0; i<totalLivros;i++)
    {
        if(strcmp(list[i].nomeLivro, "") == 0)
            {
                continue;
            }
        fprintf(fptr,"%s, %s, %s, %s\n", list[i].nomeLivro, list[i].autorLivro, list[i].ano, list[i].ISBN);
    }
    fclose(fptr);
    printf("Livros salvos com sucesso!\n");
}

int main(){

    return 0;
}