//
//  day3part1.c
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


int main(int argc, const char * argv[]) {
    
    // open the file
    FILE *fp;
    fp = fopen("day3part1.txt", "r"); // returns a pointer to the file
    if (fp == NULL) {
        perror("File not found");
        return(1);
    }
    
    // set up the number array, badly
    char char_arr[323][32];
    int index = 0;
    
    // read the numbers and strip the newline and zero characters
    while(fgets(char_arr[index++], 33, fp) != NULL );
    
    // perform calcuations
    int ground = 0, trees = 0;
    int x = 0, y = 0;
    while (y < index - 1) {
        if (y != 0) {
            if ( char_arr[y][x] == '.' ) {
                ground++;
            } else if (char_arr[y][x] == '#')  {
                trees++;
            }
            char temp[50] = {0};
            int cursor = 0;
            bool target = false;
            while (cursor < 40) {
                if (cursor != x) {
                    if (target) {
                        temp[cursor] = char_arr[y][cursor - 9];
                        cursor++;
                    } else {
                        temp[cursor] = char_arr[y][cursor];
                        cursor++;
                    }
                } else {
                    target = true;
                    strcpy(&temp[cursor], ANSI_COLOR_GREEN);
                    cursor += 5;
                    temp[cursor] = char_arr[y][cursor - 5];
                    cursor++;
                    strcpy(&temp[cursor], ANSI_COLOR_RESET);
                    cursor += 4;
                }
            }
            printf("%.40s -> Current Char: %c | x: %3i y: %3i | trees: %3i ground: %3i\n", temp, char_arr[y][x], x, y, trees, ground);
        }
        
        y += 2;
        x += 1;
        if ( x > 30 ) {
            x -= 31;
        }
    }
    
    printf("\nTrees: %i\nGround: %i\n", trees, ground);
    
    // report the numbers read
    printf("Lines Read: %i\n\n", index - 1);
    return 0;
}
