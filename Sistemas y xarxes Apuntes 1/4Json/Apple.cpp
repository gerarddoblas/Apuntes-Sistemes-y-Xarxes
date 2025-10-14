#include "Apple.h"

Json::Value Apple::Code()
{
    Json::Value json = Fruit::Code();

    json["manzanidad"] = manzanidad;
    // json[DecodeKey()] = typeid(Banana).name(); El de abajo es mejor manera de hacerlo
    ICodable::CodeSubClassType<Apple>(json);

    return json;
}

void Apple::Decode(Json::Value json)
{
    Fruit::Decode(json);
    manzanidad = json["manzanidad"].asInt();
}
