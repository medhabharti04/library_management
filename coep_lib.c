#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
struct book {
    char name[50];
    char author[50];
    int id;
    char genre[30];
    struct book* left;
    struct book* right;
};

struct student {
    char name[30];
    char email[50];
    char book[50];
    char author[50];
    int id;
    struct student* next;
};

// Global variables
struct book* root = NULL;
struct student* start = NULL;

// Function prototypes
struct book* createNode(char name[], char author[], int id, char genre[]);
struct book* insertBook(struct book* root, char name[], char author[], int id, char genre[]);
struct book* searchBook(struct book* root, int id);
struct book* findMin(struct book* root);
struct book* deleteBook(struct book* root, int id);
void inOrderDisplay(struct book* root);
void inOrderDisplayByGenre(struct book* root, char genre[], int* hasBooks);
void displayGenreIntroduction(char genre[]);
void genreBasedDisplay();
void bookIssue();
void bookReturn();
void displayStudents();
void greetings();
void main_menu();

int main() {
    // Initialize the library with some books
    root = insertBook(root, "The Kite Runner", "Khaled Hosseini", 101, "Fiction");
    root = insertBook(root, "To Kill A Mockingbird", "Harper Lee", 102, "Classic");
    root = insertBook(root, "The Alchemist", "Paulo Coelho", 103, "Self-Help");
    root = insertBook(root, "Pride And Prejudice", "Jane Austen", 104, "Classic");
    root = insertBook(root, "A Tale Of Two Cities", "Charles Dickens", 105, "Historical Fiction");
    root = insertBook(root, "1984", "George Orwell", 106, "Dystopian");
    root = insertBook(root, "The Great Gatsby", "F. Scott Fitzgerald", 107, "Classic");
    root = insertBook(root, "Sapiens", "Yuval Noah Harari", 108, "Non-Fiction");
    root = insertBook(root, "Educated", "Tara Westover", 109, "Biography");
    root = insertBook(root, "Gone Girl", "Gillian Flynn", 110, "Thriller");

    greetings();
    main_menu();

    return 0;
}

void greetings() {
    printf("\n\n");
    printf("\t\t\t______________________ WELCOME TO STUDENT LIBRARY______________________\n");
    printf("\t\t\t     ****************************************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *              COEP LIBRARY            *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *         Pune, Maharashtra, India     *\n");
    printf("\t\t\t     *         Email: coeplib@gmail.com     *\n");
    printf("\t\t\t     *      Contact: 0894583920, 348596840  *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     ****************************************\n");
    printf("\n\n\t\t\t             Press Enter to continue...");
    getchar();  
}

void main_menu() {
    int choice;
    do {
        printf("\n\n");
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t\t      MAIN MENU: ");
        printf("\n\t\t\t\t     1. ISSUE OF BOOKS ");
        printf("\n\t\t\t\t     2. RETURN OF BOOKS ");
        printf("\n\t\t\t\t     3. DISPLAY STUDENT DETAILS ");
        printf("\n\t\t\t\t     4. GENRE BASED BOOK DISPLAY ");
        printf("\n\t\t\t\t     5. EXIT\n ");
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bookIssue();
                break;
            case 2:
                bookReturn();
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                genreBasedDisplay();
                break;
            case 5:
                printf("\n\t\t\t\tThank you for using the Student Library system!\n");
                printf("\t\t\t\tHave a great day!\n");
                exit(0);
            default:
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t      Press Enter to try again: ");
                getchar(); 
                getchar();
                break;
        }
    } while (choice != 5);
}

struct book* createNode(char name[], char author[], int id, char genre[]) {
    struct book* newNode = (struct book*)malloc(sizeof(struct book));
    strcpy(newNode->name, name);
    strcpy(newNode->author, author);
    newNode->id = id;
    strcpy(newNode->genre, genre);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct book* insertBook(struct book* root, char name[], char author[], int id, char genre[]) {
    if (root == NULL) {
        return createNode(name, author, id, genre);
    }
    if (id < root->id) {
        root->left = insertBook(root->left, name, author, id, genre);
    } else if (id > root->id) {
        root->right = insertBook(root->right, name, author, id, genre);
    }
    return root;
}

struct book* searchBook(struct book* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return searchBook(root->left, id);
    }
    return searchBook(root->right, id);
}

struct book* findMin(struct book* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct book* deleteBook(struct book* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->id) {
        root->left = deleteBook(root->left, id);
    } else if (id > root->id) {
        root->right = deleteBook(root->right, id);
    } else {
        if (root->left == NULL) {
            struct book* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct book* temp = root->left;
            free(root);
            return temp;
        }
        struct book* temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        strcpy(root->author, temp->author);
        strcpy(root->genre, temp->genre);
        root->right = deleteBook(root->right, temp->id);
    }
    return root;
}

void inOrderDisplay(struct book* root) {
    if (root != NULL) {
        inOrderDisplay(root->left);
        printf("\n\t Book Title: %s", root->name);
        printf("\n\t Name of Author: %s", root->author);
        printf("\n\t Book ID: %d", root->id);
        printf("\n\t Genre: %s", root->genre);
        printf("\n\t_________________________________________________\n");
        inOrderDisplay(root->right);
    }
}

void displayGenreIntroduction(char genre[]) {
    printf("\n\t\t\t\tAre you in the mood for some %s books?\n", genre);
    printf("\t\t\t\t--------------------------------------\n");
    printf("\t\t\t\tDiscover our collection of %s books below!\n", genre);
}

void genreBasedDisplay() {
    char genre[30];

    system("clear");

    printf("\n\t\t\t\t*************************************\n");
    printf("\t\t\t\t*       Explore Books by Genre      *\n");
    printf("\t\t\t\t*************************************\n");

    printf("\n\t\t\t\tWhat genre of books are you interested in? \n");
    printf("\n\t\t\t\tChoose from the following options:\n");
    printf("\n\t\t\t\t1. Fiction");
    printf("\n\t\t\t\t2. Classic");
    printf("\n\t\t\t\t3. Self-Help");
    printf("\n\t\t\t\t4. Historical Fiction");
    printf("\n\t\t\t\t5. Dystopian");
    printf("\n\t\t\t\t6. Non-Fiction");
    printf("\n\t\t\t\t7. Biography");
    printf("\n\t\t\t\t8. Thriller");
    printf("\n\t\t\t\t9. Science Fiction");
    printf("\n\t\t\t\t10. Fantasy");
    printf("\n\t\t\t\t11. Romance");
    printf("\n\t\t\t\t12. Mystery");
    printf("\n\t\t\t\t13. Horror");
    printf("\n\t\t\t\t14. Adventure");
    printf("\n\t\t\t\t15. Drama");
    printf("\n\t\t\t\t16. Young Adult");
    printf("\n\t\t\t\t17. Art");
    printf("\n\t\t\t\t18. History");

    printf("\n\n\t\t\t\tEnter your choice (1-18): ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: strcpy(genre, "Fiction"); break;
        case 2: strcpy(genre, "Classic"); break;
        case 3: strcpy(genre, "Self-Help"); break;
        case 4: strcpy(genre, "Historical Fiction"); break;
        case 5: strcpy(genre, "Dystopian"); break;
        case 6: strcpy(genre, "Non-Fiction"); break;
        case 7: strcpy(genre, "Biography"); break;
        case 8: strcpy(genre, "Thriller"); break;
        case 9: strcpy(genre, "Science Fiction"); break;
        case 10: strcpy(genre, "Fantasy"); break;
        case 11: strcpy(genre, "Romance"); break;
        case 12: strcpy(genre, "Mystery"); break;
        case 13: strcpy(genre, "Horror"); break;
        case 14: strcpy(genre, "Adventure"); break;
        case 15: strcpy(genre, "Drama"); break;
        case 16: strcpy(genre, "Young Adult"); break;
        case 17: strcpy(genre, "Art"); break;
        case 18: strcpy(genre, "History"); break;
        default:
            printf("\n\t\t\t\tInvalid choice. Please try again.\n");
            return;
    }

    displayGenreIntroduction(genre);
   
    struct book* tempRoot = root;
    int hasBooks = 0;

    printf("\n\t\t\t\tHere are some books from the %s genre:\n", genre);
    printf("\n\t\t\t\t---------------------------------------------\n");

    inOrderDisplayByGenre(tempRoot, genre, &hasBooks);

    if (!hasBooks) {
        printf("\n\t\t\t\tNo books found in the %s genre.\n", genre);
    }

    printf("\n\t\t\t\tPress Enter to go back to the main menu...");
    getchar(); 
    getchar();  
}

void inOrderDisplayByGenre(struct book* root, char genre[], int* hasBooks) {
    if (root != NULL) {
        inOrderDisplayByGenre(root->left, genre, hasBooks);
        if (strcmp(root->genre, genre) == 0) {
            *hasBooks = 1;
            printf("\n\t Book Title: %s", root->name);
            printf("\n\t Name of Author: %s", root->author);
            printf("\n\t Book ID: %d", root->id);
            printf("\n\t Genre: %s", root->genre);
            printf("\n\t_________________________________________________\n");
        }
        inOrderDisplayByGenre(root->right, genre, hasBooks);
    }
}

void bookIssue() {
    int id;
    struct book* book;
    system("clear");

    // Welcome message for issuing a book
    printf("\n\n\t\t\t\t*******************************\n");
    printf("\t\t\t\t*       Issue a Book           *\n");
    printf("\t\t\t\t*  Find your next great read!  *\n");
    printf("\t\t\t\t*******************************\n");
    printf("\n\n");

    // Display the list of available books with their IDs
    printf("\n\t\t\t\tHere are the books available for you to borrow:\n");
    printf("\n\t\t\t\t---------------------------------------------\n");
    inOrderDisplay(root);  // Display books in the library with genre
   
    // Prompt user to enter the Book ID
    printf("\n\t\t\t\tEnter the Book ID you wish to borrow: ");
    scanf("%d", &id);

    // Search for the book with the given ID
    book = searchBook(root, id);
    if (book != NULL) {
        // Book found; display book details
        printf("\n\t\t\t\tFantastic choice! Here are the details of the book you are about to borrow:\n");
        printf("\n\t\t\t\t---------------------------------------------\n");
        printf("\t\t\t\tBook Title: %s\n", book->name);
        printf("\t\t\t\tAuthor: %s\n", book->author);
        printf("\t\t\t\tBook ID: %d\n", book->id);
        printf("\t\t\t\tGenre: %s\n", book->genre);
        printf("\t\t\t\t---------------------------------------------\n");

        // Ask for student details
        struct student* newStudent = (struct student*)malloc(sizeof(struct student));
        printf("\n\t\t\t\tPlease provide your details for the record:\n");
        printf("\t\t\t\t---------------------------------------------\n");
        printf("\t\t\t\tEnter your Name: ");
        scanf("%s", newStudent->name);
        printf("\t\t\t\tEnter your Email: ");
        scanf("%s", newStudent->email);
        strcpy(newStudent->book, book->name);
        strcpy(newStudent->author, book->author);
        newStudent->id = book->id;
        newStudent->next = NULL;

        // Add student to the list
        if (start == NULL) {
            start = newStudent;
        } else {
            struct student* ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newStudent;
        }

        // Remove the book from the library
        root = deleteBook(root, id);

        // Confirm the book issue
        printf("\n\t\t\t\tYou have successfully borrowed the book!\n");
        printf("\n\t\t\t\tThank you, %s! Happy Reading!\n", newStudent->name);
        printf("\n\t\t\t\t---------------------------------------------\n");

    } else {
        // Book not found
        printf("\n\t\t\t\tOops! No book found with ID %d.\n", id);
        printf("\n\t\t\t\tPlease check the ID and try again.\n");
        printf("\n\t\t\t\t---------------------------------------------\n");
    }

    // Prompt user to return to the main menu
    printf("\n\t\t\t\tPress Enter to go back to the main menu...");
    getchar(); 
    getchar(); 
}

void bookReturn() {
    int id;
    struct student* prev = NULL;
    struct student* curr = start;
    struct book* bookToReturn;

    system("clear");

    // Welcome message for returning a book
    printf("\n\n\t\t\t\t*******************************\n");
    printf("\t\t\t\t*       Return a Book         *\n");
    printf("\t\t\t\t*  Bring back the borrowed book! *\n");
    printf("\t\t\t\t*******************************\n");
    printf("\n\n");

    // Display the list of borrowed books with their IDs
    printf("\n\t\t\t\tHere are the books you have borrowed:\n");
    printf("\n\t\t\t\t---------------------------------------------\n");

    while (curr != NULL) {
        printf("\n\t\t\t\tName: %s", curr->name);
        printf("\n\t\t\t\tEmail: %s", curr->email);
        printf("\n\t\t\t\tBorrowed Book: %s", curr->book);
        printf("\n\t\t\t\tAuthor: %s", curr->author);
        printf("\n\t\t\t\tBook ID: %d", curr->id);
        printf("\n\t\t\t\t---------------------------------------------\n");
        curr = curr->next;
    }

    // Prompt user to enter the Book ID they wish to return
    printf("\n\t\t\t\tEnter the Book ID you wish to return: ");
    scanf("%d", &id);

    // Find the book to return
    curr = start;
    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        // Book found; display book details
        printf("\n\t\t\t\tThank you for returning the book! Here are the details of the book:\n");
        printf("\n\t\t\t\t---------------------------------------------\n");
        printf("\t\t\t\tBook Title: %s\n", curr->book);
        printf("\t\t\t\tAuthor: %s\n", curr->author);
        printf("\t\t\t\tBook ID: %d\n", curr->id);
        printf("\t\t\t\t---------------------------------------------\n");

        // Add the book back to the library
        bookToReturn = createNode(curr->book, curr->author, curr->id, "Genre not specified");
        root = insertBook(root, bookToReturn->name, bookToReturn->author, bookToReturn->id, "Genre not specified");

        // Remove the student from the list
        if (prev != NULL) {
            prev->next = curr->next;
        } else {
            start = curr->next;
        }
        free(curr);

        printf("\n\t\t\t\tBook successfully returned to the library!\n");
    } else {
        // Book not found
        printf("\n\t\t\t\tOops! No book found with ID %d.\n", id);
        printf("\n\t\t\t\tPlease check the ID and try again.\n");
    }

    // Prompt user to return to the main menu
    printf("\n\t\t\t\tPress Enter to go back to the main menu...");
    getchar();
    getchar();  
}

void displayStudents() {
    // Display student details
    struct student* ptr = start;

    system("clear");

    printf("\n\t\t\t\t*******************************\n");
    printf("\t\t\t\t*   Student Details           *\n");
    printf("\t\t\t\t*******************************\n");
    printf("\n\t\t\t\tList of Students who borrowed books:\n");
    printf("\n\t\t\t\t---------------------------------------------\n");

    while (ptr != NULL) {
        printf("\n\t\t\t\tName: %s", ptr->name);
        printf("\n\t\t\t\tEmail: %s", ptr->email);
        printf("\n\t\t\t\tBorrowed Book: %s", ptr->book);
        printf("\n\t\t\t\tAuthor: %s", ptr->author);
        printf("\n\t\t\t\tBook ID: %d", ptr->id);
        printf("\n\t\t\t\t---------------------------------------------\n");
        ptr = ptr->next;
    }

    printf("\n\t\t\t\tPress Enter to go back to the main menu...");
    getchar(); 
    getchar();  
}


