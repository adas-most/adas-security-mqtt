#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <glib.h>
#include <pbc.h>
#include <pbc_random.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "bswabe.h"
#include "../cpabe-0.11/common.h"
#include "../beecpabe.h"

int main(void){
	if(fdec("./cpabe_publickey","./cpabe_secretkey","./cat.jpg.cpabe")==-1){
		printf("DEC FAIL\n");
		return -1;
	}
	printf("DEC SUCCESS\n");
	return 0;
}

