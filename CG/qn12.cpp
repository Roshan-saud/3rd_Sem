//Write a C program for 2D reflection of a triangle about x-axis.  

#include <graphics.h>
#include <stdio.h>

// Function to apply reflection about the X-axis
void reflectX(int x, int y, int *x_new, int *y_new) {
    *x_new = x;
    *y_new = -y;  // Reflection inverts Y-coordinate
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " "); // Initialize graphics mode

    int x1, y1, x2, y2, x3, y3;  // Original coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new; // Reflected coordinates

    // Taking user input for triangle vertices
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Apply reflection transformation to each vertex
    reflectX(x1, y1, &x1_new, &y1_new);
    reflectX(x2, y2, &x2_new, &y2_new);
    reflectX(x3, y3, &x3_new, &y3_new);

    // Move origin to screen center for better visualization
    int xs = getmaxx() / 2;
    int ys = getmaxy() / 2;

    // Draw original triangle in white
    setcolor(WHITE);
    line(x1 + xs, ys - y1, x2 + xs, ys - y2);
    line(x2 + xs, ys - y2, x3 + xs, ys - y3);
    line(x3 + xs, ys - y3, x1 + xs, ys );
    // Draw reflected triangle in red
    setcolor(RED);
    line(x1_new + xs, ys - y1_new, x2_new + xs, ys - y2_new);
    line(x2_new + xs, ys - y2_new, x3_new + xs, ys - y3_new);
    line(x3_new + xs, ys - y3_new, x1_new + xs, ys - y1_new);

    // Display result
    printf("\nOriginal Triangle (White) and Reflected Triangle (Red) displayed.");
    
    getch(); // Wait for user keypress
    closegraph(); // Close graphics window

    return 0;
}

