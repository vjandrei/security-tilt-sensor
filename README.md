# 🚨 🤖 Security tilt sensor Telegram Bot 
>
This repo is project to tilt sensor surveillance system for example motorcycle. 
My motorcross bike was stoled and I need to secure my primary motorcycle so that 
if anyone tried to steal a motorcycle I would be immediately notified.

![Sensor and the 3D printed case](./images/tilt-sensor03.jpeg)


## What you need for this project

* ESP32 module
* LM393 Mini Tilt Angle Sensor
* 3D printer 
* Telegram account and bot
* Arduino IDE
* Wifi



## Let's start

### Make Telegram Bot

1. Enter @Botfather in the search tab and choose this bot.
2. Choose or type the /newbot command and send it.
3. Choose a name for your bot — your subscribers will see it in the conversation. 
4. Go to the @BotFather bot and send the command /token.

[Read more here](https://sendpulse.com/knowledge-base/chatbot/create-telegram-chatbot)


### 3D print case

Download and print this case by Thingiverse user [Razurel](https://www.thingiverse.com/thing:3799608)

### Wireup pin connections

## Pin connections

The pin assignment is not strict and every pin can be reconfigured to another one, but it is recommended to follow the pinout below so it would work with the unmodified code:

<table>
    <tr>
        <th>Pin</th>
        <th>GPIO</th>
        <th>Reference</th>
    </tr>
    <tr>
        <td>VCC</td>
        <td>PIN1</td>
        <td rowspan="13">
            <image src="./images/tilt-sensor-module-pinout.jpg" />
            <image src="./images/esp32_pinout.png" />
        </td>
    </tr>
    <tr>
        <td>GND</td>
        <td>PIN2</td>
        <td></td>
    </tr>
    <tr>
        <td>D0</td>
        <td>PIN13</td>
        <td></td>
    </tr>
</table>



