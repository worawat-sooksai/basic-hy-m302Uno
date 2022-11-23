


void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  
        Serial.println("basic hy-m302 uno src avaliable:");
        Serial.println("https://github.com/worawat-sooksai/basic-hy-m302Uno");
        Serial.println("Menu avaiable:");
        Serial.println("DHT11 (temperature,humidity) keyboard type:dht");
        Serial.println("SOUND buzzer note() keyboard type:buzzer");
        Serial.println("Type exit for quit function:exit");
        
        String Str_input;

        while(Str_input != "exit") {
          
          if(Serial.available()){
             Str_input= Serial.readString();
            Serial.println("you choose:"+Str_input);
            while(Str_input.trim()=="dht"){
              m_dht();
            }
          }
          
        }
        
        Str_input = "null";
      

}

void m_dht(){
  
      Serial.println("DHT11 (temperature,humidity) keyboard type:dht");
    
    
    
  }
