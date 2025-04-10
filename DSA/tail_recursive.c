#include <stdio.h>

// Tail-recursive function to print from n to 0
void Desc(int n) {
    if (n < 0)
    return;
    printf("%d ", n);
    Desc(n - 1);  // Tail-recursive call
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Numbers in decreasing order:\n");
    Desc(n);
}