#include <graphics.h>
#include <stdio.h>

#define MAX_VERTICES 10

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to draw and fill a polygon using scan line algorithm
void scanLineFill(struct Point polygon[], int n) {
    int i, j, yMin = polygon[0].y, yMax = polygon[0].y;

    // Find the topmost and bottommost y coordinates of the polygon
    for (i = 1; i < n; i++) {
        if (polygon[i].y < yMin) {
            yMin = polygon[i].y;
        }
        if (polygon[i].y > yMax) {
            yMax = polygon[i].y;
        }
    }

    // Process each scan line from yMin to yMax
    for (int y = yMin; y <= yMax; y++) {
        int intersections[MAX_VERTICES], k = 0;

        // Find the intersection points of the polygon with the scan line
        for (i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if (((polygon[i].y <= y) && (polygon[next].y > y)) || 
                ((polygon[i].y > y) && (polygon[next].y <= y))) {
                int x = polygon[i].x + (y - polygon[i].y) * (polygon[next].x - polygon[i].x) / (polygon[next].y - polygon[i].y);
                intersections[k++] = x;
            }
        }

        // Sort intersection points from left to right
        for (i = 0; i < k - 1; i++) {
            for (j = i + 1; j < k; j++) {
                if (intersections[i] > intersections[j]) {
                    int temp = intersections[i];
                    intersections[i] = intersections[j];
                    intersections[j] = temp;
                }
            }
        }

        // Fill the pixels between pairs of intersection points
        for (i = 0; i < k; i += 2) {
            for (int x = intersections[i]; x < intersections[i + 1]; x++) {
                putpixel(x, y, WHITE);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int n;

    // Initialize graphics
    initgraph(&gd, &gm, " ");

    // Input number of vertices and coordinates
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    struct Point polygon[MAX_VERTICES];

    printf("Enter the coordinates of the polygon vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    // Draw the polygon
    for (int i = 0; i < n - 1; i++) {
        line(polygon[i].x, polygon[i].y, polygon[i + 1].x, polygon[i + 1].y);
    }
    line(polygon[n - 1].x, polygon[n - 1].y, polygon[0].x, polygon[0].y);

    // Fill the polygon using scan line algorithm
    scanLineFill(polygon, n);

    getch();
    closegraph();

    return 0;
}

