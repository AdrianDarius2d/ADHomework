# ADHomework

Book Partitioning Program
Overview
This program reads a list of book sizes from a file and partitions them into three sections such that the total number of pages in each section is as balanced as possible. It uses a greedy algorithm to achieve a near-optimal distribution.

How It Works
The program follows these steps:

Reads the number of books and their sizes from a file named books.txt.
Partitions the books into three sections by always adding the next book to the section with the smallest current total of pages.
Prints the resulting partitions and their total page counts.
Files
partition.c: The main C program.
books.txt: The input file containing the number of books followed by the sizes of the books. An example is provided below.
Input File Format
The input file books.txt should be formatted as follows:

The first line contains a single integer representing the number of books.
The second line contains the sizes of the books separated by spaces.
Notes
Ensure that the books.txt file follows the specified format.
The program uses dynamic memory allocation to handle the array of book sizes. Make sure to free the allocated memory to prevent memory leaks.
