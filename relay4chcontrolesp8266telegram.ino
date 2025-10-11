//code ini dibuat secara manual oleh shello ardiansyah XI TJKT (github.com/AkazawaKazairo)
//script ini tidak diperjualbelikan dan siapa saja boleh menggunakan dan recode script ini
//laporkan kepada saya jika ada yang memperjualbelikan script ini! (wa: 08511732330)

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Ganti dengan WiFi yang akan digunakan
const char* ssid = "Ardi Setengah Matang";
const char* password = "1029384756";

// Token bot Telegram dari BotFather
const char* botToken = "8423776848:AAEHTjZn0WsFi2b5HZG13fGHXuKbJwWQ_O";

// Password untuk akses kontrol yang akan diminta oleh bot
const String aksesPassword = "Pak Fandi";

// Relay pin
#define relay1 D1
#define relay2 D2
#define relay3 D5
#define relay4 D6

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

unsigned long lastTimeBotRan = 0;
bool aksesAktif = false;
bool tungguPassword = false;
long userChatID = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  client.setInsecure(); // biar gak perlu sertifikat SSL

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menghubungkan WiFi...");
  }
  Serial.println("WiFi terhubung!");

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop() {
  if (millis() - lastTimeBotRan > 1000) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      for (int i = 0; i < numNewMessages; i++) {
        String status = bot.messages[i].text;
        long chat_id = bot.messages[i].chat_id;

        if (status == "/start") {
          bot.sendMessage(chat_id, "Halo! Kirim password untuk akses kontrol:", "");
          tungguPassword = true;
          userChatID = chat_id;
        }

        else if (tungguPassword && chat_id == userChatID) {
          if (status == aksesPassword) {
            aksesAktif = true;
            tungguPassword = false;
            bot.sendMessage(chat_id, "✅ Akses relay aktif!", "");
          } else {
            bot.sendMessage(chat_id, "❌ Password salah! Kirim /start untuk coba lagi.", "");
            tungguPassword = false;
          }
        }

        else if (aksesAktif && chat_id == userChatID) {
          if (status == "/relay1on") {
            digitalWrite(relay1, LOW);
            bot.sendMessage(chat_id, "Relay 1 ON", "");
          } else if (status == "/relay1off") {
            digitalWrite(relay1, HIGH);
            bot.sendMessage(chat_id, "Relay 1 OFF", "");
          } else if (status == "/relay2on") {
            digitalWrite(relay2, LOW);
            bot.sendMessage(chat_id, "Relay 2 ON", "");
          } else if (status == "/relay2off") {
            digitalWrite(relay2, HIGH);
            bot.sendMessage(chat_id, "Relay 2 OFF", "");
          } else if (status == "/relay3on") {
            digitalWrite(relay3, LOW);
            bot.sendMessage(chat_id, "Relay 3 ON", "");
          } else if (status == "/relay3off") {
            digitalWrite(relay3, HIGH);
            bot.sendMessage(chat_id, "Relay 3 OFF", "");
          } else if (status == "/relay4on") {
            digitalWrite(relay4, LOW);
            bot.sendMessage(chat_id, "Relay 4 ON", "");
          } else if (status == "/relay4off") {
            digitalWrite(relay4, HIGH);
            bot.sendMessage(chat_id, "Relay 4 OFF", "");
          } else if (status == "/status") {
            String kondisi = "Status Relay:\n";
            kondisi += "Relay 1: " + String(digitalRead(relay1) == LOW ? "ON" : "OFF") + "\n";
            kondisi += "Relay 2: " + String(digitalRead(relay2) == LOW ? "ON" : "OFF") + "\n";
            kondisi += "Relay 3: " + String(digitalRead(relay3) == LOW ? "ON" : "OFF") + "\n";
            kondisi += "Relay 4: " + String(digitalRead(relay4) == LOW ? "ON" : "OFF");
            bot.sendMessage(chat_id, kondisi, "");
          }
        }
      }
      lastTimeBotRan = millis();
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
  }
}
