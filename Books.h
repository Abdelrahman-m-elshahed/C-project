#ifndef Books_H
#define Books_H


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Storage.h"


#define Books_capacity 1000

struct Book{
    char ISBN[10];
    char title[10];
    char author[10];
    int total_copies;
    int available_copies;  // borrowed copies = total - available
}extern books[Books_capacity];

extern int Books_size;

bool Bookcheck();

bool add(struct Book new_book);

bool removeBook(char* rTitle);

int searchBook(const char* sTitle);

void booksList();

#endif