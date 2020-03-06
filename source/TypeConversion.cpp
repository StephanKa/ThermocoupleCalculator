#include <TypeConversion.h>

std::vector<double> conversion(std::string const& conversionTarget, std::string const& type, std::vector<double> const& values)
{
    if (conversionTarget == "Voltage")
    {
        return conversionTargetTemperatureToVoltage(type, values);
    }
    else if (conversionTarget == "Temperature")
    {
        return conversionTargetVoltageToTemperature(type, values);
    }
    return std::vector<double> {};
}

std::vector<double> conversionTargetVoltageToTemperature(std::string const& type, std::vector<double> const& values)
{
    std::vector<double> result;
    result.reserve(values.size());
    for (auto& val : values)
    {
        if (type == "typeB")
        {
            result.push_back(TypeB::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeE")
        {
            result.push_back(TypeE::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeJ")
        {
            result.push_back(TypeJ::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeK")
        {
            result.push_back(TypeK::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeN")
        {
            result.push_back(TypeN::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeR")
        {
            result.push_back(TypeR::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeS")
        {
            result.push_back(TypeS::VoltageToTemperature::calculate(val));
        }
        else if (type == "typeT")
        {
            result.push_back(TypeT::VoltageToTemperature::calculate(val));
        }
    }
    return result;
}

std::vector<double> conversionTargetTemperatureToVoltage(std::string const& type, std::vector<double> const& values)
{
    std::vector<double> result;
    result.reserve(values.size());
    for (auto& val : values)
    {
        if (type == "typeB")
        {
            result.push_back(TypeB::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeE")
        {
            result.push_back(TypeE::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeJ")
        {
            result.push_back(TypeJ::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeK")
        {
            result.push_back(TypeK::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeN")
        {
            result.push_back(TypeN::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeR")
        {
            result.push_back(TypeR::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeS")
        {
            result.push_back(TypeS::TemperatureToVoltage::calculate(val));
        }
        else if (type == "typeT")
        {
            result.push_back(TypeT::TemperatureToVoltage::calculate(val));
        }
    }
    return result;
}