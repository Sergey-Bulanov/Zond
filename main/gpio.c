#include "main.h"
#include "project_configuration.h"
#include "project_functions.h"

void gpio_ini() {
  // zero-initialize the config sructure.
  gpio_config_t io_conf = {};
  // disable interrupt
  io_conf.intr_type = GPIO_INTR_DISABLE;
  // set as output mode
  io_conf.mode = GPIO_MODE_OUTPUT;
  // bit mask of the pins that you want to set,e.g.GPIO14
  io_conf.pin_bit_mask = (1ULL << FRAME_OUT_PIN);
  // disable pull-down mode
  io_conf.pull_down_en = 0;
  // disable pull-up mode
  io_conf.pull_up_en = 0;
  // configure GPIO with the given settings
  gpio_config(&io_conf);
  GPIO.out_w1ts = (1 << FRAME_OUT_PIN);
}

void IRAM_ATTR setFrameLow() { GPIO.out_w1tc = (1 << FRAME_OUT_PIN); }

void IRAM_ATTR setFrameHigh() { GPIO.out_w1ts = (1 << FRAME_OUT_PIN); }
