#include "Assistant.h"

#define NULL (void*)0

Assistant::Assistant(int luxmetr, int termometr_water, int termometr_air, int sensor_mist, int sensor_level_water, int mistmaker, int phytolamp, int ventilation, int heating_air)
{
	Assistant::pin_luxmetr = luxmetr;
	Assistant::pin_termometr_water = termometr_water;
	Assistant::pin_termometr_air = termometr_air;
	Assistant::pin_sensor_mist = sensor_mist;
	Assistant::pin_sensor_level_water = sensor_level_water;

	Assistant::pin_mistmaker = mistmaker;
	Assistant::pin_phytolamp = phytolamp;
	Assistant::pin_ventilation = ventilation;
	Assistant::pin_heating_air = heating_air;
}


float Assistant::get_temperature_air()
{
	return get_temperature( Assistant::pin_termometr_water );
}

float Assistant::get_temperature_water()
{
	return get_temperature( Assistant::pin_termometr_water );
}

float Assistant::get_level_humidity()
{
	return 0;
}

int Assistant::get_level_light()
{
	int adc_value = analogRead( Assistant::pin_luxmetr );
    float volt = 5.0 * (adc_value / 1024.0);
    float resistor = (10.0 * 5.0) / volt - 10.0;
    int lx = 223.35 * pow(resistor, -10 / 8);
    return lx;
}

bool Assistant::water_exists()
{
	return false;
}

bool Assistant::mist_exists()
{
	return false;
}

void Assistant::power_on_mistmaker()
{
	digitalWrite(Assistant::pin_mistmaker, HIGH);
}

void Assistant::power_off_mistmaker()
{
	digitalWrite(Assistant::pin_mistmaker, LOW);
}

void Assistant::power_on_phytolamp()
{
	digitalWrite(Assistant::pin_phytolamp, HIGH);
}

void Assistant::power_off_phytolamp()
{
	digitalWrite(Assistant::pin_phytolamp, LOW);	
}

void Assistant::power_on_ventilation(int level_power)
{
	analogWrite(Assistant::pin_ventilation, level_power);
}

void Assistant::power_off_ventilation()
{
	analogWrite(Assistant::pin_ventilation, LOW);
}

void Assistant::power_on_heating_air(int level_power)
{
	analogWrite(Assistant::pin_heating_air, level_power);
}

void Assistant::power_off_heating_air()
{
	analogWrite(Assistant::pin_heating_air, LOW);
}






float Assistant::get_temperature(int pin_number)
{ 
  unsigned int B = 3950; // Параметр бетта(B) термистора (из datasheet)
  float r_25 = 4700.0;//сопротивление термистора при 25 градусов Цельсия
  float r_d = 10000.0;//сопротивление резистора делителя напряжения
  float voltage = analogRead(pin_number) * VIN / 1023.0;//напряжение, получаемое с термистора
  float r_t = voltage * r_d / (VIN - voltage);//сопротивление при температуре t
  float temperature = 1. / ( 1. / (B) * log(r_t / r_25) + 1. / (25. + 273.15) ) - 273.15;
  return temperature;
}

