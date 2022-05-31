#include "sdkconfig.h"
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <freertos/FreeRTOS.h>
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "driver/adc.h"
#include "driver/dac.h"
#include <driver/rmt.h>
#include "driver/timer.h"
#include "driver/ledc.h"
#include "hal/dac_ll.h"

#include "esp_log.h"
#include "esp_timer.h"
#include "esp_adc_cal.h"
#include "esp_err.h"
#include <rom/ets_sys.h>
#include "soc/sens_struct.h"
