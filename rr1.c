#include <stdio.h>
#include <stdlib.h>

int q[50], front = -1, rear = -1;

struct process {
    int pid;
    int a_t, b_t, tat, w_t, c_t, p_t, status, b_t_l;
} p[20];

void print_gantt_chart(int num);
void print_table(int n);
void calculate_average(int n);

struct done {
    int name, st, ct;
} d[10];

void enqueue(int j) {
    if (front == -1 && rear == -1) {
        front++;
    }
    rear++;
    q[rear] = j;
}

int dequeue() {
    int item;
    item = q[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return (item);
}

int main() {
    int i, j, n, t, num = 0, ls = 0, idle = 0, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the id of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i].pid);
    }
 printf("enter the arrival time of each process\n");
    for(i=0;i<n;i++){
        printf("enter the arrival time of process %d :",p[i].pid);
        scanf("%d",&p[i].a_t);
        p[i].w_t=p[i].tat=0;
    }
    printf("enter the burst time of each process\n");
    for(i=0;i<n;i++){
        printf("enter the burst time of process %d :",p[i].pid);
        scanf("%d",&p[i].b_t);
        p[i].b_t_l=p[i].b_t;
        p[i].status=0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &t);

    for(i=0,num=0,ls=0;ls<n;){
        for(j=0;j<n;j++){
            if(p[j].status==0&&p[j].a_t<=i){
                enqueue(j);
                p[j].status=1;
        }
        if(idle==0&&front==-1){
            d[num].name=-1;
            d[num].st=i;
            idle=1;
            i++;
        }
        else if(front!=-1){
            if(idle==1){
                d[num].ct=i;
                idle=0;
                num++;
            }
            k=dequeue();
            d[num].st=i;
            d[num].name=p[k].pid;
            if (p[k].b_t_l <= t) {
    d[num].ct = i + p[k].b_t_l;
    p[k].c_t = d[num].ct; // Update completion time
    i = d[num].ct;
    p[k].tat = p[k].c_t - p[k].a_t; // Correct calculation of turnaround time
    p[k].w_t = p[k].tat - p[k].b_t; // Correct calculation of waiting time
    p[k].status = 2;
    ls++;
    num++;
}

            else if(p[k].b_t_l>t){
                d[num].ct=i+t;
                i=d[num].ct;
                p[k].b_t_l=p[k].b_t_l-t;
                num++;
                for(j=0;j<n;j++){
                    if(p[j].status==0&&p[j].a_t<=i){
                        enqueue(j);
                        p[j].status=1;
                    }
                }
                enqueue(k);
            }

        }
        else{
            i++;
        }
        }

    }
    d[num].st=d[num-1].st+p[k].b_t_l;
    printf("\n");
    print_gantt_chart(num);
    printf("\n");
    print_table(n);
    printf("\n");
    calculate_average(n);

    return 0;
}

void print_gantt_chart(int num) {
    int i;
    printf("Gantt Chart:\n");
    for (i = 0; i < num; i++) {
        printf("-------------");
    }
    printf("\n");
    for (i = 0; i < num; i++) {
        printf("| p[%d] ", d[i].name);
    }
    printf("|\n");
    for (i = 0; i < num; i++) {
        printf("-------------");
    }
    printf("\n");
    for (i = 0; i <= num; i++) {
        printf("      %d     ", d[i].st);
    }
    printf("\n");
}

void print_table(int n) {
    int i;
    printf("----------------------------------------------------\n");
    printf("| pid | arrival time | burst time | completion time | turnaround time | waiting time |\n");
    printf("----------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf(" %d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].a_t, p[i].b_t, p[i].c_t, p[i].tat, p[i].w_t);
    }
    printf("----------------------------------------------------\n");
}

void calculate_average(int n) {
    int sum_wt = 0, sum_turn = 0;
    float av_wt, av_tat;
    for (int i = 0; i < n; i++) {
        sum_wt += p[i].w_t;
        sum_turn += p[i].tat;
    }
    av_wt = (float)sum_wt / n;
    av_tat = (float)sum_turn / n;
    printf("Average Waiting Time: %.2f\n", av_wt);
    printf("Average Turnaround Time: %.2f\n", av_tat);
}
