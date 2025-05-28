# Projeto de Reuso de Água com MQTT

Este projeto tem como objetivo simular um sistema de monitoramento da qualidade da água reutilizada, enviando dados de sensores de pH e turbidez via protocolo MQTT para um broker externo. O sistema foi desenvolvido utilizando o microcontrolador ESP32 no ambiente de simulação [Wokwi](https://wokwi.com/).

## 🔧 Componentes Utilizados

- ESP32 DevKit (simulado)
- Sensor de pH (simulado)
- Sensor de turbidez (simulado)
- Conexão Wi-Fi (Wokwi-GUEST)
- Broker MQTT externo: `broker.hivemq.com`
- Tópico MQTT: `grupo5/reuso`
- Biblioteca: `PubSubClient` (v2.8)

## 🚀 Funcionamento

1. O ESP32 simula leituras periódicas de sensores de pH e turbidez.
2. Os dados são formatados em JSON.
3. A cada 5 segundos, os dados são publicados no tópico MQTT `grupo5/reuso` do broker público `broker.hivemq.com`.
4. Esses dados podem ser visualizados em tempo real via [HiveMQ Web Client](http://www.hivemq.com/demos/websocket-client/).
### Como Testar
Acesse o projeto no Wokwi:
https://wokwi.com/projects/432159745510269953
Inicie a simulação clicando em "Start Simulation".

Observe o Serial Monitor para verificar o envio das mensagens MQTT.

Acesse o HiveMQ Web Client: https://www.hivemq.com/demos/websocket-client/

- HiveMQ WebSocket Client

Clique em Connect.

No campo “Subscribe”, digite:

grupo5/reuso

### Exemplo de mensagem publicada:
```json
{"ph": 6.73, "turbidez": 2.48}

