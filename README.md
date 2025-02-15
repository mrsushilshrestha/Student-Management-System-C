# Student Management System

## Overview
The **Student Management System** is a simple console-based application implemented in **C** to manage student records. It allows users to perform basic operations such as **adding**, **deleting**, **modifying**, **searching**, and **displaying** student records. The records are stored in a text file named `studentManagement.txt`.

The application supports the following functionalities:
1. **Add a Student**: Add a new student with a unique ID and details (Name, Batch Code, Class, Faculty).
2. **Delete a Student**: Delete a student record using their batch code.
3. **Modify a Student**: Modify the details of an existing student by their batch code.
4. **Show Students**: Display a list of all students stored in the system.
5. **Search for a Student**: Search for a student based on their batch code.
6. **Exit**: Exit the program.

## Features
- **Batch Code Validation**: Ensures that the batch code follows the correct format: `XXXX-123` (4 letters followed by a hyphen and 3 digits).
- **Dynamic ID Generation**: Automatically generates a unique student ID when adding a new student.
- **Color-coded Messages**: Success, error, and informational messages are displayed in color for better user experience.
- **File-Based Storage**: All student records are stored in `studentManagement.txt` and are persisted between program runs.

## Compilation and Execution

### Requirements:
- **C Compiler** (e.g., GCC).
- **Operating System** that supports C development.

### Steps to Compile and Run:
1. Save the code to a file named `student_management.c`.
2. Compile the code:
   ```bash
   gcc -o student_management student_management.c


# Example Interaction
### Student Management System
1. Add Student
2. Delete Student
3. Modify Student
4. Show Students
5. Search Student
6. Exit
#### Enter your choice: 1

Generated ID: 1
Enter Name: John Doe
Enter Batch Code (Format XXXX-123): ABCD-123
Enter Class: Computer Science
Enter Faculty: Engineering
Student added successfully!
ID   Name                           BatchCode Class      Faculty              
----------------------------------------------------------------------
1    John Doe                       ABCD-123  Computer Science  Engineering


