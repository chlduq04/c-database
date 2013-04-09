#include <stdio.h>
#include <stdlib.h>
struct linkedlist{
	int data;
	struct linkedlist *next;
	struct linkedlist *prev;
};
typedef	struct linkedlist LINKEDLIST;
typedef LINKEDLIST *LINK;

LINK newList( int data ){
	LINK list;
	list = (LINK)malloc(sizeof(LINKEDLIST));
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
	return list;
}
LINK newListNode(LINK node, int data){
	node = (LINK)malloc(sizeof(LINKEDLIST));
	node->data = data;
	return node;
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
void appendTree( LINK head, int data ){
	if( head == NULL ){
//		head = newList(data);
		head= (LINK)malloc(sizeof(LINKEDLIST));
		head->data = data;
	}else{
		if(head->prev == NULL){
			appendTree( head->prev, data );
		}else if(head->next == NULL){
			appendTree( head->next, data );
		}
	}
}
void heapTree( LINK *node, int data ){
	if( *node == NULL ){
		*node = newList(data);
	}else{
		if( (*node)->data > data ){
			heapTree( &((*node)->prev) , data );
		}else{
			heapTree( &((*node)->next) , data );
		}
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
	heapTree(&root,11);
	heapTree(&root,10);
	heapTree(&root,12);

	printf("  PREORDER : ");
	preorder(root);
	printf("  POSTORDER : ");
	postorder(root);
	printf("  INORDER : ");
	inorder(root);

//	init( head, tail );
//	appendList( head, newList(4) );
//	appendList( head, newList(3) );
//	appendList( head, newList(2) );
//	appendList( head, newList(1) );
//	deleteList( head, findList( head, 1 ) );
//	deleteList( head, findList( head, 3 ) );
//	printList(head,tail);
//	free(head);
//	free(tail);
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
	int * pi = (int *) 1000; //상수

	pv = &k;
	
	printf("%d,%d",pi,*(int *)pv);
	return 0;
}
*/
//*++p
//*p++
//++*p
//(*p)++
//실제값들

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

//동적 할당
/*
int main(int arc, int **argv){
int len;

printf("배열의 크기");
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

	printf("배열의 크기");
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
//1차원 배열
int main(int arc, int **argv){
int a = 10, b = 20, c = 30;
int *p[3] = {&a,&b,&c};
printf("*p[0] = %d, *p[1] = %d",*p[0],*p[1]);
printf("p[0][0] = %d, p[1][0] = %d",p[0][0], p[1][0]);
return 0;
} 
*/

//2차원 배열
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

	//int **p = a[3][3];
	/*
	for(row = 0;row<3;row++){
		for(col = 0;col<3;col++){
			printf("%p",a[row][col]);
		}
	}
	printf("%p\n",pa++);
	printf("%p",pa);
}
*/


/*
void (*pf)(void);//매개변수가 없고 반환값도 없는 함수포인터
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

//문제 더하기 빼기 곱하기 나누기 값교환 함수를 구현하고 함수 포인터로 이를 실행시키기
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