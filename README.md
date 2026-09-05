# Library Management System

A console-based Library Management System written in C. It manages books, members, and borrow/return transactions, with simple text-file persistence between runs.

## Features

- **Books**
  - Add a book (ISBN, title, author, total copies, available copies)
  - Remove a book by title
  - Search for a book by title
  - List all books with full details

- **Members**
  - Register a new member (ID, name, phone number)
  - List all members
  - Look up a member by ID

- **Transactions**
  - Borrow a book (by title, member ID, and loan period in days)
  - Return a book, with automatic overdue fee calculation

- **Persistence**
  - Book, member, and transaction data are loaded from text files on startup and saved back on exit
  - Record counts and data are stored in separate files (`Books_size.txt`, `Members.txt`, `Record.txt`, etc.)

## Project Structure

| File | Description |
|---|---|
| `Main.c` | Entry point; console menu that ties all modules together |
| `Books.c` / `Books.h` | Book struct and operations (add, remove, search, list) |
| `Member.c` / `Member.h` | Member struct and operations (register, list, find) |
| `Transaction.c` / `Transaction.h` | Borrow/return logic and overdue fee calculation |
| `Storage.c` / `Storage.h` | Generic load/save routines for persisting data to text files |

## Building

Requires a C compiler (GCC recommended). From the project directory:

```bash
gcc Main.c Books.c Member.c Storage.c Transaction.c -o library.exe
```

Run the resulting binary:

```bash
./library.exe
```

> The project builds cleanly with GCC, aside from one harmless format-specifier warning in `Storage.c` (`%d` used for a `bool*` field when loading transaction records).

## Usage

On launch, the program loads any existing data from `Library.txt`, `Members.txt`, and `Record.txt` (if present) and presents a menu:

```
Select an option:
1. Books Operations
2. Member Operations
3. Transactions Operations
```

Each section has its own sub-menu (add/remove/search/list for books, register/list/find for members, borrow/return for transactions). After each operation you'll be asked if you want to perform another; answering `n` saves all data back to disk before exiting.

## Data Files

| File | Contents |
|---|---|
| `Library.txt` | Book records (ISBN, title, author, total/available copies) |
| `Members.txt` | Member records (ID, name, phone number) |
| `Record.txt` | Borrow records (ISBN, member ID, borrow/due dates, return status) |
| `Books_size.txt`, `Members_size.txt`, `Transaction_size.txt` | Stored counts, used to know how many records to load on the next run |

These files are created automatically in the working directory the first time the program saves data.

## Known Limitations

This project is a work in progress / learning exercise, so a few limitations are worth calling out:

- **Fixed capacities**: Books (1000), members (300), and transactions (1000) use static arrays, so capacity is capped at compile time.
- **Member IDs are used as array indices** for the `ID_taken` lookup table, so IDs must stay within `member_capactiy` (300) and IDs ≤ 0 are unsafe.
- **No input validation** on scanf-based menu input (e.g., non-numeric input where a number is expected can put the program in a bad state).
- **Fixed-size string fields** (e.g., `title[20]`, `name[10]`) can silently truncate or overflow with longer input via `scanf("%s", ...)`.
- **Overdue fee calculation** compares the due date against the current time using `mktime`, which assumes the `struct tm` is fully and correctly populated (some fields like `tm_year`/`tm_mon` follow C's zero-based conventions and should be double-checked for correctness).
