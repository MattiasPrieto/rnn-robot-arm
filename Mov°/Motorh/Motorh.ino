//Primera prueba de mover el motor vertical, a traves de angulos
int vel = 5;        //Tiempo de retardo (milisegundos) := Velocidad del motor 
int angulo2;            //Valor recibido en grados (0° a 360°)
int numero_pasos2 = 0;   //Valor en grados donde se encuentra el motor
String leeCadena2;       //Almacena la cadena de datos recibida
void setup() {
Serial.begin(9600);
pinMode(10,OUTPUT);  //IN1
pinMode(11,OUTPUT);  //IN2
pinMode(12,OUTPUT);  //IN3
pinMode(13,OUTPUT);  //IN4
}

void loop() {
  while(Serial.available()){    //Lee el valor enviado por el Puerto serial
    delay(vel);
    char c =Serial.read();      //Lee los caracteres
    leeCadena2 +=c;              //Convierte caracteres a cadena de caracteres 
  }
  if (leeCadena2.length()>0){
    angulo2= leeCadena2.toInt(); //Convierte cadena de caracteres a Enteros
      Serial.print(angulo2);       //Envia valor en Grados
      Serial.println(" Grados");
    delay(vel);
    angulo2 = (angulo2 * 5)/12;     //Ajuste de relación
    angulo2 = (angulo2 * 5.661111111); // Ajuste de 2038 pasos por revolucion a 360  
  }
  while(angulo2>numero_pasos2){     //Giro hacia la izquierda en grados
    paso_izq(); 
    numero_pasos2 = numero_pasos2 +1;
  }  
  while(angulo2<numero_pasos2){     //Giro hacia la derecha en grados
    paso_der(); 
    numero_pasos2 = numero_pasos2 -1;
  }
  leeCadena2 = "";
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);                     //Se apaga el motor
}
///////////////////Funciones////////////////////////////////////////////////////////
void paso_der(){            //pasos a la derecha
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(vel);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(vel);
}
void paso_izq(){            //pasos a la izquierda
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(vel);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(vel);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(vel);
}
