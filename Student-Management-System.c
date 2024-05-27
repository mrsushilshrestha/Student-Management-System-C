#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_CLASS 10
#define MAX_FACULTY 50
#define MAX_BATCH_CODE 10

typedef struct
{
    int id;
    char name[MAX_NAME];
    char batchCode[MAX_BATCH_CODE];
    char class[MAX_CLASS];
    char faculty[MAX_FACULTY];
} Student;

void addStudent();
void deleteStudent();
void modifyStudent();
void showStudents();
void searchStudent();
void clearInputBuffer();
int generateID();
int isValidBatchCode(const char *code);
void displayMessage(const char *message, const char *color);
void displayStudent(const Student *student);

int main()
{
    int choice;

    while (1)
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Modify Student\n");
        printf("4. Show Students\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            showStudents();
            break;
        case 3:
            modifyStudent();
            showStudents();
            break;
        case 4:
            showStudents();
            break;
        case 5:
            searchStudent();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStudent()
{
    FILE *file = fopen("studentManagement.txt", "a");
    Student student;

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    student.id = generateID();
    printf("Generated ID: %d\n", student.id);
    printf("Enter Name: ");
    fgets(student.name, MAX_NAME, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline character

    do
    {
        printf("Enter Batch Code (Format XXXX-123): ");
        fgets(student.batchCode, MAX_BATCH_CODE, stdin);
        student.batchCode[strcspn(student.batchCode, "\n")] = '\0'; // Remove newline character
        if (!isValidBatchCode(student.batchCode))
        {
            printf("Invalid batch code format. Please try again.\n");
        }
    } while (!isValidBatchCode(student.batchCode));

    printf("Enter Class: ");
    fgets(student.class, MAX_CLASS, stdin);
    student.class[strcspn(student.class, "\n")] = '\0'; // Remove newline character
    printf("Enter Faculty: ");
    fgets(student.faculty, MAX_FACULTY, stdin);
    student.faculty[strcspn(student.faculty, "\n")] = '\0'; // Remove newline character

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    displayMessage("Student added successfully!", "\033[0;32m"); // Green color
    displayStudent(&student);                                    // Show recently added record
}

void deleteStudent()
{
    FILE *file = fopen("studentManagement.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char batchCode[MAX_BATCH_CODE];
    int found = 0;
    Student student;

    if (file == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Batch Code to delete: ");
    fgets(batchCode, MAX_BATCH_CODE, stdin);
    batchCode[strcspn(batchCode, "\n")] = '\0'; // Remove newline character

    while (fread(&student, sizeof(Student), 1, file))
    {
        if (strcmp(student.batchCode, batchCode) != 0)
        {
            fwrite(&student, sizeof(Student), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("studentManagement.txt");
    rename("temp.txt", "studentManagement.txt");

    if (found)
    {
        displayMessage("Student deleted successfully!", "\033[0;31m"); // Red color
    }
    else
    {
        printf("Student not found!\n");
    }
}

void modifyStudent()
{
    FILE *file = fopen("studentManagement.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char batchCode[MAX_BATCH_CODE];
    int found = 0;
    Student student;

    if (file == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Batch Code to modify: ");
    fgets(batchCode, MAX_BATCH_CODE, stdin);
    batchCode[strcspn(batchCode, "\n")] = '\0'; // Remove newline character

    while (fread(&student, sizeof(Student), 1, file))
    {
        if (strcmp(student.batchCode, batchCode) == 0)
        {
            found = 1;
            printf("Enter new Name: ");
            fgets(student.name, MAX_NAME, stdin);
            student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline character

            do
            {
                printf("Enter new Batch Code (Format XXXX-123): ");
                fgets(student.batchCode, MAX_BATCH_CODE, stdin);
                student.batchCode[strcspn(student.batchCode, "\n")] = '\0'; // Remove newline character
                if (!isValidBatchCode(student.batchCode))
                {
                    printf("Invalid batch code format. Please try again.\n");
                }
            } while (!isValidBatchCode(student.batchCode));

            printf("Enter new Class: ");
            fgets(student.class, MAX_CLASS, stdin);
            student.class[strcspn(student.class, "\n")] = '\0'; // Remove newline character
            printf("Enter new Faculty: ");
            fgets(student.faculty, MAX_FACULTY, stdin);
            student.faculty[strcspn(student.faculty, "\n")] = '\0'; // Remove newline character
        }
        fwrite(&student, sizeof(Student), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove("studentManagement.txt");
    rename("temp.txt", "studentManagement.txt");

    if (found)
    {
        displayMessage("Student modified successfully!", "\033[0;33m"); // Yellow color
    }
    else
    {
        printf("Student not found!\n");
    }
}

void showStudents()
{
    FILE *file = fopen("studentManagement.txt", "r");
    Student student;

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\n%-5s %-30s %-10s %-10s %-20s\n", "ID", "Name", "BatchCode", "Class", "Faculty");
    printf("----------------------------------------------------------------------\n");
    while (fread(&student, sizeof(Student), 1, file))
    {
        printf("%-5d %-30s %-10s %-10s %-20s\n", student.id, student.name, student.batchCode, student.class, student.faculty);
    }

    fclose(file);
}

void searchStudent()
{
    FILE *file = fopen("studentManagement.txt", "r");
    char batchCode[MAX_BATCH_CODE];
    int found = 0;
    Student student;

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Batch Code to search: ");
    fgets(batchCode, MAX_BATCH_CODE, stdin);
    batchCode[strcspn(batchCode, "\n")] = '\0'; // Remove newline character

    while (fread(&student, sizeof(Student), 1, file))
    {
        if (strcmp(student.batchCode, batchCode) == 0)
        {
            displayStudent(&student);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Student not found!\n");
    }
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int generateID()
{
    FILE *file = fopen("studentManagement.txt", "r");
    Student student;
    int maxID = 0;

    if (file == NULL)
    {
        return 1; // Start IDs from 1 if file doesn't exist
    }

    while (fread(&student, sizeof(Student), 1, file))
    {
        if (student.id > maxID)
        {
            maxID = student.id;
        }
    }

    fclose(file);
    return maxID + 1;
}

int isValidBatchCode(const char *code)
{
    int i;

    if (strlen(code) != 8)
        return 0;
    for (i = 0; i < 4; i++)
    {
        if (!isalpha(code[i]))
            return 0;
    }
    if (code[4] != '-')
        return 0;
    for (i = 5; i < 8; i++)
    {
        if (!isdigit(code[i]))
            return 0;
    }
    return 1;
}

void displayMessage(const char *message, const char *color)
{
    printf("%s%s\033[0m\n", color, message); // Reset color after message
}

void displayStudent(const Student *student)
{
    printf("\n%-5s %-30s %-10s %-10s %-20s\n", "ID", "Name", "BatchCode", "Class", "Faculty");
    printf("----------------------------------------------------------------------\n");
    printf("%-5d %-30s %-10s %-10s %-20s\n", student->id, student->name, student->batchCode, student->class, student->faculty);
}
// sushil shrestha