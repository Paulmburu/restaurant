#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <vector>
#include <string>
#include <fstream>
#include "Dish.h"
#include "Table.h"
#include "Action.h"


class Restaurant{		
public:
	Restaurant();
    Restaurant(const std::string &configFilePath);
    void start();
    int getNumOfTables() const;
    Table* getTable(int ind);
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Dish>& getMenu();

private:
    bool open;
    std::vector<Table*> tables;
    std::vector<Dish> menu;
    std::vector<BaseAction*> actionsLog;
};
Restaurant::Restaurant(const std::string &configFilePath){
    std::string line;
    std::ifstream myfile (configFilePath.c_str());

    if(myfile.is_open()){
        while(getline(myfile,line)){
            // std::cout<< line <<'\n';
        }
        myfile.close();
    }
    else std::cout <<"Unable to open file";

}

void Restaurant::start(){
    std::cout<<"Restaurant is open \n";
}
#endif
