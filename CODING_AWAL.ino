const int sensor = A0; //inisialisasi pin sensor
const int relay = 5;       //inisialisasi pin relay
const int ledGreen = 6;    //inisialisasi pin led hijau
const int ledYellow = 7;   //inisialisasi pin led kuning
const int ledRed = 8;      //inisialisasi pin merah

void setup() {
pinMode(sensor, INPUT);   //menetapkan pin A0 sebagai input
pinMode(relay, OUTPUT);       //menetapkan pin 5 sebagai output
pinMode(ledGreen, OUTPUT);    //menetapkan pin 6 sebagai output
pinMode(ledYellow, OUTPUT);   //menetapkan pin 7 sebagai output
pinMode(ledRed, OUTPUT);      //menetapkan pin 8 sebagai output
}

void loop() {
int dataAnalog = analogRead (sensor);  //membaca nilai dari pin sensor
Serial.print ("A0 : ");
Serial.print (dataAnalog);

//jika nilai A0 kurang dari 500, print kata serta nyalakan led hijau dan matikan led kuning, merah dan juga relay
if (dataAnalog < 500) {     //nilai awalnya 500 (jika nilainya kecil/500 dan tanah sedikit basah maka relay off)
  digitalWrite (relay, HIGH);                  //(jika nilainya besar/1500 dan tanah sedikit basah maka relay on)
  digitalWrite (ledGreen, HIGH);
  digitalWrite (ledYellow, LOW);
  digitalWrite (ledRed, LOW);
  }

 //tetapi, jika nilai A0 kurang dari 900, print kata serta nyalakan led kuning dan relay kemudian matikan led hijau dan juga merah
 else if (dataAnalog  < 900) {
  digitalWrite (relay, HIGH);
  digitalWrite (ledGreen, LOW);
  digitalWrite (ledYellow, HIGH);
  digitalWrite (ledRed, LOW);
 }

 //selain dari itu, hanya nyalakan led merah dan juga relay
 else                         //{ Serial.println (". Perlu Tambahan Air"); 
  digitalWrite (relay, LOW);
  digitalWrite (ledGreen, LOW);
  digitalWrite (ledYellow, LOW);
  digitalWrite (ledRed, HIGH);
  }
