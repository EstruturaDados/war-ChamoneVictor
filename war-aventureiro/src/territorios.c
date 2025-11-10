#include "territorios.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMapa(Territorio* territorios) {
    printf("\n=== MAPA ATUAL ===\n");
    printf("+------------------------------------------------+\n");
    printf("| %-20s | %-15s | %-6s |\n", "TERRITORIO", "COR", "TROPAS");
    printf("+------------------------------------------------+\n");
    
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("| %-20s | %-15s | %-6d |\n", 
               territorios[i].nome, 
               territorios[i].cor, 
               territorios[i].tropas);
    }
    printf("+------------------------------------------------+\n");
}

Territorio* alocarTerritorios(int quantidade) {
    Territorio* territorios = (Territorio*)calloc(quantidade, sizeof(Territorio));
    if (territorios == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return territorios;
}

void liberarTerritorios(Territorio* territorios) {
    if (territorios != NULL) {
        free(territorios);
    }
}

void cadastrarTerritoriosDinamico(Territorio* territorios) {
    printf("=== CADASTRO DE TERRITORIOS ===\n");
    
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\n--- Territorio %d ---\n", i + 1);
        
        printf("Nome: ");
        fgets(territorios[i].nome, TAM_NOME, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        
        printf("Cor do exercito: ");
        fgets(territorios[i].cor, TAM_COR, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        
        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer();
    }
}

int lancarDado() {
    return rand() % 6 + 1;
}

void simularBatalha(Territorio* atacante, Territorio* defensor) {
    printf("\n=== INICIANDO BATALHA ===\n");
    printf("%s (%s) ataca %s (%s)\n", 
           atacante->nome, atacante->cor, 
           defensor->nome, defensor->cor);
    
    int dadoAtacante = lancarDado();
    int dadoDefensor = lancarDado();
    
    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);
    
    if (dadoAtacante >= dadoDefensor) {
        // Atacante vence
        defensor->tropas--;
        printf(">>> VITORIA DO ATACANTE! <<<\n");
        printf("%s perde 1 tropa. Tropas restantes: %d\n", 
               defensor->nome, defensor->tropas);
        
        if (defensor->tropas <= 0) {
            printf(">>> %s FOI CONQUISTADO! <<<\n", defensor->nome);
            // O atacante assume o controle (muda a cor)
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1; // Mínimo de 1 tropa no território conquistado
        }
    } else {
        // Defensor vence
        atacante->tropas--;
        printf(">>> VITORIA DO DEFENSOR! <<<\n");
        printf("%s perde 1 tropa. Tropas restantes: %d\n", 
               atacante->nome, atacante->tropas);
    }
}

void faseAtaque(Territorio* territorios) {
    int atacante, defensor;
    
    printf("\n=== FASE DE ATAQUE ===\n");
    exibirMapa(territorios);
    
    printf("\nEscolha o territorio ATACANTE (1-%d): ", MAX_TERRITORIOS);
    scanf("%d", &atacante);
    printf("Escolha o territorio DEFENSOR (1-%d): ", MAX_TERRITORIOS);
    scanf("%d", &defensor);
    limparBuffer();
    
    if (atacante < 1 || atacante > MAX_TERRITORIOS || 
        defensor < 1 || defensor > MAX_TERRITORIOS || 
        atacante == defensor) {
        printf("Escolha invalida!\n");
        return;
    }
    
    // Ajustar índices para base 0
    atacante--;
    defensor--;
    
    if (territorios[atacante].tropas <= 1) {
        printf("Territorio atacante precisa de pelo menos 2 tropas!\n");
        return;
    }
    
    if (strcmp(territorios[atacante].cor, territorios[defensor].cor) == 0) {
        printf("Nao pode atacar territorios da mesma cor!\n");
        return;
    }
    
    simularBatalha(&territorios[atacante], &territorios[defensor]);
}