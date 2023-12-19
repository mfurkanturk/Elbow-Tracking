
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position

#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
int servoPin = 17;
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
int servoPin = 7;
#else
int servoPin = 18;
#endif

void setup() {
  Serial.begin(115200);
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 1000, 5000); 

}

void loop() {

	if (Serial.available() > 0) {
    // Seri porttan gelen veriyi oku
    int degree = Serial.parseInt();

    // Derece değerini kontrol et
    if (degree >= 0 && degree <= 180) {
      // Servo motoru belirtilen dereceye ayarla
      myservo.write(degree);
    }
  }
}

