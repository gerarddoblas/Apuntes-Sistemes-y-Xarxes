#include "Banana.h"

Json::Value Banana::Code()
{
    Json::Value json = Fruit::Code();

    json["bananidad"] = bananidad;
   // json[DecodeKey()] = typeid(Banana).name(); El de abajo es mejor manera de hacerlo
    ICodable::CodeSubClassType<Banana>(json);

    return json;
}

void Banana::Decode(Json::Value json)
{
    Fruit::Decode(json);
    bananidad = json["bananidad"].asInt();
}
