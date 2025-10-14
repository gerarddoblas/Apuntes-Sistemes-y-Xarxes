//#include <iostream>
//#include <json/json.h>
//#include <fstream>
//
//#include "Utils/ConsoleControl.h"
//#include "3NodeMap/NodeMap.h"
//#include "2InputSystem/InputSystem.h"
//
//
//
//
//class Player//  :Codable --> Serializable + Deserializable
//{
//public:
//
//    int life = 0;
//
//    std::string name = "Test Player";
//    unsigned int coins = 0;
//
//    Player() {}
//    ~Player() {}
//
//    void Decode(Json::Value json)//Des Serializar
//    {
//        life = json["life"].asInt();
//        name = json["name"].asString();
//        coins = json["coins"].asUInt();
//    }
//
//    Json::Value Encode()//Serializar
//    {
//        Json::Value json;
//
//        json["life"] = life;
//        json["name"] = name;
//        json["coins"] = coins;
//
//        return json;
//    }
//};
//
///// <summary>
///// ///////////////////////////////////////////////////////////////
///// </summary>
//class Tree : public INodeContent
//{
//    void Draw(Vector2 offset) override
//    {
//        CC::Lock();
//        CC::SetColor(CC::DARKGREEN, CC::BLACK);
//        CC::SetPosition(offset.X, offset.Y);
//        std::cout << "T";
//        CC::Unlock();
//    }
//};
//
//class Potatoe
//{
//
//};
//int main()
//{
//    Player* player = new Player();
//    player->coins = 5;
//    player->life = 50;
//    player->name = "Captain Test";
//
//    Json::Value newJson;
//
//    newJson["Player"] = player->Encode();
//
//    //std::ofstream* jsonWriteFile = new std::ofstream("PlayerParseTest.json", std::ifstream::binary)
//
//
//
//
//
//
//
//    /////////////////////////////////////////////////
//
//    /*
//    Node* node = new Node(Vector2(0, 0));
//
//    Tree* tree = new Tree();
//    Potatoe* potaote = new Potatoe();
//
//    node->SetContent(tree);
//
//    Tree* tree2 = node->GetContent<Tree>();
//    //Potatoe* potatoe2 = node->GetContent < Potatoe>();
//    */
//
//        NodeMap* myMap = new NodeMap(Vector2(20, 20), Vector2(2, 2));
//
//        Tree* t1 = new Tree();
//        Tree* t2 = new Tree();
//        Tree* t3 = new Tree();
//        Tree* t4 = new Tree();
//        Tree* t5 = new Tree();
//
//        myMap->SafePickNode(Vector2(0, 0), [t1](Node* node)
//            {
//                node->SetContent(t1);
//            });
//
//        myMap->SafePickNode(Vector2(0, 0), [t2](Node* node)
//            {
//                node->SetContent(t2);
//            });
//
//        myMap->SafePickNode(Vector2(0, 0), [t3](Node* node)
//            {
//                node->SetContent(t3);
//            });
//        myMap->SafePickNode(Vector2(0, 0), [t4](Node* node)
//            {
//                node->SetContent(t4);
//            });
//
//        myMap->SafePickNode(Vector2(0, 0), [t5](Node* node)
//            {
//                node->SetContent(t5);
//            });
//        myMap->UnSafeDraw();
//
//        InputSystem* iS = new InputSystem();
//
//        iS->AddListener(K_UP, [myMap]()
//        {
//            std::list<Vector2> positions;
//            positions.push_back(Vector2(10, 10));
//            positions.push_back(Vector2(10, 9));
//
//            myMap->SafeMultiPickNode(positions, [](std::list<Node*> nodes)
//                {
//
//                    std::list<Node*>::iterator it = nodes.begin();
//                    Node* n1 = *it;
//                    it++;
//                    
//                    Node* n2 = *it;
//                    
//                    n2->SetContent(n1->GetContent()); 
//                    
//                    n1->SetContent(nullptr);
//                    
//                    n1->DrawContent(Vector2(2,2));
//                    n1->DrawContent(Vector2(2,2));
//                });
//        });
//
//        iS->StartListen();
//    while (true)
//    {
//
//    }
//}



int main()
{

}
