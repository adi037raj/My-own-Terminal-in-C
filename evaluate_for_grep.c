#include<unistd.h>
#include<stdio.h>
#include<getopt.h>
#include <stdlib.h>
#include<string.h>
#include <dirent.h>
#include<sys/stat.h>
#define pf printf

void i_case(char *buff)
{
char text[50],filename[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
i+=2;
int j=i;
while(buff[i]!='\0')
{
filename[i-j]=buff[i];
i++;
}
filename[i-j]='\0';
//pf("%s soce --%s --dest",text,filename);
for(i=0;i<=strlen(text);i++){
      if(text[i]>=65&&text[i]<=90)
         text[i]=text[i]+32;
   }
FILE *fp=fopen(filename,"r");
if(fp==NULL)
{pf("No such file or directory\n");

return ;
}
char read[200];
while (fgets(read,50,fp) != NULL)
{
for(i=0;i<=strlen(read);i++){
      if(read[i]>=65&&read[i]<=90)
         read[i]=read[i]+32;
   }
   if(strstr(read,text) != NULL) {
   pf("%s \n",read);
}

   

}



}
void c_case(char *buff)
{
char text[50],filename[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
i+=2;
int j=i;
while(buff[i]!='\0')
{
filename[i-j]=buff[i];
i++;
}
filename[i-j]='\0';
//pf("%s soce --%s --dest",text,filename);
   
FILE *fp=fopen(filename,"r");
if(fp==NULL)
{pf("No such file or directory\n");

return ;
}
int c=0;
char read[200];
while (fgets(read,50,fp) != NULL)
{

   if(strstr(read,text) != NULL) {
   c++;
}

   

}
pf("%d\n",c);




}
void invert_case(char *buff)
{
char text[50],filename[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
i+=2;
int j=i;
while(buff[i]!='\0')
{
filename[i-j]=buff[i];
i++;
}
filename[i-j]='\0';
//pf("%s soce --%s --dest",text,filename);
   
FILE *fp=fopen(filename,"r");
if(fp==NULL)
{pf("No such file or directory\n");

return ;
}
int c=0;
char read[200];
while (fgets(read,50,fp) != NULL)
{

   if(strstr(read,text) != NULL) {
   continue;
  
}
 pf("%s\n ",read);
}
}
void file_with_matches(char *buff)
{
char text[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';


DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
        
	 FILE *fp=fopen(dir->d_name,"r");
	 if(fp!=NULL)
	 {
	 
	 char read[200];
    while (fgets(read,50,fp) != NULL)
       {  

   if(strstr(read,text) != NULL) {
      pf("\n  %s",dir->d_name);
  break;
}
}	 
	 
	 
	 }
        
        }
        
        pf("\n");

        closedir(d);


}
}
void i_c_case(char *buff)
{
char text[50],filename[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
i+=2;
int j=i;
while(buff[i]!='\0')
{
filename[i-j]=buff[i];
i++;
}
filename[i-j]='\0';
//pf("%s soce --%s --dest",text,filename);
for(i=0;i<=strlen(text);i++){
      if(text[i]>=65&&text[i]<=90)
         text[i]=text[i]+32;
   }
FILE *fp=fopen(filename,"r");
if(fp==NULL)
{pf("No such file or directory\n");

return ;
}
char read[200];
int c=0;
while (fgets(read,50,fp) != NULL)
{
for(i=0;i<=strlen(read);i++){
      if(read[i]>=65&&read[i]<=90)
         read[i]=read[i]+32;
   }
   if(strstr(read,text) != NULL) {
   pf("%s \n",read);
c++;}
}
pf(" %d \n",c);
}
void i_v_case(char *buff)
{

char text[50],filename[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
i+=2;
int j=i;
while(buff[i]!='\0')
{
filename[i-j]=buff[i];
i++;
}
filename[i-j]='\0';
//pf("%s soce --%s --dest",text,filename);
for(i=0;i<=strlen(text);i++){
      if(text[i]>=65&&text[i]<=90)
         text[i]=text[i]+32;
   }
FILE *fp=fopen(filename,"r");
if(fp==NULL)
{pf("No such file or directory\n");

return ;
}
char read[200];
while (fgets(read,50,fp) != NULL)
{
for(i=0;i<=strlen(read);i++){
      if(read[i]>=65&&read[i]<=90)
         read[i]=read[i]+32;
   }
   if(strstr(read,text) == NULL) {
   pf("%s \n",read);
}

   

}


}
void i_l_case(char *buff)
{
char text[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
for(i=0;i<=strlen(text);i++){
      if(text[i]>=65&&text[i]<=90)
         text[i]=text[i]+32;}

DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
        
	 FILE *fp=fopen(dir->d_name,"r");
	 if(fp!=NULL)
	 {
	 
	 char read[200];
	 
    while (fgets(read,50,fp) != NULL)
       {  
for(i=0;i<=strlen(read);i++){
      if(read[i]>=65&&read[i]<=90)
         read[i]=read[i]+32;
   }
   if(strstr(read,text) != NULL) {
      pf("\n  %s",dir->d_name);
  break;
}
}	 
	 
	 
	 }
        
        }
        
        pf("\n");

        closedir(d);


}
}

void c_v_case(char *buff)
{
char text[50],filename[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';
i+=2;
int j=i;
while(buff[i]!='\0')
{
filename[i-j]=buff[i];
i++;
}
filename[i-j]='\0';
//pf("%s soce --%s --dest",text,filename);
   
FILE *fp=fopen(filename,"r");
if(fp==NULL)
{pf("No such file or directory\n");

return ;
}
int c=0;
char read[200];
while (fgets(read,50,fp) != NULL)
{

   if(strstr(read,text) != NULL) {
   continue;
  
}
 pf("%s\n ",read);c++;
}
pf("%d \n",c);
}
void c_l_case(char *buff)
{
char text[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';


DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {
int c=0;
        while ((dir = readdir(d)) != NULL)

        {
        
	 FILE *fp=fopen(dir->d_name,"r");
	 if(fp!=NULL)
	 {
	 
	 char read[200];
    while (fgets(read,50,fp) != NULL)
       {  

   if(strstr(read,text) != NULL) {
      pf("\n  %s",dir->d_name);
  c++;break;
}
}	 
	 
	 
	 }
        
        }
        
        pf("%d\n",c);

        closedir(d);


}
}
void v_l_case(char *buff)
{
char text[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';


DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {
int c=0;
        while ((dir = readdir(d)) != NULL)

        {c=0;
        
	 FILE *fp=fopen(dir->d_name,"r");
	 if(fp!=NULL)
	 {
	 
	 char read[200];
    while (fgets(read,50,fp) != NULL)
       {  

   if(strstr(read,text) != NULL) {
    
  c++;break;
}
}
	 
	 
	 
	 }
        if(c!=0)
        pf(" %s  \n",dir->d_name);
        
        }
        
        pf("\n");

        closedir(d);


}
}
void last_case(char *buff){
char text[50];
int i=9;
while(buff[i]!='"')
{
text[i-9]=buff[i];
i++;
}
text[i-9]='\0';


DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {
int c=0,count=0;
        while ((dir = readdir(d)) != NULL)

        {c=0;
        
	 FILE *fp=fopen(dir->d_name,"r");
	 if(fp!=NULL)
	 {
	 
	 char read[200];
    while (fgets(read,50,fp) != NULL)
       {  

   if(strstr(read,text) != NULL) {
    
  c++;count++;
}
}
	 
	 
	 
	 }
        if(c!=0)
        pf(" %s  \n",dir->d_name);
        
        }
        pf("%d \n",count);
        pf("\n");

        closedir(d);


}
}

void evaluate_for_grep(char *buff)
{
//pf("%s \n",buff);
// grep -i "adi" eiil.txt
if(buff[6]=='i' &&(buff[7]!='c'||buff[7]!='v'||buff[7]!='l'))i_case(buff);
else if(buff[6]=='c'&&(buff[7]!='i'||buff[7]!='v'||buff[7]!='l'))c_case(buff);
else if(buff[6]=='v'&&(buff[7]!='i'||buff[7]!='c'||buff[7]!='l'))invert_case(buff);
else if(buff[6]=='l'&&(buff[7]!='i'||buff[7]!='v'||buff[7]!='c'))file_with_matches(buff);

else if(buff[6]=='i' && buff[7]=='c' || buff[6]=='c' && buff[7]=='i')
i_c_case(buff);
else if(buff[6]=='i' && buff[7]=='v' || buff[6]=='v' && buff[7]=='i')
i_v_case(buff);
else if(buff[6]=='i' && buff[7]=='l' || buff[6]=='l' && buff[7]=='i')
i_l_case(buff);

else if(buff[6]=='v' && buff[7]=='c' || buff[6]=='c' && buff[7]=='v')
c_v_case(buff);
else if(buff[6]=='l' && buff[7]=='c' || buff[6]=='c' && buff[7]=='l')
c_l_case(buff);

else if(buff[6]=='v' && buff[7]=='l' || buff[6]=='l' && buff[7]=='v')
v_l_case(buff);

else if(buff[6]=='i' || buff[6]=='v' || buff[6]=='l' ||buff[6]=='c')
last_case(buff);
else 
pf("ERoR\n");





}
