#include "Processor.hpp"
#include <iostream>

void TextProcessor::process(const std::vector<std::string>& data) {
    for (const auto& item : data) {
        std::cout << "Text Processor processing: " << item << " (interpreted as text data)\n";
    }
}

void NumericProcessor::process(const std::vector<std::string>& data) {
    for (const auto& item : data) {
        std::cout << "Numeric Processor processing: " << item << " (interpreted as numerical values)\n";
    }
}

void ImageProcessor::process(const std::vector<std::string>& data) {
    for (const auto& item : data) {
        std::cout << "Image Processor processing: " << item << " (interpreted as image data)\n";
    }
}

void AudioProcessor::process(const std::vector<std::string>& data) {
    for (const auto& item : data) {
        std::cout << "Audio Processor processing: " << item << " (interpreted as audio signal)\n";
    }
}