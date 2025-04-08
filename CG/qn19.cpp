// Write a C program to implement Liang-Barsky Line Clipping. 

#include <stdio.h>

#define XMIN 50
#define YMIN 50
#define XMAX 200
#define YMAX 200

// Function to implement Liang-Barsky Line Clipping
void liangBarskyLineClip(float x0, float y0, float x1, float y1) {
    float p[4], q[4];
    float dx = x1 - x0, dy = y1 - y0;

    // Parameters for the 4 boundaries: left, right, bottom, top
    p[0] = -dx;  q[0] = x0 - XMIN; // Left boundary
    p[1] = dx;   q[1] = XMAX - x0; // Right boundary
    p[2] = -dy;  q[2] = y0 - YMIN; // Bottom boundary
    p[3] = dy;   q[3] = YMAX - y0; // Top boundary

    float tmin = 0.0, tmax = 1.0;

    // Loop through the 4 boundaries
    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) { // Line is parallel to boundary
            if (q[i] < 0) {
                printf("Line rejected\n");
                return;  // Line is outside the clipping window
            }
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) { // Moving towards the boundary
                if (t > tmax)
                    return;  // Line is outside the clipping window
                if (t > tmin)
                    tmin = t; // Update tmin
            } else { // Moving away from the boundary
                if (t < tmin)
                    return;  // Line is outside the clipping window
                if (t < tmax)
                    tmax = t; // Update tmax
            }
        }
    }

    // Calculate the clipped coordinates
    float x_clipped0 = x0 + tmin * dx;
    float y_clipped0 = y0 + tmin * dy;
    float x_clipped1 = x0 + tmax * dx;
    float y_clipped1 = y0 + tmax * dy;

    // Output the clipped line segment
    printf("Line accepted: (%.2f, %.2f) to (%.2f, %.2f)\n", x_clipped0, y_clipped0, x_clipped1, y_clipped1);
}

int main() {
    float x0, y0, x1, y1;

    // Define the clipping window
    printf("Clipping Window: Xmin = %d, Ymin = %d, Xmax = %d, Ymax = %d\n", XMIN, YMIN, XMAX, YMAX);

    // Get the line coordinates from the user
    printf("Enter the coordinates of the line (x0, y0, x1, y1): ");
    scanf("%f %f %f %f", &x0, &y0, &x1, &y1);

    // Perform Liang-Barsky Line Clipping
    liangBarskyLineClip(x0, y0, x1, y1);

    return 0;
}





