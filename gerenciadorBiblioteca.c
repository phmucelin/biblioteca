#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* fptr;

#define MAX_LIVROS 100

typedef struct infoLivros
{
    char nomeLivro[100];
    char autorLivro[100];
    char ano[100];
    char ISBN[100];
}livro;

livro list[MAX_LIVROS];

int totalLivros = 0;

/*primeiro de tudo criar as funcoes de cada coisa.*/

/*Pronto!*/
void postLivro()
{
    if(totalLivros>MAX_LIVROS)
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
    for(int i = 0; i<totalLivros; i++){
        if(strcmp(list[i].nomeLivro, nomeBusca) == 0){
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
        }else{
            printf("Livro nao encontrado!\n");
            return;
        }
    }
}
/*Pronto*/
void listarLivros()
{
    if(totalLivros==0){
        printf("Voce nao possui livros em sua lista!\n");
        return;
    }
    for(int i=0;i<totalLivros;i++){
        printf("Nome do Livro: %s\nAutor do Livro: %s\nAno do Livro: %s\nISBN: %s\n", list[i].nomeLivro, list[i].autorLivro, list[i].ano, list[i].ISBN);
    }
}

/*Ainda nao esta feito*/
void removeLivro()
{

}
    
/*Pronto*/
void buscaLivro()
{
    char bookname[100];
    if(totalLivros==0){
        printf("Voce nao possui livros em sua biblioteca!\n");
        return;
    }
    printf("Qual o nome do livro que voce deseja saber as informacoes?");
    scanf(" %[^\n]", bookname);
    for(int i=0;i<totalLivros;i++)
    {
        if(strcmp(list[i].nomeLivro, bookname) == 0){
            printf("Nome do Livro: %s\nAutor do Livro: %s\nAno do Livro: %s\nISBN: %s\n", list[i].nomeLivro, list[i].autorLivro, list[i].ano, list[i].ISBN);
        } else{
            printf("Livro nao encontrado!\n");
            return;
        }
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
        fprintf(fptr,"%s, %s, %s, %s\n", list[i].nomeLivro, list[i].autorLivro, list[i].ano, list[i].ISBN);
    }
    fclose(fptr);
    printf("Livros salvos com sucesso!\n");
}


int main(){

    return 0;
}