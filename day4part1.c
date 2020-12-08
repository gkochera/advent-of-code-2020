//
//  day4part1.c
//  adventofcode
//
//  Created by George J Kochera III on 12/7/20.
//  Copyright © 2020 George J Kochera III. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

FILE* reader() {
    // open the file
    FILE * fp;
    fp = fopen("day4part1.txt", "r"); // returns a pointer to the file
    if (fp == NULL) {
        perror("File not found");
        return(NULL);
    }
    return fp;
}

void get_lines(FILE* file_pointer, char  neat_lines[]) {
    int index = 0;
    while(fgets(&neat_lines[index], 150, file_pointer) != NULL) {
        index++;
    }
}

int main(int argc, const char * argv[]) {
    FILE * fp = reader();
    char *lines_separated[3000] = { malloc( sizeof(char) * 150 ) };
    get_lines(fp, lines_separated);

}

    
