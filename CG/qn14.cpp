// Write a C program to implement 3D translation.

#include <stdio.h>

// Function to perform 3D translation
void translate3D(float *x, float *y, float *z, float tx, float ty, float tz) {
    *x += tx;
    *y += ty;
    *z += tz;
}

int main() {
    float x, y, z;      // Original coordinates
    float tx, ty, tz;   // Translation factors
    
    // Input original coordinates
    printf("Enter the coordinates of the point (x y z): ");
    scanf("%f %f %f", &x, &y, &z);
    
    // Input translation factors
    printf("Enter the translation factors (tx ty tz): ");
    scanf("%f %f %f", &tx, &ty, &tz);
    
    // Perform translation
    translate3D(&x, &y, &z, tx, ty, tz);
    
    // Output translated coordinates
    printf("The new coordinates after translation are: (%.2f, %.2f, %.2f)\n", x, y, z);
    
    return 0;
}
