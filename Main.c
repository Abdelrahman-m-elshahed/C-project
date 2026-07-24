#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Books.h"
#include "Member.h"
#include "Transaction.h"
#include "Storage.h"


int main()
{
    Load("Library.txt",books,LIBRARY);         // books is array of type struct book defined in Books.h
    Load("Members.txt",members,MEMBERSHIP);    // members is array of type struct Member defined in Member.h
    Load("Record.txt",Borrowed,RECORD);        // Borrowed is array of type struct Borrow_Record defined in Transaction.h

    int i = true;

    do
    {
        char op;
        char BookTitle[100];

        printf("select an option:\n");
        printf("%d. books operations\n",1);
        printf("%d. member operations\n",2);
        printf("%d. transactions operations\n",3);
        scanf(" %c",&op);

        if(op =='1')
        {
            printf("%d. Add a book\n",1);
            printf("%d. Remove a book\n",2);
            printf("%d. Search for a book\n",3);
            printf("%d. List books details\n",4);

            printf("your choice is ");
                scanf(" %c",&op);
                
                switch (op)
                {
                    case '1':
                        struct Book currBook;
                        printf("ISBN of the book\n");
                            scanf(" %s",currBook.ISBN);

                        printf("Title of the book\n");
                            scanf(" %s",currBook.title);
                        
                        printf("author of the book\n");
                            scanf(" %s",currBook.author);
                        
                        printf("total copies of the book\n");
                            scanf(" %d",&(currBook.total_copies));

                        printf("available copies of the book\n");
                            scanf(" %d",&(currBook.available_copies));

                        if(add(currBook))
                            printf("the booke is added successfully\n");
                        else 
                            printf("Sorry,there is no space on the shelves to add the book\n");    
                        break;

                    case '2':
                        printf("Enter the name of the book you want to remove\n");
                            scanf(" %s",BookTitle);

                        if(removeBook(BookTitle))
                            printf("we have removed the book successfully\n");
                        else
                            printf("we couldn't remove the book\n");
                        break;
                    
                    case '3':
                        printf("Enter the name of the book you want to find its index\n");
                            scanf(" %s",BookTitle);
                            printf("the index of the book is %d", searchBook(BookTitle));
                        break;

                    case '4':
                        booksList();
                        break;
                }
        }
        else if(op == '2')
        {
            printf("%d. New register\n",1);
            printf("%d. Show member list\n",2);
            printf("%d. Look for a member\n",3);

            printf("your choice is ");
                scanf(" %c",&op);

            switch (op)
            {
                case '1':
                    struct Member NewMember;
                    printf("The ID of the new member\n");
                        scanf(" %d",&(NewMember.memberID));
                    printf("The name of the new member\n");
                        scanf(" %s",NewMember.name);
                    printf("The phone number of the new member\n");
                        scanf(" %s",NewMember.phoneNumber);
                    
                    Registeration(NewMember);
                    break;

                case '2':
                    membersList();
                    break;

                case '3':
                    printf("Enter the ID of the Member You 're looking for\n");
                        int id;
                        scanf(" %d",&id);
                        FindMember(id);
                    break;
            }
        }
        else if(op == '3')
        {   
            printf("%d. Borrow a book\n",1);
            printf("%d. Return a book\n",2);

            printf("your choice is ");  
                scanf(" %c",&op);

            switch (op)
            {
                case '1':
                    printf("Enter the book name, Memeber's ID, and the period of time you need the book\n");
                        int id,day;
                        scanf(" %s %d %d",BookTitle,&id,&day);
                        Borrow(BookTitle, id,day);
                    break;
                
                case '2':
                    printf("Enter the title of the book you want to return\n");
                        scanf(" %s",BookTitle);
                    int fees = return_book(BookTitle);
                    if(fees == -1)
                        printf("there is no fees to pay\n");
                    else
                        printf("You have to pay %d EGP",fees);
                    break;
            }

        }
        else    
            printf("Incorrect selection\n");
        
        printf("do you want to perform any other operation?(y\\n)\n");
            scanf(" %c",&op);
        
        if((char)tolower(op) == 'n')
            i = false;

    }while(i);


    
}