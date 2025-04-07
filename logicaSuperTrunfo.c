#include <stdio.h>
#include <string.h>

// Função para exibir os atributos disponíveis
void mostrarAtributos(int excluido) {
    printf("\nEscolha um atributo:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    if (excluido != 6) printf("6 - PIB per Capita\n");
}

float obterValorAtributo(int opcao, int populacao, float area, float pib, int pontosTuristicos, float densidade, float pibPerCapita) {
    switch(opcao) {
        case 1: return (float)populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontosTuristicos;
        case 5: return densidade;
        case 6: return pibPerCapita;
        default: return -1;
    }
}

char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    // Dados carta 1
    char estado1[3], nome1[100];
    int populacao1, pontosTuristicos1;
    float area1, pib1, densidade1, pibPerCapita1;

    // Dados carta 2
    char estado2[3], nome2[100];
    int populacao2, pontosTuristicos2;
    float area2, pib2, densidade2, pibPerCapita2;

    // Entrada carta 1
    printf("=== Cadastro Carta 1 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado1);
    printf("Nome do país: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada carta 2
    printf("\n=== Cadastro Carta 2 ===\n");
    printf("Estado (sigla): ");
    scanf("%s", estado2);
    printf("Nome do país: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Escolha dos atributos
    int atributo1 = 0, atributo2 = 0;

    mostrarAtributos(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);
    if (atributo1 < 1 || atributo1 > 6) {
        printf("Opção inválida!\n");
        return 1;
    }

    mostrarAtributos(atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);
    if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Obter valores para comparação
    float valor1_attr1 = obterValorAtributo(atributo1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
    float valor1_attr2 = obterValorAtributo(atributo2, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1);
    float valor2_attr1 = obterValorAtributo(atributo1, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);
    float valor2_attr2 = obterValorAtributo(atributo2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);

    // Comparações (atributo 1)
    int v1 = (atributo1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    int v2 = (atributo2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Resultado
    printf("\n=== Resultado da Rodada ===\n");
    printf("Carta 1: %s (%s)\n", nome1, estado1);
    printf("%s: %.2f\n", nomeAtributo(atributo1), valor1_attr1);
    printf("%s: %.2f\n", nomeAtributo(atributo2), valor1_attr2);
    printf("Soma: %.2f\n", soma1);

    printf("\nCarta 2: %s (%s)\n", nome2, estado2);
    printf("%s: %.2f\n", nomeAtributo(atributo1), valor2_attr1);
    printf("%s: %.2f\n", nomeAtributo(atributo2), valor2_attr2);
    printf("Soma: %.2f\n", soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2)
        printf("Carta 1 (%s) venceu!\n", nome1);
    else if (soma2 > soma1)
        printf("Carta 2 (%s) venceu!\n", nome2);
    else
        printf("Empate!\n");

    return 0;
}
