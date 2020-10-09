#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>

void main() {
int n;
n=fork();
n=n-fork();
printf("Le resultat de %d est %d\n",fork(),n) ;
}
