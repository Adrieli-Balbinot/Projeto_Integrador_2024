# Controle de LED com ESP8266 via Web e OTA

Este projeto utiliza um ESP8266 para controlar o LED embutido através de uma interface web e permite atualizações OTA (Over-The-Air).

---

## 📋 Funcionalidades

- *Controle de LED via Web*: 
  - Página HTML hospedada no ESP8266 com botões para ligar e desligar o LED.
- *Configuração de Rede*: 
  - Conexão WiFi e configuração de IP estático.
- *Atualizações OTA*: 
  - Atualizações de firmware remotas protegidas por senha.

---

## 🚀 Como Usar

1. *Configuração do WiFi*: 
   No código, ajuste as variáveis ssid e password para as credenciais da sua rede WiFi:
   cpp
   const char* ssid = "Seu_SSID";
   const char* password = "Sua_Senha";
   

2. *Configuração de IP Estático* (opcional):  
   Configure o IP, gateway e máscara de sub-rede:
   cpp
   IPAddress local_IP(192,168,1,100);  // IP desejado para o ESP8266
   IPAddress gateway(192,168,1,1);    // Gateway da sua rede
   IPAddress subnet(255,255,255,0);   // Máscara de sub-rede
   

3. *Compilar e Carregar o Código*:
   - Use o Arduino IDE ou outro editor compatível para compilar o código e carregar no ESP8266.

4. *Acessar a Interface Web*:
   - Após a conexão WiFi, abra um navegador e insira o IP configurado (exemplo: http://192.168.1.100).

5. *Atualizações OTA*:
   - A senha para OTA está definida no código como:
     cpp
     ArduinoOTA.setPassword("sua_senha_OTA");
     

---

## 🛠️ Dependências

- *Bibliotecas Arduino*:
  - ArduinoOTA
  - ESP8266WiFi
  - ESP8266WebServer

Certifique-se de instalar essas bibliotecas na Arduino IDE antes de compilar.

---

## 📄 Código Explicado

1. *Configuração de WiFi e IP*:
   - O ESP8266 conecta à rede especificada e usa o IP configurado.

2. *Servidor Web*:
   - Hospeda uma página HTML com botões "ON" e "OFF" que controlam o LED embutido.

3. *Rotas HTTP*:
   - /: Exibe a página de controle.
   - /on: Liga o LED.
   - /off: Desliga o LED.

4. *Atualização OTA*:
   - Permite atualizações remotas usando ferramentas como a Arduino IDE.

---

## 📌 Exemplo de Uso

### Página Web de Controle

Ao acessar o IP configurado, você verá uma interface simples como esta:

- Botão verde para ligar o LED.
- Botão vermelho para desligar o LED.

---

## 🌐 Contribuição

Sinta-se à vontade para melhorar este projeto enviando PRs ou sugerindo melhorias!

--- 

## 📝 Licença

Este projeto está sob a licença MIT. Consulte o arquivo LICENSE para mais detalhes.