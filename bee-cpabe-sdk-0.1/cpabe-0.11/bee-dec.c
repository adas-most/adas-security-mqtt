#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <glib.h>
#include <pbc.h>
#include <pbc_random.h>
#include <stdio.h>
#include <stdlib.h>
#define MILLION 1000000
#include <time.h>
#include "bswabe.h"
#include "common.h"

char* pub_file   = 0;
char* prv_file   = 0;
char* in_file    = 0;
char* out_file   = 0;
/* int   no_opt_sat = 0; */
/* int   report_ops = 0; */
int   keep       = 0;

int dec(char* pub_pathname, char* priv_name, char* file_pathname){

	bswabe_pub_t* pub;
	bswabe_prv_t* prv;
	int file_len;
	GByteArray* aes_buf;
	GByteArray* plt;
	GByteArray* cph_buf;
	GByteArray* sf_pf;
	GByteArray* sf_prvf;
	bswabe_cph_t* cph;
	element_t m;

	pub_file = pub_pathname;
	prv_file = priv_name;
	in_file  = file_pathname;

	if(keep && !strcmp(in_file, out_file) ){
		printf("cannot keep input file when decrypting file in place \n");
	}	

	if((sf_pf = suck_file(pub_file)) == NULL) {
		return -1;
	}
	if((sf_prvf = suck_file(prv_file)) == NULL){
		return -1;
	}
	if((read_cpabe_file(in_file, &cph_buf, &file_len, &aes_buf))==-1){
		return -1;
	}

	pub = bswabe_pub_unserialize(sf_pf, 1);
	 
	prv = bswabe_prv_unserialize(pub,sf_prvf, 1);
	cph = bswabe_cph_unserialize(pub, cph_buf, 1);
 
	if(!bswabe_dec(pub, prv, cph, m)){
		return die("%s", bswabe_error());
	}
	
	bswabe_cph_free(cph);
	
	plt = aes_128_cbc_decrypt(aes_buf, m);
	g_byte_array_set_size(plt, file_len);
	g_byte_array_free(aes_buf, 1);

	if(strlen(in_file) > 6 && !strcmp(in_file + strlen(in_file) - 6, ".cpabe") ){
		out_file = g_strndup(in_file, strlen(in_file) - 6);
	}else{
		out_file = strdup(in_file);
		keep=1;
	}

	if(spit_file(out_file, plt, 1)==-1){
		return -1;
	}

	if( !keep )
		unlink(in_file);

	return 0;
}