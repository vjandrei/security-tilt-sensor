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
        <td>OE</td>
        <td>13</td>
        <td rowspan="13"><image src="./images" /></td>
    </tr>
    <tr>
        <td>CLK</td>
        <td>14</td>
    </tr>
    <tr>
        <td>LAT</td>
        <td>15</td>
    </tr>
    <tr>
        <td>CH_A</td>
        <td>26</td>
    </tr>
    <tr>
        <td>CH_B</td>
        <td>4</td>
    </tr>
    <tr>
        <td>CH_C</td>
        <td>27</td>
    </tr>
    <tr>
        <td>CH_D</td>
        <td>2</td>
    </tr>
    <tr>
        <td>R1</td>
        <td>5</td>
    </tr>
    <tr>
        <td>G1</td>
        <td>17</td>
    </tr>
    <tr>
        <td>BL1</td>
        <td>18</td>
    </tr>
    <tr>
        <td>R2</td>
        <td>19</td>
    </tr>
    <tr>
        <td>G2</td>
        <td>16</td>
    </tr>
    <tr>
        <td>BL2</td>
        <td>25</td>
    </tr>
</table>



