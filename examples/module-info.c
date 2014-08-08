#include "ubx.h"


#define WEBIF_PORT	"33000"

int main(int argc, char **argv)
{
        int ret=EXIT_FAILURE;
	ubx_node_info_t ni;

	/* initalize the node */
	ubx_node_init(&ni, "module-info");

	/* load the standard types */
	if(ubx_module_load(&ni, "/home/haianos/amicro/microblx/std_types/stdtypes/stdtypes.so") != 0)
		goto out;
       
       int stdtypenum = ubx_num_types(&ni);
       
       if(ubx_module_load(&ni, "/home/haianos/amicro/microblx/std_blocks/random/random.so") != 0)
                goto out;



	int num = ubx_num_modules(&ni);
        int nb = ubx_num_blocks(&ni);
        int nt = ubx_num_types(&ni);
        printf("Loaded %d modules\n",num);
        printf("Loaded %d blocks\n",nb);
        printf("Loaded types: %d std + %d custom: total %d\n",stdtypenum,nt-stdtypenum,nt);
        ubx_block_t *b, *btmp;
        printf("Prototype Block\n");
        HASH_ITER(hh, ni.blocks, b, btmp) {
          if(b->prototype==NULL)
          {
            if(b->type==BLOCK_TYPE_COMPUTATION)
              printf("bname: %s of type: %s\n",b->name,"cblock");
            if(b->type==BLOCK_TYPE_INTERACTION)
              printf("bname: %s of type: %s\n",b->name,"iblock");
            if(b->type!=BLOCK_TYPE_COMPUTATION && b->type!=BLOCK_TYPE_INTERACTION)
              printf("bname: %s of type: %s\n",b->name,"invalid!");
          }
        }

	ret=EXIT_SUCCESS;
 out:
	/* this cleans up all blocks and unloads all modules */
	ubx_node_cleanup(&ni);
	exit(ret);
}
