#include <stdio.h>
#include "esp_log.h"
#include "esp_flash.h" // 修正: esp_flash.h をインクルード
//#include "esp_partition.h" // 修正: esp_partition.h をインクルード


void app_main(void) {
    // デフォルトのフラッシュチップを指すポインタを取得
    esp_flash_t *flash = esp_flash_default_chip;

    // フラッシュチップのサイズを取得
    uint32_t flash_size;
    esp_err_t ret = esp_flash_get_size(flash, &flash_size);
    if (ret != ESP_OK) {
        ESP_LOGE("FLASH", "Failed to get flash size");
        return;
    }

    // ログにフラッシュチップのサイズを出力（フォーマット指定子を修正）
    ESP_LOGI("FLASH", "Detected Flash Chip Size: %lu bytes", (unsigned long)flash_size);
}

