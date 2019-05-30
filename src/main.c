#include "../libs/mathlib/src/add.h"
#include "../libs/mathlib/src/subtract.h"
#include "../libs/mathlib/src/divide.h"
#include "../libs/mathlib/src/multiply.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


void modify_state(float *state, char opt, float arg) {
    switch(opt) {
        case 'p':
            *state = add(*state, arg);
            break;
        case 'm':
            *state = multiply(*state, arg);
            break;
        case 'd':
            *state = divide(*state, arg);
            break;
        case 's':
            *state = subtract(*state, arg);
            break;
    }
}

char char_sign_map(char opt) {
    switch(opt) {
        case 'p':
            return '+';
        case 'm':
            return '*';
        case 'd':
            return '/';
        case 's':
            return '-';
        default:
            return '\0';
    }
}


int main(int argc, char **argv)
{
    float state;
    int option;

    FILE *f;
    f = fopen("state.txt", "r");

    if (!f) {
        perror("file error");
        exit(2);
    }

    fscanf(f, "%f", &state);

    FILE *of;
    of = fopen("result.txt", "w+");

    while ((option = getopt(argc, argv, "p:d:m:s:")) != -1) {
        fprintf(of, "%.2f\n %c %f = ", state, char_sign_map(option), atof(optarg));
        modify_state(&state, option, atof(optarg));
    }

    fprintf(of, "%.2f\n", state);

    fclose(f);
    fclose(of);



    return 0;
}