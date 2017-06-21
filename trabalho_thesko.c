#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID 10
#define NOME 100

// Registro para Produto

typedef struct produto{
    int id;
    char nome[NOME];
    float preco;
    int qtd;
}produto;

// Registro para Cliente

typedef struct cliente{
    int id[ID];
    char nome[NOME];
    int cpf[11];
}cliente;

// Registro para Nota Fiscal

typedef struct nota{
    int num[ID];
    int idCliente[ID];
    char produto[NOME];
    int qtd;
}nota;

// Deaclaração de funções

produto cadastrarProduto(produto prod[], int p);
produto consultarProduto(int p, char nome[NOME]);
int validarCpf(char cpf[12]);

// Função principal

int main() {
    produto vetProd[50];
    cliente cl[20];
    nota nf;
    int op = 0, x = 1, i = 0, consProd = 0, p = 0;
    char opProd, nomeProd[NOME], cpf[12];

    // Menu de opções principal
    while (op != 8){
        system("cls");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar produto\n");
        printf("3 - Listar todos os produtos\n");
        printf("4 - Cadastrar cliente\n");
        printf("5 - Consultar cliente\n");
        printf("6 - Listar todos os clientes\n");
        printf("7 - Realizar venda\n");
        printf("8 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);
        fflush(stdin);
        system("cls");

        // Escolhas de opções

        switch (op) {
            // Cadastrar produto
            case 1 :
                while (p < 50){
                    if(p < 50){
                        cadastrarProduto(vetProd,p);
                        p ++;
                        fflush(stdin);
                        printf("\nDeseja cadastrar outro produto? S/N\n");
                        opProd = getche();

                        if (opProd == 'S' || opProd == 's'){

                        } else
                            if (opProd == 'N' || opProd == 'n'){
                                system("cls");
                                break;
                            } else {
                                system("cls");
                                printf("Opcao invalida!\n\n");
                                system("pause");
                            }
                    } else {
                        printf("Atingido a quantidade maxima de cadastro.\nFavor volte e exclua algum produto pelo menu:\n3 - Listar todos os produtos\n");
                    }
                }
                break;

            // Consultar produto
            case 2 :
                while (consProd != 1 || consProd != 2 || consProd != 3){
                    printf("1 - Busca por nome\n");
                    printf("2 - Busca por ID\n");
                    printf("3 - Voltar\n\n");
                    printf("Digite a opcao desejada: ");
                    scanf("%d", &consProd);
                    system("cls");
                    fflush(stdin);

                    if (consProd == 1) {
                        printf("Digite o nome: ");
                        gets(nomeProd);
                        consultarProduto(p,nomeProd);
                    } else
                        if (consProd == 2) {
                            printf("Digite o ID: ");

                        } else
                            if (consProd == 3){

                            } else {
                                printf("\nOpcao invalida!\n\n");
                                system("pause");
                                system("cls");
                            }
                }
                break;

            case 3 :

                break;

            // Cadastrar cliente
            case 4 :
                printf("Informe o CPF: ");
                fgets(cpf,12,stdin);
                validarCpf(cpf);

                system("pause");
                break;

            case 5 :

                break;

            case 6 :

                break;

            case 7 :

                break;

            case 8 :
                printf("Logout realizado com sucesso.\n");
                break;

            default :
                printf("\nOpcao invalida!\n\n");
                system("pause");
                break;
        }
    }


    return 0;
}

// Função para cadastrar produto

produto cadastrarProduto(produto prod[], int p){
    int i = 0;

    for(i = p; i < 50; i++){
        printf("Digite o ID: ");
        scanf("%d", &prod[i].id);
        fflush(stdin);
        printf("Digite o nome: ");
        gets(prod[i].nome);
        printf("Informe o preco: R$ ");
        scanf("%f", &prod[i].preco);
        printf("Informe a quantidade: ");
        scanf("%d", &prod[i].qtd);
        break;
    }

}

// Função para consultar produto

produto consultarProduto(int p, char nome[]){
    int i = 0;


}

// Função para validar CPF

int validarCpf(char cpf[12]){
    int peso1[] = {10,9,8,7,6,5,4,3,2},
        peso2[] = {11,10,9,8,7,6,5,4,3,2},
        soma = 0,
        cpf2[11],
        i = 0;
    int primDigito = 0,
        segDigito = 0;

    for (i = 0; i < 11; i++){
        cpf2[i] = cpf[i] - 48;
    }
    for (i = 0; i < 9; i++){
        soma = soma + (cpf2[i] * peso1[i]);
    }

    primDigito = (soma % 11);

    if (primDigito < 2){
        primDigito = 0;
    } else {
        primDigito = 11 - primDigito;
    }

    soma = 0;
    for (i = 0; i < 10; i++){
        soma = soma + (cpf2[i] * peso2[i]);
    }

    segDigito = soma % 11;

    if (segDigito < 2){
        segDigito = 0;
    } else {
        segDigito = 11 - segDigito;
    }

    if (primDigito == cpf2[9] && segDigito == cpf2[10]){
        printf("CPF valido\n\n");
    } else {
        printf("CPF Invalido\n\n");
    }
}
