#include <stdio.h>

int main()
{
    // mS = média semestral, mF = média final, eF = exame final, nX = nota X, pX = peso X, op = opção
    // medAuxi = media auxiliar (criada pra definir conceitos = A, B, C...)
    
    int matricula, op;
    float n1, n2, n3, p1, p2, p3, mS, mF, eF, medAuxi;

    printf("\n-------Sistema Academico-------");

    do
    {
        printf("\n============================");
        printf("\n|           Menu           |");
        printf("\n| 1 - Media Aritmetica     |");
        printf("\n| 2 - Media Ponderada      |");
        printf("\n| 3 - Sair                 |");
        printf("\n============================");
        printf("\nInforme a opcao desejada: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
        {
            printf("\n----Media Aritmetica----");

            printf("\nInforme o numero de matricula: ");
            scanf("%d", &matricula);

            while (matricula < 0)
            {
                printf("\nInforme um numero valido! (positivo)");
                printf("\nInforme o numero de matricula: ");
                scanf("%d", &matricula);
            }

            printf("\nInforme a primeira nota: ");
            scanf("%f", &n1);

            while (n1 < 0 || n1 > 10)
            {
                printf("\nInforme um numero valido! (entre 0 e 10)");
                printf("\nInforme a primeira nota: ");
                scanf("%f", &n1);
            }

            printf("\nInforme a segunda nota: ");
            scanf("%f", &n2);

            while (n2 < 0 || n2 > 10)
            {
                printf("\nInforme um numero valido! (entre 0 e 10)");
                printf("\nInforme a segunda nota: ");
                scanf("%f", &n2);
            }

            printf("\nInforme a terceira nota: ");
            scanf("%f", &n3);

            while (n3 < 0 || n3 > 10)
            {
                printf("\nInforme um numero valido! (entre 0 e 10)");
                printf("\nInforme a terceira nota: ");
                scanf("%f", &n3);
            }

            mS = (n1 + n2 + n3) / 3;

            if (mS > 1.8 && mS < 7)
            {
                printf("\nInforme a nota do Exame Final: ");
                scanf("%f", &eF);

                while (eF < 0 || eF > 10)
                {
                    printf("\nInforme um numero valido! (entre 0 e 10)");
                    printf("\nInforme a nota do Exame Final: ");
                    scanf("%f", &eF);
                }

                mF = (mS * 0.6) + (eF * 0.4);
            }

            printf("\n================BOLETIM ACADEMICO================\n");
            printf("\nMatricula: %d\n", matricula);

            printf("\n------------------NOTAS------------------\n");
            printf("\nNota 1: %.2f", n1);
            printf("\nNota 2: %.2f", n2);
            printf("\nNota 3: %.2f\n", n3);

            printf("\nMedia Semestral (MS): %.2f\n", mS);

            printf("\n------------------SITUACAO------------------\n");

            if (mS > 1.8 && mS < 7)
            {
                printf("\nStatus: EM EXAME\n");
                printf("\nNota do Exame: %.2f", eF);
                printf("\nMedia Final: %.2f\n", mF);
            }

            printf("\nConceito: ");

            medAuxi = mS;

            if (mS > 1.8 && mS < 7)
            {
                medAuxi = mF;
            }

            if (medAuxi >= 9)
            {
                printf("A");
            }
            else if (medAuxi < 9 && medAuxi >= 7.5)
            {
                printf("B");
            }
            else if (medAuxi < 7.5 && medAuxi >= 6)
            {
                printf("C");
            }
            else if (medAuxi < 6 && medAuxi >= 4)
            {
                printf("D");
            }
            else
            {
                printf("E");
            }

            printf("\nSituacao Final: ");

            if (mS >= 7)
            {
                printf("APROVADO");
            }
            else if (mS < 1.8)
            {
                printf("REPROVADO");
            }
            else
            {
                if (mF >= 5)
                {
                    printf("APROVADO");
                }
                else
                {
                    printf("REPROVADO");
                }
            }

            printf("\n\n=================================================\n");
        }
        break;

        case 2:
        {
            printf("\n----Media Ponderada----");

            printf("\nInforme o numero de matricula: ");
            scanf("%d", &matricula);

            while (matricula < 0)
            {
                printf("\nInforme um numero valido! (positivo)");
                printf("\nInforme o numero de matricula: ");
                scanf("%d", &matricula);
            }

            printf("\nInforme a primeira nota: ");
            scanf("%f", &n1);

            while (n1 < 0 || n1 > 10)
            {
                printf("\nInforme um numero valido! (entre 0 e 10)");
                printf("\nInforme a primeira nota: ");
                scanf("%f", &n1);
            }

            printf("\nInforme peso 1: ");
            scanf("%f", &p1);

            while (p1 <= 0)
            {
                printf("\nInforme um numero valido! (maior que 0)");
                printf("\nInforme peso 1: ");
                scanf("%f", &p1);
            }

            printf("\nInforme a segunda nota: ");
            scanf("%f", &n2);

            while (n2 < 0 || n2 > 10)
            {
                printf("\nInforme um numero valido! (entre 0 e 10)");
                printf("\nInforme a segunda nota: ");
                scanf("%f", &n2);
            }

            printf("\nInforme peso 2: ");
            scanf("%f", &p2);

            while (p2 <= 0)
            {
                printf("\nInforme um numero valido! (maior que 0)");
                printf("\nInforme peso 2: ");
                scanf("%f", &p2);
            }

            printf("\nInforme a terceira nota: ");
            scanf("%f", &n3);

            while (n3 < 0 || n3 > 10)
            {
                printf("\nInforme um numero valido! (entre 0 e 10)");
                printf("\nInforme a terceira nota: ");
                scanf("%f", &n3);
            }

            printf("\nInforme peso 3: ");
            scanf("%f", &p3);

            while (p3 <= 0)
            {
                printf("\nInforme um numero valido! (maior que 0)");
                printf("\nInforme peso 3: ");
                scanf("%f", &p3);
            }

            mS = ((n1 * p1) + (n2 * p2) + (n3 * p3)) / (p1 + p2 + p3);

            if (mS > 1.8 && mS < 7)
            {
                printf("\nInforme a nota do Exame Final: ");
                scanf("%f", &eF);

                while (eF < 0 || eF > 10)
                {
                    printf("\nInforme um numero valido! (entre 0 e 10)");
                    printf("\nInforme a nota do Exame Final: ");
                    scanf("%f", &eF);
                }

                mF = (mS * 0.6) + (eF * 0.4);
            }

            printf("\n================BOLETIM ACADEMICO================\n");
            printf("\nMatricula: %d\n", matricula);

            printf("\n------------------NOTAS------------------\n");
            printf("\nNota 1: %.2f", n1);
            printf("\nPeso 1: %.2f\n", p1);

            printf("\nNota 2: %.2f", n2);
            printf("\nPeso 2: %.2f\n", p2);

            printf("\nNota 3: %.2f", n3);
            printf("\nPeso 3: %.2f\n", p3);

            printf("\nMedia Semestral (MS): %.2f\n", mS);

            printf("\n------------------SITUACAO------------------\n");

            if (mS > 1.8 && mS < 7)
            {
                printf("\nStatus: EM EXAME\n");
                printf("\nNota do Exame: %.2f", eF);
                printf("\nMedia Final: %.2f\n", mF);
            }

            printf("\nConceito: ");

            medAuxi = mS;

            if (mS > 1.8 && mS < 7)
            {
                medAuxi = mF;
            }

            if (medAuxi >= 9)
            {
                printf("A");
            }
            else if (medAuxi < 9 && medAuxi >= 7.5)
            {
                printf("B");
            }
            else if (medAuxi < 7.5 && medAuxi >= 6)
            {
                printf("C");
            }
            else if (medAuxi < 6 && medAuxi >= 4)
            {
                printf("D");
            }
            else
            {
                printf("E");
            }

            printf("\nSituacao Final: ");

            if (mS >= 7)
            {
                printf("APROVADO");
            }
            else if (mS < 1.8)
            {
                printf("REPROVADO");
            }
            else
            {
                if (mF >= 5)
                {
                    printf("APROVADO");
                }
                else
                {
                    printf("REPROVADO");
                }
            }

            printf("\n\n=================================================\n");
        }
        break;

        case 3:
        {
            printf("\n\nVolte sempre!");
        }
        break;

        default:
            printf("\nInforme uma opcao valida!");
            break;
        }

    } while (op != 3);

    return 0;
}
