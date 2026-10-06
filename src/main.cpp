#include <iostream>
#include "Configuration.hpp"
#include "ProcessorFactory.hpp"
#include "Processor.hpp"
#include "Utilities.hpp"

int main()
{
try {
        // 1. Load and parse settings
        Configuration config("config/settings.txt");

        // 2. Extract configuration options using template parsing
        double threshold = Utilities::parseOptionValue<double>(
            config.getOption("Processor.Options.Threshold")
        );
        int maxRetries = Utilities::parseOptionValue<int>(
            config.getOption("Processor.Options.MaxRetries")
        );

        std::cout << "Configured Threshold: " << threshold << '\n';
        std::cout << "Configured Max Retries: " << maxRetries << '\n';

        // Create processor type based on config settings
        std::string processorType = config.getOption("Processor.Options.Type");
        auto processor = ProcessorFactory::createProcessor(processorType);

        // Start processing
        std::vector<std::string> sampleData = {"Sample1", "Sample2", "Sample3"};
        processor->process(sampleData);

        // Start processing using template function
        Utilities::processCollection(sampleData, "String Values");

        // Different data type of double
        std::vector<double> numericCollection = {1.05, 2.34, 9.81};
        // Start processing using same template function
        Utilities::processCollection(numericCollection, "Numeric Readings");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}