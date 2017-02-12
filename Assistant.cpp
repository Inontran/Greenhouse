#include "Assistant.h"

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
	
	//pinMode
	pinMode(Assistant::pin_mistmaker, OUTPUT);
	pinMode(Assistant::pin_phytolamp, OUTPUT);
	pinMode(Assistant::pin_ventilation, OUTPUT);
	pinMode(Assistant::pin_heating_air, OUTPUT);

	Assistant::mistmaker_status = false;
	Assistant::phytolamp_status = false;
	Assistant::ventilation_status = 0;
	Assistant::heating_air_status = 0;
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
	if( ! Assistant::mistmaker_status) 
	{
		digitalWrite(Assistant::pin_mistmaker, HIGH);
		mistmaker_status = true;
	}
}

void Assistant::power_off_mistmaker()
{
	if(Assistant::mistmaker_status)
	{
		digitalWrite(Assistant::pin_mistmaker, LOW);
		mistmaker_status = false;
	}
}

void Assistant::power_on_phytolamp()
{
	if( ! Assistant::phytolamp_status )
	{
		digitalWrite(Assistant::pin_phytolamp, HIGH);
		phytolamp_status = true;
	}
}

void Assistant::power_off_phytolamp()
{
	if(Assistant::phytolamp_status)
	{
		digitalWrite(Assistant::pin_phytolamp, LOW);	
		phytolamp_status = false;
	}
}

void Assistant::power_on_ventilation(int level_power)
{
	Assistant::ventilation_status = level_power;
	analogWrite(Assistant::pin_ventilation, Assistant::ventilation_status);
}

void Assistant::power_off_ventilation()
{
	Assistant::ventilation_status = 0;
	analogWrite(Assistant::pin_ventilation, 0);
}

void Assistant::power_on_heating_air(int level_power)
{
	Assistant::heating_air_status = level_power;
	analogWrite(Assistant::pin_heating_air, Assistant::heating_air_status);
}

void Assistant::power_off_heating_air()
{
	Assistant::heating_air_status = 0;
	analogWrite(Assistant::pin_heating_air, 0);
}


bool Assistant::get_mistmaker_status()
{
	return Assistant::mistmaker_status;
}

char *Assistant::get_mistmaker_char_status()
{
	if( Assistant::mistmaker_status ) return "ON";
	else return "OFF";
}

bool Assistant::get_phytolamp_status()
{
	return Assistant::phytolamp_status;
}

char *Assistant::get_phytolamp_char_status()
{
	if( Assistant::phytolamp_status ) return "ON";
	else return "OFF";
}

int Assistant::get_ventilation_status()
{
	return Assistant::ventilation_status;
}

String Assistant::percent_ventilation_status()
{
	// char *status;
	int status = map( Assistant::ventilation_status, 0, 255, 0, 100 );
	String tmp_str(status);
	tmp_str.concat("%");
	return tmp_str;
}
		
int Assistant::get_heating_air_status()
{
	return Assistant::heating_air_status;
}

String Assistant::percent_heating_air_status()
{
	int status = map( Assistant::heating_air_status, 0, 255, 0, 100 );
	String tmp_str(status);
	tmp_str.concat("%");
	return tmp_str;
}





float Assistant::get_temperature(int pin_number)
{ 
  unsigned int B = 3950; // Параметр бетта(B) термистора (из datasheet)
  float r_25 = 4700.0;//сопротивление термистора при 25 градусов Цельсия
  float r_d = 10000.0;//сопротивление резистора делителя напряжения
  float VIN = 5.0;//
  float voltage = analogRead(pin_number) * VIN / 1023.0;//напряжение, получаемое с термистора
  float r_t = voltage * r_d / (VIN - voltage);//сопротивление при температуре t
  float temperature = 1. / ( 1. / (B) * log(r_t / r_25) + 1. / (25. + 273.15) ) - 273.15;
  return temperature;
}

