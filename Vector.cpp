#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <iomanip>
#include <map>
#include <algorithm> // Needed for std::find
//This is the isValidItemChoice, we assigned a constant string to the following variables, city, choice, and selectedItems, we also
//assigned a constant vector to selectedItems.
//We then made a map with the purpose of assigning different prices of food to different cities, for exmaple a bottle of water
//in los angeles may be different than a bottle of water in new york
//

static bool isValidItemChoice(const std::string& city, const std::string& choice, const std::vector<std::string>& selectedItems) {

    std::unordered_map<std::string, std::unordered_map<std::string, double>> groceryPrices = {
        {"Los Angeles", {
            {"Chicken Breast", 8.50}, {"Brown Rice", 4.00}, {"Water Bottle", 1.50}, {"Mixed Nuts", 6.00},
            {"Fried Chicken", 5.00}, {"White Bread", 2.50}, {"Soda", 2.00}, {"Potato Chips", 3.00}
        }},
        {"New York City", {
            {"Chicken Breast", 9.00}, {"Brown Rice", 4.50}, {"Water Bottle", 1.75}, {"Mixed Nuts", 6.50},
            {"Fried Chicken", 5.50}, {"White Bread", 3.00}, {"Soda", 2.25}, {"Potato Chips", 3.50}
        }},
        {"Illinois", {
            {"Chicken Breast", 7.00}, {"Brown Rice", 3.50}, {"Water Bottle", 1.25}, {"Mixed Nuts", 5.00},
            {"Fried Chicken", 4.25}, {"White Bread", 2.00}, {"Soda", 1.75}, {"Potato Chips", 2.75}
        }},
        {"San Francisco", {
            {"Chicken Breast", 10.00}, {"Brown Rice", 5.00}, {"Water Bottle", 2.00}, {"Mixed Nuts", 7.00},
            {"Fried Chicken", 6.00}, {"White Bread", 3.25}, {"Soda", 2.50}, {"Potato Chips", 4.00}
        }}


    };
    //we made a line of code that assigns our cityIt to a find function that goes into the groceryPrices map and finds the city the user has chosen.
    //By doing this we set ourselves up for success in being able to detect, invalid cities, or valid cities.
    //As a reminder 'auto' keyword  automatically detects the type of variable we are using depending on what we assign it to.
    auto cityIt = groceryPrices.find(city);
   
    
    if (cityIt->second.find(choice) == cityIt->second.end()) {
        std::cout << "Invalid Item Choice \n";
        return false;
    }
    //if the user tries to pick the same item more than once.
    if (std::find(selectedItems.begin(), selectedItems.end(), choice) != selectedItems.end()) {
        std::cout << "You already selected that item \n";
        return false;
    } 

   
    

 
    
    // current goal is to figure out how to add a scenario for when the user does select a valid grocery item, 
    return true;
}
int limit = 3;







int main() {
    int breakfastChoice = 0;
    int citychoicesnum = 0;
    std::string name;
    int optionchoicenumone = 0;
    std::string chosenCity;
   
    int userChoice = 0;
    int balance = 200;
    std::string itemName;
    char choice;
    double totalCost = 0.0;

    std::unordered_map<std::string, std::unordered_map<std::string, double>> cityPriceMultiplier = {
        {"Los Angeles", {
            {"Chicken Breast", 8.50}, {"Brown Rice", 4.00}, {"Water Bottle", 1.50}, {"Mixed Nuts", 6.00},
            {"Fried Chicken", 5.00}, {"White Bread", 2.50}, {"Soda", 2.00}, {"Potato Chips", 3.00}
        }},
        {"New York City", {
            {"Chicken Breast", 9.00}, {"Brown Rice", 4.50}, {"Water Bottle", 1.75}, {"Mixed Nuts", 6.50},
            {"Fried Chicken", 5.50}, {"White Bread", 3.00}, {"Soda", 2.25}, {"Potato Chips", 3.50}
        }},
        {"Illinois", {
            {"Chicken Breast", 7.00}, {"Brown Rice", 3.50}, {"Water Bottle", 1.25}, {"Mixed Nuts", 5.00},
            {"Fried Chicken", 4.25}, {"White Bread", 2.00}, {"Soda", 1.75}, {"Potato Chips", 2.75}
        }},
        {"San Francisco", {
            {"Chicken Breast", 10.00}, {"Brown Rice", 5.00}, {"Water Bottle", 2.00}, {"Mixed Nuts", 7.00},
            {"Fried Chicken", 6.00}, {"White Bread", 3.25}, {"Soda", 2.50}, {"Potato Chips", 4.00}
        }}
    };

    std::cout << "Welcome to 30 day Money Manager Tutorial !\n";
    std::cout << "In this tutorial you will be granted an initial amount of money and a choice for some other basic starter life choices that your profile consist of\n";

    std::cout << "If you would like to quit the game and hit m, if you'd like to go straight to the game hit n to start making your profile: ";
    std::cin >> choice;

    if (choice == 'm') {
        std::cout << "You have decided to end the game\n";
        return 0;
    }
    else if (choice == 'n') {
        std::cout << "Please pick the preferred name of your character: ";
        std::cin >> name;

        std::vector<std::string> cityoptions = { "City 1 - Los Angeles ", "City 2 - New York City", "City 3 - Illinois ", "City 4 - San Francisco" };

        for (size_t i = 0; i < cityoptions.size(); ++i) {
            std::cout << cityoptions[i] << std::endl;
        }

        std::cout << " Please type the number of the city you would like to live in: \n";
        std::cin >> citychoicesnum;
         
        switch (citychoicesnum) {
        case 1:
            chosenCity = "Los Angeles";
            break;
        case 2:
            chosenCity = "New York City";
            break;
        case 3:
            chosenCity = "Illinois";
            break;
        case 4:
            chosenCity = "San Francisco";
            break;
        default:
            std::cout << "Please pick a valid city.\n";
            return 1;
        }

        std::cout << "Welcome to the first day of money managing, let's see how long you can last\n";
        std::cout << "DECISION ALERT! Balance equals: $" << balance << "\n";
        std::cout << name << " is hungry for breakfast. You have 2 options:\n";

        std::vector<std::string> breakfastOptions = { "1 - Order Doordash", "2 - Buy food from grocery store" };

        for (const auto& option : breakfastOptions) {
            std::cout << option << std::endl;
        }

        std::cout << "Enter your breakfast choice (1 or 2): ";
        std::cin >> userChoice;

        if (userChoice == 1) {
            std::cout << "You have decided to order Doordash.\n";
            totalCost = 18.00;
            balance -= static_cast<int>(totalCost + 0.5);
            std::cout << "\n========================================\n";
            std::cout << "✅ PROFILE SETUP COMPLETE (Tutorial Step)\n";
            std::cout << "========================================\n";
            std::cout << "Name: " << name << "\n";
            std::cout << "City: " << chosenCity << "\n";
            std::cout << "Starting Balance: $200\n";

            std::cout << "\nBreakfast method: DoorDash\n";
            std::cout << "DoorDash cost (flat): $" << std::fixed << std::setprecision(2) << totalCost << "\n";
            std::cout << "Balance after breakfast: $" << balance << "\n";

            std::cout << "\n🎓 Tutorial complete!\n";
            std::cout << "You learned how to:\n";
            std::cout << "  1) Create a profile (name + city)\n";
            std::cout << "  2) Choose an option from a menu\n";
            std::cout << "  3) Update a value (balance) based on a choice\n";
            std::cout << "\nThanks for trying the Money Manager Tutorial.\n";
            std::cout << "Exiting...\n";
            return 0;


        }
        else if (userChoice == 2) {
            std::cout << "You have decided to buy food from the grocery store.\n";
        }
        else {
            std::cout << "Invalid Option. Please try again.\n";
            return 1;
        }




        //Making a visual graph of options for the user to see so they can know what's available
        //This is kinda like a menu
        std::vector<std::string> itemstoChoose = { " Chicken Breast ", "  Brown Rice ", " Water Bottle ", "Mixed Nuts", "Fried Chicken", "White Bread", "Soda", "Potato Chips"};

        //this is the second part of making our visual graph for users to be able to see
        for (size_t i = 0; i < itemstoChoose.size(); ++i) {
            std::cout << itemstoChoose[i] << std::endl;
        }

        //We are using a map to assign keys to specific grocery items the user may want the int stands for the key and the string stands for the grocery item
        std::unordered_map<int, std::string> groceryChooser = {
             {1, "Chicken Breast"},
               {2, "Brown Rice"},
                {3, "Water Bottle"},
                 {4, "Mixed Nuts" },
                {5, "Fried Chicken"},
                {6, "White Bread"},
                {7, "Soda"},
                {8, "Potato Chips"}

        };


        //We're making another vector this time not for the users to see but for us to have a way to measure the amount of selected items being chosen right now 
        //we only want a max of 4 so we have to make a while statement
        std::vector<std::string> selectedItems;
        int optionLimits = 4;
        int itemNum = 0;
        //This is our while statement we're basicall saying as long as the size of our selected items vector is smaller than the optionLImits, which is 
        // YOu can allow the user to pick another item
        while (selectedItems.size() < optionLimits) {
            std::cout << "Pick a grocery item by number (1-8): ";
            std::cin >> itemNum;

            // We are Checking if the number corresponds to a valid item, right now the only numbers we have our 1-8, so it wouldnt make since if the user
            //Chose something like 23, this function is making sure that if that do pick something random then it jumps to our else statement that stands for invalid item number
            if (groceryChooser.find(itemNum) != groceryChooser.end()) {
                std::string itemName = groceryChooser[itemNum];

                // Check if it's already been selected, we're basically saying here if we search selected items to find the item name from the beginning to end 
                //and we find the item name, if it's equal to the character space after our last character, that means it's equal to nothing and in that case
                //It isnt equal to anything already in our selections we can add something new.
                //

                if (std::find(selectedItems.begin(), selectedItems.end(), itemName) == selectedItems.end()) {
                    selectedItems.push_back(itemName);
                    std::cout << "Added: " << itemName << "\n";
                }
                //A else statement for if they already chose a item number that's valid
                else {
                    std::cout << "You already picked that item.\n";
                }
            }
            //A else statement for if they pick something not in the item options.
            else {
                std::cout << "Invalid item number.\n";
            }
        }


        // =========================
// Tutorial "Checkpoint" End
// =========================

// Calculate total cost of selected items based on the chosen city
        totalCost = 0.0;

        // Safety: make sure city exists in your price table
        auto cityIt2 = cityPriceMultiplier.find(chosenCity);
        if (cityIt2 != cityPriceMultiplier.end()) {
            for (const auto& food : selectedItems) {
                auto itemIt = cityIt2->second.find(food);
                if (itemIt != cityIt2->second.end()) {
                    totalCost += itemIt->second;
                }
            }
        }

        balance -= static_cast<int>(totalCost + 0.5); // simple rounding to nearest dollar

        std::cout << "\n========================================\n";
        std::cout << "✅ PROFILE SETUP COMPLETE (Tutorial Step)\n";
        std::cout << "========================================\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "City: " << chosenCity << "\n";
        std::cout << "Starting Balance: $200\n";

        std::cout << "\nYou selected the max number of grocery items (" << optionLimits << "):\n";
        for (const auto& food : selectedItems) {
            std::cout << " - " << food;

            // show price next to each item if possible
            if (cityIt2 != cityPriceMultiplier.end()) {
                auto itemIt = cityIt2->second.find(food);
                if (itemIt != cityIt2->second.end()) {
                    std::cout << " ($" << std::fixed << std::setprecision(2) << itemIt->second << ")";
                }
            }
            std::cout << "\n";
        }

        std::cout << "\nTotal grocery cost: $" << std::fixed << std::setprecision(2) << totalCost << "\n";
        std::cout << "Balance after breakfast: $" << balance << "\n";

        std::cout << "\n🎓 Tutorial complete!\n";
        std::cout << "You learned how to:\n";
        std::cout << "  1) Create a profile (name + city)\n";
        std::cout << "  2) Choose an option from a menu\n";
        std::cout << "  3) Select items with a limit\n";
        
        std::cout << "\nThanks for trying the Money Manager Tutorial.\n";
        std::cout << "Exiting...\n";
        return 0;


    }


       }
        

       


        
       

        


       


 











        
        


    

  

