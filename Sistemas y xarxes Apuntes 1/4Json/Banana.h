#pragma once

#include "Fruit.h"
class Banana: public Fruit
{
public:

	int bananidad = 0;

	virtual Json::Value Code() override;
	virtual void Decode(Json::Value json)  override;
};

