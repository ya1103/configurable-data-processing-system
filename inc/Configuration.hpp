#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <unordered_map>
#include <string>

class Configuration{
    private:
        // Stores parsed options as key-value pairs
        std::unordered_map<std::string, std::string> options;

    public:
        // Constructor reads and parses the configuration file directly
        // Explicit to avoid implicit type conversions
        explicit Configuration(const std::string& filepath);

        // Returns option value using its key
        // If key not found it throws invalid argument exception
        const std::string& getOption(const std::string& optionKey) const;
};

#endif
