#include <stdlib.h>
#include "memory.h"

/** 
 * Reallocates an array to a specific memory location
 * with the new size of the array taken into account.
*/
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if(newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    if(result == NULL) exit(1);

    return result;
}

/**
 * Frees a singular object node from the linked list in memory.
*/
static void freeObject(Obj* object) {
    switch(object -> type) {
        case OBJ_STRING: {
            ObjString* string = (ObjString*)object;
            FREE_ARRAY(char, string -> chars, string -> length + 1);
            FREE(ObjString, object);
            break;
        }
    }
}

/**
 * Parsing through a linked list and freeing all object nodes.
*/
void freeObjects() {
    Obj* object = vm.objects;
    while(object != NULL) {
        Obj* next = object -> next;
        freeObject(object);
        object = next;
    }
}