/**************************************************
 * Nintendo Switch Pro Controll USB HID driver
 * Author: Ennis Massey <ennisbaradine@gmail.com>
 * Credit to: shinyquagsire23, ToadKing and dekuNukem for reverse-engineering the handshake codes
 * Based on: USB Skeleton Driver by Greg Koah-Hartman
 * ***********************************************/


#include <linux/module.h>
#include <linux/usb.h>
#include <linux/hid.h>

MODULE_AUTHOR("Ennis Massey");
MODULE_VERSION("0.01");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Driver for Switch Pro Controller using USB-C cable");

/* Table of USB ID's this driver supports */
static const struct hid_device_id pro_controller_table[] = {
        {
                HID_USB_DEVICE(0x057e, 0x2009) /* Pro Controller */
        }, {}
};

MODULE_DEVICE_TABLE(hid, pro_controller_table);

/* Functions for handling actual input */

/**
 * Handles probing (verification and startup) of Pro Controller
 **/
static int pro_controller_probe(struct hid_device *dev, const struct hid_device_id *id) 
{
        hid_info(dev, "Pro Controller plugged in, probing\n");
        return 0;
}



/**
 * Handles disconnecting the controller
 **/
static void pro_controller_remove(struct hid_device *dev) 
{

}



static struct hid_driver pro_controller_driver = {
        .name = "pro_controller",
        .probe = pro_controller_probe,
        .id_table = pro_controller_table,
        .remove = pro_controller_remove
};

module_hid_driver(pro_controller_driver)