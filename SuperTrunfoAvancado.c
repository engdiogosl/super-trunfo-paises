#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do jogo
typedef struct {
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
    float pib_per_capita;
} Carta;

// Função para calcular densidade demográfica
float calcular_densidade(int populacao, float area) {
    return area > 0 ? (float)populacao / area : 0;
}

// Função para calcular PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return populacao > 0 ? (pib * 1000000000) / populacao : 0; // Convertendo bilhões para unidades
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade_demografica);
    printf("PIB per Capita: R$ %.2f\n", carta.pib_per_capita);
}

// Função para exibir menu de atributos
void exibir_menu_atributos(int atributo_excluido) {
    printf("\n=== ESCOLHA O ATRIBUTO ===\n");
    
    if (atributo_excluido != 1) printf("1 - População\n");
    if (atributo_excluido != 2) printf("2 - Área\n");
    if (atributo_excluido != 3) printf("3 - PIB\n");
    if (atributo_excluido != 4) printf("4 - Pontos Turísticos\n");
    if (atributo_excluido != 5) printf("5 - Densidade Demográfica\n");
    if (atributo_excluido != 6) printf("6 - PIB per Capita\n");
    
    printf("Escolha uma opção: ");
}

// Função para obter valor do atributo
float obter_valor_atributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade_demografica;
        case 6: return carta.pib_per_capita;
        default: return 0;
    }
}

// Função para obter nome do atributo
const char* obter_nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Atributo Inválido";
    }
}

// Função para obter unidade do atributo
const char* obter_unidade_atributo(int atributo) {
    switch (atributo) {
        case 1: return "habitantes";
        case 2: return "km²";
        case 3: return "bilhões";
        case 4: return "pontos";
        case 5: return "hab/km²";
        case 6: return "R$";
        default: return "";
    }
}

// Função para comparar atributos
int comparar_atributo(float valor1, float valor2, int atributo) {
    // Para densidade demográfica, menor valor vence
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor1 > valor2) ? 2 : 0;
    }
    // Para outros atributos, maior valor vence
    return (valor1 > valor2) ? 1 : (valor1 < valor2) ? 2 : 0;
}

// Função para validar escolha de atributo
int validar_atributo(int atributo, int atributo_excluido) {
    return (atributo >= 1 && atributo <= 6 && atributo != atributo_excluido);
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {
        "A01", "SaoPaulo", 12400000, 1521.11, 443.00, 15
    };
    
    Carta carta2 = {
        "B02", "RioDeJaneiro", 6747000, 1200.27, 140.00, 25
    };
    
    // Calculando atributos derivados
    carta1.densidade_demografica = calcular_densidade(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    
    carta2.densidade_demografica = calcular_densidade(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);
    
    printf("🎮 === SUPER TRUNFO - PAÍSES (NÍVEL AVANÇADO) === 🎮\n");
    printf("Comparação Avançada com Dois Atributos\n\n");
    
    // Exibindo as cartas
    printf("=== CARTA 1 ===\n");
    exibir_carta(carta1);
    
    printf("\n=== CARTA 2 ===\n");
    exibir_carta(carta2);
    
    // Escolha do primeiro atributo
    int atributo1, atributo2;
    int opcao_valida = 0;
    
    do {
        exibir_menu_atributos(0); // 0 = nenhum atributo excluído
        scanf("%d", &atributo1);
        
        opcao_valida = validar_atributo(atributo1, 0);
        
        if (!opcao_valida) {
            printf("❌ Opção inválida! Escolha entre 1 e 6.\n");
        }
    } while (!opcao_valida);
    
    printf("✅ Primeiro atributo escolhido: %s\n", obter_nome_atributo(atributo1));
    
    // Escolha do segundo atributo (menu dinâmico)
    opcao_valida = 0;
    
    do {
        printf("\nAgora escolha o SEGUNDO atributo (diferente do primeiro):\n");
        exibir_menu_atributos(atributo1); // Exclui o primeiro atributo do menu
        scanf("%d", &atributo2);
        
        opcao_valida = validar_atributo(atributo2, atributo1);
        
        if (!opcao_valida) {
            printf("❌ Opção inválida! Escolha um atributo diferente do primeiro.\n");
        }
    } while (!opcao_valida);
    
    printf("✅ Segundo atributo escolhido: %s\n", obter_nome_atributo(atributo2));
    
    // Obtendo valores dos atributos
    float valor1_attr1 = obter_valor_atributo(carta1, atributo1);
    float valor2_attr1 = obter_valor_atributo(carta2, atributo1);
    float valor1_attr2 = obter_valor_atributo(carta1, atributo2);
    float valor2_attr2 = obter_valor_atributo(carta2, atributo2);
    
    // Comparações individuais
    int vencedor_attr1 = comparar_atributo(valor1_attr1, valor2_attr1, atributo1);
    int vencedor_attr2 = comparar_atributo(valor1_attr2, valor2_attr2, atributo2);
    
    // Calculando somas (normalizadas para comparação justa)
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;
    
    // Exibindo resultados da comparação
    printf("\n🏆 === RESULTADO DA COMPARAÇÃO === 🏆\n\n");
    
    printf("📊 COMPARAÇÃO POR ATRIBUTOS:\n");
    printf("┌─────────────────────────────────────────────────────────────┐\n");
    printf("│                    %s vs %s                    │\n", carta1.nome, carta2.nome);
    printf("├─────────────────────────────────────────────────────────────┤\n");
    
    // Primeiro atributo
    printf("│ %s:\n", obter_nome_atributo(atributo1));
    printf("│   %s: %.2f %s\n", carta1.nome, valor1_attr1, obter_unidade_atributo(atributo1));
    printf("│   %s: %.2f %s\n", carta2.nome, valor2_attr1, obter_unidade_atributo(atributo1));
    printf("│   Vencedor: %s\n", 
           vencedor_attr1 == 1 ? carta1.nome : 
           vencedor_attr1 == 2 ? carta2.nome : "Empate");
    printf("│\n");
    
    // Segundo atributo
    printf("│ %s:\n", obter_nome_atributo(atributo2));
    printf("│   %s: %.2f %s\n", carta1.nome, valor1_attr2, obter_unidade_atributo(atributo2));
    printf("│   %s: %.2f %s\n", carta2.nome, valor2_attr2, obter_unidade_atributo(atributo2));
    printf("│   Vencedor: %s\n", 
           vencedor_attr2 == 1 ? carta1.nome : 
           vencedor_attr2 == 2 ? carta2.nome : "Empate");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
    
    // Soma dos atributos e resultado final
    printf("📈 SOMA DOS ATRIBUTOS:\n");
    printf("🏙️  %s: %.2f + %.2f = %.2f\n", carta1.nome, valor1_attr1, valor1_attr2, soma1);
    printf("🏙️  %s: %.2f + %.2f = %.2f\n", carta2.nome, valor2_attr1, valor2_attr2, soma2);
    
    printf("\n🎯 RESULTADO FINAL:\n");
    
    // Determinando o vencedor final usando operador ternário
    const char* resultado_final = (soma1 > soma2) ? carta1.nome :
                                  (soma2 > soma1) ? carta2.nome : "EMPATE";
    
    if (soma1 == soma2) {
        printf("🤝 EMPATE! Ambas as cartas têm a mesma soma de atributos!\n");
    } else {
        printf("🏆 VENCEDOR: %s!\n", resultado_final);
        printf("   Diferença: %.2f pontos\n", soma1 > soma2 ? soma1 - soma2 : soma2 - soma1);
    }
    
    // Estatísticas adicionais
    printf("\n📊 ESTATÍSTICAS DA PARTIDA:\n");
    printf("Atributos comparados: %s e %s\n", 
           obter_nome_atributo(atributo1), obter_nome_atributo(atributo2));
    
    int vitorias_carta1 = (vencedor_attr1 == 1 ? 1 : 0) + (vencedor_attr2 == 1 ? 1 : 0);
    int vitorias_carta2 = (vencedor_attr1 == 2 ? 1 : 0) + (vencedor_attr2 == 2 ? 1 : 0);
    
    printf("Vitórias por atributo - %s: %d | %s: %d\n", 
           carta1.nome, vitorias_carta1, carta2.nome, vitorias_carta2);
    
    printf("\n🎮 Obrigado por jogar Super Trunfo - Países! 🎮\n");
    
    return 0;
}
