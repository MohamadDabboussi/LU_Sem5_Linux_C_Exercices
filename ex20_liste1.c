#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void main(int argc,char **argv){
int a,b,sp=0,sf=0,sum=0,i;
int p[2];
pipe(p);
a=atoi(argv[1]);
b=atoi(argv[2]);
if(!fork())
{
for(i=((a+b)/2)+1;i<=b;i+=1){
sf+=i;
}
write(p[1],&sf,sizeof(int));
exit(0);
}
else{
for(i=a;i<=(a+b)/2;i+=1){
sp+=i;
}
}
read(p[0],&sf,sizeof(int));
sum=sp+sf;
printf("the sum from a to b is: %d \n",sum);
}
