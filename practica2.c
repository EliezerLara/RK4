//Programa que resuelve ecuaciones diferenciales (tres variables) por el método RK4

#include<stdio.h>
#include<math.h>

#define g1(x,y,z,t) (s*(y-x))        //primera derivada
#define g2(x,y,z,t) (r*x-y-x*z)     //segunda derivada
#define g3(x,y,z,t) (x*y-b*z)    //tercera derivada

void rk4(double t, double x, double y, double z, double tf, int n){

double s=10.0 , b=8.0/3.0;
double r;

printf("Ingresa el valor de r (parámetro positivo):\n");  //ingresamos el valor del parámetro de control
scanf("%lf", &r);

FILE*arch=fopen("lorenz7.txt", "w");
    double h = (tf-t)/n;

//funciones auxiliares

double k11, k12, k13, k21, k22, k23, k31, k32, k33, k41, k42, k43;

    for (int i=0; i<=n; i++) {

        fprintf(arch, "%lf %lf %lf %lf\n", x, y, z, t);

        k11 = h*g1(x,y,z,t);
        k12 = h*g2(x,y,z,t);
        k13 = h*g3(x,y,z,t);

        k21 = h*g1(x+k11/2.0,y+k12/2.0,z+k13/2.0,t+h/2.0);
        k22 = h*g2(x+k11/2.0,y+k12/2.0,z+k13/2.0,t+h/2.0);
        k23 = h*g3(x+k11/2.0,y+k12/2.0,z+k13/2.0,t+h/2.0);

        k31 = h*g1(x+k21/2.0,y+k22/2.0,z+k23/2.0,t+h/2.0);
        k32 = h*g2(x+k21/2.0,y+k22/2.0,z+k23/2.0,t+h/2.0);
        k33 = h*g3(x+k21/2.0,y+k22/2.0,z+k23/2.0,t+h/2.0);

        k41 = h*g1(x+k31,y+k32,z+k33,t+h);
        k42 = h*g2(x+k31,y+k32,z+k33,t+h);
        k43 = h*g3(x+k31,y+k32,z+k33,t+h);

//Actualizar el valor 

        x += (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
        y += (1.0/6.0)*(k12 + 2*k22 + 2*k32 + k42);
        z += (1.0/6.0)*(k13 + 2*k23 + 2*k33 + k43);

        // Actualizar el valor de t
        
        t += h;
    }
 
	
	 
	fclose(arch);

}

//Función principal

int main() {
    double t=0.0,  x=1.02 , y=3.02 , z=-2.02 , tf=7.0; 
    int n=1000;

    rk4(t, x, y, z, tf, n);
	
	return 0; 
}