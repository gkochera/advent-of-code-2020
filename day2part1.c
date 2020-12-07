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
    printf("\nChecking new word: %s\nMin: %i\nMax: %i\nLetter: %c\n", array, x, y, a);
    int count = 0, index = 0;
    while (index < array_length && array[index] != 0){
        if (array[index] == a){
            count++;
        }
        index++;
    }
    printf("Count: %i\n", count);
    if  (!(x <= count && count <= y)) {
        // invalid password
        return false;
    }
    else {
        // valid password
        return true;
    }
}

int main() {
    
    // open the file
    FILE *fp;
    fp = fopen("day2part1.txt", "r"); // returns a pointer to the file
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
