#include "Fruit.h"

Json::Value Fruit::Code()
{
	Json::Value json;

	json["semillas"] = semillas;
	json["hexDelColor"] = hexDelColor;

	return json;
}

void Fruit::Decode(Json::Value json)
{
	semillas = json["semillas"].asInt();
	hexDelColor = json["hexDelColor"].asString();
}