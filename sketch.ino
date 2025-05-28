#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic = "grupo5/reuso";


WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("esp32-grupo5")) {
      Serial.println("conectado!");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Simulação de sensores
  float ph = random(60, 80) / 10.0;
  float turbidez = random(15, 35) / 10.0;

  char mensagem[64];
  snprintf(mensagem, sizeof(mensagem), "{\"ph\": %.2f, \"turbidez\": %.2f}", ph, turbidez);

  client.publish(mqtt_topic, mensagem);
  Serial.println("Enviado via MQTT: ");
  Serial.println(mensagem);

  delay(5000);
}
