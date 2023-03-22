#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#ifdef _WIN32
    #include <windows.h>
//#else
    //#include <unistd.h>
int voterscounts=0,voteparty[5]={0,0,0,0,0};
struct voters
{
char prn[15];
char name[30];
char password[10];
int votecast;
char castparty[10];
}v[100];
struct candidates
{
char partyname[30];
char description[1000];
char candidate[30];
}c[4];
int viewlists()
{
    printf("\e[1;1H\e[2J");
    int k=0,m=0;
e : printf("If you want to view the list of Voters, enter 1.\nIf you want to view the list of Candidates, enter 2.\n");
    scanf("%d",&k);
    if(k==1)
    {
        if(voterscounts==0) {
            printf("\e[1;1H\e[2J");
            printf("The voters list is empty! Please enter the details of voters in order to view them.\n");
            sleep(4);
            printf("\e[1;1H\e[2J"); }
        else
        {
            printf("\e[1;1H\e[2J");
            for(int j=0;j<voterscounts;j++)
            {   
                printf("Name : %s\nPRN  : %s\n",v[j].name,v[j].prn);
                printf("\n");
            }
        }
    }
    else if(k==2)
    {
        printf("\e[1;1H\e[2J");
        for(int j=0;j<4;j++)
        {   
            printf("%d)",j+1);
            printf(" Name       : %s\n",c[j].candidate);
            printf("   Party Name : %s\n",c[j].partyname);
            printf("   Info       : %s\n",c[j].description);
            printf("\n");
        }
    }
    else
    {
        printf("Choose a number from the provided options.\n");
        goto e;
    }
f : printf("If you want to go back to the main menu, enter 1.\n");
    scanf("%d",&m);
    printf("\e[1;1H\e[2J");
    if(m==1)
    return 1;
    else 
    printf("Enter a valid number!\n");
    goto f;
}
int listedit()
{
    int k=0,m=0,n1,z,y;
a : printf("If you want to view the list of voters before editing, enter 1.\nIf you want to directly edit the list, enter 2.\n");
    scanf("%d",&k);
    printf("\e[1;1H\e[2J");
    switch(k)
    {
        case 1:n1=viewlists() ;
        goto l;
        break;
        case 2:goto l;
        break;
        default:printf("Enter a number from the provided options.\n");
        goto a;
        break;
    }
    int voteradd()
    {
        printf("\e[1;1H\e[2J");
       char name[30],prn[15],password[10];
       printf("Enter the voter's name : ");
       scanf("%s",name);
       strcpy(v[voterscounts].name,name);
       printf("\nEnter the voter's prn : ");
       scanf("%s",prn);
       strcpy(v[voterscounts].prn,prn);
       printf("\nEnter the voter's password : ");
       scanf("%s",password);
       strcpy(v[voterscounts].password,password);
       printf("\nVoter's details added successfully!\n");
       sleep(4);
       printf("\e[1;1H\e[2J");
       voterscounts++;
       int readd=0;
       o : printf("If you want to go back the to main menu, enter 1.\nIf you want go back to the previous menu, enter 2.\n");
       scanf("%d",&readd);
       printf("\e[1;1H\e[2J");
       switch(readd)
       {
           case 1:return 2;
           break;
           case 2:return 1;
           break;
           default:printf("Please enter a number from the provided options.\n");
           goto o;
           break;
       } 
    }
l : printf("If you want add a voter, enter 1.\n");
    scanf("%d",&m);
    switch(m)
    {
        case 1:if(voterscounts>99)
        {
            printf("Max limit of voters reached!\n");
            goto ef;
        }
        z=voteradd();
        if(z==2)
        goto ef;
        else if(z==1)
        goto l;
        break;
        default:printf("Enter a valid number from the provided options.\n");
        goto l;
        break;
    }
ef : return 1;
}
void results()
{
    printf("\e[1;1H\e[2J");
    int i,j,t;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(voteparty[j]>voteparty[j+1])
            {
                t=voteparty[j];
                voteparty[j]=voteparty[i+1];
                voteparty[j+1]=t;
            }
        }
    }
    printf("The Election results are as follows : \n\n");
    printf("The winner of the elections is %s.\nThe winning party is %s.\n",c[voteparty[5]].candidate,c[voteparty[5]].partyname);
    printf("Thank You. :) ");
    exit(0);
}
int votingsystem()
{
    printf("\e[1;1H\e[2J");
    if(voterscounts==0)
    {
        printf("The voters list is empty! Before initiating the voting process, please enter the details of the voters.\n");
        sleep(4);
        printf("\e[1;1H\e[2J");
        return 0;
    }
    char prn[15],name[30],password[10],check;
    int votes=0,thevote=0;;
    int ocount,tcount,thcount,e,votedone;
j : printf("Enter your PRN : ");
    thcount=votes;
    scanf("%s",prn);
    printf("Enter your Name : ");
    scanf("%s",name);
    printf("Enter your Password : ");
    scanf("%s",password);
    votes=0;
    thevote=0;
    for(int m=0;m<=voterscounts;m++)
    {
        if (strcmp(v[m].prn,prn))
        {
            if (strcmp(v[m].name,name))
            {
                if (strcmp(v[m].password,password))
                    {
                        if(v[m].votecast==1)
                        {
                            printf("You have already casted your vote!\n");
                            sleep(4);
                            printf("\e[1;1H\e[2J");
                            goto ll;
                        }
                        else
                        {
                        cc :printf("\e[1;1H\e[2J");printf("Candidate's List :\n");
                            for(int j=0;j<4;j++)
                            {   
                                printf("%d)\n",j+1);
                                printf("   Name    : %s\n",c[j].candidate);
                                printf("Party Name : %s\n",c[j].partyname);
                                printf("   Info    : %s\n",c[j].description);
                                printf("\n");
                            }
                        cb :printf("Enter your choice by typing the number corresponding to the party you want to vote .\n");
                            scanf("%d",&thevote);
                            printf("\e[1;1H\e[2J");
                            switch(thevote)
                            {
                                case 1:printf("You have voted for the party : %s.\nTo confirm enter 'Y' if not enter 'N'.\n",c[thevote-1].partyname);
                                scanf("%s",&check);
                                printf("\e[1;1H\e[2J");
                                if(check=='Y')
                                {
                                    thevote=1;
                                    printf("Vote casted!\n");
                                    sleep(4);
                                    printf("\e[1;1H\e[2J");
                                    v[m].votecast=1;                                    
                                }
                                else
                                {
                                    goto cc;
                                    thevote=0;
                                }
                                break;
                                case 2:printf("You have voted for the party : %s.\nTo confirm enter 'Y' if not enter 'N'.\n",c[thevote-1].partyname);
                                scanf("%s",&check);
                                printf("\e[1;1H\e[2J");
                                if(check=='Y')
                                {
                                    thevote=2;
                                    printf("Vote casted!\n");
                                    sleep(4);
                                    printf("\e[1;1H\e[2J");
                                    v[m].votecast=1;                                    
                                }
                                else
                                {
                                    goto cc;
                                    thevote=0;
                                }
                                break;
                                case 3:printf("You have voted for the party : %s.\nTo confirm enter 'Y' if not enter 'N'.\n",c[thevote-1].partyname);
                                scanf("%s",&check);
                                printf("\e[1;1H\e[2J");
                                if(check=='Y')
                                {
                                    thevote=3;
                                    printf("Vote casted!\n");
                                    sleep(4);
                                    printf("\e[1;1H\e[2J");
                                    v[m].votecast=1;                                    
                                }
                                else
                                {
                                    goto cc;
                                    thevote=0;
                                }
                                break;
                                case 4:printf("You have voted for the party : %s.\nTo confirm enter 'Y' if not enter 'N'.\n",c[thevote-1].partyname);
                                scanf("%s",&check);
                                printf("\e[1;1H\e[2J");
                                if(check=='Y')
                                {
                                    thevote=4;
                                    printf("Vote casted!\n");
                                    sleep(4);
                                    printf("\e[1;1H\e[2J");
                                    v[m].votecast=1;
                                }
                                else    
                                {   
                                    goto cc;
                                    thevote=0;
                                }
                                break;
                                default:printf("Enter a number from the provided options.");
                                goto cb;
                                break;
                                }
                            votes=1;
                            switch(thevote)
                            {
                                case 1:voteparty[1]++;
                                strcpy(v[m].castparty,c[0].partyname);
                                break;
                                case 2:voteparty[2]++;
                                strcpy(v[m].castparty,c[1].partyname);
                                break;
                                case 3:voteparty[3]++;
                                strcpy(v[m].castparty,c[2].partyname);
                                break;
                                case 4:voteparty[4]++;
                                strcpy(v[m].castparty,c[4].partyname);
                                break;
                                default :break;
                            }
                            break;
                        }
                    }
            }
        }
    } 
    if (votes==1)
    goto ll;
    else
    {
        printf("Enter valid credentials .\n");
        goto j;
    }
ll: printf("If you want to cast a vote, enter 1.\nIf you want to go back to the main menu, enter 2.\nIf you want to end the election and get the results, enter 3.\n"); 
    int eee=0;
    scanf("%d",&eee);
    switch(eee)
    {
        case 1:goto j;
        break;
        case 2:goto z;
        break;
        case 3:results();
        printf("Voting completed!\n");
        break;
        default:printf("Enter a number from the provided options.\n");
                goto ll;
                break;
    }
z :return 0;
    
}
int main()
{
    strcpy(c[0].partyname,"RUBY");
    strcpy(c[1].partyname,"EMERALD");
    strcpy(c[2].partyname,"PEARL");
    strcpy(c[3].partyname,"SAPPHIRE");
    strcpy(c[0].candidate,"SRIKHAR");
    strcpy(c[1].candidate,"NAVEEN");
    strcpy(c[2].candidate,"YASIR");
    strcpy(c[3].candidate,"NISCHITH");
    int a,n=1,b1,b2,b3,j;
    int votercount=0;
    printf("\e[1;1H\e[2J");
    while(n)
    {
zz :printf("If you want to edit the list of voters, enter 1.\nIf you want to view the voters list and candidates list, enter 2.\nIf you want to start the election, enter 3.\n");
    scanf("%d",&a);
    if(a==1) {
        printf("\e[1;1H\e[2J");
        b1=listedit(); 
    }
    else if(a==2) {
        printf("\e[1;1H\e[2J");
        b2=viewlists();
    }
    else if(a==3)
    {
        printf("\e[1;1H\e[2J");
        b3=votingsystem();
        z : printf("\e[1;1H\e[2J");printf("If you want to exit, enter 1.\nIf you want to continue, enter 2.\nIf you want to go to the main menu, enter 3.\n");
        scanf("%d",&j);
        printf("\e[1;1H\e[2J");
        if(j==1)
        break;
        else if(j==2)
        goto z;
        else if(j==3)
        goto zz;
        else
        {
        printf("Enter a number from the provided options.\n");
        goto z;
        }
    }
    else
    {
    printf("Enter a number from the provided options.\n");
    goto zz;
    }
    }
    return 0;
}