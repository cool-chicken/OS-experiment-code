#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

#define Maxsize 10

int hisnum=0;
char history[Maxsize][20];
int run=1;
int main()
{
   char input[256];
   char *command,*emp;
   while(run)
   {
    printf("osh>");
    int ready=1;
    fgets(input,256,stdin);
    input[strlen(input)-1]=0;
    command=strtok(input," ");
    emp=strtok(NULL," ");
    if(command!= NULL)
    {
       if(!strcmp(command, "history"))   
       {
        ready=0;
        if(hisnum==0)printf("No commands in history\n");
        else
        {
            for (int i = hisnum; i>=hisnum-9&&i>=1; i--)
            {
                printf("%d: %s\n",i,history[(i-1)%10]);
            }
        }
       }
       else if(!strcmp(command, "!!"))
       {
        if(hisnum==0)printf("No commands in history\n");
        else
        {
            printf("%d: %s\n",hisnum,history[(hisnum-1)%10]);
            strcpy(command,history[(hisnum-1)%10]);
        }
       }
       else if(command[0]=='!' && isdigit(command[1]))
        {
            if (command[1]>='0' && command[1]<='9')
            {
                printf("history[%d]: %s\n",command[1]-'0',history[(hisnum-1)%10-command[1]+'0']);
                strcpy(command,history[(hisnum-1)%10-command[1]+'0']);
            }
            else
            {
                printf("Invalid command\n");
            }
        }  
        else if(!strcmp(command, "exit"))
        {
            run=0;ready=0;
        }
        else
        {
        strcpy(history[hisnum%10],command);
        printf("%s\n",history[hisnum%10]);
        hisnum++;
        }
    }
    if (ready==1)
    {
      if(fork()==0)
    {
      execlp(command,command,NULL);
      perror(command);
      exit(1);
    }
    else{
    if(emp==NULL||strcmp(emp,"&")!=0)
    wait(NULL);
    }}}
  return 0;
}