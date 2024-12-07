#include "plant.h"

class StensMoistureSensor {
public:
  StensMoistureSensor(String sensorName);
  String getJson();
  String getHTML();
  String getRaw();

private:
  Plant* coffea_arabica;
  Plant* salvia_rosmarinus;
  Plant* capsicum_anuum;
  String sensorName;
};

StensMoistureSensor::StensMoistureSensor(String sensorName) {
  this->coffea_arabica = new Plant("Coffea Arabica", 32);
  this->salvia_rosmarinus = new Plant("Salvia Rosmarinus", 33);
  this->capsicum_anuum = new Plant("Capsicum Anuum", 35);
  this->sensorName = sensorName;
}

String StensMoistureSensor::getHTML() {
  String p = this->coffea_arabica->getName() + ":<br>Bodenfeuchtigkeit: " + this->coffea_arabica->getHumidity() + " %<br><br>";
  String p2 = this->salvia_rosmarinus->getName() + ":<br>Bodenfeuchtigkeit: " + this->salvia_rosmarinus->getHumidity() + " %<br><br>";
  String p3 = this->capsicum_anuum->getName() + ":<br>Bodenfeuchtigkeit: " + this->capsicum_anuum->getHumidity() + " %<br><br>";
  return p + p2 + p3;
}

String StensMoistureSensor::getJson() {
  String pre = "{\"sensorName\": \"" + this->sensorName + "\", \"plants\": [";

  String p = "{\"name\": \"" + this->coffea_arabica->getName() + "\", \"humidity\": \"" + this->coffea_arabica->getHumidity() + "\"},";
  String p2 = "{\"name\": \"" + this->salvia_rosmarinus->getName() + "\", \"humidity\": \"" + this->salvia_rosmarinus->getHumidity() + "\"},";
  String p3 = "{\"name\": \"" + this->capsicum_anuum->getName() + "\", \"humidity\": \"" + this->capsicum_anuum->getHumidity() + "\"}";

  String end = "]}";
  return pre + p + p2 + p3 + end;
}

String StensMoistureSensor::getRaw() {
  String pre = this->sensorName + ": \n\t";
  String p = this->coffea_arabica->getName() + ": " + this->coffea_arabica->getHumidity() + " %";
  String p2 = this->salvia_rosmarinus->getName() + ": " + this->salvia_rosmarinus->getHumidity() + " %";
  String p3 = this->capsicum_anuum->getName() + ": " + this->capsicum_anuum->getHumidity() + " %";
  return pre + p + p2 + p3;
}