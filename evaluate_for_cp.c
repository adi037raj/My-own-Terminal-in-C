#include <limits.h>
#include<unistd.h>
#include<stdio.h>
#include<getopt.h>
#include <stdlib.h>
#include <time.h> 
#include<string.h>
#include <dirent.h>
#include<sys/stat.h>
#define pf printf
#define sf scanf
char *line;
void force_copy(char *buff)
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
                
                return;
                printf("Unable to open source file to read!!\n");
                
              
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

       
      //  remove(source);
        return ;
}
int isFileExist(const char *path)
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
void interactive_copy(char *buff)
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
if(isFileExist(dest)==1)// ask for confirmation
{
pf("cp: overwrite %s ?",dest);
char opt;
sf("%c",&opt);
if(opt=='y' ||opt=='Y')
force_copy(buff);
}
else
{
force_copy(buff);
}
}
void update_copy(char *buff)
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
struct stat stat_source,stat_dest;
stat(source,&stat_source);

if(isFileExist(dest)==1 &&  stat(dest,&stat_dest)>=0)
{
if(stat_dest.st_atime>stat_source.st_atime)force_copy(buff);
}
else
force_copy(buff);

}
void no_clobber_copy(char *buff)
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
if(isFileExist(dest)==1)return ;
force_copy(buff);

}
void print_version()
{
FILE *fp=fopen("cp_version.txt","r");
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
 
void evaluate_for_cp(char *buff)
{
line=buff;
//pf("%s ,,",line);
pf("%s ",buff);
int f=0,i=0,n=0,u=0,vers=0;
if(buff[4]=='f')f=1;
else if(buff[4]=='i')i=1;
else if(buff[4]=='u')u=1;
else if(buff[4]=='n')n=1;
else if(buff[4]=='v') vers=1;



if(f==1)
force_copy(buff+4);
else if(i==1)
interactive_copy(buff+3+1);
else if(u==1)
update_copy(buff+3+1);
else if(n==1)
no_clobber_copy(buff+3+1);
else if(vers==1)
print_version();
else
pf("ERROR\n");
}
