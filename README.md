Library Management System
A modular, console-based Library Management System written in C. The application enables users to manage a catalog of books, register library members, and track borrowing and return transactions with automatic overdue fee calculation and file-based data persistence.


Features
1. Book Management (Books.c / Books.h)
Add Book: Add new titles with unique ISBNs, author names, total copies, and available stock.
Remove Book: Delete existing records by book title.
Search Book: Find the shelf index of a book by title.
List Books: Display detailed information for all cataloged books.
2. Member Management (Member.c / Member.h)
Register Member: Register new members with a unique Member ID, name, and phone number.
Member Directory: View all registered library members.
Find Member: Query member details by Member ID.
3. Borrowing & Transactions (Transaction.c / Transaction.h)
Borrow Books: Issue books to registered members for a designated number of days, automatically adjusting stock and computing due dates.
Return Books: Process returns, restock inventory, and calculate overdue penalties (10 EGP per overdue period).
4. Data Persistence (Storage.c / Storage.h)
Automatically loads catalog, member, and borrowing records on startup from text files.
Writes all updates back to disk upon exiting the program:
Library.txt & Books_size.txt
Members.txt & Members_size.txt
Record.txt & Transaction_size.txt


File Structure
├── Books.c             # Book operations implementation

├── Books.h             # Book structures and function prototypes

├── Member.c            # Member operations implementation

├── Member.h            # Member structures and function prototypes

├── Transaction.c       # Borrowing and return operations implementation

├── Transaction.h       # Transaction structures and function prototypes

├── Storage.c           # File reading and writing implementation

├── Storage.h           # Storage enum and file helper prototypes

├── Main.c              # Main application loop and CLI menu interface

└── README.md           # Project documentation


Requirements & Compilation
Prerequisites
A C compiler supporting C99 or later (such as gcc or clang).
Build Instructions
Compile all .c files using gcc:

gcc Main.c Books.c Member.c Transaction.c Storage.c -o library_system


How to Run
Execute the compiled binary:

./library_system

Navigate the system using the numbered menu prompts:
1. Books Operations: Add, remove, search, or list books.
2. Member Operations: Register, list, or look up members.
3. Transactions Operations: Borrow or return a book.
Select n when prompted to exit and save all records to disk.


System Capacities & Limits
Maximum Books: 1,000 titles
Maximum Members: 300 members
Maximum Active Transactions: 1,000 records

