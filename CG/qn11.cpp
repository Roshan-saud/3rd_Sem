// Write a C program for 2D scaling of a triangle.

#include <graphics.h>
#include <stdio.h>

// Function to apply scaling transformation
void scalePoint(int x, int y, float Sx, float Sy, int *x_new, int *y_new) {
    *x_new = x * Sx;
    *y_new = y * Sy;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    int x1, y1, x2, y2, x3, y3;  // Original coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new; // Scaled coordinates
    float Sx, Sy;  // Scaling factors

    // Taking user input for triangle vertices
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%d %d", &x3, &y3);
    
    // Taking user input for scaling factors
    printf("Enter the scaling factors (Sx Sy): ");
    scanf("%f %f", &Sx, &Sy);

    // Apply scaling transformation to each vertex
    scalePoint(x1, y1, Sx, Sy, &x1_new, &y1_new);
    scalePoint(x2, y2, Sx, Sy, &x2_new, &y2_new);
    scalePoint(x3, y3, Sx, Sy, &x3_new, &y3_new);

    // Move origin to screen center for better visualization
    int xs = getmaxx() / 2;
    int ys = getmaxy() / 2;

    // Draw original triangle in white
    setcolor(WHITE);
    line(x1 + xs, ys - y1, x2 + xs, ys - y2);
    line(x2 + xs, ys - y2, x3 + xs, ys - y3);
    line(x3 + xs, ys - y3, x1 + xs, ys - y1);

    // Draw scaled triangle in red
    setcolor(RED);
    line(x1_new + xs, ys - y1_new, x2_new + xs, ys - y2_new);
    line(x2_new + xs, ys - y2_new, x3_new + xs, ys - y3_new);
    line(x3_new + xs, ys - y3_new, x1_new + xs, ys - y1_new);

    // Display result
    printf("\nOriginal Triangle (White) and Scaled Triangle (Red) displayed.");
    
    getch(); // Wait for user keypress
    closegraph(); // Close graphics window

    return 0;
}
