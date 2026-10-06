#include <iostream>
#include "Configuration.hpp"
#include "ProcessorFactory.hpp"
#include "Processor.hpp"

int main()
{
    try{
        Configuration config("config/settings.txt");

        //Fetch processor type from extracted config file
        auto processorType = config.getOption("Processor.Options.Type");

        //Call processor factory based on fetched type
        auto processor = ProcessorFactory::createProcessor(processorType);

        //Data sample
        std::vector<std::string> data = {"Sample1", "Sample2", "Sample3"};

        //Start processing on data sample, by abstracting which processor type is used
        //This enforces polymorphism
        processor->process(data);

    } catch(std::exception& e)
    {
        std::cout << e.what();
    }
}