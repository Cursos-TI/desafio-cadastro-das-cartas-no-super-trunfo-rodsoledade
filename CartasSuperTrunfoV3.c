#include <stdio.h>

int main() {
    // Definindo o número de estados e cidades por estado
    int num_estados = 2; // Estados de A a H
    int num_cidades_por_estado = 4; // 4 cidades por estado

    // Variáveis para armazenar os dados das cidades
    char codigo[4]; // Código da carta (ex: A01, B02, etc.)
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;

    // Variáveis para propriedades calculadas
    float densidade_populacional;
    float PIB_per_capita;
    float super_poder; // Soma de todas as propriedades

    // Matriz para armazenar os dados de todas as cidades
    // Cada estado tem 4 cidades, e cada cidade tem 4 propriedades
    int populacoes[8][4];
    float areas[8][4];
    float PIBs[8][4];
    int pontos_turisticos_por_cidade[8][4];
    float densidades_populacionais[8][4];
    float PIBs_per_capita[8][4];
    float super_poderes[8][4];

    // Mensagem de boas-vindas
    printf("Bem-vindo ao cadastro de cartas do Super Trunfo - Países!\n");

    // Loop para cadastrar as cidades de cada estado
    for (int estado = 0; estado < num_estados; estado++) {
        for (int cidade = 0; cidade < num_cidades_por_estado; cidade++) {
            // Gera o código da carta automaticamente (ex: A01, A02, etc.)
            codigo[0] = 'A' + estado; // Letra do estado (A, B, C, ..., H)
            codigo[1] = '0' + (cidade + 1) / 10; // Primeiro dígito do número da cidade
            codigo[2] = '0' + (cidade + 1) % 10; // Segundo dígito do número da cidade
            codigo[3] = '\0'; // Terminador da string

            // Solicita os dados da cidade ao usuário
            printf("\nCadastrando cidade %s:\n", codigo);
            printf("Digite a população da cidade: ");
            scanf("%d", &populacao);
            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &area);
            printf("Digite o PIB da cidade (em milhões): ");
            scanf("%f", &PIB);
            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &pontos_turisticos);

            // Calcula as novas propriedades
            densidade_populacional = (float)populacao / area; // Densidade populacional
            PIB_per_capita = (PIB * 1000000) / populacao; // PIB per capita (em unidades monetárias por habitante)
            super_poder = populacao + area + PIB + pontos_turisticos + densidade_populacional + PIB_per_capita; // Super Poder

            // Armazena os dados na matriz
            populacoes[estado][cidade] = populacao;
            areas[estado][cidade] = area;
            PIBs[estado][cidade] = PIB;
            pontos_turisticos_por_cidade[estado][cidade] = pontos_turisticos;
            densidades_populacionais[estado][cidade] = densidade_populacional;
            PIBs_per_capita[estado][cidade] = PIB_per_capita;
            super_poderes[estado][cidade] = super_poder;
        }
    }

    // Exibe os dados de todas as cidades cadastradas
    printf("\nDados de todas as cidades cadastradas:\n");
    for (int estado = 0; estado < num_estados; estado++) {
        for (int cidade = 0; cidade < num_cidades_por_estado; cidade++) {
            // Gera o código da carta automaticamente
            codigo[0] = 'A' + estado;
            codigo[1] = '0' + (cidade + 1) / 10;
            codigo[2] = '0' + (cidade + 1) % 10;
            codigo[3] = '\0';

            // Exibe os dados da cidade
            printf("\nCidade %s:\n", codigo);
            printf("População: %d habitantes\n", populacoes[estado][cidade]);
            printf("Área: %.2f km²\n", areas[estado][cidade]);
            printf("PIB: %.2f milhões\n", PIBs[estado][cidade]);
            printf("Pontos Turísticos: %d\n", pontos_turisticos_por_cidade[estado][cidade]);
            printf("Densidade Populacional: %.2f hab/km²\n", densidades_populacionais[estado][cidade]);
            printf("PIB per Capita: %.2f\n", PIBs_per_capita[estado][cidade]);
            printf("Super Poder: %.2f\n", super_poderes[estado][cidade]);
        }
    }

    // Comparação de cartas
    printf("\nComparação de cartas:\n");

    char codigo_carta1[4], codigo_carta2[4];
    int estado1, cidade1, estado2, cidade2;

    // Solicita os códigos das cartas a serem comparadas
    printf("Digite o código da primeira carta (ex: A01): ");
    scanf("%s", codigo_carta1);
    printf("Digite o código da segunda carta (ex: B02): ");
    scanf("%s", codigo_carta2);

    // Converte os códigos das cartas em índices da matriz
    estado1 = codigo_carta1[0] - 'A';
    cidade1 = (codigo_carta1[1] - '0') * 10 + (codigo_carta1[2] - '0') - 1;
    estado2 = codigo_carta2[0] - 'A';
    cidade2 = (codigo_carta2[1] - '0') * 10 + (codigo_carta2[2] - '0') - 1;

    // Exibe os dados das cartas selecionadas
    printf("\nCarta %s:\n", codigo_carta1);
    printf("População: %d habitantes\n", populacoes[estado1][cidade1]);
    printf("Área: %.2f km²\n", areas[estado1][cidade1]);
    printf("PIB: %.2f milhões\n", PIBs[estado1][cidade1]);
    printf("Pontos Turísticos: %d\n", pontos_turisticos_por_cidade[estado1][cidade1]);
    printf("Densidade Populacional: %.2f hab/km²\n", densidades_populacionais[estado1][cidade1]);
    printf("PIB per Capita: %.2f\n", PIBs_per_capita[estado1][cidade1]);
    printf("Super Poder: %.2f\n", super_poderes[estado1][cidade1]);

    printf("\nCarta %s:\n", codigo_carta2);
    printf("População: %d habitantes\n", populacoes[estado2][cidade2]);
    printf("Área: %.2f km²\n", areas[estado2][cidade2]);
    printf("PIB: %.2f milhões\n", PIBs[estado2][cidade2]);
    printf("Pontos Turísticos: %d\n", pontos_turisticos_por_cidade[estado2][cidade2]);
    printf("Densidade Populacional: %.2f hab/km²\n", densidades_populacionais[estado2][cidade2]);
    printf("PIB per Capita: %.2f\n", PIBs_per_capita[estado2][cidade2]);
    printf("Super Poder: %.2f\n", super_poderes[estado2][cidade2]);

    // Compara as propriedades das cartas
    printf("\nResultados da comparação:\n");

    // População
    if (populacoes[estado1][cidade1] > populacoes[estado2][cidade2]) {
        printf("População: Carta %s vence!\n", codigo_carta1);
    } else if (populacoes[estado1][cidade1] < populacoes[estado2][cidade2]) {
        printf("População: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("População: Empate!\n");
    }

    // Área
    if (areas[estado1][cidade1] > areas[estado2][cidade2]) {
        printf("Área: Carta %s vence!\n", codigo_carta1);
    } else if (areas[estado1][cidade1] < areas[estado2][cidade2]) {
        printf("Área: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("Área: Empate!\n");
    }

    // PIB
    if (PIBs[estado1][cidade1] > PIBs[estado2][cidade2]) {
        printf("PIB: Carta %s vence!\n", codigo_carta1);
    } else if (PIBs[estado1][cidade1] < PIBs[estado2][cidade2]) {
        printf("PIB: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("PIB: Empate!\n");
    }

    // Pontos Turísticos
    if (pontos_turisticos_por_cidade[estado1][cidade1] > pontos_turisticos_por_cidade[estado2][cidade2]) {
        printf("Pontos Turísticos: Carta %s vence!\n", codigo_carta1);
    } else if (pontos_turisticos_por_cidade[estado1][cidade1] < pontos_turisticos_por_cidade[estado2][cidade2]) {
        printf("Pontos Turísticos: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("Pontos Turísticos: Empate!\n");
    }

    // Densidade Populacional (menor valor vence)
    if (densidades_populacionais[estado1][cidade1] < densidades_populacionais[estado2][cidade2]) {
        printf("Densidade Populacional: Carta %s vence!\n", codigo_carta1);
    } else if (densidades_populacionais[estado1][cidade1] > densidades_populacionais[estado2][cidade2]) {
        printf("Densidade Populacional: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("Densidade Populacional: Empate!\n");
    }

    // PIB per Capita
    if (PIBs_per_capita[estado1][cidade1] > PIBs_per_capita[estado2][cidade2]) {
        printf("PIB per Capita: Carta %s vence!\n", codigo_carta1);
    } else if (PIBs_per_capita[estado1][cidade1] < PIBs_per_capita[estado2][cidade2]) {
        printf("PIB per Capita: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("PIB per Capita: Empate!\n");
    }

    // Super Poder
    if (super_poderes[estado1][cidade1] > super_poderes[estado2][cidade2]) {
        printf("Super Poder: Carta %s vence!\n", codigo_carta1);
    } else if (super_poderes[estado1][cidade1] < super_poderes[estado2][cidade2]) {
        printf("Super Poder: Carta %s vence!\n", codigo_carta2);
    } else {
        printf("Super Poder: Empate!\n");
    }

    return 0;
}