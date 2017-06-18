#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <glib.h>
#include <pbc.h>
#include <pbc_random.h>
#include <stdarg.h>
//#include "bswabe.h"
#include "../cpabe-0.11/common.h"
#include "../cpabe-0.11/policy_lang.h"
#include "../beecpabe.h"

int main(void)
{
	if(keygen("./cpabe_secretkey_ok","./cpabe_publickey","./cpabe_masterkey",4,"jackie","boy","a = 12","s = 1000")==-1){
		printf("OK KEYGEN ERROR\n");
		return -1;
	}
	printf("OK KEYGEN SUCCESS\n");

	char* p[] = {"jackies","boy","a = 12","s = 1000"};
	
	if(vkeygen("./cpabe_secretkey_ng","./cpabe_publickey","./cpabe_masterkey",4,p/*{"jackies","boy","a = 12","s = 1000"}*/)==-1){
		printf("NG KEYGEN ERROR\n");
		return -1;
	}
	printf("NG KEYGEN SUCCESS\n");
	
	return 0;
}
