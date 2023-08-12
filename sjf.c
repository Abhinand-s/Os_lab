#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid;
    int a_t,b_t,tat,w_t,c_t;
}p[20];
struct process temp;
void print_ganttchart(int n);
void print_table(int n);
void avg(int n);
int main(){
    int n,i,j,min;
    printf("enter the number of process\n");
    scanf("%d",&n);
    printf("enter the  process id\n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i].pid);
    printf("enter the arrival time of processes\n");
    for(i=0;i<n;i++){
        printf("enter the arrival time of process %d  : ",p[i].pid);
        scanf("%d",&p[i].a_t);
    }
     printf("enter the burst time of processes\n");
    for(i=0;i<n;i++){
        printf("enter the burst time of process %d  : ",p[i].pid);
        scanf("%d",&p[i].b_t);
    }
    //sort with respect to burst time

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].b_t>p[j+1].b_t)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    //calculation
    //identify process which arrive first
    min=0;
    for(i=1;i<n;i++){
        if(p[i].a_t<p[min].a_t){
            min=i;
        }
        
    }
    temp=p[min];
    for(j=min-1;j>=0;j--){
        p[j+1]=p[j];
    }
    p[0]=temp;
    p[0].c_t=p[0].a_t+p[0].b_t;
    p[0].tat=p[0].c_t-p[0].a_t;
    p[0].w_t=p[0].tat-p[0].b_t;

    for(i=1;i<n;i++){
        p[i].c_t=p[i-1].c_t+p[i].b_t;
        p[i].tat=p[i].c_t-p[i].a_t;
        p[i].w_t=p[i].tat-p[i].b_t;
    }
    print_ganttchart(n);
    print_table(n);
    avg(n);
return 0;
}
void print_ganttchart(int n)
{
    int i;
    printf("gantt chart\n");
    printf("\n");
    for(i=0;i<n;i++){
        printf("---------------");
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf(" | p[%d]",p[i].pid);
    }
    printf("\n");
    for(i=0;i<n;i++)
    printf("--------------");
    printf("\n");
    printf("%d",p[i].a_t);
    for(i=0;i<n;i++)
        printf("      %d",p[i].c_t);
    printf("\n");
}
void print_table(int n){

    int i;
    printf("----------------------------------------------------\n");
    printf("| pid | arrival time | burst time | completion time | turnaround time | waiting time |\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf(" %d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].a_t,p[i].b_t,p[i].c_t,p[i].tat,p[i].w_t);
    }
    printf("----------------------------------------------------------------------------------------------------\n");
}
//// average 
void avg(int n){
    int sum_wt=0,sum_turn=0;
    float av_wa,av_tu;
    for(int i=0;i<n;i++){
        sum_wt+=p[i].w_t;
        sum_turn+=p[i].tat;
    }
    av_wa=(float)sum_wt/n;
    av_tu=(float)sum_turn/n;
    printf("average waiting time %f",av_wa);
    printf("average turn around time %f",av_tu);
}
