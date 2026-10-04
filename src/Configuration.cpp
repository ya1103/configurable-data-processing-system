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
        //Ignore empty lines, and commented starting with '#'
        if(eachLine.empty() || eachLine[0] == '#')
        {
            //skip parsed line
            continue;
        }
        //Find the delimiter position which is '='
        size_t delimiterPos = eachLine.find('=');
        
        //Check if delimiter has been found
        if(delimiterPos != std::string::npos)
        {
            std::string key, value;

            //Parse key and value from line using the delimiter
            key = eachLine.substr(0, delimiterPos);
            value = eachLine.substr(delimiterPos+1);
            
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