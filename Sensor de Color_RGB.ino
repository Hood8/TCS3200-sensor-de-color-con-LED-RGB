/* Este proyecto esta protegido por la licencia de software libre GNU General Public License (GPL) 3.0

Código para detectar colores mediante un sensor de color TCS3200 y un Led RGB para visualizar el resultado

Circuito:
 
  1 Arduino Uno u otras placas base compatibles
  1 sensor de color TCS3200
  1 led RGB
    
  Lista de componentes conectados a entradas:
      Sensor de color TCS3200 : Pines S0, S1, S2,S3
                
    
  Lista de componentes conectados a salidas:
     
       Sensor de color TCS3200: Pin OUT
       LED RGB: pines R,G,B
  
  FECHA :16/02/2020
  AUTOR José María Mejuto
  
  
*/

//  Pines del Sensor de color TCS3200  a pines del arduino
#define S1 7                  // Pin S1 a pin 7 en el arduino
#define S0 8                  // Pin S2 a pin 8 en el arduino
#define S3 9                  // Pin S3 a pin 9 en el arduino
#define S2 10                 // Pin S4 a pin 10 en el arduino
#define salidaSensor 11       // Pin OUT a pin 11 en el arduino

// Guarda la frecuencia leída por los fotodiodos
unsigned long frecuenciaRoja = 0;
unsigned long frecuenciaVerde = 0;
unsigned long frecuenciaAzul = 0;

//RGB pines al arduino
int ledRojo=3;
int ledVerde=5;
int ledAzul=6;


void setup() {  
  // Configuracion de los pines del sensor de color "SO,S1,S2,S3" y led RGB como salida
  
  pinMode (ledRojo, OUTPUT);
  pinMode (ledVerde,OUTPUT);
  pinMode (ledAzul, OUTPUT);
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Configuracion del pin "out"del sensor de color  como salida
  
  pinMode(salidaSensor, INPUT);  
  
  
  // Configuracion de la escala de frecuencia al 20 %  
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);  
  
  
   // iniciando el Puerto en Serie
   
  Serial.begin(9600);
}
void loop() {
  
  // Configuración de los fotodiodos de filtro rojo para ser leídos
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW); 
  
  // Lectura de la frecuencia de salida
  frecuenciaRoja = pulseIn(salidaSensor, LOW);
  
   // imprimiendo en el monitor en serie el valor de frecuencia de los fotodiodo rojo
  Serial.print("R = ");
  Serial.print(frecuenciaRoja);  
  delay(100);
  
  // Configuración de los fotodiodos de filtro verde para ser leídos
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Lectura de la frecuencia de salida
  frecuenciaVerde = pulseIn(salidaSensor, LOW);
  
  // Imprimiendo en el monitor en serie el valor de frecuencia de los fotodiodos verdes 
  Serial.print(" G = ");
  Serial.print(frecuenciaVerde);  
  delay(100);
 
  // Configuración de los fotodiodos de filtro azul para ser leídos
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Lectura de la frecuencia de salida
  frecuenciaAzul = pulseIn(salidaSensor, LOW);
  
  // Imprimiendo en el monitor en serie el valor de frecuencia de los fotodiodos azules 
  Serial.print(" B = ");
  Serial.println(frecuenciaAzul);  
  delay(100);
  
  
  
  if ( frecuenciaRoja < frecuenciaVerde && frecuenciaRoja < frecuenciaAzul ) { 
              digitalWrite (ledRojo, HIGH);
              digitalWrite (ledVerde, LOW);
              digitalWrite (ledAzul, LOW);
              // do Thing A
            }
  else if (frecuenciaVerde < frecuenciaRoja && frecuenciaVerde < frecuenciaAzul) {
              digitalWrite (ledRojo, LOW);
              digitalWrite (ledVerde, HIGH);
              digitalWrite (ledAzul, LOW);
  // do Thing B
    }
  else    {      
              digitalWrite (ledRojo, LOW);
              digitalWrite (ledVerde, LOW);
              digitalWrite (ledAzul, HIGH);
  // do Thing C
    }
    
    delay (1000);
}
//Creado por José María Mejuto Ferro siguiendo lecciones de los tutoriales de arduino online
//Agradecimientosa todos los que colaboran por extender el conocimiento y especialmente a mis camaradas rojos 
//que dan su vida por nosotros luchando contra el sistema según sus posibilidades y rangos de acción.

//Octubre 2018
