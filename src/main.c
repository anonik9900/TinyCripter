#include <stdio.h>
#include <string.h>
#include <math.h>
#define false 0
#define true !false

int even = false;

int crypt(char ch) {
        int intCh = ch - '0';
        intCh *= 32;
        intCh += intCh - 13;
        if(even == true) {
                intCh /= 3;
        }
        else {
                intCh *= 2;
        }
        return abs(intCh);
}

int main(int argc, char *argv[]) {
        printf("##################\n");
        printf("# TinyCripter #\n");
        printf("Devolved By Anonik (c) 2018\n");
        printf("##################\n\n");
        if(argc != 2) {
                printf("[WARNING] Usage %­s filename\n", argv[0]);
        }
        else {
                printf("Crypting...\n");
        FILE *file = fopen( argv[1], "r" );
        if ( file == 0 )
        {
            printf( "[WARNING] Unable to open the file!\n" ); //Impossibile aprire il file
        }
        else
        {
            int x;
            FILE *new = fopen("crypted.txt","w");
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                fprintf(new, "%d", crypt(x));
            }
            fclose(file);
            fclose(new);
            printf("\n\a[DONE] Created file crypted.txt.\n");
        }
        }
}
