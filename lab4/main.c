//
// Created by Nikita Biryulin on 14.11.2019.
//
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define STRMAX 100

int lines = 0;
int words = 0;
int bytes = 0;
int chars = 0;

int total_lines = 0;
int total_words = 0;
int total_bytes = 0;
int total_chars = 0;

int c, last = '\n';
int in_space = 1;
int key_counter;
int files_counter;
char s[STRMAX];
FILE *file;

bool print_lines, print_words, print_chars, print_bytes;


bool prefix(const char *pre, const char *str) {
    //checks whether str starts with pre
    return strncmp(pre, str, strlen(pre)) == 0;
}

void printing(char filename[]){
    if(key_counter < 1) {
        printf("%d %d %d %s \n", lines, words, chars, s);
    } else {
        if(print_lines) printf("%d ", lines);
        if(print_words) printf("%d ", words);
        if(print_chars) printf("%d ", chars);
        if(print_bytes) printf("%d ", bytes);
        printf("%s \n", filename);
    }
}

void total_printing(char filename[]){
    if(key_counter < 1) {
        printf("%d %d %d %s \n", total_lines, total_words, total_chars, filename);
    } else {
        if(print_lines) printf("%d ", total_lines);
        if(print_words) printf("%d ", total_words);
        if(print_chars) printf("%d ", total_chars);
        if(print_bytes) printf("%d ", total_bytes);
        printf("%s \n", filename);
    }
}

void makingZero(){
    total_lines += lines;
    total_words += words;
    total_bytes += bytes;
    total_chars += chars;
    lines = 0;
    words = 0;
    bytes = 0;
    chars = 0;
}

void wc(char filename[]){
    strncpy(s, filename, STRMAX - 1);
    file = fopen(s, "r");
    for (bytes = 0; (c = fgetc(file)) != EOF; ++bytes) {
        last = c;
        chars++;
        if (isspace(c)) {
            in_space = 1;
            if (c == '\n') {
                lines++;
            }
        } else {
            words += in_space;
            in_space = 0;
        }
    }
    if (last != '\n') {
        /* count last line if not linefeed terminated */
        lines++;
    }
    fclose(file);
    printing(s);
}



int main(int argc, char *argv[]) {
    if (argc >= 2) {
        // at list one argument
        for (int i = 1; i < argc; i++) {
            if (prefix("-", argv[i])) {
                key_counter++;
                if (strcmp(argv[i], "-") == 0) {
                    // if - read stdin
                } else {
                    if(strcmp(argv[i], "-l") == 0){
                        print_lines = true;
                    } else if (strcmp(argv[i], "-c") == 0){
                        print_bytes = true;
                    } else if (strcmp(argv[i], "-m") == 0) {
                        print_chars = true;
                    } else if (strcmp(argv[i], "-w") == 0) {
                        print_words = true;
                    }
                }
            } else {
                makingZero();
                files_counter++;
                wc(argv[i]);
            }
        }
        makingZero();
        total_printing("итого");
    }
//    if((fd=open("TEST.TST", O_RDONLY))==-1) {
//        printf("Cannot open file.\n");
//        exit(1);
//    }
// check for open file
/**
 * при несуществующем ключе
 * wc: неверный ключ — «b»
* По команде «wc --help» можно получить дополнительную информацию.

при неуществующем файле
wc: fiale2: Нет такого файла или каталога
 */
    return 0;
}

