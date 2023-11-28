#include <iostream>
#include <cmath>
int main(){
    int X1, X2, Y1, Y2;
    std::cin >> X1 >> Y1 >> X2 >> Y2;
     double thetta = fabsl((atan2l(X1,Y1) - atan2l(X2,Y2)) * 180/M_PI);
     if(thetta > 180) thetta = 360 -thetta;
     double line_one = sqrtl(powl(X1,2)+powl(Y1,2));
     double line_two = sqrtl(powl(X2,2)+powl(Y2,2));
     double rad = (  line_one > line_two ? line_two : line_one);
     double L = (M_PI * rad * thetta)/180;
     double res =  ((L+fabsl(line_one-line_two)) > (line_one+line_two) ? line_one+line_two : (L+fabsl(line_one-line_two)));
    printf("%.12lf",res);
return 0;
}