#include <iostream>


using namespace std;


class Car{
	private :
		int gasolinegauge;
		
	public :
		Car():gasolinegauge(20){
		
		}
		
		Car(int gas):gasolinegauge(gas){
		
		}
		
		int GetGasGauge() const{
			return gasolinegauge; 
		}
};

class HybridCar : public Car{
	private :
		int electricGauge;
	
	public :
		HybridCar():electricGauge(20){
		
		}
		
		HybridCar(int elec):electricGauge(elec){
		
		}

		HybridCar(int gas,int elec):Car(gas),electricGauge(elec){
		
		}
		
		int GetElecGauge() const{
			return electricGauge; 
		}
};



class HybridWaterCar : public HybridCar{
	private :
		int waterGauge;
	
	public :
		HybridWaterCar():waterGauge(20){
		
		}
		
		HybridWaterCar(int water):waterGauge(water){
		
		}

		HybridWaterCar(int gas,int elec, int water):HybridCar(gas,elec),waterGauge(water){
		
		}
		
		void ShowCurrentGauge() const{
			cout << "ÀÜ¿© °¡¼Ö¸°" << GetGasGauge() << endl;
			cout << "ÀÜ¿© Àü±â" << GetElecGauge() << endl;
			cout << "ÀÜ¿© ¿öÅÍ" << waterGauge << endl;
			 
		}
};


int main(void){

	HybridWaterCar tesla;
	HybridWaterCar nikola(50,50,50);
	
	tesla.ShowCurrentGauge();
	nikola.ShowCurrentGauge();
	


}
