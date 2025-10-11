# PROJECT SAKLAR OTOMATIS VIA APLIKASI TELEGRAM MENGGUNAKAN RELAY 4CH DAN ESP8266V3
# note: masih beta dan belum teruji
project ini adalah project sekolah saya, dan project ini bisa diaplikasikan di mana saja bukan hanya sekedar lampu.

big thanks to:
- Allah SWT
- pak fandy mahesa (guru mapel IOT)
- Sekolah Multistudi High School
- dan kawan kawan IOT sekelompok 3

Script ini dibuat oleh [Ardi](https://wa.me/6285117732330). Jika terjadi error bahkan setelah compile/verify, silakan hubungi saya untuk mendapatkan bantuan. ~ By Ardii
---
####  perintah bot telegram hingga ke relay
| perintah | fungsi |
|--------|--------|
| /start | Memulai sesi dan minta password |
| /relay1on | menyalakan relay 1 |
| /relay1off | mematikan relay 1 |
| /relay2on | menyalakan relay 2 |
| /relay2off | mematikan relay 2 |
| /relay3on | menyalakan relay 3 |
| /relay3off | mematikan relay 3 |
| /relay4on | menyalakan relay 4 |
| /relay4off | mematikan relay 4 |
| /status | Menampilkan status semua relay |
---
alat dan bahan:
- nodemcu esp8266 v3 
- relay 4ch
- jumper cable ftf 6 buah
- kabel micro/type-c (sesuaikan dengan nodemcu)

---
library yang digunakan:
- ESP8266
- UniversalTelegramBot
---
#### skema wiring dari relay ke esp8266
| relay | esp8266 |
|--------|--------|
| gnd | g |
| vcc | vin/3v |
| in1 | d1 |
| in2 | d2 |
| in3 | d5 |
| in4 | d6 |
---
### terima kasih sudah membaca hingga akhir~
