ROOT_DIR=$(CURDIR)/../..
include $(ROOT_DIR)/make.conf
INCLUDE_DIR=$(ROOT_DIR)/src/
SUBDIR_INSTALL=/lib/ubx/std_blocks/ptrig

# compile types to hexarrays
TYPES:=$(wildcard types/*.h)
HEXARRS:=$(TYPES:%=%.hexarr)

%.h.hexarr: %.h
	../../tools/file2carr.lua $<

ptrig.so: ptrig.o $(INCLUDE_DIR)/libubx.so
	${CC} $(CFLAGS_SHARED) -o ptrig.so ptrig.o -pthread $(INCLUDE_DIR)/libubx.so

ptrig.o: ptrig.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c $(HEXARRS)
	${CC} -fPIC -pthread -I$(INCLUDE_DIR) -c $(CFLAGS) ptrig.c

install: ptrig.o $(UBX_LIB)
	if [ ! -d "$(UBX_INSTALL)$(SUBDIR_INSTALL)" ]; then mkdir -p $(UBX_INSTALL)$(SUBDIR_INSTALL); fi
	${CC} $(CFLAGS_SHARED) $(LDFLAGS) -shared -o  $(UBX_INSTALL)$(SUBDIR_INSTALL)/ptrig.so ptrig.o -pthread -lubx

clean:
	rm -f *.o *.so *~ core $(HEXARRS)