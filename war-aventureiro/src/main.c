#include "territorios.h"

int main() {
    return main_aventureiro();
}

int main_aventureiro() {
    srand(time(NULL));
    
    Territorio* territorios = alocarTerritorios(MAX_TERRITORIOS);
    
    cadastrarTerritoriosDinamico(territorios);
    
    char continuar;
    do {
        exibirMapa(territorios);
        faseAtaque(territorios);
        
        printf("\nContinuar atacando? (s/n): ");
        scanf(" %c", &continuar);
        limparBuffer();
    } while (continuar == 's' || continuar == 'S');
    
    printf("\n=== MAPA FINAL ===\n");
    exibirMapa(territorios);
    
    liberarTerritorios(territorios);
    return 0;
}