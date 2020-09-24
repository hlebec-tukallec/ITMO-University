#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    //in.txt  out.txt  codir
    if (argc != 3) {
        printf("Wrong arguments! Try again.");
        return 1;
    }
    FILE *r;
    if ((r = fopen(argv[0], "r")) == NULL) {
        printf("Can't open the input file");
        return 2;
    }
    FILE *w;
    if((w = fopen(argv[1], "w")) == NULL) {
        printf("Can't open the output file");
        return 3;
    }
    unsigned char test_bom[4];
    fread(test_bom, sizeof(char), sizeof(test_bom), r);
    rewind(r);

    if (test_bom[0] == 0xEF && test_bom[1] == 0xBB && test_bom[2] == 0xBF) {
        //UTF-8 with BOM
        const char *str;
        const char *tmp;
        fscanf(r, "%s", str);
        for (unsigned char *i = (unsigned char *) str; *i; ++i) {
            strcat(tmp, *i);
        }
        strcpy(str, tmp);

        int i = 1;
        while (i <= strlen(str)) {


        }

    }

    else if (test_bom[0] == 0xFE && test_bom[1] == 0xFF) {
        //UTF-16 BE
    }

    else if (test_bom[0] == 0x00 && test_bom[1] == 0x00 && test_bom[2] == 0xFE && test_bom[3] == 0xFF) {
        //UTF-32 BE
    }

    else if (test_bom[0] == 0xFF && test_bom[1] == 0xFE && test_bom[2] == 0x00 && test_bom[3] == 0x00) {
        //UTF-32 LE
    }

    else if (test_bom[0] == 0xFF && test_bom[1] == 0xFE) {
        //UTF-16 LE
    }

    else {
        //UTF-8 no BOM
    }


    return 0;
}