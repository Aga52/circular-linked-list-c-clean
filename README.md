# Circular Singly Linked List in C

A console application written in C that implements a circular singly linked list using dynamic memory allocation.

Developed as part of a Procedural Programming assignment at Vilnius University.

## Features

- Create an empty circular singly linked list.
- Read integers from a text file.
- Print the list to the console or save it to a file.
- Insert a new element before the first node containing a specified value.
- Delete the entire list and free allocated memory.
- Handle invalid user input and file-related errors.
- Print list elements using recursion.
- Run unit tests with `assert()`.

## Project Structure

| File | Description |
|---|---|
| `main.c` | Main menu, user input validation, and file handling |
| `list.c` | Circular linked list operations |
| `list.h` | Node structure and function declarations |
| `tests.c` | Unit tests using `assert()` |
| `Makefile` | Build and test commands |
| `CODING_STYLE.md` | Coding style guidelines |

## How It Works

Each node contains an integer value and a pointer to the next node.

Unlike a regular singly linked list, the last node points back to the first node, forming a cycle.

For example:

`10 → 20 → 30 → 10 (head)`

The main operation is `insertBefore()`, which inserts a new node before the first occurrence of a specified value.

Example:

Before: `10 → 20 → 30`

Insert `15` before `20`.

After: `10 → 15 → 20 → 30`

The circular structure is preserved.

## Compilation and Execution

The project uses GCC and Make.

On Windows with MinGW:

```powershell
mingw32-make
mingw32-make run
```

To run unit tests without launching the interactive menu:

```powershell
mingw32-make test
```

To remove compiled executables:

```powershell
mingw32-make clean
```

## Menu

```text
0. Create an empty list
1. Read a list from a file
2. Print the list to the screen or a file
3. Insert an element before a specified value
4. Delete the entire list
5. Exit
```

## Example Input

Create a text file named `input.txt`:

```text
10 20 30 40
```

Select option `1` to read the file.

Then select option `3` to insert `15` before `20`.

Result:

```text
10 15 20 30 40
```

## Testing

Unit tests are implemented with the standard C `assert.h` library.

The tests cover node creation, circular links, insertion into an empty list, insertion before the first element, missing target values, duplicate values, recursive printing, and memory cleanup.

## Technologies

- C (C11)
- GCC
- Make
- Git and GitHub

## Author

Aga52  
Vilnius University — Software Engineering