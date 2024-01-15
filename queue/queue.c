#include "queue.h"
QueueManager *init_queue_manager(){
    QueueManager *queueManager = malloc(sizeof(QueueManager));
    queueManager->first_element = NULL;
    queueManager->last_element = NULL;
    return queueManager;
}

void delete_queue(QueueManager *queueManager, void (*free_data)(void *data)){
    QueueElement *element, *next;
    element = queueManager->first_element;
    while (element != NULL){
        next = element->next;
        free_data(element->data);
        free(element);
        element = next;
    }
    free(queueManager);
}

void add_to_queue_as_last(QueueManager *queueManager, void *data){
    QueueElement *element = malloc(sizeof(QueueElement));
    element->data = data;
    element->next = NULL;
    element->prev = queueManager->last_element;
    if (queueManager->last_element != NULL){
        queueManager->last_element->next = element;
    }
    queueManager->last_element = element;
    if (queueManager->first_element == NULL){
        queueManager->first_element = element;
    }
}

void add_to_queue_as_first(QueueManager *queueManager, void *data){
    QueueElement *element = malloc(sizeof(QueueElement));
    element->data = data;
    element->next = queueManager->first_element;
    element->prev = NULL;
    queueManager->first_element->prev = element;
    queueManager->first_element = element;
    if (queueManager->last_element == NULL){
        queueManager->last_element = element;
    }
}

void print_queue(QueueManager *queueManager, void (*print_data)(void *data)){
    QueueElement *queue = queueManager->first_element;
    while (queue != NULL){
        print_data(queue->data);
        queue = queue->next;
    }
}

SearchResult *search_queue(QueueManager *queueManager, void *search_fraze, int (*compare_data)(void *data, void *search_fraze)){
    QueueElement *queue = queueManager->first_element;
    SearchResult *searchResult = malloc(sizeof(SearchResult));
    searchResult->found = 0;
    searchResult->element = NULL;
    while (queue != NULL){
        if (compare_data(queue->data, search_fraze) == 0){
            searchResult->found = 1;
            searchResult->element = queue;
            break;
        }
        queue = queue->next;
    }
    return searchResult;
}

MultiSearchResult *multi_search_queue(QueueManager *queueManager, void *search_fraze, int (*compare_data)(void *data, void *search_fraze)){
    QueueElement *queue = queueManager->first_element;
    MultiSearchResult *multiSearchResult = malloc(sizeof(MultiSearchResult));
    multiSearchResult->found = 0;
    multiSearchResult->queue_manager = init_queue_manager();
    while (queue != NULL){
        if (compare_data(queue->data, search_fraze) == 0){
            multiSearchResult->found = 1;
            add_to_queue_as_last(multiSearchResult->queue_manager, queue->data);
        }
        queue = queue->next;
    }
    return multiSearchResult;
}

void save_queue(QueueManager *queueManager, char *file_name, void (*save_data)(void *, FILE *)) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL){
        printf("blad otwarcia pliku\n");
        return;
    }
    QueueElement *queue = queueManager->first_element;
    while (queue != NULL){
        save_data(queue->data, file);
        queue = queue->next;
    }
    fclose(file);
}

QueueManager *load_queue(char *file_name, void *(*load_data)(FILE *file)){
    FILE *file = fopen(file_name, "r");
    QueueManager *queueManager = init_queue_manager();
    if (file == NULL){
        printf("blad otwarcia pliku\n");
        return queueManager;
    }
    void *data = load_data(file);
    while (data != NULL && !feof(file)){
        add_to_queue_as_last(queueManager, data);
        data = load_data(file);
        printf("Wczytano dane\n");
    }
    fclose(file);
    return queueManager;
}

void delete_element(QueueManager *queueManager, QueueElement *element, void (*free_data)(void *data)){
    if (element->prev != NULL){
        element->prev->next = element->next;
    }
    if (queueManager->first_element == element){
        queueManager->first_element = element->next;
    }
    if (element->next != NULL){
        element->next->prev = element->prev;
    }
    if (queueManager->last_element == element){
        queueManager->last_element = element->prev;
    }
    free_data(element->data);
    free(element);
}

void delete_first_element(QueueManager *queueManager, void (*free_data)(void *data)){
    if (queueManager->first_element != NULL){
        delete_element(queueManager, queueManager->first_element, free_data);
    }
}

void delete_last_element(QueueManager *queueManager, void (*free_data)(void *data)){
    if (queueManager->last_element != NULL){
        return delete_element(queueManager, queueManager->last_element, free_data);
    }
}

unsigned long int get_next_id(QueueManager *queueManager, unsigned long int (*get_id)(void *data)){
    unsigned long int max_id = 0;
    QueueElement *queue = queueManager->first_element;
    while (queue != NULL){
        unsigned long int id = get_id(queue->data);
        if (id > max_id){
            max_id = id;
        }
        queue = queue->next;
    }
    return ++max_id;
}