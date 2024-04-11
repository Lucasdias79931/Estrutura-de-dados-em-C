#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct  Data
{
    int data;
}Data;

typedef struct Node
{
    Data *data;
    struct Node *next;
}Node;

bool isEpty(Node *no);

Data *startData(int valor){
    Data *newData = (Data *)malloc(sizeof(Data));
    
    if(newData == NULL){
        printf("\nErro de alocação de memória!");
        return;
    }

    newData->data = valor;

    return newData;
}

int main(){

    return 0;
}

bool isEpty(Node *no){
    if(no == NULL){
        return false;
    }else{
        return true;
    }
}