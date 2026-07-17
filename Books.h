#ifndef Books_H
#define Books_H

#include <stdio.h>
#include <stdbool.h>
#include "Storage.h"


#define Books_capacity 1000

struct Book{
    char * ISBN;
    char * title;
    char * author;
    int total_copies;
    int available_copies;  // borrowed copies = total - available
}books[Books_capacity];

int Books_size = -1;

bool check();

bool add(struct Book new_book);

bool remove(struct Book new_book);

int searchBook(const char* sISBN);

void booksList();

#endif