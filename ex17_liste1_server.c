#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
#include <fcntl.h>

void main(int argc,char **argv){
int charge,maxcharge,mynum;
int idpsc,idpcs;
int request,response,si=sizeof(int);
char pipename[6];
mynum=atoi(argv[1]);
charge=atoi(argv[2]);
maxcharge=atoi(argv[3]);
sprintf(pipename,"idcs%d\0",mynum);
idpsc=open("psc",O_RDWR);
idpcs=open(pipename,O_RDWR);
read(idpcs,&request,si);
if(request==0) {response=charge;write(idpsc,&response,si);}
else{
if(((request+charge)>maxcharge)||(request+charge)<0)
{response=-1;write(idpsc,&response,si);}
else{response=1;charge+=request;write(idpsc,&response,si);}
}
}
