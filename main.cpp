#include <iostream>
#include <climits> // INT_MAX ve INT_MIN gibi sabitleri kullanabilmek için
using namespace std;
int main()
{
  //*
  /*
  int a = 10;
  /// += operatörü: 'a' değişkeninin mevcut değerine 5 ekler ve sonucu 'a'ya atar.
  a += 5;  // a = a + 5;  Sonuç: a = 15

  /// -= operatörü: 'a' değişkeninden 3 çıkarır ve sonucu 'a'ya atar.
  a -= 3;  // a = a - 3;  Sonuç: a = 12

  ///- *= operatörü: 'a' değişkenini 2 ile çarpar ve sonucu 'a'ya atar.
  a *= 2;  // a = a * 2;  Sonuç: a = 24

  /// /= operatörü: 'a' değişkenini 4'e böler ve sonucu 'a'ya atar.
  a /= 4;  // a = a / 4;  Sonuç: a = 6

  /// %= operatörü: 'a' değişkeninin 5 ile bölümünden kalanı bulur ve sonucu 'a'ya atar.
  a %= 5;  // a = a % 5;  Sonuç: a = 1

  cout << "Son değer: " << a << endl; // Çıktı: Son değer: 1
  */
  //*
  /*
  int a = 5, b = 5;
  /// Prefix Increment
  int x = ++a; // a önce artırılır (6 olur), sonra x'e atanır. x = 6

  /// Postfix Increment
  int y = b++; // b önce y'ye atanır (y = 5), sonra artırılır (b = 6)

  cout << "Prefix (++a): a = " << a << ", x = " << x << endl;
  cout << "Postfix (b++): b = " << b << ", y = " << y << endl;

  /// Prefix Decrement
  int p = --a; // a önce azaltılır (5 olur), sonra p'ye atanır. p = 5

  /// Postfix Decrement
  int q = b--; // b önce q'ya atanır (q = 6), sonra azaltılır (b = 5)

  cout << "Prefix (--a): a = " << a << ", p = " << p << endl;
  cout << "Postfix (b--): b = " << b << ", q = " << q << endl;

  int x = 5, y = 3, z;

  /// Prefix Increment
  z = ++x * y;
  /// x önce artırılır (x = 6), sonra çarpma işlemi yapılır: 6 * 3 = 18
  cout << "Prefix (++x * y): x = " << x << ", z = " << z << endl;

  /// Sıfırlama
  x = 5;

  /// Postfix Increment
  z = x++ * y;
  /// Önce çarpma işlemi yapılır: 5 * 3 = 15, sonra x artırılır (x = 6)
  cout << "Postfix (x++ * y): x = " << x << ", z = " << z << endl;
  int i = 1, j;

  /// TANIMSIZ DAVRANIŞA SEBEP OLABİLECEK KOD (undefined behavior - UB)
  j = 2 * ++i + 2 + i++;
  /// 1. ++i: i önce artırılır (1 → 2 → 3 olur).
  /// 2. 2 * ++i: 2 * 3 = 6 hesaplanır.
  /// 3. 6 + 2: 8 olur.
  /// 4. i++: i önce işlemde kullanılır (3), sonra artırılır (3 → 4).
  /// 5. 8 + 3: 11 olur.
  /// Sonuç: j = 11, i = 4 (Ancak bu kod tanımsız davranış içerebilir!)

  cout << "Tanımsız davranış içeren kod: j: " << j << " i: " << i << endl;

  /// DAHA GÜVENLİ VE OKUNAKLI KOD
  i = 1;  // i'yi tekrar başlangıç değerine alalım
  ++i;  // Önce i'yi artır (i = 2 → 3 olur)
  j = 2 * i + 2;  // İlk işlemi hesapla: (2 * 3) + 2 = 6 + 2 = 8
  j += i;  // Son olarak i'yi ekleyelim: 8 + 3 = 11
  i++;  // En son i'yi artır (i = 4 olur)

  cout << "Güvenli ve okunaklı kod: j: " << j << " i: " << i << endl;
  */
  //*
  /*
  ///- **Integer Overflow (Tam Sayı Taşması) Örneği:**
  int x = 2147483647;  // int veri türü için maksimum değer (2^31 - 1)
  cout << "x: " << x << endl;  // x değeri, 2147483647 olmalı

  /// Overflow durumunu tetikleme
  x = x + 1;  // x + 1 işlemi int türünün kapasitesini aşacak ve taşmaya neden olacak
  cout << "x + 1 (Overflow): " << x << endl;  // Bu durumda x değeri negatif olacaktır (-2147483648)

  ///- **Floating-Point Overflow (Ondalıklı Sayı Taşması) Örneği:**
  double y = 1.7e308;  // double veri türü için çok büyük bir değer (yaklaşık 1.7 * 10^308)
  cout << "y: " << y << endl;  // y değeri 1.7e308 olmalı

  /// Overflow durumunu tetikleme
  y = y * 10;  // Bu işlem, double türünün kapasitesini aşacak ve "sonsuz" (infinity) değerini döndürecek
  cout << "y * 10 (Overflow): " << y << endl;  // Bu durumda y değeri "inf" (sonsuz) olur

  ///- **Overflow Kontrolü (Önceden Kontrol Etme) Örneği:**
  int z = 2147483647;  // INT_MAX, int türünün maksimum değeri (2147483647)

  /// Değerin overflow yapıp yapmadığını kontrol etme
  if (z > INT_MAX - 1) {  // INT_MAX - 1'e kadar olan değerler overflow yapmaz
      cout << "Overflow olacak!" << endl;  // Bu koşul true olacak, çünkü z'nin değeri INT_MAX'a çok yakın
  } else {
      z = z + 1;  // Overflow durumunda işlem yapılmaz
      cout << "Yeni z: " << z << endl;  // Buraya hiç gelinmez, çünkü overflow kontrolü sağlandı
  }

  ///- **Veri Türü Değişikliği ile Overflow Önleme Örneği:**
  long long int w = 9223372036854775807;  // long long int veri türü için maksimum değer (2^63 - 1)
  cout << "w: " << w << endl;  // w değeri 9223372036854775807 olmalı

  /// overflow durumunu tetikleme
  w = w + 1;  // long long int türü kapasitesini aştığında taşma olacak
  cout << "w + 1 (Overflow): " << w << endl;  // Bu durumda w değeri negatif olacaktır (-9223372036854775808)

  /// Overflow'dan kaçınmak için daha geniş bir tür kullanabiliriz (long long int)
  /// signed char 8 bitlik veri türüdür ve -128 ile 127 arasında değer alabilir.
  signed char a = 127;  // 127, signed char'ın alabileceği en büyük değeri

  /// Bu işlemde overflow (taşma) meydana gelir, çünkü 127'yi bir artırınca -128'e dönecektir.
  a = a + 1;  // 127 + 1 = 128, fakat signed char'ın sınırları -128 ile 127 arasında olduğu için taşma olur.

  cout << "a: " << (int)a << endl;  // Burada -128 yazacaktır, çünkü overflow oldu.
  */
  //*
  /*
  /// Signed char 8 bitlik bir veri türüdür, bu yüzden -128 ile 127 arasında değerler alabilir.
  /// İki'li Tamamlama (Two's Complement) yöntemi kullanılarak negatif sayılar temsil edilir.

  signed char a = 127;   // En büyük pozitif değer
  signed char b = -128;  // En küçük negatif değer
  signed char c = -127;  // -128'den bir önceki negatif değer

  cout << "a: " << (int)a << endl;  // 127, bu en büyük pozitif değerdir
  cout << "b: " << (int)b << endl;  // -128, signed char ile temsil edilebilen en küçük negatif değerdir
  cout << "c: " << (int)c << endl;  // -127, -128'den bir sonraki değerdir
  */
  return 0;
}