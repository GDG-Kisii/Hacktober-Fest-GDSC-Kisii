#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrew Mbugua");
MODULE_DESCRIPTION("A Hello World Kernel Module");

/**@brief this function is called,when the device file is opened       
                                                                       
 */
static int __init ModuleInit(void){

printk("Hello Kernel");
return 0;
}
/** @brief executes when module exits the Kernel
*
*/
static void __exit ModuleExit(void){
printk("Goodbye, Kernel");

}
module_init(ModuleInit);
module_exit(ModuleExit);


