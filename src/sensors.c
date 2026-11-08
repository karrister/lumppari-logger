#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define SENSORS_STACK_SIZE 1024
#define SENSORS_PRIORITY   5

static void sensors_thread(void *p1, void *p2, void *p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    printk("Sensors thread started\n");

    while (true) {
        // TODO: Read DS18B20 and other sensors

        printk("Sensors read:\n");
        k_sleep(K_SECONDS(10));
    }
}

K_THREAD_DEFINE(sensors_tid,
                SENSORS_STACK_SIZE,
                sensors_thread,
                NULL, NULL, NULL,
                SENSORS_PRIORITY,
                0,
                0);