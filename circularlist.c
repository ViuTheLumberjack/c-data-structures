#include "circularlist.h"

#include <stdio.h>
#include <stdlib.h>


void init(struct circularList* ptr, int size) {

    ptr->buffer = malloc(sizeof(float) * size);
    ptr->size = size;
    ptr->head = 0;
    ptr->tail = 0;
}

boolean suffInsert(struct circularList* ptr, float value){

    if((ptr->tail + 1) % ptr->size == ptr->head) return false;
    else {
        ptr->buffer[ptr->tail] = value;
        ptr->tail++;
        return true;
    }
}

boolean preInsert(struct circularList* ptr, float value){

    if((ptr->tail + 1) % ptr->size == ptr->head) return false;
    else{
        ptr->head = (ptr->head + ptr->size - 1) % ptr->size;
        ptr->buffer[ptr->head] = value;
        return true;
    }
}

boolean ordInsert(struct circularList *ptr, float value) {

    if((ptr->tail + 1) % ptr->size == ptr->head) return false;
    else{
        int position = ptr->head;
        int offset = ptr->tail;
        while(ptr->buffer[position] < value) position = (position + 1) % ptr->size;
        while(offset != position) {
            ptr->buffer[offset] = ptr->buffer[(offset-1 + ptr->size) % ptr->size];
            offset = (offset + ptr->size - 1) % ptr->size;
        }
        ptr->buffer[position] = value;
        ptr->tail = (ptr->tail + 1) % ptr->size;
        return true;
    }
}

boolean removeHead(struct circularList *ptr) {

    if(ptr->head == ptr->tail) return false;
    else{
        ptr->head = (ptr->head + 1) % ptr->size;
        return true;
    }
}

boolean removeTail(struct circularList *ptr) {
    if(ptr->head == ptr->tail) return false;
    else{
        ptr->tail = (ptr->tail - 1 + ptr->size) % ptr->size;
        return true;
    }
}

boolean seekNDestroy(struct circularList *ptr, float value) {

    boolean found = false;
    int position;
    for(position = ptr->head; position != ptr->tail && !found; position = (position + 1) % ptr->size){
        if(ptr->buffer[position] == value){
            int offset = (ptr->tail - 1 + ptr->size) % ptr->size;
            while(offset != position){
                ptr->buffer[offset] = ptr->buffer[(offset + 1) % ptr->size];
                offset = (offset - 1 + ptr->size) % ptr->size;
            }
            found = true;
        }
    }
    return found;
}

void visit(struct circularList *ptr){

    int position;
    for(position = ptr->head; position != ptr->tail; position = (position + 1) % ptr->size){
        printf("%d valore: %f", position, ptr->buffer[position]);
    }
}

boolean search(struct circularList *ptr, float value){

    int position = ptr->head;
    int found = false;
    /*
    for(position = ptr->head; position != ptr->tail; position = (position + 1) % ptr->size){
        if(ptr->buffer[position] == value) return true;
    }
    return false;
     */
    while(position != ptr->tail && !found){
        if(ptr->buffer[position] == value) found = true;
        else position = (position + 1) % ptr->size;
    }

    return found;
}