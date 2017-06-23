#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
    int num[ID];
    int idCliente[ID];
    char produto[NOME];
    int qtd;
}nota;

// Deaclaração de funçõe
produto cadastrarProduto(produto prod[], int p);
produto consultarProduto(int p, char nome[], produto prod[], int *pp);
produto consultarProdutoId(int p, int id, produto prod[], int *pp);
produto excluirProduto(int i, produto prod[], int **ppp);
int validarCpf(int c, cliente cl[]);
cliente cadastrarCliente(int c, cliente cl[]);
cliente consultarCliente(int c, char nomeCl[], cliente cl[]);
cliente consultarClienteId(int c, int id, cliente cl[]);
produto ordenacaoProd(int p, produto prod[]);
cliente ordenacaoCl(int c, cliente cl[]);

// Função principal

int main() {
    produto vetProd[50];
    setlocale(LC_ALL,"portuguese");
    cliente cl[20];
    int op = 0, consProd = 0, ipProd = 0, consCl = 0, p = 0, n = 0, *pp = &p, id = 0, c = 0, opVenda = -1, qtd = 0;
    char opProd, opCl, nomeProd[NOME], nomeCl[NOME], cpf[12];

    // Menu de opções principal
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
                                system("cls");
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
                        consultarProduto(p, nomeProd, vetProd, &p);
                        system("cls");
                    } else
                        if (consProd == 2) {
                            printf("Digite o ID: ");
                            scanf("%d", &id);
                            system("cls");
                            consultarProdutoId(p, id, vetProd, &p);
                            fflush(stdin);
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

            // Lista de produto em ordem alfabética
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
                        opCl = getche();
                        system("cls");
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
                            }
                    } else {
                        printf("Atingido a quantidade maxima de cadastro.\nFavor volte e exclua algum cliente pelo menu:\n6 - Listar todos os clientes\n");
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

            // Lista de clientes em ordem alfabética
            case 6 :
                ordenacaoCl(c, cl);
                printf("\nPressione ENTER para voltar.");
                getchar();
                system("cls");
                break;

            // Realizar venda
            case 7 :
                while(opVenda < 0){
                    printf("1 - Realizar vendas\n");
                    printf("2 - Consultar NFs\n");
                    printf("3 - Consultar estoque\n");
                    printf("4 - Consultar cliente\n");
                    printf("5 - Voltar\n");
                    printf("Informe a opaco desejada: ");
                    scanf("%d", &opVenda);

                    if(opVenda == 1){

                    } else
                        if(opVenda == 2){

                        } else
                            if(opVenda == 3){
                                ordenacaoProd(p, vetProd);
                                printf("\nPressione ENTER para voltar.");
                                getchar();
                                system("cls");
                            } else
                                if (opVenda == 4){
                                    ordenacaoCl(c, cl);
                                    printf("\nPressione ENTER para voltar.");
                                    getchar();
                                    system("cls");
                                    break;
                                } else
                                    if (opVenda == 5){
                                        break;
                                    } else {
                                        printf("\nOpcao invalida!\n\n");
                                        printf("\nPressione ENTER para voltar.");
                                        getchar();
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

// Função para cadastrar produto

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

// Função para consultar produto por nome

produto consultarProduto(int p, char nome[], produto prod[], int *pp){
    int i, cont = 0, **ppp = &pp;
    char resp;
    for(i = 0; i < p; i++){
        if(strcmp(nome,prod[i].nome) == 0){
            cont += 1;
            excluirProduto(i, prod, &pp);
        }
    }
    if (cont < 1){
        do{
            printf("Produto não encontrado!\n");
            printf("1 - Voltar.");
            resp = getch();
        }while(resp != '1');
    }
}


// Função para consultar produto por ID

produto consultarProdutoId(int p, int id, produto prod[], int *pp){
int i, cont = 0, **ppp = &pp;
    char resp;
    for(i = 0; i < p; i++){
        if(id == prod[i].id){
            cont += 1;
            excluirProduto(i, prod, &pp);
        }
    }
    if (cont < 1){
        do{
            printf("Produto não encontrado!\n");
            printf("1 - Voltar.");
            resp = getch();
        }while(resp != '1');
    }
}

//Função para excluir Produtos

produto excluirProduto(int i, produto prod[], int **ppp){
    char resp = 0;
    do{
        system("cls");
        printf("Id %10.d | Nome: %s | R$ %10.2f | %10.d uni\n", prod[i].id, prod[i].nome, prod[i].preco, prod[i].qtd);
        printf("\n1 - Excluir Produto.");
        printf("\n2 - Voltar.");
        resp = getch();
        if (resp == '1'){
            do{
                system("cls");
                printf("Após excluir o produto você não poderá recupera-lo, deseja continuar?\n1 - Sim.\n2 - Não.");
                resp = 0;
                resp = getch();
                }while(resp != '1' && resp != '2');
                    if (resp == '1'){
                        if (**ppp > 1){
                        prod[i].id = prod[**ppp-1].id;
                        strcpy(prod[i].nome, prod[**ppp-1].nome);
                        prod[i].preco = prod[**ppp-1].preco;
                        prod[i].qtd = prod[**ppp-1].qtd;
                        **ppp -= 1;
                        }else{
                        prod[i].id = prod[**ppp].id;
                        strcpy(prod[i].nome, prod[**ppp].nome);
                        prod[i].preco = prod[**ppp].preco;
                        prod[i].qtd = prod[**ppp].qtd;
                        **ppp -= 1;
                        }
                        do{
                            system("cls");
                            printf("\nProduto excluído com sucesso!");
                            printf("\n1 - voltar.");
                            resp = 0;
                            resp = getch();
                        }while(resp != '1');
                    }
                }else
                if (resp == '2'){
                    break;
                }
    }while(resp != '1');
}

// Função para Cadastrar Cliente

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

// Função para validar CPF

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

// Função para consultar cliente por nome

cliente consultarCliente(int c, char nomeCl[], cliente cl[]){
    int i = 0;

    for(i = 0; i < c; i++){
        if(strcmp(nomeCl, cl[i].nome) == 0){
            printf("Id %10.d | Nome: %s | CPF: %s \n", cl[i].id, cl[i].nome, cl[i].cpf);
        }
    }
}

// Função para consultar cliente por ID

cliente consultarClienteId(int c, int id, cliente cl[]){
    int i = 0;

    for(i = 0; i < c; i++){
        if(id == cl[i].id){
            printf("Id %10.d | Nome: %s | CPF: %s \n", cl[i].id, cl[i].nome, cl[i].cpf);
        }
    }
}

// Função para ordenar produtos em ordem alfabetica

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

// Função para ordenar clientes em ordem alfabetica

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
