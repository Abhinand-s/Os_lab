#include<stdio.h>
#include<string.h>
int main(){
    int tr[20],cr,n,i,sum=0,new;
    printf("enter the number of tracks\n");
    scanf("%d",&n);
    printf("enter the head position\n");
    scanf("%d",&cr);
    printf("enter the tracks to traverse : ");
    for(i=0;i<n;i++){
        new=0;
        scanf("%d",&tr[i]);
        new=cr-tr[i];
        if(new<0){
            new=tr[i]-cr;
        }
        cr=tr[i];
        sum=sum+new;
    }
    printf("traversed order : ");
    for(i=0;i<n;i++){
        printf("%d => ",tr[i]);

    }
    printf("\b\b\b.  \ntotal head movements : %d\n",sum);
}