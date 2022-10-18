#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu();

//estrutura para produtos
struct produtos {
    char nome[20];
    float quant;
    float valor;
    int mesValidade;
    int anoValidade;
};

//função cabeçalho
void cabecalho(){
    printf("---------------------------------------------\n");
    printf("----------CONTROLE DE ESTOQUE----------------\n");
    printf("---------------------------------------------\n");
}


//função para limpar buffer
void limparCampos() {
    system("cls");
    cabecalho();
}
//função pesquisar nome
int pesquisarNome(struct produtos *p) {
    char pesquisarNome[20];
    int i = 0;
    int j;
    int read;

    FILE *f;

    limparCampos();

    f = fopen("produto.txt", "r");

    if(f == NULL) {
        limparCampos();
        printf("Nenhum arquivo encontrado.");
        getch();

        limparCampos();
        menu(p);
    }

    printf("Procurar pelo nome do produto: ");
    scanf("%s", &pesquisarNome);

    for(;;i++) {
        read = fread(&(*p), sizeof(struct produtos),1, f);

        for(j = 0; p -> nome[j] != '\0'; j++){
            if(pesquisarNome[j] != p -> nome[j]){
                break;
            }
        }
    if(read == 0){
        break;
    }

    if(pesquisarNome[j] == '\0' && p -> nome[j] == '\0'){
        limparCampos();

        printf("Produto: %s\n", p -> nome);

        if(p -> quant < 0){
            printf("Estoque: 0\n", p -> quant);
        }else{
        printf("Estoque: %.2f\n", p -> quant);
        }

        printf("Preco: R$ %.2f\n", p -> valor);

        if(p -> mesValidade > 9) {
            printf("Validade: %d/%d\n", p -> mesValidade, p-> anoValidade);
        }else{
        printf("Validade: 0%d/%d\n", p -> mesValidade, p -> anoValidade);
        }
        printf("\n");

        fclose(f);

        return i;
    }
    }

    fclose(f);
    return -1;
}

void entrada(struct produtos *p){
    int i;
    int read;

    FILE *f;

    limparCampos();

    f = fopen("produto.txt", "a");

    if(p -> nome[0] == NULL){
        for(;;){
            for(i = 0; i < 20; i++){
                p -> nome[i] == NULL;

                if(read == 0){
                    break;
                }
            }
        }
    }

    printf("Digite o produto: ");
    scanf("%s", &p -> nome);

    printf("Digite o estoque do produto: ");
    scanf("%f", &p -> quant);

    printf("Digite o preco: ");
    scanf("%f", &p -> valor);

    printf("Digite o mes de validade: ");
    scanf("%d", &p -> mesValidade);

    printf("Digite o ano de validade: ");
    scanf("%d", &p -> anoValidade);

    fwrite(&(*p), sizeof(struct produtos), 1, f);

    printf("\n");

    fclose(f);

    limparCampos();

    menu(p);
}

void lista(struct produtos *p){
    int i, j;
    int read;

    FILE *f;

    limparCampos();

    f = fopen("produto.txt", "r");

    if(f = NULL){
        limparCampos();
        printf("Nenhum arquivo encontrado.");
        getch();

        limparCampos();
        menu(p);
    }

    if(p -> nome[0] == NULL){
        for(i = 0; i < 20; i++){
            for(j = 0; j < 20; j++){
                p -> nome[j] == NULL;
            }
        }
    }

    for(;;){
        read = fread(&(*p), sizeof(struct produtos), 1, f);

        if(read == 0){
            break;
        }

        if(
           p -> nome &&
           p -> quant &&
           p -> valor &&
           p -> mesValidade &&
           p -> anoValidade
          ){
            printf("Produtos: %s\n", p -> nome);


            if(p -> quant < 0){
                printf("Estoque: 0\n", p -> quant);
            }else{
                printf("Estoque: %.2f", p -> quant);
            }


            printf("Preco: R$ %.2f\n", p -> valor);

            if(p -> mesValidade > 9){
                printf("Validade: %d/%d\n", p -> mesValidade, p -> anoValidade);
            }else{
                printf("Validade: 0%d/%d\n", p -> mesValidade, p -> anoValidade);
            }
                printf("----------------------------------------------------\n");
           }
    }

    fclose(f);

    printf("\n");
    printf("Pressione ENTER para continuar...");

    getch();

    limparCampos();

    menu(p);
}

void menu(struct produtos *p){

    int op;

    printf("1 ------------- Entrada de dados ---------------- \n");
    printf("2 ------------- Listar todos os produtos -------- \n");
    printf("\n");

    printf("Digite uma opcao: ");
    scanf("%d", &op);

    switch(op){
    case 1:
        entrada(p);
        break;
    case 2:
        lista(p);
        break;
    default:
        limparCampos();
        printf("Algo deu errado.\n");
        printf("Digite ENTER para continuar...\n");
        getch();
        limparCampos();
        menu(p);
    }
}

int main(void){
    struct produtos produtos;
    struct produtos *p;

    p = &produtos;

    limparCampos();
    menu(p);

    return 0;
}
