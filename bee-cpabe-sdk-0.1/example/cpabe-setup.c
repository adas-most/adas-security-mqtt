#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <glib.h>
#include <pbc.h>
#include <pbc_random.h>
//#include "bswabe.h"
#include "../cpabe-0.11/common.h"
#include "../beecpabe.h"

int main(void){

	if(setup("./cpabe_publickey","./cpabe_masterkey")==-1){
		printf("SETUP ERROR!\n");
		return -1;
	}
	printf("SETUP SUCCESS\n");
	return 0;
}
