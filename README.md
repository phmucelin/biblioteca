alterar chegando em casa

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

                printf("Nome alterado com sucesso!\nNovo nome: %s\n", list[i].nomeLivro);
                
                break;

            case 2:
                printf("Qual sera o novo nome do autor?\n");
                scanf(" %[^\n]", newName);

                strcpy(list[i].autorLivro, newName);

                printf("Nome do autor alterado com sucesso!\nNovo autor: %s\n", list[i].autorLivro);

                break;
            
            case 3:
                printf("Qual sera o ano do lancamento do livro?\n");
                scanf(" %[^\n]", newName);

                strcpy(list[i].ano, newName);

                printf("O ano do filme foi alterado!\nAno corrigido: %s\n", list[i].ano);
            
            case 4:
                printf("Qual sera o novo ISBN do livro?\n");
                scanf(" %[^\n]", newName);

                strcpy(list[i].ISBN, newName);

                printf("O ISBN do livro foi alterado!\nNovo ISBN: %s", list[i].ISBN);
            default:
                break;
            }
        }
        else
            {
                printf("Livro nao encontrado!\n");
                return;
            }
    }
}
