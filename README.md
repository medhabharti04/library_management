# library_management
Developed a Library Management System utilizing Binary Search Trees (BST) for efficient book and patron management, enabling fast search, insertion, and deletion operations. Implemented algorithms for book lending, returns, and detailed reporting, optimizing system performance and scalability.

<strong> COEP Student Library Management System </strong>

Overview:
The Student Library Management System is a C-based command-line application designed to manage the operations of a library. It provides functionalities for book management (issue and return), student record keeping, and genre-based book display. This project aims to showcase the use of Binary Search Trees (BST) and linked lists to manage books and student records efficiently.

Features
Book Management:
Add books to the library.
Remove books from the library.
Display all books in the library.
Find books by genre.

Student Management:
Record the details of students who borrow books.
Display the list of students who have borrowed books.

Book Operations:
Issue books to students.
Return books to the library.
Genre-Based Book Display:
View books based on genre preferences.

Getting Started

Compilation
To compile the program, use the following command in your terminal or command prompt:
gcc -o library_management_system library_management_system.c

Running the Program:
After successful compilation, run the program with:
./library_management_system

Project Structure
The project consists of the following components:

Source Code
library_management_system.c: The main source file containing the entire implementation of the Student Library Management System.
Functions
createNode: Creates a new book node with provided details.
insertBook: Inserts a new book into the BST based on the book ID.
searchBook: Searches for a book in the BST by ID.
deleteBook: Deletes a book from the BST by ID.
inOrderDisplay: Displays all books in the library in ascending order of book ID.
inOrderDisplayByGenre: Displays books filtered by genre.
genreBasedDisplay: Handles user interaction for displaying books by genre.
bookIssue: Manages the process of issuing a book to a student.
bookReturn: Manages the process of returning a book to the library.
displayStudents: Displays the details of students who have borrowed books.
greetings: Displays the initial welcome message.
main_menu: Displays the main menu and handles user choices.

Data Structures
Binary Search Tree (BST): Used to store and manage book records. It allows efficient book insertion, deletion, and search operations.
Linked List: Used to manage student records. It allows dynamic addition and removal of student records as books are borrowed or returned.

Benefits of Using BST and Linked List:
1. Binary Search Tree (BST)
Efficient Search Operations: Searching for a book by ID is efficient with a time complexity of O(log n) on average.
Sorted Order: In-order traversal of the BST provides books in ascending order of their IDs.
Dynamic Structure: BST allows dynamic growth as books are added or removed.
2. Linked List
Dynamic Size: Linked lists allow dynamic memory allocation for storing student records.
Ease of Insertion/Deletion: Adding or removing records (students) is straightforward without the need for resizing.
