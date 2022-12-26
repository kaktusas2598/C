#include <stdio.h>
#include <string.h>
#include "misc.h"
#include "noun.h"


static unsigned playerLocation = 0;

void executeLook(const char* noun) {
    if (noun != NULL && strcmp(noun, "around") == 0) {
        printf("You are in %s.\n", player->location->description);
        listObjectsAtLocation(player->location);
    } else {
        printf("I don't understand what you're trying to look at.\n");
    }
}

void executeGo(const char* noun) {
    Object* obj = getVisible("Where do you want to go?", noun);
    if (obj == NULL) {
        // already handled in getVisible()
       printf("I don't understand where you're trying to go.\n");
    } else if (obj->location == NULL && obj != player->location) {
        printf("OK.\n");
        player->location = obj;
        executeLook("around");
    } else {
        printf("Can't get much closer than this.\n");
    }
}
