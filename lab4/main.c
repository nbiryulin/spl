//
// Created by Nikita Biryulin on 14.11.2019.
//
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

 int total_lines = 0;
 int total_words = 0;
 int total_bytes;
 int total_chars;
int c, last = '\n';
int in_space = 1;

bool print_lines, print_words, print_chars, print_bytes;

main() {
    FILE *file;
    file = fopen("/home/maxifier/CLionProjects/lab4/file", "r");
    for(total_bytes = 0; (c= fgetc(file)) !=EOF; ++total_bytes) {
        last = c;
        total_chars++;
        if (isspace(c)) {
            in_space = 1;
            if (c == '\n') {
                total_lines++;
            }
        } else {
            total_words += in_space;
            in_space = 0;
        }
    }
    if (last != '\n') {
        /* count last line if not linefeed terminated */
        total_lines++;
    }

    printf("In file %d lines.\n", total_lines);
    printf("In file %d words.\n", total_words);
    printf("In file %d chars.\n", total_chars);
    printf("In file %d bytes.\n", total_bytes);
    fclose(file);
    return 0;
}

