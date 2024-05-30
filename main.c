#include <stdio.h>
#include <stdlib.h>

// Function to find the best partition for each book to ensure balanced load
void partitionBooks(int books[], int n) {
    int i,s;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // Arrays to store partition indices
    int partition1[n], partition2[n], partition3[n];
    int p1 = 0, p2 = 0, p3 = 0;

    // Iterate through all books
    for (i = 0; i < n; i++) {
        // Check which partition to put the book into
        if (sum1 <= sum2 && sum1 <= sum3) {
            partition1[p1++] = books[i];
            sum1 += books[i];
        } else if (sum2 <= sum1 && sum2 <= sum3) {
            partition2[p2++] = books[i];
            sum2 += books[i];
        } else {
            partition3[p3++] = books[i];
            sum3 += books[i];
        }
    }

    // Print the partitions
    printf("Partition 1: ");
    for (i = 0; i < p1; i++)
        printf("%d ", partition1[i]);
    printf("\nTotal pages: %d\n", sum1);

    printf("Partition 2: ");
    for (i = 0; i < p2; i++)
        printf("%d ", partition2[i]);
    printf("\nTotal pages: %d\n", sum2);

    printf("Partition 3: ");
    for (i = 0; i < p3; i++)
        printf("%d ", partition3[i]);
    printf("\nTotal pages: %d\n", sum3);
}

int main() {
    // File pointer
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    // Read the number of books
    int n;
    fscanf(file, "%d", &n);

    // Allocate memory for the array of book sizes
    int *books = (int *)malloc(n * sizeof(int));
    if (books == NULL) {
        printf("Error: memory allocation failed\n");
        fclose(file);
        return 1;
    }

    // Read the book sizes from the file
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &books[i]);
    }

    // Close the file
    fclose(file);

    // Function call to partition books
    partitionBooks(books, n);

    // Free allocated memory
    free(books);



    return 0;
}
