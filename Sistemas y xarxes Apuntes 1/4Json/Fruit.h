#pragma once

#include <string>
#include "iCodable.h"

class Fruit: public ICodable
{
public:

	unsigned int semillas = 0;
	std::string hexDelColor = "";

	virtual Json::Value Code() override;
	virtual void Decode(Json::Value json)  override;
};

