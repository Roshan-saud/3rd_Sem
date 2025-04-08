// Write a C program to implement 3D rotation

#include <stdio.h>
#include <math.h>

// Function to rotate a point (x, y, z) around the X-axis by an angle theta
void rotate_x_axis(float *x, float *y, float *z, float theta) {
    // Convert angle from degrees to radians
    float rad = theta * (M_PI / 180.0);

    // Rotation matrix for rotation about the X-axis
    float new_y = *y * cos(rad) - *z * sin(rad);
    float new_z = *y * sin(rad) + *z * cos(rad);

    // Update the point after rotation
    *y = new_y;
    *z = new_z;
}

int main() {
    float x, y, z, angle;

    // Get input from the user
    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%f %f %f", &x, &y, &z);
    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);

    // Rotate the point around the X-axis
    rotate_x_axis(&x, &y, &z, angle);

    // Output the new coordinates
    printf("The new coordinates after rotation are: (%.2f, %.2f, %.2f)\n", x, y, z);

    return 0;
}
