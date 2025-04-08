// Write a C program to implement 2D rotation of a triangle.
#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function to rotate a point around the origin
void rotatePoint(int x, int y, float angle, int *x_new, int *y_new) {
    float radian = angle * (PI / 180.0);  // Convert degrees to radians
    *x_new = round(x * cos(radian) - y * sin(radian));
    *y_new = round(x * sin(radian) + y * cos(radian));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)""); // Initialize graphics

    int x1, y1, x2, y2, x3, y3;  // Original coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new; // Rotated coordinates
    float angle;

    // Taking user input for triangle vertices
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%d %d", &x3, &y3);
    
    // Taking user input for rotation angle
    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);

    // Applying rotation formula to each vertex
    rotatePoint(x1, y1, angle, &x1_new, &y1_new);
    rotatePoint(x2, y2, angle, &x2_new, &y2_new);
    rotatePoint(x3, y3, angle, &x3_new, &y3_new);

    // Move origin to screen center for better visualization
    int xs = getmaxx() / 2;
    int ys = getmaxy() / 2;

    // Draw original triangle in white
    setcolor(WHITE);
    line(x1 + xs, ys - y1, x2 + xs, ys - y2);
    line(x2 + xs, ys - y2, x3 + xs, ys - y3);
    line(x3 + xs, ys - y3, x1 + xs, ys - y1);

    // Draw rotated triangle in red
    setcolor(RED);
    line(x1_new + xs, ys - y1_new, x2_new + xs, ys - y2_new);
    line(x2_new + xs, ys - y2_new, x3_new + xs, ys - y3_new);
    line(x3_new + xs, ys - y3_new, x1_new + xs, ys - y1_new);

    // Display result
    printf("\nOriginal Triangle (White) and Rotated Triangle (Red) displayed.");
    
    getch(); // Wait for user keypress
    closegraph(); // Close graphics window

    return 0;
}
