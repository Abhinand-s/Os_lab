#include<stdio.h>
#include<stdlib.h>
void main(){
    int np,nb,b[20],p[20],i,j,bsort[20],remb[20],balloc[20],temp,ch,flag=0;
    printf("enter the number of memory block\n");
    scanf("%d",&nb);
    printf("enter the memory block size :");
    for(i=0;i<nb;i++){
          scanf("%d",&b[i]);
          bsort[i]=i;
          remb[i]=b[i];
          balloc[i]=-1;
    }
    printf("enter the number of processes\n");
    scanf("%d",&np);
    printf("enter the process size : ");
    for(i=0;i<np;i++){
        scanf("%d",&p[i]);
    }
    printf("block\tsize\n");
    for(i=0;i<nb;i++){
        printf("%d\t%d\n",i+1,b[i]);
    }
    printf("\n");
    printf("process\tsize\n");
    for(i=0;i<np;i++){
        printf("%d\t%d\n",i+1,p[i]);
    }
//sorting
for(i=0;i<nb-1;i++){
    for(j=0;j<nb-i-1;j++){
        if(b[bsort[j]]>b[bsort[j+1]]){
            temp=bsort[j];
            bsort[j]=bsort[j+1];
            bsort[j+1]=temp;
        }
    }
}
printf("\n\n\nMenu\n1.first fit\n2.best fit\n3.worst fit\nenter your choice\n");
scanf("%d",&ch);
switch(ch){
    case 1 : //first fit
            for(i=0;i<np;i++){
                for(j=0;j<nb;j++){
                    if(p[i]<=remb[j]){
                        remb[j]=0;
                        balloc[j]=i+1;
                        flag=0;
                        break;
                    }
                }
            }
            break;
    case 2 : //best fit
           for(i=0;i<np;i++){
            for(j=0;j<nb;j++){
                if(p[i]<=remb[bsort[j]]){
                    remb[bsort[j]]=0;
                    balloc[bsort[j]]=i+1;
                    flag=0;
                    break;
                }
            }
           }
           break;
    case 3 : //worst fit
           for(i=0;i<np;i++){
            for(j=nb-1;j>=0;j--){
                if(p[i]<=remb[bsort[j]]){
                    remb[bsort[j]]=0;
                    balloc[bsort[j]]=i+1;
                    flag=0;
                    break;
                }
            }
           }
           break;
    default:
             printf("invalid choice\n");
             exit(0);
};
//display
printf("\n");
printf("block\t\tsize\t\tallocated process\n");
for(i=0;i<nb;i++){
    printf("%d\t\t%d\t\t",i+1,b[i]);
    if(balloc[i]>-1){
        printf("%d\n",balloc[i]);
        }
    else{
        printf("-\n");
    }
}
printf("unallocated process number\n");
for(i=0;i<np;i++){
    flag=0;
    for(j=0;j<nb;j++){
        if(balloc[j]==i+1){
            flag=1;
            break;
            
        }
        }
        if(flag==0)
            printf("%d ",i+1);
        
}
printf("\n\n");


}
