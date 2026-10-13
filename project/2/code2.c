#include<stdio.h>
#include<stdlib.h>
typedef struct point
{
    int data;
    struct point *next;
 }point,*linklist;
linklist mergelist(linklist la,linklist lb)
 {
    point* pa=la->next,*pb=lb->next,*pc=la;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else if(pa->data>pb->data)
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
        else
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            point *q=pb;
            pb=pb->next;
            free(q);
        }
    }
    pc->next=pa?pa:pb;
    free(lb);
    return la;
 }
void createlist(linklist*l,int arr[],int n)
{
    *l=(linklist)malloc(sizeof(point));
    (*l)->next=NULL;
    point *tail=*l;
	for(int i=0;i<n;i++)
	{
        point *p=(point*)malloc(sizeof(point));
        p->data=arr[i];
        p->next=NULL;
        tail->next=p;
        tail=p;
		}
	}
void printlist(linklist l)
 {
    point *p=l->next;
    while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    int a[]={1,2,3},b[]={3,4,5};
    linklist la,lb;
    createlist(&la,a,3);
    createlist(&lb,b,3);
    linklist lres=mergelist(la,lb);
    printlist(lres);
	return 0;
}