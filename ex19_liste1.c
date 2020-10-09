#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void main(int argc,char **argv){
int n,s,i,si=sizeof(int);
int **p;
s=0;
n=atoi(argv[1]);
p=(int**)malloc(n*si);
for(i=0;i<n;i+=1){
p[i]=(int*)malloc(2*si);
pipe(p[i]);
}
if(!fork()){s=getpid(); write(p[0][1],&s,si); exit(0);}
for(i=1;i<n;i+=1){
if(!fork()){
read(p[i-1][0],&s,si);
s+=getpid(); printf("%d \n",s);
write(p[i][1],&s,si);
exit(0);
}
}
read(p[n-1][0],&s,si);
printf("je suis le processus principal.\n La somme est:%d",s);
}
