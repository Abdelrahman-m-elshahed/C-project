# Library Management System (C)

A simple command-line Library Management System written in C. It provides basic functionality to manage a small library: add/remove/search books, register members, borrow and return books, and persist records to text files.

## What this is
A compact, educational CLI library manager implemented in plain C for learning data structures, file I/O, and modular program organization. Intended for students or hobbyists who want a minimal, self-contained example of a CRUD-style application in C.

### Stack
- Language(s): C (100%)
- Runtime: native C (build with gcc)
- Notable libraries: standard C library headers used across the project:
  - stdio.h — input/output and file I/O
  - stdbool.h — boolean type
  - string.h — string manipulation
  - time.h — date/time handling for borrow/due dates
  - ctype.h — character utilities (tolower)

## Key features / Strength points
- Modular design: functionality split into focused modules (Books, Member, Transaction, Storage, and main CLI) with clear header/source separation.
- File-based persistence: data is loaded from and appended to text files (Library.txt, Members.txt, Record.txt) to keep the state between runs without requiring a database.
- Clear data models: use of C struct types (Book, Member, Borrow_Record) and compile-time capacity constants for simple memory management.
- Simple, interactive CLI: a menu-driven interface in Main.c makes it easy to try features without a GUI.
- Time-aware transactions: Transactions use time.h to compute borrow and due dates and calculate overdue fees.

## How it's organized
Top-level files (annotations):

```text
Books.h/c        - Book struct, add/remove/search/list operations and in-memory array storage
Member.h/c       - Member struct, registration, listing and lookup logic
Transaction.h/c  - Borrow_Record struct, borrow/return logic, overdue checks
Storage.h/c      - Simple file-load/save helpers that read/write plain text files
Main.c           - CLI menu and program entry point that ties modules together
Library.txt      - (data file used at runtime) persisted books
Members.txt      - (data file used at runtime) persisted members
Record.txt       - (data file used at runtime) persisted borrow records
```

How it fits together: Main.c loads persisted data via Storage.Load, then runs a loop presenting menus. Book, Member, and Transaction modules operate on fixed-size arrays declared in their headers and use Storage.Savedata to persist new entries. Borrow/return flows read/update both the Books and Borrowed arrays and append records to Record.txt.

## How to build
The project is pure C and can be built with gcc. From the repository root:

```bash
# Compile all sources into a single executable
gcc Main.c Books.c Member.c Transaction.c Storage.c -o library

# Run
./library
```

If your compiler defaults to C89 and you use features requiring a newer standard, consider adding `-std=c99` or `-std=c11`.

## How to run (quick)
1. Ensure the files Library.txt, Members.txt, and Record.txt are present (they are created/used by the program). If they don't exist, the program will start with empty in-memory arrays.
2. Run `./library` and follow the menu prompts to add books/members and perform borrows/returns.

## Libraries used
This project uses only the standard C library headers listed above. There are no third-party dependencies, making it straightforward to compile and run on any system with a C toolchain.

## Limitations & possible improvements
- Fixed-size arrays: current capacities are compile-time constants (Books_capacity, member_capactiy, borrowed_capacity). Switching to dynamically allocated arrays or linked lists would remove limits.
- Concurrency and atomicity: file writes append data and do not provide transactional safety; simultaneous runs could corrupt files.
- Error handling: file I/O and input parsing assume well-formed input in many places; robust checks would improve stability.
- Data serialization: using a structured format (CSV with escaping or JSON) would make persistence safer and easier to parse.
- Input validation: string lengths and formats (ISBN, names) could be validated to avoid buffer overflows and unexpected behavior.
- Tests & CI: adding unit tests and a simple build/test workflow.

## Example session
- Add a book: choose "books operations -> Add a book" and fill ISBN/title/author/copies.
- Register a member: "member operations -> New register" and provide ID/name/phone.
- Borrow a book: "transactions operations -> Borrow a book" and provide Book title, Member ID and days.
- Return a book: "transactions operations -> Return a book" and see any overdue fee reported.

## Credits
Author: Abdelrahman-m-elshahed

---

If you'd like, I can:
- Open a PR that adds this README to your repository (I can create README.md here),
- Suggest small fixes to spots in the code (off-by-one, bounds checks, clearer input prompts), or
- Convert the file persistence to CSV or JSON for safer parsing.
