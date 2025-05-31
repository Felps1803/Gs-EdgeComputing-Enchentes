# Gs-EdgeComputing-Enchentes
# 🌊Sistema Edge para Monitoramento de Enchentes

## Descrição do Problema

As enchentes urbanas causam bilhões em prejuízos anualmente no Brasil. O principal problema é a falta de dados locais em tempo real para alertas preventivos. Sistemas atuais dependem de informações meteorológicas genéricas que não refletem condições específicas de cada bairro.
Moradores precisam de informações precisas sobre:

Nível da água em pontos críticos
Intensidade de chuva local
Condições de vento que afetam drenagem
Alertas preventivos personalizados por localização

## Visão Geral da Solução

Sistema de **sensores edge distribuídos** que coletam dados ambientais em tempo real para alimentar relatórios personalizados de risco de enchente.

### Arquitetura
```
[Sensores Edge] → [Processamento Local] → [Dados para Sistema Central] → [Relatórios por Email]
```

### Componentes Edge
- **Sensor Ultrassônico**: Mede nível da água (0-50cm)
- **Sensor de Chuva**: Detecta intensidade de precipitação
- **Sensor de Vento**: Monitora velocidade do vento
- **Sistema de Alertas**: LEDs (verde/amarelo/vermelho) + buzzer
- **Display LCD**: Mostra status local em tempo real

### Classificação Automática de Risco
- **Verde** (< 20cm): Seguro
- **Amarelo** (20-30cm): Atenção  
- **Vermelho** (> 30cm): Risco crítico + buzzer

## Instruções para Execução e Simulação

### Execução
1. Acesse o projeto no Wokwi
2. Clique em "Start Simulation"
3. Observe os dados em tempo real no display LCD

### Simulação de Cenários
- **Cenário Normal**: Sensor a 15cm → LED verde
- **Cenário Atenção**: Sensor a 25cm → LED amarelo  
- **Cenário Crítico**: Sensor a 35cm → LED vermelho + buzzer

### Dados Coletados
Sistema envia dados JSON com: nível da água, chuva, vento e classificação de risco.

## Link para o projeto

