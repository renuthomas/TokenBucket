/*------------------------
TokenBucketAlgorithm.c
-------------------------*/

# include <stdio.h>
# include <stdlib.h>
# define MAX_SIZE 20

typedef struct QueType{
	int Queue[MAX_SIZE];
	int front,rear;
}QUEUE;

//--------Prototype----------------
void Init();
void Enqueue(int num);
void Dequeue();

//--------Global variables---------
QUEUE Q;

main()
{
	int max_bucket=20;
	int no_token=1; //initial number of token
	int j=0;
	int time,i,packet[20];
	
	printf("Enter the number of second:");
	scanf("%d",&time);
	
	printf("Enter the no of packets per sec:");
	for(i=0;i<time;i++){
		scanf("%d",&packet[i]);
	}
	
	printf("Initial readings\n");
	printf("No. of tokens:%d\n\n",no_token);
	
	printf("Packet reading\n\n");
	
	Init();
	
	while(1){          
		if(j<time){         // It is used to make sure that all packets will be sent
			if(Q.rear==-1) // To check if packet is not in queue
			{
			    if(packet[j]<=no_token){            // To compare the number of packet to the number of tokens
			        printf("%d packets is sent\n",packet[j]);
			        no_token=no_token-packet[j];    // To subtract the tokens based on the size of the packet
			        j++;
				}else{
				    printf("%d packets is sent to queue\n",packet[j]);
			        Enqueue(packet[j]);
				}
			}else{
			    if(Q.Queue[Q.front]<=no_token){
				    printf("%d packets is sent from the queue\n",packet[j]);
			        no_token=no_token-Q.Queue[Q.front];
			        Dequeue();
			        j++;
				}else{
				    printf("Waiting for tokens to generate\n");
				}
			}
			no_token++;	
		}else{
		    printf("Final readings\n");
			printf("No. of tokens:%d\n",no_token);	
			return;
		}
	}			
}

//-----------Function Init------------------
void Init(){
	Q.front=0;
	Q.rear=-1;
}
//----------Function Enqueue---------------
void Enqueue(int num){
	if(Q.rear==MAX_SIZE-1){
		printf("Queue is full\n");
	}else{
		Q.rear++;
		Q.Queue[Q.rear]=num;
	}
}
//---------Function Deque---------------
void Dequeue()
{
	int i;
	
	if(Q.rear==-1){
		printf("Queue is empty\n");
	}else{
		i=0;
		while(i<Q.rear){
			Q.Queue[i]=Q.Queue[i+1];
			i++;
		}
		Q.rear--;
	}
}
