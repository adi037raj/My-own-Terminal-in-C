#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<readline/readline.h> 
#include<readline/history.h>
#define pf printf
#define sf scanf

// use -lreadline to link;

void evaluate_for_cp(char *);
void evaluate_for_grep(char *);
void evaluate_for_mv(char *);

int main()
{
  char hostname[HOST_NAME_MAX];
  char username[LOGIN_NAME_MAX];
  char cwd[PATH_MAX];
  unsigned char * buff;
  
    while(1)
    {
    if (!gethostname(hostname, HOST_NAME_MAX)&& !getlogin_r(username, LOGIN_NAME_MAX) && (getcwd(cwd, sizeof(cwd)) == NULL))exit(0);
    pf("%s@%s:~%s ",username,hostname,cwd);
    buff=readline("");
   char buff1[50];
   if(strlen(buff)>0)
   {
   add_history(buff);//char *x=buff;
   strcpy(buff1,buff);
   //pf("beddffore %s ",buff1);
   
   char *token,*argv[20];
   argv[0]=token=strtok(buff," ");
   int i=1;
   
     
   
   while(token!=NULL)
   {
    
   token=argv[i]=strtok(NULL," ");
  //pf("\n %s",argv[i-1]);
   i++;
   }
   argv[i]='\0';
   //buff=x;
   //pf("%s ",x);
   strcpy(buff,buff1);
   if(strcmp(buff,"exit")==0)
   {
   pf("Bye Bye\n");
   return 0;
   }
   else if(strcmp(buff,"help")==0  || strcmp(buff,"--help")==0)
   {
   FILE *fp=fopen("help.txt","r");
   if(fp!=NULL)
   {
   char c;
   c=fgetc(fp);
   while(c!=EOF)
   {
   pf("%c",c);
   c=fgetc(fp);
   }
   
   
   }
   
   
   fclose(fp);
   continue;
   }
 
   
   else if(strlen(buff)>1 && buff[0]=='l' && buff[1]=='s') // for ls
   {
   char *cmd="ls_function";
   	if(fork()==0)
   	{
   	if(execve(cmd,argv,NULL)!=-1);
   	return 0;}
   	wait(NULL);
   	//evaluate_for_ls(argv);
   	continue;
   }
   
   else if(strlen(buff)>1 && buff[0]=='p' && buff[1]=='s') // for ps
   {
   system(buff);
   continue;
   }
   else if(strlen(buff)>1 && buff[0]=='c' && buff[1]=='p') //for cp
   {
   evaluate_for_cp(buff);
   continue;
   }
   else if( buff[0]=='m' && buff[1]=='v') // for mv
   {
   //pf("%s buuff",buff);
   evaluate_for_mv(buff);
   continue;
   }
   else if(buff[0]=='g' && buff[1]=='r' && buff[2]=='e' && buff[3]=='p') //for grep command
   {
   //pf("called");
   //pf("%s ",buff);
   evaluate_for_grep(buff);
   //pf("outt");
   continue;
   }
   
   else if( buff[0]=='m' && buff[1]=='a' && buff[2]=='n' && buff[4]=='l' && buff[5]=='s')
   {
   // man ls
   FILE *fp=fopen("ls_man.txt","r");
   if(fp!=NULL)
   {
   char c;
   c=fgetc(fp);
   while(c!=EOF)
   {
   pf("%c",c);
   c=fgetc(fp);
   }
   
   
   }
   
   
   fclose(fp);
   continue;
   }
   
   
   else if(buff[0]=='m' && buff[1]=='a' && buff[2]=='n' && buff[4]=='p' && buff[5]=='s')
   {
   // man ps
   system("man ps");
   continue;
   }
   
   else if(buff[0]=='m' && buff[1]=='a' && buff[2]=='n' && buff[4]=='c' && buff[5]=='p')
   {
   // man cp
   FILE *fp=fopen("cp_man.txt","r");
   if(fp!=NULL)
   {
   char c;
   c=fgetc(fp);
   while(c!=EOF)
   {
   pf("%c",c);
   c=fgetc(fp);
   }
   
   
   }
   
   
   fclose(fp);
   
   
   
   continue;
   }
   
   else if(buff[0]=='m' && buff[1]=='a' && buff[2]=='n' && buff[4]=='m' && buff[5]=='v')
   {
   
   // man mv
   FILE *fp=fopen("mv_man.txt","r");
   if(fp!=NULL)
   {
   char c;
   c=fgetc(fp);
   while(c!=EOF)
   {
   pf("%c",c);
   c=fgetc(fp);
   }
   
   
   }
   
   
   fclose(fp);
   continue;
   }
   
   else if( buff[0]=='m' && buff[1]=='a' && buff[2]=='n' && buff[4]=='g' && buff[5]=='r' && buff[6]=='e' && buff[7]=='p')
   {
   // man grep
   FILE *fp=fopen("grep_man.txt","r");
   if(fp!=NULL)
   {
   char c;
   c=fgetc(fp);
   while(c!=EOF)
   {
   pf("%c",c);
   c=fgetc(fp);
   }
   
   
   }
   
   
   fclose(fp);
   
   
   continue;
   }
   //pf("nkccklzxklhjklzxxhi jlhjhn");
   fflush(stdout);
   system(buff);
   
   }
    
    }
  return 0;
}
