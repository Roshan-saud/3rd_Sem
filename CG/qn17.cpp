

#include <stdio.h>

// Function to apply 3D shearing transformation
void shear_3d(float *x, float *y, float *z, float Sh_xy, float Sh_xz, float Sh_yx, float Sh_yz, float Sh_zx, float Sh_zy) {
    // Applying shear transformations based on the shear matrix
    float new_x = *x + Sh_xy * *y + Sh_xz * *z;
    float new_y = Sh_yx * *x + *y + Sh_yz * *z;
    float new_z = Sh_zx * *x + Sh_zy * *y + *z;

    // Updating the original coordinates with the new sheared coordinates
    *x = new_x;
    *y = new_y;
    *z = new_z;
}

int main() {
    float x, y, z;
    float Sh_xy, Sh_xz, Sh_yx, Sh_yz, Sh_zx, Sh_zy;

    // Get input from the user
    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%f %f %f", &x, &y, &z);
    printf("Enter the shear factors (Sh_xy, Sh_xz, Sh_yx, Sh_yz, Sh_zx, Sh_zy): ");
    scanf("%f %f %f %f %f %f", &Sh_xy, &Sh_xz, &Sh_yx, &Sh_yz, &Sh_zx, &Sh_zy);

    // Apply the shear transformation
    shear_3d(&x, &y, &z, Sh_xy, Sh_xz, Sh_yx, Sh_yz, Sh_zx, Sh_zy);

    // Output the new coordinates after shearing
    printf("The new coordinates after shearing are: (%.2f, %.2f, %.2f)\n", x, y, z);

    return 0;
}
