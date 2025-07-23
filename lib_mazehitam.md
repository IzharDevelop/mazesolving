# Dokumentasi Pustaka izhardev.h

Pustaka ini berisi fungsi-fungsi untuk mengontrol robot line follower, termasuk pergerakan motor, pembacaan sensor, dan fungsi-fungsi khusus lainnya.

## Daftar Fungsi

### Fungsi Gerakan Dasar

- [jeda_hitam(int speed)](#jeda_hitam)
- [kotak_hitam(int speed)](#kotak_hitam)
- [baca_hitam(int speedlow, int speedfast)](#baca_hitam)
- [putarkanan_hitam(int speedL, int speedR)](#putarkanan_hitam)
- [putarkiri_hitam(int speedL, int speedR)](#putarkiri_hitam)
- [moveMotors(int leftDirection, int rightDirection, int speedL, int speedR)](#moveMotors)
- [maju(int speed, int duration)](#maju)
- [mundur(int speed, int duration)](#mundur)
- [kanan(int speedL, int speedR, int duration)](#kanan)
- [kiri(int speedL, int speedR, int duration)](#kiri)
- [stop(int duration)](#stop)
- [tahan(int duration)](#tahan)

### Fungsi Suara

- [beep(int pinbuzzer, int ulangi, int frek, int durasi)](#beep)

### Fungsi Lengan Robot

- [arm_ambil(int pinservo, int Angle, int pause)](#arm_ambil)
- [arm_lepas(int pinservo, int Angle, int pause)](#arm_lepas)
- [arm_cek(int pinservo, int Angle, int pause)](#arm_cek)

### Fungsi Kontrol LED

- [signL(int pin1, int pin2)](#signL)
- [signR(int pin1, int pin2)](#signR)
- [signB(int pin1, int pin2)](#signB)
- [signO(int pin1, int pin2)](#signO)
- [LED_ON(int pin3)](#LED_ON)
- [LED_OFF(int pin)](#LED_OFF)

### Fungsi Khusus

- [START()](#START)
- [FINISH()](#FINISH)
- [kananhitam(int speedL, int speedR, int duration)](#kananhitam)
- [kirihitam(int speedL, int speedR, int duration)](#kirihitam)
- [putarkananhitam(int speedL, int speedR)](#putarkananhitam)
- [putarkirihitam(int speedL, int speedR)](#putarkirihitam)
- [kotakhitam(int speedL, int speedR)](#kotakhitam)
- [jedahitam(int speedL, int speedR)](#jedahitam)

---

### <a name="jeda_hitam"></a> `jeda_hitam(int speed)`

Fungsi ini digunakan untuk mengontrol motor berdasarkan pembacaan sensor IR.

- **Parameter:**
  - `speed`: Kecepatan motor.

- **Contoh Penggunaan:**
  ```c
  jeda_hitam(100);
  ```

### <a name="kotak_hitam"></a> `kotak_hitam(int speed)`

Fungsi ini digunakan untuk mengikuti bentuk kotak.

- **Parameter:**
  - `speed`: Kecepatan motor.

- **Contoh Penggunaan:**
  ```c
  kotak_hitam(100);
  ```

### <a name="baca_hitam"></a> `baca_hitam(int speedlow, int speedfast)`

Fungsi ini digunakan untuk membaca sensor IR dan mengontrol pergerakan motor.

- **Parameter:**
  - `speedlow`: Kecepatan motor saat berbelok sedikit.
  - `speedfast`: Kecepatan motor saat bergerak lurus atau berbelok tajam.

- **Contoh Penggunaan:**
  ```c
  baca_hitam(50, 100);
  ```

### <a name="putarkanan_hitam"></a> `putarkanan_hitam(int speedL, int speedR)`

Fungsi ini digunakan untuk memutar ke kanan hingga sensor tengah mendeteksi garis.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  putarkanan_hitam(100, 100);
  ```

### <a name="putarkiri_hitam"></a> `putarkiri_hitam(int speedL, int speedR)`

Fungsi ini digunakan untuk memutar ke kiri hingga sensor tengah mendeteksi garis.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  putarkiri_hitam(100, 100);
  ```

### <a name="moveMotors"></a> `moveMotors(int leftDirection, int rightDirection, int speedL, int speedR)`

Fungsi ini digunakan untuk mengontrol pergerakan motor.

- **Parameter:**
  - `leftDirection`: Arah motor kiri.
  - `rightDirection`: Arah motor kanan.
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  moveMotors(FORWARD_DIRECTION, FORWARD_DIRECTION, 100, 100);
  ```

### <a name="maju"></a> `maju(int speed, int duration)`

Fungsi ini digunakan untuk bergerak maju selama durasi tertentu.

- **Parameter:**
  - `speed`: Kecepatan motor.
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  maju(100, 1000); // Bergerak maju dengan kecepatan 100 selama 1 detik
  ```

### <a name="mundur"></a> `mundur(int speed, int duration)`

Fungsi ini digunakan untuk bergerak mundur selama durasi tertentu.

- **Parameter:**
  - `speed`: Kecepatan motor.
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  mundur(100, 1000); // Bergerak mundur dengan kecepatan 100 selama 1 detik
  ```

### <a name="kanan"></a> `kanan(int speedL, int speedR, int duration)`

Fungsi ini digunakan untuk berbelok ke kanan selama durasi tertentu.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  kanan(100, 100, 500); // Berbelok ke kanan selama 0.5 detik
  ```

### <a name="kiri"></a> `kiri(int speedL, int speedR, int duration)`

Fungsi ini digunakan untuk berbelok ke kiri selama durasi tertentu.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  kiri(100, 100, 500); // Berbelok ke kiri selama 0.5 detik
  ```

### <a name="stop"></a> `stop(int duration)`

Fungsi ini digunakan untuk menghentikan motor selama durasi tertentu.

- **Parameter:**
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  stop(1000); // Berhenti selama 1 detik
  ```

### <a name="tahan"></a> `tahan(int duration)`

Fungsi ini digunakan untuk menunda program selama durasi tertentu.

- **Parameter:**
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  tahan(1000); // Menunda program selama 1 detik
  ```

### <a name="beep"></a> `beep(int pinbuzzer, int ulangi, int frek, int durasi)`

Fungsi ini digunakan untuk menghasilkan suara dari buzzer.

- **Parameter:**
  - `pinbuzzer`: Pin buzzer.
  - `ulangi`: Jumlah pengulangan.
  - `frek`: Frekuensi suara.
  - `durasi`: Durasi suara.

- **Contoh Penggunaan:**
  ```c
  beep(4, 2, 1500, 50); // Menghasilkan suara dengan frekuensi 1500Hz selama 50ms sebanyak 2 kali
  ```

### <a name="arm_ambil"></a> `arm_ambil(int pinservo, int Angle, int pause)`

Fungsi ini digunakan untuk menggerakkan lengan robot untuk mengambil objek.

- **Parameter:**
  - `pinservo`: Pin servo.
  - `Angle`: Sudut servo.
  - `pause`: Jeda setelah gerakan.

- **Contoh Penggunaan:**
  ```c
  arm_ambil(5, 90, 500); // Menggerakkan servo di pin 5 ke sudut 90 derajat dan jeda 500ms
  ```

### <a name="arm_lepas"></a> `arm_lepas(int pinservo, int Angle, int pause)`

Fungsi ini digunakan untuk menggerakkan lengan robot untuk melepaskan objek.

- **Parameter:**
  - `pinservo`: Pin servo.
  - `Angle`: Sudut servo.
  - `pause`: Jeda setelah gerakan.

- **Contoh Penggunaan:**
  ```c
  arm_lepas(5, 0, 500); // Menggerakkan servo di pin 5 ke sudut 0 derajat dan jeda 500ms
  ```

### <a name="arm_cek"></a> `arm_cek(int pinservo, int Angle, int pause)`

Fungsi ini digunakan untuk melakukan pengecekan pada lengan robot.

- **Parameter:**
  - `pinservo`: Pin servo.
  - `Angle`: Sudut servo.
  - `pause`: Jeda setelah gerakan.

- **Contoh Penggunaan:**
  ```c
  arm_cek(5, 45, 500);
  ```

### <a name="signL"></a> `signL(int pin1, int pin2)`

Fungsi ini digunakan untuk menyalakan LED penanda belok kiri.

- **Parameter:**
  - `pin1`: Pin LED kiri.
  - `pin2`: Pin LED kanan.

- **Contoh Penggunaan:**
  ```c
  signL(1, 2);
  ```

### <a name="signR"></a> `signR(int pin1, int pin2)`

Fungsi ini digunakan untuk menyalakan LED penanda belok kanan.

- **Parameter:**
  - `pin1`: Pin LED kiri.
  - `pin2`: Pin LED kanan.

- **Contoh Penggunaan:**
  ```c
  signR(1, 2);
  ```

### <a name="signB"></a> `signB(int pin1, int pin2)`

Fungsi ini digunakan untuk menyalakan kedua LED.

- **Parameter:**
  - `pin1`: Pin LED kiri.
  - `pin2`: Pin LED kanan.

- **Contoh Penggunaan:**
  ```c
  signB(1, 2);
  ```

### <a name="signO"></a> `signO(int pin1, int pin2)`

Fungsi ini digunakan untuk mematikan kedua LED.

- **Parameter:**
  - `pin1`: Pin LED kiri.
  - `pin2`: Pin LED kanan.

- **Contoh Penggunaan:**
  ```c
  signO(1, 2);
  ```

### <a name="LED_ON"></a> `LED_ON(int pin3)`

Fungsi ini digunakan untuk menyalakan LED.

- **Parameter:**
  - `pin3`: Pin LED.

- **Contoh Penggunaan:**
  ```c
  LED_ON(3);
  ```

### <a name="LED_OFF"></a> `LED_OFF(int pin)`

Fungsi ini digunakan untuk mematikan LED.

- **Parameter:**
  - `pin`: Pin LED.

- **Contoh Penggunaan:**
  ```c
  LED_OFF(3);
  ```

### <a name="START"></a> `START()`

Fungsi ini digunakan untuk memulai program.

- **Contoh Penggunaan:**
  ```c
  START();
  ```

### <a name="FINISH"></a> `FINISH()`

Fungsi ini digunakan untuk mengakhiri program.

- **Contoh Penggunaan:**
  ```c
  FINISH();
  ```

### <a name="kananhitam"></a> `kananhitam(int speedL, int speedR, int duration)`

Fungsi ini menggabungkan `baca_hitam` dan `kanan` dengan penanda LED.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  kananhitam(100, 100, 500);
  ```

### <a name="kirihitam"></a> `kirihitam(int speedL, int speedR, int duration)`

Fungsi ini menggabungkan `baca_hitam` dan `kiri` dengan penanda LED.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.
  - `duration`: Durasi dalam milidetik.

- **Contoh Penggunaan:**
  ```c
  kirihitam(100, 100, 500);
  ```

### <a name="putarkananhitam"></a> `putarkananhitam(int speedL, int speedR)`

Fungsi ini menggabungkan `baca_hitam` dan `putarkanan_hitam` dengan penanda LED.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  putarkananhitam(100, 100);
  ```

### <a name="putarkirihitam"></a> `putarkirihitam(int speedL, int speedR)`

Fungsi ini menggabungkan `baca_hitam` dan `putarkiri_hitam` dengan penanda LED.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  putarkirihitam(100, 100);
  ```

### <a name="kotakhitam"></a> `kotakhitam(int speedL, int speedR)`

Fungsi ini menggabungkan `baca_hitam` dan `kotak_hitam` dengan suara beep.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  kotakhitam(100, 100);
  ```

### <a name="jedahitam"></a> `jedahitam(int speedL, int speedR)`

Fungsi ini menggabungkan `baca_hitam` dan `jeda_hitam` dengan suara beep.

- **Parameter:**
  - `speedL`: Kecepatan motor kiri.
  - `speedR`: Kecepatan motor kanan.

- **Contoh Penggunaan:**
  ```c
  jedahitam(100, 100);
  ```
