#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int i;

void h(int sig){
signal(2,h);
printf("------------%d----------\n",i);
}

void main(int argc,char **argv){
signal(2,h);
long a,b;
int j,ok;
a=atoi(argv[1]);
b=atoi(argv[2]);
for(i=a;i<=b;i++)
{ok=1;
for(j=2;j<i/2;j++){
if(i%j==0) {ok=0; break;}
}
if(ok) {printf("%d \n",i);}
}
}
