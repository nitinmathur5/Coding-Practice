#include <stdio.h>
#include <string.h>
//#include <iostream>
/*
int myfunction(char *q) {
	//memcpy(q, "hello", 6);
	
} */

void myfunction(char *q) {
	memcpy(q, "Welcome to Turing", 8);
	
}

void myfucntion() {
	
	static int x = 5;
	x++;
	printf("%d", x);
}

//#define SWAP (a, b, c) (c t; t = a; a=b; b = t)
int main()
{ 
	int array[4][3] = {{1},{2,3,4}, {5,6});
	printf("%d", sizeof(array));

/*
	int *aPtr = new int;
	*aPtr = 100;
	printf("%d", (*aPtr + 2));

	int x= 10, y=20;
	SWAP(x, y, int);
	printf("%d %d", x, y);

struct pp {
		int x;
		int y;
	};

	struct pp p1[] = {1,2,3,4,5,6};
	struct pp *ptr1 = &p1;
	printf("%d %d", ptr1->x, (ptr1+2)->x);
	
	struct student m;
	struct student *s = &m;
	s->name = "Turing";
	printf("%s", s->name);

 
	float yoe = 0.9;
	if(yoe == 0.9)
		printf("A");
	else 
		printf("B");
	float y = 0.45;	
	if(yoe == 0.45)
		printf("A");
	else 
		printf("B");
	
 
	char t [20] = "ABCDEFGHIJK";
	int s = strlen(t);
	t[3] = '\0';
	s = strlen(t);
	printf("%d", s);
	
	
 static int ary[] = {1,3,5};
	printf("%d %d", ary[-1], ary[5]);
	return 0;
 
 
	FILE *fp = stdout;
	int n;
	fprintf(fp, "%d", 45);
	fflush(stdout);
	fprintf(stderr, "%d", 65);
	return 0;



	char *dt = malloc(8);
	myfunction(dt);
	printf(dt);


	int a = 10;
	int *p=b;
	printf("%d %d", &b, &p);
	
	myfucntion();
	myfucntion();

	char *p = "";
	myfunction(p);
	printf(p);

	
	char a = 'A', b ='B';
printf("%d", a&b);
return 0;	

	
	register  i = 20;
	register *j = &i;
	printf("%d", *j);
		*/
		
		return 0;
}