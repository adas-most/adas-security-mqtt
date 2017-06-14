# adas-security-mqtt/bee-cpabe-sdk-1.0

## A. INSTALLATION:
### A.1. Prerequisites: 
Please make sure you have installed the following packages, *m4*, *flex*, *bison*, *libssl-dev*, *libgmp-dev*(**>4.0.0**), and *glib*(**>2.0.0**)

### A.2. Supporting libraries
Please make sure you have installed the following supporting libraries.
1. libpbc: You can download [libpbc](https://crypto.stanford.edu/pbc/) and install it manually.
2. libbswabe: You can download [libbswabe](http://acsc.cs.utexas.edu/cpabe/) and install it manually.

### A.3. Build Bee-CPABE
You can just make, and then
1. You will get the library (libcpabe-x.x.a) and header file (beecpabe.h).
2. You will get the sample programs in examples directory to demonstrate the libcpabe.
	* **cpabe-setup**: generate public key and master key (By default, cpabe\_publickey and cpabe\_masterkey)
	* **cpabe-keygen**: generate secret key with public key and master key. (By default, cpabe\_secretkey_ok and cpabe\_secretkey_ng)
	* **cpabe-enc**: encrypt file with public key and policy
	* **cpabe-dec**: decrypt file with public key and secret key
	* **cpabe-encdec**: encrypt and decrypt non-file data

## REFERENCE
[1] http://blog.csdn.net/huifeideyema/article/details/51695231 
