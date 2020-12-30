//
// Created by silvi on 28/12/2020.
//

#include "indexlinkedlist.h"

#include <stdio.h>
#include <stdlib.h>

void init(struct indexLinkedList *ptr, int size) {
    int count;
    ptr->free = 0;
    ptr->size = size;
    ptr->first = ptr->size;
    ptr->buffer = malloc(sizeof(struct record) * size);

    for(count = 0; count < size; count++){
        ptr->buffer[count].next = count + 1;
    }
}

boolean preInsert(struct indexLinkedList *ptr, float value) {
    if(ptr->free == ptr->size) return false;
    else{
        int temp;
        temp = ptr->free;
        ptr->free = ((ptr->buffer)[ptr->free]).next;

        ptr->buffer[temp].next = ptr->first;
        ptr->buffer[temp].item = value;
        ptr->first = temp;

        return true;
    }
}

boolean suffInsert(struct indexLinkedList *ptr, float value) {
    if(ptr->free == ptr->size) return false;
    else{
        int temp;
        int position = ptr->first;
        temp = ptr->free;
        ptr->free = ((ptr->buffer)[ptr->free]).next;

        while(ptr->buffer[position].next != ptr->size)
            position = ptr->buffer[position].next;

        ptr->buffer[position].next = temp;
        ptr->buffer[temp].next = ptr->size;
        ptr->buffer[temp].item = value;

        return true;
    }
}

boolean ordInsert(struct indexLinkedList *ptr, float value) {
    if(ptr->free == ptr->size) return false;
    else{
        int temp;
        int position = ptr->first;
        temp = ptr->free;
        ptr->free = ((ptr->buffer)[ptr->free]).next;

        while(ptr->buffer[position].next != ptr->size && ptr->buffer[position].item < value)
            position = ptr->buffer[position].next;

        ptr->buffer[temp].next = ptr->buffer[position].next;
        ptr->buffer[temp].item = value;
        ptr->buffer[position].next = temp;

        return true;
    }
}

boolean removeHead(struct indexLinkedList *ptr) {

    if(ptr->first == ptr->size) return false;
    else {
        int position;
        int temp;
        temp = ptr->first;
        position = ptr->free;
        while (ptr->buffer[position].next != ptr->size)
            position = ptr->buffer[position].next;

        ptr->first = ptr->buffer[temp].next;
        ptr->buffer[temp].next = ptr->size;
        ptr->buffer[position].next = temp;

        return true;
    }
}

boolean removeTail(struct indexLinkedList *ptr) {

    if(ptr->first == ptr->size) return false;
    else {
        int *position, *previous;

        position = &(ptr->first);
        while(*position != ptr->size){
            previous = position;
            position = &(ptr->buffer[*position].next);
        }

        ptr->buffer[*position].next = ptr->free;
        ptr->free = ptr->buffer[*previous].next;
        ptr->buffer[*previous].next = ptr->size;

        return true;
    }
}

boolean seekNDestroy(struct indexLinkedList *ptr, float value) {

    if(ptr->first == ptr->size) return false;
    else {
        int *position, *previous;

        position = &(ptr->first);
        while(*position != ptr->size && ptr->buffer[*position].item < value){
            previous = position;
            position = &(ptr->buffer[*position].next);
        }

        ptr->buffer[*previous].next = ptr->buffer[*position].next;
        ptr->buffer[*position].next = ptr->free;
        ptr->free = *position;

        return true;
    }
}

void visit(struct indexLinkedList *ptr) {

    int position;
    for(position = ptr->first; position != ptr->size; position = ptr->buffer[position].next){
        printf("%d valore: %f", position, ptr->buffer[position].item);
    }
}

boolean search(struct indexLinkedList *ptr, float value) {
    int position;
    boolean found = false;
    for(position = ptr->first; position != ptr->size && !found; position = ptr->buffer[position].next){
        if(ptr->buffer[position].item == value) found = true;
    }
    return found;
}
