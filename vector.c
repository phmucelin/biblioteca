
#include <stdio.h>

int main()
{
    char *tipos[]={
        "ACAO", "TERROR", "ROMANCE", "COMEDIA", "DRAMA", "MISTERIO"
    };
    for(int i = 0; i<10; i++)
    {
        printf("%s\n", tipos[i]);
    }
    return 0;
}