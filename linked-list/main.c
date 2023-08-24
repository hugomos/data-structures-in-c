#include <stdio.h>
#include <stdlib.h>

/*
Conceito de Lista Ligada:
  - Uma lista ligada é uma estrutura de dados fundamental em programação, usada para
  armazenar e organizar elementos de forma dinâmica. 
  
  - Diferentemente de arrays, onde os elementos são armazenados em posições contíguas de memória, 
  uma lista ligada permite a alocação dispersa dos elementos em memória, conectando-os através
  de ponteiros.
  
  - Cada nó da lista contém um valor e um ponteiro que aponta para o próximo nó (ou anterior
  em listas duplamente ligadas). As listas ligadas são úteis quando a quantidade de elementos
  não é conhecida antecipadamente ou quando inserções/remoções frequentes são necessárias.

Uso e Aplicações:
  - Armazenamento dinâmico de dados.
  - Manipulação eficiente de elementos em sequência.
  - Implementação de pilhas, filas e outras estruturas.

Funções Demonstradas:
  - Node* createNode(Node* head, int num)
    Cria um novo nó contendo o valor 'num' e o insere no início da lista.

  - void printNodes(Node* head)
    Imprime os valores dos nós presentes na lista.

  - Node* searchNode(Node* head, int num)
    Busca e retorna o nó com o valor 'num' na lista, ou NULL se não encontrado.

  - Node* removeNode(Node* head, int value)
    Remove o nó com o valor 'value' da lista e reorganiza os ponteiros.

  - Node* libera(Node *head)
    Libera a memória ocupada pelos nós da lista, evitando vazamentos de memória.

Estrutura do Código:
  - Definição da estrutura de nó.
  - Declaração das funções utilizadas.
  - Função 'main' que demonstra a criação, manipulação e liberação de nós na lista.

  Escrito por: ChatGPT, 24 de agosto de 2023
  Author do código: Vitor Hugo Oliveira <github.com/hugomos>
*/

// Definindo a estrutura nó
struct node {
  int value;
  struct node *previous;
};

typedef struct node Node;

// Função para criar um novo nó e inserir na frente da lista
Node* createNode(Node* head, int num) {
  Node* node = (Node*)malloc(sizeof(Node));
  
  node->value = num;
  node->previous = head;

  head = node;

  // Imprime informações sobre a criação do nó
  printf("\nCriacao: Endereco alocado para head:%p Conteudo:%d Anterior:%p", head, head->value, head->previous);

  return node;
}

// Função para imprimir os nós da lista
void printNodes(Node* head) {
  Node* aux = head;

  while(aux != NULL){
    // Imprime informações sobre cada nó na lista
    printf("\nPrint: Lista alocada para head:%p Conteudo:%d Anterior:%p", head, aux->value, aux->previous);
    aux = aux->previous;
  }
}

// Função para buscar um nó com um valor específico na lista
Node* searchNode(Node* head, int num) {
  Node* aux = head;

  while(aux != NULL && aux->value != num){
    aux = aux->previous;
  }

  if(aux == NULL) return NULL;

  // Imprime informações sobre o nó encontrado
  printf("\nBusca: Endereco alocado para head:%p Conteudo:%d Anterior:%p", head, aux->value, aux->previous);
  return aux;
}

// Função para remover um nó com um valor específico da lista
Node* removeNode(Node* head, int value) {
  Node* current = head;
  Node* prev = NULL;

  // Percorre a lista até encontrar o elemento a ser removido
  while (current != NULL && current->value != value) {
    prev = current;
    current = current->previous;
  }

  // Nó não encontrado
  if (current == NULL) return head;

  // Caso o nó seja o primeiro
  if (prev == NULL) {
    head = current->previous;
  } else {
    // Caso o nó seja qualquer outro
    prev->previous = current->previous;
  }

  // Imprime informações sobre a remoção do nó
  printf("\nRemove: Endereco alocado para head:%p Conteudo:%d Anterior:%p", head, current->value, current->previous);

  free(current);
  return head;
}

// Função para liberar a memória ocupada pelos nós da lista
Node *libera(Node *head) {
  Node *aux = head;
  Node *previous;

  while (aux != NULL) {
    previous = aux->previous;
    free(aux);
    aux = previous;
  }

  return NULL;
}

int main()
{
  // Iniciando a lista encadeada
  Node* head = NULL;
  printf("\nCriacao: Endereco alocado para head %p", head);

  printf("\n");

  // Criando e manipulando a lista
  head = createNode(head, 1);
  head = createNode(head, 2);
  head = createNode(head, 3);

  printf("\n");

  head = removeNode(head, 2);

  printf("\n");

  head = createNode(head, 4);
  head = createNode(head, 5);

  printf("\n");

  searchNode(head, 4);

  printf("\n");

  // Imprimindo a lista
  printNodes(head);

  // Liberando a memória ocupada pelos nós
  libera(head);

  return 0;
}
