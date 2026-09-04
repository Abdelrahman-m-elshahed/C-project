#include "Books.h"

struct Book books[Books_capacity];
int Books_size = -1;

bool Bookcheck()
{
    if(Books_size == -1)
        return 0;
    return 1;
}

bool ISBN_Check(char * ISBN_b_checked)
{
    for(int i = 0 ; i <= Books_size;++i)
    {
        if(!(strcmp(ISBN_b_checked,books[i].ISBN)))
            return 0;
    }
    
    return 1;
}

bool add(struct Book new_book)
{   
    if(Books_size  == Books_capacity -1)
        return 0;
    if(!ISBN_Check(new_book.ISBN))
        return 0;

    if(new_book.total_copies < new_book.available_copies)
        return 0;
        
    books[Books_size + 1] = new_book;
    Books_size++;
    #if 0
    Savedata("Library.txt",&new_book,LIBRARY);
    #endif

    return 1;
}

bool removeBook(char* rTitle)
{ 
    if(!Bookcheck())
        return 0;
    
    int index = searchBook(rTitle);

    if(index == -1)
        return 0;

    for(int i = index + 1 ; i <= Books_size; ++i)
        books[i - 1] = books[i];
    
    Books_size--;

    return 1;
}

int searchBook(const char* sTitle)
{
    for(int i = 0 ; i <= Books_size;++i)
    {
        if(!strcmp(sTitle,books[i].title))
            return i; // returning the position of the book 
    }
    return -1;
} 

void booksList()
{
    
    if(!Bookcheck())
    {
        printf("There is no Available Books yet!\n");
        return;
    }

    printf("Books\n");

    for(int i =0 ; i <= Books_size;++i)
    {
        printf("ISBN : %s\n",books[i].ISBN);
        printf("Title of the Book : %s\n",books[i].title);
        printf("Author Name : %s\n",books[i].author);
        printf("total number of books : %d\n",books[i].total_copies);
        printf("Available books to borrow : %d\n",books[i].available_copies);
        printf("\n");
    }
    printf("Total number of books %d\n",Books_size+1);
}