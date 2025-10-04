#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumni {
    int id;
    char name[50];
    char department[50];
    int year;
    char occupation[50];
    struct Alumni* next;
};

struct Alumni* head = NULL;

static void chomp(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[n-1] = '\0';
        n--;
    }
}

struct Alumni* createNode(int id, const char name[], const char dept[], int year, const char occupation[]) {
    struct Alumni* newNode = (struct Alumni*)malloc(sizeof(struct Alumni));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->id = id;
    strncpy(newNode->name, name, sizeof(newNode->name)-1);
    newNode->name[sizeof(newNode->name)-1] = '\0';
    strncpy(newNode->department, dept, sizeof(newNode->department)-1);
    newNode->department[sizeof(newNode->department)-1] = '\0';
    newNode->year = year;
    strncpy(newNode->occupation, occupation, sizeof(newNode->occupation)-1);
    newNode->occupation[sizeof(newNode->occupation)-1] = '\0';
    newNode->next = NULL;
    return newNode;
}

void insertAlumni() {
    char buf[128];
    char name[50], dept[50], occupation[50];
    int id, year;

    printf("Enter ID: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    id = atoi(buf);

    printf("Enter Name: ");
    if (!fgets(name, sizeof(name), stdin)) return;
    chomp(name);

    printf("Enter Department: ");
    if (!fgets(dept, sizeof(dept), stdin)) return;
    chomp(dept);

    printf("Enter Year: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    year = atoi(buf);

    printf("Enter Occupation: ");
    if (!fgets(occupation, sizeof(occupation), stdin)) return;
    chomp(occupation);

    struct Alumni* newNode = createNode(id, name, dept, year, occupation);
    newNode->next = head;
    head = newNode;

    printf("Alumni added successfully!\n");
}

void searchById() {
    char buf[64];
    int id;
    printf("Enter Alumni ID to search: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    id = atoi(buf);

    struct Alumni* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("%d | %s | %s | %d | %s\n",
                   temp->id, temp->name, temp->department, temp->year, temp->occupation);
            return;
        }
        temp = temp->next;
    }
    printf("Alumni not found\n");
}

void display() {
    struct Alumni* temp = head;
    if (temp == NULL) {
        printf("No records\n");
        return;
    }
    printf("\nAll Alumni Records:\n");
    while (temp != NULL) {
        printf("%d | %s | %s | %d | %s\n",
    temp->id, temp->name, temp->department, temp->year, temp->occupation);
        temp = temp->next;
    }
}

int main() {
    char buf[32];
    int choice = -1;

    while (1) {
        printf("\n1. Insert Alumni\n2. Search by ID\n3. Display All\n4. Exit\nChoice: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        choice = atoi(buf);

        switch (choice) {
            case 1: insertAlumni(); break;
            case 2: searchById(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
