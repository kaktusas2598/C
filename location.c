#include <stdio.h>
#include <string.h>

struct Location {
    const char* description;
    const char* tag;
};

struct Location locs[] = {
    {"a dark forest", "forest"},
    {"a small cave", "cave"}
};

#define numberOfLocations (sizeof locs / sizeof *locs)

static unsigned playerLocation = 0;

void executeLook(const char* noun) {
    if (noun != NULL && strcmp(noun, "around") == 0) {
        printf("You are in %s.\n", locs[playerLocation].description);
    } else {
        printf("I don't understand what you're trying to look at.\n");
    }
}

void executeGo(const char* noun) {
    unsigned i;
    for (i = 0; i < numberOfLocations; i++) {
        if (noun != NULL && strcmp(noun, locs[i].tag) == 0) {
            if (i == playerLocation) {
                printf("Can't get much closer than this.\n");
            } else {
                printf("OK\n");
                playerLocation = i;
                executeLook("around");
            }
            return;
        }
    }
    printf("I don't understand where you're trying to go.\n");
}
