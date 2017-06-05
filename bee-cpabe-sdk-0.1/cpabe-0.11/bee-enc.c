#include <string.h>
#include <unistd.h>
#include <glib.h>
#include <pbc.h>
#include <pbc_random.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bswabe.h"
#include "common.h"
#include "policy_lang.h"

char* pub_file = 0;
char* in_file  = 0;
char* out_file = 0;
int   keep     = 0;

char* policy = 0;


int enc(char* pub_key, char* plain, char* str_policy, char* cipher){
	bswabe_pub_t* pub;
	bswabe_cph_t* cph;
	int file_len;
	GByteArray* plt;
	GByteArray* cph_buf;
	GByteArray* aes_buf;
	element_t m;

	//pub_file = pub_key;
	//in_file = in_name;

    	if((policy = parse_policy_lang(str_policy)) == NULL){ return -1;}

	if(!strcmp(cipher,"default")){
		out_file = g_strdup_printf("%s.cpabe", plain);
	}else{
		out_file = cipher;
	}

    	pub = bswabe_pub_unserialize(suck_file(pub_key), 1);
	
    	if(!(cph = bswabe_enc(pub, m, policy))){
		return die("%s", bswabe_error());
	}

        free(policy);
	cph_buf = bswabe_cph_serialize(cph);
	bswabe_cph_free(cph);
	plt = suck_file(plain);
	file_len = plt->len;
	aes_buf = aes_128_cbc_encrypt(plt, m);
	g_byte_array_free(plt, 1);
	element_clear(m);
 
 	if(write_cpabe_file(out_file, cph_buf, file_len, aes_buf)==-1){
		return -1;
	}
 
	g_byte_array_free(cph_buf, 1);
	g_byte_array_free(aes_buf, 1);
 
	if( !keep )
 		unlink(plain);
	return 0;
}
