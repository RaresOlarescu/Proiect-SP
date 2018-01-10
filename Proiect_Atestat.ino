const int verdem = 5;
const int galbenm = 6;
const int rosum = 7;
const int verdep = 4;
const int rosup = 3;
const int buton = 9;
const int senzor = A5;
int ok = 1;
int glb = 2; 
int val = 0;

void setup() {
  pinMode(verdem,OUTPUT);
  pinMode(galbenm,OUTPUT);
  pinMode(rosum,OUTPUT);
  pinMode(verdep,OUTPUT);
  pinMode(rosup,OUTPUT);
  pinMode(buton,INPUT);
  pinMode(senzor,INPUT);
}

void loop() {
  val = analogRead(senzor);
  if (val > 500 && ok == 1){
    digitalWrite(verdem, HIGH);
    digitalWrite(rosup, HIGH);
    ok = 2;
    glb = 2;
  }
  if (val > 500 && ok == 2){
    if(digitalRead(buton) == LOW){
      schimbaculori();
    }
  }
  if (val < 500 && glb == 2){
    oprestetot();
    glb = 1;
    ok = 1;
  }
  if (val < 500 && ok == 1 && glb == 1){
    digitalWrite(galbenm, HIGH);
    delay(500);
    digitalWrite(galbenm, LOW);
    delay(500);
  }

}

void oprestetot(){
  digitalWrite(verdem, LOW);
  digitalWrite(galbenm, LOW);
  digitalWrite(rosum, LOW);
  digitalWrite(verdep, LOW);
  digitalWrite(rosup, LOW);
}

void schimbaculori(){
  delay(100);
  for (int i = 1; i < 6; i++){
    digitalWrite(verdem, LOW);
    delay(300);
    digitalWrite(verdem, HIGH);
    delay(300);
  }
  digitalWrite(verdem, LOW);
  digitalWrite(galbenm, HIGH);
  delay(1000);
  digitalWrite(galbenm, LOW);
  digitalWrite(rosum, HIGH);
  delay(1000);
  digitalWrite(rosup, LOW);
  digitalWrite(verdep, HIGH);
  delay(5000);
  for (int i = 1; i < 6; i++){
    digitalWrite(verdep, LOW);
    delay(300);
    digitalWrite(verdep, HIGH);
    delay(300);
  }
  digitalWrite(verdep, LOW);
  digitalWrite(rosup, HIGH);
  delay(1000);
  digitalWrite(rosum, LOW);
  digitalWrite(verdem, HIGH);
}

