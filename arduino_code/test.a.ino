#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11
#define BLUE 8
#define GREEN 10
#define WHITE 12
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(3000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if ((humidity  <= 25.0)&& (humidity  >= 80.0)) {
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
      digitalWrite(12, HIGH);//White
    }
  else if (temperature <= 5.0)   {
      digitalWrite(8, HIGH);//BLUE
      digitalWrite(10, LOW);
      digitalWrite(12, LOW);
    }
  else if ((temperature > 5.0) &&  (temperature <= 7.0)) {
     digitalWrite(8, LOW);
     digitalWrite(10, HIGH);//GREEN
     digitalWrite(12, LOW);
  }
  else{
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    
  }
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print("°C ");
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println("%");
  delay(3000);

}
