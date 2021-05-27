#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>

#define pf printf
#define sf scanf
char *line;
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fptr = fopen(path, "r");

    // If file does not exists 
    if (fptr == NULL)
        return 0;

    // File exists hence close file and return true.
    fclose(fptr);

    return 1;
}


void force_move(char *buff)
{
char source[50],dest[50];
int i=3;
while(buff[i]!=' ')
{
source[i-3]=buff[i];
i++;
}
source[i-3]='\0';
int j=i;
i++;
//pf("source is %s",source);

while(buff[i]!='\0')
{

dest[i-j-1]=buff[i];i++;
}
dest[i-j-1]='\0';
//pf("deste is %s  ,",dest);
  FILE* fp1 = fopen(source, "r");
if (!fp1) {
                system(line);
               
                return ;
        }
FILE * fp2 = fopen(dest, "w");
        if (!fp2) {
                printf("Unable to open target file to write\n");
                return ;
        }
int ch;
while ((ch = fgetc(fp1)) != EOF) {
                fputc(ch, fp2);
        }
        
        
        fclose(fp1);
        fclose(fp2);

        /* removing the source file */
        remove(source);
        return ;
}
void no_clobber(char *buff)
{
char source[50],dest[50];
int i=3;
while(buff[i]!=' ')
{
source[i-3]=buff[i];
i++;
}
source[i-3]='\0';
int j=i;
i++;
//pf("source is %s",source);

while(buff[i]!='\0')
{

dest[i-j-1]=buff[i];i++;
}
dest[i-j-1]='\0';
//pf("deste is %s  ,",dest);
if(isFileExists(dest)==1)return ;
force_move(buff);
}

void interactive_move(char *buff)
{
char source[50],dest[50];
int i=3;
while(buff[i]!=' ')
{
source[i-3]=buff[i];
i++;
}
source[i-3]='\0';
int j=i;
i++;
//pf("source is %s",source);

while(buff[i]!='\0')
{

dest[i-j-1]=buff[i];i++;
}
dest[i-j-1]='\0';
//pf("deste is %s  ,",dest);
if(isFileExists(dest)==1)// ask for confirmation
{
pf("mv: overwrite %s ?",dest);
char opt;
sf("%c",&opt);
if(opt=='y' ||opt=='Y')
force_move(buff);
}
else
{
force_move(buff);
}
}
void call_version()
{
FILE *fp=fopen("mv_version.txt","r");
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
   
}
void call_for_v(char *buff)
{
force_move(buff);
char source[50],dest[50];
int i=3;
while(buff[i]!=' ')
{
source[i-3]=buff[i];
i++;
}
source[i-3]='\0';
int j=i;
i++;
//pf("source is %s",source);

while(buff[i]!='\0')
{

dest[i-j-1]=buff[i];i++;
}
dest[i-j-1]='\0';
pf("renamed %s -> %s\n",source,dest);



}

void evaluate_for_mv(char *buff)
{
line=buff;
int f=0,n=0,i=0,ver=0,v=0;

if(buff[4]=='f')
f=1;
else if(buff[4]=='v' && buff[5]!='e')v=1;
else if(buff[4]=='v')ver=1;
else if(buff[4]=='i')
i=1;
else if(buff[4]=='n') n=1;

if(f==1)
force_move(buff+3+1);
else if(i==1)
interactive_move(buff+1+3);
else if(n==1)
no_clobber(buff+1+3);
else if(ver==1)
call_version();
else if(v==1)
call_for_v(buff+1+3);
else 
pf("ERRoR\n");
}
