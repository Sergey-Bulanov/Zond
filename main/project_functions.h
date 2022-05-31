// gpio.c - выдача фрейма
void gpio_ini();    // ранее - gpio_ini()
void setFrameLow();
void setFrameHigh();

// rmt.c - выдача зондирующих импульсов
void rmt_init(channelPulses_t channelPulses);   // ранее - initRmt(...)
void rmt_run(channelPulses_t channelPulses);    // ранее - runRmt(...)

// pwm.c - выдача импульсов для преобразователя напряжения
void pwm_init();

// dac.c - выдача ВАРУ
void dac_init();
void dac_start();

// adc.c - чтение блока данных из АЦП в цикле приема
void adc_run_dma(uint16_t adc1_chan_mask, uint16_t adc2_chan_mask, adc_channel_t *channel, uint8_t channel_num);
// adc_run_dma - ранее называлась - continuous_adc_init(...) и запускалась в start_adc_rmt_dac(...) 
// ранее start_adc_rmt_dac(...) была главная и единственная функция, запускаемая в главном цикле
