ROOT_DIR=$(CURDIR)/../..
include $(ROOT_DIR)/make.conf
INCLUDE_DIR=$(ROOT_DIR)/src/
SUBDIR_INSTALL=/lib/ubx/std_types/stdtypes

stdtypes.so: stdtypes.o $(INCLUDE_DIR)/libubx.so
	${CC} -shared -o stdtypes.so stdtypes.o $(INCLUDE_DIR)/libubx.so

stdtypes.o: stdtypes.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c
	${CC} -fPIC -I$(INCLUDE_DIR) -c $(CFLAGS) stdtypes.c

install: stdtypes.o $(UBX_LIB)
	if [ ! -d "$(UBX_INSTALL)$(SUBDIR_INSTALL)" ]; then mkdir -p $(UBX_INSTALL)$(SUBDIR_INSTALL); fi
	${CC} $(LDFLAGS) -shared -o $(UBX_INSTALL)$(SUBDIR_INSTALL)/stdtypes.so stdtypes.o -lubx

clean:
	rm -f *.o *.so *~ core