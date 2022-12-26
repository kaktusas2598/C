#ifndef __Object__
#define __Object__

struct Object {
    const char* description;
    const char* tag;
    struct Object* location;
};

typedef struct Object Object;
extern Object objs[];

#define field (objs + 0)
#define cave (objs + 1)
#define silver (objs + 2)
#define gold (objs + 3)
#define guard (objs + 4)
#define player (objs + 5)

#define endOfObjs (objs + 6)

#endif // __Object__
