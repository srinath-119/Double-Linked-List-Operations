#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void create_linkedlist(struct node *head,int n)
{
    struct node *newnode, *tmp;
    int num, i;
    

    if(head == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        head->prev=NULL;
        head->data = num;      
        head->next = NULL; // links the address field to NULL
        tmp = head;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if(newnode== NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                 
                newnode->data = num;     
            newnode->prev=tmp; // links the num field of fnNode with num
                newnode->next= NULL; // links the address field of fnNode with NULL
                 
                tmp->next= newnode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->next; 
            }
        }
    }
}

void displayList(struct node* head)
{
    struct node * temp;
    temp=head;
    printf("Linked List is:\n");
    while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
    }
    printf("\n");
}

struct node* insert_Beginning(struct node*head)
{
    struct node *newnode;
    int num;
    printf("\n Enter the data:");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;
}

struct node* insert_Atposition(struct node* head)
{
    struct node* ptr;
    int data,index;
    printf("Input data for node:");
    scanf("%d",&data);
    printf("Enter the index after which you want to insert the node:");
    scanf("%d",&index);
    ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while (i != index-1)
    {
            p=p->next;  
            i++;                           
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->prev=p;
    p->next=ptr;

    return head;
}

struct node* insert_Atend(struct node* head)
{
    struct node* ptr;
    int data;
    printf("enter the data:\n");
    scanf("%d",&data);
    ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p;
    p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=p;
    p->next=ptr;
    return head;
}


struct node* delete_FirstNode(struct node* head)
{
    struct node* p;
    p=head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
}

struct node* delete_Atposition(struct node* head)
{
    int index;
    printf("Enter the index after which you want to delete the node:");
    scanf("%d",&index);
   
    struct node* p;
    p=head;
    struct node* q;
    q=head->next;
    int i=0;
    while(i != index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    struct node* z;
    z=q->next;
    z->prev=p;
    free(q);
    return head;
}

struct node* delete_lastNode(struct node* head)
{
    struct node* p;
    p=head;
    struct node* q;
    q=head->next;
    while(q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;

}

int count_noof_nodes(struct node *n){
    int count=0;
    while(n != NULL){
        n=n->next;
        count++;
    }
    return count;
}
int main()
{ 
    struct node* head;
    head = (struct node *)malloc(sizeof(struct node));
    int option;
    
        /* code */
        printf("\n\n MAIN MENU");
        printf("\n 1: Create a Singly Linked List \n");
        printf("\n 2: Display the Singly Linked List \n");
        printf("\n 3: Insert a node at the beginning of a Singly Linked List \n");
        printf("\n 4: Insert a node at the given position of a Singly Linked List \n");
        printf("\n 5:Insert a new node at the end of a Singly Linked List\n");
        printf("\n 6: Delete first node of a Singly Linked List \n");
        printf("\n 7: Delete a node from the given position of a Singly Linked List \n");
        printf("\n 8: Delete the last node of a Singly Linked List \n");
        printf("\n 9: Count the number of nodes in the List \n");
        printf("\n 10: EXIT");
    do
    {
        printf("\n\nEnter your option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: 
            {
                    int n;
		            printf("\n\n To create Singly Linked List :\n");
		            printf("-----------------------------------\n");
                    printf("Input the number of nodes : ");
                    scanf("%d", &n);
                    create_linkedlist(head,n);
                    printf("\nLINKED LIST CREATED");
            }
            break;

            case 2:
                    displayList(head);
                    break;

            case 3:
                    head=insert_Beginning(head);
                    break;
            
            case 4: 
                    head=insert_Atposition(head);
                    break;

            case 5:
                    head=insert_Atend(head);
                    break;
            
            case 6:
                    head=delete_FirstNode(head);
                    break;

            case 7: delete_Atposition(head);
                    break;
            
            case 8: delete_lastNode(head);
                    break;

            case 9: 
            {
                    int count;
                    count=count_noof_nodes(head);
                    printf("%d",count);
                    break;
            }
        }
    } while (option !=10);
    
    
}