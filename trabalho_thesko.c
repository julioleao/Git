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
    int id;
    char nome[NOME];
    char cpf[12];
}cliente;

// Registro para Nota Fiscal

typedef struct nota{
    int num;
    int idCliente;
    char produto[NOME];
    int qtd;
}nota;

// Deaclara��o de fun��es

produto cadastrarProduto(produto prod[], int p);
produto consultarProduto(int p, char nome[], produto prod[]);
produto consultarProdutoId(int p, int id, produto prod[]);
int validarCpf(int c, cliente cl[]);
cliente cadastrarCliente(int c, cliente cl[]);
cliente consultarCliente(int c, char nomeCl[], cliente cl[]);
cliente consultarClienteId(int c, int id, cliente cl[]);
produto ordenacaoProd(int p, produto prod[]);
cliente ordenacaoCl(int c, cliente cl[]);
nota notaFiscal(int p, int n, int id, int idPrd, int qtd, produto prod[], nota nf[]);
nota consultarNf(nota nf[], int n);
produto ordenacaoProdId(int p, produto prod[]);
void venda(int n, nota nf[], int c, int p, produto vetProd[], int id, int idPrd, int qtd, cliente cl[]);

// Fun��o principal

int main() {
    produto vetProd[50];
    cliente cl[20];
    nota nf[100];

    /*  Variaveis
    op: Menu principal,
    consProd: Consultar Produto
    consCl: Consultar Cliente
    p: Controla quantidade de produtos cadastrados
    c: Controla quantidade de clientes cadastrados
    n: Controla o numero da NF
    opVenda: Op��es para o menu Vendas
    opProd: Op��es para o menu cadastrar produto
    opCl: Op��es para o menu cadastrar cliente
    id: Consulta por ID
    idPrd: Consultar ID de produto  */

    int op = 0, id = 0, idPrd = 0, consProd = 0, consCl = 0, p = 0, c = 0, n = 0, opVenda = -1, qtd = 0;
    char opProd, opCl, nomeProd[NOME], nomeCl[NOME], cpf[12];

    // Menu de op��es principal
    while (op != 8){
        system("cls");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar produto\n");
        printf("3 - Listar todos os produtos\n");
        printf("4 - Cadastrar cliente\n");
        printf("5 - Consultar cliente\n");
        printf("6 - Listar todos os clientes\n");
        printf("7 - Vendas\n");
        printf("8 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);
        fflush(stdin);
        system("cls");

        // Escolhas de op��es

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
                        system("cls");
                        if (opProd == 'S' || opProd == 's'){

                        } else
                            if (opProd == 'N' || opProd == 'n'){
                                system("cls");
                                break;
                            } else {
                                system("cls");
                                printf("Opcao invalida!\n\n");
                                printf("\nPressione ENTER para voltar.");
                                getchar();
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
                        system("cls");
                        consultarProduto(c, nomeProd, vetProd);
                        printf("\n\nDigite ENTER para voltar.");
                        getchar();
                        system("cls");
                    } else
                        if (consProd == 2) {
                            printf("Digite o ID: ");
                            scanf("%d", &id);
                            system("cls");
                            consultarProdutoId(p, id, vetProd);
                            fflush(stdin);
                            printf("\n\nPressione ENTER para voltar.");
                            getchar();
                            system("cls");
                        } else
                            if (consProd == 3){
                                break;
                            } else {
                                printf("\nOpcao invalida!\n\n");
                                printf("\nPressione ENTER para voltar.");
                                getchar();
                                system("cls");
                            }
                }
                break;

            // Lista de produto em ordem alfab�tica
            case 3 :
                ordenacaoProd(p, vetProd);
                printf("\nPressione ENTER para voltar.");
                getchar();
                system("cls");
                break;

            // Cadastrar cliente
            case 4 :
                while (c < 20){
                    if(c < 20){
                        cadastrarCliente(c, cl);
                        while(c > -1){
                            printf("Informe o CPF: ");
                            fgets(cl[c].cpf,12,stdin);
                            validarCpf(c,cl);
                            if(validarCpf(c,cl) != 1){
                                printf("CPF invalido!\nDigite novamente\n\n");
                            } else {
                                printf("CPF valido!\n\n");
                                break;
                            }
                        }
                        c ++;
                        fflush(stdin);

                            printf("\nDeseja cadastrar outro cliente? S/N\n");
                        do{
                            opCl = getche();
                        }while(opCl != 'S' || opCl != 'N');

                        if (opCl == 'S' || opCl == 's'){

                        } else
                            if (opCl == 'N' || opCl == 'n'){
                                system("cls");
                                break;
                            } else {
                                system("cls");
                                printf("Opcao invalida!\n\n");
                                printf("\nPressione ENTER para voltar.");
                                getchar();
                                system("cls");
                            }
                    } else {
                        printf("Atingido a quantidade maxima de cadastro.\nFavor volte e exclua algum cliente\n");
                    }
                }
                break;

            // Consultar cliente
            case 5 :
                while (consCl != 1 || consCl != 2 || consCl != 3){
                    printf("1 - Busca por nome\n");
                    printf("2 - Busca por ID\n");
                    printf("3 - Voltar\n\n");
                    printf("Digite a opcao desejada: ");
                    scanf("%d", &consCl);
                    system("cls");
                    fflush(stdin);

                    if (consCl == 1) {
                        printf("Digite o nome: ");
                        gets(nomeCl);
                        system("cls");
                        consultarCliente(c, nomeCl, cl);
                        printf("\n\nDigite ENTER para voltar.");
                        getchar();
                        system("cls");
                    } else
                        if (consCl == 2) {
                            printf("Digite o ID: ");
                            scanf("%d", &id);
                            system("cls");
                            consultarClienteId(c, id, cl);
                            fflush(stdin);
                            printf("\n\nPressione ENTER para voltar.");
                            getchar();
                            system("cls");
                        } else
                            if (consCl == 3){
                                break;
                            } else {
                                printf("\nOpcao invalida!\n\n");
                                printf("\nPressione ENTER para voltar.");
                                getchar();
                                system("cls");
                            }
                }
                break;

            // Lista de clientes em ordem alfab�tica
            case 6 :
                ordenacaoCl(c, cl);
                printf("\nPressione ENTER para voltar.");
                getchar();
                system("cls");
                break;

            // Realizar venda
            case 7 :
                opVenda = -1;
                while(opVenda < 0){
                    printf("1 - Realizar vendas\n");
                    printf("2 - Consultar NFs\n");
                    printf("3 - Consultar estoque\n");
                    printf("4 - Consultar cliente\n");
                    printf("5 - Voltar\n");
                    printf("\nInforme a opcao desejada: ");
                    scanf("%d", &opVenda);
                    fflush(stdin);
                    system("cls");

                    if(opVenda == 1){
                        venda(n, nf, c, p, vetProd, id, idPrd, qtd, cl);

                        n++;
                        opVenda = -1;
                    } else
                        if(opVenda == 2){

                        consultarNf(nf, n);

                        printf("\nPressione ENTER para voltar.");
                        getchar();
                        system("cls");
                        opVenda = -1;
                        } else
                            if(opVenda == 3){
                                ordenacaoProd(p, vetProd);
                                printf("\nPressione ENTER para voltar.");
                                getchar();
                                system("cls");
                                opVenda = -1;
                            } else
                                if (opVenda == 4){
                                    ordenacaoCl(c, cl);
                                    printf("\nPressione ENTER para voltar.");
                                    getchar();
                                    system("cls");
                                    opVenda = -1;
                                } else
                                    if (opVenda == 5){
                                        break;
                                    } else {
                                        printf("\nOpcao invalida!\n\n");
                                        printf("\nPressione ENTER para voltar.");
                                        getchar();
                                        opVenda = -1;
                                        system("cls");
                                    }


                }
                break;

            // Sair do sistema
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

// Fun��o para cadastrar produto

produto cadastrarProduto(produto prod[], int p){
    int i = 0;

    for(i = p; i < 50; i++){
        prod[i].id = p + 1;
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

// Fun��o para consultar produto por nome

produto consultarProduto(int p, char nome[], produto prod[]){
    int i = 0;
    for(i = 0; i < p; i++){
        if(strcmp(nome,prod[i].nome) == 0){
            printf("Id %10.d | Nome: %s | R$ %10.2f | %10.d uni\n", prod[i].id, prod[i].nome, prod[i].preco, prod[i].qtd);
        }
    }
}

// Fun��o para consultar produto por ID

produto consultarProdutoId(int p, int id, produto prod[]){
    int i = 0;
    for(i = 0; i < p; i++){
        if(id == prod[i].id){
            printf("Id %10.d | Nome: %s | R$ %10.2f | %10.d uni\n", prod[i].id, prod[i].nome, prod[i].preco, prod[i].qtd);
        }
    }
}

// Fun��o para Cadastrar Cliente

cliente cadastrarCliente(int c, cliente cl[]){
    int i = 0;

    for(i = c; i < 50; i++){
        cl[i].id = c + 1;
        fflush(stdin);
        printf("Digite o nome: ");
        gets(cl[i].nome);

        break;
    }
}

// Fun��o para validar CPF

int validarCpf(int c, cliente cl[]){
    int peso1[] = {10,9,8,7,6,5,4,3,2},
        peso2[] = {11,10,9,8,7,6,5,4,3,2},
        soma = 0,
        cpf2[11],
        i = 0;
    int primDigito = 0,
        segDigito = 0;

    for (i = 0; i < 11; i++){
        cpf2[i] = cl[c].cpf[i] - 48;
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
        return 1;
    } else {
        return 0;
    }
}

// Fun��o para consultar cliente por nome

cliente consultarCliente(int c, char nomeCl[], cliente cl[]){
    int i = 0;

    for(i = 0; i < c; i++){
        if(strcmp(nomeCl, cl[i].nome) == 0){
            printf("Id %10.d | Nome: %s | CPF: %s \n", cl[i].id, cl[i].nome, cl[i].cpf);
        }
    }
}

// Fun��o para consultar cliente por ID

cliente consultarClienteId(int c, int id, cliente cl[]){
    int i = 0;

    for(i = 0; i < c; i++){
        if(id == cl[i].id){
            printf("Id %10.d | Nome: %s | CPF: %s \n", cl[i].id, cl[i].nome, cl[i].cpf);
        }
    }
}

// Fun��o para ordenar produtos em ordem alfabetica

produto ordenacaoProd(int p, produto prod[]){
    int i = 0, j = 0, auxQtd, auxId;
    char aux[NOME];
    float auxPreco;

    for (i = 0; i < p; i++){
        for(j = i + 1; j < p; j++){
            if(strcmp(prod[i].nome,prod[j].nome) > 0){
                strcpy(aux,prod[j].nome);
                strcpy(prod[j].nome,prod[i].nome);
                strcpy(prod[i].nome,aux);
                auxId = prod[j].id;
                prod[j].id = prod[i].id;
                prod[i].id = auxId;
                auxPreco = prod[j].preco;
                prod[j].preco = prod[i].preco;
                prod[i].preco = auxPreco;
                auxQtd = prod[j].qtd;
                prod[j].qtd = prod[i].qtd;
                prod[i].qtd = auxQtd;
            }
        }
    }

    for (i = 0; i < p; i++){
        printf("Id %10.d | Nome: %s | R$ %10.2f | %10.d uni\n", prod[i].id, prod[i].nome, prod[i].preco, prod[i].qtd);
    }
}

// Fun��o para ordenar clientes em ordem alfabetica

cliente ordenacaoCl(int c, cliente cl[]){
    int i = 0, j = 0, auxQtd, auxId;
    char aux[NOME];
    float auxPreco;

    for (i = 0; i < c; i++){
        for(j = i + 1; j < c; j++){
            if(strcmp(cl[i].nome,cl[j].nome) > 0){
                strcpy(aux,cl[j].nome);
                strcpy(cl[j].nome,cl[i].nome);
                strcpy(cl[i].nome,aux);
                auxId = cl[j].id;
                cl[j].id = cl[i].id;
                cl[i].id = auxId;
                strcpy(aux,cl[j].cpf);
                strcpy(cl[j].cpf,cl[i].cpf);
                strcpy(cl[i].cpf,aux);
            }
        }
    }

    for (i = 0; i < c; i++){
        printf("Id %10.d | Nome: %s | CPF %s\n", cl[i].id, cl[i].nome, cl[i].cpf);
    }
}

// Fun��o para vendas

void venda(int n, nota nf[], int c, int p, produto vetProd[], int id, int idPrd, int qtd, cliente cl[]){
    system("cls");
    ordenacaoCl(c, cl);
    do{
        printf("\nInforme o id do cliente: ");
        scanf("%d", &id);
    }while(id < 1 || id > c);

    system("cls");
    ordenacaoProdId(p, vetProd);
    do{
        printf("\nInforme o id do produto: ");
        scanf("%d", &idPrd);
    }while (idPrd < 1 || idPrd > p);

    do{
        printf("Informe a quantidade desejada: ");
        scanf("%d", &qtd);
    } while (qtd > vetProd[idPrd - 1].qtd);
    vetProd[idPrd - 1].qtd = vetProd[idPrd - 1].qtd - qtd;
    notaFiscal(p, n, id, idPrd, qtd, vetProd, nf);
}

// Fun��o para gerar NF

nota notaFiscal(int p, int n, int id, int idPrd, int qtd, produto prod[], nota nf[]){
    int i = 0, j = 0;

    for(i = n; i < 100; i++){
        nf[i].num = n + 1;
        nf[i].idCliente = id;
        for(j = 0; j < p; j++){
            if (prod[j].id == idPrd){
                strcpy(nf[i].produto, prod[j].nome);
            }
        }
        nf[i].qtd = qtd;
        break;
    }
}

// Fun��o para consultar NF

nota consultarNf(nota nf[], int n){
    int i = 0;

    for (i = 0; i < n; i++){
        printf("\t Numero da Nota: %d \n\nID do Cliente: %d \nNome do produto: %s \nQuantidade: %d \n",nf[i].num, nf[i].idCliente, nf[i].produto, nf[i].qtd);
    }
}

// Fun��o para ordenar por ID

produto ordenacaoProdId(int p, produto prod[]){
    int i = 0, j = 0, auxQtd, auxId;
    char aux[NOME];
    float auxPreco;

    for (i = 0; i < p; i++){
        for(j = i + 1; j < p; j++){
            if(prod[i].id > prod[j].id){
                strcpy(aux,prod[j].nome);
                strcpy(prod[j].nome,prod[i].nome);
                strcpy(prod[i].nome,aux);
                auxId = prod[j].id;
                prod[j].id = prod[i].id;
                prod[i].id = auxId;
                auxPreco = prod[j].preco;
                prod[j].preco = prod[i].preco;
                prod[i].preco = auxPreco;
                auxQtd = prod[j].qtd;
                prod[j].qtd = prod[i].qtd;
                prod[i].qtd = auxQtd;
            }
        }
    }
     for (i = 0; i < p; i++){
        printf("Id %10.d | Nome: %s | R$ %10.2f | %10.d uni\n", prod[i].id, prod[i].nome, prod[i].preco, prod[i].qtd);
    }
}

