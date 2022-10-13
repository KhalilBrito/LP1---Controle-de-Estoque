#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include<time.h>
#include<conio.h>

//estrutura para armazenar dados dos produtos
typedef struct produto{
int cod;
char nome[20];
float quantidade;
float preco;
}produtos;


//variáveis globais para contagem de produtos
int cont_prod = -1;

//declarando as funções
int menu();
void cad_prod(prod *);
void estoque(prod *);
void listar_prod(prod *);
//função limpeza de buffer
void lb();
int main(int argc, char **argv){
int op;

//vetor para armazenar produtos cadastrados
prod p[10];

do{
    op = menu();
    switch(op){
case 1:
    cad_prod(p); //chama a função cadastro de produtos
    break;
case 2:
    listar_prod(p); //chama a função listar produtos
    break;
case 3:
    printf("Saindo\n");//saindo da tela
    break;
default:
    printf("Escolha outra opção:\n");
    break;
    }
}while(op != 3);
return 0;
}
int menu(){
int op;
printf("1--Cadastrar Produtos--\n");
printf("2--Listar Produtos--\n");
printf("3--Sair--\n");
printf("Escolha uma opção: ");
scanf("%d", &op);
setbuf(stdin, NULL);
printf("\n");
return (op);
}

void cad_prod{
FILE *prod;
prod = fopen("hello.txt", "w");
printf("Insira dados");
}

cont_cli++;

printf("\nNome: ");
scanf(" %[^\n]s", (c[cont_cli].nome));
lb();

printf("\\\\\\\\\\\\\\\\")
}
