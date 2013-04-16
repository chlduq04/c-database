//실제값들이 무엇인지 확인해 보기
//*++p
//*p++
//++*p
//(*p)++


//서로 다른점을 확인해 보기
//int * pi;
//const int * pi;
//int * const pi;
//const int * const pi;


//동적할당 하는 법 알아보기
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

//struct 기본개념
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

//포인터와 배열 정의, 그리고 memset으로 초기화 해보기
/*
int main(int arc, int **argv){
	int *arrays;
	int len;
	int i=0;

	printf("배열의 크기");
	scanf("%d",&len);
	arrays = (int*)malloc(sizeof(int)*len);
	memset(arrays, '0', len);
	//arrays = (int*)calloc(sizeof(int)*len);
	for(i=0;i<len;i++){
		printf("%d",arrays[i]);
	}
	free(arrays);
}
*/

//1차원 배열과 2차원 배열 사용하기
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


//배열을 포인터로 받아서 사용하기
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


//함수형 포인터와 
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