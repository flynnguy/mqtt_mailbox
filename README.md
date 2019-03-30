# MQTT Mailbox
This uses a [SparkFun ESP8266 Thing](https://www.sparkfun.com/products/13231)
to send MQTT messages when a [Reed switch](https://en.wikipedia.org/wiki/Reed_switch)
causes a reset. 

On bootup, the ESP8266 Thing connects to the wifi and then sends both the
voltage of the battery as well as an 'opened' message before going into a deep
sleep to conserve battery. To wake it up, I connect the reset pin to ground
which wakes up the Thing.

For the mailbox, I used the [Patriot Large Plastic Post-Mount Mailbox](https://www.homedepot.com/p/Gibraltar-Mailboxes-Patriot-Large-Plastic-Post-Mount-Mailbox-Black-GMB515B01/207205059)
which has a smaller flag which indicates when the mailbox has opened. I added
magnets to the inside of this smaller flag and used electrical tape to affix
the reed switch to the inside of the mailbox. When the small flag passes the
reed switch, it closes the connection and causes a reset.

One modification I had to make to the esp8266 Thing was to rotate the resistor
90 degrees as described in [Selecting the Antenna](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/hardware-overview#selecting-antenna)
and used a small [2.4Ghz Antenna](https://smile.amazon.com/Diymall-Antenna-Antennas-Arduino-ESP-072pcs/dp/B00ZBJNO9O/ref=sr_1_4?keywords=antenna+U.FL&qid=1553793179&s=gateway&sr=8-4).


