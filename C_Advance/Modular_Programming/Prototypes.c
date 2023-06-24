#include <stdio.h>
#include <stdlib.h>

/** Đặt vấn đề:
 Những bài hướng dẫn trước, tôi yêu cầu bạn đặt các functions trước main. Tại sao vậy?
Tại vì thứ tự sắp xếp có một tầm quan trọng: Khi bạn đặt function trước main, máy tính sẽ đọc và
nhớ nó. Khi được gọi lại trong main, máy tính sẽ biết phải kiếm lại function đó ở đâu.
Nhưng nếu bạn đặt sau main, chương trình sẽ không hoạt động vì máy tính vẫn không biết
function đó là gì.
*/
// Đoạn code sau chính là  prototype của function dientichHinhChuNhat :
double dientichHinhChuNhat(double chieuRong, double chieuDai);
//Rút gọn:
//double dientichHinhChuNhat (double , double);
int main(int argc, char *argv[])
{
    printf("Hinh chu nhat voi chieu rong 5 va chieu dai 10 co dien tich la %f\n",
           dientichHinhChuNhat(5, 10));
    printf("Hinh chu nhat voi chieu rong 2.5 va chieu dai 3.5 co dien tich la %f\n",
           dientichHinhChuNhat(2.5, 3.5));
    printf("Hinh chu nhat voi chieu rong 4.2 va chieu dai 9.7 co dien tich la %f\n",
           dientichHinhChuNhat(4.2, 9.7));
    return 0;
}
// function dientichHinhChuNhat Bây giờ có thể đặt ở bất kì vị trí nào trong code source
double dientichHinhChuNhat(double chieuRong, double chieuDai)
{
    return chieuRong * chieuDai;
}