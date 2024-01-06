#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_QUEUE_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ELEMENT{
    void *data;
    struct ELEMENT *next;
    struct ELEMENT *prev;
} QueueElement;

typedef struct MANAGER{
    QueueElement *first_element;
    QueueElement *last_element;
} QueueManager;

typedef struct SEARCH_RESULT{
    short found;
    QueueElement *element;
} SearchResult;

typedef struct MULTI_SEARCH_RESULT{
    short found;
    QueueManager *queue_manager;
} MultiSearchResult;

QueueManager *init_queue_manager();
void delete_queue(QueueManager *queueManager, void (*free_data)(void *data));
void add_to_queue_as_last(QueueManager *queueManager, void *data);
void add_to_queue_as_first(QueueManager *queueManager, void *data);
void print_queue(QueueManager *queueManager, void (*print_data)(void *data));
SearchResult *search_queue(QueueManager *queueManager, void *search_fraze, int (*compare_data)(void *data, void *search_fraze));
MultiSearchResult *multi_search_queue(QueueManager *queueManager, void *data, int (*compare_data)(void *data, void *search_fraze));
void save_queue(QueueManager *queueManager, char *file_name, void (*save_data)(void *data, FILE *file));
QueueManager *load_queue(char *file_name, void *(*load_data)(FILE *file));
void delete_element(QueueManager *queueManager, QueueElement *element, void (*free_data)(void *data));
void delete_first_element(QueueManager *queueManager, void (*free_data)(void *data));
void delete_last_element(QueueManager *queueManager, void (*free_data)(void *data));
unsigned long int get_next_id(QueueManager *queueManager, unsigned long int (*get_id)(void *data));

#endif //PARADYGMATY_PROGRAMOWANIA_PROJECT_3_QUEUE_H
