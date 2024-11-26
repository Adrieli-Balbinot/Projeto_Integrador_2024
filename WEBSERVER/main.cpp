#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Rede_adri";
const char* password = "socorro12";

ESP8266WebServer server(80);  // Inicializa o servidor web na porta 80.
const int led = LED_BUILTIN;   // Define o LED embutido como 'led'.

IPAddress local_IP(192,168,143,54); // IP desejado para o ESP8266
IPAddress gateway(192,168,143,1);   
IPAddress subnet(255,255,255,0);    // Máscara de sub-rede

void configureWiFi();
void handleRoot();
void turnOnLED();
void turnOffLED();

void configureWiFi() {
  WiFi.mode(WIFI_STA);  // Define o modo do WiFi como estação (STA).
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("Falha ao configurar IP.");
  }
  WiFi.begin(ssid, password);  // Conecta ao WiFi com as credenciais fornecidas.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void handleRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  html += "<link rel=\"icon\" href=\"data:,\">";
  html += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-color: #4b5563; color: #f8fafc;}";
  html += ".button { background-color: #22c55e; border: none; color: white; padding: 16px 40px;";
  html += "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
  html += ".button2 {background-color: #ef4444;}</style></head>";
  html += "<body><h1>Turning on LED of NodeMCU</h1>";
  html += "<h2>Buttons</h2>";
  html += "<button onclick=\"toggleLED('on')\" class=\"button\">ON</button>";
  html += "<button onclick=\"toggleLED('off')\" class=\"button button2\">OFF</button>";
  html += "<script>";
  html += "function toggleLED(state) {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/' + state, true);";
  html += "  xhr.send();";
  html += "}";
  html += "</script>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void turnOnLED() {
  digitalWrite(led, LOW);  // Liga o LED embutido (LOW acende o LED no ESP8266).
  server.send(200, "text/plain", "LED Ligado!");
  Serial.println("LED foi ligado.");
}

void turnOffLED() {
  digitalWrite(led, HIGH); // Desliga o LED embutido.
  server.send(200, "text/plain", "LED Desligado!");
  Serial.println("LED foi desligado.");
}


void setup() {
  Serial.begin(9600);  // Inicializa o monitor serial para debug.
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);  // Desliga o LED (LED_BUILTIN é ativo em LOW).

  ArduinoOTA.setPassword("garotas");  // Define a senha de autenticação para OTA.

  configureWiFi();  // Conecta ao WiFi e configura o IP fixo.

  // Callbacks para monitorar o processo OTA
  ArduinoOTA.onStart([]() { Serial.println("Start"); });
  ArduinoOTA.onEnd([]() { Serial.println("\nEnd"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
  });

  // Define as rotas do servidor
  server.on("/", HTTP_GET, handleRoot);      // Rota principal.
  server.on("/on", HTTP_GET, turnOnLED);     // Rota para ligar o LED.
  server.on("/off", HTTP_GET, turnOffLED);   // Rota para desligar o LED.
  server.begin();

  ArduinoOTA.begin();  // Inicializa o serviço OTA.
  Serial.println("Pronto para uso.");
}

void loop() {
  ArduinoOTA.handle();     // Processa eventos OTA (necessário para a atualização OTA).
  server.handleClient();   // Processa as requisições HTTP para o servidor.
}
























