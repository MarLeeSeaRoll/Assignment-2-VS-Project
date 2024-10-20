# Student Grades Program - README

## Authors

- [@SRVSRR](https://www.github.com/SRVSRR)
- [@MarLeeSeaRoll](https://www.github.com/MarLeeSeaRoll)

## Overview

The **Student Grades Program** is a C++ application designed to manage and analyze student performance data, including their coursework and final exam marks. The program supports various functionalities such as viewing, updating, and calculating key metrics like class average, pass rates, and identifying the highest scorer. The data is stored in a doubly linked list, providing flexibility for list operations.

## Features

1.**Print Entire List of Students with Grades: Display all student data, including coursework, final exam marks, total marks, grades，the average mark for the class，the percentage of students who passed and the details of the student with the highest total mark.
2.**Update Student's Marks: Search for a student by ID and update their coursework or final exam marks.
3.**Calculate Average Marks: Calculate  the average mark for the class.
4.**Calculate Pass Rate: Calculate  the percentage of students who passed (total marks ≥ 50).
5.**Identify Highest Scorer's Details: Identify the student with the highest total mark.
6.**Exit Program: Gracefully terminate the program, releasing all dynamically allocated memory.

## File Format

Student data is read from a file called `studentData.txt`. This file should contain three columns: 
- `ID` (student identifier)
- `Coursework` (marks for coursework out of 50)
- `Final_Exam` (marks for final exam out of 50)

### Example File Format:
```
ID      Coursework   Final_Exam
S00001  46.05        39.4
S00002  23.6         12.4
S00003  17.3         17.8
```

**Sample data in `studentData.txt`:**

```
ID      Coursework   Final_Exam
S00001  46.05        39.4
S00002  23.6         12.4
S00003  17.3         17.8
S00004  22.5         27.8
S00005  41.7         20.0
...
```

The program reads this data into a doubly linked list, where each student's data is stored in a node.

## How the Program Works

### Menu Options
Upon running the program, a menu is presented with the following options:

1. **Print Entire List with Grades: Displays all students along with their coursework, final exam marks, total marks, their computed grade, the average mark, the pass rate of this course and highest scorer.

2. **Update Student's Marks**: Prompts the user to search for a student by ID and allows updating either their coursework, final exam marks, or both.

3. **Exit Program**: Exits the program, displaying a thank-you message and cleaning up allocated memory.

### Grading Scheme
Grades are determined by total marks (coursework + final exam):
- A+ : Total marks ≥ 85
- A  : Total marks ≥ 78
- B+ : Total marks ≥ 71
- B  : Total marks ≥ 64
- C+ : Total marks ≥ 57
- C  : Total marks ≥ 50
- D  : Total marks ≥ 40
- E  : Total marks < 40

### Memory Management
The program dynamically allocates memory for each `Student` structure and each `node` in the linked list. Before exiting, it ensures all memory is freed using the `FreeList()` function to prevent memory leaks.

## Running the Program

### Requirements
- A C++ compiler such as `g++`.
- The input file `studentData.txt` in the correct format.

### Compilation and Execution
1. **Compile the Program**:
   ```bash
   g++ studentGrades.cpp -o studentGrades
   ```
   
2. **Run the Program**:
   ```bash
   ./studentGrades
   ```

3. **Follow the Menu**:
   After starting, the program loads the student data from `studentData.txt` and displays a menu for interacting with the system. Choose options by entering the corresponding number.

### Example Program Flow
1. **Welcome Message**:
   ```
   +-------------------------------------------------+
   |      WELCOME TO THE STUDENT GRADES PROGRAM      |
   +-------------------------------------------------+
   Enter S to start or Q to quit
   ```

2. **Main Menu**:
   ```
   Menu:
   1. Print Entire List with Grades
   2. Update Student's Marks
   3. Exit Program

   Enter the number corresponding to your choice:
   ```

3. **Sample Output - Print Entire List**:
   ```
   The Entire List of Students with Grades:
   ID                   Coursework          Final Exam          Grade               
   -----------------------------------------------------------------
   S00001               46.05               39.4                A                   
   S00002               23.6                12.4                E                   
   S00003               17.3                17.8                E                   
   ...
Average Marks: 43.78
Pass Rate: 40.00%

Highest Scorer:
ID        CW Marks   FE Marks   Total      Grade
----------------------------------------------
S00001    46.05     39.40     85.45     A+
   ```

## Program Logic

### Core Functions

1. **`fillArray(string fileName, int& rows, node*& pHead)`**:
   - Reads the student data from `studentData.txt` and appends it to a doubly linked list.
   
2. **`printEntireList(node* pHead)`**:
   - Prints all students in the list along with their coursework, final exam, total marks, calculated grade, calculated average mark, calculated pass rate and details of highest scorer.

3. **`updateMark(node* pHead)`**:
   - Searches for a student by their ID and allows the user to update their coursework and/or final exam marks.

### Input Validation
- The program includes robust input validation to ensure the user enters valid options and that student IDs conform to the expected format.

### Exit and Cleanup
- When the user selects "Exit", the program gracefully frees all allocated memory and displays a thank-you message.

## Conclusion

The **Student Grades Program** is a comprehensive tool for managing and analyzing student performance data. With its ability to calculate key metrics like average marks and pass rates, along with flexible data updating and viewing capabilities, this program can be a useful addition to any academic or training environment.