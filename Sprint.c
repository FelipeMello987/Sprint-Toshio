#include <stdio.h>
#include <string.h>

int main() {
    int energia, hora, minuto, recarregada;
    float custo;
    char vip[10];

    printf("========== SIMULADOR DE RECARGA ==========\n");
    printf("Preco da recarga é R$0,40 para cada 1%% de recarga\n");
    printf("Voce é cliente premium para ganhar 10%% de desconto?[S/N] ");
    scanf("%s", vip);
    printf("Qual a carga atual em porcentagem: ");
    scanf("%d", &energia);

    hora = 0;
    minuto = -1;
    recarregada = (100 - energia);
    custo = recarregada * 0.4;

    if (energia >= 100){
        energia = 99;
    }
    if (energia < 0){
        energia = 0;
    }

    printf("!!!INICIANDO RECARGA!!!\n");
    while (energia <= 100) {
        printf("Energia atual: %d%%\n", energia);
        minuto += 1;
        energia += 1;
    }

    if (minuto >= 60){
        hora = minuto/60;
        minuto = minuto-60;
    }

    printf("DEBUG: vip = %s\n", vip);
    if (strcmp(vip, "s") == 0) {
        custo = custo * 0.9;
    }   

    printf("========== RECARGA COMPLETA ==========\n");
    printf("Tempo gasto: %d hora(s)", hora);
    printf(" e %d minuto(s)\n",minuto);
    printf("Energia recarregada: %d%%\n", recarregada);
    printf("Valor a se pagar: R$%.2f", custo);
    return 0;
}