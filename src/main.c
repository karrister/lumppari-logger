#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

int main(void)
{
    printk("Lumppari Logger started!\n");

    while (1) {
        k_sleep(K_SECONDS(10));
        printk("Logger alive\n");
    }

    return 0;
}