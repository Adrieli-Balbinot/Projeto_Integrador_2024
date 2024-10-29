# Conexão OTA e Controle Telnet com ESP8266

**Desenvolvido por:** Adrieli, Roberta e Tainá

## Visão Geral

Este projeto utiliza o microcontrolador ESP8266 para conectar-se a uma rede Wi-Fi, habilitar a atualização Over-The-Air (OTA) e estabelecer um servidor Telnet que permite controlar um LED remotamente. Através de uma conexão Telnet, é possível enviar comandos para ligar e desligar o LED conectado ao pino D1 do ESP8266.

## Objetivos

- Conectar o ESP8266 a uma rede Wi-Fi.
- Habilitar o recurso OTA para permitir atualizações de firmware remotamente.
- Criar um servidor Telnet que possibilite o controle de um LED através de comandos.

## Componentes Utilizados

- **ESP8266**: Microcontrolador com capacidade de conexão Wi-Fi.
- **LED**: Indicador visual controlado pelo ESP8266.
- **Bibliotecas**:
  - `<ESP8266WiFi.h>`
  - `<ArduinoOTA.h>`

## Estrutura do Código

### Variáveis de Configuração

- **`ssid`**: Nome da rede Wi-Fi (SSID).
- **`password`**: Senha da rede Wi-Fi. Mantenha-a segura para proteger o acesso ao dispositivo.
- **`LED_PIN`**: Pino do ESP8266 conectado ao LED (pino D1).

### Funções

#### `setup()`

- Configura o pino do LED como saída.
- Configura e conecta o ESP8266 à rede Wi-Fi.
- Define as funções de callback para as diferentes etapas da atualização OTA:
  - **Início**: Informa que a atualização foi iniciada.
  - **Progresso**: Exibe o progresso da atualização no console serial.
  - **Erro**: Exibe mensagens de erro no caso de falhas na atualização.
  - **Término**: Exibe uma mensagem de conclusão.
- Inicia o serviço OTA e exibe o endereço IP do dispositivo.
- Configura e inicia o servidor Telnet.

#### `loop()`

- Chama `ArduinoOTA.handle()` para verificar continuamente se uma nova atualização OTA está disponível.
- Verifica se há um novo cliente conectado ao servidor Telnet e, caso positivo, envia instruções sobre como controlar o LED.
- Lê comandos recebidos do cliente Telnet:
  - **Comando `1`**: Liga o LED e exibe uma mensagem de confirmação.
  - **Comando `0`**: Desliga o LED e exibe uma mensagem de confirmação.
  - Outros comandos: Informa que o comando é inválido e solicita o envio de `1` ou `0`.

### Controle via Telnet

Uma conexão Telnet permite controlar o LED remotamente. A seguir estão os comandos disponíveis:

- **`1`**: Liga o LED.
- **`0`**: Desliga o LED.
