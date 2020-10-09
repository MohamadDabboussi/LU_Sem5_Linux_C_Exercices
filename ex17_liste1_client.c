#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
#include <fcntl.h>

void main(){
int request,response;
int servernumber;
int idsc,idcs[2],si=sizeof(int);
mknod("psc",S_IFIFO+0600,0);
mknod("idcs1",S_IFIFO+0600,0);
mknod("idcs2",S_IFIFO+0600,0);
idsc=open("psc",O_RDWR);
idcs[0]=open("idcs1",O_RDWR);
idcs[1]=open("idcs2",O_RDWR);
while(1){
printf("Request ? \n");
scanf("%d %d",servernumber,request);
write(idcs[(servernumber+1)%2],&request,si);
read(idsc,&response,si);
if(request==0) printf("tu as : %d \n",response);
else{
if(response==1) printf("request done \n");
else{
write(idcs[(servernumber)%2],&request,si);
read(idsc,&response,si);
if(response==1) printf("request done by server number:%d \n",servernumber%2+1);
else printf("Impossible request \n");
}
}
}
}


