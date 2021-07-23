#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<time.h>
#include<string.h>
#include<conio.h>
//Tamanho da Matriz//
int linha = 25;
int coluna = 80;
int main() {
    setlocale(LC_ALL, "portuguese");
    FILE * words;
    
    int a, h = 0, v = 0, d = 0, di = 0, ops;
    int l, c, j, i, matriz[100][100], total, pos;
    char x, y[50], op;

    srand((unsigned) time(NULL));
    words = fopen("words.txt", "r");
    for (i = 0; i < linha; i++) {
        printf("\n");
        for (j = 0; j < coluna; j++) {
            matriz[i][j] = (65 + rand() % 26);
        }
    }
    fflush(stdin);
    fflush(stdout);
    //Lendo o arquivo com as palavras//
    while (fscanf(words, "%s\n", & y) != EOF) {
        h = 0;
        v = 0;
        d = 0;

        printf("\n%s\n", y);
        total = strlen(y);
        printf("%d", total);
        printf("\n\n");
        //Gerando posição automatica e imprimindo a resposta do Caça Palavras//
        l = rand() % linha;
        printf("\nlinha: %d", l);
        
        c = rand() % coluna;
        printf("\ncoluna: %d", c);
        //Checando onde pode ser inserida a palavra//
        if (total < coluna - c) {
            //Pode inserir no sentido leste/Oeste//
            h = 1;
        }
        if (total < (linha - l)) {
        //Pode inserir no sentido Norte/Sul//
            v = 1;
        }
        if ((total < (coluna - c)) && (total < (linha - l))) {
        //Pode inserir no sentido Sudeste/Noroeste//
            d = 1;
        }
        if ((total < (coluna - c)) && (total< l-4)) {
		//Pode inserir no sentido Sudoeste/Nordeste//
            di = 1;
        }

       //Gerando aleatoriamente o sentido em que a palavra será inserida//
        if ((h == 1) && (v == 1) && (d == 1) && (di == 1)) {
            pos = 1 + rand() % 4;
            printf("\n%d", pos);
        }
        if ((h == 0) && (v == 1) && (d == 1) && (di == 1)) {
            pos = 2 + rand() % 3;
            printf("\n%d", pos);
        }
        if ((h == 0) && (v == 0) && (d == 1) && (di == 1)) {
            pos = 3 + rand() % 2;
            printf("\n%d", pos);
        }
        if ((h == 0) && (v == 0) && (d == 0) && (di == 1)) {
            pos = 4;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 1) && (d == 1) && (di == 0)) {
            pos = 1 + rand() % 3;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 1) && (d == 0) && (di == 0)) {
            pos = 1 + rand() % 2;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 0) && (d == 0) && (di == 0)) {
            pos = 1;
            printf("\npos %d", pos);
        }
        if ((h == 0) && (v == 1) && (d == 0) && (di == 0)) {
            pos = 2;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 0) && (d == 1) && (di == 0)) {
            pos = 3;
            printf("\npos %d", pos);
        }
        if ((h == 0) && (v == 0) && (d == 0) && (di == 0)) {
            c = 0;
            l = 0;
            pos=3;
        }
        if ((h == 1) && (v == 0) && (d == 1) && (di == 0)) {
            pos = 1;
            printf("\npos %d", pos);
        }
        if ((h == 0) && (v == 1) && (d == 0) && (di == 1)) {
            pos = 4;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 1) && (d == 0) && (di == 1)) {
            pos = 2;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 0) && (d == 1) && (di == 1)) {
            pos = 3;
            printf("\npos %d", pos);
        }
        if ((h == 0) && (v == 1) && (d == 1) && (di == 0)) {
            pos = 2;
            printf("\npos %d", pos);
        }
        if ((h == 1) && (v == 0) && (d == 0) && (di == 1)) {
            pos = 1;
            printf("\npos %d", pos);
        }
        //Inserindo a palavra na Matriz//
        if (pos == 1) {
            ops = 1 + rand() % 2;
            a = total - 1;
            if (ops == 1) {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[a];
                    c++;
                    a--;
                }
            } else {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[i];
                    c++;
                }
            }
        }
        if (pos == 2) {
            ops = 1 + rand() % 2;
            a = total - 1;
            if (ops == 1) {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[a];
                    l++;
                    a--;
                }
            } else {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[i];
                    l++;
                }
            }

        }
        if (pos == 3) {
            ops = 1 + rand() % 2;
            a = total - 1;
            if (ops == 1) {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[i];
                    l++;
                    c++;
                }
            } else {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[a];
                    l++;
                    c++;
                    a--;
                }
            }

        }
        if (pos == 4) {
            ops = 1 + rand() % 2;
            a = total - 1;
            if (ops == 1) {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[i];
                    l--;
                    c++;
                }
            } else {
                for (i = 0; i < total; i++) {
                    matriz[l][c] = y[a];
                    l--;
                    c++;
                    a--;
                }
            }

        }
    }

	//Imprimindo o Caça Palavras//
    printf("\n\n");
    for (i = 0; i < linha; i++) {
        printf("\n");
        for (j = 0; j < coluna; j++) {
            matriz[i][j];
            printf("%c", matriz[i][j]);

        }
    }
    
    fclose(words);
    printf("\n\n");
    system("pause");
    return 0;
}
