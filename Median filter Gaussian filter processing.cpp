#include "opencv2/opencv.hpp"
#include <iostream>
#include <time.h>
using namespace cv;
using namespace std;

#define Mask_Size 7

int main() {
    clock_t start, end;
    double result;

    Mat src = imread("Lenna_Noise.jpg");
    Mat dst_Box_filter;
    Mat dst_Gaussian_filter;

    start = clock(); // 수행 시간 측정 시작

    // 수행시간 측정하고자 하는 코드
    blur(src, dst_Box_filter, Size(Mask_Size, Mask_Size));


    end = clock(); // 시간 측정 끝
    result = (double)(end - start);

    // 결과 출력
    cout << "Box filter result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl;

    start = clock(); // 수행 시간 측정 시작

    // 수행시간 측정하고자 하는 코드 
    GaussianBlur(src, dst_Gaussian_filter, Size(Mask_Size, Mask_Size), 0, 0);


    end = clock(); // 시간 측정 끝
    result = (double)(end - start);

    // 결과 출력
    cout << "GaussianBlur result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl;

    imshow("source", src);
    imshow("Box filter", dst_Box_filter);
    imshow("Gaussian filter", dst_Gaussian_filter);

    waitKey(0);
    return 0;
}