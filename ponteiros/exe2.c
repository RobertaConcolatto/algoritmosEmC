/*Exercício 2 — Cadastro e Atualização de produto
typedef struct {
int codigo;
char descricao[50];
float preco;
int quantidade;
} Produto;
• Implemente:
• void cadastrarProduto(Produto *produto);
• void aplicarDesconto(Produto *produto, float percentual);
• void exibirProduto(const Produto *produto);*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[50];
    float preco;
    int quantidade;
} Produto;
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void cadastrarProduto(Produto *produto)
{
    printf("\n--- CADASTRAR PRODUTO ---");
    printf("\nCódigo: ");
    scanf("%d", &produto->codigo);
    limparBuffer();

    printf("\nDescrição: ");
    fgets(produto->descricao, sizeof(produto->descricao), stdin);
    produto->descricao[strcspn(produto->descricao, "\n")] = '\0';
    while (strlen(produto->descricao) < 1)
    {
        printf("\nResposta vazia!");
        printf("\nDescrição: ");
        fgets(produto->descricao, sizeof(produto->descricao), stdin);
        produto->descricao[strcspn(produto->descricao, "\n")] = '\0';
    }

    printf("\nPreço: R$");
    scanf("%f", &produto->preco);

    printf("\nQuantidade: ");
    scanf("%d", &produto->quantidade);
}

void aplicarDesconto(Produto *produto, float percentual)
{
    produto->preco = produto->preco - (produto->preco * (percentual / 100.0));
}

void exibirProduto(const Produto *produto)
{
    printf("\nCódigo: %d", produto->codigo);
    printf("\nDescrição: %s", produto->descricao);
    printf("\nPreço: R$%.2f", produto->preco);
    printf("\nQuantidade: %d", produto->quantidade);
}

int main()
{
    Produto produto;
    printf("==== Cadastro e Atualização de produto ====");

    cadastrarProduto(&produto);
    exibirProduto(&produto);

    float percentualDesconto;
    printf("\n--- Aplicar Desconto ---");
    printf("\nInforme o percentual de desconto: ");
    scanf("%f", &percentualDesconto);
    aplicarDesconto(&produto, percentualDesconto);
    exibirProduto(&produto);

    return 0;
}