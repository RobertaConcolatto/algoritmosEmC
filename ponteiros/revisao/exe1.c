/*1. Registro de um equipamento
Conteúdos: enum, struct aninhada, typedef, inicialização, cópia e comparação de structs.
Defina enum Estado com DESLIGADO = 1 e LIGADO = 2. Defina Data (dia, mes, ano) e Equipamento (codigo,
estado e revisao do tipo Data), usando typedef. Inicialize um equipamento com código 10, estado DESLIGADO e
revisão 1/10/2026. Copie esse registro para outro e leia, para a cópia, estado e data de revisão. Valide o estado
antes de convertê-lo para enum. Apresente os dois registros e informe se são iguais, comparando todos os
campos. Use switch para exibir o estado. Não se exige validação de calendário; considere datas válidas*/

#include <stdio.h>

typedef enum Estado
{
    DESLIGADO = 1,
    LIGADO = 2
} Estado;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int codigo;
    Estado estado;
    Data revisao;
} Equipamento;

void exibirEquipamento(Equipamento equipamento)
{
    printf("\nCódigo: %d", equipamento.codigo);
    printf("\nEstado: ");
    switch (equipamento.estado)
    {
    case DESLIGADO:
        printf("DESLIGADO");
        break;
    case LIGADO:
        printf("LIGADO");
        break;
    default:
        printf("ERRO");
        break;
    }
    printf("\nRevisão: %d/%d/%d",
           equipamento.revisao.dia,
           equipamento.revisao.mes,
           equipamento.revisao.ano);
}

int main()
{
    Equipamento original = {10, DESLIGADO, {1, 10, 2026}};
    Equipamento copia = original;
    int opcao;
    printf("\nInforme o novo estado: ");
    printf("\n 1 - DESLIGADO");
    printf("\n 2- LIGADO");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    if (opcao < DESLIGADO || opcao > LIGADO)
    {
        return 1;
    }

    copia.estado = (Estado) opcao;

    printf("\nInforme o dia da revisão: ");
    scanf("%d", &copia.revisao.dia);
    
    printf("\nInforme o mês da revisão: ");
    scanf("%d", &copia.revisao.mes);
    
    printf("\nInforme o ano da revisão: ");
    scanf("%d", &copia.revisao.ano);

    printf("\n==== REGISTRO ORIGINAL ====");
    exibirEquipamento(original);
    
    printf("\n==== REGISTRO CÓPIA ====");
    exibirEquipamento(copia);

    if (original.codigo == copia.codigo &&
        original.estado == copia.estado &&
        original.revisao.dia == copia.revisao.dia &&
        original.revisao.mes == copia.revisao.mes &&
        original.revisao.ano == copia.revisao.ano)
    {
        printf("\nOs registros são iguais");
    }
    else
    {
        printf("\nOs registros são diferentes");
    }
       
    return 0;
}