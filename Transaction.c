#include "Transaction.h"

int dayMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Borrow(struct Book curr_book,const char * Member_ISBN,int days)
{
    if(curr_book.available_copies == 0)
        return 0;
    
     Borrowed[borrowed_size + 1].R_ISBN = curr_book.ISBN;
     Borrowed[borrowed_size + 1].R_id = Member_ISBN;
     
     
     
     time_t t = time(NULL);
     struct tm date = *localtime(&t);
     #if 0
     Borrowed[borrowed_capacity + 1].due_date = ;
     #endif
     int dueMonth = date.tm_mon + 1;
     sprintf(Borrowed[borrowed_size + 1].borrow_date,"%02d-%02d-%2d",date.tm_mday,dueMonth,date.tm_year + 1900);

     int dueDate = date.tm_mday + days;
     
     if(dueDate > dayMonth[date.tm_mon])
     {
        dueDate -= dayMonth[date.tm_mon];
        dueMonth +=1;
     }
     sprintf(Borrowed[borrowed_size + 1].due_date,"%02d-%02d-%2d",dueDate,dueMonth,date.tm_year + 1900);
     
     Borrowed[borrowed_size + 1].returned = 1;
    --curr_book.available_copies;
    return 1;
}



bool return_book(struct Book curr_book)
{
    int index = search(curr_book.ISBN);
    Borrowed[index].returned = 0;
    ++curr_book.available_copies;
    
    for(int i = index + 1;i <= borrowed_size;++i)
        Borrowed[i - 1] = Borrowed[i];
    
    --borrowed_size;

}


int overdue_checks(const * R_ISBN)
{
   int index = search(R_ISBN);
    int extra = Borrowed[index].due_date - Borrowed[index].borrow_date;
        
    if(extra >= 0) 
        return 10 * extra;
    
    return -1;
}

int search(const * R_ISBN)
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
