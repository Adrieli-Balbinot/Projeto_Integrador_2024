# Documentação do Projeto: Controle de Dispositivo com SinricPro e ESP8266

Este projeto utiliza um ESP8266 para controlar um dispositivo (como um relé) tanto via botão físico quanto remotamente usando a plataforma **SinricPro**. O dispositivo também pode ser integrado com assistentes de voz como Amazon Alexa ou Google Assistant.

---

## 🧾 Funcionalidades

- Controle de um relé por botão físico ou comando remoto via SinricPro.
- Atualização em tempo real do estado do dispositivo (ligado/desligado).
- Conexão Wi-Fi para comunicação com a nuvem.
- Proteção contra múltiplos acionamentos consecutivos (debounce do botão físico).

---

## 🛠️ Componentes Necessários

- **ESP8266 (NodeMCU ou outro modelo)**
- **Relé**
- **Botão físico**
- **Fonte de alimentação compatível com o ESP8266**

---

## 📋 Configurações Prévias

1. **Criar uma conta no [SinricPro](https://sinric.pro)**.
2. **Adicionar um dispositivo do tipo "Interruptor" na plataforma SinricPro**.
3. Anote as seguintes informações geradas:
   - **APP KEY** e **APP SECRET**
   - **ID do dispositivo**

4. Configure os dados de sua rede Wi-Fi:
   ```cpp
   #define WIFI_SSID "Sua_Rede"
   #define WIFI_PASS "Sua_Senha"
   ```

5. Substitua as credenciais do SinricPro:
   ```cpp
   #define APP_KEY "sua_app_key"
   #define APP_SECRET "seu_app_secret"
   #define SWITCH_ID "id_do_seu_dispositivo"
   ```

---

## 🔌 Esquema de Conexão

- **Botão físico**: conectado ao **GPIO0**.
- **Relé**: conectado ao **GPIO5**.

| Componente       | Pino ESP8266 |
|-------------------|--------------|
| Botão físico      | GPIO0        |
| Relé              | GPIO5        |

---

## 🧩 Código Explicado

### Importação de Bibliotecas
As bibliotecas usadas são:
- **ESP8266WiFi**: Para conexão à rede Wi-Fi.
- **SinricPro e SinricProSwitch**: Para integração com a plataforma SinricPro.

### Configurações de Wi-Fi
A função `setupWiFi()` conecta o ESP8266 à rede configurada. Caso a conexão seja bem-sucedida, o IP do dispositivo é exibido no **Serial Monitor**.

### Integração com SinricPro
A função `setupSinricPro()` estabelece a conexão com o servidor do SinricPro e define as ações para quando o dispositivo for ligado/desligado remotamente.

### Controle do Relé
O estado do relé é gerenciado pela função `onPowerState()` ao receber um comando remoto e pela função `handleButtonPress()` ao pressionar o botão físico.

### Proteção contra múltiplos acionamentos
Foi implementado um debounce simples usando a variável `lastBtnPress` para evitar múltiplos acionamentos do botão físico em curto intervalo de tempo.

---

## 📄 Estrutura do Código

1. **Setup**: Configura os pinos do botão e do relé, inicializa o Wi-Fi e conecta ao SinricPro.
2. **Loop Principal**: 
   - Verifica se o botão físico foi pressionado.
   - Monitora solicitações da plataforma SinricPro.

---

## 🚀 Como Usar

1. **Instale as bibliotecas necessárias**:
   - Adicione as bibliotecas **SinricPro** e **SinricProSwitch** na IDE Arduino.

2. **Carregue o código no ESP8266**:
   - Conecte seu ESP8266 ao computador.
   - Compile e faça o upload do código.

3. **Acompanhe o Serial Monitor**:
   - Observe as mensagens para verificar a conexão com o Wi-Fi e SinricPro.

4. **Teste o Controle**:
   - Pressione o botão físico para alternar o estado do relé.
   - Use a plataforma SinricPro para controlar o dispositivo remotamente.


## **Esquema de Conexão**

Abaixo está o esquema de conexão para o projeto:

![Arquitetura do projeto](imagens/WhatsApp%20Image%202024-11-19%20at%2021.12.33.jpeg)

## Demonstração do Projeto

Abaixo está um GIF demonstrando o funcionamento do projeto:

<!-- ![Funcionamento do Projeto](images/exemplo.gif) -->

