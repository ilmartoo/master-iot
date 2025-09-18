/************************************
 * 5. Entorno de programación - LED *
 ************************************/
/*
#define LED_INTERNO D13

void setup() {
  pinMode(LED_INTERNO, OUTPUT); // Inicialización del pin LED_INTERNO como una salida
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_INTERNO, HIGH); // Encendido del LED
  delay(1000);
  digitalWrite(LED_INTERNO, LOW); // Apagado del LED
  delay(1000);
}
*/


/**************************************
 * 6. Resistencias PULLUP y PULLDOWN  *
 **************************************/
/*
#define PIN_PULSADOR D9
#define RELE 32
int estadoPulsador;

void setup() {
  pinMode(PIN_PULSADOR, INPUT_PULLUP);
  pinMode(RELE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  estadoPulsador = digitalRead(PIN_PULSADOR);

  if (estadoPulsador) {
    Serial.print("Botón no pulsado: entrada=");
    Serial.println(estadoPulsador);
    digitalWrite(RELE, HIGH);
  }
  else {
    Serial.print("Botón pulsado: entrada=");
    Serial.println(estadoPulsador);
    digitalWrite(RELE, HIGH);
  }
  delay(500);
}
*/


/**************************************
 * 7. Control PWM                     *
 **************************************/
 /*
const int canalPWM = 0;
const int ledPin = D13;
const int frecuenciaPWM = 5000;
const int resolucionPWM = 8;

const int retardo_ms = 10;

const int maxDutyCycle = (int) (pow(2, resolucionPWM) - 1);

void setup() {
  ledcAttachChannel(ledPin, frecuenciaPWM, resolucionPWM, canalPWM);
}

void loop() {
  for (int dutyCycle = 0; dutyCycle <= maxDutyCycle; dutyCycle++) {
    ledcWrite(ledPin, dutyCycle);
    delay(retardo_ms);
  }
  
  for (int dutyCycle = maxDutyCycle; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledPin, dutyCycle);
    delay(retardo_ms);
  }
}
*/

/**************************************
 * 8. Ejercicios - Ejercicio 1        *
 **************************************/

#define LED_PIN D13
#define INPUT_PIN A1
#define ON_PIN D2
#define OFF_PIN D3

#define RESOLUTION 10

uint16_t rawValue;
bool isOn = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  pinMode(ON_PIN, INPUT);
  pinMode(OFF_PIN, INPUT);
  analogReadResolution(RESOLUTION);
  Serial.begin(9600);
}

void loop() {
  rawValue = analogRead(INPUT_PIN);
  Serial.print("LDR value = ");
  Serial.println(rawValue);

  if (digitalRead(ON_PIN)) {
    isOn = true;
  }
  if (digitalRead(OFF_PIN)) {
    isOn = false;
  }

  if (isOn && rawValue > 512) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(250);
}

/**************************************
 * 8. Ejercicios - Ejercicio 2        *
 **************************************/

/*
void setup() {

}

void loop() {
  
}
*/
