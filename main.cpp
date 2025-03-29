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
  signed char x = 130;  // 130 signed char'ın alabileceği en büyük değeri aştığı için overflow olur
  cout << "x: " << (int)x << endl;  // Sonuç: -126, çünkü taşma sonucu negatif değeri temsil eder

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
  //*
  /*
  /// INT_MAX: signed int veri türünün alabileceği en büyük değeri gösterir.
  /// Genellikle 32-bit sistemlerde 2147483647'dir.
  cout << "INT_MAX: " << INT_MAX << endl;

  /// INT_MIN: signed int veri türünün alabileceği en küçük değeri gösterir.
  /// Genellikle 32-bit sistemlerde -2147483648'dir.
  cout << "INT_MIN: " << INT_MIN << endl;

  /// LONG_MAX: signed long veri türünün alabileceği en büyük değeri gösterir.
  /// Genellikle 32-bit sistemlerde 2147483647, 64-bit sistemlerde 9223372036854775807'dir.
  cout << "LONG_MAX: " << LONG_MAX << endl;

  /// LONG_MIN: signed long veri türünün alabileceği en küçük değeri gösterir.
  /// Genellikle 32-bit sistemlerde -2147483648, 64-bit sistemlerde -9223372036854775808'dir.
  cout << "LONG_MIN: " << LONG_MIN << endl;

  /// CHAR_MAX: signed char veri türünün alabileceği en büyük değeri gösterir.
  /// signed char için genellikle 127'dir, unsigned char için ise 255'tir.
  cout << "CHAR_MAX: " << CHAR_MAX << endl;

  /// CHAR_MIN: signed char veri türünün alabileceği en küçük değeri gösterir.
  /// signed char için genellikle -128'dir.
  cout << "CHAR_MIN: " << CHAR_MIN << endl;

  /// USHRT_MAX: unsigned short veri türünün alabileceği en büyük değeri gösterir.
  /// unsigned short için genellikle 65535'tir.
  cout << "USHRT_MAX: " << USHRT_MAX << endl;

  /// USHRT_MIN: unsigned short veri türünün alabileceği en küçük değeri gösterir.
  /// unsigned short için minimum değer her zaman 0'dır.
  cout << "USHRT_MIN: " << USHRT_MIN << endl;

  /// UINT_MAX: unsigned int veri türünün alabileceği en büyük değeri gösterir.
  /// Genellikle 32-bit sistemlerde 4294967295'dir.
  cout << "UINT_MAX: " << UINT_MAX << endl;

  /// UINT_MIN: unsigned int veri türünün alabileceği en küçük değeri gösterir.
  /// unsigned int için minimum değer her zaman 0'dır.
  cout << "UINT_MIN: " << UINT_MIN << endl;

  /// LLONG_MAX: signed long long veri türünün alabileceği en büyük değeri gösterir.
  /// Genellikle 64-bit sistemlerde 9223372036854775807'dir.
  cout << "LLONG_MAX: " << LLONG_MAX << endl;

  /// LLONG_MIN: signed long long veri türünün alabileceği en küçük değeri gösterir.
  /// Genellikle 64-bit sistemlerde -9223372036854775808'dir.
  cout << "LLONG_MIN: " << LLONG_MIN << endl;

  /// UCHAR_MAX: unsigned char veri türünün alabileceği en büyük değeri gösterir.
  /// unsigned char için genellikle 255'tir.
  cout << "UCHAR_MAX: " << UCHAR_MAX << endl;
  */
  //*
  /*
  /// -----------------------------------
  /// 1. Implicit Type Conversion (Otomatik Dönüşüm)
  /// Derleyici, türler arasında veri kaybı olmadan dönüşüm yapar.
  double d = 9.99;   // double türünde bir değişken
  int i = d;         // Otomatik olarak double'dan int'e dönüşüm (decimal kısmı kaybolur)
  cout << "Implicit Conversion (double to int): " << i << endl;

  /// -----------------------------------
  /// 2. Explicit Type Conversion (Açık Dönüşüm)
  /// Tür dönüşümünü açıkça belirtmek için (type) veya static_cast<> kullanılır.
  double d2 = 3.14;
  int i2 = (int)d2;   // (int) kullanarak açık dönüşüm yapılır (decimal kısmı kaybolur)
  cout << "Explicit Conversion (double to int): " << i2 << endl;

  /// -----------------------------------
  /// 3. static_cast (Statik Dönüşüm)
  /// Daha güvenli ve anlamlı dönüşümler için kullanılır.
  float f = 12.75f;
  int i3 = static_cast<int>(f);  // static_cast ile açık dönüşüm (decimal kısmı kaybolur)
  cout << "static_cast (float to int): " << i3 << endl;

  /// -----------------------------------
  /// 4. dynamic_cast (Dinamik Dönüşüm)
  /// Polimorfizmde sınıflar arasında güvenli dönüşüm sağlar.
  class Base { virtual void foo() {} };
  class Derived : public Base {}; // Derived, Base sınıfından türemektedir.

  Base* basePtr = new Derived;
  Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Base* türünden Derived* türüne dönüşüm
  if (derivedPtr) {
      cout << "dynamic_cast successful!" << endl; // Eğer dönüşüm başarılıysa mesaj yazdırılır
  } else {
      cout << "dynamic_cast failed!" << endl;
  }

  /// -----------------------------------
  /// 5. const_cast (const Verileri Değiştirme)
  /// Sabit (const) olan verileri değiştirmek için kullanılır.
  const int x = 10;
  int* ptr = const_cast<int*>(&x);  // const_cast ile sabit değeri değiştirebiliriz (ancak bu iyi bir uygulama değildir)
  ///-*ptr = 20;  // Sabit değeri değiştirmek tehlikeli olabilir.
  cout << "const_cast: " << *ptr << endl; // Ancak bu tür dönüşümlerin yan etkileri olabilir.

  /// -----------------------------------
  /// 6. reinterpret_cast (Belirli Türlerin Bellekteki Temsilini Yeniden Yorumlama)
  /// Daha tehlikeli bir dönüşümdür ve bellek adreslerini manipüle etmek için kullanılır.
  long l = 65;
  char* c = reinterpret_cast<char*>(&l);  // long'u char*'a dönüştürme
  cout << "reinterpret_cast: " << *c << endl;  // Bellekteki veriyi karakter olarak okur

  /// -----------------------------------
  /// 7. nullptr ile Tür Dönüşümü
  /// Bir işaretçi türünü `nullptr` ile değiştirme
  int* ptr2 = nullptr;  // `nullptr` işaretçisi
  cout << "nullptr pointer: " << ptr2 << endl;

  /// -----------------------------------
  /// 8. Akıllı Pointern Dönüşümü (smart pointer casting)
  /// shared_ptr, unique_ptr gibi akıllı işaretçi türleri arasında dönüşüm yapılabilir.
  #include <memory>
  shared_ptr<Base> basePtr2 = make_shared<Derived>();
  shared_ptr<Derived> derivedPtr2 = static_pointer_cast<Derived>(basePtr2);  // shared_ptr ile dönüşüm
  cout << "smart pointer cast successful!" << endl;

  /// -----------------------------------
  /// 9. explicit Anahtar Kelimesiyle Tür Dönüşümü
  /// `explicit` anahtar kelimesi, otomatik tür dönüşümünü engeller.
  class MyClass {
  public:
      explicit MyClass(int x) { cout << "Explicit constructor called with " << x << endl; }
  };

  /// MyClass obj = 10;  // Hata verir çünkü explicit dönüşüm var
  MyClass obj(10); // explicit dönüşüm gerektirir
  */

  return 0;
}