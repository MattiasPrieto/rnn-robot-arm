//Primera prueba de mover el motor vertical, a traves de angulos
int vel = 5;        //Tiempo de retardo (milisegundos) := Velocidad del motor 
int angulo1;            //Valor recibido en grados (0° a 360°)
int numero_pasos1 = 0;   //Valor en grados donde se encuentra el motor
String leeCadena1;       //Almacena la cadena de datos recibida
void setup() {
Serial.begin(9600);
pinMode(6,OUTPUT);  //IN1
pinMode(7,OUTPUT);  //IN2
pinMode(8,OUTPUT);  //IN3
pinMode(9,OUTPUT);  //IN4
}

void loop() {
  while(Serial.available()){    //Lee el valor enviado por el Puerto serial
    delay(vel);
    char c =Serial.read();      //Lee los caracteres
    leeCadena1 +=c;              //Convierte caracteres a cadena de caracteres 
  }
  if (leeCadena1.length()>0){
    angulo1 = leeCadena1.toInt(); //Convierte cadena de caracteres a Enteros
      Serial.print(angulo1);       //Envia valor en Grados
      Serial.println(" Grados");
    delay(vel);
    angulo1 = (angulo1 * 5)/12;     //Ajuste de relación
    angulo1 = (angulo1 * 5.661111111); // Ajuste de 2038 pasos por revolucion a 360  
  }
  while(angulo1>numero_pasos1){     //Giro hacia la izquierda en grados
    paso_izq(); 
    numero_pasos1 = numero_pasos1 +1;
  }  
  while(angulo1<numero_pasos1){     //Giro hacia la derecha en grados
    paso_der(); 
    numero_pasos1 = numero_pasos1 -1;
  }
  leeCadena1 = "";
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);                     //Se apaga el motor
}
///////////////////Funciones////////////////////////////////////////////////////////
void paso_der(){            //pasos a la derecha
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(vel);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(vel);
}
void paso_izq(){            //pasos a la izquierda
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(vel);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(vel);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(vel);
}
