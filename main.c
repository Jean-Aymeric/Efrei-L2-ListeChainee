
#include "Point2D.h"
#include "link.h"
#include <stdio.h>

int main() {
    Point2D a;
    a.x = 3;
    a.y = 4;
    Link* list = createLinkByPoint2D(&a);
    Point2D b;
    b.x = 5;
    b.y = 7;
    for (int i = 0; i < 2; i++) {
        addLink (list, createLinkByPoint2D(&b));
        addLink (list, createLinkByPoint2D(&a));
    }
    showList(list);
    printf("\n");
    deleteLink(list,getLinkByRank(list,1));
    showList(list);

    return 0;
}
