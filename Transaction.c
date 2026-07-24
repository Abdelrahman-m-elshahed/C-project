#include "Transaction.h"

struct Borrow_Record Borrowed[borrowed_capacity];
int borrowed_size = -1;

int dayMonth[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Borrow(const char* Book_name,int Member_ID,int days)
{
    if(books[searchBook(Book_name)].available_copies == 0)
        return 0;
    
    if(borrowed_size == borrowed_capacity -1)
        return 0;
    
    int index = searchBook(Book_name);
    if(index == -1)
        return 0;

     strcpy(Borrowed[borrowed_size + 1].R_ISBN, books[index].ISBN);
     Borrowed[borrowed_size + 1].R_id = Member_ID;
     
     
     
     time_t t = time(NULL);
     struct tm date = *localtime(&t);
     #if 0
     Borrowed[borrowed_capacity + 1].due_date = ;
     #endif
     int dueMonth = date.tm_mon + 1;
     Borrowed[borrowed_size + 1].borrow_date.tm_mday =date.tm_mday;
     Borrowed[borrowed_size + 1].borrow_date.tm_mon =date.tm_mon;
     Borrowed[borrowed_size + 1].borrow_date.tm_year =date.tm_year + 1900;
     
    
    int dueDate = date.tm_mday + days;
    if((date.tm_year + 1900) % 4 == 0)
        dayMonth[1] = 29;
    else
        dayMonth[1] = 28;
     
     if(dueDate > dayMonth[date.tm_mon])
     {
        dueDate -= dayMonth[date.tm_mon];
        dueMonth +=1;
     }
     
     Borrowed[borrowed_size + 1].due_date.tm_mday = dueDate;
     Borrowed[borrowed_size + 1].due_date.tm_mon = dueMonth;
     Borrowed[borrowed_size + 1].due_date.tm_year = date.tm_year + 1900;
     
     Borrowed[borrowed_size + 1].returned = 1;
    --books[searchBook(Book_name)].available_copies;
    borrowed_size++;
    
    Savedata("Record.txt",Borrowed,RECORD);
    return 1;
}



int return_book(const char* Book_Title)
{
    int index = searchBook(Book_Title);
    int Borrowed_index = TransactionSearch((char *)books[index].ISBN); // ISBN is an array and the parameter is an char *
    Borrowed[Borrowed_index].returned = 0;
    ++books[index].available_copies;
    
    for(int i = Borrowed_index + 1;i <= borrowed_size;++i)
        Borrowed[i - 1] = Borrowed[i];
    
    --borrowed_size;

    return overdue_checks(Borrowed_index);

}

int overdue_checks(int index)
{

    time_t current =  time(NULL);
    time_t due = mktime(&(Borrowed[index].due_date));
    int extra = current - due;
        
    if(extra > 0) 
        return 10 * extra;
    
    return 0;
}
 

int TransactionSearch(const char* R_ISBN)
{
    int i = 0;
    while(i <= borrowed_size)
    {
        if(!strcmp(Borrowed[i].R_ISBN,R_ISBN))
            break;
        ++i;
    }
    return i;
}
