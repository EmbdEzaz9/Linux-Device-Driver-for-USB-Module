//<1> Include Header Files

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/usb.h>

//<2> Define Vendor & Product ID

#define VENDOR_ID 0X02EB   // Maufacture Id
#define PRODUC_ID 0X02EB   // Specific Id

//<3> USB Device ID Table

static struct usb_device_id  usb_dev_table[]={
{  USB_DEVICE(VENDOR_ID,PRODUC_ID)},
{},
};

MODULE_DEVICE_TABLE(usb, usb_dev_table);

//<4> Prob Function/Usb Driver FFunction

static int my_usb_probe(struct usb_interface *interface,const struct usb_device_id *id){
printk(KERN_INFO "USB pendrive plugged in(%04X:%04X) \n",
id-> idVendor, id-> idProduct);
return 0;
}

//<5> Disconnect Functiion


static void my_usb_disconnect(struct usb_interface *interface){
printk(KERN_INFO "USB pendrive removed");}													

// <6> Usb Device Driver structure

static struct usb_driver my_usb_driver ={	
.name=my_usb_driver,
.idtable=usb_dev_table,
.probe=my_usb_probe,
.disconnect=my_usb_disconnect,}	;

// <7> Register the driver with USB-Core

static int __init USBDriver_init(void){						
int result;
printk(KERN_INFO "Registering driver with kernel \n");
result=usb_register(&my_usb_driver);
printk(KERN_INFO "Registration is completed \n");
if(result)
{	
printk(KERN_INFO "Registering error \n");
return_result;
}
return 0;
}


//<8> Deregister the Driver
static void __exit USBDriver_exit(void){
printk(KERN_INFO "Unregistration..\n");
usb_deregister(&my_usb_driver);
printk(KERN_INFO "Unregistering is completed \n");
}	

//<9> Module Entry & Exit Point

module_init(USBDriver_init);
module_exit(USBDriver_exit);

// <10> Meta data
MODULE_LICENSE("GPL");




