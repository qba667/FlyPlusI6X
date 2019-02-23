#include "flysky.h"

extern uint16_t reallocatedChannelsData[]; 

/*
    The firmware sends the radio frames with code that is being executed
    by the interrupt handler of a timer.
    The timer code itself is not responsible for the putting together of the
    radio frame - this is done from the main loop - it simply sends whatever
    is in the radio frame buffer.
    
    The device's analog inputs are read constantly with the ADC which uses DMA.
    The channels' raw ADC data is converted (scaled, mixed, etc.) to the
    actual channel values (1000-2000) on every iteration of the main loop.
    
    The main loop also builds the radio frame that should be sent by the timer code.
    For some reason (I didn't find the exact reason since the state machine which
    controls this is quite complex) this radio frame is built less frequently than
    it is actually being sent. That's why the timer code sends several frames with the same
    content.
    
    Instead of trying to understand the complex state machine and trying to figure out
    where its logic fails, a simpler approach is taken:
    
    The code below is injected just before a radio frame is sent over SPI to the A7105
    chip. It recognizes if the frame carries channel data and if it does, it simply
    copies the channels from the channel buffer which is propely updated on every
    iteration of the main loop.
*/

int channelsBugfix(char *buf, int count) {
    // AFHDS 2
    if(count == 39 && buf[1] == 0x58) {
        // copy 10 channels, only the 10 ADC channels are critical
        __aeabi_memcpy(buf+10, reallocatedChannelsData, 2*10);
    }
    // AFHDS
    else if(count == 22 && buf[1] == 0x55) {
        // copy 8 channels
        __aeabi_memcpy(buf+6, reallocatedChannelsData, 2*8);
    }
    
    spiSend(buf, count);
}
