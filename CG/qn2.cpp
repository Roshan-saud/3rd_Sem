// . Write a C program for DDA Line Drawing Algorithm.  

#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

void ddaLine(int x1, int y1, int x2, int y2) {
    // Calculate the difference in x and y
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate increment in x and y for each step
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    // Start from the first point
    float x = x1;
    float y = y1;

    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Draw pixel
        x += xIncrement; // Increment x
        y += yIncrement; // Increment y
    }
}

int main() {
    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) ""); // Adjust the path as necessary

    // Define the start and end points of the line
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Call the DDA line drawing function
    ddaLine(x1, y1, x2, y2);

    // Wait for a key press
    getch();

    // Close the graphics system
    closegraph();
    return 0;
}
