#include "main.h"
#include "project_configuration.h"
#include "project_functions.h"

// ранее эта функция запускалась в start_adc_rmt_dac(channelPulses_t channelPulses)
// ранее эта функция называлась - static void continuous_adc_init(...)
void IRAM_ATTR adc_run_dma(uint16_t adc1_chan_mask, uint16_t adc2_chan_mask, adc_channel_t *channel, uint8_t channel_num)
{
    adc_digi_init_config_t adc_dma_config = {
        .max_store_buf_size = MAX_STORE_BUFF_SIZE,
        .conv_num_each_intr = TIMES,
        .adc1_chan_mask = adc1_chan_mask,
        .adc2_chan_mask = adc2_chan_mask,
    };

    adc_digi_configuration_t dig_cfg = {
        .conv_limit_en = ADC_CONV_LIMIT_EN,
        .conv_limit_num = CONV_LIMIT_NUM,
        .sample_freq_hz = SAMPLE_FREQ_HZ,
        .conv_mode = ADC_CONV_MODE,
        .format = ADC_OUTPUT_TYPE,
    };

    adc_digi_pattern_config_t adc_pattern[SOC_ADC_PATT_LEN_MAX] = {0};
    dig_cfg.pattern_num = channel_num;
    for (int i = 0; i < channel_num; i++) {
        uint8_t unit = GET_UNIT(channel[i]);
        uint8_t ch = channel[i] & 0x7;
        adc_pattern[i].atten = ADC_ATTEN_DB_11; // ADC_ATTEN_DB_11  ADC_ATTEN_DB_6  ADC_ATTEN_DB_0
        adc_pattern[i].channel = ch;
        adc_pattern[i].unit = unit;
        adc_pattern[i].bit_width = SOC_ADC_DIGI_MAX_BITWIDTH;

    }
    dig_cfg.adc_pattern = adc_pattern;
}
