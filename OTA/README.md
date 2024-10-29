# Conexão e Atualização OTA com ESP8266

**Desenvolvido por:** Adrieli, Roberta e Tainá

## Visão Geral

Este projeto implementa uma conexão Wi-Fi para um dispositivo ESP8266, usando uma rede previamente configurada, e habilita o recurso de **Atualização Over-The-Air (OTA)**. O recurso OTA permite que o código do dispositivo seja atualizado remotamente, sem a necessidade de conexão física, o que facilita a manutenção e a adição de novas funcionalidades.

## Objetivos

- Conectar o ESP8266 a uma rede Wi-Fi.
- Habilitar o recurso OTA para permitir atualizações de firmware remotamente.
- Exibir o progresso da atualização e tratar possíveis erros durante o processo OTA.

## Componentes Utilizados

- **ESP8266:** Microcontrolador com capacidade de conexão Wi-Fi.
- **Bibliotecas:** 
  - `<Arduino.h>`
  - `<ESP8266WiFi.h>`
  - `<ArduinoOTA.h>`

## Estrutura do Código

### Variáveis de Configuração

- **`ssid`**: Nome da rede Wi-Fi (SSID).
- **`password`**: Senha da rede Wi-Fi. É importante mantê-la segura para proteger o acesso ao dispositivo.

### Funções

#### `setup()`

- Configura a conexão Wi-Fi do ESP8266.
- Realiza tentativas de reconexão caso a conexão falhe.
- Configura os eventos de início, fim, progresso e erro para o processo OTA.
- Inicia o serviço OTA e exibe o endereço IP do dispositivo no console serial.

#### `loop()`

- Invoca o método `ArduinoOTA.handle()`, que verifica continuamente se uma nova atualização OTA está disponível.

### Funcionalidades OTA

- **Início (`onStart`)**: Informa que a atualização começou.
- **Término (`onEnd`)**: Exibe uma mensagem de conclusão.
- **Progresso (`onProgress`)**: Exibe o percentual de progresso da atualização no console serial.
- **Erros (`onError`)**: Informa sobre diferentes erros que podem ocorrer durante o processo OTA, incluindo falhas de autenticação, conexão e recebimento de dados.
