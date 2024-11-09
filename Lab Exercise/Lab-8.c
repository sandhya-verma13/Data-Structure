
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct User {
    char username[50];
    struct User* next;
} User;

User* hashTable[TABLE_SIZE];

unsigned int hash(const char* username) {
    unsigned int hashValue = 0;
    while (*username) {
        hashValue = (hashValue << 5) + *username++;
    }
    return hashValue % TABLE_SIZE;
}

void insertUser(const char* username) {
    unsigned int index = hash(username);
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->username, username);
    newUser->next = hashTable[index];
    hashTable[index] = newUser;
}

int userExists(const char* username) {
    unsigned int index = hash(username);
    User* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

void freeMemory() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        User* current = hashTable[i];
        while (current != NULL) {
            User* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    char username[50];
    char choice;

    do {
        printf("Enter a username to register: ");
        scanf("%s", username);

        if (userExists(username)) {
            printf("Username '%s' already exists!\n", username);
        } else {
            insertUser(username);
            printf("Username '%s' registered successfully!\n", username);
        }

        printf("Do you want to register another username? (y/n): ");
        scanf(" %c", &choice);  

    } while (choice == 'y' || choice == 'Y');

    
    freeMemory();

    return 0;
}


