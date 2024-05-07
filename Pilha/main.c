#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




typedef struct  Data
{
    char *book;
}Data;

typedef struct Node
{
    Data *data;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node *base;
    Node *top;
}Stack;

bool isEpty(Stack *stack);
Data *createData(char *book);
void initializeStack(Stack *stack);
void push(Stack *stack, Data *data);
char *pop(Stack *stack);


void print(Stack *stack){
        Node *current = stack->base;

    while(current != NULL){ 
        printf("\n%s",current->data->book);
        current = current->next;
    }
}
int main(){

    Stack *stack = (Stack *) malloc(sizeof(Stack));
    initializeStack(stack);

    push(stack,createData("sandman"));
    push(stack,createData("ana"));
    push(stack,createData("paulo"));

    print(stack);

    char *temp = pop(stack);

    print(stack);
    

    
    
    

    return 0;
}


void initializeStack(Stack *stack){
    stack->base = NULL;
    stack->top = NULL;
}

bool isEpty(Stack *stack){
    return stack->base == NULL;
}
Data *createData(char *book) {
    Data *newBook = (Data *)malloc(sizeof(Data));
   
    if (newBook == NULL) {
        printf("\nErro na alocação de memória para novo livro!");
        return NULL;
    }

    newBook->book = (char *)malloc((strlen(book) + 1) * sizeof(char));

    if (newBook->book == NULL) {
        printf("\nErro na alocação de memória para o nome do livro!");
        free(newBook);
        return NULL;
    }

    strcpy(newBook->book, book);

    return newBook;
}
void push(Stack *stack, Data *data){
    Node *newNode = (Node *) malloc(sizeof(Node));
    
   
    if(newNode == NULL){
        printf("\nErro na alocacao para um novo no");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(stack->base == NULL){
        stack->base = newNode;
        stack->top = newNode;
    }else{
        stack->top->next = newNode;
        stack->top = newNode;
    }

}


char *pop(Stack *stack) {
    if (stack->top == NULL) // Verifica se a pilha está vazia
        return NULL;

    char *book = (char *)malloc((strlen(stack->top->data->book) + 1) * sizeof(char)); // Aloca memória para o livro
    if (book == NULL) {
        printf("\nErro na alocação de memória para o livro!");
        return NULL;
    }

    strcpy(book, stack->top->data->book); // Copia o livro

    Node *temp = stack->top;
    if (stack->top == stack->base) { // Caso haja apenas um nó na pilha
        stack->top = NULL;
        stack->base = NULL;
    } else {
        Node *current = stack->base;
        while (current->next != stack->top) {
            current = current->next;
        }
        current->next = NULL;
        stack->top = current;
    }

    free(temp->data->book);
    free(temp->data);
    free(temp);

    return book;
}




/*




push(item): Adiciona um elemento ao topo da pilha.
pop(): Remove e retorna o elemento no topo da pilha.
peek(): Retorna o elemento no topo da pilha sem removê-lo.
isEmpty(): Verifica se a pilha está vazia.
size(): Retorna o número de elementos na pilha.

clear(): Remove todos os elementos da pilha.
search(item): Retorna a posição do item na pilha (contando a partir do topo), ou -1 se o item não estiver na pilha.
isFull(): Verifica se a pilha está cheia (se for uma pilha com tamanho fixo).
copy(): Retorna uma cópia da pilha.
reverse(): Inverte a ordem dos elementos na pilha.
merge(stack): Combina duas pilhas em uma.
iterate(): Permite iterar sobre os elementos da pilha.





*/