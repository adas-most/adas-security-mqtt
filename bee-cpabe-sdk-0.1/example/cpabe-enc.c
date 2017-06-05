#include <errno.h>
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
#include "../cpabe-0.11/policy_lang.h"
#include "../beecpabe.h"

int main(void){
	if(enc("./cpabe_publickey","./cat.jpg","jackie and s >= 100","default")==-1){
		printf("ENC FAIL\n");
		return -1;
	}
	printf("ENC SUCCESS\n");
	return 0;
}

