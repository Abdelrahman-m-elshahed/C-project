#include "Member.h"

struct Member members[member_capactiy];
int member_size = -1;

bool Membercheck()
{
    if(member_size == -1)
        return 0;
    return 1;
}

bool Registeration(struct Member newMember)
{
    // if member size is 1000 then the index would be 1001
    
    if(member_size == member_capactiy -1) 
        return 0;
        
    members[member_size + 1] = newMember;
    member_size++;
    
    Savedata("Members.txt",members,MEMBERSHIP);
    return 1;
}

void membersList()
{
    if(!Membercheck())
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
void FindMember(int sID)
{
    printf("The member's name is %s\n The member's phone number is %s\n",members[sID - 1].name,members[sID - 1].phoneNumber); // sID starts from 1 , so we have to subtract 1         
}

