#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
void main()
{
int pfp[2],ppf[2],ok,i,np,nf,r,binf,bsup,si;
pipe(pfp);
pipe(ppf);
ok=0;i=0;si=sizeof(int);
srand(getpid()+time(NULL));
if(!fork())
{
binf=0;bsup=1000;nf=500;
while(1)
{
write(pfp[1],&nf,si);
read(ppf[0],&r,si);
if(r==0) {exit(0);}
if(r==1) {binf=nf; nf=nf+(bsup-nf)/2;}
if(r==-1) {bsup=nf; nf=nf-(nf-binf)/2;}
}
}
else{
np=(rand()%1000)+1;
while(!ok)
{
read(pfp[0],&nf,si);
if(np>nf) r=1;
if(np<nf) {r=-1;}
if(np==nf) {r=0; ok=1;}
i+=1;
write(ppf[1],&r,si);
printf("iter:%d np:%d nf=%d",i,np,nf);
}
}
}
