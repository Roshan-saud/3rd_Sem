

#include <graphics.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform the 2D translation
void translate(int *x, int *y, int dx, int dy) {
    *x = *x + dx;
    *y = *y + dy;
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    int dx, dy;

    // Initialize graphics mode
    initgraph(&gd, &gm, " ");

    // Input the initial coordinates of the triangle
    printf("Enter the coordinates of the triangle's vertices:\n");
    printf("Vertex 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Vertex 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Vertex 3 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the original triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Input the translation values (dx, dy)
    printf("Enter the translation values (dx, dy): ");
    scanf("%d %d", &dx, &dy);

    // Translate the triangle's vertices
    translate(&x1, &y1, dx, dy);
    translate(&x2, &y2, dx, dy);
    translate(&x3, &y3, dx, dy);

    // Draw the translated triangle
    setcolor(RED);
    drawTriangle(x1, y1, x2, y2, x3, y3, RED);

    // Wait for user input to close the graphics window
    getch();
    closegraph();

    return 0;
}
