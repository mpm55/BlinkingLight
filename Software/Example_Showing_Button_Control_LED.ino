const int keyPin = 6; //the number of the key pin 12
const int ledPin = 3; //the number of the key pin 12

/**********************************/
void setup()
{
pinMode(keyPin,INPUT);//initialize the key pin as input 
pinMode(ledPin,OUTPUT);//initialize the led pin as output
}
/**********************************/
void loop()
{
//read the state of the key value
//and check if the kye is pressed
//if it is,the state is HIGH 
if(digitalRead(keyPin) ==HIGH )
{
digitalWrite(ledPin,HIGH);//turn on the led
}
else
{
digitalWrite(ledPin,LOW);//turn off the led
}
}

/************************************/
