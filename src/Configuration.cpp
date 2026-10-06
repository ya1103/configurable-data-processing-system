#include "Configuration.hpp"
#include <fstream>
#include <stdexcept>

Configuration::Configuration(const std::string& filepath)
{
    std::fstream file(filepath);

    //Check if file is opened
    if(!file.is_open())
    {
        throw std::runtime_error("Configuration file could not be opened: " + filepath);
    }

    std::string eachLine;
    while(std::getline(file, eachLine))
    {
        //Trim each extracted line from file to remove whitespaces
        std::string trimmedLine = trim(eachLine);

        //Ignore empty lines, and commented starting with '#'
        if(trimmedLine.empty() || trimmedLine[0] == '#')
        {
            //skip parsed line
            continue;
        }
        //Find the delimiter position which is '='
        size_t delimiterPos = trimmedLine.find('=');
        
        //Check if delimiter has been found
        if(delimiterPos != std::string::npos)
        {
            std::string key, value;

            //Parse key and value from line using the delimiter
            //Trim before assigning
            key = trim(trimmedLine.substr(0, delimiterPos));
            value = trim(trimmedLine.substr(delimiterPos+1));
            
            //Check if key is null before inserting into map
            if(!key.empty())
            {
                //Insert by moving semantics
                options.insert(std::make_pair(std::move(key), std::move(value)));
            }

        }
    }
}


const std::string& Configuration::getOption(const std::string& optionKey) const
{
    auto it = options.find(optionKey);
    //Check if key found
    if(it != options.end())
    {
        return it->second;
    }else{
        throw std::invalid_argument("Configuration option not found: " + optionKey);
    }
}

std::string Configuration::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}