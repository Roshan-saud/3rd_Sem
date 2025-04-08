

#include <stdio.h>

#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4  // 0100
#define TOP 8     // 1000

// Define the clipping window boundaries
#define XMIN 50
#define YMIN 50
#define XMAX 200
#define YMAX 200

// Function to compute the region code for a point (x, y)
int computeRegionCode(float x, float y) {
    int code = INSIDE;

    if (x < XMIN)       // to the left of the clipping window
        code |= LEFT;
    else if (x > XMAX)  // to the right of the clipping window
        code |= RIGHT;

    if (y < YMIN)       // below the clipping window
        code |= BOTTOM;
    else if (y > YMAX)  // above the clipping window
        code |= TOP;

    return code;
}

// Function to perform the Cohen-Sutherland line clipping algorithm
void cohenSutherlandLineClip(float x0, float y0, float x1, float y1) {
    int code0, code1;
    int accept = 0, done = 0;

    code0 = computeRegionCode(x0, y0); // region code for first endpoint
    code1 = computeRegionCode(x1, y1); // region code for second endpoint

    // Loop until the line is either accepted or rejected
    while (!done) {
        // Case 1: Both endpoints are inside the clipping window
        if (code0 == 0 && code1 == 0) {
            accept = 1;
            done = 1;
        }
        // Case 2: Both endpoints are outside the clipping window
        else if (code0 & code1) {
            done = 1;
        }
        // Case 3: One endpoint is outside the clipping window
        else {
            int codeOut;
            float x, y;

            // Determine which endpoint is outside the clipping window
            if (code0 != 0) codeOut = code0;
            else codeOut = code1;

            // Find the intersection point using the clipping window
            if (codeOut & TOP) { // point is above the window
                x = x0 + (x1 - x0) * (YMAX - y0) / (y1 - y0);
                y = YMAX;
            }
            else if (codeOut & BOTTOM) { // point is below the window
                x = x0 + (x1 - x0) * (YMIN - y0) / (y1 - y0);
                y = YMIN;
            }
            else if (codeOut & RIGHT) { // point is to the right of the window
                y = y0 + (y1 - y0) * (XMAX - x0) / (x1 - x0);
                x = XMAX;
            }
            else if (codeOut & LEFT) { // point is to the left of the window
                y = y0 + (y1 - y0) * (XMIN - x0) / (x1 - x0);
                x = XMIN;
            }

            // Update the outside point with the new intersection point
            if (codeOut == code0) {
                x0 = x;
                y0 = y;
                code0 = computeRegionCode(x0, y0);
            }
            else {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            }
        }
    }

    // Display the result
    if (accept) {
        printf("Line accepted: (%.2f, %.2f) to (%.2f, %.2f)\n", x0, y0, x1, y1);
    }
    else {
        printf("Line rejected\n");
    }
}

int main() {
    float x0, y0, x1, y1;

    // Define the clipping window
    printf("Clipping Window: Xmin = %d, Ymin = %d, Xmax = %d, Ymax = %d\n", XMIN, YMIN, XMAX, YMAX);

    // Get the line coordinates from the user
    printf("Enter the coordinates of the line (x0, y0, x1, y1): ");
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);

    // Perform Cohen-Sutherland Line Clipping
    cohenSutherlandLineClip(x0, y0, x1, y1);

    return 0;
}
