#ifndef Transaction_H
#define Transaction_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Books.h"
#include "Member.h"
#include <time.h>
#include "Storage.h"

#define borrowed_capacity 1000

struct Borrow_Record
{
    char R_ISBN[10];
    int R_id; 
    struct tm borrow_date;  // 30\12\2030
    struct tm due_date;
    bool returned; // 1 is borrwed
}extern Borrowed[borrowed_capacity];

extern int borrowed_size;

bool Borrow(const char* Book_name,int Member_ID,int days);

int return_book(const char* Book_Title);

int overdue_checks(int index);

int TransactionSearch(const char* R_ISBN);

#endif 