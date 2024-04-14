#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Data
{
   char *book;
} Data;

typedef struct Node
{   
    struct Node *previous;
    Data *data;
    struct Node *next;
} Node;

typedef struct End
{
    Node *end;
} End;

void push(Node **ini, Data *data, End **end);
Data *creatData(char *book);

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    Node *Books = NULL;
    End *endList = NULL;

    // Adicionando um livro e apontando para a lista de fim
    push(&Books, creatData("sandman"), &endList);

    printf("\nPrimeira interação. Conteúdo de ini: %s\nConteúdo de end: %s",
    Books->data->book, endList->end->data->book);

   
    push(&Books, creatData("vademecum"), &endList);
    printf("\nSegunda interação. Conteúdo de ini: %s\nConteúdo de end: %s",
    Books->data->book, endList->end->data->book);

    return 0;
}

Data *creatData(char *book) {
    // Alocação de memória para a struct Data
    Data* newBook = (Data *)malloc(sizeof(Data));

    // Verificação se a alocação foi bem-sucedida
    if (newBook == NULL) {
        printf("\nErro na alocação de memória para novo livro!");
        return NULL; // Retornando NULL em caso de erro
    }
    
    // Alocação de memória para a string de livro, considerando o tamanho correto
    newBook->book = (char *)malloc((strlen(book) + 1) * sizeof(char));

    // Verificação se a alocação foi bem-sucedida
    if (newBook->book == NULL) {
        printf("\nErro na alocação de memória para o nome do livro!");
        free(newBook); // Liberando a memória alocada para newBook
        return NULL; // Retornando NULL em caso de erro
    }

    // Copiando o nome do livro para newBook->book
    strcpy(newBook->book, book);

    return newBook;
}

void push(Node **ini, Data *data, End **end) {
    // Alocação de memória para o novo nó
    Node *newNode = (Node *)malloc(sizeof(Node));
    

    // Verificação se a alocação foi bem-sucedida
    if (newNode == NULL) {
        printf("\nErro na alocação de memória para novo nó!");
        return;
    }

    // Configurando os valores do novo nó
    newNode->previous = NULL;
    newNode->data = data;
    newNode->next = NULL;

    // Verificando se a lista está vazia
    if (*ini == NULL) {
        // Se a lista está vazia, o novo nó será tanto o início quanto o fim da lista
        *ini = newNode;


        if (*end == NULL) {
            *end = (End *)malloc(sizeof(End));
            
            if (*end == NULL) {
                printf("\nErro na alocação de memória para o fim da lista!");
                free(newNode);
                return;
            }
        }

        (*end)->end = newNode;

       
    } else {
        
        Node *current = *ini;

        // Encontra o último nó na lista
        while (current->next != NULL) {
            current = current->next;
        }

        // Adiciona o novo nó após o último nó existente
        current->next = newNode;
        newNode->previous = current;

        // Atualiza o ponteiro de fim para apontar para o novo nó
        
        (*end)->end = newNode;
    }
}