//307 Aiswarya Anil Nair
#include <stdio.h>
#define N 5
struct cqueue
{
	int CQ[N];
	int front;
	int rear;
};
typedef struct cqueue cqueue;

void create(cqueue *cq);
void enqueue(cqueue *cq, int ele);
void dequeue(cqueue *cq);
int IsFull(cqueue *cq);
int IsEmpty(cqueue *cq);
void display(cqueue *cq);

int main()
{
	cqueue Q;
	create(&Q);
	int choice;
	do
	{
		printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter any other number to exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			if(IsFull(&Q))
			{
				printf("Queue is full.\n");
			}
			else
			{
				printf("Enter element:\n");
				int ele;
				scanf("%d",&ele);
				enqueue(&Q,ele);
				printf("Queue:\n");
				display(&Q);
			}
		}
		else if(choice==2)
		{
			if(IsEmpty(&Q))
			{
				printf("Queue is empty.\n");
			}
			else
			{
				dequeue(&Q);
				printf("Remaining Queue:\n");
				display(&Q);
			}
		}
	}while(choice==1 || choice==2);
return(0);
}

void create(cqueue *cq)
{
	cq->front=-1;
	cq->rear=-1;
}

void enqueue(cqueue *cq, int ele)
{
	if(cq->front==-1 && cq->rear==-1)
	{
		cq->front=0;
		cq->rear=0;
		cq->CQ[cq->rear]=ele;
	}
	else
	{
		cq->rear=(cq->rear + 1)%N;
		cq->CQ[cq->rear]=ele;
	}
}

void dequeue(cqueue *cq)
{
	if(cq->front==cq->rear)
	{
		printf("Dequeued Element: %d\n",cq->CQ[cq->front]);
		cq->front=-1;
		cq->rear=-1;
	}
	else
	{
		printf("Dequeued Element: %d\n",cq->CQ[cq->front]);
		cq->front=(cq->front + 1)%N;
	}
}

int IsFull(cqueue *cq)
{
	if(((cq->rear + 1)%N)== cq->front)
		return 1;
	else
		return 0;
}

int IsEmpty(cqueue *cq)
{
	if(cq->front==-1 && cq->rear==-1)
		return 1;
	else
		return 0;
}

void display(cqueue *cq)
{
	int i=cq->front;
	while(i!=cq->rear)
	{
		printf("%d\n",cq->CQ[i]);
		i=(i+1)%N;
	}
	printf("%d\n",cq->CQ[cq->rear]);
}