#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640      // Width of the canvas
#define HEIGHT 480     // Height of the canvas

// Structure to represent a pixel
typedef struct {
    int r, g, b;
} Pixel;

// Create a frame buffer
Pixel frameBuffer[WIDTH][HEIGHT];

// Function to initialize the frame buffer
void initFrameBuffer() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            frameBuffer[x][y].r = 255;  // Set default color to white
            frameBuffer[x][y].g = 255;
            frameBuffer[x][y].b = 255;
        }
    }
}

// Function to set a pixel's color in the buffer
void setPixel(int x, int y, int r, int g, int b) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        frameBuffer[x][y].r = r;
        frameBuffer[x][y].g = g;
        frameBuffer[x][y].b = b;
    }
}

// Function to draw a circle by manipulating the buffer
void drawCircle(int xc, int yc, int r, int colorR, int colorG, int colorB) {
    int x = 0, y = r, p = 1 - r;
    while (x <= y) {
        // Plot points in all 8 octants of the circle
        setPixel(xc + x, yc + y, colorR, colorG, colorB);
        setPixel(xc - x, yc + y, colorR, colorG, colorB);
        setPixel(xc + x, yc - y, colorR, colorG, colorB);
        setPixel(xc - x, yc - y, colorR, colorG, colorB);
        setPixel(xc + y, yc + x, colorR, colorG, colorB);
        setPixel(xc - y, yc + x, colorR, colorG, colorB);
        setPixel(xc + y, yc - x, colorR, colorG, colorB);
        setPixel(xc - y, yc - x, colorR, colorG, colorB);

        x++;

        // Update decision parameter
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

// Function to display the buffer on the screen
void displayFrameBuffer() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color = COLOR(frameBuffer[x][y].r, frameBuffer[x][y].g, frameBuffer[x][y].b);
            putpixel(x, y, color);  // Put pixel data from buffer to screen
        }
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, (char*)"");

    // Declare variables for user input
    int xc, yc, r;
    int colorR, colorG, colorB;

    // Get user input for the circle
    printf("Enter the center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    printf("Enter the RGB values for the color (0-255):\n");
    printf("Red (0-255): ");
    scanf("%d", &colorR);
    printf("Green (0-255): ");
    scanf("%d", &colorG);
    printf("Blue (0-255): ");
    scanf("%d", &colorB);

    // Initialize frame buffer
    initFrameBuffer();

    // Draw the circle on the buffer
    drawCircle(xc, yc, r, colorR, colorG, colorB);

    // Display the contents of the frame buffer on the screen
    displayFrameBuffer();

    // Wait for user input before closing
    getch();
    closegraph();

    return 0;
}
