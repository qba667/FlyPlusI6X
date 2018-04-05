# FlyPlusI6X

Implemented features:
[LIST]
[*]    Using telemetry value SNR/RSSI/ERROR for auxiliary channels (channel 11/12) - fixed for values below 16dB 05.04.2017
[*]    Alarm for SNR values <= 10dB
[*]    2 Bytes sensors added to telemetry list (without units because in case of to long text display method crashes)
[/LIST]

Telemetry data is working with IA6B, you can use my custom CleanFlight from:

[URL="https://github.com/qba667/cleanflight/releases"]https://github.com/qba667/cleanflight/releases[/URL]

Or current branch of BetaFlight
[URL="https://github.com/betaflight/betaflight/releases"]https://github.com/betaflight/betaflight/releases[/URL]

Selected sensors can be configured using CLI by setting array "ibus_sensor"
If sensor id assigned to this array equals 0 it means sensor is not configured. First occurrence of 0 is preventing further sensors usage.

MavlinkToIBUS can be also used in case of APM/Pixhawk
[URL="https://github.com/qba667/MAVLinkToIbus"]https://github.com/qba667/MAVLinkToIbus[/URL]


As always ideas are welcome. 
Please list current issues with the unit maybe we can solve them together.

Because myself I am not using the system any more I see no sense in buying the unit for firmware development.
Also some of you declared to support the project, because of that I have started a crowdfunding campaign under:

[URL="https://gogetfunding.com/flyplus-firmware-for-flysky-i6x"]https://gogetfunding.com/flyplus-firmware-for-flysky-i6x[/URL]

During I6 firmware development I have damaged 2 units, so it must be expendable hardware.

List of donors:
[LIST]
[*] Gas Teddy
[*] darmach
[*] frenchtony
[*] mece
[*] kamikazze
[*] Adam W.
[/LIST]

Subtrim/endpoint fixed - lesson for feature do not mess with defined channels count. 
Now you don't have to configure total channels count  - RSSI/Error on channel 11/12 always present.

[B]FlySky updater seems to remove receiver ID from configuration or change transmitter ID. After updating you will have to rebind your receivers.
I have noticed that in updater the field Transmitter ID gets incremented every time - so maybe setting value   to current value -1 will allow us to keep TX id.
Someone have to test it.
[/B]

RSSI on channel 11 added.
Error on channel 12 added.

In cleanflight/betaflight configure all 14 channels:
[CODE]set max_aux_channels = 14[/CODE]
configure RSSI channel
[QUOTE]set rssi_channel = 11 [/QUOTE]

[B]Using original updater to flash FW[/B]
FlySky provided to use nice way to flash new FW. 
Just copy modified firmware file "[B]FS-i6X.bin[/B]" in same directory where original updater is located.
Then start updater. Updater should detect new file and use it instead of default one.
Version displayed will be wrong. But it will update the unit correctly.
As bonus we get 2 additional fields:
Transmitter ID
Company code
And selection how many hoops does the transmitter has.


@dolphin78 has reported that Windows Defender detected Win32/Fuerboos.A!cl trojan
It can be because I have used original updater - probably same issue as in topic:

[url]https://www.rcgroups.com/forums/showthread.php?2972121-Can-t-register-Flysky-FS-I6X-Firmware-Virus[/url]

I just scanned the updater file with nodistribute.com please see results:

[url]https://nodistribute.com/result/Wk9XeIaMSbBHY3Eo[/url]

It seems that not all units are handling update correctly -issues reported by maczar_pl smeat. 

To workaround it before flashing factory defaults must be performed.

But just in case original FW attached (restore to default fw, restore factory defaults settings, flash modified firmware).

The crisis recovery method - seems to be working just fine.

Precondition: both trims on left side moved to the center on powering on the unit.
The unit should display nothing on screen.
Then start updater, it should detect the device and start flashing.
