top_srcdir = .
prefix = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
mandir = ${prefix}/share/man

cpabe_dir = ${top_srcdir}/cpabe-0.11
example_dir = ${top_srcdir}/example
pbc_dir = ${top_srcdir}/pbc-0.5.14
bswabe_dir = ${top_srcdir}/libbswabe-0.9

CC = gcc
CFLAGS  = -O3 -Wall -g \
	-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include   \
	 \
	-I/usr/include/pbc -I/usr/local/include/pbc \
	 \
	-DPACKAGE_NAME=\"cpabe\" -DPACKAGE_TARNAME=\"cpabe\" -DPACKAGE_VERSION=\"0.11\" -DPACKAGE_STRING=\"cpabe\ 0.11\" -DPACKAGE_BUGREPORT=\"bethenco@cs.berkeley.edu\" -DPACKAGE_URL=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DSTDC_HEADERS=1 -DHAVE_FCNTL_H=1 -DHAVE_STDDEF_H=1 -DHAVE_STRING_H=1 -DHAVE_STDLIB_H=1 -DHAVE_MALLOC=1 -DLSTAT_FOLLOWS_SLASHED_SYMLINK=1 -DHAVE_VPRINTF=1 -DHAVE_LIBCRYPTO=0 -DHAVE_LIBCRYPTO=0 -DHAVE_STRCHR=1 -DHAVE_STRDUP=1 -DHAVE_MEMSET=1 -DHAVE_GMP=1 -DHAVE_PBC=1 -DHAVE_BSWABE=1
LDFLAGS = -L. -lbee-cpabe-0.1 \
	-lglib-2.0   \
	-Wl,-rpath /usr/local/lib -lgmp \
	-Wl,-rpath /usr/local/lib -lbswabe \
	-lpbc \
	-lcrypto -lgmp
DISTNAME = bee-cpabe-0.11

TARGETS  = libbee-cpabe-0.1.a cpabe-setup cpabe-keygen cpabe-enc cpabe-dec cpabe-encdec
DEVTARGS = test-lang TAGS

MANUALS  = $(TARGETS:=.1)
HTMLMANS = $(MANUALS:.1=.html)

all: $(TARGETS)

libbee-cpabe-0.1.so: ${cpabe_dir}/bee-setup.o ${cpabe_dir}/common.o ${cpabe_dir}/bee-enc.o ${cpabe_dir}/policy_lang.o ${cpabe_dir}/bee-keygen.o ${cpabe_dir}/bee-dec.o
	$(CC) -shared -o $@ $^ 
	ln -f -s $@ libbee-cpabe.so

# user-level compilation
libbee-cpabe-0.1.a: ${cpabe_dir}/bee-setup.o ${cpabe_dir}/common.o ${cpabe_dir}/bee-enc.o ${cpabe_dir}/policy_lang.o ${cpabe_dir}/bee-keygen.o ${cpabe_dir}/bee-dec.o
#	$(CC) -c $^ $(CFLAGS)
	$(AR) rcs -o $@ $^ 
	ln -f -s $@ libbee-cpabe.a

#setup.o common.o enc.o policy_lang.o keygen.o dec.

cpabe-setup:$(example_dir)/cpabe-setup.o 
	$(CC) -o $(example_dir)/$@ $^ $(LDFLAGS)

cpabe-keygen:$(example_dir)/cpabe-keygen.o 
	$(CC) -o $(example_dir)/$@ $^ $(LDFLAGS)

cpabe-enc:$(example_dir)/cpabe-enc.o
	$(CC) -o $(example_dir)/$@ $^ $(LDFLAGS)

cpabe-dec:$(example_dir)/cpabe-dec.o
	$(CC) -o $(example_dir)/$@ $^ $(LDFLAGS)

cpabe-encdec:$(example_dir)/cpabe-encdec.o
	$(CC) -o $(example_dir)/$@ $^ $(LDFLAGS)

%.o: %.c *.h Makefile
	$(CC) -c -o $@ $< $(CFLAGS)

#libpbc:
#	$(shell cd ${pbc_dir}; sh configure; make; sudo make install)

#libbswabe:
#	$(shell cd ${bswabe_dir}; sh configure; make; sudo make install)

clean:
	rm -f libbee-cpabe-0.1.a libbee-cpabe.a
	rm -f ${example_dir}/cpabe-setup ${example_dir}/cpabe-keygen ${example_dir}/cpabe-enc ${example_dir}/cpabe-dec ${example_dir}/cpabe-encdec ${example_dir}/*.o 
	rm -f ${example_dir}/cpabe_publickey ${example_dir}/cpabe_masterkey ${example_dir}/cpabe_secretkey* ${example_dir}/cat.jpg.cpabe
	$(shell cd cpabe-0.11; rm -f *.o)
