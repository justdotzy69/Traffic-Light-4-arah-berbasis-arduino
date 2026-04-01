/* * Pengaturan Pin: [0]=Merah, [1]=Kuning, [2]=Hijau
 */

int utara[]   = {2, 3, 4}; 
int barat[]   = {11, 12, 13};  
int selatan[] = {8, 9, 10};    
int timur[]   = {5, 6, 7};    

void setup() {
  // Setting pin 2-13 sebagai output
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// Fungsi agar semua lampu merah menyala (stop semua)
void semuaMerah() {
  digitalWrite(utara[0], HIGH);
  digitalWrite(timur[0], HIGH);
  digitalWrite(barat[0], HIGH);
  digitalWrite(selatan[0], HIGH);
}

void aktifkanSimpang(int pin[]) {
  semuaMerah(); // Reset semua ke merah
  delay(1000);
  
  // Hijau menyala 5 detik
  digitalWrite(pin[0], LOW);  // Merah off
  digitalWrite(pin[2], HIGH); // Hijau on
  delay(5000);

  // Hijau mati, Kuning kedip 3x
  digitalWrite(pin[2], LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(pin[1], HIGH); delay(300);
    digitalWrite(pin[1], LOW);  delay(300);
  }

  // Kembali ke Merah
  digitalWrite(pin[0], HIGH);
}

void loop() {
  // Jalankan urutan simpang secara bergantian
  aktifkanSimpang(utara);
  aktifkanSimpang(timur);
  aktifkanSimpang(selatan);
  aktifkanSimpang(barat);
}