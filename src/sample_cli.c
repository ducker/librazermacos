#include<stdio.h>
#include "razerdevice.h"
#include "razerkbd_driver.h"

int main(int argc, const char * argv[]) {
    RazerDevices allDevices = getAllRazerDevices();
    RazerDevice *razerDevices = allDevices.devices;

    printf("%d Razer device(s) found:\n", allDevices.size);

    for (int i = 0; i < allDevices.size; i++) {
        RazerDevice device = razerDevices[i];
        printf("%#06x\n", device.productId);

        // Testing out the deathstalker v2 pro to set static green color
        if (device.productId == 0x0292)
        {
            printf("Found deathstalker v2 pro keyboard (wired)\n");
            char color[] = {0x00, 0xff, 0x00};
            razer_attr_write_mode_static(device.usbDevice, color, 3);
        }
    }

    closeAllRazerDevices(allDevices);
    return 0;

}
