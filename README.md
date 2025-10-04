# Alumni-Tracking-System
Description:
This C program manages alumni records using a singly linked list. It allows adding new alumni, searching by ID, and displaying all alumni records. Each record contains Alumni ID, Name, Department, Year of Graduation, and Occupation.

Features:
1. Insert Alumni – Add a new alumni record with ID, Name, Department, Year, and Occupation.
2. Search by ID – Find an alumni by their ID.
3. Display All – Show all alumni records.
4. Exit – Close the program.

How it Works:
- Uses a struct Alumni with fields: ID, Name, Department, Year, Occupation, and pointer to next node.
- Linked list dynamically stores alumni records.
- New entries are added to the head of the list.
- Provides a menu-driven interface for easy operation.

Compilation and Execution:
gcc studentsrecord_alumni.c -o studentsrecord_alumni
./studentsrecord_alumni

Sample Input/Output:
Enter choice: 1
Enter ID: 101
Enter Name: Alice
Enter Department: Computer Science
Enter Year: 2020
Enter Occupation: Software Engineer
Alumni added successfully!

Enter choice: 3
All Alumni Records:
101 | Alice | Computer Science | 2020 | Software Engineer
