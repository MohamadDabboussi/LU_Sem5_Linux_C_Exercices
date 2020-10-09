#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int a,b,t,r;

void h(int sig){
if(sig==14) {
if(t==0){
t=1;
signal(14,h);
alarm(b-a);
}
else {if(t==1) t=2;}
}
if(sig==2){
if(t==0) {r=alarm(0); printf("trop tot:%d secondes\n",a-r); exit(0);}
if(t==2) {printf("trop tard"); exit(0);}
if(t==1) {
signal(2,h); r=alarm(0); printf("temps ecoule:%d \n",b-r);t=0; alarm(a);
}
}
}
void main(int argc,char **argv){
a=atoi(argv[1]);
b=atoi(argv[2]);
t=0;
signal(14,h);
signal(2,h);
alarm(a);
while(1){
pause();
}
}
