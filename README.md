# Student-Management-System-on-C
📘 Student Management System (CRUD in C)

This project is a menu-driven Student Management System developed in C that performs basic CRUD operations (Create, Read, Update, Delete) using file handling.

🚀 Features
Create: Add new student records
Read: View all stored records
Update: Modify existing student details
Delete: Remove student records
Sort: Organize records based on faculty, year, and roll number
🧾 Stored Data

Each student record includes:

Name
Address
Roll Number
Section
Faculty
Phone Number

🛠️ Technologies Used
C Programming Language
File Handling (.bin file for persistent storage)
Structures, Arrays, and Functions

⚙️ How It Works
The program is menu-driven, allowing users to select operations from the main menu.
Data is stored in a binary file (student.bin) to ensure permanent storage.
Functions are modularized for each operation (Add, View, Edit, Delete, Sort).

⚠️ Challenges & Solutions
String input issues with scanf() → solved using fgets() and newline handling
Unavailable functions (clrscr(), getch()) → replaced with alternatives like system("clear") and getchar()
Uppercase conversion → implemented using a custom function

🎯 Learning Outcomes
Practical understanding of file handling in C
Use of structures and modular programming
Improved problem-solving and logical thinking skills
