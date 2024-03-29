#define MAJOR 1
#define MINOR 3
#define REVISION 2
#define botao_esquerdo 4
#define botao_direito 2
#define botao_meio 3
#define PIN_TONE 11

/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define BOLAS 7 // total de bolas em um jogo

#include <EEPROM.h>

int paredao = 0;
int pts_paredao = 0;
int circulo = 0;
int bola = 0;
int parcial[BOLAS];
int total = 0;
int total_paredao = 0;
int total_circulo = 0;

void setup() {
    pinMode(botao_esquerdo, INPUT_PULLUP);
    pinMode(botao_direito, INPUT_PULLUP);
    pinMode(botao_meio, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    // RESTART
    Serial.println("-------------------------------------------------");
    //Serial.println("           Bem vindo ao");
    Serial.println("  ...::: PAREDAO DO ALEMÃO :::... ");
    Serial.print("          (Versao ");
    Serial.print(MAJOR);
    Serial.print(".");
    Serial.print(MINOR);
    Serial.print(".");
    Serial.print(REVISION);
    Serial.println(")");
    Serial.println("-------------------------------------------------");
    Serial.println();

    while (bola < BOLAS) {
        //detectar quando o botão esquerdo for pressionado
        if (!digitalRead(botao_esquerdo)) {  
            paredao++;
            Serial.println(paredao);
            delay(300);
            continue;
        }
        
        //detectar quando o botão direito for pressionado
        if (!digitalRead(botao_direito)) {  
            paredao++;
            circulo++;
            Serial.print(paredao);
            Serial.println(" (+ bonus)");
            delay(300);
            continue;
        }

        //detectar quando o botão central for pressionado
        //Queda de bola
        if (!digitalRead(botao_meio)) {  
            bola++;
            delay(300);
            tone(PIN_TONE, NOTE_C4, 100);
            delay(110);
            tone(PIN_TONE, NOTE_C3, 100);
            delay(110);
            tone(PIN_TONE, NOTE_C2, 300);
            delay(310);

            //PLACAR
            Serial.println("-------------------------------------------------");
            Serial.print("- BOLA ");
            Serial.println(bola);
            Serial.println("-------------------------------------------------");

            //mostra acertos no paredão
            Serial.print("Acertos no paredao: ");
            Serial.println(paredao);

            //mostra acertos no círculo
            Serial.print("Acertos no círculo: ");l
            Serial.println(circulo);

            //mostra pontos paredão
            pts_paredao = int(paredao/10);
            Serial.print("Pontos paredão: ");
            Serial.println(pts_paredao);

            //mostra pontos no círculo
            Serial.print("Pontos círculo: ");
            Serial.println(circulo);

            //mostra pontuação obtida nessa bola
            parcial[bola] = pts_paredao + circulo;
            total += parcial[bola];
            total_paredao += paredao;
            total_circulo += circulo;
            Serial.print("Pontuacao obtida nesta bola: ");
            Serial.println(parcial[bola]);
            Serial.print("TOTAL PARCIAL DE PONTOS: ");
            Serial.println(total);
            Serial.println("-------------------------------------------------");
            
            //Guarda placar por bola
            if (bola=1) {
                   paredao1=paredao
                   circulo1=circulo
                   pts_paredao1=pts_paredao
              }
             else if (bola=2) {
                   paredao2=paredao
                   circulo2=circulo
                   pts_paredao2=pts_paredao
              else if (bola=3) então 
                   paredao3=paredao
                   circulo3=circulo
                   pts_paredao3=pts_paredao
               }
              else if (bola=4) {
                   paredao4=paredao
                   circulo4=circulo
                   pts_paredao4=pts_paredao 
               } 
              else if (bola=5) {
                   paredao5=paredao
                   circulo5=circulo
                   pts_paredao5=pts_paredao  
              }                 
             else if (bola=6) {
                   paredao6=paredao
                   circulo6=circulo
                   pts_paredao6=pts_paredao
              }
             else if (bola=7) {
                   paredao7=paredao
                   circulo7=circulo
                   pts_paredao7=pts_paredao
              }
         
            //Zera placar
            paredao = 0;
            circulo = 0;
            pts_paredao = 0;
        }
            //teste

    }

    //mostra pontuação total
    Serial.println("-------------------------------------------------");
    Serial.println("              --== FIM DO JOGO ==--");
    Serial.println("-------------------------------------------------");
    
    //Imprime relatorio sequencias
    Serial.println("SEQUÊNCIA 1");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao1);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao1);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo1);
    Serial.println("SEQUÊNCIA 2");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao2);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao2);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo2);
    Serial.println("SEQUÊNCIA 3");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao3);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao3);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo3);
    Serial.println("SEQUÊNCIA 4");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao4);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao4);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo4);
    Serial.println("SEQUÊNCIA 5");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao5);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao5);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo5);
    Serial.println("SEQUÊNCIA 6");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao6);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao6);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo6);
    Serial.println("SEQUÊNCIA 7");
    Serial.print("Acertos paredao: ");
    Serial.print(paredao7);
    Serial.print("Pts Paredao: ");
    Serial.println(pts_paredao7);
    Serial.print("Pts Circulo: ");
    Serial.println(circulo7);
    Serial.println("-------------------------------------------------");
    Serial.print("TOTAL DE PONTOS: ");
    Serial.println(total);
    //Serial.print("Total de acertos no paredao: ");
    //Serial.println(total_paredao);
    //Serial.print("Total de acertos no circulo: ");
    //Serial.println(total_circulo);

    paredao = 0;
    pts_paredao = 0;
    circulo = 0;
    bola = 0;
    total = 0;
    total_paredao = 0;
    total_circulo = 0;
}
