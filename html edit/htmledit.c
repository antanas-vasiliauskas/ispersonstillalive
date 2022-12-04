#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define spec '|'

void htmlEdit(FILE *file, char strings[][100]){
    int flength, loopDepth = 0, tempLength, replaceNr = 0;
    int repNum[10];
    char copy[1000], replace[1000];
    char *tempName = malloc(10);
    char *loop;
    strcpy(tempName, "t0.txt");
    FILE **temps = malloc(10 * sizeof(FILE*));
    temps[0] = fopen(tempName, "w+");
    fseek(file, 0, SEEK_END);
    flength = ftell(file);
    fseek(file, 0, SEEK_SET);
    while(ftell(file) < flength){
        fgets(copy, 1000, file);
        loop = strstr(copy, "(repeat) ");
        if(loop == NULL){
            loop = strstr(copy, "(endrep)\n");
            if(loop == NULL){
                fputs(copy, temps[loopDepth]);
            }
            else{
                tempLength = ftell(temps[loopDepth]);
                for(int i = 0; i < repNum[loopDepth]; ++i){
                    tempLength = ftell(temps[loopDepth]);
                    fseek(temps[loopDepth], 0, SEEK_SET);
                    while(ftell(temps[loopDepth]) < tempLength){
                        fgets(copy, 1000, temps[loopDepth]);
                        fputs(copy, temps[loopDepth - 1]);
                    }
                }
                fclose(temps[loopDepth]);
                sprintf(tempName, "t%d.txt", loopDepth);
                remove(tempName);
                --loopDepth;
            }
        }
        else{
            ++loopDepth;
            repNum[loopDepth] = atoi(loop + 9);
            sprintf(tempName, "t%d.txt", loopDepth);
            temps[loopDepth] = fopen(tempName, "w+");
        }
    }
    //---------------------------------------------------------------------
    fseek(file, 0, SEEK_SET);
    fseek(temps[0], 0, SEEK_END);
    flength = ftell(temps[0]);
    fseek(temps[0], 0, SEEK_SET);
    while(ftell(temps[0]) < flength){
        fgets(copy, 1000, temps[0]);
        while(strchr(copy, spec) != NULL){
            strcpy(replace, strchr(copy, spec) + 1);
            *strchr(copy, spec) = '\0';
            strcat(copy, strings[replaceNr]);
            ++replaceNr;
            strcat(copy, replace);
        }
        fputs(copy, file);
    }
    fclose(temps[0]);
    remove("t0.txt");
}
