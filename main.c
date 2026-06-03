#include <zephyr/kernel.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    /* USB alt yapısını fiziksel olarak başlatır */
    int ret = usb_enable(NULL);
    if (ret != 0) {
        LOG_ERR("USB baslatilamadi: %d", ret);
        return ret;
    }

    LOG_INF("USB CDC-ACM basariyla aktif edildi.");

    /* İşlemcinin sürekli açık kalması için döngü */
    while (1) {
        k_sleep(K_FOREVER);
    }

    return 0;
}
