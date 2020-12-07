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
    fp = fopen("day1part1.txt", "r"); // returns a pointer to the file
    if (fp == NULL) {
        perror("File not found");
        return(1);
    }
    
    // set up the number array, badly
    int num_arr[10000];
    int index = 0;
    int number_of_items_read = 0;
    
    // read the numbers
    while (fscanf(fp, "%i", &num_arr[index]) == 1) {
        index++;
        number_of_items_read++;
    }
    
    // report the numbers read
    printf("Numbers Read: %i\n", number_of_items_read);
    
    for (int i = 0; i < number_of_items_read; i++) {
        for (int j = i + 1; j <= number_of_items_read; j++) {
            int total = num_arr[i] + num_arr[j];
            if (total == 2020) {
                printf("%i + %i = 2020\n", num_arr[i], num_arr[j]);
                printf("%i + %i = %i\n", num_arr[i], num_arr[j], num_arr[i] * num_arr[j]);
            }
        }
    }
    return 0;
}
