#include "ProcessorFactory.hpp"
#include "Processor.hpp"
#include <stdexcept>


std::unique_ptr<Processor> ProcessorFactory::createProcessor(const std::string& type)
{
    if(type == "Text")
    {
        return std::make_unique<TextProcessor>();
    } else if(type == "Numeric")
    {
        return std::make_unique<NumericProcessor>();
    } else if(type == "Image")
    {
        return std::make_unique<ImageProcessor>();
    } else if(type == "Audio")
    {
        return std::make_unique<AudioProcessor>();
    } else{
        throw std::invalid_argument("Invalid processor type!");
    }
}