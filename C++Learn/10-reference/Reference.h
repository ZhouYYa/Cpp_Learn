#pragma once
class Reference
{
};

int x = 0;
int* p = &x;
int& r = x; // r ����x������r��x����0.  ����һ��Ҫ�г�ֵ��   
            // sizeof(r) == sizeof(x)
int x2 = 5;                               // &x == &r;
r = x2;         // r�������´����������塣
int& r2 = r;

// object����reference�Ĵ�С��ͬ����ַҲ��ͬ��ȫ���Ǽ���

// reference�����ڲ������ݣ� pass by reference
// referenceͨ�����������������������ڲ������ͺͷ������͵�������

double imag(const double& im) {}
double imag(const double im) {}
//      signature    same signature,����ͬʱ����
// constҲ�Ǻ���ǩ����һ����