#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
const int MORTO = 0;

void mostrar_vetor(int vet[], int size, int espada){
    printf("[");
    bool eh_o_primeiro = true;

    for(int i = 0; i < size; i++){
        if(vet[i] != MORTO){
            if(eh_o_primeiro){
                eh_o_primeiro = false;
                }
            
            else
                printf(" ");
            
            if(vet[i] == (espada + 1) && vet[i] > 0)
                printf("%d>", vet[i]);

            else if(vet[i] == (espada + 1) && vet[i] < 0)
                printf("<%d", vet[i]);

            else
                printf("%d", vet[i]);
              
        } 
    }
    printf("]\n");
}
// acha o proximo elemento vivo a partir de inicio + 1
int achar_vivo_dir(int vet[], int size, int inicio){

    int pos = (inicio + 1) % size;
    while(vet[pos] == MORTO)
        pos = (pos + 1) % size;
    
    
    return pos;
}

int achar_vivo_esq(int vet[], int size, int inicio){
    int pos;
    pos = ((inicio - 1) == -1) ? size - 1: inicio - 1;

    while(vet[pos] == MORTO)
    pos = ((pos - 1) == -1) ? size - 1 : pos - 1;

    return pos;
}

void descobrir_sinal_vetor(int vet[], int size, int sinal){
    /*if(sinal < 0){
        for(int i = 0; i < size; i++){
            if(i % 2 == 0)
                vet[i] = (i + 1) * (-1);
            
            else if(i % 2 == 1)
                vet[i] = i + 1;
        }   
    }

    else{
        for(int i = 1; i <= size; i++){
            if(i % 2 == 0)
                vet[i - 1] = i;
            
            else if(i % 2 == 1)
                vet[i] = (i + 1) * (-1);
        }
    }*/

    for(int i = 0; i < size; i++){
        vet[i] = (i + 1) * sinal;
        sinal *= -1;
    }

    /*
    for(int i = 0; i < size; i++){
        (vet[i - 1] < 0) ? ( ( (vet[i - 1]) * (-1) ) + 1) : ((vet[i - 1] + 1) * (-1));
    }
    */

}

int main(void)
{
    int size = 0;
    scanf("%d", &size);
    int vet[size];
    
    int esc = 0; //o escolhido
    scanf("%d", &esc);

    int sinal = 0;
    scanf("%d", &sinal);
    //setbuf(stdin, NULL);

    //for(int i = 1; i <= size; i++)
    //    vet[i - 1] = i;

    descobrir_sinal_vetor(vet, size, sinal);

    esc = esc - 1;
    mostrar_vetor(vet, size, esc);

    int qtd = size;
    //int salvar_esc;

    while(qtd > 1){
        
        int next;
        if(vet[esc] > 0){

            int vai_morrer = achar_vivo_dir(vet, size, esc);
            vet[vai_morrer] = MORTO;

            abs(esc);
            for(int i = 1; i <= vet[esc]; i++){
                next = achar_vivo_dir(vet, size, esc);
            }
        }

        else {
            int vai_morrer = achar_vivo_esq(vet, size, esc);
            vet[vai_morrer] = MORTO;

            abs(esc);
            for(int i = 1; i <= vet[esc]; i++){
                next = achar_vivo_esq(vet, size, esc);
            }
        }

        mostrar_vetor(vet, size, esc);

        esc = next;
        qtd--;
    }

    return 0;
}


//testes 4, 6, 8, 11 as vezes passa, as vezes não passa.