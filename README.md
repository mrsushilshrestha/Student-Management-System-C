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



### Example User Interaction

Let's go through a typical session with the program:

#### **Adding a Student (Option 1)**

1. After selecting **1** to add a student, the program will generate a unique student ID for you.
2. Then, it prompts you to enter the student's details:
    ```
    Generated ID: 1
    Enter Name: John Doe
    Enter Batch Code (Format XXXX-123): ABCD-123
    Enter Class: Computer Science
    Enter Faculty: Engineering
    ```

3. Once the data is entered, the system confirms that the student was added successfully:
    ```
    Student added successfully!
    ```

4. The system will display the newly added student's details:
    ```
    ID   Name                           BatchCode Class      Faculty              
    ----------------------------------------------------------------------
    1    John Doe                       ABCD-123  Computer Science  Engineering
    ```

#### **Deleting a Student (Option 2)**

1. Choose **2** to delete a student.
2. The program will ask for the **batch code** of the student to delete:
    ```
    Enter Batch Code to delete:
    ```

3. If the student is found, the system will confirm deletion with a message like this:
    ```
    Student deleted successfully!
    ```

4. If the batch code is incorrect, the system will notify the user:
    ```
    Student not found!
    ```

#### **Modifying a Student (Option 3)**

1. Choose **3** to modify a student’s details.
2. Enter the **batch code** of the student you want to modify:
    ```
    Enter Batch Code to modify:
    ```

3. After finding the student, you will be prompted to modify the student's details:
    ```
    Enter new Name: Jane Doe
    Enter new Batch Code (Format XXXX-123): XYZA-456
    Enter new Class: Software Engineering
    Enter new Faculty: Computer Science
    ```

4. Once modifications are done, the system will show the updated student details:
    ```
    Student modified successfully!
    ID   Name                           BatchCode Class               Faculty
    ----------------------------------------------------------------------
    1    Jane Doe                       XYZA-456  Software Engineering  Computer Science
    ```

#### **Showing All Students (Option 4)**

1. When you select **4**, all student records are displayed:
    ```
    ID   Name                           BatchCode Class      Faculty              
    ----------------------------------------------------------------------
    1    John Doe                       ABCD-123  Computer Science  Engineering
    2    Jane Doe                       XYZA-456  Software Engineering  Computer Science
    ```

#### **Searching for a Student (Option 5)**

1. Choose **5** to search for a student by their **batch code**.
2. The system will prompt for the **batch code**:
    ```
    Enter Batch Code to search:
    ```

3. If the student is found, the system displays their details:
    ```
    ID   Name                           BatchCode Class      Faculty              
    ----------------------------------------------------------------------
    1    John Doe                       ABCD-123  Computer Science  Engineering
    ```

4. If no student is found, it will display:
    ```
    Student not found!
    ```

#### **Exiting the Program (Option 6)**

1. Choose **6** to exit the program:
    ```
    Exiting the system...
    ```

---

## Key Functions

### `addStudent()`
- Adds a new student with generated ID and entered details (Name, Batch Code, Class, Faculty).

### `deleteStudent()`
- Deletes a student record based on **batch code**.

### `modifyStudent()`
- Modifies an existing student's record based on **batch code**.

### `showStudents()`
- Displays all student records in a tabular format.

### `searchStudent()`
- Searches and displays a student by **batch code**.

### `clearInputBuffer()`
- Clears the input buffer to prevent leftover characters from affecting subsequent inputs.

### `generateID()`
- Generates a unique student ID by reading the existing records.

### `isValidBatchCode()`
- Validates that the batch code follows the correct format: `XXXX-123` (4 letters, hyphen, 3 digits).

### `displayMessage()`
- Displays success, error, or informational messages in color.

### `displayStudent()`
- Displays the details of a single student in a formatted table.

## Error Handling

- **File errors**: If the student records file cannot be opened, an error message is displayed.
- **Invalid input**: The program ensures that user inputs such as batch codes and student details are validated.
- **Student not found**: When deleting, modifying, or searching for a student, if the batch code is not found, the system will notify the user.

---

## Conclusion

This **Student Management System** provides a simple interface for managing student data. You can add, modify, delete, search, and view all student records efficiently. It uses a text file to persist data between sessions, ensuring that records are not lost.

Feel free to enhance the program by adding additional features like sorting records or implementing more complex search filters.
