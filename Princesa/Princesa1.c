#include <stdio.h>

void girar_vetor(int v[], int size){
    int primeiro = v[0];
    
    for(int i = 1; i < size; i++){
        v[i - 1] = v[i];
    }

    v[size - 1] = primeiro;
}

int main(void)
{
    int size, espada;
    scanf("%d %d", &size, &espada);

    int v[size];

    for(int i = 0; i < size; i++){
        v[i] = i + 1;
    }

    while(v[0] != espada){
        girar_vetor(v, size);
    }

    while(size > 1){
        girar_vetor(v, size);
        girar_vetor(v, size);

        size--;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }

    return 0;
}