#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

// Declare ADC calibration characteristics
static esp_adc_cal_characteristics_t adc1_chars;

void app_main(void)
{
    // Initialize ADC calibration
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);
    
    // Configure ADC width 
    adc1_config_width(ADC_WIDTH_BIT_DEFAULT);

    // Configure channels with attenuation
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);

    while (1) 
    {
         // Read raw data from ADC1_CHANNEL_4 (GPIO32)
        int adc_value = adc1_get_raw(ADC1_CHANNEL_4);
        printf("potentiometer Value: %d", adc_value);
        printf("\n");
        vTaskDelay(500/ portTICK_PERIOD_MS);
    }
}
