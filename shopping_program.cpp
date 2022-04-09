#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;

const std::array <string, 3> products = {"Bread","Egg","Jam"}; //the product in the shop
const std::array <float, 3>  price = {10.0,5.50,7.20}; //the prices for the items
string input; // To store user input from the cmd.
std::vector <string> user; // This where the user selected items will go
float total;

void clear(){
    user.clear();
    total = 0.0;
}

void receipt(){ // prints out the receipt int text file
    int i = 0;
    std::ofstream file("receipt.txt");

    file << std::setw(23) << "Buzwane's shoping" << std::endl << 
        "============================" << std::endl;

    while(i < user.size()){ 
        /* Will go though all the elenents in the vector and will  
        print out the prices acording to the what is in the user vector*/
        if(user[i] == "BREAD"){ //
            file << user[i] << " " << std::setw(22) << std::setprecision(2) << std::fixed << price[0] << std::endl;
        } 
        else if(user[i] == "EGG"){
            file << user[i] << " " << std::setw(24) << std::setprecision(2) << std::fixed <<  price[1] << std::endl;
        }
        else{
            file << user[i] << " " << std::setw(24) << std::setprecision(2) << std::fixed <<  price[2] << std::endl;
        }
                
        i++;
    }
    file << "============================\n";
    file << "Your total will be " << "R" << std::setw(8) << std::setprecision(2) << std::fixed <<  total << std::endl;
}

void calculateTotal(){ // will add the total.
    int k = 0; // It count though all the items in the user array.
    while(k < user.size()){
       if(user[k] == "BREAD"){
           total += price[0];
       } 
       else if(user[k] == "EGG"){
           total += price[1];
       }
       else{
           total += price[2];
       }

        k++;
    }
    cout << "Your total will be " << "R" << std::setprecision(2) << std::fixed <<  total << std::endl;
    
}

void choice(){
    do{
        
        cout << "What product do you went?\n\n" << "Bread: R10\nEgg: R5.50\nJam: R7.20\nDone\n";
        cin >> input;
        std::transform(input.begin(),input.end(),input.begin(), ::toupper); //changes input to upper case
        if ((input == "BREAD") || (input == "EGG") || (input == "JAM")){
            user.push_back(input); //adds to vector
            cout << "added\n";
        }
        else if(input == "DONE"){
            break;
        }
        else{
            cout << "That is not part of the items\n";
        }

        }while(true);
}

bool again(){
    cout << "Again? Yes/No\n";
        do{
            cin >> input;
            std::transform(input.begin(),input.end(),input.begin(), ::toupper);
            if(input == "YES"){
                return true;
                break;
                
            }
            else if(input == "NO"){
                return false;
                break;
            }

            else{
                cout << "not a answer\n";
            }
        } while (true);
        
}
int main(){
    do{
        clear();
        choice();
        calculateTotal(); // will add the total.
        receipt();
    } while(again());
    cout << "Thanks for using Buzwane shopping";
   
    
}