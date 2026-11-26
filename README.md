##single linked list


##Student data

A menu-driven Student Record Management System developed in C using a singly linked list, dynamic memory allocation and file handling. The application provides functionalities to manage student records efficiently and stores records persistently using file operations.

## Features
- **Add (`a/A`)** – Add a new student record with the smallest available positive roll number.
- **Delete (`d/D`)** – Delete a student record by roll number or name.
- **Display (`s/S`)** – Display all student records in tabular format.
- **Modify (`m/M`)** – Modify student details.
- **Save (`v/V`)** – Save student records to `student.dat`.
- **Exit (`e/E`)** – Save and exit or exit without saving.
- **Sort (`t/T`)** – Sort records by name or percentage.
- **Delete All (`l/L`)** – Delete all nodes and free allocated memory.
- **Reverse (`r/R`)** – Reverse the singly linked list.

## Concepts Used
- C Programming
- Structures
- Singly Linked List
- Dynamic Memory Allocation (`malloc`, `free`)
- File Handling 
- Pointer Manipulation
- Searching and Sorting
- Makefile

## Project Structure

```text
Student_Record_Management/
│
├── stud_main.c
├── student.h
├── stud_add.c
├── stud_del.c
├── stud_show.c
├── stud_mod.c
├── stud_save.c
└── Makefile
```

## Compilation

The project uses a Makefile to compile and link all source files.

```bash
make
```

This generates the executable named `studentdata`.

## Execution

```bash
./student data
```

## Clean

To remove the executable and generated object files:

```bash
make clean
```

## File Storage

Student records are saved in a binary file named `student.dat`. The saved records can be loaded when the application starts again, allowing data to persist between executions.

## Purpose

This project demonstrates the practical implementation of linked lists, pointers, dynamic memory allocation, file handling and modular programming in C.
