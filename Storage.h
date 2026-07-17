#ifndef Storage_H
#define Storage_H

#include <stdio.h>
#include "Member.h"
#include "Books.h"
#include "Transaction.h"


enum Type {LIBRARY,MEMBERSHIP,RECORD};

void Load(const char * fileName ,void * data,enum Type tp);
void Save(const char * fileName ,void * data,enum Type tp);

#endif