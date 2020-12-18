//Primera prueba de mover el motor de la base, a traves de angulos
int vel = 5;        //Tiempo de retardo (milisegundos) := Velocidad del motor 
int angulo;            //Valor recibido en grados (0° a 360°)
int numero_pasos = 0;   //Valor en grados donde se encuentra el motor
String leeCadena;       //Almacena la cadena de datos recibida
void setup() {
Serial.begin(9600);
pinMode(2,OUTPUT);  //IN1
pinMode(3,OUTPUT);  //IN2
pinMode(4,OUTPUT);  //IN3
pinMode(5,OUTPUT);  //IN4
}

void loop() {
  while(Serial.available()){    //Lee el valor enviado por el Puerto serial
    delay(vel);
    char c =Serial.read();      //Lee los caracteres
    leeCadena +=c;              //Convierte caracteres a cadena de caracteres 
  }
  if (leeCadena.length()>0){
    angulo = leeCadena.toInt(); //Convierte cadena de caracteres a Enteros
      Serial.print(angulo);       //Envia valor en Grados
      Serial.println(" Grados");
    delay(vel);
    angulo = (angulo * 21)/40;     //Ajuste de relación
    angulo = (angulo * 5.661111111); // Ajuste de 2038 pasos por revolucion a 360  
  }
  while(angulo>numero_pasos){     //Giro hacia la izquierda en grados
    paso_izq(); 
    numero_pasos = numero_pasos +1;
  }  
  while(angulo<numero_pasos){     //Giro hacia la derecha en grados
    paso_der(); 
    numero_pasos = numero_pasos -1;
  }
  leeCadena = "";
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);                     //Se apaga el motor
}
///////////////////Funciones////////////////////////////////////////////////////////
void paso_der(){            //pasos a la derecha
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  delay(vel);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  delay(vel);
}
void paso_izq(){            //pasos a la izquierda
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  delay(vel);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  delay(vel);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  delay(vel);
}
