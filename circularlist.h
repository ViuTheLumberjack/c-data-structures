#ifndef DATA_STRUCTURES_CIRCULARLIST_H
#define DATA_STRUCTURES_CIRCULARLIST_H
#define true 1
#define false 0

typedef int boolean;


struct circularList{
    float* buffer;
    int size;
    int head;
    int tail;
};

/**
 * Inizializza la lista
 * @param ptr
 * @param size
 */
void init(struct circularList* ptr, int size);

/**
 * Inserimento in coda
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean suffInsert(struct circularList* ptr, float value);

/**
 * Inserimento in testa
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean preInsert(struct circularList* ptr, float value);

/**
 * Inserimento degli elementi in ordine crescente
 * N.B Anche la lista deve essere ordinata inizialmente
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean ordInsert(struct circularList* ptr, float value);

/**
 * Cancella L'elemento in testa alla lista
 * @param ptr
 * @return esito dell'operazione
 */
boolean removeHead(struct circularList* ptr);

/**
 * Cancella L'elemento in testa alla lista
 * @param ptr
 * @return esito dell'operazione
 */
boolean removeTail(struct circularList* ptr);

/**
 * Rimuove dalla lista l'elemento value
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean seekNDestroy(struct circularList* ptr, float value);

/**
 * Stampa i valori della lista
 * @param ptr
 */
void visit(struct circularList* ptr);

/**
 * Cerca un valore nella lista
 * @param ptr
 * @param value
 * @return esito dell'operazione
 */
boolean search(struct circularList* ptr, float value);

#endif //DATA_STRUCTURES_CIRCULARLIST_H
