#include "Storage.h"
FILE* fptr; 

void Load(const char * fileName ,void * data,enum Type tp)
{
    fptr = fopen(fileName,"r");
    if(fptr == NULL) 
        return;
    if(tp == LIBRARY)
    {
        for(int i = 0 ; i < Books_size;++i)
        {
            struct Book *BK = (struct Book*) (data + i);
            fscanf(fptr, "%s  %s  %s  %d  %d",BK->ISBN,BK->title,BK->author,BK->total_copies,BK->available_copies);
        }
    }
    else if(tp == MEMBERSHIP)
    {
        for(int i = 0 ; i < member_size;++i)
        {
            struct Member *MB = (struct Member*) (data + i);
            fscanf(fptr, "%d  %s  %s",MB->memberID,MB->name,MB->phoneNumber);
        }
    }
    
    else if(tp == RECORD)
    {
        for(int i = 0 ; i < borrowed_size;++i)
        {
            struct Borrow_Record *BR = (struct Borrow_Record*) (data + i);
            fscanf(fptr, "%s %d %S %s %B",BR->R_ISBN,BR->R_id,BR->borrow_date,BR->due_date,BR->returned);
        }
    }
    
    fclose(fptr);
}   

void Save(const char * fileName ,void * data,enum Type tp)
{
    fptr = fopen(fileName,"a");
        if(fptr == NULL) 
        return;
    if(tp == LIBRARY)
    {
            struct Book BK = *((struct Book*) data);
            fprintf(fptr, "%s  %s  %s  %d  %d\n",BK.ISBN,BK.title,BK.author,BK.total_copies,BK.available_copies);
    }
    else if(tp == MEMBERSHIP)
    {
        struct Member MB = *((struct Member*) data );
        fprintf(fptr, "%d  %s  %s\n",MB.memberID,MB.name,MB.phoneNumber);
    }
    
    else if(tp == RECORD)
    {
        struct Borrow_Record BR = *((struct Borrow_Record*) data);
        fprintf(fptr, "%s %d %S %s %B\n",BR.R_ISBN,BR.R_id,BR.borrow_date,BR.due_date,BR.returned);
    }
    
    fclose(fptr);
}