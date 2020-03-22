#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/types.h> /*uint8_t*/


/*GLOBAL*/
const static uint8_t gpio_led = 17;//GPIO17,pin11

/*
 *#define GPIO25 25 // pin22 on raspberry pi 3
 */




static int __init gpio_init(void){
  	pr_info(KERN_INFO "RQST_GPIO: module iniialize");
	gpio_request(gpio_led,"LED RED");
  	if (gpio_request(gpio_led, "LED red") == 0){
		pr_err(KERN_ERR "GPIO request failed for LED "
					"selection, gpio: 17\n");
		return 0;
	}else
	gpio_direction_output(gpio_led,false);
  	gpio_set_value(gpio_led, true);
  	pr_info(KERN_INFO ": gpio 17 LED On");
  	msleep(500);
  	gpio_set_value(gpio_led, false);
  	pr_info(KERN_INFO ": gpio25 LED OFF");
  	gpio_free(gpio_led);
  	return 0;
}

static void __exit gpio_exit(void){
	pr_info(KERN_INFO "RQST_GPIO: mpodule exit");
}
module_init(gpio_init);
module_exit(gpio_exit);

MODULE_AUTHOR("Polin Chen");
MODULE_DESCRIPTION("Basic GPIO Module example!");
MODULE_LICENSE("GPL");
