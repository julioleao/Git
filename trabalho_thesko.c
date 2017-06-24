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

// Deaclaração de funções

produto cadastrarProduto(produto prod[], int p);
produto consultarProduto(int p, char nome[], produto prod[], int *pp);
produto consultarProdutoId(int p, int id, produto prod[], int *pp);
produto excluirProduto(int i, produto prod[], int **ppp);
int validarCpf(int c, cliente cl[]);
cliente cadastrarCliente(int c, cliente cl[]);
cliente consultarCliente(int c, char nomeCl[], cliente cl[], int *cc);
cliente consultarClienteId(int c, int id, cliente cl[], int *cc);
cliente excluirCliente(int i, cliente cl[], int **ccc);
produto ordenacaoProd(int p, produto prod[]);
cliente ordenacaoCl(int c, cliente cl[]);
nota notaFiscal(int p, int n, int id, int idPrd, int qtd, produto prod[], nota nf[]);
nota consultarNf(nota nf[], int n);
produto ordenacaoProdId(int p, produto prod[]);
void venda(int n, nota nf[], int c, int p, int id, int idPrd, produto vetProd[], int qtd, cliente cl[]);
int validarStrings(char nome[]);
int validarInteiro(char numero[]);
float validarFloat(char numero[]);

// Função principal

int main() {
    produto vetProd[50];
    cliente cl[20];
    nota nf[100];
    setlocale(LC_ALL,"portuguese");
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

    int op = 0, id = 0, idPrd = 0, consProd = 0, consCl = 0, p = 0, *pp = &p, c = 0, *cc = &c, n = 0, opVenda = -1, qtd = 0;
    char opProd, opCl, nomeProd[NOME], nomeCl[NOME], cpf[12], idVendaP[51], idVendaC[21];

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
                        do{
                            opProd = getch();
                        }while(opProd != 'S' && opProd != 'N' && opProd != 's' && opProd != 'n');
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
                        do{
                            system("cls");
                            printf("Digite o nome: ");
                            gets(nomeProd);
                        }while (validarStrings(nomeProd) == 0);
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
                        c ++;
                        fflush(stdin);

                            printf("\nDeseja cadastrar outro cliente? S/N\n");
                        do{
                            opCl = getch();
                        } while (opCl != 'S' && opCl != 'N' && opCl != 's' && opCl != 'n');
                            if (opCl == 'S' || opCl == 's'){
                                system("cls");
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
                        do{
                            system("cls");
                            printf("Digite o nome: ");
                            gets(nomeCl);
                        }while (validarStrings(nomeCl) == 0);
                        system("cls");
                        consultarCliente(c, nomeCl, cl, &c);
                        system("cls");
                    } else
                        if (consCl == 2) {
                            printf("Digite o ID: ");
                            scanf("%d", &id);
                            system("cls");
                            consultarClienteId(c, id, cl, &c);
                            fflush(stdin);
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
                        venda(n, nf, c, p, id, idPrd, vetProd, qtd, cl);

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
                printf("Digite ENTER para voltar.");
                getchar();
                break;
        }
    }

    return 0;
}

// Função para cadastrar produto

produto cadastrarProduto(produto prod[], int p){
    int i = 0;
    char qtd[10], preco[10];
    float x;


    for(i = p; i < 50; i++){
        prod[i].id = p + 1;
        fflush(stdin);
        do{
            system("cls");
            printf("Digite o nome: ");
            gets(prod[i].nome);
        } while (validarStrings(prod[i].nome) == 0);

        printf("Informe o preco: R$ ");
        do{
            gets(preco);
            prod[i].preco = atof(preco);
        } while (validarFloat(preco) == 0);

        printf("Informe a quantidade: ");
        do{
            gets(qtd);
        }while(validarInteiro(qtd) == 0);
        prod[i].qtd = atoi(qtd);
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
        printf("Produto não encontrado!\n");
        printf("\n\nDigite ENTER para voltar.");
        getchar();
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
    fflush(stdin);
    if (cont < 1){
        printf("Produto não encontrado!\n");
        printf("\n\nDigite ENTER para voltar.");
        getchar();
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
        do{
            system("cls");
            printf("Digite o nome: ");
            gets(cl[i].nome);
        } while (validarStrings(cl[i].nome) == 0);
        do{
            printf("Informe o CPF: ");
            fgets(cl[c].cpf,12,stdin);
            validarCpf(c,cl);
            if(validarCpf(c,cl) != 1){
                printf("CPF invalido!\nDigite novamente\n\n");
            } else {
                printf("CPF valido!\n\n");
                break;
            }
        }while(validarCpf(c,cl) != 1);
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

cliente consultarCliente(int c, char nomeCl[], cliente cl[], int *cc){
    int i, cont = 0, **ccc = &cc;
    char resp = 0;
    for(i = 0; i < c; i++){
        if(strcmp(nomeCl,cl[i].nome) == 0){
            cont += 1;
            excluirCliente(i, cl, &cc);
        }
    }
    if (cont < 1){
        printf("Cliente não encontrado!\n");
        printf("\nDigite ENTER para voltar.");
        getchar();
    }
}

// Função para consultar cliente por ID

cliente consultarClienteId(int c, int id, cliente cl[], int *cc){
    int i, cont = 0, **ccc = &cc;
    char resp;
    for(i = 0; i < c; i++){
        if(id == cl[i].id){
        cont += 1;
            excluirCliente(i, cl, &cc);
        }
    }
    fflush(stdin);
    if (cont < 1){
        printf("Cliente não encontrado!\n");
        printf("\nDigite ENTER para voltar.");
        getchar();
    }
}


// Função para excluir  clientes

cliente excluirCliente(int i, cliente cl[], int **ccc){
char resp = 0;
    do{
        system("cls");
        printf("Id %10.d | Nome: %s | CPF: %s \n", cl[i].id, cl[i].nome, cl[i].cpf);
        printf("\n1 - Excluir Cliente.");
        printf("\n2 - Voltar.");
        resp = getch();
        if (resp == '1'){
            do{
                system("cls");
                printf("Após excluir o cliente você não poderá recupera-lo, deseja continuar?\n1 - Sim.\n2 - Não.");
                resp = 0;
                resp = getch();
                }while(resp != '1' && resp != '2');
                    if (resp == '1'){
                        if (**ccc > 1){
                        cl[i].id = cl[**ccc-1].id;
                        strcpy(cl[i].nome, cl[**ccc-1].nome);
                        strcpy(cl[i].cpf, cl[**ccc-1].cpf);
                        **ccc -= 1;
                        }else{
                        cl[i].id = cl[**ccc].id;
                        strcpy(cl[i].nome, cl[**ccc].nome);
                        strcpy(cl[i].cpf, cl[**ccc].cpf);
                        **ccc -= 1;
                        }
                        do{
                            system("cls");
                            printf("\nCliente excluído com sucesso!");
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

// Função para vendas

void venda(int n, nota nf[], int c, int p, int id, int idPrd, produto vetProd[], int qtd, cliente cl[]){
    char idVendaC[21], idVendaP[51];

    system("cls");
    ordenacaoCl(c, cl);

    printf("\nInforme o id do cliente: ");
    do{
        do{
            gets(idVendaC);
        } while(validarInteiro(idVendaC) == 0);
        id = atoi(idVendaC);
    }while(id < 1 || id > c);


    system("cls");
    ordenacaoProdId(p, vetProd);

    printf("\nInforme o id do produto: ");
    do{
        do{
            gets(idVendaP);
        } while(validarInteiro(idVendaP) == 0);
        idPrd = atoi(idVendaP);
    } while (idPrd < 1 || idPrd > p);


        printf("Informe a quantidade desejada: ");
    do{
        scanf("%d", &qtd);
    } while (qtd > vetProd[idPrd - 1].qtd);
    system("cls");
    vetProd[idPrd - 1].qtd = vetProd[idPrd - 1].qtd - qtd;
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

// Função para validar Strings

int validarStrings(char nome[]){
    int i = 0, cont = 0;

    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i] >= 65 && nome[i] <= 90 || nome[i] >= 97 && nome[i] <= 122){
            cont ++;
        } else {
            cont = 0;
            break;
        }
    }
    return cont;
}

// Função para validar Inteiros

int validarInteiro(char numero[]){
    int i;
    for(i = 0; i < strlen(numero); i++){
        if(!(isdigit(numero[i]))){
            return 0;
        }
    }
    return 1;
}

// Função para validar Float

float validarFloat(char numero[]){
    int i;
    for(i = 0; i < strlen(numero); i++){
        if(!(isdigit(numero[i])) && numero[i] != ','){
            return 0;
        }
    }
    return 1;
}
