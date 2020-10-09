#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>
#include <string.h>

typedef struct{
int id;
char* mot;
}message;

void main(int argc,char **argv){
int **p;
message m1,m2;
int i,j;
p=(int**)malloc((argc)*sizeof(int));
for(i=1;i<argc;i+=1){
p[i]=(int*)malloc(2*sizeof(int));
pipe(p[i]);
}
for(i=1;i<argc;i+=1){
if(!fork())
{
m1.id=getpid();
m1.mot=(char*)malloc(strlen(argv[i])*sizeof(char));
m1.mot=argv[i];
write(p[i][1],&m1,sizeof(message));
read(p[i+2*(i%2)-1][0],&m2,sizeof(message));
printf("fils numero %d de pid=%d: j'ai recu de mon frere numero %d de pid=%d le mot %s \n",i,getpid(),(i+2*(i%2)-1),m2.id,m2.mot);
exit(0);
}
if(i%2==0){wait(NULL);wait(NULL);}
}
}
