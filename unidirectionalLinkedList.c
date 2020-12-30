//
// Created by silvi on 29/12/2020.
//

#include "unidirectionalLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void init(struct unidirectionalLinkedList **ptr) {

    ptr = NULL;

}

void preInsert(struct unidirectionalLinkedList **ptr, float value) {

    struct unidirectionalLinkedList *tmp;

    tmp = *ptr;
    *ptr = malloc(sizeof(struct unidirectionalLinkedList));
    (*ptr)->next = tmp;
    (*ptr)->value = value;
}

void suffInsert(struct unidirectionalLinkedList **ptr, float value) {


    while((*ptr)->next != NULL) *ptr = (*ptr)->next;
    preInsert(ptr, value);

}

void ordInsert(struct unidirectionalLinkedList **ptr, float value) {

    while((*ptr)->next != NULL && (*ptr)->value < value) *ptr = (*ptr)->next;
    preInsert(ptr, value);

}

boolean removeHead(struct unidirectionalLinkedList **ptr, float *value) {

    struct unidirectionalLinkedList *tmp;

    if(ptr != NULL){
        *value = (*ptr)->value;

        tmp = *ptr;
        *ptr = (*ptr)->next;
        free(tmp);

        return true;
    } else return false;
}

boolean removeTail(struct unidirectionalLinkedList **ptr, float *value) {

    if(ptr != NULL){

        struct unidirectionalLinkedList *previous, *position;
        position = *ptr;
        while(position->next != NULL) {
            previous = position;
            position = position->next;
        }

        *value = position->value;
        previous->next = NULL;
        free(position);

        return true;
    } else return false;
}

boolean seekNDestroy(struct unidirectionalLinkedList **ptr, float value) {

    if(ptr != NULL){

        boolean found = false;
        struct unidirectionalLinkedList *previous, *position;
        position = *ptr;
        while(position->next != NULL && !found) {
            if(position->value == value) found = true;
            else {
                previous = position;
                position = position->next;
            }
        }

        if(found){
            previous->next = position->next;
            free(position);
        }

        return found;
    } else return false;

}

void visit(struct unidirectionalLinkedList *ptr) {

    while(ptr != NULL){
        printf("Valore: %f", ptr->value);
        ptr = ptr->next;
    }

}

boolean search(struct unidirectionalLinkedList *ptr, float value, struct unidirectionalLinkedList **target) {

    boolean found = false;
    while(ptr != NULL && !found){
        if (ptr->value == value) {
            found = true;
            *target = ptr;
        } else ptr = ptr->next;
    }
    return found;
}