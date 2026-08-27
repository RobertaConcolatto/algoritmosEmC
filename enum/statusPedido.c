/* Crie um enum chamado StatusPedido contendo: • RECEBIDO = 1 • EM_PREPARACAO • ENVIADO • ENTREGUE • CANCELADO Leia o código do status e apresente uma mensagem correspondente, como: Pedido enviado para transporte. Valide a opção antes de convertê-la para o tipo enumerado. */
#include<stdio.h>

enum StatusPedido{
    RECEBIDO = 1,
    EM_PREPARACAO,
    ENVIADO,
    ENTREGUE,
    CANCELADO
};  

int main(){
    int opcao;
    enum StatusPedido status;

    printf("\n====== MENU ======");
    printf("\n 1 - RECEBIDO\n 2 - EM_PREPARACAO\n 3 - ENVIADO\n 4 - ENTREGUE\n 5 - CANCELADO");
    printf("\nInforme o status do pedido: ");
    scanf("%d", &opcao);
    while (opcao>5 || opcao<1)
    {
        printf("\nInforme uma opção válida! (0 a 5)");
        printf("\nInforme o status do pedido: ");
        scanf("%d", &opcao);
    }
    
    status = (enum StatusPedido) opcao;
    switch (status)
    {
    case RECEBIDO:
        printf("\nSeu pedido foi recebido!");
        break;
    case EM_PREPARACAO:
        printf("\nPedido confirmado e em preparação!");
        break;
    case ENVIADO:
        printf("\nPedido enviado para transporte!");
        break;
    case ENTREGUE:
        printf("\nPedido entregue!");
        break;
    case CANCELADO:
        printf("\nPedido cancelado = (");
        break;
    default:
        break;
    }
}