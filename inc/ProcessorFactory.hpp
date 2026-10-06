#ifndef PROCESSORFACTORY_HPP
#define PROCESSORFACTORY_HPP

#include <memory>

//Forward declaration
class Processor;

class ProcessorFactory{
    public:
        //Static helper function which returns a unique pointer to abstract class *Processor*
        //Should throw an error if type is invalid argument
        static std::unique_ptr<Processor> createProcessor(const std::string& type);

};

#endif
