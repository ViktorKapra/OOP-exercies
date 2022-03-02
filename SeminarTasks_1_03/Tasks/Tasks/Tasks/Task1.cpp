#include <iostream>

struct ElectricalSupply
{
	double kWh;
	double priceOfProduct;
	double priceOfInstalation;
	int luxuryClass;
	ElectricalSupply(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, int _luxuryClass)
	{
		kWh = _kWh;
		priceOfProduct = _priceOfProduct;
		priceOfInstalation = _priceOfInstalation;
		luxuryClass = _luxuryClass;
	}
	double getPriceOfProduct() { return priceOfProduct; }
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
	Microwave(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, int _luxuryClass)
	:ElectricalSupply( _kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getMicrowavePrice(Microwave m) { return m.getPriceOfProduct(); }

struct Fridge : ElectricalSupply
{
	Fridge(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, int _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getFridgePrice(Fridge m) { return m.getPriceOfProduct(); }

struct Oven : ElectricalSupply
{
	Oven(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, int _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getOvenPrice(Oven m) { return m.getPriceOfProduct(); }

struct Aspirator : ElectricalSupply
{
	Aspirator(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, int _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getAspiratorPrice(Aspirator m) { return m.getPriceOfProduct(); }

struct FoodProcessor : ElectricalSupply
{
	FoodProcessor(double _kWh, double _priceOfProduct,
		double _priceOfInstalation, int _luxuryClass)
	:ElectricalSupply(_kWh, _priceOfProduct, _priceOfInstalation, _luxuryClass)
	{ }
};
double getFoodProcessorPrice(FoodProcessor m) { return m.getPriceOfProduct(); }

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
	std::cout << "Microwave price(" << (INCLUDES_INSTALLATION ? "including" : "excluding") << " installation) :" << getMicrowavePrice(microwave);
	std::cout << "Fridge price(" << (INCLUDES_INSTALLATION ? "including" : "excluding") << " installation) :" << getFridgePrice(fridge);
}