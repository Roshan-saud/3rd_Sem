// Write a C program to implement Polygon Clipping (Sutherland Hodgeman polygon clipping)

#include <stdio.h>

#define XMIN 50
#define YMIN 50
#define XMAX 200
#define YMAX 200

// Structure to represent a 2D point
typedef struct {
    float x;
    float y;
} P;

// Function to check if a point is inside the clipping window
int isInside(P p) {
    return (p.x >= XMIN && p.x <= XMAX && p.y >= YMIN && p.y <= YMAX);
}

// Function to compute the intersection of two line segments
P cI(P p1, P p2, P p3, P p4) {
    P intersection;
    float denom = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
    if (denom != 0) {
        float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / denom;
        intersection.x = p1.x + t * (p2.x - p1.x);
        intersection.y = p1.y + t * (p2.y - p1.y);
    }
    return intersection;
}

// Function to clip the polygon against a single edge
int clipEdge(P *polygon, int *n, P edgeStart, P edgeEnd) {
    P newPolygon[100];
    int newPsize = 0;

    for (int i = 0; i < *n; i++) {
        int j = (i + 1) % *n;
        P current = polygon[i];
        P next = polygon[j];

        if (isInside(current) && isInside(next)) {
            newPolygon[newPsize++] = next;
        }
        else if (isInside(current) && !isInside(next)) {
            newPolygon[newPsize++] = cI(current, next, edgeStart, edgeEnd);
        }
        else if (!isInside(current) && isInside(next)) {
            newPolygon[newPsize++] = cI(current, next, edgeStart, edgeEnd);
            newPolygon[newPsize++] = next;
        }
    }

    for (int i = 0; i < newPsize; i++) {
        polygon[i] = newPolygon[i];
    }
    *n = newPsize;

    return newPsize > 0;
}

// Function to perform Sutherland-Hodgman polygon clipping
void sutherlandHodgman(P *polygon, int *n) {
    P edges[4][2] = {
        { {XMIN, YMIN}, {XMIN, YMAX} }, // Left edge
        { {XMAX, YMIN}, {XMAX, YMAX} }, // Right edge
        { {XMIN, YMIN}, {XMAX, YMIN} }, // Bottom edge
        { {XMIN, YMAX}, {XMAX, YMAX} }  // Top edge
    };

    for (int i = 0; i < 4; i++) {
        if (!clipEdge(polygon, n, edges[i][0], edges[i][1])) {
            printf("Polygon rejected: It is outside the clipping window.\n");
            return;
        }
    }

    printf("Clipped Polygon:\n");
    for (int i = 0; i < *n; i++) {
        printf("(%.2f, %.2f)\n", polygon[i].x, polygon[i].y);
    }
}

int main() {
    int n;
    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &n);

    P polygon[n];
    printf("Enter the vertices of the polygon (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &polygon[i].x, &polygon[i].y);
    }

    sutherlandHodgman(polygon, &n);

    return 0;
}
