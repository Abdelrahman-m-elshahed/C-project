#ifndef member_H
#define member_H

#include <stdio.h>
#include <stdbool.h>
#include "Storage.h"


#define member_capactiy 300

struct Member
{
    int memberID;
    char name[10];
    char phoneNumber[15]; // so u can change it later
}extern members[member_capactiy];

extern int member_size;

bool Membercheck();

bool Registeration(struct Member newMember);

void membersList();

void FindMember(int sID);

#endif