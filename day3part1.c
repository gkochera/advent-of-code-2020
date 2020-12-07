//
//  day3part1.c
//  adventofcode
//
//  Created by George J Kochera III on 12/7/20.
//  Copyright © 2020 George J Kochera III. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

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
    int number_of_items_read = 0;
    
    // read the numbers
    while (fscanf(fp, "%s\n", char_arr[index]) == 1) {
        index++;
        number_of_items_read++;
    }
    int ground = 0, trees = 0;
    int x = 0, y = 0;
    while (y < 324) {
        if ( char_arr[y][x] == '.' ) {
            ground++;
        } else {
            trees++;
        }
        y++;
        x += 3;
        if ( x > 31 ) {
            x %= 31;
        }
    }
    
    printf("Trees: %i\nGround: %i\n", trees, ground);
    
    // report the numbers read
    printf("Lines Read: %i\n", number_of_items_read);
    printf("%c\n", char_arr[0][31]);
    
    return 0;
}
