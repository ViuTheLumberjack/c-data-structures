//
// Created by silvi on 28/12/2020.
//

#ifndef DATA_STRUCTURES_INDEXLINKEDLIST_H
#define DATA_STRUCTURES_INDEXLINKEDLIST_H

#define true 1
#define false 0

typedef int boolean;

struct record{
    float item;
    int next;
};

struct indexLinkedList{
    int first;
    int free;
    int size;
    struct record* buffer;
};

/**
 * Inizializza la lista
 * @param ptr
 * @param size
 */
void init(struct indexLinkedList* ptr, int size);

/**
 * Inserimento in testa
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean preInsert(struct indexLinkedList* ptr, float value);

/**
 * Inserimento in coda
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean suffInsert(struct indexLinkedList* ptr, float value);

/**
 * Inserimento degli elementi in ordine crescente
 * N.B Anche la lista deve essere ordinata inizialmente
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean ordInsert(struct indexLinkedList* ptr, float value);

/**
 * Cancella L'elemento in testa alla lista
 * @param ptr
 * @return esito dell'operazione
 */
boolean removeHead(struct indexLinkedList* ptr);

/**
 * Cancella L'elemento in testa alla lista
 * @param ptr
 * @return esito dell'operazione
 */
boolean removeTail(struct indexLinkedList* ptr);

/**
 * Rimuove dalla lista l'elemento value
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean seekNDestroy(struct indexLinkedList* ptr, float value);

/**
 * Stampa i valori della lista
 * @param ptr
 */
void visit(struct indexLinkedList* ptr);

/**
 * Cerca un valore nella lista
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean search(struct indexLinkedList* ptr, float value);

#endif //DATA_STRUCTURES_INDEXLINKEDLIST_H
