#pragma once

#include "Fruit.h"
class Apple : public Fruit
{
public:

	int manzanidad = 0;

	virtual Json::Value Code() override;
	virtual void Decode(Json::Value json)  override;
};

