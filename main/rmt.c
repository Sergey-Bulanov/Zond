#include "main.h"
#include "project_configuration.h"
#include "project_functions.h"

// static char tag[] = "rmt_tests";
rmt_channel_t channelA, channelB; 

static rmt_item32_t itemsA[5];
static rmt_item32_t itemsB[5];

// ранее - initRmt(...)
void rmt_init(channelPulses_t channelPulses){

	static bool channelIsntalled[4] = {false, false, false, false};
	
	gpio_num_t pinA, pinB;

	if(channelPulses == CHANNEL_1_AB){
		channelA = RMT_CHANNEL_0;
		channelB = RMT_CHANNEL_1;
		pinA = CHANNEL_1A_PIN;
		pinB = CHANNEL_1B_PIN;
	}else{
		channelA = RMT_CHANNEL_2;
		channelB = RMT_CHANNEL_3;
		pinA = CHANNEL_2A_PIN;
		pinB = CHANNEL_2B_PIN;
	}

	rmt_config_t config;
	config.rmt_mode = RMT_MODE_TX;

	// config.gpio_num = pinA;
	config.gpio_num = 21;
	config.mem_block_num = 1;
	config.tx_config.loop_en = 0;
	config.tx_config.carrier_en = 0;
	config.tx_config.idle_output_en = 1;
	config.tx_config.idle_level = 0;
	config.tx_config.carrier_duty_percent = 50;
	config.tx_config.carrier_freq_hz = 10000;
	config.tx_config.carrier_level = 1;
	config.clk_div = 1;

	config.channel = RMT_CHANNEL_0;
	rmt_config(&config); 
	rmt_driver_install(config.channel, 0, 0); 
	channelIsntalled[config.channel] = true;

	config.channel = RMT_CHANNEL_1;
	config.gpio_num = 22;
	rmt_config(&config);
	rmt_driver_install(config.channel, 0, 0); 
	channelIsntalled[config.channel] = true;

	itemsA[0].duration0 = 654;
	itemsA[0].level0 = 0;
	itemsA[0].duration1 = 4;
	itemsA[0].level1 = 0;

	itemsA[1].duration0 = 22;
	itemsA[1].level0 = 1;
	itemsA[1].duration1 = 22;
	itemsA[1].level1 = 0;
	itemsA[2].duration0 = 22;
	itemsA[2].level0 = 1;
	itemsA[2].duration1 = 22;
	itemsA[2].level1 = 0;
	itemsA[3].duration0 = 22;
	itemsA[3].level0 = 1;
	itemsA[3].duration1 = 22;
	itemsA[3].level1 = 0;
	itemsA[4].duration0 = 22;
	itemsA[4].level0 = 1;
	itemsA[4].duration1 = 22;
	itemsA[4].level1 = 0;

	itemsB[0].duration0 = 22;
	itemsB[0].level0 = 1;
	itemsB[0].duration1 = 22;
	itemsB[0].level1 = 0;
	itemsB[1].duration0 = 22;
	itemsB[1].level0 = 1;
	itemsB[1].duration1 = 22;
	itemsB[1].level1 = 0;
	itemsB[2].duration0 = 22;
	itemsB[2].level0 = 1;
	itemsB[2].duration1 = 22;
	itemsB[2].level1 = 0;
	itemsB[3].duration0 = 22;
	itemsB[3].level0 = 1;
	itemsB[3].duration1 = 22;
	itemsB[3].level1 = 0;
	itemsB[4].duration0 = 22;
	itemsB[4].level0 = 0;
	itemsB[4].duration1 = 22;
	itemsB[4].level1 = 0;

}

// ранее - runRmt(...)
void IRAM_ATTR rmt_run(channelPulses_t channelPulses) {

	if(channelPulses == CHANNEL_1_AB){
		channelA = RMT_CHANNEL_0;
		channelB = RMT_CHANNEL_1;
	}else{
		channelA = RMT_CHANNEL_2;
		channelB = RMT_CHANNEL_3;
	}
rmt_write_items(channelA, itemsA,
			5, /* Number of itemsA */
			0 /* NOT wait till done */);
rmt_write_items(channelB, itemsB,
			5, /* Number of itemsB */
			0 /* wait till done */);
}
