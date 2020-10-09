#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
int i=0,j=0,p;
void h14p (int sig) {
kill (p,2);
}
void h14f (int sig) {
kill (getppid() ,2);
}
void h2f (int sig) {
i ++ ;
printf("%d\n",i);
}
void h2p (int sig) {
j-=2;
printf("%d \n",j);
}
void main () {
p=fork();
if(p) { signal(2,h2p); signal (14,h14p); alarm (3); }
else { signal(2,h2f); signal (14,h14f); alarm (5);}
while(1);
}
