/*
    Trabalho Grafos (Não direcional)
    Aluno: Luís Filipe Silva
    Professor: Kayo Henrique 
*/

#include <stdio.h>

int vertice = 0;

void linha() {
    printf("\n---------------------------------------\n");
}

void imprimir(int matriz[vertice][vertice]) {
    int i; // contador 1
    int j; // contador 2

    linha();
    printf("\n");
    for(i = 0; i < vertice; i++) {
        for(j = 0; j < vertice; j++) {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    linha();

    menu(matriz);
}

void remover_adjacencia(int matriz[vertice][vertice]) {
    system("clear"); // limpar console (win = cls, linux = clear)

    int num1, num2; // Vertices adjacentes

    printf("Digite um vertice de 1 a %d: ", vertice);
    scanf("%d", &num1);

    printf("Digite o vertice adjacente ao primeiro de 1 a %d: ", vertice);
    scanf("%d", &num2);

    matriz[num1 - 1][num2 - 1] = 0;
    matriz[num2 - 1][num1 - 1] = 0;

    imprimir(matriz);
}

void adicionar_adjacencia(int matriz[vertice][vertice]) {
    system("clear"); // limpar console (win = cls, linux = clear)

    int num1, num2; // Vertices adjacentes

    printf("Digite um vertice de 1 a %d: ", vertice);
    scanf("%d", &num1);

    printf("Digite o vertice adjacente ao primeiro de 1 a %d: ", vertice);
    scanf("%d", &num2);

    matriz[num1 - 1][num2 - 1] = 1;
    matriz[num2 - 1][num1 - 1] = 1;

    imprimir(matriz);
}

void menu(int matriz[vertice][vertice]) {

    int opcao = 0; // opcao do menu

    // Menu
    do {
        printf("Digite uma opcao:\n\n(1}Inserir adjacencia\n(2)Remover adjacencia\n(3)Imprimir grafo\n(4)Sair\n");
        scanf("%d", &opcao);

        // Condicional de erro
        if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
            printf("\n\nOpcao invalida!");
        }; 
    } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);

    switch(opcao){
        case 1:
            adicionar_adjacencia(matriz);
            break;
        case 2:
            remover_adjacencia(matriz);
            break;
        case 3:
            imprimir(matriz);
            break;
        case 4:
            system("pause"); // Pausar a aplicação
            break;
    }
}

void definir_vertice() {
    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &vertice);

    int i; // contador 1
    int j; // contador 2

    int matriz[vertice][vertice];
    
    // Atribuir a todas as posições da matriz o valor 0
    for(i = 0; i < vertice; i++) {
        for(j = 0; j < vertice; j++) {
            matriz[i][j] = 0;
        }
    };

    menu(matriz);
}

int main () {
    system("clear"); // limpar console (win = cls, linux = clear)
    definir_vertice();
    return 0;
}
