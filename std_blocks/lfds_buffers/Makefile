ROOT_DIR=$(CURDIR)/../..
include $(ROOT_DIR)/make.conf
INCLUDE_DIR=$(ROOT_DIR)/src/
SUBDIR_INSTALL=/lib/ubx/std_blocks/lfds_buffers

default: lfds_cyclic.so lfds_cyclic_raw.so

lfds_cyclic.so: lfds_cyclic.o $(INCLUDE_DIR)/libubx.so liblfds611/bin/liblfds611.a
	${CC} $(CFLAGS_SHARED) -o lfds_cyclic.so lfds_cyclic.o liblfds611/bin/liblfds611.a $(INCLUDE_DIR)/libubx.so

lfds_cyclic.o: lfds_cyclic.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c
	${CC} -fPIC -I$(INCLUDE_DIR) -c $(CFLAGS) lfds_cyclic.c

lfds_cyclic_raw.so: lfds_cyclic_raw.o $(INCLUDE_DIR)/libubx.so liblfds611/bin/liblfds611.a
	${CC} $(CFLAGS_SHARED) -o $@ $^ liblfds611/bin/liblfds611.a $(INCLUDE_DIR)/libubx.so

lfds_cyclic_raw.o: lfds_cyclic_raw.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c
	${CC} -fPIC -I$(INCLUDE_DIR) -c $(CFLAGS) lfds_cyclic_raw.c

liblfds611/bin/liblfds611.a:
	$(shell mkdir -p liblfds611/obj liblfds611/bin)
	make -C liblfds611

install: lfds_cyclic.o lfds_cyclic_raw.o liblfds611/bin/liblfds611.a $(UBX_LIB)
	if [ ! -d "$(UBX_INSTALL)$(SUBDIR_INSTALL)" ]; then mkdir -p $(UBX_INSTALL)$(SUBDIR_INSTALL); fi
	${CC} $(CFLAGS_SHARED) $(LDFLAGS) -o $(UBX_INSTALL)$(SUBDIR_INSTALL)/lfds_cyclic.so lfds_cyclic.o liblfds611/bin/liblfds611.a -lubx
	${CC} $(CFLAGS_SHARED) $(LDFLAGS) -o $(UBX_INSTALL)$(SUBDIR_INSTALL)/lfds_cyclic_raw.so lfds_cyclic_raw.o liblfds611/bin/liblfds611.a -lubx

clean:
	rm -f *.o *.so *~ core
	make -C liblfds611 clean
