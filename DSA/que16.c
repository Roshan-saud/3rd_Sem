//  //Quadratic hashing
// #include <stdio.h>
// #define TABLE_SIZE 10

// int hashTable[TABLE_SIZE]; // Hash table

// // Hash function
// int hash(int key)
// {
//     return key % TABLE_SIZE;
// }

// // Quadratic probing function to insert a key
// void insert(int key)
// {
//     int index = hash(key);
//     int i = 0;
//     while (hashTable[(index + i * i) % TABLE_SIZE] != -1)
//     {
//         i++;
//         if (i == TABLE_SIZE)
//         {
//             printf("Hash table is full, cannot insert %d\n", key);
//             return;
//         }
//     }
//     hashTable[(index + i * i) % TABLE_SIZE] = key;
//     printf("Inserted %d at index %d\n", key, (index + i * i) % TABLE_SIZE);
// }

// int main()
// {
//     for (int i = 0; i < TABLE_SIZE; i++)
//     {
//         hashTable[i] = -1; // Initialize hash table with -1 (indicating empty slots)
//     }

//     int n, key;
//     printf("Enter the number of elements to insert: ");
//     scanf("%d", &n);
//     printf("Enter the elements:\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &key);
//         insert(key);
//     }
//     printf("Your table is: ");
//     for (int i = 0; i < TABLE_SIZE; i++)
//     {
//         if(hashTable[i] == -1)
//             printf("a[%d]:'empty', ",i);
//         else
//         printf("a[%d]: %d, ",i, hashTable[i]);
//     }
//     return 0;
// }

//Double hashing
#include <stdio.h>
#define TABLE_SIZE 10
int hashTable[TABLE_SIZE]; // Hash table
int hash1(int key)
{
    return key % TABLE_SIZE;
}
int hash2(int key)
{
    return (7 - (key % 7)); // Using a prime number smaller than TABLE_SIZE
}

void insert(int key)
{
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;

    while (hashTable[(index + i * step) % TABLE_SIZE] != -1)
    {
        i++;
        if (i == TABLE_SIZE)
        {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }
    hashTable[(index + i * step) % TABLE_SIZE] = key;
    printf("Inserted %d at index %d\n", key, (index + i * step) % TABLE_SIZE);
}

int main()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1; // Initialize hash table with -1 (indicating empty slots)
    }

    int n, key;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter the elementss:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }
printf("Your table is: ");
for (int i = 0; i < TABLE_SIZE; i++)
{
    if(hashTable[i] == -1)
        printf("a[%d]:'empty ', ",i);
    else
    printf("a[%d]: %d, ",i, hashTable[i]);
}
return 0;
}