#include "Books.h"
    
bool check()
{
    if(Books_size == -1)
        return 0;
    return 1;
}

bool add(struct Book new_book)
{   
    if(Books_size  > Books_capacity)
        return 0;
    
    books[Books_size + 1] = new_book;
    Books_size++;

    return 1;
}

bool remove(struct Book new_book)
{ 
    if(!check())
        return 0;
    
    int index = search(new_book.ISBN);

    for(int i = index + 1 ; i <= Books_size; ++i)
        books[i - 1] = books[i];
    
    Books_size--;

    return 1;
}

int searchBook(char* sISBN)
{
    for(int i = 0 ; i <= Books_size;++i)
    {
        if(sISBN == books[i].ISBN)
            return i; // returning the position of the book 
    }
} 

void booksList()
{
    
    if(!check())
    {
        printf("There is no Available Books yet!\n");
        return;
    }

    printf("Books\n");

    for(int i =0 ; i <= Books_size;++i)
    {
        printf("ISBN %s\n",books[i].ISBN);
        printf("Title of the Book %s\n",books[i].title);
        printf("Author Name %s\n",books[i].author);
        printf("total number of books %d\n",books[i].total_copies);
        printf("Available books to borrow %d\n",books[i].available_copies);
        printf("\n");
    }
}