#include "Storage.h"

FILE* fptr; 


void NUMSoL(const char * filename,bool SoL,enum Type tp)
{
    if(SoL == 1)
    {
        fptr = fopen(filename,"r");
        if(fptr == NULL)
            return;    

        if(tp == LIBRARY)
            fscanf(fptr,"%d",&Books_size);
        
        else if(tp == MEMBERSHIP)
            fscanf(fptr,"%d",&member_size);
        
        else if(tp == RECORD)
            fscanf(fptr,"%d",&borrowed_size);  
        }
        else
        {
            fptr = fopen(filename,"w");
            if(fptr == NULL)
            return;
            
            if(tp == LIBRARY)
                fprintf(fptr,"%d",Books_size);
            
            else if(tp == MEMBERSHIP)
                fprintf(fptr,"%d",member_size);
            
            else if(tp == RECORD)
                fprintf(fptr,"%d",borrowed_size);
        }

        fclose(fptr);
}

void Load(const char * fileName ,void * data,enum Type tp)
{
    fptr = fopen(fileName,"r");
    if(fptr == NULL) 
        return;

    if(tp == LIBRARY)
    {
        for(int i = 0 ; i <= Books_size;++i)
        {
            struct Book *BK = ((struct Book*) data) + i;
            fscanf(fptr, "%s  %s  %s  %d  %d",BK->ISBN,BK->title,BK->author,&BK->total_copies,&BK->available_copies);
        }
    }
    else if(tp == MEMBERSHIP)
    {
        for(int i = 0 ; i <= member_size;++i)
        {
            struct Member *MB = ((struct Member*) data) + i;
            fscanf(fptr, "%d  %s  %s",&MB->memberID,MB->name,MB->phoneNumber);
        }
    }
    else if(tp == RECORD)
    {
        for(int i = 0 ; i <= borrowed_size;++i)
        {
            struct Borrow_Record *BR = ((struct Borrow_Record*) data) + i;
            fscanf(fptr, "%s  %d  %d-%d-%d  %d-%d-%d  %d",BR->R_ISBN,&BR->R_id,&BR->borrow_date.tm_mday,&BR->borrow_date.tm_mon,&BR->borrow_date.tm_year,&BR->due_date.tm_mday,&BR->due_date.tm_mon,&BR->due_date.tm_year,&BR->returned);
        }
    }

    fclose(fptr);
}   

#if 0
void Savedata(const char * fileName ,void * data,enum Type tp)
{
    fptr = fopen(fileName,"a");
    if(fptr == NULL) 
        return;

    if(tp == LIBRARY && Books_size != -1)
    {
            struct Book BK = *((struct Book*) data);
            fprintf(fptr, "%s  %s  %s  %d  %d\n",BK.ISBN,BK.title,BK.author,BK.total_copies,BK.available_copies);
    }
    else if(tp == MEMBERSHIP && member_size != -1)
    {
        struct Member MB = *((struct Member*) data );
        fprintf(fptr, "%d  %s  %s\n",MB.memberID,MB.name,MB.phoneNumber);
    }
    else if(tp == RECORD && borrowed_size != -1)
    {
        struct Borrow_Record BR = *((struct Borrow_Record*) data);
        fprintf(fptr, "%s  %d  %d-%d-%d  %d-%d-%d  %d",BR.R_ISBN,BR.R_id,BR.borrow_date.tm_mday,BR.borrow_date.tm_mon,BR.borrow_date.tm_year,BR.due_date.tm_mday,BR.due_date.tm_mon,BR.due_date.tm_year,BR.returned);
    }
    
    fclose(fptr);
}
#endif

void Savedata(const char * fileName ,void * data,enum Type tp)
{
   fptr = fopen(fileName,"w");
    if(fptr == NULL) 
        return;

    if(tp == LIBRARY && Books_size != -1)
    {
        for(int i = 0 ; i <= Books_size; ++i)
        {
            struct Book BK = *((struct Book*) data + i);
            fprintf(fptr, "%s  %s  %s  %d  %d\n",BK.ISBN,BK.title,BK.author,BK.total_copies,BK.available_copies);
        }
    }
    else if(tp == MEMBERSHIP && member_size != -1)
    {
        for(int i = 0; i <= member_size;++i)
        {
            struct Member MB = *((struct Member*) data + i);
            fprintf(fptr, "%d  %s  %s\n",MB.memberID,MB.name,MB.phoneNumber);
        }
    }
    else if(tp == RECORD)
    {
        for(int i = 0 ; i <= borrowed_size;++i)
        {
            struct Borrow_Record BR = *((struct Borrow_Record*) data + i);
            fprintf(fptr, "%s  %d  %d-%d-%d  %d-%d-%d  %d",BR.R_ISBN,BR.R_id,BR.borrow_date.tm_mday,BR.borrow_date.tm_mon,BR.borrow_date.tm_year,BR.due_date.tm_mday,BR.due_date.tm_mon,BR.due_date.tm_year,BR.returned);
        }
    }
    
    fclose(fptr);  
}