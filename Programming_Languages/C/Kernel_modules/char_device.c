#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrew Mbugua");
MODULE_DESCRIPTION("Registers a device and implement some call back fuction");

/**
 *@brief This function is called,when the device file is opened
 */
static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_nr - open was called!\n");
	return 0;
}
/**
 *@brief 2 - This function is called,when the device file is opened
 	 When you "open" always remember to close
 */
static int driver_close(struct inode *device_file, struct file *instance){
        printk("dev_nr - close was called!\n");
        return 0;
}

static struct file_operations fops = {
		.owner = THIS_MODULE,
		.open = driver_open,
		.release = driver_close


};

#define MYMAJOR 90

static int __init ModuleInit(void){
	int retval;
	printk("Hello Kernel");
	/* register device nr. */

	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);
		if (retval == 0){
			printk("dev_nr - registered Device number Major: %d, Minor: %d\n",MYMAJOR,0);
}
 		if (retval > 0){
                        printk("dev_nr - registered Device number Major:%d, Minor: %d\n", retval >> 20, retval&0xfffff);
}
else{
	printk("Could not register device number");
	return -1;
}

	return 0;
}
