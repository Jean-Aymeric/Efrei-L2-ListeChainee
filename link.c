//
// Created by jeana on 20/09/2021.
//
#include "link.h"
#include <stdio.h>
#include <stdlib.h>

Link* goToEndRecursive (Link* list);
Link* goToEnd (Link* list);

void addLink (const Link *list, const Link *linkToAdd) {
    if (list != NULL){
        Link* last = goToEndRecursive(list);
        last->next = linkToAdd;
    }
};

Link* createLinkByPoint2D (const Point2D *point2DToAdd) {
    Link* link = malloc(sizeof (Link));
    if (link != NULL){
        link->data = point2DToAdd;
        link->next = NULL;
    }
    return link;
};

void showList (const Link *list) {
    if (list != NULL){
        Link* temp = list;
        do {
            printf("%f %f\n", temp->data->x, temp->data->y);
            temp = temp->next;
        }while (temp != NULL);
    }
};

void showListRecursive (const Link *list){
    if (list != NULL){
        printf("%f %f\n", list->data->x, list->data->y);
        showListRecursive(list->next);
    }
}

void showListRecursiveInverse (const Link *list){
    if (list != NULL){
        showListRecursive(list->next);
        printf("%f %f\n", list->data->x, list->data->y);
    }
}

Link* goToEndRecursive (Link* list) {
    if (list == NULL){
        return NULL;
    }
    if (list->next == NULL){
        return list;
    }

    return goToEndRecursive(list->next);
};

Link* goToEnd (Link* list){
    if (list == NULL){
        return NULL;
    }
    Link* temp = list;
    while (temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

void deleteLink(const Link *list, const Link *linkToDelete){
    if (list != NULL){
        Link* temp = list;
        while((temp->next != linkToDelete) && (temp->next != NULL)){
            temp = temp->next;
        }
        if ((temp->next != NULL) && (linkToDelete != NULL)){
            temp->next = linkToDelete->next;
            free(linkToDelete->data);
            free(linkToDelete);
        }
    }
}

Link* getLinkByRank(const Link *list, int rank){
    if (list == NULL){
        return NULL;
    }
    Link* temp = list;
    for (int i=0;(i<rank)&&(temp != NULL);i++){
        temp = temp->next;
    }
    return temp;
}

void insertLinkByRank(const Link *list, int rank, Link *linkToAdd){
    if (list != NULL) {
        Link *temp = list;
        for (int i=0;(i<rank-1)&&(temp != NULL);i++){
            temp = temp->next;
        }
        if (temp != NULL){
            goToEndRecursive(linkToAdd)->next = temp->next;
            temp->next = linkToAdd;
        }
    }
}