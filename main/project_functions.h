// gpio.c - выдача фрейма
void gpio_ini();
void setFrameLow();
void setFrameHigh();

// rmt.c - выдача зондирующих импульсов
void rmt_init(channelPulses_t channelPulses);
void rmt_run(channelPulses_t channelPulses);

// pwm.c - выдача импульсов для преобразователя напряжения
void pwm_init();

// dac.c - выдача ВАРУ
void dac_init();
void dac_start();

// adc.c - чтение блока данных из АЦП в цикле приема
void adc_run_dma(uint16_t adc1_chan_mask, uint16_t adc2_chan_mask, adc_channel_t *channel, uint8_t channel_num);