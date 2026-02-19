#include <stdio.h>
#include <math.h>

double factorial(int f){
    if (f <= 1) return 1.0;
    return f * factorial(f - 1);
}

double bernulli(int n){
    if (n == 0) return 1;
    if (n == 1) return -0.5;
    if (n > 1 && n % 2 == 1) return 0;

    double s = 0.0;
    for (int k = 0; k < n; k++){
        s += (factorial(n+1) / (factorial(k) * factorial(n+1-k))) * bernulli(k);
    }
    return -s / (n+1);
}

double sinus(double x, int n){
    double s = 0.0;
    for (int i = 0; i <= n; i++){
        s += pow(-1, i) * pow(x, 2*i + 1) / factorial(2*i + 1);
    }
    return s;
}

double cosinus(double x, int n){
    double s = 0.0;
    for (int i = 0; i <= n; i++){
        s += pow(-1, i) * pow(x, 2*i) / factorial(2*i);
    }
    return s;
}

double expanent(double x, int n){
    double s = 0.0;
    for (int i = 0; i <= n; i++){
        s += pow(x, i) / factorial(i);
    }
    return s;
}

double cosecans(double x, int n){
    double s = 0.0;
    for (int i = 1; i <= n; i++){
        double coeff = (2 * (pow(2, 2*i-1) - 1) * bernulli(2*i) * pow(x, 2*i - 1)) / factorial(2*i);
        s += pow(-1, i - 1) * coeff;
    }
    return (1/x) + s;
}

int main(){
    double (*sinus1)(double, int) = &sinus;
    double (*cosinus1)(double, int) = &cosinus;
    double (*expanent1)(double, int) = &expanent;
    double (*cosecans1)(double, int) = &cosecans;
    int f;
    

    while (1)
    {
        printf("\nChoose mode:\n");
        printf("1 - calculated\n2 - experiment\n0 - exit\n");
        scanf_s("%d", &f);

        if (f == 0) break;
        switch (f)
        {
        case 1:{

            while (1)
            {
                int n;
                
                printf("\nChoose mode:\n");
                printf("1 - sinus\n2 - cosinus\n3 - expanent\n4 - cosecans\n0 - exit\n");
                scanf_s("%d", &n);

                if (n == 0) break;

                printf("Enter: value  degree  precision\n");

                double value, precision;
                int degree;
                scanf_s("%lf %d %lf", &value, &degree, &precision);

                int digits = (int)(-log10(precision));

                switch (n)
                {
                    case 1:
                        printf("calculated:\n");
                        printf("%.*f\n", digits,sinus1(value, degree));
                        printf("reference:\n");
                        printf("%.*f\n",digits,sin(value));
                        printf("difference:\n");
                        printf("%.*f",digits,sin(value)-sinus1(value,degree));
                        break;
                    case 2:
                        printf("calculated:\n");
                        printf("%.*f\n", digits, cosinus1(value, degree));
                        printf("reference:\n");
                        printf("%.*f\n",digits,cos(value));
                        printf("difference:\n");
                        printf("%.*f",digits,cos(value)-cosinus1(value,degree));
                        break;
                    case 3:
                        printf("calculated:\n");
                        printf("%.*f\n", digits, expanent1(value, degree));
                        printf("reference:\n");
                        printf("%.*f\n",digits,exp(value));
                        printf("difference:\n");
                        printf("%.*f",digits,exp(value)-expanent1(value,degree));
                        break;
                    case 4:
                        printf("calculated:\n");
                        printf("%.*f\n", digits, cosecans1(value, degree));
                        printf("reference:\n");
                        printf("%.*f\n",digits,(1/sin(value)));
                        printf("difference:\n");
                        printf("%.*f",digits,(1/sin(value))-cosecans1(value, degree));
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                    
            }
        
            break;
        }
        case 2:{

            while (1)
            {
                printf("\nChoose function:\n");
                printf("1 - sinus\n2 - cosinus\n3 - expanent\n4 - cosecans\n0 - exit\n");
                 int m;
                scanf_s("%d", &m);

                if (m == 0) break;

                printf("set the value point:\n");
                double value;
                scanf_s("%lf", &value);

                
                printf("Enter: value NMax\n");

                int NMax;
                scanf_s("%d",&NMax);


                

                switch (m)
                {
                    case 1:
                        printf("reference:\n");
                        printf("%f\n",sin(value));
                        printf("experiment:\n");
                        for (int i = 0; i <= NMax; i++){
                            printf("%f %f",sinus1(value,i),sin(value)-sinus1(value,i));
                            printf("\n");
                        }
                        break;
                    case 2:
                        printf("reference:\n");
                        printf("%f\n",cos(value));
                        printf("experiment:\n");
                        for (int i = 0; i <= NMax; i++){
                            printf("%f %f",cosinus1(value,i),cos(value)-cosinus1(value,i));
                            printf("\n");
                        }
                        break;
                    case 3:
                        printf("reference:\n");
                        printf("%f\n",exp(value));
                        printf("experiment:\n");
                        for (int i = 0; i <= NMax; i++){
                            printf("%f %f",expanent1(value,i),exp(value)-expanent1(value,i));
                            printf("\n");
                        }
                        break;
                    case 4:
                        printf("reference:\n");
                        printf("%f\n",1/(sin(value)));
                        printf("experiment:\n");
                        for (int i = 0; i <= NMax; i++){
                            printf("%f %f",cosecans1(value,i),1/(sin(value))-cosecans1(value,i));
                            printf("\n");
                        }
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                    
            }
        
            break;
        }
        default:
            printf("Invalid choice\n");
        }

    }

    return 0;
}
