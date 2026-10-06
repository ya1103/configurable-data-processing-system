#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

namespace Utilities{

    //Generic template to diplay and process any collections of any data type
    template<typename T>
    void processCollection(const std::vector<T>& collection, const std::string& label = "Generic Data")
    {
        std::cout << "--- Processing [" << label << "] (Size: " << collection.size() << ") ---\n";
        for (const auto& item : collection) {
            std::cout << "  [Item]: " << item << '\n';
        }
        std::cout << "-----------------------------------------\n";
    }

    template<typename T>
    T parseOptionValue(const std::string& strValue)
    {
        std::stringstream ss(strValue);
        T parsedValue;

        //Check successfull operation
        if(!(ss >> parsedValue))
        {
            throw std::invalid_argument("Failed to parse configuration value: " + strValue);
        }

        //return safely
        return parsedValue;
    }
}
#endif
