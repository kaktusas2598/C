#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "location.h"

bool parseAndExecute(char* input) {
    char* verb = strtok(input, " \n");
    char* noun = strtok(NULL, " \n");

    if (verb != NULL) {
        if (strcmp(verb, "quit") == 0) {
            return false;
        } else if (strcmp(verb, "look") == 0) {
            executeLook(noun);
            /*printf("You are in the dark forest surrounded by ancient oak tress.\n");*/
        } else if (strcmp(verb, "go") == 0) {
            executeGo(noun);
            /*printf("It is too dark to go anywhere.\n");*/
        } else {
            printf("How do you %s?\n", verb);
        }
    }
    return true;
}
