#ifndef Storage_H
#define Storage_H

#include <stdio.h>
#include "Books.h"
#include "Member.h"
#include "Transaction.h"


enum Type {LIBRARY,MEMBERSHIP,RECORD};

void Load(const char * fileName ,void * data,enum Type tp);
void Savedata(const char * fileName ,void * data,enum Type tp);

#endif