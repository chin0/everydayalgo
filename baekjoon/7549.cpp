#include <cstdio>
#include <cmath>

double get_rad(double deg) 
{
  return deg * (M_PI / 180.0);
}

int main(void)
{
  int c = 0;

  scanf("%d",&c);
  for(int i = 0; i < c; i++) {
    double R;
    int n;
    scanf("%lf %d", &R, &n);
    double degree = 360.0 / (double)n;
    double r = R * sin(get_rad(degree/2)) / (1 + sin(get_rad(degree/2)));
    printf("Scenario #%d:\n",i+1);
    printf("%.3lf\n\n",r);
  }
}
