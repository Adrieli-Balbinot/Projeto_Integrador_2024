// VERSÃO DUVIDOSA 2
// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
// #include <ArduinoOTA.h>

// // Credenciais WiFi
// const char* ssid = "Rede_adri";
// const char* password = "socorro12";

// // Configuração de IP fixo
// IPAddress local_IP(192,168,143,54); // IP desejado para o ESP8266
// IPAddress gateway(192,168,143,1);   // Gateway correto conforme a imagem
// IPAddress subnet(255,255,255,0);    // Máscara de sub-rede

// // Configuração do servidor web e LED embutido
// ESP8266WebServer server(80);
// const int ledPin = LED_BUILTIN; // Define o LED embutido

// // Funções para controle do LED e a página HTML
// void handleRoot();
// void handleOn();
// void handleOff();

// void setup() {
//     Serial.begin(9600);
//     pinMode(ledPin, OUTPUT);
//     digitalWrite(ledPin, HIGH); // Apaga o LED (padrão é inverso no ESP8266)

//     // Configuração do WiFi com IP fixo
//     if (!WiFi.config(local_IP, gateway, subnet)) {
//         Serial.println("Falha ao configurar IP fixo.");
//     }
//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println("\nWiFi conectado.");
//     Serial.print("Endereço IP: ");
//     Serial.println(WiFi.localIP());

//     // Configuração do servidor web
//     server.on("/", HTTP_GET, handleRoot);
//     server.on("/led/on", HTTP_GET, handleOn);
//     server.on("/led/off", HTTP_GET, handleOff);
//     server.begin();

//     // Configuração OTA
//     ArduinoOTA.onStart([]() {
//         Serial.println("Iniciando atualização OTA...");
//     });
//     ArduinoOTA.onEnd([]() {
//         Serial.println("\nAtualização concluída.");
//     });
//     ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
//         Serial.printf("Progresso: %u%%\r", (progress / (total / 100)));
//     });
//     ArduinoOTA.onError([](ota_error_t error) {
//         Serial.printf("Erro[%u]: ", error);
//         if (error == OTA_AUTH_ERROR) Serial.println("Falha na autenticação");
//         else if (error == OTA_BEGIN_ERROR) Serial.println("Falha no início");
//         else if (error == OTA_CONNECT_ERROR) Serial.println("Falha na conexão");
//         else if (error == OTA_RECEIVE_ERROR) Serial.println("Falha no recebimento");
//         else if (error == OTA_END_ERROR) Serial.println("Falha na finalização");
//     });
//     ArduinoOTA.begin();
//     Serial.println("Pronto para atualizações OTA.");
// }

// void loop() {
//     server.handleClient();
//     ArduinoOTA.handle();
// }

// // Funções para a página web e controle do LED
// void handleRoot() {
//     String html = R"rawliteral(
//         <!DOCTYPE html>
//         <html>
//         <head>
//             <meta name="viewport" content="width=device-width, initial-scale=1">
//             <link rel="icon" href="data:,">
//             <style>
//                 html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }
//                 .button { background-color: #EE82EE; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }
//                 .button2 { background-color: #EE82EE; }
//             </style>
//         </head>
//         <body>
//             <h1>ESP8266 Web Server</h1>
//             <h2>Alunas Adrieli, Taina e Roberta</h2>
//             <button onclick="toggleLED('on')" class="button">ON</button>
//             <button onclick="toggleLED('off')" class="button button2">OFF</button>
//             <script>
//                 function toggleLED(state) {
//                     var xhr = new XMLHttpRequest();
//                     xhr.open('GET', '/led/' + state, true);
//                     xhr.send();
//                 }
//             </script>
//         </body>
//         </html>
//     )rawliteral";
//     server.send(200, "text/html", html);
// }

// void handleOn() {
//     digitalWrite(ledPin, LOW); // Liga o LED embutido (inverso no ESP8266)
//     server.send(200, "text/plain", "LED Ligado!");
// }

// void handleOff() {
//     digitalWrite(ledPin, HIGH); // Desliga o LED embutido
//     server.send(200, "text/plain", "LED Desligado!");
// }

// VERSÃO DUVIDOSA 2
// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
// #include <ArduinoOTA.h>

// // Credenciais WiFi
// const char* ssid = "Rede_adri";
// const char* password = "socorro12";

// // Configuração de IP fixo
// IPAddress local_IP(192,168,143,54);
// IPAddress gateway(192,168,143,1);
// IPAddress subnet(255,255,255,0);

// // Configuração do servidor web e LED embutido
// ESP8266WebServer server(80);
// const int ledPin = LED_BUILTIN; // LED embutido do ESP8266

// // Funções para controle do LED e a página HTML
// void renderWebPage();
// void turnOnLED();
// void turnOffLED();

// void setup() {
//     Serial.begin(9600);

//     // Configura o LED embutido
//     pinMode(ledPin, OUTPUT);
//     digitalWrite(ledPin, HIGH); // Apaga o LED

//     // Configuração do WiFi com IP fixo
//     Serial.println("Conectando ao WiFi...");
//     if (!WiFi.config(local_IP, gateway, subnet)) {
//         Serial.println("Erro: Falha ao configurar IP fixo.");
//     }
//     WiFi.begin(ssid, password);

//     // Tenta conexão WiFi
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println("\nWiFi conectado.");
//     Serial.print("Endereço IP: ");
//     Serial.println(WiFi.localIP());

//     // Configuração do servidor web
//     server.on("/", HTTP_GET, renderWebPage);
//     server.on("/led/on", HTTP_GET, turnOnLED);
//     server.on("/led/off", HTTP_GET, turnOffLED);
//     server.begin();
//     Serial.println("Servidor web iniciado.");

//     // Configuração OTA com autenticação
//     ArduinoOTA.setPassword("senhaSegura123"); // Altere para uma senha forte
//     ArduinoOTA.onStart([]() {
//         String type = (ArduinoOTA.getCommand() == U_FLASH) ? "sketch" : "filesystem";
//         Serial.println("Iniciando atualização OTA: " + type);
//     });
//     ArduinoOTA.onEnd([]() {
//         Serial.println("\nAtualização OTA concluída.");
//     });
//     ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
//         Serial.printf("Progresso OTA: %u%%\r", (progress / (total / 100)));
//     });
//     ArduinoOTA.onError([](ota_error_t error) {
//         Serial.printf("Erro OTA [%u]: ", error);
//         if (error == OTA_AUTH_ERROR) Serial.println("Erro de autenticação");
//         else if (error == OTA_BEGIN_ERROR) Serial.println("Erro no início");
//         else if (error == OTA_CONNECT_ERROR) Serial.println("Erro de conexão");
//         else if (error == OTA_RECEIVE_ERROR) Serial.println("Erro de recebimento");
//         else if (error == OTA_END_ERROR) Serial.println("Erro na finalização");
//     });
//     ArduinoOTA.begin();
//     Serial.println("Pronto para atualizações OTA.");
// }

// void loop() {
//     server.handleClient();
//     ArduinoOTA.handle();
// }

// // Renderiza a página web
// void renderWebPage() {
//     String html = R"rawliteral(
//         <!DOCTYPE html>
//         <html>
//         <head>
//             <meta name="viewport" content="width=device-width, initial-scale=1">
//             <style>
//                 html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }
//                 .button { background-color: #EE82EE; border: none; color: white; padding: 16px 40px; font-size: 30px; cursor: pointer; }
//             </style>
//         </head>
//         <body>
//             <h1>ESP8266 Web Server</h1>
//             <h2>Alunas Adrieli, Taina e Roberta</h2>
//             <button onclick="toggleLED('on')" class="button">ON</button>
//             <button onclick="toggleLED('off')" class="button">OFF</button>
//             <script>
//                 function toggleLED(state) {
//                     var xhr = new XMLHttpRequest();
//                     xhr.open('GET', '/led/' + state, true);
//                     xhr.send();
//                 }
//             </script>
//         </body>
//         </html>
//     )rawliteral";
//     server.send(200, "text/html", html);
//     Serial.println("Página web renderizada.");
// }

// // Liga o LED embutido
// void turnOnLED() {
//     digitalWrite(ledPin, LOW); // Liga o LED (inverso no ESP8266)
//     server.send(200, "text/plain", "LED Ligado!");
//     Serial.println("LED ligado via HTTP.");
// }

// // Desliga o LED embutido
// void turnOffLED() {
//     digitalWrite(ledPin, HIGH); // Desliga o LED
//     server.send(200, "text/plain", "LED Desligado!");
//     Serial.println("LED desligado via HTTP.");
// }






// Para documentar o projeto do NodeMCU ESP8266, aqui está um guia dividido em seções conforme solicitado:

// ### 1. Documentação Técnica

// #### 1.1. Passo a Passo de Desenvolvimento e Configuração

// 1. **Configuração do Hardware**:
//    - **Conectar o NodeMCU ESP8266 ao computador** via cabo USB.
//    - **Configurar o LED embutido** no NodeMCU para controle via software. No código, usamos `LED_BUILTIN` (normalmente na porta D4) que indica o LED embutido.

// 3. **Configuração da Rede WiFi**:
//    - No código, defina as credenciais de WiFi substituindo `ssid` e `password` pelos valores da sua rede.
//    - **Configuração de IP Fixo**: Altere `local_IP`, `gateway`, e `subnet` conforme necessário para o seu ambiente.

// 4. **Função OTA**:
//    - Configure a senha OTA alterando `senhaSegura123` para uma senha personalizada e forte para aumentar a segurança das atualizações OTA.

// #### 1.2. Funcionamento do Servidor Web e Explicação das Rotas

// - **Servidor Web**: O ESP8266 hospeda um servidor web na porta 80. Quando o dispositivo está conectado ao WiFi, é possível acessar a interface web inserindo o endereço IP (neste caso, `192.168.143.54`) no navegador.
// - **Rotas Disponíveis**:
//   - `"/"`: Rota principal que carrega a interface web com dois botões, **ON** e **OFF**, para controle do LED.
//   - `"/led/on"`: Rota acionada ao clicar no botão **ON**; ativa o LED embutido.
//   - `"/led/off"`: Rota acionada ao clicar no botão **OFF**; desliga o LED embutido.

// ### 2. Fotos

// - Inclua as fotos do NodeMCU, tiradas durante os experimentos, para mostrar a configuração do hardware. Se possível, organize as fotos para demonstrar o LED embutido em funcionamento, o NodeMCU conectado ao computador e a interface web sendo acessada.

// ### 3. Testes

// #### 3.1. Teste do Servidor Web e Controle do LED

// 1. **Acesse o servidor web**:
//    - Conecte seu dispositivo à mesma rede WiFi e insira o endereço IP do ESP8266 (`192.168.143.54`).
//    - Verifique se a interface com os botões ON e OFF é carregada no navegador.

// 2. **Controle do LED**:
//    - Clique no botão **ON** e observe o LED embutido acender.
//    - Clique no botão **OFF** e confirme que o LED é desligado.
//    - Verifique no monitor serial da IDE Arduino se as mensagens de debug confirmam as mudanças de estado do LED.

// #### 3.2. Teste OTA

// 1. **Configuração OTA no Arduino IDE**:
//    - Em `Ferramentas`, selecione `Porta` e escolha a entrada OTA do NodeMCU (geralmente aparece como `esp8266-[ENDEREÇO-IP]`).
//    - **Inicie uma atualização OTA**: Abra um código atualizado na IDE e envie para o dispositivo.
//    - **Verificação da Autenticação**: Quando solicitado, insira a senha OTA definida (ex: `senhaSegura123`). Verifique no monitor serial que a atualização foi iniciada e acompanhe o progresso.
//    - Ao final, o dispositivo deve reiniciar e operar com o firmware atualizado.

// Esses passos fornecem uma estrutura completa para documentação, com orientações para configuração, operação, e testes.







// ### Explicação Detalhada do Código

// 1. **Bibliotecas Importadas**
//    - `ArduinoOTA`: permite a atualização do firmware do ESP8266 pela rede sem fio (OTA).
//    - `ESP8266WiFi`: gerencia a conexão WiFi.
//    - `ESP8266WebServer`: fornece funcionalidades para criar um servidor web no ESP8266.

// 2. **Configurações Iniciais**
//    - `ssid` e `password` armazenam as credenciais de WiFi.
//    - `server(80)`: inicializa o servidor web na porta 80 (porta padrão HTTP).
//    - `led` define o pino do LED embutido (LED_BUILTIN).
//    - `local_IP`, `gateway`, e `subnet` configuram o ESP8266 para usar um IP fixo.

// 3. **Funções de Configuração e Controle**

//    - `configureWiFi()`: conecta o ESP8266 à rede WiFi usando o IP fixo especificado. Imprime mensagens de status no monitor serial durante a conexão.
   
//    - `handleRoot()`: cria uma página HTML para o controle do LED. A página contém dois botões, **ON** e **OFF**, que acionam funções no servidor para ligar ou desligar o LED.
   
//    - `turnOnLED()` e `turnOffLED()`: funções que ligam ou desligam o LED embutido e enviam uma resposta de texto ao navegador, além de mostrar o status do LED no monitor serial.

// 4. **Configuração OTA**
//    - `ArduinoOTA.setPassword("garotas")`: define uma senha de autenticação para a atualização OTA.
//    - `ArduinoOTA.onStart`, `onEnd`, `onProgress`, e `onError`: funções de callback para exibir mensagens no monitor serial durante as atualizações OTA (por exemplo, iniciar, concluir, exibir o progresso e lidar com erros).

// 5. **Configuração do Servidor Web**
//    - `server.on("/", HTTP_GET, handleRoot)`: define a rota principal (`"/"`) que chama a função `handleRoot()` para exibir a interface web.
//    - `server.on("/on", HTTP_GET, turnOnLED)` e `server.on("/off", HTTP_GET, turnOffLED)`: definem rotas para os botões ON e OFF.

// 6. **Função `setup()`**
//    - Configura o monitor serial e o pino do LED.
//    - Configura e conecta o WiFi com IP fixo.
//    - Configura as rotas do servidor web e inicializa a funcionalidade OTA.

// 7. **Função `loop()`**
//    - `ArduinoOTA.handle()`: verifica continuamente se há atualizações OTA pendentes.
//    - `server.handleClient()`: mantém o servidor web ativo e pronto para responder às requisições do navegador.

// ### Resumo
// - Acesse a interface web pelo IP fixo para controlar o LED embutido.
// - Permite atualizar o firmware remotamente usando OTA com uma senha de segurança.




#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Rede_adri";
const char* password = "socorro12";

ESP8266WebServer server(80);  // Inicializa o servidor web na porta 80.
const int led = LED_BUILTIN;   // Define o LED embutido como 'led'.

IPAddress local_IP(192,168,143,54); // IP desejado para o ESP8266
IPAddress gateway(192,168,143,1);   // Gateway correto conforme a imagem
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
























