// Write a C program to implement 2D shearing.  


#include <graphics.h>
#include <stdio.h>

// Function to apply X-shear transformation
void shearX(int x, int y, float Shx, int *x_new, int *y_new) {
    *x_new = x + Shx * y; // Shearing in X
    *y_new = y;
}

// Function to apply Y-shear transformation
void shearY(int x, int y, float Shy, int *x_new, int *y_new) {
    *x_new = x;
    *y_new = y + Shy * x; // Shearing in Y
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Initialize graphics mode

    int x1, y1, x2, y2, x3, y3;  // Original coordinates
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new; // Sheared coordinates
    float Shx = 0, Shy = 0;  // Shear factors

    // Taking user input for triangle vertices
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Taking user input for shearing type and factors
    int choice;
    printf("\nChoose Shearing Type:\n1. Shear in X-Direction\n2. Shear in Y-Direction\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Shear Factor for X-Direction (Shx): ");
        scanf("%f", &Shx);
        
        // Apply X-shear transformation
        shearX(x1, y1, Shx, &x1_new, &y1_new);
        shearX(x2, y2, Shx, &x2_new, &y2_new);
        shearX(x3, y3, Shx, &x3_new, &y3_new);
    } else if (choice == 2) {
        printf("Enter Shear Factor for Y-Direction (Shy): ");
        scanf("%f", &Shy);
        
        // Apply Y-shear transformation
        shearY(x1, y1, Shy, &x1_new, &y1_new);
        shearY(x2, y2, Shy, &x2_new, &y2_new);
        shearY(x3, y3, Shy, &x3_new, &y3_new);
    } else {
        printf("Invalid choice!");
        closegraph();
        return 0;
    }

    // Move origin to screen center for better visualization
    int xs = getmaxx() / 2;
    int ys = getmaxy() / 2;

    // Draw original triangle in white
    setcolor(WHITE);
    line(x1 + xs, ys - y1, x2 + xs, ys - y2);
    line(x2 + xs, ys - y2, x3 + xs, ys - y3);
    line(x3 + xs, ys - y3, x1 + xs, ys - y1);

    // Draw sheared triangle in red
    setcolor(RED);
    line(x1_new + xs, ys - y1_new, x2_new + xs, ys - y2_new);
    line(x2_new + xs, ys - y2_new, x3_new + xs, ys - y3_new);
    line(x3_new + xs, ys - y3_new, x1_new + xs, ys - y1_new);

    // Display result
    printf("\nOriginal Triangle (White) and Sheared Triangle (Red) displayed.");
    
    getch(); // Wait for user keypress
    closegraph(); // Close graphics window

    return 0;
}
