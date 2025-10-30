#include <stdio.h>


typedef enum {
    ATR_POPULACAO = 1,
    ATR_AREA = 2,
    ATR_PIB = 3,
    ATR_PONTOS_TURISTICOS = 4,
    ATR_DENSIDADE = 5,
    ATR_EXIBIR_NOMES = 6,
    ATR_SAIR = 0
} Atributo;

int main(void) {
    // Carta 1
    char estado1[3];
    char codigo1[4];
    char nomePais1[50];       
    int  populacao1;
    float area1;
    float pib1;                
    int  pontosTuristicos1;

    // Carta 2
    char estado2[3];
    char codigo2[4];
    char nomePais2[50];
    int  populacao2;
    float area2;
    float pib2;              
    int  pontosTuristicos2;

    /*dados das duas cartas */
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (ex.: SP): ");
    scanf(" %2s", estado1);

    printf("Digite o Codigo da Carta (Ex: A01): ");
    scanf(" %3s", codigo1);

    printf("Digite o Nome do Pais: ");
    scanf(" %49[^\n]", nomePais1);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a Area em km^2: ");
    scanf("%f", &area1);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (ex.: RJ): ");
    scanf(" %2s", estado2);

    printf("Digite o Codigo da Carta (Ex: B02): ");
    scanf(" %3s", codigo2);

    printf("Digite o Nome do Pais: ");
    scanf(" %49[^\n]", nomePais2);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area em km^2: ");
    scanf("%f", &area2);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);


    float densidade1 = (area1 > 0.0f) ? ((float)populacao1 / area1) : 0.0f;
    float densidade2 = (area2 > 0.0f) ? ((float)populacao2 / area2) : 0.0f;

    // PIB
    float pibPerCapita1 = (populacao1 > 0) ? ((pib1 * 1e9f) / (float)populacao1) : 0.0f;
    float pibPerCapita2 = (populacao2 > 0) ? ((pib2 * 1e9f) / (float)populacao2) : 0.0f;


    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Pais: %s\n", nomePais1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de R$\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Demografica: %.2f hab/km^2\n", densidade1);
    printf("PIB per capita (info): R$ %.2f\n", pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Pais: %s\n", nomePais2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de R$\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Demografica: %.2f hab/km^2\n", densidade2);
    printf("PIB per capita (info): R$ %.2f\n", pibPerCapita2);

    /* Menu interativo */
    int opcao;
    do {

        printf("   MENU DE COMPARACAO (SWITCH)\n");
        printf("[1] Populacao (vence MAIOR)\n");
        printf("[2] Area (km^2) (vence MAIOR)\n");
        printf("[3] PIB (bilhoes de R$) (vence MAIOR)\n");
        printf("[4] Pontos Turisticos (vence MAIOR)\n");
        printf("[5] Densidade Demografica (vence MENOR)\n");
        printf("[6] Exibir apenas os nomes dos paises\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { /* descarta */ }
            opcao = -1;
        }

        int vencedor = 0;     
        const char* nomeAtributo = NULL;
        float v1f = 0.0f, v2f = 0.0f;
        int   v1i = 0,    v2i = 0;    

        switch (opcao) {
            case ATR_POPULACAO:
                nomeAtributo = "Populacao";
                v1i = populacao1;
                v2i = populacao2;

                if (v1i > v2i) {
                    vencedor = 1;
                } else if (v2i > v1i) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }

                printf("\n=== Comparacao por %s ===\n", nomeAtributo);
                printf("%s (%s): %d\n", nomePais1, estado1, v1i);
                printf("%s (%s): %d\n", nomePais2, estado2, v2i);
                break;

            case ATR_AREA:
                nomeAtributo = "Area (km^2)";
                v1f = area1;
                v2f = area2;

                if (v1f > v2f) {
                    vencedor = 1;
                } else if (v2f > v1f) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }

                printf("\n=== Comparacao por %s ===\n", nomeAtributo);
                printf("%s (%s): %.2f\n", nomePais1, estado1, v1f);
                printf("%s (%s): %.2f\n", nomePais2, estado2, v2f);
                break;

            case ATR_PIB:
                nomeAtributo = "PIB (bilhoes de R$)";
                v1f = pib1;
                v2f = pib2;

                if (v1f > v2f) {
                    vencedor = 1;
                } else if (v2f > v1f) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }

                printf("\n=== Comparacao por %s ===\n", nomeAtributo);
                printf("%s (%s): %.2f\n", nomePais1, estado1, v1f);
                printf("%s (%s): %.2f\n", nomePais2, estado2, v2f);
                break;

            case ATR_PONTOS_TURISTICOS:
                nomeAtributo = "Pontos Turisticos";
                v1i = pontosTuristicos1;
                v2i = pontosTuristicos2;

                if (v1i > v2i) {
                    vencedor = 1;
                } else if (v2i > v1i) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }

                printf("\n=== Comparacao por %s ===\n", nomeAtributo);
                printf("%s (%s): %d\n", nomePais1, estado1, v1i);
                printf("%s (%s): %d\n", nomePais2, estado2, v2i);
                break;

            case ATR_DENSIDADE:
                nomeAtributo = "Densidade Demografica (hab/km^2) — vence MENOR";
                v1f = densidade1;
                v2f = densidade2;

                
                if (v1f < v2f) {
                    vencedor = 1;
                } else if (v2f < v1f) {
                    vencedor = 2;
                } else {
                    vencedor = 0;
                }

                printf("\n=== Comparacao por %s ===\n", nomeAtributo);
                printf("%s (%s): %.2f\n", nomePais1, estado1, v1f);
                printf("%s (%s): %.2f\n", nomePais2, estado2, v2f);
                break;

            case ATR_EXIBIR_NOMES:
                printf("\n=== Paises cadastrados ===\n");
                printf("Carta 1: %s (%s) | Cod: %s\n", nomePais1, estado1, codigo1);
                printf("Carta 2: %s (%s) | Cod: %s\n", nomePais2, estado2, codigo2);
                break;

            case ATR_SAIR:
                printf("\nSaindo... Obrigado por jogar!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }


        if (opcao >= ATR_POPULACAO && opcao <= ATR_DENSIDADE) {
            if (vencedor == 1) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomePais1);
            } else if (vencedor == 2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
        }
    } while (opcao != ATR_SAIR);

    return 0;
}
