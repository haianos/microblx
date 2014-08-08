ROOT_DIR=$(CURDIR)/../..
include $(ROOT_DIR)/make.conf
INCLUDE_DIR=$(ROOT_DIR)/src/
SUBDIR_INSTALL=/lib/ubx/std_blocks/luablock

TYPES:=$(wildcard types/*.h)
HEXARRS:=$(TYPES:%=%.hexarr)

luablock.so: luablock.o $(INCLUDE_DIR)/libubx.so 
	${CC} $(CFLAGS_SHARED) -o luablock.so luablock.o $(INCLUDE_DIR)/libubx.so -lluajit-5.1  -lpthread

luablock.o: luablock.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c $(HEXARRS)
	${CC} -fPIC -I$(INCLUDE_DIR) -c $(CFLAGS) luablock.c

install: luablock.o $(UBX_LIB)
	if [ ! -d "$(UBX_INSTALL)$(SUBDIR_INSTALL)" ]; then mkdir -p $(UBX_INSTALL)$(SUBDIR_INSTALL); fi
	${CC} $(CFLAGS_SHARED) $(LDFLAGS) -o $(UBX_INSTALL)$(SUBDIR_INSTALL)/luablock.so luablock.o -lluajit-5.1  -lpthread -lubx

clean:
	rm -f *.o *.so *~ core $(HEXARRS)
