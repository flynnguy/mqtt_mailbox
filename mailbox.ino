#include <ESP8266WiFi.h>
#include <PubSubClient.h>

ADC_MODE(ADC_VCC);

const char* ssid = "<ssid>";
const char* password = "<ssid_password>";
const char* mqtt_server = "<mqtt_hostname>";
const String clientId = "mailbox";

WiFiClient espClient;
PubSubClient client(espClient);

// setup_wifi connects to the WiFi
void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  Serial.print("\n");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// get_voltage puts the value of the battery into the byte array *b
void get_voltage(byte *b) {
  uint16_t battery_level = ESP.getVcc();
  String vcc = String(battery_level/1024.0);
  Serial.println(vcc);
  
  vcc.getBytes(b, 5);
}

void send_messages() {
  byte b[5];
  Serial.print("Attempting MQTT connection...");
        
  // Attempt to connect
  if (client.connect(clientId.c_str())) {
    Serial.println("connected");
    get_voltage(b);
      
    client.publish("homeassistant/mailbox/voltage", b, 5);  
    client.publish("homeassistant/mailbox", "opened");

    client.disconnect();
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
  } 
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  send_messages();
  
  Serial.println("Going to sleep...");
  ESP.deepSleep(0); 
}
