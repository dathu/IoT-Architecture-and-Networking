#include "contiki.h" // contiki libray header files
#include <stdio.h>   // standard C header file


// here their is no main() insted program starts with processes thread
PROCESS(my_SOIS_app, "MYSOIS");//Here process is my_SOIS_app and its name is MYSOIS
AUTOSTART_PROCESSES(&my_SOIS_app); //  kernal autostarts from this memory location

PROCESS_THREAD(my_SOIS_app,ev,data) // no stack implementation its a process that run using process anme, env info, kernal data
{
static int i =10;
PROCESS_BEGIN();

printf("We are SOIS %d", i); // logic must be implemented between process begin and end

PROCESS_END();
}
