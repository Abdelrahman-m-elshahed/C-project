#ifndef member_H
#define member_H

#include <stdio.h>
#include <stdbool.h>
#include "Storage.h"

#define member_capactiy 300

struct Member
{
    int memberID;
    char* name;
    char phoneNumber[15]; // so u can change it later
}members[member_capactiy];

int member_size = -1;

bool check();

bool Registeration(struct Member newMember);

void membersList();

struct Member search(int sID);

#endif