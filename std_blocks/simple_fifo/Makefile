ROOT_DIR=$(CURDIR)/../..
include $(ROOT_DIR)/make.conf
INCLUDE_DIR=$(ROOT_DIR)/src/
SUBDIR_INSTALL=/lib/ubx/std_blocks/simple_fifo

simple_fifo.so: simple_fifo.o $(INCLUDE_DIR)/libubx.so
	${CC} $(CFLAGS_SHARED) -o simple_fifo.so simple_fifo.o $(INCLUDE_DIR)/libubx.so

simple_fifo.o: simple_fifo.c $(INCLUDE_DIR)/ubx.h $(INCLUDE_DIR)/ubx_types.h $(INCLUDE_DIR)/ubx.c
	${CC} -fPIC -I$(INCLUDE_DIR) -c $(CFLAGS) simple_fifo.c

install: simple_fifo.o $(UBX_LIB)
	if [ ! -d "$(UBX_INSTALL)$(SUBDIR_INSTALL)" ]; then mkdir -p $(UBX_INSTALL)$(SUBDIR_INSTALL); fi
	${CC} $(CFLAGS_SHARED) $(LDFLAGS) -o $(UBX_INSTALL)$(SUBDIR_INSTALL)/simple_fifo.so simple_fifo.o -lubx

clean:
	rm -f *.o *.so *~ core