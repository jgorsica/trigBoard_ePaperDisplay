Based on trigBoard v8 ESP32 development board design:\
https://www.tindie.com/products/kdcircuits/trigboard-ultra-low-power-esp32-iot-platform/ \
https://trigboard-docs.readthedocs.io/en/latest/

Uses WaveShare ePaper Display with WaveShare ePaper Display HAT:\
7.5-inch black/white/red 800x480pixels\
https://www.amazon.com/gp/product/B075YP81JR/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1

This project uses API sites and requires free registration to those sites to obtain API keys to get data:\
https://developer.accuweather.com/ \
https://rapidapi.com/hub \
https://ourmanna.readme.io/reference/get-a-bible-verse (no API key needed) \
Also register for APIs:\
https://rapidapi.com/jayantur13/api/word-of-the-day2/ \
https://rapidapi.com/bitbiscuit-bitbiscuit-default/api/motivational-quotes1/ \
https://rapidapi.com/APILAB/api/random-facts2/ \
https://rapidapi.com/KegenGuyll/api/dad-jokes/ \
https://rapidapi.com/matchilling/api/chuck-norris/


After registering with AccuWeather and RapidAPI, keys need to be pasted in top of EPAPER.ino file.

Hardware Connections for ePaper Hat:\
DIN goes to 13\
CLK goes to 14\
CS to 15\
DC to 33\
RST to 32\
BUSY to 39\
3.3V supply from trigBoard to power display\
Ground connection between trigBorad and display

Optional Hardware Modification to delay button release long enough to force display update on short button presses:\
Replace 10K pulldown resistor on low side of "Wake Button" with 470K pulldown resistor.\
Add 1.0 uF capacitor between low side of "Wake Button" and ground.\
Note: "low side" of "Wake Button" is the side not connected 4V2 power supply.

This project requires WiFi internet access.  WiFi credentials and the selection of API widgets that are displayed are configured through the trigBoard configurator tool.  https://krdarrah.github.io/trigBoardConfigurator/ \
Instructions are provided on the ePaper display after holding the "Wake Button" for 10 seconds.

Finished project:

![PXL_20220628_010002174](https://user-images.githubusercontent.com/10436684/180631119-84d68cb6-d98c-49a1-be54-8bf34827dae8.jpg)
![PXL_20220626_225345347_2](https://user-images.githubusercontent.com/10436684/180631120-e3fc6c4b-a969-4f8a-866d-fbc64d0d116e.jpg)
