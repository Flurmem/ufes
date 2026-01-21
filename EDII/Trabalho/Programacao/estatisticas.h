#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

typedef struct {
    long long comparacoes; 
    long long trocas;
    double tempo_execucao;
} Estatisticas;

void inicializa_estatisticas(Estatisticas *est);

#endif