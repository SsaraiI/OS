//64050050
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum, csum;
void *runner(void *param);
void parent(int num);

int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	//2.2
	pthread_create(&tid, &attr, runner, argv[1]);
	
	//2.5
	//pthread_join(tid, NULL);

	int num = atoi(argv[1]);
	//2.3
	parent(num);
	int diff = csum - msum;
	//2.4
	printf("difference between msum and csum = %d\n", abs(diff));
	return 0;
}

//2.2
void *runner(void *param) {
	int upper = atoi(param);
	int i;
	csum = 0;
	if (upper > 0) {
		for(i = 0; i <= (upper*2); i++) {
			csum += i;
		}
	}
	printf("csum = %d\n", csum);
	pthread_exit(0);
}

//2.3
void parent(int num) {
	int i;
	msum = 0;
	if (num > 0) {
		for(i = 0; i <= num; i++) {
			msum += i;
		}
	}
	printf("msum = %d\n", msum);
}

//2.5 have 2 case: 
//if input 5
//case 1 :child finish before parent
//case 2 :parent finish before child
