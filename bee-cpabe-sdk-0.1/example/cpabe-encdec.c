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

	unsigned char plaintext[256];
	unsigned char* ciphertext = "PLAIN";

	scanf("%s", plaintext);

	// ENCRYPTION PROCESS
	int enc_length = 0;
	enc_length=enc("./cpabe_publickey", plaintext, "jackie and s >= 100", &ciphertext);
	if(enc_length==-1){
		printf("ENC FAIL\n");
		return -1;
	}
	printf("enc_length = %d\n",enc_length);
	printf("ENC SUCCESS: (%s->%s)\n", plaintext, ciphertext);

	// DECRYPTION PROCESS
	unsigned char* result = 0;

	if(dec("./cpabe_publickey", "./cpabe_secretkey", ciphertext, &result)==-1){
		printf("DEC FAIL\n");
		return -1;
	}
	printf("DEC SUCCESS: (%s->%s)\n", ciphertext, result);

	free(ciphertext);
	free(result);

	return 0;
}

