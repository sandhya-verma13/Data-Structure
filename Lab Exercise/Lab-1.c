#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
};

struct Node {
    struct Book book;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(struct Book book) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->book = book;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addBook(struct Book book) {
    struct Node* newNode = createNode(book);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void removeBook(char title[]) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->book.title, title) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            free(current);
            printf("Book %s removed.\n", title);
            return;
        }
        current = current->next;
    }
    printf("Book %s not found.\n", title);
}

void displayBookForward() {
    struct Node* current = head;
    while (current != NULL) {
        printf("Title : %s, Author : %s\n", current->book.title, current->book.author);
        current = current->next;
    }
}

void displayBookReverse() {
    struct Node* current = tail;
    while (current != NULL) {
        printf("Title : %s, Author : %s\n", current->book.title, current->book.author);
        current = current->prev;
    }
}

struct Book readBookDetails() {
    struct Book book;
    printf("Enter book title: ");
    scanf("%99s", book.title);
    printf("Enter author Name: ");
    scanf("%99s", book.author);
    return book;
}

int main() {
    int choice;
    struct Book book;
    do {
        printf("\nMenu:\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. Display books in forward order\n");
        printf("4. Display books in reverse order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                book = readBookDetails();
                addBook(book);
                break;
            case 2:
                printf("Enter book title to remove: ");
                scanf("%99s", book.title);
                removeBook(book.title);
                break;
            case 3:
                displayBookForward();
                break;
            case 4:
                displayBookReverse();
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}



