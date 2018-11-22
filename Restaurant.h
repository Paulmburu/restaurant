#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Dish.h"
#include "Table.h"
#include "Action.h"


class Restaurant{		
public:
	Restaurant();  // done
    Restaurant(const std::string &configFilePath);  //done
    void start();   // done
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
    std::vector<std::string> details;

    int noOfTables=0;

    //open the config file
    if(myfile.is_open()){
        while(getline(myfile,line)){
            // std::cout<< line <<'\n';
            details.push_back(line);
        }
        myfile.close();
    }
    else std::cout <<"Unable to open file";

    for(int i=0;i!=details.size();++i){
        // store number of tables
        if(details.at(i).compare("#number of tables")==0)
                noOfTables=std::stoi(details.at(i+1)); //ignore

        // store table description    
        if(details.at(i).compare("#tables description")==0){
                // ie 6,4,4,14,10,10
                std::string nosDescription=details.at(i+1);
                

                if(noOfTables<2)
                    std::cout<<"one table\n";
                if(noOfTables>=2){
                    std::stringstream ss(nosDescription);
                    while(ss.good()){
                        std::string number;
                        getline(ss,number,',');
                        // std::cout<<number<<" "<<std::endl; 
                        tables.push_back(new Table(std::stoi(number)));
                    }
                }
        }

        
    }
    std::cout<<"Tables are "<<noOfTables<<std::endl;
}

void Restaurant::start(){
    std::cout<<"Restaurant is open \n";
    open=true;

    std::string userInput;
    while(getline(std::cin,userInput)){
        // break input into words and store in a vector
        std::string word;
        int noOfCustomers=0;
        std::vector<std::string> words;

        std::stringstream iss(userInput);
        while(iss>>word)
            words.push_back(word);

        // get customers count
        if(words.size()>=3)
            noOfCustomers=words.size()-2;
        // closeall
        if(words.at(0).compare("closeall")==0){
            std::cout<<"Time to close program"<<std::endl;
            return;
        }
        // open 2 Shalom,veg Dan,chip Alice,veg Bob,spc
        if(words.at(0).compare("open")==0){
            std::cout<<"open <table_id> <customer_1>,< customer_1_strategy> <customer_2>,<customer_2_ strategy>"<<std::endl;
            std::cout<<"Open table =======> "+words.at(1)<<std::endl;
            std::cout<<"Customers are =======> "<<noOfCustomers<<std::endl;
            std::cout<<"\n";
        }
        // order <table_id>
        if(words.at(0).compare("order")==0){
            std::cout<<"order <table_id> "<<std::endl;
            std::cout<<"\n";
        }  
        // move 2 3 5
        if(words.at(0).compare("move")==0){
            std::cout<<"move <origin_table_id> <dest_table_id> <customer_id>"<<std::endl;
            std::cout<<"\n";
        }
        // close
        if(words.at(0).compare("close")==0){
            std::cout<<"close <table_id> "<<std::endl;
            std::cout<<"\n";
        }

        // menu
        if(words.at(0).compare("menu")==0){
            std::cout<<"Salad VEG 40NIS\n"<<
            "Water BVG 20NIS\n"<<"Chili con carne SPC 440NIS\n\n";
        }

        //status <table_id>
        if(words.at(0).compare("status")==0){
            std::cout<<"menu\n"<<std::endl;
        }

        //log
        if(words.at(0).compare("log")==0){
            std::cout<<"log \n"<<std::endl;
        }



        
    }
}
#endif
