#include <stdio.h>
#include <stdlib.h>

struct linkedlist{
	int data;
	struct linkedlist *next;
	struct linkedlist *prev;
	void (*order[3])(struct linkedlist*);
};
typedef	struct linkedlist LINKEDLIST;
typedef LINKEDLIST *LINK;

LINK newlist( int data );
void heapTree( LINK *node, int data );
void preorder( LINK node );
void postorder( LINK node );
void inorder( LINK node );


LINK newList( int data ){
	LINK list;
	list = (LINK)malloc(sizeof(LINKEDLIST));
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
	list->order[0] = preorder;
	list->order[1] = inorder;
	list->order[2] = postorder;
	return list;
}
void appendList( LINK list, LINK argu ){
	list->next->prev = argu;
	argu->next = list->next;
	list->next = argu;
	argu->prev = list;
}

LINK findList( LINK head, int value ){
	LINK list = head;
	while(list->data != value){
		list = list->next;
		if(list->next == NULL){
			break;
		}
	}
	return list;
}
void deleteList( LINK head, LINK find ){
	find->next->prev = find->prev;
	find->prev->next = find->next;
	free(find);
}
void printList( LINK head ,LINK tail){
	LINK print = head->next;
	while(print != tail){
		printf("%d\n",print->data);
		print = print->next;
	}
}
void init( LINK head, LINK tail ){
	head->next = tail;
	tail->prev = head;
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
void appendTree( LINK *node, int data ){
	if( *node == NULL ){
		*node = newList(data);
	}else{
		if( (*node)->data > data ){
			appendTree( &(*node)->prev, data );
		}else{
			appendTree( &(*node)->next, data );
		}
	}
}

bool insertNode( LINK *node, int data ){
	if( *node == NULL ){
		*node = newList(data);
		return true;
	}else{
		if( (*node)->data > data ){
			insertNode( &(*node)->prev , data );
		}else{
			insertNode( &(*node)->next , data );
		}
	}
}
LINK searchNode( LINK *node,LINK *parentnode, int data ){
	if( (*node)->data == data ){
		return *node;
	}else{
		if( (*node)->data > data ){
			*parentnode = *node;
			if(&(*node)->prev != NULL){
				searchNode( &(*node)->prev ,parentnode, data );
			}
			else
				return NULL;
		}else{
			*parentnode = *node;
			if(&(*node)->next!= NULL){
				searchNode( &(*node)->next ,parentnode, data );
			}
			else
				return NULL;
		}
	}
}

LINK maxNode( LINK *node ){
	LINK max = *node;
	while(max->next != NULL){
		max = max->next;
	}
	return max;
}

LINK minNode( LINK *node ){
	LINK min = *node;
	while(min->prev != NULL){
		min = min->prev;
	}
	return min;
}

bool deleteNode( LINK *node, int data ){
	LINK parent;
	LINK result = searchNode(node,&parent,data);
	if( result->prev == NULL && result->next == NULL ){
		free(result);
	}
	else if( result->prev != NULL && result->next == NULL ){
		if(parent->prev == result){

		}else{

		}
	}
	else if( result->prev == NULL && result->next != NULL ){
		if(parent->prev == result){

		}else{

		}
	}
	else{
	}
}
void preorder( LINK node ){
	if(node->data != NULL)
		printf("%d",node->data);
	if(node->prev != NULL)	
		preorder(node->prev);
	if(node->next != NULL)
		preorder(node->next);
}

void postorder( LINK node ){
	if(node->prev != NULL)	
		preorder(node->prev);
	if(node->next != NULL)	
		preorder(node->next);
	if(node->data != NULL)
		printf("%d",node->data);
}

void inorder( LINK node ){
	if(node->prev != NULL)
		preorder(node->prev);
	if(node->data != NULL)
		printf("%d",node->data);
	if(node->next != NULL)
		preorder(node->next);

}

void main(void){
	LINK root = NULL;//= (LINK)malloc(sizeof(LINKEDLIST));	
	insertNode(&root,10);
	insertNode(&root,11);
	insertNode(&root,12);
	printf("  PREORDER : ");
	root->order[0](root);
	printf("  POSTORDER : ");
	root->order[1](root);
	printf("  INORDER : ");
	root->order[2](root);
//	printf("  PREORDER : ");
//	preorder(root);
//	printf("  POSTORDER : ");
//	postorder(root);
//	printf("  INORDER : ");
//	inorder(root);
}
/*
void main(){
}*/
/*
int main(int arc, int **argv){
	int k=100;
	int *lk = &k;
	void * pv; 
	char *kdsf = "sdfds";
	int * pi = (int *) 1000; //���

	pv = &k;
	
	printf("%d,%d",pi,*(int *)pv);
	return 0;
}
*/
//*++p
//*p++
//++*p
//(*p)++
//��������

//int * pi;
//const int * pi;
//int * const pi;
//const int * const pi;

/*
int main(int arc, int **argv){
char* pc = (char*)malloc(5*sizeof(char));

int size_char = sizeof(char);
printf("char = %d\n",size_char);
free(pc);
return 0;
}
*/

//���� �Ҵ�
/*
int main(int arc, int **argv){
int len;

printf("�迭�� ũ��");
scanf("%d",&len);
int array[len];
}
*/
/*
struct mydata
{
    int a;
    char b[25];
};
int main()
{
    char buf[255];
    struct mydata data;

    memset(buf, '1', 255);
    buf[254] = 0x00;

    printf("%s\n", buf);
    memset((void *)&data, 0x00, sizeof(data));

}
*/
/*
int main(int arc, int **argv){
	int *arrays;
	int len;
	int i=0;

	printf("�迭�� ũ��");
	scanf("%d",&len);
	arrays = (int*)malloc(sizeof(int)*len);

	memset(arrays, '0', len);

	for(i=0;i<len;i++){
		printf("%d",arrays[i]);
	}
	free(arrays);
}
*/
/*
//1���� �迭
int main(int arc, int **argv){
int a = 10, b = 20, c = 30;
int *p[3] = {&a,&b,&c};
printf("*p[0] = %d, *p[1] = %d",*p[0],*p[1]);
printf("p[0][0] = %d, p[1][0] = %d",p[0][0], p[1][0]);
return 0;
} 
*/

//2���� �迭
/*
int main(int arc, int **argv){
int a[5] = {1,2,3,4,5};
int b[5] = {10,20,30,40,50};
int c[5] = {100,200,300,400,500};

int *p[3] = {a,b,c};
}
*/

/*
int main(int arc, int **argv){
	int col = 0, row= 0;
	int a[3][3] = {{1,2,3},{10,20,30},{100,200,300}};
	int (*pa)[3];
	pa = a;
}
*/


/*
void (*pf)(void);//�Ű������� ���� ��ȯ���� ���� �Լ�������
void one(){
	printf("one");
}
void two(){
	printf("two");
}
void main(){
	pf = one;
	pf();
	pf = two;
	pf();
}
*/

//���� ���ϱ� ���� ���ϱ� ������ ����ȯ �Լ��� �����ϰ� �Լ� �����ͷ� �̸� �����Ű��
//void (*pf)(int*,int*);
//c
//c++

//void change(int m);
//void change1(int *m);
//void change2(int& m);

/*
void change(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main(){
	int a = 3;
	int b = 4;
	pf = change;
	pf(&a,&b);
	printf("%d,%d",a,b);
}
*/

/*
1.	char str[43] = "apple";
2.	char str[43];
	str = "apple";
3.	char* str = "apple";
4.	char* str;
	str = "apple";
*/