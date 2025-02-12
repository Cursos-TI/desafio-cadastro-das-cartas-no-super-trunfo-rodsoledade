#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.


int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.


    // Definindo o número de estados e cidades por estado
    int num_estados = 8; // Estados de A a H
    int num_cidades_por_estado = 4; // 4 cidades por estado

    // Variáveis para armazenar os dados da cidade
    char codigo_cidade[4]; // Código da carta (ex: A01, B02, etc.)
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;

    // Mensagem de boas-vindas
    printf("Bem-vindo ao cadastro de cartas do Super Trunfo - Países!\n");

    // Loop para cadastrar as cidades de cada estado
    for (int estado = 0; estado < num_estados; estado++) {
        for (int cidade = 0; cidade < num_cidades_por_estado; cidade++) {
            // Gera o código da carta automaticamente (ex: A01, A02, etc.)
            codigo_cidade[0] = 'A' + estado; // Letra do estado (A, B, C, ..., H)
            codigo_cidade[1] = '0' + (cidade + 1) / 10; // Primeiro dígito do número da cidade
            codigo_cidade[2] = '0' + (cidade + 1) % 10; // Segundo dígito do número da cidade
            codigo_cidade[3] = '\0'; // Terminador da string

            // Solicita os dados da cidade ao usuário
            printf("\nCadastrando cidade %s:\n", codigo_cidade);
            printf("Digite a população da cidade: ");
            scanf("%d", &populacao);
            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &area);
            printf("Digite o PIB da cidade (em milhões): ");
            scanf("%f", &PIB);
            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &pontos_turisticos);

            // Exibe os dados da cidade cadastrada
            printf("\nDados da cidade %s cadastrada:\n", codigo_cidade);
            printf("População: %d habitantes\n", populacao);
            printf("Área: %.2f km²\n", area);
            printf("PIB: %.2f milhões\n", PIB);
            printf("Pontos Turísticos: %d\n", pontos_turisticos);
        }
    }

    return 0;
}