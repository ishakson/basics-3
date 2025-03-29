#include <iostream>
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

  return 0;
}