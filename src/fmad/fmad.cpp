//__m128 _mm_fmadd_ps (__m128 a, __m128 b, __m128 c)
void fmadd(float * a, float * b, float * c, int num){
    for(int i=0;i<num;i++)
        c[i] = a[i] * b[i] +c[i];
}