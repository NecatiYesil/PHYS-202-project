#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
// Constants 
const double A = 3;// Amplitude
const double G = 9.81;//gravity 
const double K = 200;//Spring Constant
const double M = 5;// Mass
const double DELTA_T = .001;// Time increment for the Euler Cromo
const int AMOUNT = 10000; // How many times the project should run 


class comp_Pro {
public:
	void exe1()
	{
		cout << fixed << setprecision(2) << endl;
		ofstream exe1v("exe1v.txt");
		ofstream exe1y("exe1y.txt");
		vn[0] = 0;
		yn[0] = A;
		time = 0;
		exe1v << "time vs velocity" << endl;
		exe1y << " time vs Postion " << endl;
		for (int i = 0; i < AMOUNT; i++)
		{
			dv = (K/M) * yn[i] - G;
			yn[i + 1] = yn[i] + vn[i] * DELTA_T;
			vn[i + 1] = vn[i] - dv*DELTA_T;
				exe1v << time << "," << vn[i] << endl;
				exe1y << time << "," << yn[i] << endl;
				time = time + DELTA_T;
		}
	}

	void exe1_exam() // exercise 1 
	{
		cout << fixed << setprecision(2) << endl;
		ofstream exe1v_c("exe1v_c.txt");
		ofstream exe1y_c("exe1y_c.txt");
		time = 0;
		yn[0] = A;
		for (int i = 0; i < AMOUNT; i++)
		{
			yn[i] = yn[0] * cos(sqrt(K/M) *time);// This checks the postion of Exe 1
			
			vn[i] = -(sqrt(K/M)) *yn[0] * sin(sqrt(K/M)*time);// The Velocity of Exe 1
			
			exe1v_c << time << "," << vn[i] << endl;
			exe1y_c << time << "," << yn[i] << endl;
			time = time + DELTA_T;
		}
	}

	void exe3()// Energy in the euler algorithm Model Using Euler Method (FIX THIS CODE )
	{
		cout << fixed << setprecision(2) << endl;
		ofstream exe3_e("exe3_Energy.txt");//Note Energy as A function of time 
		yn[0] = A;
		vn[0] = 0;
		time = 0;
		
		for (int i = 0; i < AMOUNT; i++)
		{
			dv = (-K/M)*yn[i];
			vn[i + 1] = vn[i] + dv*DELTA_T;
			yn[i + 1] = yn[i] + vn[i] * DELTA_T;
			e_tot = (.5*M*(vn[i] * vn[i])) + (.5*K*(yn[i] * yn[i]));

			exe3_e << time << "," << e_tot << endl;
			time = time + DELTA_T; 
		}

	}

	void exe4()// Same as EXE 1 But now using Euler cromer numerical Method 
	{
		cout << fixed << setprecision(2) << endl;
		ofstream exe4_p("exe4_p.txt");
		ofstream exe4_v("exe4_v.txt");
		yn[0] = A;// this equals the amplitude 
		vn[0] = 0;
		time = 0;
		for (int i = 0; i < AMOUNT; i++)
		{
			dv = (K/M)*yn[i] - G;
			vn[i + 1] = vn[i] - dv*DELTA_T;
			yn[i + 1] = yn[i] + vn[i+1] * DELTA_T;//ALL Euler Cromer method is vn[i+1] ONLY Diff AND Amplitude remains the same 
			exe4_p << time << "," << yn[i] << endl;
			exe4_v << time << "," << vn[i] << endl;
			time = time + DELTA_T;
		}
	}
	void exe5() //  Energy in the euler algorithm Model Using Euler Cromer Method
	{
		ofstream exe5_e("exe5_tot_e.txt");
		yn[0] = A;
		vn[0] = 0;
		time = 0;
		for (int i = 0; i < AMOUNT; i++)// using cromer values from exe 4
		{
			dv = (-K/M)*yn[i];
			vn[i + 1] = vn[i] + dv*DELTA_T;
			yn[i + 1] = yn[i] + vn[i + 1] * DELTA_T;
			e_tot = (.5*M*(vn[i] * vn[i])) +(.5*K*(yn[i] * yn[i]));

			exe5_e << time << "," << e_tot << endl;
			time = time + DELTA_T;
		}
	}
	void accepted_tot_energy()// This is the accepted Energy using the equation Etot = 1/2 K A^2
	{
		ofstream acc_tot_energy("acc_tot_engy.txt");
		time = 0; 
		for (int i = 0; i < AMOUNT; i++)
		{
			e = .5*K*(A*A);
			acc_tot_energy << time << "," << e << endl;
			time = time + DELTA_T;
		}
	}
private:
	double vn[AMOUNT];
	double yn[AMOUNT];
	double dv;// This stands for dv/dt 
	double time;
	double e_tot;// Energy Total 
	double e;//Accepted TOTAL  ENERGY (NOT REQUIRED)
};
int main()
{
	comp_Pro obj;
	obj.exe1();// Exercise 1 Euler Method 
	obj.exe3();//Exercise 3 Energy Using Euler method (NOTE HAS TO BE BEFORE EXE 1 CHECK TO COPY EXE1 COMP VALUES)
	obj.exe1_exam();// Exercise 1 Checker Using Theoretical Equations 
	obj.exe4();// Exe 4 Same as Exe 1 But now with Euler cromer 
	obj.exe5();// Exe 5 Same as Exe 3 But now with euler cromer 
	obj.accepted_tot_energy();//This give the graph of the REAL TOTAL ENERGY USING theoretical Equations 
	cout << "\n\nPress Any Key to quit " << endl;
	int zz;
	cin >> zz;
	return 0;
}
