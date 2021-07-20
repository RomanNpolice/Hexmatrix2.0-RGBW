# RGB HexMatrix2.0 RGBW Version with Wifimanager
original : [HexMatrix2.0](https://www.instructables.com/RGB-HexMatrix-IOT-Clock-20/)

Afterall, This repository is 2nd creation of HexMatrix2.0 by Mukesh sankhla.

For Better Beautiful, Less Power, Warm Light of the HexMatrix, I develope it for RGBW version.
There are the problems when move at another places when wifi didn't reaches so far it have to revice Wifi ssid from the code, I add WifiManager to connect AP more easier and don't need to modify firmware when connect it.
SK6812 LED is a good replacement from WS2812B nowadays.
RGB version also included.

# Instructions
For Made This Gorgeous HexMatrix, It needs 3d printed parts and pcbs.
It discribed in the original link on the top of the articles.
This work needs SK6812 RGBW or RGFBNW LED (WS2812B weakness of heat) and ESP8266 NodeMCU. It assumes around 100 LEDs.
Soldering LEDs are little trickey, So you prepare knife tip for solder iron.
Solder 1 LED for test and connect NodeMCU to board and upload firmware to test led.
When done, Bring devices can access internet(ex. Laptop, Desktop, Smartphone ...) and Connect AP which is "RGB HexMatrix", access 192.168.4.1 and configure wifi. From the [Link](https://github.com/tzapu/WiFiManager) to setup WifiManager.
If led goes on, Solder rest of leds as is.
If led doesn't come, Check Wifi AP has been connected WifiManager, If it is, disconnect board and solder UPSIDE DOWN LED and try again.
Finish the circuit, Cut the legs of the NodeMCU board and put everything in the enclosure.
More information, Link in [original link](https://www.instructables.com/RGB-HexMatrix-IOT-Clock-20/)

# The Reason why I developed it RGBW version
Existing version is disadvantage to short life cycle from weekness of heat. So, SK6812, compatable with WS2812, is more fit to LED clock reason why more strong from the heat and easy to solder. Additionally, When turn on white color, RGB LED truns three diodes 'R', 'G', 'B' but RGBW LED turns only one diodes 'W' So it more efficient of power consumption and long lasting for led lives. I also made RGBNW version for beauty.