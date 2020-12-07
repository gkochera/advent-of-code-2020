//
//  day2part1.c
//  adventofcode
//
//  Created by George J Kochera III on 12/7/20.
//  Copyright © 2020 George J Kochera III. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool check_line(int x, int y, char a, char* array, int array_length) {
    if (array[x-1] == a || array[y-1] == a) {
        if (array[x-1] != array[y-1]) {
            return true;
        }
    }
    return false;
}

int main() {
    
    // open the file
    FILE *fp;
    fp = fopen("day2part2.txt", "r"); // returns a pointer to the file
    if (fp == NULL) {
        perror("File not found");
        return(1);
    }
    
    // set up the character array, and fill it, count the number of lines read
    int C_BUFFER = 100;
    char char_arr[10000][C_BUFFER];
    int index = 0;
    int number_of_items_read = 0;
    while(fgets(char_arr[index], C_BUFFER, fp) != NULL) {
        number_of_items_read++;
        index++;
    }
    
    // go back to the beginning of the stream
    rewind(fp);
    
    // parse the array
    int STRING_LENGTH = 100;
    int valid_passwords = 0, invalid_passwords = 0;
    for (index = 0; index < number_of_items_read; index++) {
        int x = 0, y = 0;
        char a = ' ';
        char b_arr[STRING_LENGTH];
        fscanf(fp, "%d-%d %c: %s", &x, &y, &a, b_arr);
        if (check_line(x, y, a, b_arr, STRING_LENGTH)) {
            valid_passwords++;
        } else {
            invalid_passwords++;
        }
    }
    
    // report the numbers read
    printf("\nNumbers Read: %i\nValid Passwords: %i\nInvalid Passwords: %i\n", number_of_items_read, valid_passwords, invalid_passwords);
    
}
