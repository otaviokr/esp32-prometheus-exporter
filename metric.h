#include <string>
#include "metric_type.h"

#ifndef PROMETHEUS_METRIC_H
#define PROMETHEUS_METRIC_H

class PrometheusMetric {
    public:
    // Basic constructor.
    PrometheusMetric();

    // Constructor with the minimum required information. Since comments are not parsed anyway, it can be ignored.
    PrometheusMetric(std::string name, std::string description,
            enum PrometheusMetricType type, enum PrometheusMetricValueType ValueType);

    //
    PrometheusMetric(std::string name, std::string description, std::string comment,
            enum PrometheusMetricType type, enum PrometheusMetricValueType valueType);
    void setValue(int value);
    void setValue(float value);
    void setValue(double value);
    std::string getName();
    std::string getDescription();
    std::string getComment();
    std::string getType();
    std::string getValueAsString();

    private:
    std::string name;
    std::string description;
    std::string comment;
    enum PrometheusMetricType type;
    enum PrometheusMetricValueType valueType;
    int intValue;
    float floatValue;
    double doubleValue;
    int getMetricIndex(std::string metric);
};

#endif