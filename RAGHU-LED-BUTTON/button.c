#include <stdio.h>
#include "contiki.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"

PROCESS(button_process, "Test Button");
AUTOSTART_PROCESSES(&button_process);

static uint8_t flag;
PROCESS_THREAD(button_process,ev,data)
{
PROCESS_BEGIN();
flag=0;
SENSORS_ACTIVATE(button_sensor);
while(1)
{
PROCESS_WAIT_EVENT_UNTIL(ev==sensors_event && data==&button_sensor); //event  triggered is LED Process and data is provded by Button Press
leds_toggle(LEDS_ALL);
if(!flag)
{
leds_on(LEDS_BLUE);
printf("LED BLUE %d\n",leds_get()); //here leds_get() fetches the status of LED
}
else 
{
printf("LED BLUE %d\n",leds_get());
leds_off(LEDS_BLUE);
}
flag ^= 1; // Here ^ is Exor Operation
leds_toggle(LEDS_ALL);
}
PROCESS_END();
}
