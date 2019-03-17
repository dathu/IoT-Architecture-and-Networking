#include "contiki.h" // contiki libray header files
#include <stdio.h>   // standard C header file


PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);


PROCESS_THREAD(hello_world_process, ev, data) 
{
  PROCESS_BEGIN(); 
  printf("Hello, world\n"); 
 // printf("%s\n", hello);
 // printf("This is a value in hex 0x%02X, the same as %u\n", num, num);
  PROCESS_END(); 
}
