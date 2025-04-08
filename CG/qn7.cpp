// Write a C program for Mid-Point Ellipse Drawing Algorithm. 

#include <stdio.h>
#include <graphics.h>  // This is for using graphics library functions

// Midpoint Ellipse Drawing Algorithm
void midpointEllipse(int xc, int yc, int a, int b)
{
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int d1 = b2 - (a2 * b) + (a2 / 4);
    int dx = 2 * b2 * x;
    int dy = 2 * a2 * y;

    // First region (when slope < 1)
    while (dx < dy)
    {
        // Plot the points in all 4 quadrants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Check if we need to move along the x-axis or y-axis
        if (d1 < 0)
        {
            x++;
            dx = dx + 2 * b2;
            d1 = d1 + dx + b2;
        }
        else
        {
            x++;
            y--;
            dx = dx + 2 * b2;
            dy = dy - 2 * a2;
            d1 = d1 + dx - dy + b2;
        }
    }

    // Second region (when slope > 1)
    int d2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0)
    {
        // Plot the points in all 4 quadrants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Check if we need to move along the x-axis or y-axis
        if (d2 > 0)
        {
            y--;
            dy = dy - 2 * a2;
            d2 = d2 + a2 - dy;
        }
        else
        {
            x++;
            y--;
            dx = dx + 2 * b2;
            dy = dy - 2 * a2;
            d2 = d2 + dx - dy + a2;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, a, b;

    // Initialize graphics mode
    initgraph(&gd, &gm, " ");

    // Taking user input for the ellipse parameters
    printf("Enter the coordinates of the center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the semi-major axis length (a): ");
    scanf("%d", &a);

    printf("Enter the semi-minor axis length (b): ");
    scanf("%d", &b);

    // Call the function to draw the ellipse
    midpointEllipse(xc, yc, a, b);

    // Wait for user to close the graphics window
    getch();
    closegraph();

    return 0;
}