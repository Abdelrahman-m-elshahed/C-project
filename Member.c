#include "Member.h"

bool check()
{
    if(member_size == -1)
        return 0;
    return 1;
}

bool Registeration(struct Member newMember)
{
    if(!check())
        return 0;
        
    members[member_size + 1] = newMember;
    member_size++;
    return 1;
}

void membersList()
{
    if(!check())
    {
        printf("There is no members yet!]n");
        return;
    }

    printf("Members\n");

    for(int i = 0;  i < member_size;++i)
    {
        printf("Member Name: %s",members[i].name);
        printf("Member Name: %d",members[i].memberID);
        printf("Member Name: %s",members[i].phoneNumber);
        printf("\n");
    }

}

struct Member search(int sID)
{
    return members[sID - 1]; // sID starts from 1 , so we have to subtract 1         
}

