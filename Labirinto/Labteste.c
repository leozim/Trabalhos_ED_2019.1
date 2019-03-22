#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

const char WALL = '#';
const char PERSON = 'o'; //tava tentando por um bonequinho pra entrar no lab.
const char PATH = '.';

void mostrar_matriz(int nl, int nc, char mat[nl][nc]);


typedef struct _Pos{
    int l;
    int c;
} Pos;
    
#define pegar_vizinhos(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}} //pode usar qualquer nome de variável

//typedef struct {
//    Pos vet[4];
//} Neibs;

/*Neibs preencher_vizinhos(int l, int c){
    //vet[0] = (Pos){l, c - 1}; left
    //vet[1] = (Pos){l - 1, c}; up
    //vet[2] = (Pos){l, c + 1}; right
    //vet[3] = (Pos){l + 1, c}; down
    Neibs neibs = {{{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}};
    return neibs;

}*/

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux; 
    }
}

bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char parede){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return mat[l][c] == parede;
}

bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl, nc, mat, l, c, WALL))
        return false;

    int cont = 0;
    Pos neibs[] = pegar_vizinhos(l, c);
    for(int i = 0; i < 4; i++){
        if(equals(nl, nc, mat, neibs[i].l, neibs[i].c, WALL))
            cont++;  
    }
    if(cont < 3)
        return false;
    
    return true;

}

void passar_a_faca(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!eh_furavel(nl, nc, mat, l, c))
        return;

    mat[l][c] = ' '; 
    Pos neibs[] = pegar_vizinhos(l, c);
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++){
        passar_a_faca(nl, nc, mat, neibs[i].l, neibs[i].c);
    } //para todos os vizinhos

    //mostrar_matriz(nl, nc, mat);
    //getchar();
}


void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == WALL)
                printf("█");

            else
                printf("%c", mat[l][c]);
        }
        puts("");
    }
    //printf("l");
}

bool achar_caminho(int nl, int nc, char mat[nl][nc], int l, int c, bool matbool[nl][nc], int linha_final, int coluna_final){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nl))
        return false;
    if(mat[l][c] != ' ')
        return false;
    if(matbool[l][c] == true)
        return false;
    matbool[l][c] = true; // marca como visitado
    //mat[l][c] = PATH; // marca os pontos no chao

    if (l == linha_final && c == coluna_final)
        return true;
    Pos neibs[] = pegar_vizinhos(l, c);
    for(int i = 0; i < 4; i++){
        if(achar_caminho(nl, nc, mat, neibs[i].l, neibs[i].c, matbool, linha_final, coluna_final))
        return true;
    }
    
    mat[l][c] = PATH; 
    return false;
}


int main(void)
{
    srand(time(NULL));
    int nl = 0; 
    int nc = 0;

    puts("Digite o tamanho do labirinto: ");
    scanf("%d %d", &nl, &nc);


    char mat[nl][nc];
    //char * p  = &mat[0][0];
    bool matbool[nl][nc];

    for(int i = 0; i < nl; i++)
        for(int k = 0; k < nc; k++){
            mat[i][k] = WALL;
            matbool[i][k] = false; 
        }

    mostrar_matriz(nl, nc, mat);

    int local_linha = 0; //onde inicia o primeiro ponto
    int local_coluna = 0; //onde inicia o primeiro ponto

    puts("Digite ao local que deseja começar no labirinto: ");
    scanf("%d %d", &local_linha, &local_coluna);

    passar_a_faca(nl, nc, mat, local_linha, local_coluna);

    int linha_final = 0; //ponto final
    int coluna_final = 0; //ponto final
    scanf("%d %d", &linha_final, &coluna_final);

    achar_caminho(nl, nc, mat, local_linha, local_coluna, matbool, linha_final, coluna_final);
    mostrar_matriz(nl, nc, mat);
    
    // mostrar_matriz(nl, nc, mat);
    //printf("%d %d\n", nl, nc);
    //Pos vet[4] = pegar_vizinhos(l, c);

    return 0;
}