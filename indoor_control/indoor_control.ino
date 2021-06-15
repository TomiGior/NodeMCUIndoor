//Este proyecto es para el control semi-automático de un indoor en un placard con WiFi y NodeMCU.
//Se intentará hacerlo full-automático para el futuro y lograr implementar una API que de soporte a APPS y Syslog-Ng

//Seccion de dispositivos a 220v
const int luz = 5;
//const int ventilador = 4;
//const int burbujas = 0;
//const int calefactor = 2;
const int boton1 = 4;

//Estado de dispositivos para verificación pre-cambio de estado.
boolean luz_flag = false;
int btn_value = 0;
//boolean ventilador_flag = false;
//boolean burbujas_flag = false;
//boolean calefactor_flag = false;

void setup() {
  //Iniciamos el monitor Serial para debuggear control points.
  Serial.begin(115200);
  pinMode(luz, OUTPUT);
  //  pinMode(ventilador, OUTPUT);
  //  pinMode(burbujas, OUTPUT);
  //  pinMode(calefactor, OUTPUT);
  //  pinMode(boton1, INPUT);
}

void loop() {
  Serial.print("\n\nBienvenidos al sketch de Indoor.\n");
  delay(100);
  btn_value = digitalRead(boton1);
  if (btn_value) {
    prendo_apago_luz(btn_value);
  }

}

void prendo_apago_luz(int boton) {
  if (boton == 1) {
    //Optimizar en función luego.
    if (luz_flag == false) {

      Serial.print("Luz encendida.\n");
      digitalWrite(luz, HIGH);
      luz_flag = true;
      delay(500);
    }
    else {
      Serial.print("Luz apagada.\n");
      digitalWrite(luz, LOW);
      luz_flag = false;
      delay(500);
    }
  }
  Serial.print("El estado del LED es " + String(luz_flag) + "\n");
}
