/*
    Include glib.h, pbc.h, pbc_random.h 
 */
int setup(char* pubkey_path, char* mstkey_path);
/*  Function Name: setup
 *  
 *  Purpose:
 *  Generate system parameters, a public key, and a master secret key
 *  for use with keygen, encrytion, decrption
 *
 *  Parameters:
 *  1. pubkey_path: the path of public key (Ex. ./public_key)
 *  2. mstkey_path: the path of master secret key (Ex. ./master_key)
 *
 *  Return:
 *   0: success
 *  -1: failed
 */

int keygen(char* pubkey_path, char* mstkey_path, char* prikey_path, int attr_no, ...);
/*  Function Name: keygen
 *  
 *  Purpose:
 *  Generate a personal key with the listed attributes using public key and master secret key
 *  If you want to know more please find the detail in this link 
 *  http://acsc.cs.utexas.edu/cpabe/cpabe-keygen.html
 *
 *  Parameters:
 *  1. pubkey_path: the path of public key
 *  2. mstkey_path: the path of maskter key 
 *  3. prikey_path: the path of private personal key
 *  4. attr_no: the number of attributes
 *  5. ...: a serial of attributes in two forms, non-numerical and numerical.
 *  (Ex. "boy", "student" are non-numerical form and "salary = 1000", "age >= 18" are numerical form)
 *
 *  Return:
 *   0: success
 *  -1: failed
 */

int enc(unsigned char* pk_path, unsigned char* pt, unsigned char* policy_str, unsigned char** ct);
int fenc(unsigned char* pk_path, unsigned char* pt_path, unsigned char* policy_str, unsigned char* ct_path);
/*  Function Name: enc
 *  
 *  Purpose:
 *  Encrypt plaintext into ciphertext with public key and access policy using cpabe.  
 *
 *  Parameters:
 *  1. pubkey_path: the path of public key
 *  2. plaintext_path: the path of plaintext
 *  3. access_policy: the access policy (Please refer http://acsc.cs.utexas.edu/cpabe/cpabe-enc.html)
 *  (Ex. "boy and salary > 1000")
 *  4. ciphertext_path: the path of ciphertext
 *
 *  Return:
 *   0: success
 *  -1: failed
 */

int dec(unsigned char* pk_path, unsigned char* sk_path, unsigned char* ct, unsigned char** pt);
int fdec(unsigned char* pb_path, unsigned char* sk_path, unsigned char* ct_path);
/*  Function Name: dec
 *  
 *  Purpose:
 *  Decrypt ciphertext into plaintext with public key and private key using cpabe.  
 *
 *  Parameters:
 *  1. pubkey_path: the path of public key
 *  2. prikey_path: the path of private key
 *  3. ciphertext_path: the path of ciphertext
 *
 *  Return:
 *   0: success
 *  -1: failed
 */
