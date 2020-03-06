#pragma once
#include <TypeBCoefficients.h>
#include <TypeECoefficients.h>
#include <TypeJCoefficients.h>
#include <TypeKCoefficients.h>
#include <TypeNCoefficients.h>
#include <TypeRCoefficients.h>
#include <TypeSCoefficients.h>
#include <TypeTCoefficients.h>
#include <vector>

std::vector<double> conversion(std::string const& conversionTarget, std::string const& type, std::vector<double> const& values);

std::vector<double> conversionTargetVoltageToTemperature(std::string const& type, std::vector<double> const& values);

std::vector<double> conversionTargetTemperatureToVoltage(std::string const& type, std::vector<double> const& values);