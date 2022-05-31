#include "main.h"
#include "project_configuration.h"
#include "project_functions.h"

// static bool buffer_print_done = false;

void IRAM_ATTR app_main(void) {

// #ifdef PRINT_DEBUG
//   printf("My Task started.\n");
// #endif

  esp_err_t ret = 0;
  uint32_t ret_num = 0;
  uint8_t result[TIMES] = {0};
  adc_channel_t channel_list[1] = {ADC_ECHO_INPUT};

  gpio_init();
  rmt_init(0); // функция Скрибловского - 0 или 1  
  pwm_init();
  dac_init();

  while (1) { // Цикл зондирования

    // ранее start_adc_rmt_dac(...) была главная и единственная функция, запускаемая в главном цикле

    ledc_stop(LEDC_MODE, LEDC_CHANNEL_40V, 0);  // lib - прекратить PWM на время приема
    memset(result, 0xcc, TIMES);

    setFrameLow();  // gpio.c - начать фрейм

    rmt_run(0);      // rmt.c - выдать зондирующие импульсы
    adc_run_dma(ADC1_CHAN_MASK, ADC2_CHAN_MASK, channel_list, sizeof(channel_list) / sizeof(adc_channel_t));  // adc.c - запуск АЦП
    dac_start();    // dac.c - программная выдача серии значений в ЦАП

    adc_digi_stop();  // lib - стоп АЦП
    adc_digi_deinitialize();  // lib -  
    setFrameHigh(); // gpio.c - завершение фрейма

    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_40V);  // lib - возобновить PWM 

    vTaskDelay( 1 * portTICK_PERIOD_MS ); // lib - Интервал между зондированиями
  }
}
