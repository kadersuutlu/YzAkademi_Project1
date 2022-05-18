#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int maxMul(uint8_t *p,int sizeBuffer,int serialNumber){
    /*maxMul adında 3 parametreli bir fonksiyon oluşturdum. Bu fonksiyonun
    ilk parametresi main fonksiyonundan gelen dizinin elemanlarını tutuyor.
    ikinci parametresi dizinin eleman sayısını tutuyor.
    üçüncü parametresi ise ardışık kaç sayının çarpımını istediğimizi tutuyor.
    */
  unsigned long long mul=1,maxMul=1,startPosition,finishPosition;
  /*ilk çarpımı tutması için mul, en büyük çarpımı tutması için ise maxMul değişkenini tanımladım.
  Bu çarpımlara ilk değer olarak 1 verdim. Yeni çarpım değer bu değerin yerine yazılıyor.
  startPosition serinin ilk elemanını, finishPosition ise serinin son elemanını tutan değişkenlerdir. */
    for(int i=0;i<sizeBuffer-(serialNumber-1);i++){
        mul=1;
    	for(int j=i;j<i+serialNumber;j++){
            mul*=p[j];
        }
        if(mul>maxMul){
            maxMul=mul;
            startPosition=i+1;   // En büyük çarpım başlama pozisyonu
            finishPosition=i+serialNumber;   // En büyük çarpım bitiş pozisyonu
        }
    }
    /*ilk for döngümüz serimizin ilk elemanından başlar.
    Dizinin eleman sayısı-(serialNumber-1) olana kadar  birer artarak tüm diziyi döner.
    Bunun nedeni dizinin ilk elemanının sıfır kabul edilmesidir
    sizeBuffer-(serialNumber-1) olmasının nedeni mesela 13 ardışık sayıyı düşünürsek dizinin son 12 elemanı kalana kadar
    çarpma devam eder.Fakat en son 12 eleman  kaldığında  bizden 13 eleman istendiği için çarpma işlemini yapmaz.
    ikinci for döngümüz i'den i+serialNumber'a kadar birer artarak devam eder. Burada da mul değeri her seferinde güncellenir.
    if bloğumuzda mul değerimiz ile maxMul değerimiz karşılaştırılır. En büyük çarpım hangisi ise yeni maxMul değeri o olur.
    başlangıç pozisyonumuzda dizimizin ilk indisi 0 kabul edildiği için i+1 olarak alınır ve bitis pozisyonumuzda
    i+serialNumber olur*/
    printf("Start Position : %d\n",startPosition);
    printf("Finish Position : %d\n",finishPosition);
    return maxMul;
}

int main()
{
    uint8_t buffer[1000] = {
        6,4,0,7,7,1,7,6,5,3,1,3,3,0,6,2,4,9,1,9,2,2,5,1,1,9,6,7,4,4,2,6,5,7,4,7,4,2,3,5,5,3,4,9,1,9,4,9,3,
        4,9,6,9,8,3,5,2,0,3,1,2,7,7,4,5,0,6,3,2,6,2,3,9,5,7,8,3,1,8,0,1,6,9,8,4,8,0,1,8,6,9,4,7,8,8,5,1,8,
        4,3,8,5,8,6,1,5,6,0,7,8,9,1,1,2,9,4,9,4,9,5,4,5,9,5,0,1,7,3,7,9,5,8,3,3,1,9,5,2,8,5,3,2,0,8,8,0,5,
        5,1,1,1,2,5,4,0,6,9,8,7,4,7,1,5,8,5,2,3,8,6,3,0,5,0,7,1,5,6,9,3,2,9,0,9,6,3,2,9,5,2,2,7,4,4,3,0,4,
        3,5,5,7,6,6,8,9,6,6,4,8,9,5,0,4,4,5,2,4,4,5,2,3,1,6,1,7,3,1,8,5,6,4,0,3,0,9,8,7,1,1,1,2,1,7,2,2,3,
        8,3,1,1,3,6,2,2,2,9,8,9,3,4,2,3,3,8,0,3,0,8,1,3,5,3,3,6,2,7,6,6,1,4,2,8,2,8,0,6,4,4,4,4,8,6,6,4,5,
        2,3,8,7,4,9,3,0,3,5,8,9,0,7,2,9,6,2,9,0,4,9,1,5,6,0,4,4,0,7,7,2,3,9,0,7,1,3,8,1,0,5,1,5,8,5,9,3,0,
        7,9,6,0,8,6,6,7,0,1,7,2,4,2,7,1,2,1,8,8,3,9,9,8,7,9,7,9,0,8,7,9,2,2,7,4,9,2,1,9,0,1,6,9,9,7,2,0,8,
        8,8,0,9,3,7,7,6,6,5,7,2,7,3,3,3,0,0,1,0,5,3,3,6,7,8,8,1,2,2,0,2,3,5,4,2,1,8,0,9,7,5,1,2,5,4,5,4,0,
        5,9,4,7,5,2,2,4,3,5,2,5,8,4,9,0,7,7,1,1,6,7,0,5,5,6,0,1,3,6,0,4,8,3,9,5,8,6,4,4,6,7,0,6,3,2,4,4,1,
        5,7,2,2,1,5,5,3,9,7,5,3,6,9,7,8,1,7,9,7,7,8,4,6,1,7,4,0,6,4,9,5,5,1,4,9,2,9,0,8,6,2,5,6,9,3,2,1,9,
        7,8,4,6,8,6,2,2,4,8,2,8,3,9,7,2,2,4,1,3,7,5,6,5,7,0,5,6,0,5,7,4,9,0,2,6,1,4,0,7,9,7,2,9,6,8,6,5,2,
        4,1,4,5,3,5,1,0,0,4,7,4,8,2,1,6,6,3,7,0,4,8,4,4,0,3,1,3,9,8,9,0,0,0,8,8,9,5,2,4,3,4,5,0,6,5,8,5,4,
        1,2,2,7,5,8,8,6,6,6,8,8,1,1,6,4,2,7,1,7,1,4,7,9,9,2,4,4,4,2,9,2,8,2,3,0,8,6,3,4,6,5,6,7,4,8,1,3,9,
        1,9,1,2,3,1,6,2,8,2,4,5,8,6,1,7,8,6,6,4,5,8,3,5,9,1,2,4,5,6,6,5,2,9,4,7,6,5,4,5,6,8,2,8,4,8,9,1,2,
        8,8,3,1,4,2,6,0,7,6,9,0,0,4,2,2,4,2,1,9,0,2,2,6,7,1,0,5,5,6,2,6,3,2,1,1,1,1,1,0,9,3,7,0,5,4,4,2,1,
        7,5,0,6,9,4,1,6,5,8,9,6,0,4,0,8,0,7,1,9,8,4,0,3,8,5,0,9,6,2,4,5,5,4,4,4,3,6,2,9,8,1,2,3,0,9,8,7,8,
        7,9,9,2,7,2,4,4,2,8,4,9,0,9,1,8,8,8,4,5,8,0,1,5,6,1,6,6,0,9,7,9,1,9,1,3,3,8,7,5,4,9,9,2,0,0,5,2,4,
        0,6,3,6,8,9,9,1,2,5,6,0,7,1,7,6,0,6,0,5,8,8,6,1,1,6,4,6,7,1,0,9,4,0,5,0,7,7,5,4,1,0,0,2,2,5,6,9,8,
        3,1,5,5,2,0,0,0,5,5,9,3,5,7,2,9,7,2,5,7,1,6,3,6,2,6,9,5,6,1,8,8,2,6,7,0,4,2,8,2,5,2,4,8,3,6,0,0,8,
        2,3,2,5,7,5,3,0,4,2,0,7,5,2,9,6,3,4,5,0};

    int buffLength=1000; 
    //Dizinin eleman sayısı belli olduğu için tekrar hesaplatmadım ve kolaylık olsun diye değişkene atadım.

    printf("\n");

    /*Burada sadece 13 ardışık çarpımı değil herhangi bir
    15 ardışık çarpımıda bulmamız istendiği için bu değeri kullanıcıdan istedim*/
    int howManyNumber;
    printf("How many consecutive numbers do you want to multiply ? ");
    scanf("%d",&howManyNumber);

    //En son main fonksiyonundan maxMul fonksiyonunu çağırıp verilen parametrelerle işlem yapılmasını sağladım.
   // maxMul(buffer,buffLength,howManyNumber);
    printf("Maximum Value : %llu",maxMul(buffer,buffLength,howManyNumber));
    return 0;

}
