#pragma once
#include "Arduino.h"

class Plant {
public:
  Plant(String name, int sensorNumber);
  float getHumidity();
  void setName(String name);
  int getSensorNumber();
  String getName();
private:
  String name;
  float humidity;
  int sensorNumber;
};

Plant::Plant(String name, int sensorNumber) {
  this->name = name;
  this->sensorNumber = sensorNumber;
}

float Plant::getHumidity() {
  this->humidity = (4096.0-analogRead(sensorNumber))/4096.0*100;
  return this->humidity;
}

String Plant::getName() {
  return this->name;
}