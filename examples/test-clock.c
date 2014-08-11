#include "ubx.h"


#define WEBIF_PORT	"33000"

int main(int argc, char **argv)
{
        int retval, i;
        struct ubx_timespec uts;
        retval = ubx_clock_mono_gettime(&uts);
    
        for(i=0;i<10;i++)
        {
          if (retval == 0 )
            printf("I got %lu: %lu\n",uts.sec,uts.nsec);
          else
          {
            printf("Error");
            exit(1);
          }
        }
        
	exit(0);
}
