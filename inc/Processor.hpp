#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <vector>
#include <string>

class Processor{
    public:
        virtual ~Processor() = default;

        virtual void process(const std::vector<std::string>& data) = 0;
};

class TextProcessor: public Processor{
    public:
        virtual void process(const std::vector<std::string>& data) override;
};

class NumericProcessor: public Processor{
    public:
        virtual void process(const std::vector<std::string>& data) override;
};

class ImageProcessor: public Processor{
    public:
        virtual void process(const std::vector<std::string>& data) override;
};

class AudioProcessor: public Processor{
    public:
        virtual void process(const std::vector<std::string>& data) override;
};

#endif
