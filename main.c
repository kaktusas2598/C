#include <stdbool.h>
#include <stdio.h>

#include "parsexec.h"

static char input[100] = "look around";
static bool getInput(void) {
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}

int main() {

    printf("Welcome to Text Adventure!\n");

    while(parseAndExecute(input) && getInput());

    printf("\nGood bye!\n");
    return 0;
}
