#include <stdio.h>

int main() {
    // Definindo o número de estados e cidades por estado
    int num_estados = 8; // Estados de A a H
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

    // Matriz para armazenar os dados de todas as cidades
    // Cada estado tem 4 cidades, e cada cidade tem 4 propriedades
    int populacoes[8][4];
    float areas[8][4];
    float PIBs[8][4];
    int pontos_turisticos_por_cidade[8][4];
    float densidades_populacionais[8][4];
    float PIBs_per_capita[8][4];

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

            // Armazena os dados na matriz
            populacoes[estado][cidade] = populacao;
            areas[estado][cidade] = area;
            PIBs[estado][cidade] = PIB;
            pontos_turisticos_por_cidade[estado][cidade] = pontos_turisticos;
            densidades_populacionais[estado][cidade] = densidade_populacional;
            PIBs_per_capita[estado][cidade] = PIB_per_capita;
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
        }
    }

    return 0;
}