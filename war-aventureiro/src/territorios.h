#ifndef TERRITORIOS_H
#define TERRITORIOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERRITORIOS 5
#define TAM_NOME 50
#define TAM_COR 20

typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

// Funções utilitárias
void limparBuffer();
void exibirMapa(Territorio* territorios);

// Gerenciamento de territórios
Territorio* alocarTerritorios(int quantidade);
void cadastrarTerritoriosDinamico(Territorio* territorios);
void liberarTerritorios(Territorio* territorios);

// Sistema de batalha
int lancarDado();
void simularBatalha(Territorio* atacante, Territorio* defensor);
void faseAtaque(Territorio* territorios);

// Função principal do nível aventureiro
int main_aventureiro();

#endif