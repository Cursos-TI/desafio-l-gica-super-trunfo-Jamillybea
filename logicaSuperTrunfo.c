#include <stdio.h>
#include <string.h>

int main() {
    char pais1[100], pais2[100];
    char codigo1[24], codigo2[24];
    char cidade1[27], cidade2[27];
    unsigned long int populacao1, populacao2;
    float pib1, pib2, area1, area2;
    int pontos1, pontos2;
    float dens1, dens2;
    float percap1, percap2;
    float super1, super2;
    int escolha1, escolha2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma1, soma2;

    // ===== LEITURA DAS CARTAS =====
    printf("=== CARTA 1 ===\n");
    printf("Digite o nome do pais:\n");
    fgets(pais1, sizeof(pais1), stdin);
    pais1[strcspn(pais1, "\n")] = 0;

    printf("Digite o codigo da carta:\n");
    scanf("%23s", codigo1);
    getchar();

    printf("Digite o nome da cidade:\n");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("Digite a populacao:\n");
    scanf("%lu", &populacao1);

    printf("Digite a area (km2):\n");
    scanf("%f", &area1);

    printf("Digite o PIB:\n");
    scanf("%f", &pib1);

    printf("Digite a quantidade de pontos turisticos:\n");
    scanf("%d", &pontos1);
    getchar();

    dens1 = populacao1 / area1;
    percap1 = pib1 / populacao1;
    super1 = (float)populacao1 + area1 + pib1 + (float)pontos1 + percap1 + (1.0f / dens1);

    printf("\n=== CARTA 2 ===\n");
    printf("Digite o nome do pais:\n");
    fgets(pais2, sizeof(pais2), stdin);
    pais2[strcspn(pais2, "\n")] = 0;

    printf("Digite o codigo da carta:\n");
    scanf("%23s", codigo2);
    getchar();

    printf("Digite o nome da cidade:\n");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a populacao:\n");
    scanf("%lu", &populacao2);

    printf("Digite a area (km2):\n");
    scanf("%f", &area2);

    printf("Digite o PIB:\n");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turisticos:\n");
    scanf("%d", &pontos2);

    dens2 = populacao2 / area2;
    percap2 = pib2 / populacao2;
    super2 = (float)populacao2 + area2 + pib2 + (float)pontos2 + percap2 + (1.0f / dens2);

    // ===== MENU DINÂMICO =====
    printf("\n=== Escolha do primeiro atributo ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turisticos\n");
    printf("5 - PIB per capital\n");
    printf("6 - Densidade demografica (menor vence)\n");
    scanf("%d", &escolha1);

    switch (escolha1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break; //menu dessa maneira fica organizado, sendo assim valor1_c1(carta1) recebe o valor dos atributos da carta 1, a lógica funciona para a carta 2.
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos1; valor1_c2 = pontos2; break;
        case 5: valor1_c1 = percap1; valor1_c2 = percap2; break;
        case 6: valor1_c1 = dens1; valor1_c2 = dens2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

   
    printf("\n=== Escolha do segundo atributo ===\n"); //Aqui o usuario poderá escolher uma segunda opção sem ser a primeira
    if (escolha1 != 1) printf("1 - Populacao\n");// a leitura seria SE (escolha1) não for 1 (população) então ele mostrará no menu
    if (escolha1 != 2) printf("2 - Area\n");
    if (escolha1 != 3) printf("3 - PIB\n");
    if (escolha1 != 4) printf("4 - Pontos turisticos\n");
    if (escolha1 != 5) printf("5 - PIB per capital\n");
    if (escolha1 != 6) printf("6 - Densidade demografica (menor vence)\n");
    scanf("%d", &escolha2);

    if (escolha2 == escolha1) {
        printf("Voce nao pode escolher o mesmo atributo!\n");
        return 0; // Aqui está claro que se escolha 1 for igual a escolha 2 não poderá escolher o mesmo atributo
    }

    switch (escolha2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos1; valor2_c2 = pontos2; break;
        case 5: valor2_c1 = percap1; valor2_c2 = percap2; break;
        case 6: valor2_c1 = dens1; valor2_c2 = dens2; break;
        default: printf("Opcao invalida!\n"); return 0;
    }


    printf("\n=== Comparacao ===\n");

    if (escolha1 == 6) { // densidade: menor vence
        printf("Atributo 1: %s = %.2f | %s = %.2f -> %s vence\n",
               pais1, valor1_c1, pais2, valor1_c2,
               (valor1_c1 < valor1_c2) ? pais1 : pais2);
    } else {
        printf("Atributo 1: %s = %.2f | %s = %.2f - %s vence\n",
               pais1, valor1_c1, pais2, valor1_c2,
               (valor1_c1 > valor1_c2) ? pais1 : pais2);
    }

    if (escolha2 == 6) { // densidade: menor vence
        printf("Atributo 2: %s = %.2f | %s = %.2f -> %s vence\n",
               pais1, valor2_c1, pais2, valor2_c2,
               (valor2_c1 < valor2_c2) ? pais1 : pais2);
    } else {
        printf("Atributo 2: %s = %.2f | %s = %.2f -> %s vence\n",
               pais1, valor2_c1, pais2, valor2_c2,
               (valor2_c1 > valor2_c2) ? pais1 : pais2);
    }

    // Soma para desempate
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos: %s = %.2f | %s = %.2f\n", pais1, soma1, pais2, soma2);

    if (soma1 > soma2) {
        printf("Resultado final: %s venceu!\n", pais1);
    } else if (soma2 > soma1) {
        printf("Resultado final: %s venceu!\n", pais2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
