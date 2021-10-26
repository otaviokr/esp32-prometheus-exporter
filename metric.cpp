#include "metric.h"
#include <iostream>
#include <string>

PrometheusMetric::PrometheusMetric() {
}

PrometheusMetric::PrometheusMetric(std::string name, std::string description,
        enum PrometheusMetricType type, enum PrometheusMetricValueType valueType) {
    this->name = name;
    this->description = description;
    this->type = type;
    this->valueType = valueType;
}

PrometheusMetric::PrometheusMetric(std::string name, std::string description, std::string comment,
        enum PrometheusMetricType type, enum PrometheusMetricValueType valueType) {
    this->name = name;
    this->description = description;
    this->comment = comment;
    this->type = type;
    this->valueType = valueType;
}

void PrometheusMetric::setValue(int value) {
    this->intValue = value;
}

void PrometheusMetric::setValue(float value) {
    this->floatValue = value;
}

void PrometheusMetric::setValue(double value) {
    this->doubleValue = value;
}

std::string PrometheusMetric::getName() {
    return this->name;
}

std::string PrometheusMetric::getDescription() {
    return this->description;
}

std::string PrometheusMetric::getComment() {
    return this->comment;
}

std::string PrometheusMetric::getType() {
    switch (this->type) {
    case 0:
        break;

    default:
        break;
    }

    return "";
}

std::string PrometheusMetric::getValueAsString() {
    switch(this->valueType) {
        case PrometheusMetricValueType::Double:
            return std::to_string(this->doubleValue);
        case PrometheusMetricValueType::Float:
            return std::to_string(this->floatValue);
        case PrometheusMetricValueType::Integer:
            return std::to_string(this->intValue);
    }
    return "NaN";
}