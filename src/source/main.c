#include <stdlib.h>
#include "i6x.h"
#include "channelsHack.h"

 __attribute__((section (".remove_main"))) __attribute__((used)) int main(void) {
    keepChannelHackReferences();
}
