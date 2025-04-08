// Write a C program to implement 3D scaling.

#include <stdio.h>

// Function to scale a point (x, y, z) by scaling factors Sx, Sy, Sz
void scale_3d(float *x, float *y, float *z, float Sx, float Sy, float Sz) {
    *x = *x * Sx;
    *y = *y * Sy;
    *z = *z * Sz;
}

int main() {
    float x, y, z;
    float Sx, Sy, Sz;

    // Get input from the user
    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%f %f %f", &x, &y, &z);
    printf("Enter the scaling factors (Sx, Sy, Sz): ");
    scanf("%f %f %f", &Sx, &Sy, &Sz);

    // Apply the scaling transformation
    scale_3d(&x, &y, &z, Sx, Sy, Sz);

    // Output the new coordinates after scaling
    printf("The new coordinates after scaling are: (%.2f, %.2f, %.2f)\n", x, y, z);

    return 0;
}
