#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h> //time()

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 
const char BURN = 'x';

//left, up, right, down
int deltaL[] = {0, -1, 0, 1};
int deltaC[] = {-1, 0, 1, 0};
int qtd_lados = sizeof(deltaL) / sizeof(int);
//int bispo[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void shuffle(int vet[], int size){
    for(int i = 0; i < size; i++){
        int esc = rand() % size;
        int temp = vet[i];
        vet[i] = vet[esc];
        vet[esc] = temp;
    }

}

void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            printf(" %c", mat[l][c]);
        }
        puts("");
    }
    getchar();
}

int pegar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if( (l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0; // return 0;

    if(mat[l][c] != TREE)
        return 0;

    //mat[l][c] = FIRE;
    mat[l][c] = FIRE;
    mostrar_matriz(nl, nc, mat);
    int cont = 1;
    int neib[] = {0, 1, 2, 3};
    shuffle(neib, nl);
    for(int v = 0; v < nl; v++){
        int i = neib[v];
        cont += pegar_fogo(nl, nc, mat, l + deltaL[i], c + deltaC[i]);
    }
    mat[l][c] = BURN;
    mostrar_matriz(nl, nc, mat);

    /*
    cont += pegar_fogo(nl, nc, mat, l + 0, c - 1); //left
    cont += pegar_fogo(nl, nc, mat, l - 1, c + 0); //up
    cont += pegar_fogo(nl, nc, mat, l + 0, c + 1); //right
    cont += pegar_fogo(nl, nc, mat, l + 1, c + 0); //down
    */

    return cont;

}

int main(void)
{
    srand(time(NULL));

    int nl = 0; // numero de linhas
    int nc = 0; // numero de colunas

    puts("Digite as dimensoes da matriz!");
    scanf("%d %d", &nl, &nc);

    puts("Digite a porcentagem de arvores de 0--100");
    int porc_tree = 0; // porcentagem de arvores
    scanf("%d", &porc_tree);

    char mat[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(rand() % 101 <= porc_tree)
                mat[l][c] = TREE;
            
            else    
                mat[l][c] = EMPTY;
        }
    }

    mostrar_matriz(nl, nc, mat);

    puts("Indique a posicao que quer incendiar!");
    int l = 0; // linhas
    int c = 0; // colunas
    scanf("%d %d", &l, &c);

    
        //fgets(mat[i], sizeof(mat[i]), stdin);
    int total = 0;
    total = pegar_fogo(nl, nc, mat, l, c);
    mostrar_matriz(nl, nc, mat);

    printf("Tamanho do estrago: %d\n arvores queimadas", total);
    
    return 0;
}

/*
ler nl, nc, l(posicao da linha), c(posicao da coluna)
matriz[nl][nc]
pegar_fogo(mat, l, c)
*/
