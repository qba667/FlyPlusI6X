#include <stdlib.h>
const int bytes[] = {0,0,0,0};
int main(void) {
	for (unsigned i = 0; i < 800000; i++) {
        __asm__("nop");
    }
	int i = 0;
	while(1) {
		if(bytes[0] == 2){
			i++;
		}
		
	}
}