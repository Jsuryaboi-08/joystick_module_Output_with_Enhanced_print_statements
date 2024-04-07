const int xpin = 15;
const int ypin = 0;
const int swpin = 12;

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

int xdirection = 0; //setting the initial x direction as zero
int ydirection = 0; //setting the initial Y direction as zero
int swstate = 1; //inital switch state is one

int xcontrol = 0;//initial state 
int ycontrol = 0;//final state

void setup(){
  Serial.begin(115200);
  pinMode(swpin, INPUT);

  digitalWrite(swpin, HIGH); // the joystick is always high unless this button is pressed.
  
}

void loop(){

  xdirection = analogRead(xpin);
  ydirection = analogRead(ypin);
  swstate = digitalRead(swpin);

  debug("The state of the switch is: ");
  debugln(swstate);

  debug("X: ");
  debugln(xdirection);

  debug("Y: ");
  debugln(ydirection);


  if(!swstate){
    debug("Button is pressed");
  }

  if(xdirection<425){
    xcontrol = 1;//up
    debug("up");
  }else if(xdirection>465){
    xcontrol = 2;//down
    debug(down);
  }else{
    xcontrol = 0;//return to inital state
  }

  if(ydirection<425){
    ycontrol = 1;//up
    debug(left);
  }else if(ydirection>465){
    ycontrol = 2;//down
    debug(right);
  }else{
    ycontrol = 0;//return to inital state
  }


  delay(500);

}
