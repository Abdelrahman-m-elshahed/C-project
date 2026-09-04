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
    NUMSoL("Books_size.txt",true,LIBRARY);
    NUMSoL("Members_size.txt",true,MEMBERSHIP);
    NUMSoL("Transaction_size.txt",true,RECORD);

    Load("Library.txt",books,LIBRARY);         // books is array of type struct book defined in Books.h
    Load("Members.txt",members,MEMBERSHIP);    // members is array of type struct Member defined in Member.h
    Load("Record.txt",Borrowed,RECORD);        // Borrowed is array of type struct Borrow_Record defined in Transaction.h

    int i = true;

    do
    {
        char op;
        char BookTitle[100];

        printf("Select an option:\n");
        printf("%d. Books Operations\n",1);
        printf("%d. Member Operations\n",2);
        printf("%d. Transactions Operations\n",3);
        
        printf("-> ");
            scanf(" %c",&op);

        if(op =='1')
        {
            printf("Select an Operation:\n");
                printf("%d. Add a book\n",1);
                printf("%d. Remove a book\n",2);
                printf("%d. Search for a book\n",3);
                printf("%d. List books details\n",4);

            printf("-> ");
                scanf(" %c",&op);
                
                switch (op)
                {
                    case '1':
                        struct Book currBook;
                        printf("ISBN of the book\n");
                        printf("-> ");
                            scanf(" %s",currBook.ISBN);

                        printf("Title of the book\n");
                        printf("-> ");
                            scanf(" %s",currBook.title);
                        
                        printf("Author of the book\n");
                        printf("-> ");
                            scanf(" %s",currBook.author);
                        
                        printf("Total copies of the book\n");
                        printf("-> ");
                            scanf(" %d",&(currBook.total_copies));

                        printf("Available copies of the book\n");
                        printf("-> ");
                            scanf(" %d",&(currBook.available_copies));

                        if(add(currBook))
                            printf("The booke is added successfully\n");
                        else 
                            printf("Sorry,there is no space on the shelves to add the book\n");    
                        break;

                    case '2':
                        printf("Enter the name of the book you want to remove\n");
                        printf("-> ");
                            scanf(" %s",BookTitle);

                        if(removeBook(BookTitle))
                            printf("We have removed the book successfully\n");
                        else
                            printf("We couldn't remove the book\n");
                        break;
                    
                    case '3':
                        printf("Enter the name of the book you want to find its index\n");
                        printf("-> ");
                            scanf(" %s",BookTitle);

                            int index = searchBook(BookTitle);
                            if(index < 0)
                                printf("Sorry, we don't have that book.\n");
                            else
                                printf("The index of the book is %d\n", index);
                        break;

                    case '4':
                        booksList();
                        break;
                }
        }
        else if(op == '2')
        {
            printf("Select an Operation:\n");
                printf("%d. New register\n",1);
                printf("%d. Show member list\n",2);
                printf("%d. Look for a member\n",3);

            printf("-> ");
                scanf(" %c",&op);

            switch (op)
            {
                case '1':
                    struct Member NewMember;
                    printf("The ID of the new member\n");
                    printf("-> ");
                        scanf(" %d",&(NewMember.memberID));
                    
                    printf("The name of the new member\n");
                    printf("-> ");
                        scanf(" %s",NewMember.name);
                    
                    printf("The phone number of the new member\n");
                    printf("-> ");
                        scanf(" %s",NewMember.phoneNumber);
                    
                    if(Registeration(NewMember))
                        printf("Registeration is done successfully\n");
                    else    
                        printf("505\n");
                    
                    break;

                case '2':
                    membersList();
                    break;

                case '3':
                    printf("Enter the ID of the Member You 're looking for\n");
                    printf("-> ");
                        int id;
                        scanf(" %d",&id);
                        FindMember(id);
                    break;
            }
        }
        else if(op == '3')
        {   
            printf("Select an Operation:\n");
                printf("%d. Borrow a book\n",1);
                printf("%d. Return a book\n",2);

            printf("-> ");  
                scanf(" %c",&op);

            switch (op)
            {
                case '1':
                    printf("Enter the book name, Memeber's ID, and the period of time you need the book\n");
                    printf("-> ");
                        int id,day;
                        scanf(" %s %d %d",BookTitle,&id,&day);
                        Borrow(BookTitle, id,day);
                    break;
                
                case '2':
                    printf("Enter the title of the book you want to return\n");
                    printf("-> ");
                        scanf(" %s",BookTitle);
                    int fees = return_book(BookTitle);

                    if(fees == -2)
                        printf("This book doesn't exist\n");
                    else if(fees == -1)
                        printf("This book was not borrowed\n");
                    else if(fees == 0)
                        printf("There is no fees to pay\n");
                    else
                        printf("You have to pay %d EGP",fees);
                    break;
            }

        }
        else    
            printf("Incorrect selection\n");
        
        printf("Do you want to perform any other operation?(y\\n)\n");
            scanf(" %c",&op);
        
        if((char)tolower(op) == 'n')
        {
            NUMSoL("Books_size.txt",false,LIBRARY);
            NUMSoL("Members_size.txt",false,MEMBERSHIP);
            NUMSoL("Transaction_size.txt",false,RECORD);
            
            Savedata("Library.txt",books,LIBRARY);         // books is array of type struct book defined in Books.h
            Savedata("Members.txt",members,MEMBERSHIP);    // members is array of type struct Member defined in Member.h
            Savedata("Record.txt",Borrowed,RECORD);        // Borrowed is array of type struct Borrow_Record defined in Transaction.h
            
            i = false;
        }

    }while(i);

}
