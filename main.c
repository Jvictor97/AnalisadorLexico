/*  Disciplina: CC6252 - Compiladores
 *  Projeto II - Variáveis e Números
 *  Desenvolvido por: João Victor Fernandes de Souza - RA: 22116012-0
 *                    Marcus Vinicius Sato Moré      - RA: 22115003-0
 */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// Adicionando arquivo de funções auxiliares
#include "helpers.c"

char TempS[11];
char buff[200];
char e[100];
char m[50][11];
int TempN;
int p = 0, idx = -1;

void S1();
void S2();
void S3();
void S4();
void S5();
void S6();
void printVar(int);
void printInt(int);

int main(){

    printf("\nDigite a entrada: ");
    gets(e);
    printf("\nSaida:\n");
    goto E0;

E0:
    if((e[p] >= 'a' && e[p] <= 'z') || (e[p] >= 'A' && e[p] <= 'Z')){
        S1();
        goto E1;
    }
    else
        if(e[p] >= '0' && e[p] <= '9'){
            S4();
            goto E2;
        }
        else
            if(e[p] == ' '){
                p++;
                goto E0;
            }
            else 
                if(e[p] == '\0')
                    goto SAIDA;

E1:
    if((e[p] >= 'a' && e[p] <= 'z') || (e[p] >= 'A' && e[p] <= 'Z') || (e[p] >= '0' && e[p] <= '9')){
        S2();
        goto E1;
    }
    else{
        S3();
        goto E0;
    }

E2:
    if(e[p] >= '0' && e[p] <= '9'){
        S5();
        goto E2;
    }
    else{
        S6();
        goto E0;
    }
        
SAIDA:
    printf("%s", buff);
    printf("\n");
    if(idx >= 0)
        printf("\nTabela de Variaveis:\n");
    for(int i = 0; m[i][0] != 0; i++){
        printf("    %d....%s\n", i, m[i]);
    }
    printf("\n");
    //system("pause");
    return 0;
}

void S1(){
    concat(TempS, e[p]);
    p++;
}

void S2(){
    concat(TempS, e[p]);
    p++;
}

void S3(){
    concat(TempS, '\0');

    for(int i = 0; i <= idx; i++){
        if(iguais(TempS, m[i])){
            printVar(i);
            TempS[0] = '\0';
            return;
        }
    }
    idx++;
    copy(m[idx], TempS);
    printVar(idx);
    TempS[0] = '\0';
}

void S4(){
    TempN = e[p] - '0';
    p++;
}

void S5(){
    TempN = TempN * 10 + (e[p] - '0');
    p++;
}

void S6(){
    printInt(TempN);
}

void printVar(int p){
    printf("V(%d) ", p);
}

void printInt(int i){
    printf("N(%d) ", i);
}