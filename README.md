Zephyr LoRaWAN Sensör

Bu proje, Zephyr RTOS kullanılarak geliştirilmiş, QEMU tabanlı ve RF donanımı içermeyen bir LoRaWAN sensör uygulamasıdır.

## Proje Kapsamı
- Hedef: LoRaWAN Class A sensör düğümü
- Bölge: EU868
- LoRaWAN Versiyonu: 1.0.3
- Ortam: QEMU (RF donanımı yok)

## Gerçekleştirilen Özellikler
- LoRaWAN yapılandırma soyutlaması
- Periyodik sensör verisi üretimi (sıcaklık ve nem – mock)
- Payload formatlama
- HMAC-SHA256 ile payload imzalama
- Test amaçlı RF-less gönderim simülasyonu

## Payload Formatı
- T:<sıcaklık>,H:<nem>#<HMAC_SHA256>
