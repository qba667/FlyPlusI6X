# FlyPlusI6X

# Implemented features:

* Using telemetry value SNR/RSSI/ERROR for auxiliary channels (channel 11/12) - fixed for values below 16dB 05.04.2017
* Alarm for SNR values <= 10dB
* 2 Bytes sensors added to telemetry list (without units because in case of to long text display method crashes)


Telemetry data is working with IA6B, you can use my custom CleanFlight from:

https://github.com/qba667/cleanflight/releases

Or current branch of BetaFlight

https://github.com/betaflight/betaflight/releases

Selected sensors can be configured using CLI by setting ibus_sensor array:

```set ibus_sensor = 12,13,14,15,16,17,240,65,0,255,255,255,255,255,255```

If sensor id assigned to this array equals 0 it means sensor is not configured. First occurrence of 0 is preventing further sensors usage.

# Sensors IDs:

| 2 Bytes          | ID            |
| ---------------- | ------------- |
| Temperature      | 1             |
| RPM              | 2             |
| External Voltage | 3             |
| Avg Cell Voltage | 4             |
| Battery current  | 5             |
| Remaining batt.  | 6             |
| Throttle         | 7             |
| Heading          | 8             |
| Climb rate       | 9             |
| CoG              | 10            |
| GPS status       | 11            |
| ACC X            | 12            |
| ACC Y            | 13            |
| ACC Z            | 14            |
| Roll             | 15            |
| Pitch            | 16            |
| Yaw              | 17            |
| Vertical speed   | 18            |
| Ground speed     | 19            |
| GPS distnace     | 20            |
| Armed            | 21            |
| Flight mode      | 22            |


MavlinkToIBUS can be also used in case of APM/Pixhawk

https://github.com/qba667/MAVLinkToIbus


**FlySky updater seems to remove receiver ID from configuration or change transmitter ID. After updating you will have to rebind your receivers. I have noticed that in updater the field Transmitter ID gets incremented every time - so maybe setting value   to current value -1 will allow us to keep TX id.
Someone have to test it.
**

# In cleanflight/betaflight configure all 14 channels:
```set max_aux_channels = 14```
# Configure RSSI channel
```set rssi_channel = 11```

**Using original updater to flash FW**

FlySky provided to use nice way to flash new FW. 
Just copy modified firmware file **"FS-i6X.bin"** (Relese archive already has it) in same directory where original updater is located. Then start updater. Updater should detect new file and use it instead of default one.
Version displayed will be wrong. But it will update the unit correctly.
As bonus we get 2 additional fields:
*Transmitter ID*
*Company code*
And selection how many hoops does the transmitter has.

It seems that not all units are handling update correctly - issues reported by maczar_pl smeat. 

To workaround it before flashing factory defaults must be performed.

But just in case original FW attached (restore to default fw, restore factory defaults settings, flash modified firmware).

The crisis recovery method - seems to be working just fine.

Precondition: both trims on left side moved to the center on powering on the unit.
The unit should display nothing on screen.
Then start updater, it should detect the device and start flashing.
