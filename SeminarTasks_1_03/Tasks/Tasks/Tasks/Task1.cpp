#include <iostream>

struct ElectricalSupply
{
	double kWh;
	double priceOfProduct;
	double priceOfInstalation;
	int luxuryClass;

};
double getKWh(ElectricalSupply e, float priceKWh)
{
	return e.kWh * priceKWh;
}
int getLuxuryClass(ElectricalSupply e)
{
	return e.luxuryClass;
}
struct Microwave :ElectricalSupply
{
};
struct Fridge : ElectricalSupply
{};
struct Oven : ElectricalSupply
{};
struct Aspirator : ElectricalSupply
{};
struct FoodProcessor : ElectricalSupply
{};

int main()
{
	Microwave microwave = {1.0, 200.0, 0, 8};
	Fridge fridge = {3, 500.0, 0.0, 8};
	const float POWER_PRICE_KWH = 100.0f; 
	const bool INCLUDES_INSTALLATION = true;

	std::cout << "Total price per hour : "
	<< getKWh(microwave, POWER_PRICE_KWH) + getKWh(fridge, POWER_PRICE_KWH) << std::endl;
	std::cout << "Microwave luxury class :" << getLuxuryClass(microwave) << std::endl;
	std::cout << "Fridge luxury class : " << getLuxuryClass(fridge) << std::endl;
}