//
// Created by silvi on 29/12/2020.
//

#ifndef DATA_STRUCTURES_UNIDIRECTIONALLINKEDLIST_H
#define DATA_STRUCTURES_UNIDIRECTIONALLINKEDLIST_H

#define true 1
#define false 0

typedef int boolean;

struct unidirectionalLinkedList{
    float value;
    struct unidirectionalLinkedList* next;
};

void init(struct unidirectionalLinkedList** ptr);

/**
 * Inserimento in testa
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
void preInsert(struct unidirectionalLinkedList** ptr, float value);

/**
 * Inserimento in coda
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
void suffInsert(struct unidirectionalLinkedList **ptr, float value);

/**
 * Inserimento degli elementi in ordine crescente
 * N.B Anche la lista deve essere ordinata inizialmente
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
void ordInsert(struct unidirectionalLinkedList **ptr, float value);

/**
 * Cancella L'elemento in testa alla lista
 * @param ptr
 * @return esito dell'operazione
 */
boolean removeHead(struct unidirectionalLinkedList **ptr, float *value);

/**
 * Cancella L'elemento in testa alla lista
 * @param ptr
 * @return esito dell'operazione
 */
boolean removeTail(struct unidirectionalLinkedList **ptr, float *value);

/**
 * Rimuove dalla lista l'elemento value
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean seekNDestroy(struct unidirectionalLinkedList **ptr, float value);

/**
 * Stampa i valori della lista
 * @param ptr
 */
void visit(struct unidirectionalLinkedList* ptr);

/**
 * Cerca un valore nella lista
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean search(struct unidirectionalLinkedList *ptr, float value, struct unidirectionalLinkedList **target);

#endif //DATA_STRUCTURES_UNIDIRECTIONALLINKEDLIST_H
