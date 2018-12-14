// use preprocessor directives to define constants in the code
#define FLASH_RATE_HZ 2
#define BUTTON_IN 6
#define PWM_LED_OUT 3
#define PWM_MAX 255

// global variables representing "state" across all functions
// operating mode: 0 - off, 1 - bright, 2 - mid-bright, 3 - dim, 4 - flash
int operating_mode = 0;
bool button_is_pushed = false;
int previous_button_state = 0;
int PWM_OUT = 0;
int ledState = LOW;             // ledState used to set the LED


unsigned long currentMillis = 0;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;// executed one-time at device startup

void setup() 
{ 
    Serial.begin(9600);
   // define output (PWM) pin connected to LED
    pinMode(PWM_LED_OUT,OUTPUT);
    pinMode(BUTTON_IN,INPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON_IN), button_pushed, FALLING);

}
  
// continually-running loop
// calls functions that are named as "actions"
void loop()
{
    check_button_press();
    set_pwm_based_on_operating_mode();
//    Serial.println(button_is_pushed);
//    shine_led();
}

void button_pushed() 
{
    button_is_pushed = true;
}

void check_button_press() 
{
  //Serial.print("give me lighting\n");
  if (button_is_pushed == true)
     Serial.print("i press the button\n");
     operating_mode = operating_mode + 1;
        if (operating_mode == 4) 
        {
            operating_mode = 0;
        }

      button_is_pushed = false;
}
        
void shine_led() 
{
    Serial.print(operating_mode);
    delay(100);
    analogWrite(PWM_LED_OUT, PWM_OUT);
}

void set_pwm_based_on_operating_mode() 
{
    switch (operating_mode)
    {
        case 0:
            PWM_OUT = 0;
            digitalWrite(PWM_LED_OUT,LOW);
            break;
        case 1:
            PWM_OUT = PWM_MAX;
            shine_led();
            break;
        case 2:
            PWM_OUT = int(PWM_MAX/2);
            shine_led();
            break;
        case 3:
            PWM_OUT = int(PWM_MAX/4);
            shine_led();
            break;
        case 4:
            flash_the_light();
            break;
    }

}


void flash_the_light() 
{
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(PWM_LED_OUT, ledState);
  }
}
       
       

