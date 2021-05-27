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
void print_with_f_all(){

DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {
struct stat my_stat;
        while ((dir = readdir(d)) != NULL)

        {
        
	  int direct=0;
	  stat(dir->d_name,&my_stat);
	  if(S_ISDIR(my_stat.st_mode))
	  direct=1;
	  pf("%s",dir->d_name);
        if(direct==1)
        pf("/");
        pf("\t");
        }
        
        pf("\n");

        closedir(d);


}
}


void print_with_f() //ls -f
{
DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {
struct stat my_stat;
        while ((dir = readdir(d)) != NULL)

        {
        if(dir->d_name[0]=='.')continue;
	  int direct=0;
	  stat(dir->d_name,&my_stat);
	  if(S_ISDIR(my_stat.st_mode))
	  direct=1;
	  pf("%s",dir->d_name);
        if(direct==1)
        pf("/");
        pf("\t");
        }
        
        pf("\n");

        closedir(d);


}
}


void print_all()  // ls -a
{


DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
	  pf("\n%s",dir->d_name);
        
        }

        closedir(d);
pf("\n");

}
}
void  print_with_comma_all() 
{
DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
        
	  pf("%s ,",dir->d_name);
        
        }
        pf("\b ");
        pf("\n");

        closedir(d);


}
}

void print_with_comma()  // ls -m
{
DIR *d;

    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
        if(dir->d_name[0]!='.')
	  pf("%s ,",dir->d_name);
        
        }
        pf("\b ");
        pf("\n");

        closedir(d);


}
}
void  print_with_size_all()
{
DIR *d;
struct stat my_stat;
    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
	  if(stat(dir->d_name,&my_stat)<0)
            {printf("errror\n");
          exit(0);
             }
             
             printf("%ld %s\t",my_stat.st_blocks,dir->d_name);
        
        }
        pf("\b ");
        pf("\n");

        closedir(d);


}

}
void print_with_size_comma()
{
DIR *d;
struct stat my_stat;
    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
	  if(stat(dir->d_name,&my_stat)<0)
            {printf("errror\n");
          exit(0);
             }
             if(dir->d_name[0]!='.')
             printf("%ld %s, ",my_stat.st_blocks,dir->d_name);
        
        }
        pf("\n");
        
        closedir(d);


}
}
void print_with_size()  //ls -s
{
DIR *d;
struct stat my_stat;
    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
	  if(stat(dir->d_name,&my_stat)<0)
            {printf("errror\n");
          exit(0);
             }
             if(dir->d_name[0]!='.')
             printf("%ld %s\t",my_stat.st_blocks,dir->d_name);
        
        }
        pf("\n");
        
        closedir(d);


}
}
void print_everything()
{
DIR *d;
struct stat my_stat;
    struct dirent *dir;

    d = opendir(".");

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {
	  if(stat(dir->d_name,&my_stat)<0)
            {printf("errror\n");
          exit(0);
             }
             int direct=0;
             if(S_ISDIR(my_stat.st_mode))
	  direct=1;
	  
 		if(direct==0)            
             printf("%ld %s , ",my_stat.st_blocks,dir->d_name);
             else
             printf("%ld %s/ , ",my_stat.st_blocks,dir->d_name);
        
        }
        pf("\b ");
        pf("\n");
        
        closedir(d);


}

}


int main(int argc,char **buff)
{
   
  int opt; 
     
     int x=2;
     int all=0,m=0,s=0,f=0;
  //   pf("HIII");
    //pf("it contains %s ",buff);
    fflush(stdout);
    //sleep(50);
    //pf("\n %s %s",buff[0],buff[1]);
    while((opt = getopt(argc,buff,"amsF")) != -1)  
    {
    //pf("%c\n",opt);
      
    switch(opt) 
    {
    case 'a':all=1; break;
    case 'm':m=1;break;
    case 's':s=1;break;
    case 'F':f=1;break;
    case '?':
     printf("zero case");
                break;  
    
    }
    }/*
    
    if(strchr(buff,'a')!=NULL)
    all=1;
    if(strchr(buff,'m')!=NULL)m=1;
    if(strchr(buff+2,'F')!=NULL)f=1;
    if(strchr(buff+3,'s')!=NULL)s=1;
    */
    //pf("\na m s f is %d %d %d %d",all,m,s,f); 
    
    
    if(all==1 && m==0 && s==0&&f==0)
    print_all();
    else if(all==0 && m==1 && s==0&&f==0)
    print_with_comma() ;
    else if(all==0 && m==0 && s==1&&f==0)
    print_with_size() ;
    else if(all==0 && m==0 && s==0&&f==1)
     print_with_f();
    else if(all==1&&m==1&&s==0&&f==0)
    print_with_comma_all() ;
    else if(all==1&&m==0&&s==1&&f==0)
    print_with_size_all() ;
    else if(all==1&&m==0&&s==0&&f==1)
	print_with_f_all();
    else if(m==1&&s==1&&f==0)
    print_with_size_comma();
    else if(m==1 || s==1 || f==1)
    print_everything();
    else
    pf("ERRor\n");
   return 0;
}
