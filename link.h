//
// Created by jeana on 20/09/2021.
//
#include "Point2D.h"
#ifndef LISTECHAINEE_LINK_H
#define LISTECHAINEE_LINK_H

typedef struct Link {
    Point2D *data;
    struct Link* next;
} Link;

void addLink (const Link *list, const Link *linkToAdd);
Link* createLinkByPoint2D (const Point2D *point2DToAdd);
void showList (const Link *list);
void showListRecursive (const Link *list);
void showListRecursiveInverse (const Link *list);
void deleteLink(const Link *list, const Link *linkToDelete);
Link* getLinkByRank(const Link *list, int rank);
void insertLinkByRank(const Link *list, int rank, Link *LinkToAdd);
#endif //LISTECHAINEE_LINK_H
