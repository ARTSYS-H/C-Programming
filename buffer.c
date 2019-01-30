#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPA 5
#define ZMAX 4

typedef struct
{
    char tab[ZMAX+1];

}string;

typedef struct
{
    string buf[CAPA];
    int last;
    int size;

}buffer;

void initBufffer(buffer* b)
{
    //on initialise le buffer
    //on remplis le buffer avec des chaines vide

    b->last = -1;
    b->size = 0;
    
    for(int i = 0; i < CAPA; i++)
    {
        strcpy(b->buf[i].tab, "\0");
    }
    
}

void put(buffer* b, char* str)
{
    //si le buffer n'est pas plein
    //on copie la chaine passée en paramètre dans l'emplacement libre suivant du buffer
    //on incremente la variable size et la variable last

    if (b->size == CAPA) 
    {
        printf("Erreur (put): La file est pleine !\n");
    }
    else
    {
        b->last = b->last + 1;
        if(b->last == CAPA)
        {
            b->last = 0;
        }
        strcpy(b->buf[b->last].tab, str);
        b->size = b->size + 1;
    }  
    
}

void get(buffer* b, char* dest)
{
    //si le buffer n'est pas vide
    //on determine la chaine la plus ancienne de la file
    //et on copie cette chaine dans le tampon passé en paramètre 
    //Formule théorique : (last+1)%size

    if (b->size == 0) 
    {
        printf("Erreur (get): La file est vide !\n");
    }
    else
    {
        int old;

        old = (b->last + 1) % b->size;
        strcpy(dest, b->buf[old].tab);

        b->size = b->size - 1;
    }
    
}

void affichBuffer(buffer* b)
{
    //permet d'afficher l'état du buffer
    //affiche le la chaine de chaque emplacement du buffer

    printf("last = %d et size = %d\n", b->last, b->size);
    printf("/*\n");
    for(int i = 0; i < CAPA; i++)
    {
        printf("Buf[%d] = %s\n", i, b->buf[i].tab);
    }
    printf("*/\n");
}

int main(int argc, char const *argv[])
{
    buffer b;
    char tampon[ZMAX+1];

    initBufffer(&b);
    put(&b, "Tim");
    put(&b, "Tom");
    put(&b, "Rob");
    get(&b, tampon);
    printf("%s\n", tampon);
    put(&b, "Pim");
    put(&b, "Poum");
    get(&b, tampon);
    printf("%s\n", tampon);
    put(&b, "doom");
    affichBuffer(&b);

    return 0;
}
