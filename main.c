#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 64

void simple();
void safe();

int main(){
    safe();
    return 0;
}

void simple(){
    FILE *fip, *fop;
    char buffer[BUFF_SIZE], line[BUFF_SIZE];

    fip = fopen("input", "r");
    fop = fopen("output", "w");

    fgets(line, BUFF_SIZE, fip);

    fprintf(fop, "%s", line);

    fclose(fip);
    fclose(fop);
}

void safe(){
    FILE *fip, *fop;
    char buffer[BUFF_SIZE], line[BUFF_SIZE];

    fip = fopen("input", "r");
    fop = fopen("output", "w");

    fgets(line, BUFF_SIZE, fip);
    strcpy(buffer, line);
    while(!strcmp(buffer, line)){
        strcpy(buffer, line);
        fclose(fip);
        fip = fopen("input", "r");
        fgets(line, BUFF_SIZE, fip);
    }

    fprintf(fop, "%s", line);

    fclose(fip);
    fclose(fop);
}