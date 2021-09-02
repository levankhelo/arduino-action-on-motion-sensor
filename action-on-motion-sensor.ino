int led = 13;                 // store LED pin
int sensor = 2;               // store Sensor pin
int state = LOW;              // set LED state to off by default
int val = 0;                  // store value of Motion Sensor
bool logs = false;            // allow Serial Monitor logs

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial monitor
}

// required actions should be described here
void action(int value) {
  digitalWrite(led, value);
}

void loop(){
  // check for change
  if ( val == digitalRead(sensor) ) {
    return;
  } else {
    // capture sensor change and pass it to action function
    action( digitalRead(sensor) );

    // check if logs are enabled and print output in Serial Monitor
    if ( !logs ) return;
    if ( val == HIGH ) { Serial.println("Motion detected"); } else { Serial.println("Motion stopped"); }
  }
}

