/*
 * Project weatherStation
 * Description:
 * Author:
 * Date:
 */

#include "sht3x-i2c.h"

SerialLogHandler logHandler(LOG_LEVEL_INFO);

Sht3xi2c sensor(Wire);

void setup()
{
sensor.begin(CLOCK_SPEED_400KHZ);
}

void loop()
{
static uint32_t timer = System.uptime();
double temp, humid;

if (System.uptime() - timer > 5)
{
timer = System.uptime();
if (sensor.single_shot(&temp, &humid) == 0)
{
Log.info("Temperature: %.2f, Humidity: %.2f", temp, humid);
}
}
}