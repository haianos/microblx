ROOT_DIR=$(CURDIR)/../..
include $(ROOT_DIR)/make.conf
INCLUDE_DIR=$(ROOT_DIR)/src/
SUBDIR_INSTALL=/lib/ubx/std_blocks/hexdump

hexdump.so: hexdump.o $(INCLUDE_DIR)/libubx.so
	${CC} $(CFLAGS_SHARED) -o hexdump.so hexdump.o $(INCLUDE_DIR)/libubx.so

hexdump.o: hexdump.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c
	${CC} -fPIC -I$(INCLUDE_DIR) -c $(CFLAGS) hexdump.c

install: hexdump.o
	if [ ! -d "$(UBX_INSTALL)$(SUBDIR_INSTALL)" ]; then mkdir -p $(UBX_INSTALL)$(SUBDIR_INSTALL); fi
	${CC} $(CFLAGS_SHARED) $(LDFLAGS) -o $(UBX_INSTALL)$(SUBDIR_INSTALL)/hexdump.so hexdump.o -lubx

clean:
	rm -f *.o *.so *~ core