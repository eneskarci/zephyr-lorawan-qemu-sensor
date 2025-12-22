Zephyr LoRaWAN Sensör

Bu proje, Zephyr RTOS kullanılarak geliştirilen, QEMU tabanlı ve RF donanımı içermeyen bir LoRaWAN sensör uygulaması iskeletidir.

Proje Kapsamı

Hedef: LoRaWAN Class A sensör düğümü

Bölge: EU868

LoRaWAN Versiyonu: 1.0.3

Ortam: QEMU (RF donanımı yok)

Gerçekleştirilen Özellikler

LoRaWAN yapılandırma soyutlaması

Periyodik sensör verisi üretimi (sıcaklık ve nem – mock)

Payload formatlama

HMAC-SHA256 ile payload imzalama

Test amaçlı RF-less gönderim simülasyonu (send stub)

Payload Formatı

T:<sıcaklık>,H:<nem>#<HMAC_SHA256>

Derleme ve Çalıştırma

Proje, Zephyr’in west tabanlı derleme sistemi kullanılarak QEMU hedefi için derlenir

Uygulama QEMU ortamında çalıştırılır

Notlar

Bu proje gerçek RF iletim yapmaz

LoRaWAN uygulama katmanının donanımdan bağımsız olarak geliştirilmesi ve test edilmesi amaçlanmıştır
