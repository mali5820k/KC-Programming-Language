#include <stdio.h>
#include <string.h>

#include "object.h"
#include "memory.h"
#include "value.h"

/**
 * Initializes an empty value array with no memory allocation.
*/
void initValueArray(ValueArray* array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

/**
 * Writes the specified value to the provided value array,
 * and increases the size of the array with increased memory allocation
 * when necessary.
*/
void writeValueArray(ValueArray* array, Value value) {
    if(array->capacity < array->count + 1) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}

/**
 * Safely frees the memory allocated for the provided value array.
*/
void freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

/**
 * Prints out values with respect to each variable and object type.
*/
void printValue(Value value) {
    //printf("Result: ");
    #ifdef NAN_BOXING
        if (IS_BOOL(value)) {
            printf(AS_BOOL(value) ? "true" : "false");
        } 
        else if (IS_NULL(value)) {
            printf("null");
        } 
        else if (IS_NUMBER(value)) {
            printf("%g", AS_NUMBER(value));
        } 
        else if (IS_OBJ(value)) {
            printObject(value);
        }
    #else
    switch(value.type) {
        case VAL_BOOL:
            printf(AS_BOOL(value) ? "true" : "false");
            break;
        case VAL_NULL: printf("null"); break;
        case VAL_NUMBER: printf("%g", AS_NUMBER(value)); break;
        case VAL_OBJ: printObject(value); break;
    }
    #endif
    //printf("%g ", AS_NUMBER(value)); // This was the original line that caused duplicate prints
}

/**
 * Returns a C-bool for whether or not two values are equal.
*/
bool valuesEqual(Value a, Value b) {
    #ifdef NAN_BOXING
        if (IS_NUMBER(a) && IS_NUMBER(b)) {
            return AS_NUMBER(a) == AS_NUMBER(b);
        }
        return a == b;
    #else
    if(a.type != b.type) return false;

    switch(a.type) {
        case VAL_BOOL:   return AS_BOOL(a) == AS_BOOL(b);
        case VAL_NULL:   return true;
        case VAL_NUMBER: return AS_NUMBER(a) == AS_NUMBER(b);
        case VAL_OBJ:    return AS_OBJ(a) == AS_OBJ(b);
        default:         return false;
    }
    #endif
}