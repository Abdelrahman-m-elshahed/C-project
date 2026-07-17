#ifndef Transaction_H
#define Transaction_H

#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "books.h"
#include "member.h"
#include "Storage.h"

#define borrowed_capacity 1000

struct Borrow_Record
{
    char * R_ISBN;
    int R_id; 
    char borrow_date[11];  // 30\12\2030
    char due_date[11];
    bool returned; // 1 is borrwed
}Borrowed[1000];

int borrowed_size = -1;

bool Borrow(struct Book curr_book,const char * Member_ISBN,int days);

bool return_book(struct Book curr_book);

int overdue_checks(const * R_ISBN);

int search(const * R_ISBN);

#endif 