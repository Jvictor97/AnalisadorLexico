/*  Disciplina: CC6252 - Compiladores
 *  Projeto III - Analisador Léxico
 *  Desenvolvido por: João Victor Fernandes de Souza - RA: 22116012-0
 *                    Marcus Vinicius Sato Moré      - RA: 22115003-0
 */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// Adicionando arquivo de funções auxiliares
#include "helpers.c"

char TempC;
char TempS[11];
char buff[200];
char e[100];
char m[50][11]; // Tabela de Variáveis
char w[9][6] = { 
    "IF", "ELSE", "GOTO", 
    "END", "THEN", "READ", 
    "PRINT", "LET", "OF" 
}; // Tabela de Palavras Reservadas
int TempN;
int p = 0, idx = -1;

void S1();
void S2();
void S3();
void S4();
void S5();
void S6();
void S7();
void S8();
void S9();
void S10();
void printVar(int);
void printInt(int);
void printWord(int);

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
                if(e[p] == ':'){
                    p++;
                    goto E3;
                }
                else 
                    if(e[p] == '%'){
                        //p++; // VERIFICAR
                        goto E5;
                    }
                    else 
                        if(e[p] == '\0')
                            goto SAIDA;
                        else{
                            S9();
                            goto E6;    
                        }

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
        
E3:
    if(e[p] == '='){
        p++;
        goto E4;
    }
    else {
        p++;
        S8();
        goto E0;
    }

E4:
    S7();
    goto E0;

E5:
    if(e[p] == '\0')
        goto E0;
    else{
        p++;
        goto E5;
    }

E6: 
    S10();
    goto E0;

SAIDA:
    printf("%s", buff);
    printf("\n");
    if(idx >= 0){
        printf("\nTabela de Variaveis:\n");
        for(int i = 0; m[i][0] != 0; i++){
            printf("    %d....%s\n", i, m[i]);
        }
        printf("\nTabela de Palavras:\n");
        for(int i = 0; i < 9; i++){
            printf("    %d....%s\n", i, w[i]);
        }
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
    //concat(TempS, '\0');

    for(int i = 0; i < 9; i++){
        if(iguais(TempS, w[i])){
            printWord(i);
            TempS[0] = '\0';
            return;
        }
    }

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

void S7(){
    printf(":= ");
}

void S8(){
    printf(": ");
}

void S9(){
    TempC = e[p];
    p++;
}

void S10(){
    printf("%c", TempC);
}

void printVar(int p){
    printf("V(%d) ", p);
}

void printInt(int i){
    printf("N(%d) ", i);
}

void printWord(int i){
    printf("P(%d) ", i);
}