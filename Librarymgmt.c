#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char name[50];
    char author[50];
    int quantity;
};

struct Book library[MAX];
int count = 0;

// Safe integer input
int getInt() {
    char input[50];
    int value;

    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &value) != 1) {
        return -1; // invalid
    }
    return value;
}

// Safe string input
void getString(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline
}

// Display Books
void displayBooks() {
    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d", library[i].id);
        printf("\nName: %s", library[i].name);
        printf("\nAuthor: %s", library[i].author);
        printf("\nQuantity: %d\n", library[i].quantity);
    }
}

// Add Book
void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", library[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[count].author);

    printf("Enter Quantity: ");
    scanf("%d", &library[count].quantity);

    count++;
    printf("Book added successfully!\n");
}

// Search Book
void searchBook() {
    int id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!");
            printf("\nName: %s", library[i].name);
            printf("\nAuthor: %s", library[i].author);
            printf("\nQuantity: %d\n", library[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Issue Book
void issueBook() {
    int id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].quantity > 0) {
                library[i].quantity--;
                printf("Book issued successfully!\n");
            } else {
                printf("Book out of stock!\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

// Return Book
void returnBook() {
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            library[i].quantity++;
            printf("Book returned successfully!\n");
            return;
        }
    }

    printf("Book not found.\n");
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Library Menu ---\n1. Display Book\n2. Add Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayBooks(); break;
            case 2: addBook(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n"); break;
        }
    }

    return 0;
}