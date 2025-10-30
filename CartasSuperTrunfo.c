#include <stdio.h>


typedef enum {
    ATR_POPULACAO = 0,
    ATR_AREA = 1,
    ATR_PIB = 2,
    ATR_DENSIDADE = 3,
    ATR_PIB_PER_CAPITA = 4
} Atributo;


const Atributo ATRIBUTO_ESCOLHIDO = ATR_POPULACAO;


int main(void) {

    // Carta 1
    char estado1[3];           
    char codigo1[4];            
    char nomeCidade1[50];
    int  populacao1;
    float area1;                
    float pib1;            
    int  pontosTuristicos1;

    // Carta 2
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    int  populacao2;
    float area2;              
    float pib2;               
    int  pontosTuristicos2;

    //dados Carta 1 
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (ex.: SP): ");
    scanf(" %2s", estado1);

    printf("Digite o Codigo da Carta (Ex: A01): ");
    scanf(" %3s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1); 

    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a Area em km^2: ");
    scanf("%f", &area1);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    //dados Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (ex.: RJ): ");
    scanf(" %2s", estado2);

    printf("Digite o Codigo da Carta (Ex: B02): ");
    scanf(" %3s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area em km^2: ");
    scanf("%f", &area2);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

   

    float densidade1 = (area1 > 0.0f) ? ( (float)populacao1 / area1 ) : 0.0f;
    float densidade2 = (area2 > 0.0f) ? ( (float)populacao2 / area2 ) : 0.0f;

    // PIB
    float pibPerCapita1 = (populacao1 > 0) ? ( (pib1 * 1e9f) / (float)populacao1 ) : 0.0f;
    float pibPerCapita2 = (populacao2 > 0) ? ( (pib2 * 1e9f) / (float)populacao2 ) : 0.0f;

 
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de R$\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de R$\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita2);


    int vencedor = 0; 
    const char* nomeAtributo = "";

    if (ATRIBUTO_ESCOLHIDO == ATR_POPULACAO) {
        nomeAtributo = "Populacao";
        if (populacao1 > populacao2) vencedor = 1;
        else if (populacao2 > populacao1) vencedor = 2;
    } else if (ATRIBUTO_ESCOLHIDO == ATR_AREA) {
        nomeAtributo = "Area (km^2)";
        if (area1 > area2) vencedor = 1;
        else if (area2 > area1) vencedor = 2;
    } else if (ATRIBUTO_ESCOLHIDO == ATR_PIB) {
        nomeAtributo = "PIB (bilhoes de R$)";
        if (pib1 > pib2) vencedor = 1;
        else if (pib2 > pib1) vencedor = 2;
    } else if (ATRIBUTO_ESCOLHIDO == ATR_DENSIDADE) {
        nomeAtributo = "Densidade Populacional (hab/km^2)";
        // Para densidade, VENCE O MENOR valor
        if (densidade1 < densidade2) vencedor = 1;
        else if (densidade2 < densidade1) vencedor = 2;
    } else if (ATRIBUTO_ESCOLHIDO == ATR_PIB_PER_CAPITA) {
        nomeAtributo = "PIB per capita (R$)";
        if (pibPerCapita1 > pibPerCapita2) vencedor = 1;
        else if (pibPerCapita2 > pibPerCapita1) vencedor = 2;
    }


    printf("\n=== Comparacao de Cartas (Atributo: %s) ===\n", nomeAtributo);

    // Mostrar os valores usados na comparação
    if (ATRIBUTO_ESCOLHIDO == ATR_POPULACAO) {
        printf("Carta 1 - %s (%s): %d\n", nomeCidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %d\n", nomeCidade2, estado2, populacao2);
    } else if (ATRIBUTO_ESCOLHIDO == ATR_AREA) {
        printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, area1);
        printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, area2);
    } else if (ATRIBUTO_ESCOLHIDO == ATR_PIB) {
        printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, pib1);
        printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, pib2);
    } else if (ATRIBUTO_ESCOLHIDO == ATR_DENSIDADE) {
        printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, densidade1);
        printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, densidade2);
    } else if (ATRIBUTO_ESCOLHIDO == ATR_PIB_PER_CAPITA) {
        printf("Carta 1 - %s (%s): R$ %.2f\n", nomeCidade1, estado1, pibPerCapita1);
        printf("Carta 2 - %s (%s): R$ %.2f\n", nomeCidade2, estado2, pibPerCapita2);
    }

    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
