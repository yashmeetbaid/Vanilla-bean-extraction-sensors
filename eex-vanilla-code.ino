#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
#define LED_PIN 5 // Define the pin for the LED
#define BUZZER_PIN 6 // Define the pin for the buzzer
#define RELAY_PIN_1 19 // Define the pin for the first relay
#define RELAY_PIN_2 18 // Define the pin for the second relay
#define TEMPERATURE_THRESHOLD 65 // Define the temperature threshold
#define BLINK_INTERVAL 500 // Define the blink interval in milliseconds
#define RELAY_ON_DURATION 4000 // Define the duration for which the relays should be on (in milliseconds)

bool ledState = LOW; // Initial state of the LED
unsigned long relayStartTime = 0; // Variable to store the time when the relays were turned on

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("Temperature:");
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
}

void loop() 
{
  float temperatureC = 60; // Simulated temperature value (change as needed)
  
  lcd.setCursor(0, 1);
  lcd.print("     "); // Clear previous temperature
  lcd.setCursor(0, 1);
  lcd.print(temperatureC); // Display temperature on LCD
  
  if (temperatureC > TEMPERATURE_THRESHOLD)
  {
    // Check if the relays are not already on
    if (millis() - relayStartTime >= RELAY_ON_DURATION)
    {
      // Turn on the relays and record the start time
      digitalWrite(RELAY_PIN_1, HIGH);
      digitalWrite(RELAY_PIN_2, HIGH);
      relayStartTime = millis();
    }
    
    // Blink the LED if temperature is above threshold
    digitalWrite(LED_PIN, ledState);
    ledState = !ledState;
    
    digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
    delay(BLINK_INTERVAL / 2); // Half of the blink interval
    digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
  } 
  else 
  {
    digitalWrite(LED_PIN, LOW); // Turn off LED if temperature is below threshold
    digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
    
    // Check if the relays have been on for more than RELAY_ON_DURATION
    if (millis() - relayStartTime >= RELAY_ON_DURATION)
    {
      // Turn off the relays
      digitalWrite(RELAY_PIN_1, HIGH);
      digitalWrite(RELAY_PIN_2, HIGH);
    }
  }
  
  delay(BLINK_INTERVAL / 2); // Adjust delay time as needed for smoother blinking
}
