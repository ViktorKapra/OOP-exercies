#include <iostream>

struct ElectricalSupply
{
	double kWh;
	double priceOfProduct;
	double priceOfInstalation;
	double luxuryClass;
	ElectricalSupply(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, double _luxuryClass)
	{
		kWh = _kWh;
		priceOfProduct = _priceOfProduct;
		priceOfInstalation = _priceOfInstalation;
		luxuryClass = _luxuryClass;
	}
	double getFullPrice()const { return priceOfProduct+ priceOfInstalation; }
};
double getKWh(ElectricalSupply &e, float priceKWh)
{
	return e.kWh * priceKWh;
}
double getLuxuryClass(ElectricalSupply &e)
{
	return e.luxuryClass;
}
struct Microwave :ElectricalSupply
{
	Microwave(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, double _luxuryClass)
	:ElectricalSupply( _kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getMicrowavePrice(const Microwave &m) { return m.getFullPrice(); }

struct Fridge : ElectricalSupply
{
	Fridge(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, double _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getFridgePrice(Fridge m) { return m.getFullPrice(); }

struct Oven : ElectricalSupply
{
	Oven(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, double _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getOvenPrice(Oven m) { return m.getFullPrice(); }

struct Aspirator : ElectricalSupply
{
	Aspirator(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, double _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getAspiratorPrice(Aspirator m) { return m.getFullPrice(); }

struct FoodProcessor : ElectricalSupply
{
	FoodProcessor(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, double _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getFoodProcessorPrice(FoodProcessor m) { return m.getFullPrice(); }

int main1()
{
	Microwave microwave = {1.0, 200.0, 0, 8};
	Fridge fridge = {3, 500.0, 0.0, 8};
	const float POWER_PRICE_KWH = 100.0f; 
	const bool INCLUDES_INSTALLATION = true;

	std::cout << "Total price per hour : "
	<< getKWh(microwave, POWER_PRICE_KWH) + getKWh(fridge, POWER_PRICE_KWH) << std::endl;
	std::cout << "Microwave luxury class : " << getLuxuryClass(microwave) << std::endl;
	std::cout << "Fridge luxury class : " << getLuxuryClass(fridge) << std::endl;
	std::cout << "Microwave price(" << (INCLUDES_INSTALLATION ? "including" : "excluding") << " installation) :" << getMicrowavePrice(microwave)<<std::endl;
	std::cout << "Fridge price(" << (INCLUDES_INSTALLATION ? "including" : "excluding") << " installation) :" << getFridgePrice(fridge);
	return 0;
}