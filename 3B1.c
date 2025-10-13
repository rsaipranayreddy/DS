#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert(int value){
    if((front==0 && rear==MAX-1)||(front==(rear+1)%MAX)){
        printf("Queue overflow\n");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=value;
        printf("%d inserted into queue\n",value);
    }
    else{
        rear=(rear+1)%MAX;
        queue[rear]=value;
        printf("%d inserted into queue\n",value);
        
    }
}
void delete(){
    if(front==-1)
        printf("Queue underflow\n");
    else{
        printf("Deleted element:%d\n",queue[front]);
        if(front==rear){
                front=-1;
                rear=-1;
        }
        else
            front=(front+1)%MAX;
        }
}
void display(){
    if(front==-1)
        printf("Queue is empty\n");
    else{
        printf("Queue elements\n");
        int i=front;
        while(1){
            printf("%d\n",queue[i]);
            if(i==rear)
                break;
            i=(i+1)%MAX;
        }
    }
}
int main(){
    int choice,value;
    while(1){
        printf("\nCircular queue operation\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter value to insert ");
                scanf("%d",&value);
                insert(value);
                break;
            case 2: 
                delete();
                break;
            case 3: 
                display();
                break;
            case 4: 
                printf("Exiting a program\n");
                return 0;
            default: 
                printf("Invalid choice\n");
            }
        }
}