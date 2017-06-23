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
    int num;
    int idCliente;
    char produto[NOME];
    int qtd;
}nota;

// Deaclaração de funçõe
produto cadastrarProduto(produto prod[], int p);
<<<<<<< HEAD
produto consultarProduto(char nome[], produto prod[], int *pp);
produto consultarProdutoId(int id, produto prod[], int *pp);
produto excluirProduto(int i, produto prod[], int **ppp);
int validarCpf(int c, cliente cl[]);
cliente cadastrarCliente(int c, cliente cl[]);
cliente consultarCliente(char nomeCl[], cliente cl[]);
cliente consultarClienteId(int id, cliente cl[]);
produto ordenacaoProd(int p, produto prod[]);
cliente ordenacaoCl(int c, cliente cl[]);
<<<<<<< HEAD
=======
nota notaFiscal(int p, int n, int id, int idPrd, int qtd, produto prod[], nota nf[]);
nota consultarNf(nota nf[], int n);
produto ordenacaoProdId(int p, produto prod[]);
void venda(int n, nota nf[], int c, int p, produto vetProd[], int id, int idPrd, int qtd);
>>>>>>> fabdd12746184fe7bf0ba33ecb3d58c8ef6360a1
=======
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
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf

// Função principal

int main() {
    produto vetProd[50];
    setlocale(LC_ALL,"portuguese");
    cliente cl[20];
<<<<<<< HEAD
<<<<<<< HEAD
    nota nf;
    int op = 0, x = 1, i = 0, consProd = 0, consCl = 0, p = 0, *pp = &p,id = 0, c = 0, opVenda = 0;
    char opProd, opCl, nomeProd[NOME], nomeCl[NOME], cpf[12];setlocale(LC_ALL,"portuguese");
=======
=======
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
    nota nf[100];

    /*  Variaveis
    op: Menu principal,
    consProd: Consultar Produto
    consCl: Consultar Cliente
    p: Controla quantidade de produtos cadastrados
    c: Controla quantidade de clientes cadastrados
    n: Controla o numero da NF
    opVenda: Opções para o menu Vendas
    opProd: Opções para o menu cadastrar produto
    opCl: Opções para o menu cadastrar cliente
    id: Consulta por ID
    idPrd: Consultar ID de produto  */

    int op = 0, id = 0, idPrd = 0, consProd = 0, consCl = 0, p = 0, c = 0, n = 0, opVenda = -1, qtd = 0;
    char opProd, opCl, nomeProd[NOME], nomeCl[NOME], cpf[12];
>>>>>>> fabdd12746184fe7bf0ba33ecb3d58c8ef6360a1

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
<<<<<<< HEAD
                        consultarProduto(nomeProd, vetProd, &p);
=======
                        consultarProduto(c, nomeProd, vetProd);
                        printf("\n\nDigite ENTER para voltar.");
                        getchar();
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
                        system("cls");
                    } else
                        if (consProd == 2) {
                            printf("Digite o ID: ");
                            scanf("%d", &id);
                            system("cls");
<<<<<<< HEAD
                            consultarProdutoId(id, vetProd, &p);
=======
                            consultarProdutoId(p, id, vetProd);
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
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

            // Lista de clientes em ordem alfabética
            case 6 :
                ordenacaoCl(c, cl);
                printf("\nPressione ENTER para voltar.");
                getchar();
                system("cls");
                break;

            // Realizar venda
            case 7 :
<<<<<<< HEAD
<<<<<<< HEAD
=======
                opVenda = -1;
>>>>>>> fabdd12746184fe7bf0ba33ecb3d58c8ef6360a1
=======
                opVenda = -1;
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
                while(opVenda < 0){
                    printf("1 - Realizar vendas\n");
                    printf("2 - Consultar NFs\n");
                    printf("3 - Consultar estoque\n");
                    printf("4 - Consultar cliente\n");
                    printf("5 - Voltar\n");
<<<<<<< HEAD
<<<<<<< HEAD
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


=======
=======
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
                    printf("\nInforme a opcao desejada: ");
                    scanf("%d", &opVenda);
                    fflush(stdin);
                    system("cls");

                    if(opVenda == 1){
<<<<<<< HEAD
                        ordenacaoCl(c, cl);
                        ordenacaoProdId(p, vetProd);
                        venda(n, nf, c, p, vetProd, id, idPrd, qtd);
=======
                        venda(n, nf, c, p, vetProd, id, idPrd, qtd, cl);
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf

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


<<<<<<< HEAD
>>>>>>> fabdd12746184fe7bf0ba33ecb3d58c8ef6360a1
=======
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
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

<<<<<<< HEAD
produto consultarProduto(char nome[], produto prod[], int *pp){
    int i, cont = 0, **ppp = &pp;
    char resp;
    for(i = 0; i < 50; i++){
=======
produto consultarProduto(int p, char nome[], produto prod[]){
    int i = 0;
    for(i = 0; i < p; i++){
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
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

<<<<<<< HEAD
produto consultarProdutoId(int id, produto prod[], int *pp){
    int i = 0, cont = 0, **ppp = &pp;
    char resp;
    for(i = 0; i < 50; i++){
            if(id == prod[i].id){
                cont += 1;
                excluirProduto(i,prod,&pp);
=======
produto consultarProdutoId(int p, int id, produto prod[]){
    int i = 0;
    for(i = 0; i < p; i++){
        if(id == prod[i].id){
            printf("Id %10.d | Nome: %s | R$ %10.2f | %10.d uni\n", prod[i].id, prod[i].nome, prod[i].preco, prod[i].qtd);
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
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
    char resp;
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
                resp = getch();
                }while(resp != '1' && resp != '2');
                    if (resp == '1'){
                        prod[i].id = prod[**ppp - 1].id;
                        strcpy(prod[i].nome, prod[**ppp - 1].nome);
                        prod[i].preco = prod[**ppp - 1].preco;
                        prod[i].qtd = prod[**ppp - 1].qtd;
                        **ppp -= 1;
                        do{
                            system("cls");
                            printf("\nProduto excluído com sucesso!");
                            printf("\n1 - voltar.");
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
<<<<<<< HEAD
<<<<<<< HEAD
=======

// Função para vendas

void venda(int n, nota nf[], int c, int p, produto vetProd[], int id, int idPrd, int qtd){

    do{
        printf("\n\nInforme o id do cliente: ");
        scanf("%d", &id);
    }while(id < 1 && id >= c);

    system("cls");

    do{
        printf("\n\nInforme o id do produto: ");
        scanf("%d", &idPrd);
    }while (idPrd < 1 && idPrd >= p);
=======

// Função para vendas

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
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf

    do{
        printf("Informe a quantidade desejada: ");
        scanf("%d", &qtd);
    } while (qtd > vetProd[idPrd - 1].qtd);
<<<<<<< HEAD

=======
    vetProd[idPrd - 1].qtd = vetProd[idPrd - 1].qtd - qtd;
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
    notaFiscal(p, n, id, idPrd, qtd, vetProd, nf);
}

// Função para gerar NF

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

// Função para consultar NF

nota consultarNf(nota nf[], int n){
    int i = 0;

    for (i = 0; i < n; i++){
        printf("\t Numero da Nota: %d \n\nID do Cliente: %d \nNome do produto: %s \nQuantidade: %d \n",nf[i].num, nf[i].idCliente, nf[i].produto, nf[i].qtd);
    }
}

// Função para ordenar por ID

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

<<<<<<< HEAD
>>>>>>> fabdd12746184fe7bf0ba33ecb3d58c8ef6360a1
=======
>>>>>>> 04cb62cf815744acde667ac5f1285cc7567c83bf
